#include <iostream>
//#include <string>
#include <conio.h>
//#include <cstdlib>
#include <random>
#include <time.h> 
//#include <algorithm>
//#include <ctime>
#include <vector>

#define X 10
#define Y 20
#define ENDx 7
#define ENDy 17


const int ROW = 21;
const int COL = 41;

const int STARTy = 1;
const int STARTx = 1;

const int FINy = 17;
const int FINx = 37;

using namespace std;


struct playerInfo {
	int posX;
	int posY;
	char visual;
};


void displayMap(char map[ROW][COL], playerInfo player) {
	//cout << player.posY << endl;
	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			if ((player.posX == i) && (player.posY == k)) cout << player.visual; else cout << map[i][k];
		}
		cout << endl;
	}
}

playerInfo move(playerInfo player, char direction, char map[ROW][COL], int ver) {
	//player.posY = 3;
	//player.posX = 2;
	//player.visual = 'K';
	if (direction == 'p') {
		if (map[player.posX][player.posY + 1] != '#') player.posY = player.posY + ver;
	}
	if (direction == 'l') {
		if (map[player.posX][player.posY - 1] != '#') player.posY = player.posY - ver;
	}
	if (direction == 'd') {
		if (map[player.posX + 1][player.posY] != '#') player.posX = player.posX + ver;
	}
	if (direction == 'g') {
		if (map[player.posX - 1][player.posY] != '#') player.posX = player.posX - ver;
	}
	return player;
}

playerInfo movePrim(playerInfo player, char direction, char map[ROW][COL], int ver) {

	if (direction == 'p') {
		if (map[player.posY][player.posX + 1] != '#') player.posX = player.posX + ver;
	}
	if (direction == 'l') {
		if (map[player.posY][player.posX - 1] != '#') player.posX = player.posX - ver;
	}
	if (direction == 'd') {
		if (map[player.posY + 1][player.posX] != '#') player.posY = player.posY + ver;
	}
	if (direction == 'g') {
		if (map[player.posY - 1][player.posX] != '#') player.posY = player.posY - ver;
	}
	return player;
}


void randomizePath(char map[ROW][COL]) {

	struct playerInfo path;
	path.posX = STARTx;
	path.posY = STARTy;
	path.visual = ' ';

	//srand(time(NULL));

	while (1) {

		int randomDirection = rand() % 4;
		//cout << randomDirection;
		char dir;
		if (randomDirection == 0) dir = 'p';
		if (randomDirection == 1) dir = 'l';
		if (randomDirection == 2) dir = 'd';
		if (randomDirection == 3) dir = 'g';
		path = move(path, dir, map, 1);
		map[path.posX][path.posY] = path.visual;
		if ((path.posX == ENDx) && (path.posY == ENDy)) break;
	}
}

void generateMap(char map[ROW][COL]) {
	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			if ((i == 0) || (i == X - 1) || (k == 0) || (k == Y - 1)) map[i][k] = '#'; else map[i][k] = '+';
		}
	}
	randomizePath(map);
	map[STARTx][STARTy] = '$';
	map[ENDx][ENDy] = '@';

	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			if (map[i][k] == '+') map[i][k] = '#';
		}
	}
	int emptySlots = 0;
	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			if (map[i][k] == ' ') emptySlots++;
		}
	}
	if (emptySlots > 85) generateMap(map);

}

int checkNorth(playerInfo currentSpot) {  //Y na minus
	if ((currentSpot.posY - 2) > 0) return 0;
	return 1;
}

int checkSouth(playerInfo currentSpot) {  //Y na plus
	if ((currentSpot.posY + 2) < ROW) return 0;
	return 1;
}

int checkWest(playerInfo currentSpot) {  //X na minus
	if ((currentSpot.posX - 2) > 0) return 0;
	return 1;
}

int checkEast(playerInfo currentSpot) {  //Y na minus
	if ((currentSpot.posX + 2) < COL) return 0;
	return 1;
}

int numberOFneighbours(playerInfo currentWall, char (&map)[ROW][COL]){
	int n = 0;
	if (map[currentWall.posY+1][currentWall.posX] == '+') n++;
	if (map[currentWall.posY-1][currentWall.posX] == '+') n++;
	if (map[currentWall.posY][currentWall.posX+1] == '+') n++;
	if (map[currentWall.posY][currentWall.posX-1] == '+') n++;
	return n;
}


int checkIfAlreadyExists(playerInfo a, vector<playerInfo> &walls) {
	for (int i = 0; i < walls.size(); i++) {
		if (a.posX == walls[i].posX) if (a.posY == walls[i].posY) return 1;
	}
	return 0;
}

void addWalls(playerInfo currentSpot, vector<playerInfo> &walls) {
	//cout << walls.size() << " tutaj" << endl;
	if (checkNorth(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX;
		a.posY = currentSpot.posY-1;
		if (checkIfAlreadyExists(a, walls) == 0) walls.push_back(a);
	}
	if (checkSouth(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX;
		a.posY = currentSpot.posY + 1;
		//cout << a.posX << " tutaj SPOT dol" << a.posY << endl;
		if (checkIfAlreadyExists(a, walls) == 0) walls.push_back(a);
	}
	if (checkWest(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX - 1;
		a.posY = currentSpot.posY;
		if (checkIfAlreadyExists(a, walls) == 0) walls.push_back(a);
	}
	if (checkEast(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX+1;
		a.posY = currentSpot.posY;
		if (checkIfAlreadyExists(a, walls) == 0) walls.push_back(a);
	}
	//cout << walls.size() << " tutaj" << endl;
}

void displayPrimMap(char map[ROW][COL], playerInfo b) {
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			if ((b.posX == k) && (b.posY == i)) cout << b.visual; else {
				//if ((k % 2 == 0) && (i % 2 == 0)) map[i][k] = ' '; else if ((k % 2 == 1) && (i % 2 == 1)) map[i][k] = ' '; else map[i][k] = '#';
				//cout << map[i][k];
				if ((map[i][k] == '+') || (map[i][k] == 'O')) cout << " "; else cout << map[i][k];
				//if (map[i][k] == 'O') cout << " "; else cout << map[i][k];
			}
		}
		cout << endl;
	}
}

int main(){
	char map[ROW][COL];
	vector<playerInfo> walls;
	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			//if ((k % 2 == 0) && (i % 2 == 0)) map[i][k] = ' '; else if ((k % 2 == 1) && (i % 2 == 1)) map[i][k] = ' '; else map[i][k] = '#';
			if (i % 2 == 0) map[i][k] = '#'; else if (k % 2 == 1) map[i][k] = ' '; else map[i][k] = '#';
			//cout << map[i][k];
		}
		//cout << endl;
	}


	srand(time(NULL));


	//vector<playerInfo> frontiers; // tylko nieparzyste sa dozwolonymi polami
	//frontiers[0].posX = 1; // COL to x ---->
	//frontiers[0].posY = 1;

	//vector<playerInfo> walls;

	//frontiers.emplace_back(1, 1, '*');

	playerInfo p;
	p.posX = STARTx;
	p.posY = STARTy;
	p.visual = 'X';

	playerInfo b;
	b.posX = STARTx;
	b.posY = STARTy;
	b.visual = 'X';


	map[STARTy][STARTx] = '+';





	//frontiers.push_back(p);

	//map[frontiers[0].posY][frontiers[0].posX] = frontiers[0].visual;



	//for (int i = 0; i < frontiers.size(); i++) {
		if (checkNorth(p) == 0) {
			p.posX = b.posX;
			p.posY = (b.posY-1);
			walls.push_back(p);
		}
		if (checkSouth(p) == 0) {
			p.posX = b.posX;
			p.posY = (b.posY + 1);
			walls.push_back(p);
		}
		if (checkWest(p) == 0) {
			p.posX = b.posX-1;
			p.posY = (b.posY);
			walls.push_back(p);
		}
		if (checkEast(p) == 0) {
			p.posX = b.posX +1;
			p.posY = (b.posY);
			walls.push_back(p);
		}
	//}

	while (walls.size()>0) {
		int randomDirection = rand() % (walls.size());
		if (randomDirection == walls.size()) randomDirection = randomDirection - 1;
		if (numberOFneighbours(walls[randomDirection],map) == 1) {
			//cout << "tutaj";
			map[walls[randomDirection].posY][walls[randomDirection].posX] = 'O';
			if ((walls[randomDirection].posY % 2) == 0) {
				map[walls[randomDirection].posY - 1][walls[randomDirection].posX] = '+';
				map[walls[randomDirection].posY + 1][walls[randomDirection].posX] = '+';

				p.posX = walls[randomDirection].posX;
				p.posY = walls[randomDirection].posY - 1;
				
				addWalls(p, walls);

				p.posX = walls[randomDirection].posX;
				p.posY = walls[randomDirection].posY + 1;

				addWalls(p, walls);


			}
			else {
				map[walls[randomDirection].posY][walls[randomDirection].posX+1] = '+';

				p.posX = walls[randomDirection].posX+1;
				p.posY = walls[randomDirection].posY;

				addWalls(p, walls);

				p.posX = walls[randomDirection].posX-1;
				p.posY = walls[randomDirection].posY;

				addWalls(p, walls);

				map[walls[randomDirection].posY][walls[randomDirection].posX-1] = '+';
			}
			//walls.erase(walls.begin() + randomDirection);
/*			cout << walls.size() << " tutaj" << endl;
			if (walls.size() > 315) {
				cout << "teraz" << endl;
				for (int i = 0; i < walls.size(); i++) {
					cout << walls[i].posX << "," << walls[i].posY << endl;
				}

			}
			if (walls.size() > 315) break;
	*/		//break;
		}
		walls.erase(walls.begin() + randomDirection);
	}


	
	//while (walls.size() > 0) {
	//	cout << walls[walls.size()-1].posX << ',' << walls[walls.size()-1].posY << endl;
	//	walls.pop_back();
	//}



	//map[frontiers[1].posY][frontiers[1].posX] = frontiers[1].visual;
	//map[frontiers[2].posY][frontiers[2].posX] = frontiers[2].visual;

	cout << "Wcisnij 1 dla wersji minimalnej wersji gdzie labirynt to tylko nie bezposrednia droga" << endl;
	cout << "Wcisnij 2 dla wersji gdzie labirynt ma slepe zaulki (20x10 to liczba pol na ktorych moze znajdowac sie gracz, czyli sciany nie sa uwzglednione)" << endl;
	char buttonPressed = 'q';
	buttonPressed = _getch();
	system("CLS");
	if (buttonPressed == '1') {
		generateMap(map);
		while (1) {
			displayMap(map, b);
			//break;
			buttonPressed = _getch();
			system("CLS");
			b = move(b, buttonPressed, map, 1);
			if ((b.posX == ENDx) && (b.posY == ENDy)) break;
		}
		cout << "sukces";
		_getch();
	}

	if (buttonPressed == '2') {
		map[STARTy][STARTx] = '$';
		map[FINy][FINx] = '@';
		while (1) {
			displayPrimMap(map, b);
			buttonPressed = _getch();
			system("CLS");
			b = movePrim(b, buttonPressed, map,2);
			if ((b.posX == FINx) && (b.posY == FINy)) break;
		}
		
	}

	cout << "sukces";


}
#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <random>
#include <time.h> 

#define X 10
#define Y 20

#define STARTx 1
#define STARTy 1

#define ENDx 7
#define ENDy 17



using namespace std;


struct playerInfo {
	int posX;
	int posY;
	char visual;
};

playerInfo move(playerInfo player, char direction, char map[X][Y]);


void randomizePath(char map[X][Y]) {

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
		path = move(path, dir, map);
		map[path.posX][path.posY] = path.visual;
		if ((path.posX == ENDx) && (path.posY == ENDy)) break;
	}
}

void generateMap(char map[X][Y]) {
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
	if (emptySlots > 100) generateMap(map);

	//struct playerInfo path;
}

void displayMap(char map[X][Y], playerInfo player) {
	//cout << player.posY << endl;
	for (int i = 0; i < X; i++) {
		for (int k = 0; k < Y; k++) {
			if ((player.posX == i) && (player.posY == k)) cout << player.visual; else cout << map[i][k];
		}
		cout << endl;
	}
}


playerInfo move(playerInfo player, char direction, char map[X][Y]) {
	//player.posY = 3;
	//player.posX = 2;
	//player.visual = 'K';
	if (direction == 'p') {
		if (map[player.posX][player.posY + 1] != '#') player.posY = player.posY + 1;
	}
	if (direction == 'l') {
		if (map[player.posX][player.posY - 1] != '#') player.posY = player.posY - 1;
	}
	if (direction == 'd') {
		if (map[player.posX + 1][player.posY] != '#') player.posX = player.posX + 1;
	}
	if (direction == 'g') {
		if (map[player.posX - 1][player.posY] != '#') player.posX = player.posX - 1;
	}
	return player;
}


int main() {
	char map[X][Y];
	char buttonPressed = 'q';
	struct playerInfo player;
	player.posX = STARTx;
	player.posY = STARTy;
	player.visual = 'O';
	//char map[X];
	srand(time(NULL));
	generateMap(map);
	//while (buttonPressed != 'k') {
	//while ((player.posX!= ENDx) && (player.posY!= ENDy)){
	while (1 == 1) {
		displayMap(map, player);
		buttonPressed = _getch();
		system("CLS");
		//cout << "jakis tekst " << buttonPressed;
		player = move(player, buttonPressed, map);
		//cout << player.posY << endl;
		//displayMap(map, player);
		//randomizePath(map);
		if ((player.posX == ENDx) && (player.posY == ENDy)) break;
	}
	cout << "sukces";
	_getch();
}
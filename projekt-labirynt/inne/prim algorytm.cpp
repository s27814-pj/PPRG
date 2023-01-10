#include <iostream>
#include <string>
#include <conio.h>
#include <cstdlib>
#include <random>
#include <time.h> 
#include <algorithm>
#include <ctime>
#include <vector>
#include <stack>

//
//#define X 50
//#define Y 150
//
//#define STARTx 1
//#define STARTy 1
//
//#define ENDx 7
//#define ENDy 17
//
//const int ROW = 50;
//const int COL = 150;
//
//int maze[ROW][COL];
//
//using namespace std;
//
//
//struct playerInfo {
//	int posX;
//	int posY;
//	char visual;
//};
//
//playerInfo move(playerInfo player, char direction, char map[X][Y]);
//
//
//void randomizePath(char map[X][Y]) {
//
//	struct playerInfo path;
//	path.posX = STARTx;
//	path.posY = STARTy;
//	path.visual = ' ';
//
//	//srand(time(NULL));
//
//	int previous = 1;
//
//	while (1) {
//		
//
//		int randomDirection = rand() % 4;
//		//cout << randomDirection;
//		char dir;
//		//if (randomDirection == previous) continue;
//		previous = randomDirection;
//		if ((randomDirection == 0) && (previous !=1)) dir = 'p';
//		if ((randomDirection == 1) && (previous != 0)) dir = 'l';
//		if ((randomDirection == 2) && (previous != 3)) dir = 'd';
//		if ((randomDirection == 3) && (previous != 2)) dir = 'g';
//		path = move(path, dir, map);
//		for (int a = rand() % 4; a > 0; a--)  map[path.posX][path.posY] = path.visual;
//		
//		if ((path.posX == ENDx) && (path.posY == ENDy)) break;
//	}
//	/*path.posX = 5;
//	path.posY = 17;
//	while (1) {
//
//
//		int randomDirection = rand() % 4;
//		//cout << randomDirection;
//		char dir;
//		//if (randomDirection == previous) continue;
//		previous = randomDirection;
//		if ((randomDirection == 0) && (previous != 1)) dir = 'p';
//		if ((randomDirection == 1) && (previous != 0)) dir = 'l';
//		if ((randomDirection == 2) && (previous != 3)) dir = 'd';
//		if ((randomDirection == 3) && (previous != 2)) dir = 'g';
//		path = move(path, dir, map);
//		map[path.posX][path.posY] = path.visual;
//		if ((path.posX == 2) && (path.posY == 17)) break;
//	}
//	mt19937 generator(random_device{}());
//	//random_shuffle(map.begin(), map.end(), generator);
//	*/
//}
//
//void generateMap(char map[X][Y]) {
//	for (int i = 0; i < X; i++) {
//		for (int k = 0; k < Y; k++) {
//			if ((i == 0) || (i == X - 1) || (k == 0) || (k == Y - 1)) map[i][k] = '#'; else map[i][k] = '+';
//		}
//	}
//	/*for (int i = 3; i < X; i = i + 2) {
//		for (int k = 3; k < Y; k=k+2) {
//			map[i][k] = '#';
//		}
//	}*/
//	map[STARTx][STARTy] = '$';
//	map[ENDx][ENDy] = '@';
//	//map[8][13] = '+';
//	randomizePath(map);
//	map[STARTx][STARTy] = '$';
//	map[ENDx][ENDy] = '@';
//
//	for (int i = 0; i < X; i++) {
//		for (int k = 0; k < Y; k++) {
//			if (map[i][k] == '+') map[i][k] = '#';
//		}
//	}
//	int emptySlots = 0;
//	for (int i = 0; i < X; i++) {
//		for (int k = 0; k < Y; k++) {
//			if (map[i][k] == ' ') emptySlots++;
//		}
//	}
//	//if (emptySlots > 85) generateMap(map);
//
//	//struct playerInfo path;
//}
//
//void displayMap(char map[X][Y], playerInfo player) {
//	//cout << player.posY << endl;
//	for (int i = 0; i < X; i++) {
//		for (int k = 0; k < Y; k++) {
//			if ((player.posX == i) && (player.posY == k)) cout << player.visual; else cout << map[i][k];
//		}
//		cout << endl;
//	}
//}
//
//
//playerInfo move(playerInfo player, char direction, char map[X][Y]) {
//	//player.posY = 3;
//	//player.posX = 2;
//	//player.visual = 'K';
//	if (direction == 'p') {
//		if (map[player.posX][player.posY + 1] != '#') player.posY = player.posY + 1;
//	}
//	if (direction == 'l') {
//		if (map[player.posX][player.posY - 1] != '#') player.posY = player.posY - 1;
//	}
//	if (direction == 'd') {
//		if (map[player.posX + 1][player.posY] != '#') player.posX = player.posX + 1;
//	}
//	if (direction == 'g') {
//		if (map[player.posX - 1][player.posY] != '#') player.posX = player.posX - 1;
//	}
//	return player;
//}
//
//
//
//
//void create_maze() {
//	// Initialize the maze with all walls
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++) {
//			maze[i][j] = 1;
//		}
//	}
//
//	stack<pair<int, int>> s;
//	vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//	int start_row = rand() % ROW;
//	int start_col = rand() % COL;
//
//	s.push({ start_row, start_col });
//	maze[start_row][start_col] = 0;
//
//	while (!s.empty()) {
//		int row = s.top().first;
//		int col = s.top().second;
//
//		bool done = true;
//
//		// Shuffle the directions to make the maze more random
//		random_shuffle(directions.begin(), directions.end());
//
//		for (auto d : directions) {
//			int new_row = row + d.first;
//			int new_col = col + d.second;
//
//			if (new_row >= 0 && new_row < ROW && new_col >= 0 && new_col < COL && maze[new_row][new_col] == 1) {
//				maze[new_row][new_col] = 0;
//				s.push({ new_row, new_col });
//				done = false;
//				break;
//			}
//		}
//
//		if (done) {
//			s.pop();
//		}
//	}
//}
//
//int main() {
//	char map[X][Y];
//	//array<array<char, X>, Y> map;
//	char buttonPressed = 'q';
//	struct playerInfo player;
//	player.posX = STARTx;
//	player.posY = STARTy;
//	player.visual = 'O';
//	//char map[X];
//	srand(time(NULL));
//	create_maze();
//	for (int i = 0; i < ROW; i++) {
//		for (int j = 0; j < COL; j++) {
//			cout << maze[i][j];
//		}
//		cout << endl;
//	}
//	//generateMap(map);
//	//while (buttonPressed != 'k') {
//	//while ((player.posX!= ENDx) && (player.posY!= ENDy)){
//	/*while (1 == 1) {
//		displayMap(map, player);
//		buttonPressed = _getch();
//		system("CLS");
//		//cout << "jakis tekst " << buttonPressed;
//		player = move(player, buttonPressed, map);
//		//cout << player.posY << endl;
//		//displayMap(map, player);
//		//randomizePath(map);
//		if ((player.posX == ENDx) && (player.posY == ENDy)) break;
//	}*/
//	cout << "sukces";
//	_getch();
//}
//
//
//using namespace std;
//
//
//#define INF 9999999
//
//// number of vertices in grapj
//#define V 5
//
//// create a 2d array of size 5x5
////for adjacency matrix to represent graph
//
//int G[V][V] = {
//  {0, 9, 75, 0, 0},
//  {9, 0, 95, 19, 42},
//  {75, 95, 0, 51, 66},
//  {0, 19, 51, 0, 31},
//  {0, 42, 66, 31, 0} };
//
//int main() {
//    int no_edge;  // number of edge
//
//    // create a array to track selected vertex
//    // selected will become true otherwise false
//    int selected[V];
//
//    // set selected false initially
//    memset(selected, false, sizeof(selected));
//
//    // set number of edge to 0
//    no_edge = 0;
//
//    // the number of egde in minimum spanning tree will be
//    // always less than (V -1), where V is number of vertices in
//    //graph
//
//    // choose 0th vertex and make it true
//    selected[0] = true;
//
//    int x;  //  row number
//    int y;  //  col number
//
//    // print for edge and weight
//    cout << "Edge"
//        << " : "
//        << "Weight";
//    cout << endl;
//    while (no_edge < V - 1) {
//        //For every vertex in the set S, find the all adjacent vertices
//        // , calculate the distance from the vertex selected at step 1.
//        // if the vertex is already in the set S, discard it otherwise
//        //choose another vertex nearest to selected vertex  at step 1.
//
//        int min = INF;
//        x = 0;
//        y = 0;
//
//        for (int i = 0; i < V; i++) {
//            if (selected[i]) {
//                for (int j = 0; j < V; j++) {
//                    if (!selected[j] && G[i][j]) {  // not in selected and there is an edge
//                        if (min > G[i][j]) {
//                            min = G[i][j];
//                            x = i;
//                            y = j;
//                        }
//                    }
//                }
//            }
//        }
//        cout << x << " - " << y << " :  " << G[x][y];
//        cout << endl;
//        selected[y] = true;
//        no_edge++;
//    }
//
//    return 0;
//}

const int ROW = 21;
const int COL = 41;

char map[ROW][COL];

using namespace std;







struct playerInfo {
	int posX;
	int posY;
	char visual;
};

vector<playerInfo> walls;



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

int numberOFneighbours(playerInfo currentWall) {
	int n = 0;
	if (map[currentWall.posY+1][currentWall.posX] == '+') n++;
	if (map[currentWall.posY-1][currentWall.posX] == '+') n++;
	if (map[currentWall.posY][currentWall.posX+1] == '+') n++;
	if (map[currentWall.posY][currentWall.posX-1] == '+') n++;
	return n;
}


int checkIfAlreadyExists(playerInfo a) {
	for (int i = 0; i < walls.size(); i++) {
		if (a.posX == walls[i].posX) if (a.posY == walls[i].posY) return 1;
	}
	return 0;
}

void addWalls(playerInfo currentSpot) {
	//cout << walls.size() << " tutaj" << endl;
	if (checkNorth(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX;
		a.posY = currentSpot.posY-1;
		if (checkIfAlreadyExists(a) == 0) walls.push_back(a);
	}
	if (checkSouth(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX;
		a.posY = currentSpot.posY + 1;
		//cout << a.posX << " tutaj SPOT dol" << a.posY << endl;
		if (checkIfAlreadyExists(a) == 0) walls.push_back(a);
	}
	if (checkWest(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX - 1;
		a.posY = currentSpot.posY;
		if (checkIfAlreadyExists(a) == 0) walls.push_back(a);
	}
	if (checkEast(currentSpot) == 0) {
		playerInfo a;
		a.posX = currentSpot.posX+1;
		a.posY = currentSpot.posY;
		if (checkIfAlreadyExists(a) == 0) walls.push_back(a);
	}
	//cout << walls.size() << " tutaj" << endl;
}

int main(){

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			//if ((k % 2 == 0) && (i % 2 == 0)) map[i][k] = ' '; else if ((k % 2 == 1) && (i % 2 == 1)) map[i][k] = ' '; else map[i][k] = '#';
			if (i % 2 == 0) map[i][k] = '#'; else if (k % 2 == 1) map[i][k] = ' '; else map[i][k] = '#';
			//cout << map[i][k];
		}
		//cout << endl;
	}


	srand(time(NULL));


	vector<playerInfo> frontiers; // tylko nieparzyste sa dozwolonymi polami
	//frontiers[0].posX = 1; // COL to x ---->
	//frontiers[0].posY = 1;

	//vector<playerInfo> walls;

	//frontiers.emplace_back(1, 1, '*');

	playerInfo p;
	p.posX = 1;
	p.posY = 1;
	p.visual = '+';


	frontiers.push_back(p);

	map[frontiers[0].posY][frontiers[0].posX] = frontiers[0].visual;



	for (int i = 0; i < frontiers.size(); i++) {
		if (checkNorth(frontiers[i]) == 0) {
			p.posX = frontiers[i].posX;
			p.posY = (frontiers[i].posY-1);
			walls.push_back(p);
		}
		if (checkSouth(frontiers[i]) == 0) {
			p.posX = frontiers[i].posX;
			p.posY = (frontiers[i].posY + 1);
			walls.push_back(p);
		}
		if (checkWest(frontiers[i]) == 0) {
			p.posX = frontiers[i].posX-1;
			p.posY = (frontiers[i].posY);
			walls.push_back(p);
		}
		if (checkEast(frontiers[i]) == 0) {
			p.posX = frontiers[i].posX +1;
			p.posY = (frontiers[i].posY);
			walls.push_back(p);
		}
	}

	while (walls.size()>0) {
		int randomDirection = rand() % (walls.size());
		if (randomDirection == walls.size()) randomDirection = randomDirection - 1;
		if (numberOFneighbours(walls[randomDirection]) == 1) {
			//cout << "tutaj";
			map[walls[randomDirection].posY][walls[randomDirection].posX] = 'O';
			if ((walls[randomDirection].posY % 2) == 0) {
				map[walls[randomDirection].posY - 1][walls[randomDirection].posX] = '+';
				map[walls[randomDirection].posY + 1][walls[randomDirection].posX] = '+';

				p.posX = walls[randomDirection].posX;
				p.posY = walls[randomDirection].posY - 1;
				
				addWalls(p);

				p.posX = walls[randomDirection].posX;
				p.posY = walls[randomDirection].posY + 1;

				addWalls(p);


			}
			else {
				map[walls[randomDirection].posY][walls[randomDirection].posX+1] = '+';

				p.posX = walls[randomDirection].posX+1;
				p.posY = walls[randomDirection].posY;

				addWalls(p);

				p.posX = walls[randomDirection].posX-1;
				p.posY = walls[randomDirection].posY;

				addWalls(p);

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

	for (int i = 0; i < ROW; i++) {
		for (int k = 0; k < COL; k++) {
			//if ((k % 2 == 0) && (i % 2 == 0)) map[i][k] = ' '; else if ((k % 2 == 1) && (i % 2 == 1)) map[i][k] = ' '; else map[i][k] = '#';
			//cout << map[i][k];
			if ((map[i][k] == '+') || (map[i][k] == 'O')) cout << " "; else cout << map[i][k];
			//if (map[i][k] == 'O') cout << " "; else cout << map[i][k];
		}
		cout << endl;
	}

	// dodaj adjacent komorki do frontiers


}
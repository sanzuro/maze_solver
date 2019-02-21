#include "pch.h"
#include <iostream>
 

using namespace std;
int inf = 100000;

int maze[100][100] = {0};
 
int start_x, start_y, end_x, end_y;

void recur(int x, int y , int value ) {
	maze[x][y] = value;
	std::cout << value << " " << x << " " << y << std::endl;
	if (x == end_x) {
		if (y == end_y) {
			std::cout << value <<std::endl;
			return;
		}
	}
	if (maze[x + 1][y] > value) {
		recur(x + 1, y, value + 1);
	}
	if (maze[x - 1][y] > value) {
		recur(x - 1, y, value + 1);
	}
	if (maze[x][y + 1] > value) {
		recur(x, y + 1, value + 1);
	}
	if (maze[x][y - 1] > value) {
		recur(x, y - 1, value + 1);
	}
	return;
}

int main()
{
	int t;
	int size_x , size_y;
	std::cin >> size_x >> size_y;
	for (int i = 0; i < size_x; i++) {
		for (int j = 0; j < size_y; j++) {
			std::cin >> t;
			maze[i][j] = (!t) ? inf : 0;
		}
	}
	std::cin >> start_x >> start_y >> end_x >> end_y;
	recur(start_x, start_y, 0);
	return 0;
}

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int map[19][19];

int direct[8][2] = {
	{-1,-1},
	{-1,0},
	{-1,1},
	{0,-1},
	{0,1},
	{1,-1},
	{1,0},
	{1,1},
};
int p;
int winner;
bool iswin = false;
int resulty;
int resultx;
void checkwinner() {
	iswin = false;
	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			if (map[i][j] == 1) {
				for (int k = 0; k < 8; k++)
				{
					int dy = i;
					int dx = j;
					p = 0;
					while (true) {

						dy = dy + direct[k][0];
						dx = dx + direct[k][1];

						if (dy >= 0 && dy < 19 && dx >= 0 && dx < 19) {
							if (map[dy][dx] != 1) {
								break;
							}
							else {
								p++;
							}
						}
					}

					if (p == 4) {
						dy = i - direct[k][0];
						dx = j - direct[k][1];
						if (dy >= 0 && dy < 19 && dx >= 0 && dx < 19) {
							if (map[dy][dx] == 1) {
								break;
							}
							else {
								iswin = true;
								winner = 1;
								resulty = i;
								resultx = j;
								return;
							}
						}
					}
				}
			}

			if (map[i][j] == 2) {
				for (int k = 0; k < 8; k++)
				{
					int dy = i;
					int dx = j;
					p = 0;
					while (true) {

						dy = dy + direct[k][0];
						dx = dx + direct[k][1];

						if (dy >= 0 && dy < 19 && dx >= 0 && dx < 19) {
							if (map[dy][dx] != 2) {
								break;
							}
							else {
								p++;
							}
						}
					}

					if (p == 4) {
						dy = i - direct[k][0];
						dx = j - direct[k][1];
						if (dy >= 0 && dy < 19 && dx >= 0 && dx < 19) {
							if (map[dy][dx] == 2) {
								break;
							}
							else {
								iswin = true;
								winner = 2;
								resulty = i;
								resultx = j;
								return;
							}
						}
					}

				}
			}
		}

	}
}
int main()
{
	//freopen("input.txt", "r", stdin);

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> map[i][j];
		}
	}
	checkwinner();
	if (winner == 0) {
		cout << "0";
	}
	else {
		cout << winner << '\n';
		cout << resulty + 1 << " " << resultx + 1;
	}
}

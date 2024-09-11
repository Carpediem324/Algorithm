#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
struct Point {
	int y;
	int x;
};
int N;
int map[101][101];
int visited[101][101];
int height = 0;
int maxheight = 0;
int result = 0;
int direct[4][2] = {
	-1,0,
	1,0,
	0,-1,
	0,1,
};
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			maxheight = max(map[i][j], maxheight);
		}
	}
}

void bfs(Point cp) {
	queue<Point> q;
	visited[cp.y][cp.x] = 1;
	q.push(cp);
	while (!q.empty()) {
		Point now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + direct[i][0];
			int nx = now.x + direct[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= N)continue;
			if (visited[ny][nx] == 1)continue;
			if (map[ny][nx] <= height)continue;//물높이보다낮으면잠긴곳임
			
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
		

	}
}
void process() {
	
	while (1) {//높이 1부터 최대높이까지 계속시작
		if (height == maxheight) {
			break;
		}
		memset(visited, 0, sizeof(visited));
		int countdevides = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (visited[i][j] == 1)continue;
				if (map[i][j] <= height)continue;//물높이보다낮으면못감.
				bfs({ i, j });
				countdevides++;
			}
		}

		result = max(result, countdevides);

		height++;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	process();
	cout << result;
}
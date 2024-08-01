#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int N;
int MAP[20][20];

struct Point
{
	int y;
	int x;
};
int sum;
int ans;
int DAT[101];


int direct[4][2] = {
	1,1,
	1,-1,
	-1,-1,
	-1,1
};

void init()
{
	memset(MAP, 0, sizeof(MAP));
	memset(DAT, 0, sizeof(DAT));
	ans = -1;
	sum = 0;
}

void input()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> MAP[i][j];
}

void dfs(Point cp, Point sp, int dir, int isSp)
{
	if (!isSp && cp.y == sp.y && cp.x == sp.x) //현재점이 초기점과 같다면, 처음이아니고
	{
		ans = max(ans, sum);
		return;
	}
	Point np = { cp.y + direct[dir][0], cp.x + direct[dir][1] }; //다음점

	if (np.y < 0 || np.x < 0 || np.y >= N || np.x >= N) //범위밖이면 리턴
		return;



	if (DAT[MAP[np.y][np.x]] == 1) //갔던 디저트면 리턴
		return;

	DAT[MAP[np.y][np.x]] = 1;
	sum++;

	if (dir < 3)//회전수가 끝까지 0,1,2중에 하나라면 돌려봄 3에서는 못돌린다
	{
		dfs(np, sp, dir+1, 0);
	}
	dfs(np, sp, dir, 0);
	DAT[MAP[np.y][np.x]] = 0;

	sum--;
}
void solve()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			dfs({ i, j }, { i, j }, 0, 1);//처음에만 스타팅포인트라고 4번째 파라미터 1로넣음
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		input();
		solve();
		cout << "#" << tc << " " << ans << '\n';
	}
}
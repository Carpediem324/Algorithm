#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;



int N, M, K, X;

vector<vector<int>> edge;
vector<int> visited;
//거리가 K인 도시의 번호를 오름차순으로 출력
//없으면 -1출력
void input() {
	cin >> N >> M >> K >> X;
	edge = vector<vector<int>>(N + 1);
	visited = vector<int>(N+1,-1);

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
}


void dijkstra() {
	queue<int> pq;//오름차순으로 출력하려고
	pq.push(X);
	
	
	visited[X] = 0;
	while (!pq.empty()) {
		int now = pq.front();
		pq.pop();
		if (visited[now] >= K)break;
		for (int a: edge[now])
		{
			int nextcost = visited[now] + 1;
			
			
			if (visited[a] == -1) {
				visited[a] = nextcost;
				pq.push(a);
			}
		}
	}
	bool printresult = false;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == K) {
			cout << i << '\n';
			printresult = true;
		}
	}
	if (printresult == false) {
		cout << "-1";
	}
}
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	dijkstra();
	
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
using namespace std;
int V, E;
int K;
struct Edge {
	int to;
	int cost;
};
bool compare(Edge a, Edge b) {
	return a.cost < b.cost;
}
vector<vector<Edge>> graph;
void input() {
	//V는 정점의 개수 E는 간선의 개수
	cin >> V >> E;
	//시작정점의 번호
	cin >> K;
	graph.reserve(V+1);
	graph.resize(V+1);
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		//방향그래프임
		graph[u].push_back({ v,w });
	}
	for (int i = 1; i <= V; i++) {
		//코스트작은거부터할라고
		sort(graph[i].begin(), graph[i].end(), compare);
	}
}

int visited[200001];
struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.cost > b.cost;
	}
};
priority_queue<Edge, vector<Edge>, cmp> pq;
void dijkstra(int start) {
	fill(&visited[0], &visited[0] + 20001, INT_MAX);
	pq.push({ start, 0 });
	visited[start] = 0;
	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();
		for (auto a : graph[now.to]) {
			int nextpoint = a.to;
			int nextcost = now.cost + a.cost;

			if (visited[nextpoint] > nextcost) {
				visited[nextpoint] = nextcost;
				pq.push({ nextpoint,nextcost });
			}
			
		}
	}
	for (int i = 1; i <= V; i++) {
		if (visited[i] == INT_MAX) {
			cout << "INF\n";
		}
		else {
			cout << visited[i] << '\n';
		}
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	dijkstra(K);
}
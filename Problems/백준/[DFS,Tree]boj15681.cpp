#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <unordered_map>

using namespace std;

int N, R, Q;
unordered_map<int, vector<int>> mymap;
unordered_map<int, int> res;
unordered_map<int, bool> visited;

int dfs(int node) {
    if (res[node] > 0)return res[node];
    visited[node] = true;
    int rescnt = 1; // 자기 자신 포함

    for (auto a : mymap[node]) {
        if (!visited[a]) {
            rescnt += dfs(a);
        }
    }

    res[node] = rescnt;
    return rescnt;
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> R >> Q;

    for (int i = 0; i < N - 1; i++) {
        int from, to;
        cin >> from >> to;
        mymap[from].push_back(to);
        mymap[to].push_back(from);
    }

    dfs(R);

    for (int i = 0; i < Q; i++) {
        int query;
        cin >> query;
        cout << res[query] << '\n';
    }
}

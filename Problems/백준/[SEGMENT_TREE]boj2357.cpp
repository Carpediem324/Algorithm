#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
long long numbers[100001];
long long mintree[400004];
long long maxtree[400004];
long long mininit(int start, int end, int node) {
	if (start == end) {
		return mintree[node] = numbers[start];
	}
	int mid = (start + end) / 2;
	
	return mintree[node] = min(mininit(start, mid, node * 2), mininit(mid + 1, end, node * 2 + 1));
}

long long maxinit(int start, int end, int node) {
	if (start == end) {
		return maxtree[node] = numbers[start];
	}
	int mid = (start + end) / 2;

	return maxtree[node] = max(maxinit(start, mid, node * 2), maxinit(mid + 1, end, node * 2 + 1));
}

long long minfind(int start, int end, int node, int left, int right) {
	if (left > end || right < start)return 1000000001;
	if (left <= start && right >= end)return mintree[node];
	int mid = (start + end) / 2;
	return min(minfind(start, mid, node * 2, left, right), minfind(mid + 1, end, node * 2 + 1, left, right));
}

long long maxfind(int start, int end, int node, int left, int right) {
	if (left > end || right < start)return 0;
	if (left <= start && right >= end)return maxtree[node];
	int mid = (start + end) / 2;
	return max(maxfind(start, mid, node * 2, left, right), maxfind(mid + 1, end, node * 2 + 1, left, right));
}
void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		numbers[i] = temp;
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();
	mininit(0, N - 1, 1);
	maxinit(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		int left, right;
		cin >> left >> right;
		left--;
		right--;
		cout << minfind(0, N - 1, 1, left, right) << " " << maxfind(0, N - 1, 1, left, right)<<'\n';
	}

}
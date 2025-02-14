#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <string>
using namespace std;
#define NUMBER 100001
long long numbers[NUMBER];
long long tree[4*NUMBER];


long long init(int start, int end, int node) {
	if (start == end) return tree[node] = numbers[start];
	int mid = (start + end) / 2;

	return tree[node]=min(init(start, mid, node * 2), init(mid + 1, end, node * 2 + 1));
}

long long minfind(int start, int end, int node, int left, int right) {
	if (left > end || right < start)return 1000000001;
	if (left <= start && right >= end)return tree[node];

	int mid = (start + end) / 2;
	return min(minfind(start, mid, node * 2, left, right), minfind(mid + 1, end, node * 2 + 1, left, right));
}
int N, M;

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		long long temp;
		cin >> temp;
		numbers[i] = temp;
	}
	init(0, N - 1, 1);
	for (int i = 0; i < M; i++)
	{
		int left, right;
		cin >> left >> right;
		left--;
		right--;
		cout<<minfind(0, N - 1, 1, left, right)<<'\n';
	}

}
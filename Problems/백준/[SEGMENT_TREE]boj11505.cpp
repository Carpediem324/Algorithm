#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
//boj 11505 구간 곱 구하기
//업데이트를 어떻게할지가 관건인 문제였음.
typedef long long ll;
long long numbers[1000001];
long long multree[4000001];

long long devnum = 1000000007;
long long init(int start, int end, int node) {
	if (start == end)return multree[node] = numbers[start];

	int mid = (start + end) / 2;

	return multree[node] = (init(start, mid, node * 2) * init(mid + 1, end, node * 2 + 1)) % devnum;
}

long long findmul(int start, int end, int node, int left, int right) {
	if (end<left || right<start)return 1;
	if (left <= start && end <= right)return multree[node];
	
	int mid = (start + end) / 2;
	return (findmul(start, mid, node * 2, left, right) * findmul(mid + 1, end, node * 2 + 1, left, right))%devnum;
}

void update(int start, int end, int node, int index, ll og, ll cg) {
	if (start > index || index > end) return;

	if (start == end) {
		multree[node] = cg;
		return;
	}
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, og, cg);
	update(mid+1, end, node * 2+1, index, og, cg);
	multree[node] = (multree[node * 2] * multree[node * 2 + 1]) % devnum;
}
int N, M, K;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	init(0, N - 1, 1);

	for (int i = 0; i < M+K; i++)
	{
		int type;
		cin >> type;
		if (type == 1) {//바꾸기
			int index, cg;
			cin >> index >> cg;
			ll og = numbers[index - 1];
			update(0, N - 1, 1, index - 1, og, cg);
			numbers[index - 1] = cg;
		}
		else if (type == 2) {
			int from, to;
			cin >> from >> to;
			cout << findmul(0, N - 1, 1, from - 1, to - 1)<<'\n';
		}
	}
	return 0;
}
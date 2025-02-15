#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

long long numbers[100001];
long long tree[400001];
int N, Q;
long long init(int start, int end, int node) {
	if (start == end)return tree[node] = numbers[start];
	int mid = (start + end) / 2;
	return tree[node]=init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start)return 0;
	if (left <= start && right >= end)return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2,left,right) + sum(mid + 1, end, node * 2 + 1, left, right);
}
//업데이트함수 못외움
//인덱스가 범위밖이면 그냥 리턴
//트리노드 +=차이
// 다음거 왼쪽오른쪽업데이트.
void update(int start, int end, int node, int index, long long dif) {
	if (index<start || index>end) return;
	tree[node] += dif;
	if (start == end)return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, dif);
	update(mid+1, end, node * 2+1, index, dif);
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	init(0, N - 1, 1);

	for (int i = 0; i < Q; i++)
	{
		int from, to;
		int index;
		long long num;
		cin >> from >> to >> index >> num;
        //말장난 문제 ...신경써야함
		if (from < to) {
			cout << sum(0, N - 1, 1, from - 1, to - 1) << '\n';
		}
		else {
			cout << sum(0, N - 1, 1, to - 1, from - 1) << '\n';
		}
		

		long long dif = num - numbers[index-1];
		numbers[index - 1] = num;
		update(0, N - 1, 1, index - 1, dif);

	}
	return 0;

}
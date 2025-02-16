#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

long long numbers[100001];
long long mintree[400001];

int N, M;

long long mininit(int start, int end, int node) {
	if (start == end)return mintree[node] = numbers[start];
	int mid = (start + end) / 2;
	return mintree[node] = min(mininit(start, mid, node * 2), mininit(mid + 1, end, node * 2 + 1));
}

long long minfind(int start, int end, int node, int left, int right) {
	if (start > right || end < left)return 999999999;
	if (left <= start && right >= end)return mintree[node];
	int mid = (start + end) / 2;
	return min(minfind(start, mid, node * 2, left, right), minfind(mid + 1, end, node * 2 + 1, left, right));
}

long long update(int start, int end, int node, int index, long long change) {
	if (index < start || end < index)return mintree[node];
	if (start == end)return mintree[node]= change;
	int mid = (start + end) / 2;
	
	return mintree[node] = min(update(start, mid, node * 2, index, change),update(mid+1, end, node * 2+1, index, change));
}
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	mininit(0, N - 1, 1);
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int type;
		cin >> type;
		if (type == 1) {
			int index;
			long long v;
			cin >> index >> v;

			numbers[index - 1] = v;
			update(0, N - 1, 1, index - 1, v);

		}
		else if(type==2){
			int left, right;
			cin >> left >> right;
			cout<<minfind(0, N - 1, 1, left-1, right-1)<<'\n';
		}

	}
}
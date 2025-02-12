#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <string>
using namespace std;
const int MAX = 1000000;

long long numbers[MAX+1];
long long tree[4* MAX+1];
int N, M;

long long init_seg(int start, int end, int node) {
	if (start == end)return tree[node]=numbers[start];
	int mid = (start + end) / 2;
	return tree[node]= init_seg(start, mid, node*2) + init_seg(mid + 1, end, node*2+1);
}

long long sum_seg(int start, int end, int node, int left, int right) {
	if (end < left || start > right) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum_seg(start, mid, node*2, left, right) + sum_seg(mid + 1, end, node*2+1, left, right);
}

void update_seg(int start, int end, int node, int index, long long dif) {
	if (index < start || end < index)return;
	tree[node] += dif;
	if (start == end)return;
	int mid = (start + end) / 2;
	update_seg(start, mid, node * 2,index, dif);
	update_seg(mid + 1, end, node * 2 + 1,index, dif);
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;

	//init_seg(0, N-1, 1);
	for (int i = 0; i < M; i++){
		int types, from, to;
		cin >> types >> from >> to;

		if (types == 0) {
			if (from > to)swap(from, to);
			cout << sum_seg(0, N - 1, 1, from-1, to-1)<<'\n';
		}
		else if (types == 1) {
			
			long long dif = to - numbers[from - 1];
			numbers[from - 1] = to;
			
			update_seg(0, N - 1, 1, from-1, dif);
		}
	}
}
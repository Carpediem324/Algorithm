#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

//K개의 랜선보유
//N개 이상 으로 나눠야하는데 최대길이
int K, N;
vector<int> lans;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> K >> N;
	for (int i = 0; i < K; i++) {
		int temp;
		cin >> temp;
		lans.push_back(temp);
	}
	//크게자르고 줄여가는방향으로해야함.

	long long startindex = 1;
	long long endindex = *max_element(lans.begin(), lans.end());
	long long result = 0;

	while (startindex <= endindex) {
		long long mid = (startindex + endindex) / 2;
		long long count = 0;

		// 각 랜선을 mid 길이로 잘라서 몇 개가 나오는지 계산
		for (int i = 0; i < K; i++) {
			count += lans[i] / mid;
		}

		// N개 이상 만들 수 있으면 길이를 더 늘릴 수 있는지 확인
		if (count >= N) {
			result = mid; // 가능한 길이로 저장
			startindex = mid + 1;
		}
		else {
			endindex = mid - 1;
		}
	}
	cout << result;

	return 0;
}
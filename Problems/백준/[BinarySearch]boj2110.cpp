#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int N;
int C;
vector<int> house, dist;
//집 N개가 수직선위에 있다.
// 어디서나 와이파이를 즐기기위해 공유기 C개 설치
// 한집 공유기하나, 가장인접한 공유기 사이거리 크게
// 집의 좌표는 10억까지

// 공유기 C개를 설치하는데 
// 가장 인접한 두 공유기 사이의 최대 거리

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		house.push_back(temp);
	}
	//이진탐색은 정렬되어있어야한다.
	sort(house.begin(), house.end());
	int ans = 0;
	int left = 1;
	int right = house[N - 1];
	int mid;
	int before, counts;
	while (left <= right) {
		mid = (left + right) / 2;
		counts=1;
		before = house[0];
		for (int i = 1; i < N; i++)
		{
			if (house[i] - before >= mid) {
				before = house[i];
				counts++;
			}
		}

		if (counts >= C) {
			left = mid + 1;
			ans = mid;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans;
}
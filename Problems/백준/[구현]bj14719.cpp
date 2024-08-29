#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W;
vector<int> map;

void input() {
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		int temp;
		cin >> temp;
		map.push_back(temp);
	}
}

int calculateWater() {
	if (W <= 2) return 0;  // 블록이 2개 이하일 경우 물이 고일 수 없음

	vector<int> leftMax(W, 0);
	vector<int> rightMax(W, 0);

	// 왼쪽에서 오른쪽으로 최대 높이 구하기
	leftMax[0] = map[0];
	for (int i = 1; i < W; i++) {
		leftMax[i] = max(leftMax[i - 1], map[i]);
	}

	// 오른쪽에서 왼쪽으로 최대 높이 구하기
	rightMax[W - 1] = map[W - 1];
	for (int i = W - 2; i >= 0; i--) {
		rightMax[i] = max(rightMax[i + 1], map[i]);
	}

	// 각 칸에서 고일 수 있는 물의 양 계산
	int result = 0;
	for (int i = 0; i < W; i++) {
		result += min(leftMax[i], rightMax[i]) - map[i];
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	input();

	int result = calculateWater();
	cout << result;
	return 0;
}

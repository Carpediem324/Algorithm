#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//일정이 있는 곳에만 코팅지를 달력에 붙이려고 한다.
int N;
vector<int> v;
int dat[1001];
int maxindex = 0;
int minindex = 99999999;
int result = 0;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int from, to;
		cin >> from >> to;
		maxindex = max(maxindex, to);
		minindex = min(minindex, from);

		for (int i = from; i <= to; i++)
		{
			dat[i]++;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	input();
	int height = 0;
	int width = 0;
	for (int i = minindex; i <= maxindex+1; i++)
	{
		if (dat[i] == 0) {
			result += height * width;
			height = 0;
			width = 0;
		}
		else {
			height = max(height, dat[i]);
			width++;
		}
	}

	cout << result;
}
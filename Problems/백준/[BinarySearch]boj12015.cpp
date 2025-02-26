#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <queue>
//boj 12015 가장 긴 증가하는 부분 수열 2
using namespace std;
int N;
vector<int> v;
vector<int> res;
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		v.push_back(tmp);
	}

	res.push_back(v[0]);
	int current = 1;
	while (current<N) {
		int target = res[res.size() - 1];
		if (target < v[current]) {
			res.push_back(v[current]);

		}
		else {
			int pos = lower_bound(res.begin(), res.end(), v[current])-res.begin();
			res[pos] = v[current];

		}
		current++;
	}
	cout << res.size();
}
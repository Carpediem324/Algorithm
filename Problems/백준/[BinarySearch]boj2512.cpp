#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

int N;
int M;
vector<int> v;
int total = 0;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		v.push_back(temp);
		total += temp;
	}
	cin >> M;

	if (M >= total) {//예산이 더많으면 요청액합보다
		cout << *max_element(v.begin(), v.end());
		return 0;
	}
	int startindex = 0;
	int endindex = *max_element(v.begin(), v.end());
	int ans = 0;
	while (startindex <= endindex) {
		int mid = (startindex + endindex) / 2;
		int total = 0;
		for (int i = 0; i < N; i++) {
			if (v[i] >= mid) {
				total += mid;
			}
			else {
				total += v[i];
			}
		}

		if (total <= M) {
			ans = mid;
			startindex = mid + 1;
		}
		else {
			endindex = mid -1;
		}

	}
	cout << ans;



	return 0;
}

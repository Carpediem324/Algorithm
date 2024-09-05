#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		else {
			return abs(a) > abs(b);
		}
	}
};
priority_queue<int, vector<int>, compare> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 0) {
			if (pq.empty()) {
				cout << "0" << '\n';
				continue;
			}
			cout<<pq.top()<<'\n';
			pq.pop();
		}
		else {
			pq.push(temp);
		}
	}

	return 0;
}
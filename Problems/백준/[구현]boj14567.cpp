#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N, M;
int result[1001];
vector<int> v[1001];
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		v[B].push_back(A);
	}
	memset(result, -1, sizeof(result));
}

void process() {
	int count = 0;
	vector<int> removable;
	while (1) {
		bool insalldone = true;
		for (int i = 1; i <= N; i++)
		{
			if (result[i] == -1) {
				insalldone = false;
				break;
			}
		}
		if (insalldone)break;
		count++;
		removable.clear();
		for (int i = 1; i <= N; i++)
		{
			if (v[i].size() == 0) {//선수과목이하나도없음
				if (result[i] == -1) {
					result[i] = count;
					removable.push_back(i);
				}				
			}
		}

		for (int i = 1; i <= N; i++)
		{
			for (int k:removable)
			{
				v[i].erase(remove(v[i].begin(), v[i].end(), k), v[i].end());
			}
		}

	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	input();
	process();
	for (int i = 1; i <= N; i++)
	{
		cout << result[i] << " ";
	}
	

}
#include <bits/stdc++.h>
using namespace std;

int N, T;
int nujuck[1000001];
unordered_map<string, float> mymap;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> T;
	int nujuckss = 0;
	for (int i = 1; i <= N; i++) {
		int temp;
		cin >> temp;
		nujuckss += temp;
		nujuck[i] = nujuckss;
	}

	for (int i = 0; i < T; i++) {
		int a, b;
		cin >> a >> b;
		string mapkey = to_string(a) + to_string(b);

		if (mymap.find(mapkey) == mymap.end()) {
			// 해당 키 값의 맵에 값이 없으면
			float ans;
			if (a == 1) {
				ans = float(nujuck[b]) / float((b - a + 1));
			} else {
				ans = float(nujuck[b] - nujuck[a - 1]) / float(b - a + 1);
			}
			mymap[mapkey] = ans;
		}
		cout << fixed;
		cout.precision(2);
		cout << mymap[mapkey] << '\n';
	}
	return 0;
}
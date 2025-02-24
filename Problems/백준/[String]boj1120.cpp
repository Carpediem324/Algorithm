#include <bits/stdc++.h>
using namespace std;

int compare(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == ' ') continue;
        if (a[i] != b[i]) cnt++;
    }
    return cnt;
}

int main() {
    string a, b;
    cin >> a >> b;

    int min_diff = INT_MAX;
    int gap = b.size() - a.size();
    int res =compare(a, b);
    for (int i = 1; i <= gap; i++)
    {
        a = " " + a;//a의 앞에 0을 추가
        res = min(res,compare(a, b));
    }
    cout<<res<<'\n';
    return 0;
}

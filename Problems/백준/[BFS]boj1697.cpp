#include <bits/stdc++.h>
using namespace std;

int N, K;


int maze[100001];
int direct[2]={-1,1};
int visited[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>K;

    queue<int> q;
    q.push(N);
    visited[N]=1;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        if(now==K){
            cout<<visited[now]-1;
            break;
        }
        int next;
        for(int i=0;i<2;i++){
            next = now+direct[i];
            if(next<0||next>100000)continue;
            if(visited[next]!=0)continue;
            visited[next]=visited[now]+1;
            q.push(next);
        }
        next = now*2;
        if(next<0||next>100000)continue;
        if(visited[next]!=0)continue;
        visited[next]=visited[now]+1;
        q.push(next);
    }


}
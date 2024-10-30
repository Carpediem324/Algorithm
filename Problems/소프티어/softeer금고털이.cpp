#include<bits/stdc++.h>
using namespace std;

struct jewel{
    int weight;
    int cost;
};
int W,N;
struct compare {
	bool operator() (jewel a, jewel b) {
		return a.cost < b.cost;
	}
};
priority_queue<jewel, vector<jewel>,compare> pq;
int main(int argc, char** argv)
{
    cin>>W>>N;
    for(int i =0;i<N;i++){
        int weight;
        int cost;
        cin>>weight>>cost;
        pq.push({weight,cost});
    }
    int result =0;
    while(W+=0){
        jewel now = pq.top();
        pq.pop();
        if(W>now.weight){
            W = W-now.weight;
            result += now.weight*now.cost;
        }
        else{
            
            result += W * now.cost;
            W=0;
        }
    }
    cout<<result;
    return 0;
}
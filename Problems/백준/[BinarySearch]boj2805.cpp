#include <bits/stdc++.h>
using namespace std;

int N,M;

vector<int> v;

int main(){
    cin>>N>>M;
    
    for(int i=0;i<N;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }

    long long startindex = 1;
    long long endindex = *max_element(v.begin(),v.end());
    long long ans=0;
    while(startindex<=endindex){
        long long mid = (startindex+endindex) /2;
        long long result = 0;
        for(int i=0;i<N;i++){
            if(v[i]>mid){
                result += v[i] - mid;
            }
        }

        if(result >=M){
            startindex = mid+1;
            ans = mid;
        }
        else{
            endindex = mid-1;
        }
    }
    cout<<ans;
    return 0;
}

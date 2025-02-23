//boj 3273 두 수의 합
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    for (int i = 0; i < n; i++)
    {       
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int target;
    cin>>target;

    sort(v.begin(),v.end());
    
    int left =0;
    int right = v.size()-1;
    int res =0;
    while(left<right){
        int leftside= v[left];
        int rightside = v[right];
        if(leftside+rightside==target){
            res++;
            left++;
            right--;
        }
        else if(leftside+rightside<target){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<res;
    
}
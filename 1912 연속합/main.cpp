//
//  main.cpp
//  1912 연속합
//
//  Created by 정지현 on 2021/07/20.
//
//
#include <iostream>
#include <algorithm>
using namespace std;
#define NMAX 100000
int arr[NMAX+1];
int dp[NMAX+1];
int main() {
    // insert code here...
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    
    int n;
    int ans=-1000;
    cin>>n;
    cin>>arr[0];
    dp[0]=arr[0];
    for(int i=1; i<n; i++){
        cin>>arr[i];
        dp[i]=max(arr[i], dp[i-1]+arr[i]);
        ans=max(ans,dp[i]);
    }
    ans=max(ans,dp[0]);
    cout<<ans<<'\n';
    return 0;
}

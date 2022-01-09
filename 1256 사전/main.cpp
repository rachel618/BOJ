//
//  main.cpp
//  1256 사전
//
//  Created by 정지현 on 2021/03/06.
//

#include <iostream>
#include <string>
typedef long long ll;
using namespace std;

ll getCombination(int n, int m){
    ll result=1;
    for(ll i=1; i<=m; i++){
        result*=(n-i+1);
        result/= i;
    }
    if(result>1000000000) result=1000000000;
    return result;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    string str="";
    int length= n+m;
    ll total= getCombination(length,m);
    
    if(k>total){
        cout<<-1<<'\n';
        return 0;
    }
    
    for(int i=0; i<length; i++){
        if(n==0){
            str+='z';
            continue;
        }
        else if(m==0){
            str+='a';
            continue;
        }
        
        ll tmp=getCombination(n+m-1,m);
        if(k<=tmp){
            str+='a';
            n--;
        }
        else{
            str+='z';
            k-=tmp;
            m--;
        }
    }
    cout<<str<<'\n';
    return 0;
}

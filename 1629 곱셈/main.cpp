//
//  main.cpp
//  1629 곱셈
//
//  Created by 정지현 on 2021/07/20.
//

#include <iostream>
typedef long long ll;
using namespace std;

ll ipow(ll a, ll b,ll c){
    if(b==0) return 1;
    ll x = ipow(a,b/2,c);
    x= x*x%c;
    if(b %2==1)
        return (x*a)%c;
    return x;
}
int main() {
    // insert code here...
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll A,B,C;
    cin>>A>>B>>C;
    ll answer=ipow(A,B,C);
    cout<<answer<<'\n';
}

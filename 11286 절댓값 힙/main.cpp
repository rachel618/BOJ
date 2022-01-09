//
//  main.cpp
//  11286 절댓값 힙
//
//  Created by 정지현 on 2021/02/15.
//

#include <iostream>
#include <functional>
#include <queue>
typedef long long ll;
using namespace std;

struct cmp{
    bool operator()(ll x, ll y){
        if(abs(x)== abs(y)) return x>y;
        return abs(x)>abs(y);
    }
};
priority_queue<ll, vector<ll>, cmp> pq;
int main() {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tc, a;
    cin>>tc;
    while(tc--){
        cin>>a;
        if(a==0){
            if(pq.empty()) cout << '0'<<'\n';
            else cout<<pq.top()<<'\n', pq.pop();
        }
        else
            pq.push(a);
    }
    return 0;
}

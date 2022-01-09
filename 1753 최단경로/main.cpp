//
//  main.cpp
//  1753 최단경로
//
//  Created by 정지현 on 2021/05/13.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

priority_queue<pair<ll, ll>, vector<pair<ll,ll>>,greater<>>q;
const ll n_=20202, inf=1e18;
ll V,E,K,dist[n_];
vector<pair<ll,ll>>v[n_];

int main() {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>V>>E;
    cin>>K;
    while(E--){
        ll a,b,c;
        cin>>a>>b>>c;
        v[a].push_back({b,c});
    }
    fill(dist, dist+V+1, inf);
    dist[K]=0;
    q.push({0,K});
    while(q.size()){
        auto cur=q.top(); // java의 var 같은 느낌
        q.pop();
        if(dist[cur.second]<cur.first) continue;
        for(auto nxt: v[cur.second]){
            if(dist[nxt.first]<=cur.first+nxt.second) continue;
            dist[nxt.first]=cur.first+nxt.second;
            q.push({dist[nxt.first], nxt.first});
        }
    }
    for(int i=1; i<=V; i++)cout<<dist[i]<<'\n';
    return 0;
}

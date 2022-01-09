//
//  main.cpp
//  2178 미로탐색
//
//  Created by 정지현 on 2021/04/09.
//

#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321
using namespace std;
typedef pair<int, int>pii;

int V,E,K;
int dist[20202];
vector<pii> d[20202];
int visited[20202];
priority_queue<pii, vector<pii>, greater<pii>>pq;

void dijkstra()
{
    while(!pq.empty()){
        int s=pq.top().second;
        int sval=pq.top().first;
        visited[s]=1;
        pq.pop();
        for(int i=0; i<d[s].size(); i++){
            int e=d[s][i].first,eval=d[s][i].second;
            if(dist[e]>sval+eval && !visited[e]){
                dist[e]=sval+eval;
                pq.push(pii(dist[e],e));
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>V>>E>>K;
    for(int i=0; i<E; i++){
        int a,b,c;
        cin>>a>>b>>c;
        d[a].push_back(pii(b,c));
    }
    for(int i=1; i<=V; i++)dist[i]=INF;
    dist[K]=0;
    pq.push(pii(0,K));
    dijkstra();
    for(int i=1; i<=V; i++){
        if(dist[i]==INF)cout<<"INF\n";
        else cout<<dist[i]<<'\n';
    }
}

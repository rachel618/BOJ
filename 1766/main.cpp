//
//  main.cpp
//  1766
//
//  Created by 정지현 on 2021/07/27.
//
#include <iostream>
#include <vector>
#include <queue>
//#include <algorithm> 오름차순으로 정리하면 시간초과 우서순위 큐 사용할것
#define NMAX 32000
using namespace std;

vector<int> adj[NMAX+1]; // 인접행렬
queue<int> ans;
int indegree[NMAX+1]={0,};
void tsort(int n){
    priority_queue<int,vector<int>, greater<int>>pq;
    for(int i=1; i<=n; i++)
        if(indegree[i]==0) pq.push(i);
    while(!pq.empty()){
        int now=pq.top();
        pq.pop();
        ans.push(now);
        for (auto& next : adj[now]){
            indegree[next]--;
            if(indegree[next]==0) pq.push(next);
        }
    }
        
}

int main() {
    // insert code here...
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    tsort(n);
    while(!ans.empty()){
        cout<< ans.front()<< " ";
        ans.pop();
    }
}

//
//  main.cpp
//  2252
//
//  Created by 정지현 on 2021/07/27.
//

#include <iostream>
#include <vector>
#include <queue>
#define NMAX 32000
using namespace std;

vector<int> adj[NMAX+1]; // 인접행렬
queue<int> ans;
int indegree[NMAX+1]={0,};
void tsort(int n){
    queue<int>q;
    for(int i=1; i<=n; i++)
        if(indegree[i]==0) q.push(i);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        ans.push(now);
        for (auto& next : adj[now]){
            indegree[next]--;
            if(indegree[next]==0) q.push(next);
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

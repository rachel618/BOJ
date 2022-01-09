//
//  main.cpp
//  11000 강의실 배정
//
//  Created by 정지현 on 2021/02/15.
//

#include <iostream>
#include <vector>
using namespace std;
#define NMAX 200000
vector<vector<int>>v;
bool visited[NMAX];

int main() {
    // insert code here...
    int N;
    cin>>N;
    while(N--){
        int s,t;
        cin>>s>>t;
        v[s].push_back(t);
    }
    int ans=0;
    queue
    return 0;
}

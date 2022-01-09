//
//  main.cpp
//  1662
//
//  Created by 정지현 on 2021/07/21.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[51]; // 중복체크

int dfs(string& S, int idx) {

    int cnt = 0;
    for (int i = idx; i < S.size(); i++) {
        if (S[i] == '(' && !visit[i]) {
            visit[i] = true;
            int num = S[i - 1] - '0';
            cnt--;
            cnt += num * dfs(S, i + 1);
        }
        else if (S[i] == ')' && !visit[i]) {
            visit[i] = true;
            return cnt;
        }
        else if(!visit[i]){
            visit[i] = true;
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
    string S;
    cin >> S;
    cout << dfs(S, 0) << '\n';
    return 0;
}

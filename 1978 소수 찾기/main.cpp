//
//  main.cpp
//  1978 소수 찾기
//
//  Created by 정지현 on 2021/03/04.
//
#include <iostream>
using namespace std;

int main() {
    // insert code here...
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int N, cnt=0, tmp;
    cin>>N;
   
    for(int i=0; i<N; i++){
        cin>>tmp;
         bool isPrime=true;
        if(tmp==1) continue;
        else if(tmp==2){
            cnt++;
            continue;
        }
        for(int j=2; j*j<=tmp; j++){
            if(tmp%j==0){
                isPrime=false;
                break;
            }
        }
        if(isPrime==true) cnt++;
    }
    cout<<cnt;
    
}

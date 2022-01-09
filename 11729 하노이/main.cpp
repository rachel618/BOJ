//
//  main.cpp
//  11729 하노이
//
//  Created by 정지현 on 2021/07/20.
//

#include <iostream>
using namespace std;
void hanoi(int n, int src, int dest, int med){
    if(n==1){
        cout<< src << ' '<< dest <<'\n';
        return;
    }
    hanoi(n-1, src,med, dest);
    cout<< src<<' '<<dest<<'\n';
    hanoi(n-1, med, dest,src);
}
int main(){
    // insert code here...
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin>>n;
    cout<< (1<<n)-1 <<'\n';
    hanoi(n,1,3,2);
    return 0;
}

//
//  main.cpp
//  1437 수 분해
//
//  Created by 정지현 on 2021/03/01.
//

#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int ans=1;
    int quota=n/3;
    if(n<5) ans=n;
    else{
        ans = pow(3, quota);
        if(n%3!=0)
            ans *= (n%3);
    }
}

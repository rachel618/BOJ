//
//  main.cpp
//  10090
//
//  Created by 정지현 on 2021/07/21.
//

#include <iostream>
#include <vector>
 
using namespace std;
 
vector<int> arr, temparr;
 
long long Inv = 0;
 
void counting_inversions(int start, int end){
    if(start == end) return;
    
    int mid = (start + end)/2;
    
    counting_inversions(start, mid);
    counting_inversions(mid+1, end);
    
    int low = start;
    int high = mid+1;
    long long temp_Inv = 0;
    int idx = 0;
    
    while(low <= mid || high <= end){

        if(low <= mid && (high > end || arr[low] < arr[high])){
            temparr[idx++] = arr[low++];
        }
        else{
            temparr[idx++] = arr[high++];
            temp_Inv += (mid - low + 1);
        }
    }
    
    for(int i = start; i <= end; i++){
        arr[i] = temparr[i - start];
    }
    Inv += temp_Inv;
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    arr.resize(N+1);
    temparr.resize(N+1);
    for(int i = 0; i < N; i++)
        cin >> arr[i];
    counting_inversions(0, N-1);
    
    cout << Inv <<'\n';
    
    return 0;
}


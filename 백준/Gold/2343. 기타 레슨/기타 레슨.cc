#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m; cin>>n>>m; 
    vector<int> a(n,0);

    int en=0; // 최장길이 
    int result=0;

    for(int i=0; i<n; i++){
        cin>>a[i]; 
        en += a[i]; 
    }

    int st=*max_element(a.begin(), a.end()); // 최소길이 

    while(st <= en){  // <= 로 변경
        int sum=0; 
        int cnt=1;
        int mid=(st+en)/2; 

        for(int i=0; i<n; i++){
            if(sum + a[i] > mid){
                sum=0; 
                cnt++; 
            }
            sum += a[i];
        }

        if(cnt <= m){
            result = mid;
            en = mid - 1;  // 더 작은 값 탐색
        } else {    
            st = mid + 1;  // 더 큰 값 필요
        }
    }
    cout<<result<<"\n";
}
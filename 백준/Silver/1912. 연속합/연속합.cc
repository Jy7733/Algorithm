#include <bits/stdc++.h>

using namespace std;

int arr[1000001];
int tmp[1000001];

int n;
int result;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    result = arr[0];
    tmp[0] = arr[0];
    for(int i=1; i<n; i++){
        tmp[i] = max(arr[i], tmp[i-1]+arr[i]);
        result = max(result,tmp[i]);
    }

    cout<<result<<"\n";}

#include <bits/stdc++.h>
using namespace std;

long long arr[101]; 

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int t; cin>>t;

    //초기화 
    for(int i=0; i<3; i++){
        arr[i] = 1;
    }

    for(int i=3; i<5; i++){
        arr[i] = 2;
    }
    //v : 1 1 1 2 2 


    // 규칙대로 배열 채우기 
    for(int i=5; i<=100; i++){
        arr[i] = arr[i-1] + arr[i-5];
    }


    for(int i=0; i<t; i++){
        int n; cin>>n;
        cout<<arr[n-1]<<"\n";
    }

}
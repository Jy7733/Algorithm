#include <bits/stdc++.h>

using namespace std;

int arr[21];
int dArr[21];
int cnt = 0;
int r = 0;
int n,s;

void comb(int depth, int next){
    
    if(depth == r){
        int sum = 0;
        for(int i=0; i<depth; i++){
            sum += dArr[i];
        }

        if( sum == s) cnt+=1;
        return;
    }
    
    for(int i=next; i<=n; i++){
        dArr[depth] = arr[i];
        comb(depth+1,i+1);
    }
    
}

int main(void){
    
    cin>>n>>s;
    for(int i=0; i<n; i++){
        cin>>arr[i+1];
    }
    
    for(r=1; r<=n; r++) comb(0,1);
    
    cout<<cnt;
}

#include <bits/stdc++.h>
using namespace std;

int col[16]; 
int n; 
int cnt=0; 

bool check(int x){
    for(int i=0; i<x; i++){
        if(col[i] == col[x] || abs(col[i] - col[x]) == abs(i-x)) return false; 
    }
    return true;
}

void backtrack(int x){
    if(x == n){
        cnt++; 
        return;
    }
    for(int i=0; i<n; i++){
        col[x] = i; // (x,i) 에 퀸 배치 
        if(check(x)) backtrack(x+1);
    }
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n; 

    backtrack(0); 
    cout<<cnt<<"\n";
}


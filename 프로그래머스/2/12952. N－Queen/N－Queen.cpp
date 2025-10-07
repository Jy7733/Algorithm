#include <bits/stdc++.h>

using namespace std;
int answer = 0;

int visited[13][13]; 

void checkVisited(int x, int y, int n, int flag){
    //가로 
    for(int i=0; i<n; i++){
        visited[x][i] += flag; 
    }
    
    //세로
    for(int i=0; i<n; i++){
        visited[i][y] += flag; 
    }
    
    //대각선 
    for(int i=1; i<n; i++){
        if(x-i>=0 && y-i>=0) visited[x-i][y-i] += flag; 
        if(x+i<n && y+i <n) visited[x+i][y+i] += flag;  
        if(x+i<n && y-i>=0) visited[x+i][y-i] += flag; 
        if(x-i>=0 && y+i <n) visited[x-i][y+i] += flag; 
    }
}

void func(int k, int n, int x){
    if(k == n){
        answer ++; 
        return; 
    }
    
    for(int i=0; i<n; i++){
        if(visited[x][i] > 0) continue;
        checkVisited(x,i,n,1);
        func(k+1,n,x+1);
        checkVisited(x,i,n,-1);
    }
}

int solution(int n) {
    func(0,n,0);
    return answer;
}
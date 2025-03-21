#include <bits/stdc++.h>

using namespace std;

bool visited[200];
vector<vector<int>> adj(200);

void DFS(int start, vector<vector<int>> computers, int n){
    visited[start] = true;
    
    for(int i=0; i<n; i++){
        if(!visited[i] && computers[start][i] == 1)
            DFS(i, computers, n);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){
            DFS(i, computers, n);
            answer++;
        }
    }
    
    return answer;
}



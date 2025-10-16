#include <bits/stdc++.h>
#define INF (~0U>>2)

using namespace std;

vector<vector<int>> adj; 

int check(int x, int n){
    
    vector<bool> visited(n+1,false);
    queue<int> q; 
    visited[x] = true; 
    q.push(x); 
    
    int cnt = 0;
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        for(int i=1; i<=n; i++){
            if(adj[cur][i] == 0) continue; //연결이 안됐으면 통과 
            if(visited[i]) continue;
            visited[i] = true;
            cnt++;
            q.push(i);
        }
    }
    return cnt; 
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INF;
    adj.resize(n+1, vector<int>(n+1,0)); 
    
    for(auto wire : wires){
        adj[wire[0]][wire[1]]=1;
        adj[wire[1]][wire[0]]=1; 
    }
    
    for(int i=0; i<wires.size(); i++){
        int u = wires[i][0]; 
        int v = wires[i][1];
        
        //연결끊기
        adj[u][v] = 0;
        adj[v][u] = 0; 
        
        answer = min(answer, abs(check(u,n)-check(v,n)));
        
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    return answer;
}


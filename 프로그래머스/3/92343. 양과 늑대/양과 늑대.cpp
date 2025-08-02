#include <bits/stdc++.h>

using namespace std;

bool visited[17][17][17]; 
vector<int> state(17); 
vector<vector<int>> adj(17);
int answer = 0;

void DFS(int cur, int sheep, int wolf){
    if(cur == 0){
        answer = max(answer, sheep);
    }
    
    for(auto next : adj[cur]){
        // 다음 노드가 양인 경우 
        if(state[next] == 0 && !visited[next][sheep+1][wolf]){
            visited[next][sheep+1][wolf] = true;
            state[next] = -1;
            DFS(next, sheep+1, wolf);
            state[next] = 0;
            visited[next][sheep+1][wolf] = false;
        }
        
        // 다음 노드가 늑대인 경우 
        else if(state[next] == 1 && !visited[next][sheep][wolf+1] && sheep > wolf+1){
            visited[next][sheep][wolf+1] = true; 
            state[next] = -1;
            DFS(next, sheep, wolf+1);
            state[next] = 1;
            visited[next][sheep][wolf+1] = false;
        }
        
        // 아무것도 없는 노드인 경우 
        else if(state[next] == -1 && !visited[next][sheep][wolf]){
            visited[next][sheep][wolf] = true;
            DFS(next,sheep,wolf);
            visited[next][sheep][wolf] = false;
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    
    for(auto edge : edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    
    state = info;
    state[0] = -1; 
    visited[0][1][0] = true;
    DFS(0,1,0); 
    
    return answer;
}

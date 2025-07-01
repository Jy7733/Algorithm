#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    queue<int> q;
    vector<bool> visited(n + 1, false);
    vector<vector<int>> adj(n+1);
    
    int dist[n+1];
    fill(dist,dist+n+1,INF);
    
    
    //인접 배열 세팅
    for(auto vertex : edge){
        adj[vertex[0]].push_back(vertex[1]);
        adj[vertex[1]].push_back(vertex[0]);
    }
    
    q.push(1);
    visited[1] = true;
    dist[1] = 0;
    
    while(!q.empty()){
        int current = q.front();
        q.pop();
        
        for(int vertex : adj[current]){
            if(visited[vertex]) continue;
            q.push(vertex);
            visited[vertex] = true;
            dist[vertex] = min(dist[current] + 1, dist[vertex]);
        }
    }
    
    int max = *max_element(dist+1, dist+n);
    for(int i=1; i<n; i++){
        if(dist[i] == max) answer++;
    }

    return answer;
}
        
           
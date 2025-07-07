#include <bits/stdc++.h>
#define INF (~0U>>2)

using namespace std;

vector<vector<int>> adj;


vector<int> dijkstra(int start, int n){
    
    vector<int> distance(n + 1, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    pq.push({0,start});
    distance[start] = 0;
    
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();
        
        if(distance[curNode] != curCost) continue;
        
        for(auto next : adj[curNode]){
            int nextDist = distance[curNode] + 1;
            if(nextDist < distance[next]){
                distance[next] = nextDist;
                pq.push({nextDist,next});
            }
        }
    }
    
    return distance;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    adj.resize(n+1);
    for(auto road : roads){
        adj[road[0]].push_back(road[1]);
        adj[road[1]].push_back(road[0]);
    }
    
    
    
    vector<int> distance = dijkstra(destination,n);
    
    for(auto src : sources){
        if(distance[src] == INF) answer.push_back(-1);
        else answer.push_back(distance[src]);
    }

    return answer;
}

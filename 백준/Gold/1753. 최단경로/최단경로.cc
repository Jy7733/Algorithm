#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

int d[20001];
priority_queue<pair<int,int>> q;
vector<pair<int, int>> adj[20001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int v,e;
    cin>>v>>e;
    
    int k;
    cin>>k;
    
    for(int i=0; i<e; i++){
        int u,v,w;
        cin>>u>>v>>w;
        
        adj[u].push_back({w,v});
    }
    
    //최단 거리 테이블 초기화
    fill(d,d+v+1,INF);
    
    // 우선순위 큐에 (거리, 시작정점) 삽입
    q.push({0,k});
    
    //최단거리 테이블 d[시작점] = 0 으로 업데이트
    d[k] = 0;
    
    while(!q.empty()){
        
        //거리가 가장 작은 정점 뽑음
        int curV = q.top().second;
        int curD = -q.top().first;
        q.pop();
        
        //최단거리 테이블 값과 비교
        if(d[curV] < curD) continue; //최단거리 테이블값과 일치하지 않으면 건너뜀
        
        //현재 정점에서 갈 수 있는 인접 정점에 대하여 순회
        for(auto node : adj[curV]){
            int destV = node.second;
            int destD = node.first;
            
            // d[이전 정점] + 가중치 가 더 작다면 갱신
            if(d[destV] > d[curV] + destD){
                d[destV] = d[curV] + destD;
                q.push({-d[destV], destV});
            }
            
        }
        
    }
    
    for(int i=1; i<=v; i++){
        if(d[i] == INF){
//            cout<<"INF"<<"\n";
            printf("INF\n");
        }
        else{
//            cout<<d[i]<<"\n";
            printf("%d\n",d[i]);
        }
        
    }
    
}




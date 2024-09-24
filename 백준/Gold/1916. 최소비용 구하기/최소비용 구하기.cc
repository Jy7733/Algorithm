#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

int d[1001];
int pre[1001];
//priority_queue<pair<int,int>> q;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
vector<pair<int, int>> adj[1001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n; //도시 개수
    
    int m;
    cin>>m; //버스 개수
    
    for(int i=1; i<=m; i++){
        int v,u,w;
        cin>>v>>u>>w;
        
        adj[v].push_back({w,u});
    }
    
    int start,end;
    cin>>start>>end;
    
    q.push({0,start});
    
    //최단거리 테이블 초기화
    fill(d,d+n+1,INF);
    d[start]=0;
    
    while(!q.empty()){
        pair<int,int> cur = q.top();
        int curV = cur.second;
        int curD = cur.first;
        q.pop();
        
        if(d[curV] < curD) continue; //최단 거리 테이블에 저장된 값이 더 작으면 건너뜀
        
        for(auto node : adj[curV]){
            int destV = node.second;
            int destD = node.first;
            
            //d[이전노드] + 비용 이 더 작다면 갱신
            if(d[destV] > curD + destD){
                d[destV] = curD + destD; //최단거리 테이블 갱신
                q.push({d[destV],destV}); //우선순위 큐에 삽입
                pre[destV] = curV;
                
            }
        }
    }
    
    //최소비용 출력
    cout<<d[end]<<"\n";
}



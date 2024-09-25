#include <bits/stdc++.h>
#define INF 99999999

using namespace std;

int d[1001];
int totalD[1001];

vector<pair<int, int>> adj[1001];

int n,m,x;

int dijkstra(int start, int end){
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;

    //최단거리 테이블 초기화 
    fill(d,d+n+1,INF);
    d[start] = 0;

    //큐에 시작점 삽입 
    q.push({0,start});

    while(!q.empty()){
        pair<int,int> cur = q.top();
        int curV = cur.second;
        int curW = cur.first;

        q.pop();

        if(curW > d[curV]) continue; //저장되어 있는 값이 이미 더 작은 값이면 무시

        //curD 의 인접노드 확인 
        for(auto node : adj[curV]){
            int adjV = node.second;
            int adjW = node.first;

            //새로 계산한 값이 더 작은 경우 
            if(d[curV] + adjW < d[adjV]){
                d[adjV] = d[curV] + adjW; //최단거리 테이블 업데이트 
                q.push({d[adjV],adjV}); //큐에 삽입          
            }
        }
    }
    return d[end];
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m>>x;

    for(int i=0; i<m; i++){
        int u,v,w;

        cin>>u>>v>>w;
        adj[u].push_back({w,v});
    }


    int maxD = 0;
    for(int i=1; i<=n; i++){
        maxD = max(dijkstra(i,x)+dijkstra(x,i),maxD);
    }

    cout<<maxD<<"\n";
}




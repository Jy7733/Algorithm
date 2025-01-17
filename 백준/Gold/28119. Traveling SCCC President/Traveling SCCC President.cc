#include <bits/stdc++.h>

using namespace std;

vector<pair<int, pair<int,int>>> arr;
int p[2001];


int find(int x){
    if(p[x] == x) return x; //루트 노드이면 그대로 반환 

    return p[x] = find(p[x]);
}

void uni(int u,int v){
    u = find(u);
    v = find(v);

    //cycle 이 발생하지 않는다면 하나의 루트 노드로 병합 
    if(p[u] != p[v]) p[v] = u; 

}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n,m,s;
    cin>>n>>m>>s;

    for(int i=0; i<m; i++){
        int v,u,w;
        cin>>v>>u>>w;
        arr.push_back({w, {u,v}});
    }

    sort(arr.begin(),arr.end());

    for(int i=1; i<=n; i++){
        p[i] = i;
    }

    int edge = 0;
    int result = 0;

    for(int i=0; i<m; i++){
        int cost = arr[i].first; //도로 통행 시간 
        int u = arr[i].second.first; //건물1
        int v = arr[i].second.second; //건물2

        if(edge == (n-1)) break;

        if(find(u) != find(v)){
            uni(u,v);
            result+=cost;
            edge+=1;
            if(edge == (n-1)) break;
        }
    }

    cout<<result<<"\n";

}
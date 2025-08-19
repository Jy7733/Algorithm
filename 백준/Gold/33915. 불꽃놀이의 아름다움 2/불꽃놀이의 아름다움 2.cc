#include <bits/stdc++.h>
using namespace std;

vector<int> colors; 
vector<vector<int>> adj;
int dup = 0;

void DFS(int node, int color){
    for(auto next : adj[node]){
        if(colors[next]==0){
            colors[next] = color*(-1);
            DFS(next,color*(-1));
        }

        if(colors[node] == colors[next]){
            dup++;
        }
    }
}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int answer =2;
    int n; cin>>n;
    colors.resize(n+1);
    adj.resize(n+1);

    for(int i=0; i<n; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    DFS(1,1);

    cout<<answer + dup/2<<"\n";
}

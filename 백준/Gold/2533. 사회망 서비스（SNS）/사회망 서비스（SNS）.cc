#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

vector<bool> visited;
vector<vector<int>> dp;
vector<vector<int>> adj;

void func(int x){
  visited[x] = true;
  dp[x][1]=1; //노드 x선택 

  for(auto child : adj[x]){
    if(visited[child]) continue;
    func(child);

    dp[x][0] += dp[child][1];
    dp[x][1] += min(dp[child][1], dp[child][0]);
  }
  return;
}

int main(void){
  int n;
  cin>>n;

  adj.resize(n + 1);
  visited.resize(n + 1);
  dp.resize(n + 1, vector<int>(2, 0));

  for(int i=0; i<n-1; i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  func(1);

  cout<<min(dp[1][0], dp[1][1])<<"\n";
}
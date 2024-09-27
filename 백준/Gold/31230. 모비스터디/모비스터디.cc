#include <bits/stdc++.h>
#define INF LLONG_MAX

using namespace std;

vector<long long> d;
vector<vector<int>> pre;
vector<vector<pair<int, int>>> adj;
set<int> path;

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

int n, m, a, b;

void dijkstra(int start) {
    fill(d.begin(), d.end(), INF);
    d[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        pair<long long, int> curr = q.top(); 
        int currCity = curr.second;
        long long currCost = curr.first; 
        q.pop();

        if (currCost > d[currCity]) continue;

        for (auto node : adj[currCity]) {
            int destCity = node.second;
            long long destCost = node.first; 

            if (d[destCity] > d[currCity] + destCost) {
                d[destCity] = d[currCity] + destCost;
                pre[destCity].clear();
                pre[destCity].push_back(currCity);
                q.push({d[destCity], destCity});
            } 
            else if (d[destCity] == d[currCity] + destCost) {
                pre[destCity].push_back(currCity);
            }
        }
    }
}

void DFS(int x) {
    if (x == a) {
        path.insert(a); // 시작점 추가
        path.insert(b); // 종료지점 추가 
        return;  
    }

    for (int prevCity : pre[x]) {
        path.insert(prevCity); 
        DFS(prevCity);
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> a >> b;

    d.resize(n + 1);
    pre.resize(n + 1);
    adj.resize(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    dijkstra(a); 

    DFS(b);
    
    cout << path.size() << "\n"; 
    
    for (int city : path) {
        cout << city << " "; 
    }
    cout << "\n"; 
}

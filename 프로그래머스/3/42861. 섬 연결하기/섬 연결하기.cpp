#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<bool> visited(n, false);
    vector<vector<pair<int, int>>> adj(n);

    // 인접 리스트 구성 (비용, 연결 노드)
    for (auto& c : costs) {
        int u = c[0], v = c[1], w = c[2];
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    // 최소 힙: {비용, 노드 번호}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0});  // 시작: 0번 섬, 비용 0

    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if (visited[node]) continue;
        visited[node] = true;
        answer += cost;

        for (auto& [w, next] : adj[node]) {
            if (!visited[next]) {
                pq.push({w, next});
            }
        }
    }

    return answer;
}

#include <bits/stdc++.h>
#define INF LLONG_MAX

using namespace std;

vector<long long> d;
vector<vector<int>> pre;
vector<vector<pair<int, int>>> adj;
set<int> path; // 중복을 없애기 위해 set 사용

priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

int n, m, a, b;

void dijkstra(int start) {
    fill(d.begin(), d.end(), INF);
    d[start] = 0;
    q.push({0, start});

    while (!q.empty()) {
        pair<long long, int> curr = q.top(); // 자료형 변경
        int currCity = curr.second;
        long long currCost = curr.first; // 자료형 변경
        q.pop();

        if (currCost > d[currCity]) continue;

        for (auto node : adj[currCity]) {
            int destCity = node.second;
            long long destCost = node.first; // 자료형 변경

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
        path.insert(prevCity); // 중복을 방지하기 위해 set에 추가
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

    dijkstra(a); // 다익스트라 실행

    DFS(b);  // 도착점에서 출발점으로 경로를 역추적

    // path는 set이므로 중복이 제거되어 있습니다.
    vector<int> result(path.begin(), path.end());
    sort(result.begin(), result.end()); // 오름차순 정렬

    cout << result.size() << "\n";  // 경로에 포함된 도시의 개수 출력
    
    for (int city : result) {
        cout << city << " "; // 도시 번호 출력
    }
    cout << "\n"; // 마지막 줄바꿈 추가

    return 0;
}

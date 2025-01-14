#include <bits/stdc++.h>

using namespace std;

vector<int> adj[201];
int p[201];
vector<int> plan;

int find(int u) {
    if (p[u] < 0) return u;
    return p[u] = find(p[u]);
}

bool uni(int u, int v) {
    // 루트 노드 검색 
    u = find(u);
    v = find(v); 

    if (u == v) return false;

    // u의 랭크가 더 크도록 보장
    if (p[u] < p[v]) {
        swap(u, v);
    }

    if (p[u] == p[v]) {
        p[u]--;
    }

    p[v] = u;
    return true;
}

int main(void) {
    // 도시 개수 
    int n;
    cin >> n; 

    // 여행 계획에 속한 도시들의 수 
    int m;
    cin >> m;

    // 부모 배열 초기화
    memset(p, -1, sizeof(p));

    // 연결 정보 입력 & 부모 노드 업데이트 
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int x;
            cin >> x;
            if (x == 1) uni(i, j);
        }
    }

    // 여행계획 입력 
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x; 
        plan.push_back(x);
    }

    // 계획된 도시들이 같은 집합인지 확인
    for (int i = 0; i < m - 1; i++) {
        if (find(plan[i]) != find(plan[i + 1])) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";
}

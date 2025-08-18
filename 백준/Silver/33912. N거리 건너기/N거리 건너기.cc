#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll simulate(int n, int m, const vector<int>& pos, bool cw) {
    ll t = 0;
    int cur = 1;
    while (cur != m) {
        int nxt = cw ? (cur % n + 1) : (cur - 1 == 0 ? n : cur - 1);
        int edge = cw ? cur : nxt;   // 건널 횡단보도 번호
        int p = pos[edge];     
        int wait = (p - (t % n) + n) % n; // 기다려야 하는 시간 
        t += wait;  
        t += 1;     
        cur = nxt;
    }
    return t;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    // pos[e] = 이 횡단보도가 초록불 켜지는 시각 mod N
    vector<int> pos(n + 1);
    for (int i = 0; i < n; i++) pos[A[i]] = i;

    ll tCW = simulate(n, m, pos, true);
    ll tCCW = simulate(n, m, pos, false);

    if (tCW < tCCW) cout << "CW\n";
    else if (tCW > tCCW) cout << "CCW\n";
    else cout << "EQ\n";
}

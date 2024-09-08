#include <bits/stdc++.h>

using namespace std;

long count(int n) {
    if (n == 1 || n == 2) return 1; // f(1) = 1, f(2) = 1

    long prevCnt = 1; // f(1)
    long currCnt = 1; // f(2)
    long nextCnt;

    for (int i = 3; i <= n; i++) { // n >= 3인 경우
        nextCnt = prevCnt + currCnt; // f(n) = f(n-1) + f(n-2)
        prevCnt = currCnt; // f(n-2) 업데이트
        currCnt = nextCnt; // f(n-1) 업데이트
    }

    return currCnt; // f(n) 반환
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    cout << count(n) << "\n"; // count 함수 호출 및 결과 출력
}

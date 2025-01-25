### 💡알고리즘 분류

---

- 누적합

### 🔎 접근 방법

---

가장 먼저 떠오르는 방법은 그냥 for 반복문 돌리는 단순한 방법이지만,, 

최악의 경우 N = 1024 이고, M = 100000 이고 (1,1) ~ (N,N) 를 반복문으로 구한다면 시간 초과가 날 것이 분명하다..!

이전에 누적합을 썼던 문제가 생각나서 누적합을 쓰는 문제가 아닐까 생각했다. 

→ 각 행에 대한 누적합을 sum 배열에 저장할 것을 생각했다. ( sum[x][y] = x행의 y열까지의 누적합) 

이를 이용하여 예를 들어 (2,2) ~ (3,4) 를 구한다고 하면, 

`sum[2][4] - sum[2][1]`  + `sum[3][4] - sum[3][1]` 을 통해 구할 수 있다! 

```cpp
#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    int sum[n+1][n+1];
    memset(sum, 0, sizeof(sum));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            int x; 
            cin>>x;
            sum[i][j] = sum[i][j-1] + x;
        }
    }

    for(int i=0; i<m; i++){
        int x1,y1,x2,y2 = 0;
        cin >>x1>>y1>>x2>>y2;

        int result = 0;
        for(int j=x1; j<=x2; j++){
            result += (sum[j][y2] - sum[j][y1-1]);
        }

        cout<<result<<"\n";
    }
}
```

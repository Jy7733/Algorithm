#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin>>n>>m;

    int sum[n+1][n+1];

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

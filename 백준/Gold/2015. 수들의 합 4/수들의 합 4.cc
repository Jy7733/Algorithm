#include <bits/stdc++.h>

using namespace std;

int sum[200001];
map<int, long long> m;

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,k;
    cin>>n>>k;

    long long result = 0;

    for(int i=1; i<=n; i++){
        int x;
        cin>>x;
        sum[i] = sum[i-1] + x;

        if(sum[i] == k) result+=1;
    }

    for(int i=1; i<=n; i++){
        result += m[sum[i] - k]; 
        m[sum[i]]++;
    }

    cout<<result<<"\n";

}
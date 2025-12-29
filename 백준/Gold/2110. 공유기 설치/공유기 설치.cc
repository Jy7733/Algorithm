#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, c;
    cin>>n>>c;

    vector<int> a(n,0);

    for(int i=0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end()); 

    int st=1, en=a[n-1]-a[0]; 
    int dist=0; 
    
    int result = 0; 

    while(st <= en){
        dist = (st+en)/2;

        int count = 1; 
        int current = a[0]; 

        // 설치 가능한 공유기 개수 세기 
        for(int i=1; i<a.size(); i++){
            if(a[i] >= current + dist){
                current = a[i]; 
                count+=1;
            }
        }

        // 설치 가능 개수가 목표보다 크거나 같다면 -> 거리를 늘림 (더 적게 설치해야 하므로)
        if(count >= c) {
            st=dist+1;
            result = dist;
        }

        // 설치 가능 개수가 목표보다 작다면 -> 거리를 좁힘 (더 많이 설치해야 하므로)
        else if(count < c) en=dist-1; 
    }
    cout<<result<<"\n";
}
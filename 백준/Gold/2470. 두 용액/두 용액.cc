#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n; 
    vector<int> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i]; 

    vector<int> ans(2,0); 

    sort(a.begin(), a.end()); 
    int st=0, en=n-1; 
    ll sum = abs(a[st]+a[en]); 
    ans[0] = a[st]; ans[1] = a[en]; 

    while( st < en){
        
        ll tmp = abs(a[st]+a[en]); 
        if(sum > tmp){
            sum = tmp; 
            ans[0] = a[st]; 
            ans[1] = a[en]; 

            if(sum == 0){
                cout<<ans[0]<<" "<<ans[1]<<"\n";
                return 0; 
            }
        }
 
        if(a[st]+a[en] < 0){
            st+=1;
        }
        else{
            en-=1; 
        }
        
    }
    cout<<ans[0]<<" "<<ans[1]<<"\n";

}

#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    
    cin>>n;
    vector<int> a(n, 0);

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end()); 

    cin>>m; 

    for(int i=0; i<m; i++){
        int target; cin>>target; 

        cout<<upper_bound(a.begin(), a.end(), target) - lower_bound(a.begin(),a.end(),target)<<" ";
    }

}
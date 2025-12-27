#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<int> a(n,0);

    for(int i=0; i<n; i++) cin>>a[i]; 
    vector<int> tmp = a; 


    sort(tmp.begin(), tmp.end()); 

    
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end()); 

    for(int i=0; i<n; i++){
        int target = a[i]; 
        cout<<lower_bound(tmp.begin(), tmp.end(), target) - tmp.begin()<<" ";
    }


}
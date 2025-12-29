#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n; 
    vector<int> a(n,0);
    for(int i=0; i<n; i++) cin>>a[i]; 
    vector<int> tmp; 

    for(int i=0; i<n; i++){
        int cur = a[i]; 

        auto it = lower_bound(tmp.begin(), tmp.end(), cur); 
        if(it == tmp.end()) tmp.push_back(cur);
        else *it = cur; 
    }

    cout<<tmp.size()<<"\n";
}

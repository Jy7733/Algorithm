#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<int> v(n,0); 
    for(int i=0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end()); 

    int right=1; 
    for(int i=0; i<n; i++){
        if(right < v[i]){
            break;
        }
        right += v[i]; 
    }
    cout<<right<<"\n";
}
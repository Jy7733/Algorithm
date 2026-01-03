#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n; cin>>n;
    vector<pair<int,int>> v; 
    for(int i=0; i<n; i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b}); 
    }

    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<>> q;

    for(int i=0; i<n; i++){
        auto [start, end] = v[i]; 

        if(q.empty()){
            q.push(end); 
        }
        else{
            int prevEnd = q.top(); 
            if(start >= prevEnd){
                q.pop(); 
            }
            q.push(end); 
        }
    }
    cout<<q.size()<<"\n";
}
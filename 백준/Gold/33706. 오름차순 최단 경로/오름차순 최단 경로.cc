#include <bits/stdc++.h>

using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m;
  cin>>n>>m; 
  bool v[n+1]; 
  fill(v, v+n+1, false);
  
  v[1] = true;
  for(int i=0; i<m; i++){
    int a,b;
    cin>>a>>b; 

    v[b] = true; 
  }

  for(int i=2; i<=n; i++){
    if(!v[i]){ 
      cout<<"NO\n"; 
      return 0; 
    }
  }
  cout<<"YES\n"; 
  return 0; 
}


#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n,m; 
  cin>>n>>m; 

  int parity = 1; 
  if((n*m)%2 == 0) parity = 0; 

  int result = 0; 

  for(int r=1; r<=n; r++){
    for(int c=1; c<=m; c++){
      if((r+c) %2 == parity){
        cout<<"? "<<r<<" "<<c<<endl; 
        cin>>result; 
        if(result == 1) return 0; 
      }
    }
  }
}


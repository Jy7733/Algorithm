#include <bits/stdc++.h>

using namespace std;

int cnt[4]; 

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  for(int i=0; i<4; i++){
    cin>>cnt[i]; 
  }

  int sn = cnt[0] + cnt[3]; 
  int c = cnt[1] + cnt[2]*2; 

  int answer = min(sn/3, c/6); 
  cout<<answer<<"\n";
  return 0;
}


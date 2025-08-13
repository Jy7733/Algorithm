#include <bits/stdc++.h>

using namespace std;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin>>n;

  long long answer = 0; 

  for(int i=n; i>=1; i--){
    answer += i;
  }

  cout<<answer<<"\n";
}

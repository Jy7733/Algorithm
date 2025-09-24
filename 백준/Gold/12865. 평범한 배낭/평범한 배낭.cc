#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

int main(void){
  int n,k;
  cin>>n>>k; 

  int answer = 0; 
  vector<int> dp(k+1,0);
  vector<int> weight(n, 0);
  vector<int> value(n,0);

  for(int i=0; i<n; i++){
    cin>>weight[i]>>value[i];
  }

  for(int i=0; i<n; i++){ // i번 물품
    for(int w=k; w >= weight[i]; w--){
      dp[w] = max(dp[w], dp[w - weight[i]] + value[i]);  //w무게 만큼을 담았을 때의 value
    }
  }

  cout<<dp[k]<<"\n";

}
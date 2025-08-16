#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000000; 

vector<int> arr(MAX); 
vector<bool> notPrime(MAX+1); 

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin>>n;

  for(int i=0; i<n; i++){
    cin>>arr[i]; 
  }

  // 소수가 아닌지 판단 
  for(int i=2; i*i<=MAX; i++){
    if(!notPrime[i]){
      for(int j=i*i; j<=MAX; j+=i){
        notPrime[j] = true; 
      }
    }
  }

  for(int i=0; i<n; i++){
    if(notPrime[arr[i]] || ((i>0) && arr[i-1]!=1) && arr[i]!=1){
      cout<<"YES\n"; 
      return 0;
    }
  }

  // 배열이 오름차순인지 확인 
  for(int i=1; i<n; i++){
    if(arr[i-1] > arr[i]){
      cout<<"NO\n";
      return 0; 
    }
  }

  cout<<"YES\n";
  return 0;
}


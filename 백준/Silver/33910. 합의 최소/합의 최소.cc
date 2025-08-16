#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(void){
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll sum = 0; 
  ll minVal = LLONG_MAX; 
  int n; cin >> n;

  vector<ll> arr(n); 
  for(int i=0; i<n; i++){
    cin>>arr[i]; 
  } 
  reverse(arr.begin(), arr.end()); 

  for(auto a : arr){
    minVal = min(minVal, a); 
    sum += minVal; 
  }

  cout << sum << "\n";
}

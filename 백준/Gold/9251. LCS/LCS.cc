#include <bits/stdc++.h>

using namespace std;

int main(void){
  string str1; 
  string str2; 
  cin>>str1>>str2; 

  string x = ' '+str1;
  string y = ' '+str2; 

  vector<vector<int>> LCS(1001, vector<int>(1001,0)); 

  for(int i=1; i<x.size(); i++){
    for(int j=1; j<y.size(); j++){
      if(x[i] == y[j])
        LCS[i][j] = LCS[i-1][j-1] + 1; 
      else
        LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]); 
    }
  }
  cout<<LCS[x.size()-1][y.size()-1]<<"\n";
}

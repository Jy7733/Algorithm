#include <bits/stdc++.h>

using namespace std;

vector<int> used(101); 

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);

  int answer = 0; 

  int n; cin>>n;

  for(int i=0; i<n*3; i++){
    int num; cin>>num;
    used[num]++; 
  }

  for(int i=1; i<=98; i++){
    for(int j=i+1; j<=99; j++){
      for(int z=j+1; z<=100; z++){
        int maxVal = 0; 
        bool able = true; 

        used[i]++; 
        used[j]++;
        used[z]++; 

        if(used[z] == 1) maxVal=z; 
        else if(used[j] == 1) maxVal=j; 
        else if(used[i] == 1) maxVal =i; 

        // 모두 삭제되는 경우 불가능 
        if(used[i]>1 && used[j]>1 && used[z]>1){
          able=false;
        }
        // 선택한 숫자 중 최대값보다 큰 숫자가 남아있는 경우 불가능 
        for(int k=100; k>maxVal; k--){
          if(used[k] == 1){ 
            able=false;
            break;
          }
        }

        if(able) answer++;
        used[i]--; 
        used[j]--;
        used[z]--; 
      }
    }
  }
  cout<<answer<<"\n";
  return 0;
}

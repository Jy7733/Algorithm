#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

vector<pair<int,int>> pos; 
vector<bool> used; 
vector<int> shelter; 
int n, k;
int answer = INF;

int calDist(){
  vector<int> dist(n,INF); 
  for(int i=0; i<k; i++){
    
    int shelterIdx = shelter[i];
    int shelterX = pos[shelterIdx].first;
    int shelterY = pos[shelterIdx].second;

    for(int j=0; j<n; j++){
      int houseX = pos[j].first;
      int houseY = pos[j].second;

      int distance = abs(houseX - shelterX) + abs(houseY - shelterY);
      dist[j] = min(dist[j], distance); //j번째 집과 대피소까지 가장 가까운 거리 
    }
  }

  int maxDist = *max_element(dist.begin(), dist.end());
  return maxDist;
}


void backTracking(int selected, int start){
  if(selected == k){
    int ndist = calDist();
    answer = min(ndist, answer);
    return;
  }

  for(int i=start; i<n; i++){
    if(used[i]) continue;
    used[i] = true;
    shelter.push_back(i); 
    backTracking(selected+1, i+1);
    used[i] = false; 
    shelter.pop_back();
  }
}

int main(void){
  
  cin>>n>>k;

  for(int i=0; i<n; i++){
    int x,y;
    cin>>x>>y;
    pos.push_back({x,y});
  }
  used.resize(n,false);

  backTracking(0,0);
  cout<<answer<<"\n";
}
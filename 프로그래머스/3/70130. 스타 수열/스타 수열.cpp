#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int solution(std::vector<int> a) {
    int answer = 0;
    int n = a.size();
    map<int,int> m;
    vector<vector<int>> v(n);
//    vector<bool> used(n,false);

    if(n == 1) return 0;

    for(int i=0; i<n; i++){
      m[a[i]]++;
      v[a[i]].push_back(i);
    }
    vector<pii> mv(m.begin(), m.end());
    sort(mv.begin(), mv.end(),[](pii a, pii b){
      return a.second > b.second;
    });

    for(int i=0; i<mv.size(); i++){
      int x= mv[i].first;
      vector<bool> used(n,false);
      int tmp = 0;
      for(auto i : v[x]){
        if((i-1>=0) && !used[i-1] && !used[i] && (a[i-1] != a[i])){
          used[i-1] = true;
          used[i] = true;
          tmp +=2;
        }
        else if((i+1<n) && !used[i+1] && !used[i] &&(a[i+1] != a[i])){
          used[i+1] = true;
          used[i] = true;
          tmp +=2;
        }
      }
      answer = max(tmp, answer);
    }


    return answer;
}
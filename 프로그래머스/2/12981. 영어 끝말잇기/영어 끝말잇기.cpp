#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer = {0,0};

    // 이미 나왔던 단어인지 확인하기 위한 map
    map<string,int> existWords;
    for(int i=0; i<words.size(); i++){
      // 탈락하는경우
      if((existWords[words[i]] != 0)
          || ((i >= 1) && (words[i][0] != words[i-1][words[i-1].size() - 1])))
      {
        int num = (i%n) + 1;
        int turn = (i/n) + 1;
        return {num,turn};
      }
      
      existWords[words[i]]++;
    }
    return answer;
}

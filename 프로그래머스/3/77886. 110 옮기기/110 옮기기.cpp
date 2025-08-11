#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> s) {
    vector<string> answer;

    for(auto str : s){
      // 110 검색
      int cnt = 0;
      string tmp = "";

      for(auto c : str){
        tmp.push_back(c);

        // "110" 탐색
        if(tmp.size() >= 3
          && tmp[tmp.size()-3] == '1'
          && tmp[tmp.size()-2] == '1'
          && tmp[tmp.size()-1] == '0'){
            tmp.erase(tmp.size()-3, 3);
            cnt++;
        }
      }

        // 마지막으로 0이 있는 곳 검색
        int last0Index = -1;
        for(int i=(int)tmp.size()-1; i>=0; i--){
          if(tmp[i] == '0'){
            last0Index = i+1;
            break;
          }
        }

        // 삽입할 문자열 생성 
        string insertString;
        for(int i=0; i<cnt; i++){
          insertString += "110";
        }

        // 0이 없다면 맨 앞에
        if(last0Index == -1){
          answer.push_back(insertString + tmp);
        }else{
          answer.push_back(tmp.substr(0,last0Index) + insertString + tmp.substr(last0Index));
        }
    }
    return answer;
}

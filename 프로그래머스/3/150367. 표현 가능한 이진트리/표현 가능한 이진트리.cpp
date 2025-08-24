#include <bits/stdc++.h>

using namespace std;

typedef long long ll; 

string toBinary(ll num){
  string str = ""; 
  while(num != 0){
    str += (num % 2) + '0';
    num /= 2; 
  }
  reverse(str.begin(), str.end()); 

  int len = str.size(); 
  int h = 1;
  while((1LL << h) - 1 < len) h++; 
  int fullLen = (1LL << h) - 1;
  str = string(fullLen - len, '0') + str;

  return str; 
}

//가능 여부 탐색 
bool check(string str){
  
  int n = str.size();
  if(n ==1) return true; 

  int root = n/2; 

  string left = str.substr(0,root);
  string right = str.substr(root+1);

  if(str[root] == '0'){
    if(left.find('1') != string::npos || right.find('1') != string::npos){
      return false; 
    }
  }

  return check(left) && check(right); 
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for(auto num : numbers){
      string binStr = toBinary(num); 
      bool able = check(binStr); 
      if(able) answer.push_back(1);
      else answer.push_back(0);
    }

    return answer;
}

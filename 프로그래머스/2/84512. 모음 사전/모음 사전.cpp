#include <bits/stdc++.h>
using namespace std;

string order = "AEIOU";
int cnt = 0; 
int answer = 0; 
bool found = false;

void func(string word, string tmp){
    if(found) return;  // 이미 찾았으면 종료

    if(word == tmp){
        answer = cnt;
        found = true;
        return;
    }

    for(int i=0; i<5; i++){
        if(tmp.size() < 5){
            cnt++; // 새 단어가 만들어질 때마다 증가
            func(word, tmp + order[i]);
        }
    }
}

int solution(string word) {
    func(word, "");
    return answer;
}

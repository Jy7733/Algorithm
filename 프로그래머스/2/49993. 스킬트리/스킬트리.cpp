#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> m; 
    for(auto s : skill){
        m[s]++;
    }
    
    for(string st : skill_trees){
        int i=0; //포인터 역할 
        bool able = true;
        for(char c : st){
            // skill에 명시된 skill 인 경우
            if(m[c] > 0){
                if(c == skill[i]){
                    i++;
                }
                else{
                    able = false;
                    continue;
                }
            }
        }
        if(able) answer++;
    }
    
    return answer;
}
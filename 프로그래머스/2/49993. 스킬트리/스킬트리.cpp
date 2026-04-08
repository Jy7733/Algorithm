#include <bits/stdc++.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    map<char,int> m;
    
    for(auto s : skill){
        m[s]++;
    }
    
    for(auto st : skill_trees){
        int i=0;
        bool able = true; 
        for(auto c : st){
            if(m[c] > 0){
                if(c==skill[i]) i++;
                else{
                    able = false;
                    break;
                }
            }
        }
        if(able) answer+=1; 
    }
    
    
    return answer;
}
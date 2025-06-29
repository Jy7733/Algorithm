#include <bits/stdc++.h>

using namespace std;

int length = 0;
int answer = 0;
vector<vector<string>> bannedList;
map<string, int> m;
set<set<string>> resultSet;

void backTracking(int k, set<string> tmp){
    if(k == length){
        resultSet.insert(tmp);
        return;
    }
    
    for(int i=0; i<bannedList[k].size(); i++){
        if(m[bannedList[k][i]] == 0){
            m[bannedList[k][i]]++;
            tmp.insert(bannedList[k][i]);
            backTracking(k+1, tmp);
            m[bannedList[k][i]]--;
            tmp.erase(bannedList[k][i]);
        }
    }
    return;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    
    length = banned_id.size();
    bannedList.resize(length);                                                                         
    
    for(int i=0; i<banned_id.size(); i++){
        for(auto id : user_id){
            if(banned_id[i].size() != id.size()) continue;
            bool same = true;
            for(int j=0; j<banned_id[i].size(); j++){
                if(banned_id[i][j] != '*' && banned_id[i][j] != id[j]){
                    same = false;
                    break;
                }
            }
            if(same) bannedList[i].push_back(id);
        }
    }
    
    set<string> tmp;
    backTracking(0,tmp);
    answer = resultSet.size();
    return answer;
}

// *rodo -> frodo, crodo
// *rodo -> frodo, crodo
// ****** -> abc123, frodoc                 
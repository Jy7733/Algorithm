#include <bits/stdc++.h>

using namespace std;

int answer = INT_MAX;
bool visited[51];

bool checkChange(string a, string b){
    int diff = 0;
    for(int i=0; i < a.size(); i++){
        if(a[i] != b[i]){
            diff++;
        }
    }
    
    if(diff == 1) return true;
    else return false;
}

void DFS(string begin, string target, vector<string> words, int depth){
    //종료조건 : target 과 동일한 단어가 만들어진 경우 
    if(begin == target){
        answer = min(depth, answer);
        return;
    }
    
    for(int i=0; i<words.size(); i++){
        if(checkChange(begin, words[i]) && !visited[i]){
            visited[i] = true;
            DFS(words[i], target, words, depth+1);
            visited[i] = false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    
    DFS(begin, target, words, 0);
    
    if(answer == INT_MAX) return 0;
    else return answer;
}
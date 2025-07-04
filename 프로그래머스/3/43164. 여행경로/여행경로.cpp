#include <bits/stdc++.h>

using namespace std;

bool visited[10001];
vector<string> answer;
bool isAnswer;

void DFS(string start, vector<vector<string>> tickets, int cnt){

    answer.push_back(start);

    if(cnt == tickets.size()){
        isAnswer = true;
        return;
    }
    
    for(int i=0; i<tickets.size(); i++){
        if(visited[i]) continue;
        if(start == tickets[i][0]){
            visited[i] = true;
            DFS(tickets[i][1], tickets, cnt+1);

            if(!isAnswer){
                answer.pop_back();
                visited[i] = false;
            }
        }
    }

}

vector<string> solution(vector<vector<string>> tickets) {

    sort(tickets.begin(), tickets.end());
    string start = tickets[0][0];

    DFS("ICN", tickets,0);
    
    return answer;
}
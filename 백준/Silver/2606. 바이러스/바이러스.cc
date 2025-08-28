#include <iostream>
#include <vector>

using namespace std;

vector<int> arr[101];
bool visited[101];

int cnt = 0; //바이러스 걸린 컴퓨터 수 

void dfs(int start){
    
    if(!visited[start]) cnt+=1;
    visited[start] = true; //방문 처리 
    
    //인접 노드 체크 
    for(int i=0; i<arr[start].size(); i++){
        int y = arr[start][i]; //체크할 노드 
        if(!visited[y]){
            dfs(y);
        }
    }
}

int main(void){
    int n,m;
    
    cin>>n; //컴퓨터 개수 
    cin>>m; //쌍 개수 
    
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    
    dfs(1);
    cout<<cnt-1; //1빼고 감염된 컴퓨터 개수 출력
}
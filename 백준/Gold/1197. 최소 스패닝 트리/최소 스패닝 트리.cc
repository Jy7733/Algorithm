#include <bits/stdc++.h>
using namespace std;

vector< pair<int, pair<int,int>>> arr;

int parents[10001];

//부모 노드 찾기 
int find(int node){
    //node 가 parents 배열에서 가리키는 값이 자기 자신이면 -> 루트노드임을 의미 
    if(parents[node] == node ) return node;

    //node 가 루트노드가 아니라면 
    //최종적으로 찾은 루트 노드를 부모노드로 지정해줌 
    return parents[node] = find(parents[node]);
}

//두 노드 연결하기 
void unionNodes(int v1,int v2){
    v1 = find(v1); // v1 의 루트 노드 
    v2 = find(v2); // v2 의 루트 노드 

    // 두 노드의 루트노드가 동일하지 않다면 (-> cycle 이 발생하지 않는 경우 )
    if(parents[v1] != parents[v2]) parents[v2] = v1; //하나의 루트 노드로 병합하기 

}

int main(void){

    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int result = 0;  //최종 가중치 
    int edge = 0; //간선 개수 

    int v,e;
    cin>>v>>e;

    for(int i=0; i<e; i++){
        int v1,v2,cost;
        cin>>v1>>v2>>cost;
        
        arr.push_back({cost, {v1,v2}});
    }

    sort(arr.begin(),arr.end());

    //초기 세팅 - 모든 노드의 부모노드는 본인 
    for(int i=1; i<=v; i++){
        parents[i] = i; 
    }

    for(int i=0; i<arr.size(); i++){
        int curCost = arr[i].first;
        int node1 = arr[i].second.first; // 부모노드 
        int node2 = arr[i].second.second; // 현재 노드 

        if(edge == (v-1)) break;

        // 두 노드의 루트노드가 다른 경우 (cycle 이 발생하지 않는 경우)
        if(find(node1) != find(node2)){
            unionNodes(node1,node2); // 병합 
            result+=curCost; 
            edge+=1; 
            if(edge == v-1) break;
        }
    }

    cout<<result<<"\n";
}
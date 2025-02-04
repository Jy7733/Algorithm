#include <bits/stdc++.h>
#define INF (~0U >> 2)

using namespace std;

int foxDist[4001];
int wolfDist[2][4001]; //wolfDist[0][x] = x노드에 늑대가 1/2배 느리게 들어올 때의 비용 
vector<pair<int,int>> adj[4001];
int n,m;

//여우 -> 일반 다익스트라로 구현 
void foxDijkstra(){
	fill(foxDist,foxDist + n + 1, INF);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	pq.push({0,1});
	foxDist[1] = 0;

	while(!pq.empty()){
		auto Cur = pq.top(); pq.pop();
		int curCost = Cur.first;
		int curNode = Cur.second;

		if(foxDist[curNode] != curCost) continue;

		for(auto next : adj[curNode]){
			int nextCost = next.first;
			int nextNode = next.second;

			if(foxDist[nextNode] > curCost + nextCost){
				foxDist[nextNode] = curCost + nextCost;
				pq.push({foxDist[nextNode], nextNode});
			}
		}

	}
}

void wolfDijkstra(){
	fill(wolfDist[0], wolfDist[0]+n+1, INF);
	fill(wolfDist[1], wolfDist[1]+n+1, INF);

	// dist, {node, state} 형태로 저장 ( state = 0 -> 1/2 느리게, state=1 -> 2배 빠르게 )
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq; 
	pq.push({0,{1,1}}); //첫 노드(1) 의 비용은 0, 다음 노드로 2배 빠르게 이동함

	while(!pq.empty()){
		auto Cur = pq.top(); pq.pop();
		int curCost = Cur.first;
		int curNode = Cur.second.first;
		int curState = Cur.second.second;

		//현재 노드에서 2배로 간다면 : 이전에 1/2배로 이동한 것이므로 foxDist[0][x] 와 비교 
		//현재 노드에서 1/2배로 간다면 : 이전에 2배로 이동한 것이므로 foxDist[1][x] 와 비교 
		if(wolfDist[(curState + 1)%2][curNode] < curCost) continue;

		for(auto next : adj[curNode]){
			int nextCost = next.first;
			int nextNode = next.second;

			//현재 노드에서 2배로 가는 경우 
			if(curState == 1){
				nextCost = nextCost/2;
				if(wolfDist[1][nextNode] > curCost + nextCost){
					wolfDist[1][nextNode] = curCost + nextCost;
					pq.push({wolfDist[1][nextNode], {nextNode, 0}}); 
				}
			}
			else if(curState == 0){
				nextCost = nextCost * 2; 
				if(wolfDist[0][nextNode] > curCost + nextCost){
					wolfDist[0][nextNode] = curCost + nextCost;
					pq.push({wolfDist[0][nextNode], {nextNode,1}});
				}
			}
		}
		
	}
}

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin>>n>>m;

	for(int i=0; i<m; i++){
		int a,b,d;
		cin>>a>>b>>d;
		adj[a].push_back({d*2,b});
		adj[b].push_back({d*2,a});
	}

	foxDijkstra();
	wolfDijkstra();

	int result = 0;
	for(int i=2; i<=n; i++){
		if(foxDist[i] < min(wolfDist[0][i], wolfDist[1][i])) result +=1;
	}

	cout<<result<<"\n";
}

## 💡알고리즘 분류

- 그래프 이론
- 최단 경로
- 데이크스트라

## 🔎 접근 방법

여우, 늑대에 대하여 각각 다익스트라 알고리즘으로 비용 저장 → 비교 

늑대 → 홀수 번째면 비용을 1/2 배로 계산 → 몇 번째 이동인지 저장하는 배열 필요 

다익스트라를 따로. ? 

- 늑대의 경우 경로 비용이 바뀌기 때문에 한 단계 한 단계 체크하면 최소 비용을 찾을 수 없음
    - ex) 4 까지 가는 데 최소 비용
        - 1 에서 2까지 가는 최소 비용은 1이지만 ,
        - 1에서 4까지 가는 최소 비용은: 1 → 3 → 2 → 4 로 가야하는데,
            
            이때의 2까지 가는 비용은 1 → 3 → 2 ⇒ 5이다. 
            
        - 근데 문제는, 1 → 3 → 2 에서 d[2] 를 업데이트 하려고 할 때, d[2] = 1 이기 때문에 1로 남아있게 된다.
            
            그래서 4까지 가는 최소비용을 잘못 계산하게 됨! 
            
- DFS 도 생각해봤지만, 시간초과가 날 것 같았다!

### 🔑 해답을 보고 알게 된 전략! : 느리게 들어오는 경우 vs 빠르게 들어오는 경우를 구별 !

**`dist[0][x]`** = 늑대가 x노드에 느리게 들어올 때의 최소 비용 저장

**`dist[1][x]`** = 늑대가 x노드에 빠르게 들어올 때의 치소 비용 저장 

- 여우에 대한 다익스트라는 기본적인 다익스트라로 구현

### **늑대에 대한 다익스트라 ⬇️**

⭐️ 1번 노드에 대한 dist 배열을 0으로 초기화 하지 않는다! 

→ 1번을 다시 거쳐가는 경우가 더 빠를 수도 있으므로! 

⭐️ 소수점 문제를 피하기 위해 입력을 받을 때 cost * 2 로 받는다! 

⭐️ 늑대의 경우 1번 노드를 0으로 초기화하지 않기 때문에 마지막에 여우 배열과 비교할 때 2번 노드부터 비교를 해줘야 한다! 

```cpp
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
```

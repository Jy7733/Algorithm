

## 💡알고리즘 분류
- 다이나믹 프로그래밍
- 그래프 이론
- 위상 정렬
- 방향 비순환 그래프

…이지만 나는 그냥 맘대로 구현해부렸다..ㅎㅎ

## 🔎 접근 방법

- semester[i] = i 번 과목을 듣기 위한 최소 학기로 정의한다.
- ⭐️ 고민했던 부분
    - 입력을 들어온 순서대로 처리하면, 예를 들어 (2,3) , (1,2) 순서대로 처리한다면
        
        `semester[2]`, `semester[3]`을 계산하고 `semester[1]`, `semester[2]`가 업데이트 되면서 다시 pre[3] 을 업데이트 해야한다는 문제가 있다.
        
        즉, **연결된 모든 노드**들의 semester[i] 값을 업데이트 해야한다.
        
- 이걸 어떻게 추적해야 할까 고민하던 중, **입력 (A, B)는 항상 A < B 를 만족한다**는 조건을 확인했다.
- **입력 (A, B)는 항상 A < B 를 만족한다는 조건에서 :**
    - 항상 A번 과목을 들어야 B번 과목을 들을 수 있다 = 즉, (3,1) (4,1) 이런 입력은 없다는 뜻
    - 이 조건을 활용해서 **A가 작은 순서대로 정렬하면 자연스럽게 선수 과목을 먼저 처리**할 수 있겠다라는 아이디어를 생각해 냈다!
        
        1번 과목 다음 들을 수 있는 과목들의 semester[i] 값들을 업데이트하고, 
        
        2번 과목 다음 들을 수 있는 과목들의 semester[i] 값들을 업데이트하고 …. 반복
        
        이렇게 하면 연결된 모든 과목들을 추적하지 않아도 업데이트 할 수 있다고 생각했다. 
        

- **이 아이디어를 토대로 구현하면 :**
    - A 를 기준으로 정렬하기 위해 → priority_queue를 사용
    - semester 배열은 INF로 일단 채워두고,
    - 만약 `semester[A] = INF` 라면, 1학기로 두고 (처음으로 처리하는 경우이므로!)
        - `semester[B] = IN`F라면, 바로 `semester[A] + 1` 로 업데이트
        - INF가 아니라면, `semester[A] + 1` 과 `semester[B]` (= 기존 값) 중에 더 큰 값으로 업데이트


```cpp
#include <bits/stdc++.h>
#define INF (~0U >> 2)

typedef long long ll;

using namespace std;

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> seq;

int main(void){
	int n,m;
	cin>>n>>m;

	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		seq.push({a,b});
	}

	ll semester[n+1]; 
	fill(semester, semester+n+1, INF);

	while(!seq.empty()){
		auto cur = seq.top();
		int pre = cur.first;
		int next = cur.second;
		seq.pop();

		if(semester[pre] == INF){
			semester[pre] = 1;
		}

		if(semester[next] == INF) semester[next] = semester[pre]+1;
		else semester[next] = max(semester[next],semester[pre] + 1);
	}

	for(int i=1; i<=n; i++){
		if(semester[i] == INF) cout<<"1 ";
		else cout<<semester[i]<<" ";
	}

}
```

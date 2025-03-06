## 💡 알고리즘 분류

- 이분 탐색
- 매개변수 탐색

## 🔎 접근 방법

**조건 확인하기** 

1 ≤ N ≤ 1,000,000 ⇒ 반복문 한 번 정도만 허용될 것! (시간제한이 1초이기 때문) 

1 ≤ M ≤ 2,000,000,000

0 ≤ H ≤ 1,000,000,000

**구해야 하는 것 !  :  M 미터**의 나무를 가져갈 수 있는 **최대 H (높이) 값**

✅ 최적화 문제 ⇒ 일단 **이진 탐색**을 고려해보자 ! 

### 구현

H의 최대 (max)  → 입력받은 나무의 크기 중 최댓값으로 설정

H의 최소 (min) → 0으로 설정 

**자를 수 있을 때 까지 (min ≤ max) 아래 로직을 반복 ⬇️**

1. H 를 max 와 min 의 중간으로 설정 
2. 입력받은 나무 배열을 돌면서 가져갈 수 있는 나무의 크기 합 계산 (sum) 
    1. sum ≥ 목표길이 (M) 이라면 : min 값을 H+1 로 설정 & result 값을 h 로 설정 
    2. sum < 목표길이 (M) 이라면 : max 값은 H-1 로 설정 
3. 최종 result 값을 출력 

```cpp
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll m, min, max, sum, result;
	ll trees[1000001];

	cin>>n>>m;

	for(int i=0; i<n; i++){
		cin>>trees[i];
	}

	sort(trees, trees+n);
	max = trees[n-1];
	min = 0;

	while(min <= max){
		ll h = (min + max)/2;
		sum = 0;

		for(int i=0; i<n; i++) if(trees[i] - h > 0) sum += (trees[i] - h);

		if(sum >= m){
			result = h;
			min = h + 1;
		}
		else{
			max = h-1;
		}
	}

	cout<<result<<"\n";

}
```

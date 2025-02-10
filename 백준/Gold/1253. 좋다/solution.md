## 💡 알고리즘 분류

- 정렬
- 이분 탐색
- 두 포인터

## 🔎 접근 방법

- n ≤ 2000 이니까 100,000 번 정도까지는 반복이 가능 → 다 기록해도 괜찮을 것 같다.
    - 그래서 루프 2번 돌면서 map 에 더한 값과 갯수 추가하는 방향으로 생각!

### 🚨 생각해야 했던 반례 !

0 1 2 3 이 있을 때

- 0 + 1 = 1 인데, map에 { 1 : 1 } 로 들어가서 1을 두 수의 합으로 만들 수 있는 것으로 체크 됨
- 하지만, 사실은 불가능!
- 이 부분을 고려해야 한다.

### 🔑 정렬하기!

정렬하고, 검사하는게 키포인트! 

0, 1, 2, 3 이 정렬된 것임을 알고 있을 때

input[0] + input[1] = 1 이고, 만약에 input[1] 이외에 1이 있다면, 바로 다음 인덱스에 들어있을 것이다. 

그래서 input[2] = 1 이었다면, 두 수의 합으로 1을 만들 수 있는 것이니까 카운트해도 괜찮다. 

하지만, input[2] ≠ 1 이니까 이 경우에서는 카운트 하지 않는다. 

다음과 같이 조건문을 만들 수 있다! 

```cpp
if(sum == input[j] && j+1 < n){
	if(input[j+1] == sum) sumMap[sum] +=1;
}

else if(sum == input[i] && i-1 >= 0){
	if(input[i-1] == sum) sumMap[sum] +=1;
}

else if(sum != input[j] && sum != input[i]) sumMap[sum] +=1;
```

```cpp
#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	ll num;
	int result = 0;

	cin>>n;
	ll input[n];
	map<ll, ll> sumMap;
	
	for(int i=0; i<n; i++){
		cin>>num;
		input[i] = num;
	}

	sort(input, input+n);

	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			ll sum = input[i] + input[j];
			if(sum == input[j] && j+1 < n){
				if(input[j+1] == sum) sumMap[sum] +=1;
			}
			else if(sum == input[i] && i-1 >= 0){
				if(input[i-1] == sum) sumMap[sum] +=1;
			}
			else if(sum != input[j] && sum != input[i]) sumMap[sum] +=1;
		}
	}

	for(int i=0; i<n; i++){
		if(sumMap[input[i]] > 0 ) result+=1;
	}

	cout<<result<<"\n";

}
```

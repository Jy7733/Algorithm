## 💡알고리즘 분류

- 수학
- 정수론
- 소수 판정
- 에라토스테네스의 체

## 🔎 접근 방법

### 🚨 알아야 했던 것!! - 에라토스테네스의 체

에라토스테네의 체로 푸는 문제를 풀어본적이 없어서 떠올리지 못했다!! 

소수가 아닌 값을 지워나가는 것 처럼, 이 문제에서는 제곱수의 배수인 값들을 지워나가면 된다. 

- **🔥 해결하면서 겪은 문제 !**

  **min, max 가 10^12 이상이기 때문에, max 크기만큼의 배열을 생성하면 —> 런타임 에러가 발생한다.**  
  
  따라서, `max - min + 1` 크기의 배열로, 이를 방지할 수 있다. 
  
  이렇게 되면 arr[0] 값은 min 값에 대한 값임에 주의해야 한다!! 

- **구현 :**
    - for 문에서, min 다음으로 나오는 숫자 중 처음으로 제곱 수의 배수인 값부터 검사를 시작해야 한다.
        - `min % (i*i)` (min 이 제곱수의 배수라면)  → `start = min` min 부터 검사 시작!
        - min이 제곱 수의 배수가 아니라면 → `start = ((min / i*i ) + 1) * (i*i)`
            
            ex) min = 10, i*i = 4 인 경우, 
            
            10 / 4 = 2 → 10 보다 작으면서 4의 배수인 값은 2 * 4 = 8
            
            min보다 크면서 첫 번재 i*i 의 배수를 구해야 하므로 (2 + 1 ) * 4 = 12 를 통해 구한다. 
            
    - `j = start` 부터 시작해서 `i*i`씩 증가하면서 검사를 진행한다.

```cpp
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	ll min, max = 0;
	ll result = 0;
	cin>>min>>max;

	vector<bool> arr(max - min + 1, false); //제곱수의 배수라면 true

	for(ll i=2; i*i <= max; i++){

		ll start = 0;
		
		//min 이상인 첫 번째 수 검색 
		if(min % (i*i) == 0){ // min = 제곱수의 배수인 경우 
			start = min;
		}
		else{
			start = (min/(i*i) + 1) * (i*i);
		}

		//j가 제곱수의 배수인 경우 
		for(ll j = start; j<=max; j+=(i*i)){
			arr[j - min] = true; 
		}
	}

	for(ll i=min; i <= max; i++){
		if(arr[i - min] == false) result+=1;
	}
	cout<<result<<"\n";

}
```

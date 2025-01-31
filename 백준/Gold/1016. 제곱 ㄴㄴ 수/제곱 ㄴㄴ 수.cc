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
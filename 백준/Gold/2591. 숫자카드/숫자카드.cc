#include <bits/stdc++.h>

using namespace std;

vector<int> input;

stack<int> s;

int cnt;

void countCombination(int k){

	if(k >= input.size()){
		cnt+=1;
		return;
	}

	// if(input[k+1] == 0) return;
	// else countCombination(k+1);
	if(input[k] != 0) countCombination(k+1);

	//묶을 수 있다면 ( 1이상, 34이하 )
	if(k + 1 < input.size() && input[k] != 0){
		int num = input[k] * 10 + input[k+1];

		if(num >= 1 && num <= 34) countCombination(k+2);
	}
	// if(input[k]*10 + input[k+1] <= 34 && input[k]*10 + input[k+1] >= 1 && input[k] != 0){
	// 	if(k + 2 > input.size()-1) {
	// 		if(input[input.size()-1] == 0) return;
	// 		else countCombination(input.size()-1);
	// 	}
	// 	else countCombination(k+2);
	// }

}

int main(void){

	ios::sync_with_stdio(0);
	cin.tie(0);

	string str; 
	cin>>str;

	//숫자로 변환 
	for(int i=0; i<str.size(); i++){
		input.push_back(str[i] - '0');
	}

	countCombination(0);
	cout<<cnt<<"\n";
}
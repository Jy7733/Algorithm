#include <bits/stdc++.h>

using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;

    vector< vector<int>> result(t);

    for(int j=0; j<t; j++){
        int m;
        cin>>m;

        priority_queue<int> Left;
        priority_queue<int, vector<int>, greater<int>> Right;
        int mid = 0;

        for(int i=1; i<=m; i++){
            int input; 
            cin>>input; 

            if(i == 1){
                mid = input;
                // cout<<mid<<" ";
                result[j].push_back(mid);
            }

            //짝수 번째인 경우 
            if(i % 2 == 0){
                //mid 값과 비교 
                if( input <= mid) {
                    Left.push(input);
                    Right.push(mid);
                }
                else if(input > mid) {
                    Right.push(input);
                    Left.push(mid);
                }
            }

            //홀수 번째인 경우 
            else if(i % 2 != 0 && i > 1){
                int leftTop = Left.top();
                int rightTop = Right.top();

                if(input <= leftTop){
                    mid = leftTop;
                    Left.pop();
                    Left.push(input);
                }
                else if(input >= rightTop){
                    mid = rightTop;
                    Right.pop();
                    Right.push(input);
                }
                else if(input > leftTop && input < rightTop){
                    mid = input;
                }

                // cout<<mid<<" ";
                result[j].push_back(mid);
            }
        }
    }

    for(int i=0; i<t; i++){
        cout<<result[i].size()<<"\n";
        for(auto value : result[i]){
            cout<<value<<" ";
        }
        cout<<"\n";
    }
}
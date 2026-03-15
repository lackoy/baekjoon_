#include<iostream>
using namespace std;

int N, answer;
int main(){
    cin >> N;
    while(N >= 0){
        if(N%5 == 0){
            answer += N/5;
            cout << answer << endl;
            return 0;
        }
        N -= 3;
        answer++;
    }

    cout << -1 << endl; 
}

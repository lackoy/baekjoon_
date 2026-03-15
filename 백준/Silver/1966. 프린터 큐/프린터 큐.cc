#include <iostream>
#include <queue>
using namespace std;

int n, m, ipt, test_case;
int main(){
    int count = 0;
    cin >> test_case;
    
    for(int i = 0; i < test_case; ++i){
        cin >> n >> m;
        count = 0;

        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for(int j = 0; j < n; ++j){
            cin >> ipt;
            q.push({j, ipt});
            pq.push(ipt);
        }

        while(!q.empty()){
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if(pq.top() == value){
                pq.pop();
                ++count;

                if(index == m){
                    cout << count << "\n";
                    break;
                }
            }
            else q.push({index, value});
        }
    }
}
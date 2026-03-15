#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;
int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        q.push(i);
    
    cout << "<";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k-1; j++){
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if(i == n-1) cout << ">";
        else cout << ", ";
    }

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int n, a;
string s;
queue<int> q;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            cin >> a;
            q.push(a);
        }else if(s == "pop"){
            if(!q.empty()){
                cout << q.front() << "\n";
                q.pop();
            }else cout << "-1\n";
        }else if(s == "size"){
            cout << q.size() << "\n";
        }else if(s == "empty"){
            if(q.empty()) cout << "1\n";
            else cout << "0\n";
        }else if(s == "front"){
            if(!q.empty()) cout << q.front() << "\n";
            else cout << "-1\n";
        }else if(s == "back"){
            if(!q.empty()) cout << q.back() << "\n";
            else cout << "-1\n";
        }
    }

    return 0;
}
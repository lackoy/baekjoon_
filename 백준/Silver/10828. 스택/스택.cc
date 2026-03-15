#include <iostream>
#include <stack>
using namespace std;

int n, a;
string s;
stack<int> st;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        if(s == "push"){
            cin >> a;
            st.push(a);
        }else if(s == "pop"){
            if(!st.empty()){
                cout << st.top() << "\n";
                st.pop();
            }else cout << "-1\n";
        }else if(s == "size"){
            cout << st.size() << "\n";
        }else if(s == "empty"){
            if(st.empty()) cout << "1\n";
            else cout << "0\n";
        }else if(s == "top"){
            if(st.empty()) cout << "-1\n";
            else cout << st.top() << "\n";
        }
    }

    return 0;
}
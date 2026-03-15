#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int testcase;
    cin >> testcase;

    while(testcase--) {
        stack<char> st;
        string s;
        cin >> s;
        
        for(int j = 0; j < s.length(); j++) {
            if(st.empty()) st.push(s[j]);
            else{
                if(st.top() == '(' && s[j] == ')') st.pop();
                else st.push(s[j]);
            }
        }
        if(st.empty()) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}
#include <iostream>
#include <string>
using namespace std;

int M, x, bitmask;
string str;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M;
    for(int i = 0; i < M; ++i){
        cin >> str;
        
        if(str == "add"){
            cin >> x;
            bitmask = bitmask | (1 << (x-1));
        }else if(str == "remove"){
            cin >> x;
            bitmask = bitmask & ~(1 << (x-1));
        }else  if(str == "check"){
            cin >> x;
            bool tmp = bitmask & (1 << (x-1));

            if(tmp) cout << 1 << '\n';
            else cout << 0 << '\n';
        }else if(str == "toggle"){
            cin >> x;
            bitmask = bitmask ^ (1 << (x-1));
        } else if (str == "all") bitmask = (1 << 20)-1;
        else if (str == "empty") bitmask = 0;
    }

    return 0;
}
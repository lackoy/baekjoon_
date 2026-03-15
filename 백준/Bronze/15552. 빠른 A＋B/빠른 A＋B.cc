#include <iostream>
using namespace std;

int n, a, b;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        cout << a+b << "\n";
    }
    
    return 0;
}
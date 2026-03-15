#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, cnt = 0;
    cin >> n;

    while(n != 0){
        if(n%125 == 0) cnt += 3;
        else if(n%25 == 0) cnt += 2;
        else if(n%5 == 0) cnt++;
        n--;
    }

    cout << cnt;
    
    return 0;
}
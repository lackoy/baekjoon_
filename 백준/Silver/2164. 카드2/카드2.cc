#include <iostream>
#include <deque>
using namespace std;

int n, a;
deque<int> d;
int main(){
    cin >> n;

    for(int i = 1; i <= n; i++)
        d.push_back(i);

    while(d.size() > 1){
        d.pop_front();
        a = d.front();
        d.pop_front();
        d.push_back(a);
    }

    cout << d.front();

    return 0;
}
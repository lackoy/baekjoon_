#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if(a % b == 0) return b;
    else return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

int n, m;
int main(){
    cin >> n >> m;
    cout << gcd(n, m) << "\n" << lcm(n, m);

    return 0;
}
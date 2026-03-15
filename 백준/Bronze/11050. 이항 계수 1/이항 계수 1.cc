#include <iostream>
using namespace std;

int factorial(int num){
    if(num == 0|| num == 1) return 1;
    return num*factorial(num-1);
}

int n, k;
int main(){
    cin >> n >> k;
    cout << factorial(n)/(factorial(k)*factorial(n-k));

    return 0;
}
#include <iostream>
using namespace std;

int number, i = 0;
int main(){
    cin >> number;

    for(int sum = 2; sum <= number; i++)
        sum += 6*i;
    
    if(number == 1) i = 1;
    cout << i;
    
    return 0;
}
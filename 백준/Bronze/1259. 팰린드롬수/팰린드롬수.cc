#include <iostream>
#include <math.h>
using namespace std;

int n;
int main() {

    while(1) {
        int t = 0;
        cin >> n;

        if(n == 0) break;
        else{
            int len = to_string(abs(n)).length();
            int j = pow(10, len);

            for(int i = n; i > 0; i /= 10) {
                t += (i%10)*j;
                j /= 10;
            }
            
            if(t/10 == n) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}
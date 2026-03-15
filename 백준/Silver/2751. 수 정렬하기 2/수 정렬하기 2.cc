#include <iostream>
#include <algorithm>
using namespace std;

int n, arr[1000001];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << "\n";

    return 0;
}
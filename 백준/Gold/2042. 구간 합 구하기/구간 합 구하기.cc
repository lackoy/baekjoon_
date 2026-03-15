#include <iostream>
using namespace std;
#define MAX 1000001
    
int N, M, K;
long long arr[MAX], segTree[4000004];
long long init(int start, int end, int nodeNum){
    if(start == end) return segTree[nodeNum] = arr[start];
    
    int mid = (start+end)/2;
    return segTree[nodeNum] = init(start, mid, nodeNum*2)+init(mid+1, end, nodeNum*2+1);
}

long long subSum(int start, int end, int nodeNum, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return segTree[nodeNum];
    int mid = (start+end)/2;
    return subSum(start, mid, nodeNum*2, left, right)+subSum(mid+1, end, nodeNum*2+1, left, right);
}
    
void update(int start, int end, int nodeNum, int targetIdx, long long val){
    if (targetIdx < start || end < targetIdx) return;
    
    segTree[nodeNum] += val;
    if(start == end) return;
    int mid = (start+end)/2;
    update(start, mid, nodeNum*2, targetIdx, val);
    update(mid+1, end, nodeNum*2+1, targetIdx, val);
}
    
int main(){
    cin >> N >> M >> K;
    
    int num;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    init(0, N - 1, 1);
    
    long long a, b, c;
    for (int i = 0; i < M+K; i++){
        cin >> a >> b >> c;
        if(a == 1){
            long long tmp = c-arr[b-1];
            arr[b-1] = c;
            update(0, N-1, 1, b-1, tmp);
        }else cout << subSum(0, N-1, 1, b-1, c-1) << "\n";
    }
    
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

bool flag = false;
queue<pair<int,int>> q;
int N ,M, days = -1, tomato[1001][1001], visited[1001][1001], dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
int main() {
    cin >> M >> N;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> tomato[i][j];
            visited[i][j] = -1;

            if(tomato[i][j] == 1){
                q.push({i, j});
                visited[i][j]++;
            }
        }
    }

    while(!q.empty()){
        int a = q.front().first, b = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int na = a+dx[i], nb = b+dy[i];
            if(na >= 0 && nb >= 0 && N > na && M > nb && visited[na][nb] == -1 && tomato[na][nb] == 0){
                q.push({na, nb});
                visited[na][nb] = visited[a][b]+1;
            }
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(days<=visited[i][j]) days=visited[i][j];
            if(tomato[i][j] == 0 && visited[i][j] == -1){
                days = -1;
                flag = true;
                break;
            }
        }
        if(flag) break;
    }

    cout << days;

    return 0;
}
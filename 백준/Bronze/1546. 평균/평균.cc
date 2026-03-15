#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

int n;
double score[1001];
vector<double> new_score;
int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> score[i];

    double max = *max_element(score, score + n);

    for(int i = 0; i < n; i++)
        new_score.push_back((double)score[i]/max*100.0);
    
    cout << accumulate(new_score.begin(), new_score.end(), 0.0)/n;

    return 0;
}
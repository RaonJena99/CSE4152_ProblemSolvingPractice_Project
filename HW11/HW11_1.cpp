#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int N;
vector<vector<int>> cost_graph;
vector<vector<int>> DP;

int tsp(int city, int visited) {
    if (visited == (1 << N) - 1) {
        if (cost_graph[city][0] != 0) {
            return cost_graph[city][0];
        } else {
            return INF;
        }
    }

    if (DP[city][visited] != -1) return DP[city][visited];

    int ans = INF;
    for (int next = 0; next < N; next++) {
        if (visited & (1 << next)) continue;
        if (cost_graph[city][next] == 0) continue;

        int temp = tsp(next, visited | (1 << next));
        if (temp != INF) {
            ans = min(ans, cost_graph[city][next] + temp);
        }
    }
    DP[city][visited] = ans;
    return ans;
}

int travelling() {
    DP.assign(N, vector<int>(1 << N, -1));
    int answer = tsp(0, 1 << 0);
    if (answer >= INF) answer = -1;  
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;

    cost_graph.assign(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cost_graph[i][j];
        }
    }

    int ans = travelling();
    cout << ans << '\n';

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

void BFS_dis(vector<vector<pair<int, double>>> &adj, int &n, vector<double> &dis){
    queue<int> Q;
    dis[n] = 0;
    Q.push(n);

    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        for(const auto &near:adj[x]){
            int v = near.first;
            double w = near.second;
            if (dis[v] == -1) {
                dis[v] = dis[x] + w;
                Q.push(v);
            }
        }
    }
}

int BFS_far(vector<vector<pair<int, double>>> &adj, int &n){
    vector<double> dis(adj.size(), -1);
    queue<int> Q;
    dis[n] = 0;
    Q.push(n);
    int far = n;
    double max_dis = 0;

    while(!Q.empty()){
        int x = Q.front();
        Q.pop();

        if(dis[x] > max_dis){
            max_dis = dis[x];
            far = x;
        }

        for(const auto &near:adj[x]){
            int v = near.first;
            double w = near.second;
            if (dis[v] == -1) {
                dis[v] = dis[x] + w;
                Q.push(v);
            }
        }
    }
    return far;
}


int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(12);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        double max_dist = 0;

        vector<vector<pair<int, double>>> adj(n + 1);

        // input edge info
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            adj[u].emplace_back(v, w);
            adj[v].emplace_back(u, w);
        }

        // TODO
        int tmp = 1;
        int rad_A = BFS_far(adj,tmp);
        int rad_B = BFS_far(adj,rad_A);

        vector<double> dis_A(n+1,-1),dis_B(n+1,-1);
        BFS_dis(adj,rad_A,dis_A);
        BFS_dis(adj,rad_B,dis_B);

        double max_A=0,max_B=0;

        for(int i=1;i<=n;i++){
            if(adj[i].size()==1){
                if(dis_A[i]<=dis_B[i]){
                    max_A = max(max_A,dis_A[i]);
                }else{
                    max_B = max(max_B,dis_B[i]);
                }
            }
        }
        max_dist = max(max_A,max_B)/2.0;
        // Print the minimum possible maximum distance
        cout << max_dist << "\n";
    }

    return 0;
}

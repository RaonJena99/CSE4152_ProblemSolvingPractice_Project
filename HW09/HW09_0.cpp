#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
int answer;

int dfs(int node){
    visit[node]=true;
    bool child[3] = {false, false, false};

    for(int ch : adj[node]){
        if(!visit[ch]){
            int status = dfs(ch);
            child[status] = true;;
        }
    }

    if(child[0]){ // child no camera
        answer++;
        return 2;
    }

    if(child[2]) return 1; // in range of camera
    
    return 0; //no child
}
 
int solve(int G) {
    visit = vector<bool>(G,false);
	answer = 0;

    for(int i=0;i<G;i++){
        if(!visit[i] && !dfs(i)){
            answer++;
        }
    }

	return answer;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int C, H, G, p1, p2;
	cin >> C;

	while (C--) {
		cin >> G >> H;
		adj = vector<vector<int>>(G);

		for (int i = 0; i < H; i++) {
			cin >> p1 >> p2;

			adj[p1].push_back(p2);
			adj[p2].push_back(p1);
		}

		cout << solve(G) << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

vector<int> pebbles(int N, int K, string S) {
    vector<int> ans;

    int j = 0, max = 0, w = 0;
    queue<int> W;
    for(int i=0;i<N;i++){
        if(S[i] == 'W') {
            W.push(i); w++;
        }
        while(w > K){
            if(S[j++] == 'W'){
                W.pop(); w--;
            }
        }
        if (i - j + 1 > max) {
            max = i - j + 1;
            ans.clear();
            
            queue<int> tmp = W;
            while (!tmp.empty()) {
                ans.push_back(tmp.front());
                tmp.pop();
            }
        }

    }

    return ans;
}

int main() {
    int N, K;
    string S;

    cin >> N >> K >> S;

    vector<int> ans = pebbles(N, K, S);

    cout << ans.size() << '\n';
    for (int x: ans) cout << x + 1 << ' ';
    cout << '\n';

    return 0;
}
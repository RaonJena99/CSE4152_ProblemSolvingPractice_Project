#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool can_rearrange_trains(int N, vector<int> &trains) {
    stack<int> S;
    int C = 1;

    for(int i=0;i<N;i++){
        if(S.empty()) S.push(trains[i]);
        else{
            if(S.top() > trains[i]) S.push(trains[i]);
            else return false;
        }

        if(S.top()==C){
            while(!S.empty()){
                if(S.top() != C) break;
                S.pop();
                C++;
            }
        }
    }
    return true;
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> trains(N);
        for (int i = 0; i < N; i++) {
            cin >> trains[i];
        }

        cout << can_rearrange_trains(N, trains) << '\n';
    }

    return 0;
}
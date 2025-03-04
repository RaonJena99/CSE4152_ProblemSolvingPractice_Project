#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> salesman(int N, vector<pair<int, int>> meetings) {
    vector<pair<int, int>> answer;

    sort(meetings.begin(),meetings.end(),
    [](pair<int, int>& a, pair<int, int>& b){ return a.second < b.second; });

    for(int i=0;i<N;i++){
        if(!i) answer.push_back(meetings[i]);
        else{
            if(meetings[i].first >= answer[answer.size()-1].second) 
                answer.push_back(meetings[i]);
        }
    }

    return answer;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> meetings(N);

    for (int i = 0; i < N; i++) {
        cin >> meetings[i].first >> meetings[i].second;
    }

    vector<pair<int, int>> ans = salesman(N, meetings);

    for (auto meeting: ans) {
        cout << meeting.first << " " << meeting.second << " ";
    }
    cout << '\n';

    return 0;
}
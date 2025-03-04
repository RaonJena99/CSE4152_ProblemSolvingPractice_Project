#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findNLargestElements(const vector<vector<int>>& matrix, int n) {
    vector<int> largestElements;
    priority_queue<int> mh;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mh.push(matrix[i][j]);
        }
    }

    for(int i=0;i<n;i++){
        int val = mh.top();
        mh.pop();
        largestElements.push_back(val);
    }
    
    
    return largestElements;
}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> M(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> M[i][j];
        }
    }

    vector<int> largestElements = findNLargestElements(M, n);

    for (int element : largestElements) {
        cout << element << "\n";
    }

    return 0;
}

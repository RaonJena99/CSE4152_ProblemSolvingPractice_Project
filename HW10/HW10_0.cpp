#include <iostream>
#include <vector>
using namespace std;

int maxWater(vector<int>& arr) {
    vector<int> val(arr.size(),0);
    int res = 0, x = 1, y = arr.size()-2;
    int xmax = arr[x-1], ymax = arr[y+1];

    while(x <= y){
        if(ymax <= xmax){
            res += max(0, ymax - arr[y]);
            ymax = max(ymax, arr[y]);
            y--;
        } else{
            res += max(0, xmax - arr[x]);
            xmax = max(xmax, arr[x]);
            x++;
        }
    }

    return res;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num; 

    for (int t = 0; t < test_num; ++t) {
        int B;
        cin >> B; 

        vector<int> arr(B);
        for (int i = 0; i < B; ++i) {
            cin >> arr[i];
        }

        cout << maxWater(arr) << endl;
    }

    return 0;
}
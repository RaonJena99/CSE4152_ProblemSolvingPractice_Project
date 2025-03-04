#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

vector<int> min_multiplications(int n) {
    vector<int> powers;
    set<int> visit;
    queue<vector<int> > queue;

    powers.push_back(1);
    queue.push(powers);
    visit.insert(1);

    while(!queue.empty()){
        vector<int> Arr = queue.front();
        queue.pop();
        int Size = Arr.size();

        if(Arr[Size-1] == n){
            powers = Arr;
            break;
        }

        for(int i=0;i<Size;i++){
            int sum = Arr[Size-1]+Arr[i];

            if(sum <= n && visit.find(sum) == visit.end()){
                visit.insert(sum);
                Arr.push_back(sum);
                queue.push(Arr);
                Arr.pop_back();
            }
        }
    }

    return powers;
}

int main(){

    int n;
    cin >> n;

    
    vector<int> steps = min_multiplications(n);
    cout << steps.size() - 1 << " ";
    for (int step : steps) {
        cout << step << " ";
    }

    return 0;
}
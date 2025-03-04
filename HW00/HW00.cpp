#include<iostream>
#include <vector>

using namespace std;

int main(){
    int n,i,j;
    cin >> n;
    vector<int> arr(n);
    int max_num=0, maxtail=0;;
    
    // TODO : complete Maximum subsequence sum algorithm
    for(i=0;i<n;i++) cin>>arr[i];
    
    for(i=0;i<n;i++){
        maxtail = max(maxtail+arr[i],0);
        max_num = max(max_num,maxtail);
    }

    cout << max_num;

    return 0;
}
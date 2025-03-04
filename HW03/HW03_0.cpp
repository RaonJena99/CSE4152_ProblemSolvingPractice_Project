#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

void matrix_check(int N, vector<vector<double>>& D,int R1, int R2, int C1, int C2, double V) {
    D[R1-1][C1-1]+=V;
    if(R2 < N) D[R2][C1-1]-=V;
    if(C2 < N) D[R1-1][C2]-=V;
    if(R2 < N && C2 < N) D[R2][C2]+=V;
}

void matrix_addition(int N, vector<vector<double>>& A,vector<vector<double>>& D) {
    //TODO:
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            D[i][j]+=D[i][j-1];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=1;j<N;j++){
            D[j][i]+=D[j-1][i];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j]+=D[i][j];
        }
    }

}

int main() {
    // Do NOT delete these lines unless you know what you are doing:
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N;
    cin >> N;

    vector<vector<double>> A(N, vector<double>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    vector<vector<double>> D(N,vector<double>(N,0));
    int R1, R2, C1, C2, Q;
    double V;
    cin >> Q;
    while(Q--){
        cin>>R1>>C1>>R2>>C2>>V;
        matrix_check(N,D,R1,R2,C1,C2,V);
    }
    matrix_addition(N, A, D);

    cout << fixed << setprecision(12);
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << A[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
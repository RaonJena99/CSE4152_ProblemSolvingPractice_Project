#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct point {
    double x, y;

    point() : x(0), y(0) {}

    point(double x, double y) : x(x), y(y) {}
};

bool half_circle_property(int N, vector<point>& A) {
    vector<double> angles;
    const double ESP = 1e-9;
    double gap = 0;

    for(const point P : A){
        double angle = atan2(P.y,P.x);
        if(angle < 0) angle += 2*M_PI;
        angles.push_back(angle);
    }
    sort(angles.begin(),angles.end());

    for(int i=0;i<angles.size();i++){
        gap = max(gap, angles[i]-angles[i-1]);
    }

    gap = max(gap, 2*M_PI-(angles[N-1]-angles[0]));
    if(fabs(gap-M_PI) < ESP) gap = M_PI;

    if(gap >= M_PI) return true;
    return false;
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

        vector<point> A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i].x >> A[i].y;
        }

        bool answer = half_circle_property(N, A);

        cout << answer << '\n';
    }

    return 0;
}
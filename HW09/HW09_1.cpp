#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

string Gifts(const string& d, int n, int m) {
    string digits = d;
    sort(digits.begin(), digits.end()); 

    queue<pair<string, int>> Q;
    set<int> visited_mod;

    for (char ch : digits) {
        if (ch == '0') continue; 
        int mod = (ch - '0') % n;
        string num_str(1, ch);

        if (mod == m && (ch - '0') >= n) return num_str;

        Q.push({num_str, mod});
        visited_mod.insert(mod);
    }

    while (!Q.empty()) {
        auto [num_str, mod] = Q.front();
        Q.pop();

        for (char ch : digits) {
            string next_num_str = num_str + ch;
            int next_mod = (mod * 10 + (ch - '0')) % n;

            if (next_mod == m && stoll(next_num_str) >= n) {
                return next_num_str;
            }

            if (visited_mod.count(next_mod)) continue; 

            Q.push({next_num_str, next_mod});
            visited_mod.insert(next_mod);
        }
    }

    return "IMPOSSIBLE";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int test_num;
    cin >> test_num;

    while (test_num--) {
        string d;
        int n, m;
        cin >> d >> n >> m;

        cout << Gifts(d, n, m) << "\n";
    }

    return 0;
}

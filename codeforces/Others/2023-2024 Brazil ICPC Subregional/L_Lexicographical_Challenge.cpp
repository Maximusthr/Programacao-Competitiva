#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    string s;
    cin >> s;

    int k;
    cin >> k;

    vector<vector<char>> vec(k);

    int n = s.size();

    for (int i = 0; i < k; i++) {
        for (int j = i; j < n; j += k) {
            vec[i].push_back(s[j]);
        }
        sort(vec[i].rbegin(), vec[i].rend());
    }

    // for (int i = 0; i < vec.size(); i++) {
    //     for (auto c : vec[i]) {
    //         cout << c << ' ';
    //     }
    //     cout << endl;
    // }

    while (vec[0].size() > 0) {
        for (int i = 0; i < k; i++) {
            if (vec[i].size() > 0) {
                cout << vec[i][vec[i].size() - 1];
                vec[i].pop_back();
            }
        } 
    }
    cout << endl;

    return 0;
}
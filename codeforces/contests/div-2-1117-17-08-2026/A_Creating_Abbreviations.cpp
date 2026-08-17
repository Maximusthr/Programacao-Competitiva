#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<string> arr(n);
    vector<bool> freq(27);
    for (auto &i : arr) {
        cin >> i;
        freq[i[0] - 'a'] = true;
    }

    vector<string> abr(m);
    for (int i = 0; i < m; i++){
        cin >> abr[i];
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < abr[i].size(); j++){
            if (freq[abr[i][j] - 'A']) continue;
            else {
                cout << "NO" << "\n";
                return;
            }
        }
    }
    cout << "YES" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}

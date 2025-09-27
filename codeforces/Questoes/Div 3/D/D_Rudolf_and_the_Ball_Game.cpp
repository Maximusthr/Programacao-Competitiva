#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m, k; cin >> n >> m >> k;

    vector<int> lanc; 
    lanc.push_back(k);

    set<int> uni;

    for (int i = 0; i < m; i++){
        int r; cin >> r;
        char c; cin >> c;

        for (int j = 0; j < (int)lanc.size(); j++){
            if (c == '0'){
                int v = (lanc[j] + r) % n;
                if (v == 0) v = n;

                uni.insert(v);
            }
            else if (c == '1'){
                int v = (lanc[j] - r + n) % n;
                if (v == 0) v = n;

                uni.insert(v);
            }
            else {
                int v = (lanc[j] + r) % n;
                if (v == 0) v = n;

                uni.insert(v);

                v = (lanc[j] - r + n) % n;
                if (v == 0) v = n;

                uni.insert(v);
            }
        }
        lanc.assign(uni.begin(), uni.end());
        uni.clear();
    }

    cout << (int)lanc.size() << "\n";
    for (auto &i : lanc) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
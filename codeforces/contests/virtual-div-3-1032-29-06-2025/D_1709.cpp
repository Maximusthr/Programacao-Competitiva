// Upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int ans = 0;
    vector<pair<int, int>> oper;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++){
            if (a[j] > a[j+1]){
                ans++;
                swap(a[j], a[j+1]);
                oper.push_back({1, j+1});
            }
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-1; j++){
            if (b[j] > b[j+1]){
                ans++;
                swap(b[j], b[j+1]);
                oper.push_back({2, j+1});
            }
        }
    }

    for (int i = 0; i < n; i++){
        if (a[i] > b[i]){
            ans++;
            swap(a[i], b[i]);
            oper.push_back({3, i+1});
        }
    }

    cout << ans << "\n";
    for (int i = 0; i < oper.size(); i++){
        cout << oper[i].first << " " << oper[i].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
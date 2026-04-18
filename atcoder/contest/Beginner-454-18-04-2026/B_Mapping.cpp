#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        freq[arr[i]]++;
    }

    bool dif = true;
    for (auto [x, y ] : freq){
        if (y > 1) dif = false;
    }
    bool nao = true;
    for (int i = 1; i <= m; i++){
        if (freq[i] == 0){
            nao = false;
        }
    }

    if (dif){
        cout << "Yes" << "\n";
    }
    else cout << "No" << "\n";
    if (nao){
        cout << "Yes" << "\n";
    }
    else cout << "No" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
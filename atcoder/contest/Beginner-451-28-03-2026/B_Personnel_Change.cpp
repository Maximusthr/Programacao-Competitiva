#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;

    map<int, int> freq1, freq2;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        freq1[x]++;
        freq2[y]++;
    }

    for (int i = 1; i <= m; i++){
        cout << freq2[i] - freq1[i] << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
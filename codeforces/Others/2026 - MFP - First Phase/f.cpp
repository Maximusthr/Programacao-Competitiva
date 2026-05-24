#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    double prob = 1.0;
    for (int i = 0; i < n; i++){
        prob *= min(1.0, (double)(k - 1)/(double)arr[i]);
    }

    cout << fixed << setprecision(10);
    cout << 1 - prob << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
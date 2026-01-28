#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<ll> diff(n+2);
    for (int i = 1; i <= n; i++){
        if (i > n-k+1) break;
        diff[i]++;
        diff[min(i+k, n+1)]--;
    }

    for (int i = 1; i <= n; i++){
        diff[i] += diff[i-1];
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++){
        sum += (arr[i-1] * diff[i]);
    }

    cout << fixed << setprecision(10);
    cout << (double)(sum)/(double)(n-k+1) << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
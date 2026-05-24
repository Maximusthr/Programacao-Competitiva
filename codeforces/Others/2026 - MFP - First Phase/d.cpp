#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    ll gcdd = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        gcdd = __gcd(gcdd, arr[i]);
    }

    ll sum = 0;
    for (int i = 0; i < n; i++){
        arr[i] /= gcdd;
        sum += arr[i];
    }

    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
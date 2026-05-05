#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    auto ok = [&](int mid) -> bool {
        vector<int> copy = arr;
        sort(copy.begin(), copy.begin() + mid, greater<int> ());

        ll he = 0;
        for (int i = 0; i < mid; i += 2) he += copy[i];

        return (he <= k);
    };

    int l = 1, r = n;
    while(l < r){
        int mid = l + (r-l+1)/2;

        if (ok(mid)) l = mid;
        else r = mid - 1;
    }

    cout << l << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
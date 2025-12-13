#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

vector<int> arr;

int rec(int l, int r){
    if (r - l == 1) return 0;

    int mid = l + (r-l)/2;

    int mL = *max_element(arr.begin() + l, arr.begin() + mid);
    int mR = *max_element(arr.begin() + mid, arr.begin() + r);

    int ans = 0;

    if (mL > mR){
        ans++;
        
        for (int i = 0; i < (mid - l); i++){
            swap(arr[l + i], arr[i + mid]);
        }

    }
    return rec(l, mid) + rec(mid, r) + ans;
}

void solve(){
    int n; cin >> n;

    arr.resize(n);
    for (auto &i : arr) cin >> i;

    int ans = rec(0, n);

    if (is_sorted(arr.begin(), arr.end())){
        cout << ans << "\n";
        return;
    }
    cout << -1 << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
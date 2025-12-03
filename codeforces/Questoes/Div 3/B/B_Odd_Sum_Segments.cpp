#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    int odd = 0;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i] % 2) odd++;
    }

    int segs = 0;
    vector<int> idx;
    for (int i = 0; i < n; i++){
        if (arr[i] % 2){
            if (segs + 1 == k){
                if (odd % 2){
                    segs++;
                    idx.push_back(n);
                    break;
                }
                else {
                    cout << "NO" << "\n";
                    return;
                }
            }
            else {
                segs++;
                odd--;
                idx.push_back(i+1);
            }
        }
    }

    if (segs == k){
        cout << "YES" << "\n";
        for (auto &i : idx) cout << i << " ";
        cout << "\n";
    }
    else {
        cout << "NO" << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
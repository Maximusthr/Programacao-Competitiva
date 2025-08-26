// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    if (k % 2){
        for (int i = 0; i < n; i++){
            if (arr[i] % 2){
                arr[i] += k;
            }
        }

        for (auto &i : arr) cout << i << " ";
        cout << "\n";
        return;
    }
    else {
        if (k == 2){
            for (int i = 0; i < n; i++){
                while (arr[i] % 3 != 0){
                    arr[i] += k;
                }
            }
        }
        else {
            for (int i = 0; i < n; i++){
                ll aux = (k-1) - (arr[i] % (k-1));
                arr[i] += aux * k;
            }
        }

        for (auto &i : arr) cout << i << " ";
        cout << "\n";
        return;
    }

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
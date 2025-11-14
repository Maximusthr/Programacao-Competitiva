#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 1e6+50;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    vector<int> crivo(MAX, true);

    crivo[0] = 0;
    crivo[1] = 0;

    for (ll i = 2; i < MAX; i++){
        if (crivo[i]){
            for (ll j = i * i; j < MAX; j += i){
                crivo[j] = false;
            }
        }
    }

    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n; i++){
        if (arr[i] <= MAX && crivo[arr[i]]) {
            cout << "NO" << "\n";
            continue;
        }

        ll v = sqrtl(arr[i]);

        if (v * v != arr[i]){
            cout << "NO" << "\n";
            continue;
        }
        cout << (crivo[v] ? "YES" : "NO") << "\n";
    }
}
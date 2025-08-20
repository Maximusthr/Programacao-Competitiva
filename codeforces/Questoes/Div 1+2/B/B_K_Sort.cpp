#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<ll> arr(n);
    for (auto &i : arr) cin >> i;

    vector<ll> val;
    ll maior = arr[0];
    for (int i = 1; i < n; i++){
        if (arr[i] >= maior){
            maior = arr[i];
        }
        else {
            val.push_back(maior-arr[i]);
        }
    }
    
    ll cost = 0;
    ll sum = 0;
    ll temp = val.size();
    sort(val.begin(), val.end());
    for (int i = 0; i < val.size(); i++){
        val[i] -= sum;
        cost += val[i] * (temp+1);
        sum += val[i];
        temp--;
    }

    cout << cost << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int t; cin >> t;

    while(t--){
        solve();
    }
}
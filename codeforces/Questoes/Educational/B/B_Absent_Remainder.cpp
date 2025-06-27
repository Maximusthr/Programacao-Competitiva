#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;
    sort(arr.begin(), arr.end(), greater<int> ());

    int menor = arr[n-1];

    vector<pair<int, int>> pares;
    for (int i = 0; i < n-1; i++){
        pares.push_back({arr[i], menor});
    }

    for (int i = 0; i < n/2; i++){
        cout << pares[i].first << " " << pares[i].second << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
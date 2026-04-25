#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    vector<ll> arr(n);
    map<ll, ll> freq;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }

    vector<pair<ll, ll>> qtd;
    for (auto [x, y] : freq){
        qtd.push_back({x, x*y});
    }

    sort(qtd.begin(), qtd.end(), [&](pair<ll, ll> x, pair<ll, ll> y){
        if (x.second != y.second) return x.second > y.second;
        return x.first > y.first;
    });

    ll sum = 0;
    for (int i = k; i < qtd.size(); i++){
        sum += qtd[i].second;
    }
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
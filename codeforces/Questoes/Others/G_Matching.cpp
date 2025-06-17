#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<ll, vector<ll>> valores;

    for (int i = 1; i <= n; i++){
        int x; cin >> x;
        valores[i - x].push_back(x);
    }

    ll sum = 0;
    for (auto [x, y] : valores){
        vector<ll> temp;
        for (int i = 0; i < y.size(); i++){
            temp.push_back(y[i]);
        }
        sort(temp.begin(), temp.end(), greater<int> ());
        for (int i = 0; i < temp.size()-1; i += 2){
            if ((temp[i] + temp[i+1]) > 0) sum += temp[i] + temp[i+1];
        }
    }

    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        solve();
    }
}
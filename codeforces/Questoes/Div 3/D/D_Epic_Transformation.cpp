#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    map<int, int> freq;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        freq[x]++;
    }

    vector<int> v;
    for (auto [x, y] : freq){
        v.push_back(y);
    }

    int sum = accumulate(v.begin(), v.end(), 0);
    int sobra = 0;

    n = (int)v.size();

    for (int i = 0; i < n; i++){
        sum -= v[i];
        if (v[i] > sum) sobra = max(sobra, v[i] - sum);
        sum += v[i];
    }
    
    cout << max(sobra, sum & 1 ? 1 : 0) << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
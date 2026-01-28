#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    vector<int> prefix(n+1);
    for (int i = 0; i < n; i++){
        if (s[i] == 'W') prefix[i+1]++;
        else prefix[i+1]--;
        prefix[i+1] += prefix[i];
    }

    while(k--){
        int l, r; cin >> l >> r;

        cout << (prefix[r] - prefix[l-1] > 0 ? "Y" : "N");
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
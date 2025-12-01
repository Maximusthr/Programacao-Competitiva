#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    map<char, int> freq1, freq2;

    vector<int> pref(n+2);
    for (int i = 0; i < n; i++){
        freq1[s[i]]++;
        if (freq1[s[i]] == 1){
            pref[i+1]++;
        }
        pref[i+1] += pref[i];
    }

    vector<int> suffix(n+2);
    for (int i = n-1; i >= 0; i--){
        freq2[s[i]]++;
        if (freq2[s[i]] == 1){
            suffix[i]++;
        }
        suffix[i] += suffix[i+1];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++){
        ans = max(ans, pref[i] + suffix[i]);
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
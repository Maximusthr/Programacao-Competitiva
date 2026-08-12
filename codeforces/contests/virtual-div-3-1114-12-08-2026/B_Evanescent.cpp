#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    vector<int> pref(n, 1), suf(n, 1);
    for (int i = 1; i < n; i++){
        if (s[i] == s[i-1]) {
            pref[i] += pref[i-1];
        }
    }
    for (int i = n-2; i >= 0; i--){
        if (s[i] == s[i+1]) {
            suf[i] += suf[i+1];
        }
    }

    int ans = 0;
    int pos = 1;
    for (int i = 1; i < n-1; i++){
        if (s[i] != s[i-1] && s[i] != s[i+1]) {
            pos = i;
            break;
        }
    }

    for (int i = 1; i < n-1; i++){
        if (s[i-1] == s[i+1] && s[i] != s[i-1] && s[i] != s[i+1]){
            if (ans < pref[i-1] + suf[i+1]){
                ans = pref[i-1] + suf[i+1];
                pos = i;
            }
        }
    }

    string new_s;
    for (int i = 0; i < n; i++){
        if (i == pos) continue;
        new_s.push_back(s[i]);
    }

    int tot = 0;
    for (int i = 1; i < n; i++){
        if (new_s[i] == new_s[i-1]) tot++;
    }

    cout << new_s.size() - tot << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
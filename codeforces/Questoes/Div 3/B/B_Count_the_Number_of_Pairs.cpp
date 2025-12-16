#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;

    string s; cin >> s;

    vector<int> M(27), m(27);

    for (int i = 0; i < n; i++){
        if (s[i] >= 'A' && s[i] <= 'Z') M[s[i] - 'A']++;
        else m[s[i] - 'a']++;
    }

    int ans = 0;
    for (int i = 0; i < 27; i++){
        ans += min(M[i], m[i]);

        ans += min(k, (abs(M[i] - m[i])/2));

        k = max(0, k - (abs(M[i] - m[i])/2));
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
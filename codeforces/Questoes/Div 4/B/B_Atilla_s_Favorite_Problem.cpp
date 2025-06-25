#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        string s; cin >> s;

        int ans = 0;
        for (int i = 0; i < n; i++){
            ans = max(ans, s[i]-'a');
        }

        cout << ans + 1 << "\n";
    }
}
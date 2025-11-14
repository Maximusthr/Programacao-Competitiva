#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();

    string ans;    
    char best = s[n-1];
    ans += best;
    
    for (int i = n-2; i >= 0; i--){
        if (s[i] > best){
            if ((s[i] + 1) > '9'){
                ans += '9';
            }
            else ans += (s[i] + 1);
        }
        else {
            best = s[i];
            ans += best;
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
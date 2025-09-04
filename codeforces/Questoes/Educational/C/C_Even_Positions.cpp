#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    int start = 0;
    for (int i = 0; i < n; i++){
        if (!start && s[i] == '_' || s[i] == '('){
            start++;
            s[i] = '(';
        }
        else if (start && s[i] != '('){
            start--;
            s[i] = ')';
        }
    }

    ll ans = 0;
    stack<int> pos;
    for (int i = 0; i < n; i++){
        if (s[i] == '('){
            pos.push(i);
        }
        else {
            ans += (i - pos.top());
            pos.pop();
        }
    }

    cout << ans << "\n";
    return;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
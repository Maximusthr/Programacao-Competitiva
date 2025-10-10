#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = s.size();

    reverse(s.begin(), s.end());

    int pos = -1;
    
    for (int i = 0; i < n-1; i++){
        if (s[i] >= '5'){
            int v = (s[i+1] - '0') + 1;
            s[i+1] = v + '0';
            pos = i;
        }
    }

    if (s[n-1] >= '5'){
        s.push_back('1');
        pos = n-1;
    }

    for (int i = pos; i >= 0; i--){
        s[i] = '0';
    }

    reverse(s.begin(), s.end());

    for (auto c : s) cout << c;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
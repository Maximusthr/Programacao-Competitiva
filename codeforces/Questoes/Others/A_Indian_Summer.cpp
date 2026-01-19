#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    
    set<pair<string, string>> s;
    for (int i = 0; i < n; i++){
        string a, b; cin >> a >> b;

        s.insert({a, b});
    }

    cout << s.size() << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
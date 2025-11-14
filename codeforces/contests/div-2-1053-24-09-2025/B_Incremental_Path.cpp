#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, m; cin >> n >> m;
    string s; cin >> s;

    set<int> pos;
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        pos.insert(x);
    }

    int atual = 1;
    for (int i = 0; i < n; i++){
        atual++;
        if (s[i] == 'B'){
            while(pos.count(atual)) atual++;
        }

        pos.insert(atual);

        if (s[i] == 'B') {
            while(pos.count(atual)) atual++;
        }
    }

    cout << pos.size() << "\n";
    for (auto &i : pos) cout << i << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
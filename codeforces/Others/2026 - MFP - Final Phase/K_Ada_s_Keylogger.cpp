#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int k; cin >> k;

    string t;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '#'){
            if (t.size() > 0){
                t.pop_back();
            }
        }
        else t.push_back(s[i]);
    }

    if (k > t.size()){
        cout << -1 << "\n";
    }
    else cout << t[k-1] << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
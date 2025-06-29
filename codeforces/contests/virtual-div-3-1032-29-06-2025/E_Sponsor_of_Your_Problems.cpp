#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string l, r; cin >> l >> r;

    int n = l.size();

    int equal = 0;
    bool ok = true, maybe = true;
    for (int i = 0; i < n; i++){
        if (ok && l[i] == r[i]) {
            equal += 2;
        }
        else if (maybe && (r[i]-'0') - (l[i]-'0') == 1 || (r[i] == '0' && l[i] == '9')){
            equal++;
            ok = false;
            maybe = false;
        }
        else break;
    }

    cout << equal << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
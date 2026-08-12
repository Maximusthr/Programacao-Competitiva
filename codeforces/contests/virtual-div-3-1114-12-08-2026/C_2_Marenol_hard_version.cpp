#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string a, b; cin >> a >> b;

    if (a == b){
        cout << 0 << "\n";
        return;
    }

    int a_odd = 0, b_odd = 0;
    int a_even = 0, b_even = 0;
    for (int i = 0; i < n; i++){
        a_odd += (a[i] == '1' && i % 2);
        a_even += (a[i] == '1' && i % 2 == 0);
        b_odd += (b[i] == '1' && i % 2);
        b_even += (b[i] == '1' && i % 2 == 0);
    }

    if (a_odd != b_odd || a_even != b_even) {
        cout << "-1" << "\n";
        return;
    }

    vector<int> a_od, b_od, a_ev, b_ev;
    for (int i = 0; i < n; i++){
        if (a[i] == '1' && i & 1) a_od.push_back(i);
        if (b[i] == '1' && i & 1) b_od.push_back(i);
        if (a[i] == '1' && (i % 2 == 0)) a_ev.push_back(i);
        if (b[i] == '1' && (i % 2 == 0)) b_ev.push_back(i);
    }

    ll ans = 0;
    for (int i = 0; i < a_od.size(); i++){
        ans += abs(a_od[i] - b_od[i])/2;
    }
    for (int i = 0; i < a_ev.size(); i++){
        ans += abs(a_ev[i] - b_ev[i])/2;
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
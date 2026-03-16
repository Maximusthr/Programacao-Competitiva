#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    ll a, b, c, m; cin >> a >> b >> c >> m;

    ll a_b = lcm(a, b);
    ll b_c = lcm(b, c);
    ll a_c = lcm(a,  c);
    ll todos = lcm(lcm(a, b), c);

    // encontros:

    ll enc1 = lcm(a_b, todos);
    ll enc2 = lcm(b_c, todos);

    ll alice = (m/a)*6;
    alice = alice - (m/a_b)*3;
    alice = alice - (m/a_c)*3;
    alice = alice + (m/todos)*2;

    ll bob = (m/b) * 6;
    bob = bob - (m/a_b)*3;
    bob = bob - (m/b_c)*3;
    bob = bob + (m/todos)*2;

    ll carol = (m/c)*6;
    carol = carol - (m/a_c)*3;
    carol = carol - (m/b_c)*3;
    carol = carol + (m/todos)*2;

    cout << alice << " " << bob << " " << carol << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
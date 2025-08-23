#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<ll> v64;
typedef vector<int> v32;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
#define INF 0x3fffffff
#define LLINF 0x3fffffffffffffff
#define PI 3.14159265358979323846
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fast_cin()               \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
template<class T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve() {
    ll a, b, c; cin >> a >> b >> c;

    ll m; cin >> m;
    
    vector<ll> x(m);
    for (auto &i : x) cin >> i;

    vector<ll> ans;

    for (int i = 0; i < m; i++){
        ll f = abs(((a + c)*x[i]*x[i]*x[i]) - (b*x[i]*x[i]) + (b*c*x[i]) + ((x[i] + c) * (x[i] - a)));

        ans.push_back(f);
    }

    ll anss = 0;

    for (int i = 0; i < m; i++){
        anss ^= ans[i];
    }

    cout << anss << endl;

}

int main() {
    fast_cin();
    solve();
}
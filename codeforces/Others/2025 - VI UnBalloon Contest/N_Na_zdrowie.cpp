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

int main() {
    fast_cin();
    
    ll n, q;
    cin >> n >> q;

    vector<ll> vec(n + 1);
    vector<ll> prefix(n + 1);
    for (ll i = 1; i <= n; i++) {
        cin >> vec[i];
        prefix[i] = prefix[i - 1] + vec[i];
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;

        ll m = r - l + 1;
        ll target = (1 + m) * m / 2; 
        ll sum = prefix[r] - prefix[l - 1];

        if (target == sum) cout << "TAK" << endl;
        else cout << "NIE" << endl;
    }
}
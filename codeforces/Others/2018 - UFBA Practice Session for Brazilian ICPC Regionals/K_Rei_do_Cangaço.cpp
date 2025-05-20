// Danilo did

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
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 0x3fffffff
#define LLINF 0x3fffffffffffffff
#define PI 3.14159265358979323846
#define endl '\n'
#define F first
#define S second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
#define pb push_back
#define fast_cin()                    \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
template<class T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

void solve() {
    int n;
    cin>>n;
    v64 v(n);
    for (auto& x : v)
        cin>>x;
    
    v64 pf(n+1), dp(n);
    for (int i = 1; i <= n; i++) {
        pf[i] = v[i-1] + pf[i-1]; 
    }

    dp[n-1] = max(0ll, v[n-1]);
    if (n > 1)
        dp[n-2] = max(0ll, v[n-2]+v[n-1]);
    if (n > 2)
        dp[n-3] = max(0ll, v[n-3]+v[n-2]+v[n-1]);

    for (int i = n-4; i >= 0; i--) {
        int j = i;
        int k = 1;
        while (j < n) {
            int idx = min(3*k+j, n);
            // if (idx == n+1)
            //     break;
            ll sum = pf[idx]-pf[j];
            //cerr << pf[idx-1] << ' ' << sum << ", ";
            if (sum > 0)
                dp[i] += sum;
            j = idx;
            k++;
        }
        //cerr << endl;
    }

    for (int i = 0; i < n; i++) {
        cout << dp[i];
        if (i+1 < n) cout << endl;
    }
}

int main() {
    fast_cin();
    solve();
}
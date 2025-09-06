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
    int n;
    cin>>n;
    v32 bits(31);
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        for (int j = 0; j < 31; j++)
            if ((x>>j) & 1) bits[j]++;
    }

    for (int i = 0; i < n; i++) {
        int num = 0;
        for (int j = 0; j < 31; j++) {
            if (bits[j]) {
                num += 1<<j;
                bits[j]--;
            }
        }
        cout << num << " \n"[i==n-1];
    }
}

int main() {
    fast_cin();
    solve();
}
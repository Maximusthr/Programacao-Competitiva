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

ll cnt = 0;
map<int, int> mp;

int main() {
    fast_cin();

    int n, m;
    cin >> n >> m;

    vector<int> vec(n);
    for(int i = 0; i < n; i++) vec[i] = i + 1;
    
    while (m--) {
        int a, b;
        cin >> a >> b;
        
        mp[a] = b;
    }
    

    sort(all(vec), [](int a, int b){
        cnt++;
        if (cnt == 2 * 1e8) {
            cout << -1 << endl;
            exit(0);
        }

        if (mp.find(a) != mp.end()) {
            if (mp[a] == b) return true;
        }    

        return a < b;
    });

    for (int i = 0; i < n; i++) {
        cout << vec[i] << (i == n - 1 ? endl : ' ');
    }

    return 0;
}
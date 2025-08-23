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
    
}

int main() {
    fast_cin();
    
    string line;
    getline(cin, line);

    if (line[10] == 'T') {
        cout << "Staraptor, eu escolho voce!" << endl; 
    } else if (line[10] == 'S') {
        cout << "Luxray, eu escolho voce!" << endl; 
    } else {
        cout << "Torterra, eu escolho voce!" << endl;
    }

    return 0;
}
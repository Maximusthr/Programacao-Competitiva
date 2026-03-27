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
#define fcin                     \
    ios::sync_with_stdio(false); \
    cin.tie(nullptr);
template<class T> using ordered_set = 
tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

void solve() {
    int n,q;
    cin>>n>>q;
    map<string, int> fq;
    for (int k = 0; k < n; k++) {
        string s;
        cin>>s;
        string t;
        for (auto x : s) {
            int i = x-'a';
            // abc
            if (i < 3) {
                t.pb('a');
            }
            // def
            else if (i < 6) {
                t.pb('d');
            }
            // ghi
            else if (i < 9) {
                t.pb('g');
            }
            // jkl
            else if (i < 12) {
                t.pb('j');
            }
            // mno
            else if (i < 15) {
                t.pb('m');
            }
            // pqrs
            else if (i < 19) {
                t.pb('p');
            }
            // tuv
            else if (i < 22) {
                t.pb('t');
            }
            // wxyz
            else {
                t.pb('w');
            }
        }
        fq[t]++;
    }
    while (q--) {
        string d;
        cin>>d;
        string t;
        for (auto x : d) {
            if (x == '2') t.pb('a');
            else if (x == '3') t.pb('d');
            else if (x == '4') t.pb('g');
            else if (x == '5') t.pb('j');
            else if (x == '6') t.pb('m');
            else if (x == '7') t.pb('p');
            else if (x == '8') t.pb('t');
            else t.pb('w');
        }
        if (fq.count(t))
            cout << fq[t] << endl;
        else
            cout << 0 << endl;
    }
}

int main() {
    fcin;
    solve();
}
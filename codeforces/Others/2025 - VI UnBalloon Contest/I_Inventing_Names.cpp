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

int n, k;

string proxima(string &s) {
    int len = s.size();
    string ans = s;

    if (len < k) {
        return ans + 'a'; 
    } else {
        int j = len - 1;

        while (ans[j] == 'z') {
            ans.pop_back();
            j--;
        }

        ans[j] = ans[j] + 1;
        return ans;
    }
}

int main() {
    fast_cin();

    cin >> n >> k;

    set<string> names;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        names.emplace(s);
    } 

    if (names.count("a") == 0) {
        cout << 'a' << endl;
        return 0;
    }

    for (auto it = names.begin(); it != names.end(); it++) {
        string curr = *it;
        it++;
        if (it != names.end()) {
            string nxt = *it;
        
            if (proxima(curr) != nxt) {
                // cout << "Resposta saiu daqui" << endl;
                // cout << "com curr = " << curr << endl;
                cout << proxima(curr) << endl;
                return 0;
            } 
        } else {
            // cout << "Resposta saiu daqui" << endl;
            cout << proxima(curr) << endl;
        }

        it--; 
    }

    return 0;
}
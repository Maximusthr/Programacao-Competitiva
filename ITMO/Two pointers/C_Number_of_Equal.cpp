#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> a(n);
    vector<int> b(m);

    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;

    int i = 0, j = 0;
    int pos_i = 0;
    int ans = 0;

    while (i < n || j < m){
        if (i < n && a[i] == b[j]){
            i++;
        }
        else {
            if (b[j] == a[pos_i]) {
                ans += i-pos_i;
                j++;
            }
        }
    }

    cout << ans << "\n";
}

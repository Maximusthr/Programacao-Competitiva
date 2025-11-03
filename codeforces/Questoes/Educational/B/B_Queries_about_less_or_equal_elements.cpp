#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);
    for (auto &i : a) cin >> i;
    sort(a.begin(), a.end());

    for (int i = 0; i < m; i++){
        int x; cin >> x;

        auto it = upper_bound(a.begin(), a.end(), x) - a.begin();

        cout << it << " "[i==m-1];
    }
}
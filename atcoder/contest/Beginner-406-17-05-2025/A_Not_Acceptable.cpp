#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int m, n, a, b; cin >> m >> n >> a >> b;

    if (a < m) cout << "Yes" << "\n";
    else if (a <= m && b < n) cout << "Yes" << "\n";
    else if (a >= m && b > n) cout << "No" << "\n";
    else cout << "No" << "\n";
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int talvez = n/2;

    if (talvez * 2 == n) cout << talvez-1 << "\n";
    else cout << talvez << "\n";
}

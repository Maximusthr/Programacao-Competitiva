#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    string a, b; cin >> a >> b;

    double x = 0, y = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == '*') x++;
        if (b[i] == '*') y++;
    }

    cout << fixed << setprecision(2) << 1 - y/x << "\n";
}

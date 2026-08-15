#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    double a, b; cin >> a >> b;

    if (a+b == 9 || a-b == 9 || a*b == 9 || a/b == 9){
        cout << "Nine" << "\n";
    }
    else cout << "Nein" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}

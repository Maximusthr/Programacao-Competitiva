#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string a, b; cin >> a >> b;

    if (a == b) {
        cout << -1 << "\n";
    }
    else cout << max(a.size(), b.size()) << "\n";
}

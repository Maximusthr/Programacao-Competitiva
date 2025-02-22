#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string a; cin >> a;
    string b; cin >> b;

    bool ok = false;
    for (int i = 0; i < a.size(); i++){
        if (a[i] <= 90) a[i] += (122-90);
        if (b[i] <= 90) b[i] += (122-90);

        if (a[i] != b[i]) {
            if (a[i] > b[i]) cout << 1 << "\n";
            else cout << -1 << "\n";
            ok = true;
            break;
        }
    }

    if (!ok) cout << 0 << "\n";
}

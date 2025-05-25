#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int x; cin >> x;

    string a, b; cin >> a >> b;

    int ans = 0;
    for (int i = 0; i < x; i++){
        if (a[i] != b[i]) ans++;
    }

    cout << ans << "\n";
}
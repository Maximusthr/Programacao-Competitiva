#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x, y; cin >> x >> y;

    int ans = 0;
    for (int i = 0; i < x; i++){
        int aux; cin >> aux;

        if (aux > y) ans += 2;
        else ans += 1;
    }

    cout << ans << "\n";
}

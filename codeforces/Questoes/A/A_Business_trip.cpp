#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int x; cin >> x;

    vector<int> qtd(12);
    for (auto &i : qtd) cin >> i;

    if (x == 0) {
        cout << 0 << "\n";
        return 0;
    }
    sort(qtd.begin(), qtd.end(), greater<int>());

    int ans = 0;
    int k = 0;
    while(x > 0){
        if (k == 12) {
            cout << -1 << "\n";
            return 0;
        }
        x -= qtd[k++];
        ans++;
    }

    cout << ans << "\n";
}

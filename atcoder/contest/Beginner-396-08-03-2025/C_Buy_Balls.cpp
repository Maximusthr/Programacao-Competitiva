#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m; cin >> n >> m;

    vector<long long> p(n);
    vector<long long> b(m);

    for (auto &i : p) cin >> i;
    for (auto &i : b) cin >> i;

    sort(p.rbegin(), p.rend());
    sort(b.rbegin(), b.rend());


    long long ans = 0;
    int pos_final = -1;

    bool ok = true;
    for (int i = 0; i < n; i++){
        // if (i == 0 && p[i] < 0) {
        //     ok = false;
        //     cout << 0 << "\n";
        //     break;
        // }
        if (p[i] > 0 || (p[i] <= 0 && i < (int)b.size() && (b[i] + p[i]) > 0)) {
            ans += p[i];
        }
        else break;
        pos_final = i;
    }

    if (ok){
        for (int i = 0; i < m; i++){
            if (b[i] > 0 && i <= pos_final && (b[i] + p[i] > 0)) ans += b[i];
            else break;
        }
        cout << ans << "\n";
    }

}

#include <bits/stdc++.h>
#define endl '\n'


using namespace std;
#define INF 0x3fffffff

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    int n;
    cin>>n;
    vector<int> v(2*n);
    for (int i = 0; i < 2*n; i++) cin>>v[i];
    sort(v.begin(), v.end());

    int ans = INF;
    for (int i = 0; i < 2*n-1; i++) {
        for (int j = i+1; j < 2*n; j++) {
            int cont = 0;
            bool ok = true;
            for (int k = 0; k < 2*n; k++) {
                if (k == i || k == j) continue;
                cont += v[k]*(ok ? 1 : -1);
                ok ^= 1;
            }
            cont = abs(cont);
            ans = min(ans, cont);
        }
    }
    cout << ans << endl;

    return 0;
}

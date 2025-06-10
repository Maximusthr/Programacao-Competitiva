#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, m, k; cin >> n >> m >> k;

    vector<ll> arr(n+1);
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    vector<array<int, 3>> updates(m);
    for (int i = 0; i < m; i++){
        cin >> updates[i][0] >> updates[i][1] >> updates[i][2];
    }
    
    vector<ll> dif(m+2);
    for (int i = 0; i < k; i++){
        int l, r; cin >> l >> r;
        dif[l]++;
        dif[r+1]--;
    }

    vector<ll> add(n+2);
    for (int i = 1; i <= m; i++){
        dif[i] += dif[i-1];

        add[updates[i-1][0]] += dif[i] * updates[i-1][2]; // l
        add[updates[i-1][1] + 1] -= dif[i] * updates[i-1][2]; // r + 1
    }

    for (int i = 1; i <= n; i++){
        add[i] += add[i-1];
        cout << arr[i] + add[i] << " \n"[i == n];
    }
}

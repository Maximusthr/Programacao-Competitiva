#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    
    int n, q; cin >> n >> q;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> H(n); // 1
    vector<int> G(n); // 2
    vector<int> J(n); // 3

    int temp = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 1) temp++;
        H[i] = temp;
    }

    temp = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 2) temp++;
        G[i] = temp;
    }

    temp = 0;
    for (int i = 0; i < n; i++){
        if (arr[i] == 3) temp++;
        J[i] = temp;
    }

    while(q--){
        int x, y; cin >> x >> y;
        x--;
        y--;

        if (x == 0) cout << H[y] << " " << G[y] << " " << J[y] << "\n";
        else cout << H[y] - H[x-1] << " " << G[y] - G[x-1] << " " << J[y] - J[x-1] << "\n";
    }
}

#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(nullptr);

    int n, x, y;
    cin >> n >> x >> y;

    int aux;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        cin >> aux;
        if (aux <= x) cnt++;
    }

    if (x > y) {
        cout << n << endl;
    } else {
        if (cnt % 2 == 0) cout << cnt / 2 << endl;
        else cout << (cnt + 1) / 2 << endl;
    }

    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;

    int arr[t+1];
    memset(arr, 0, sizeof arr);

    int p; cin >> p;
    for (int i = 0; i < p; i++){
        int aux; cin >> aux;
        arr[aux]++;
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++){
        int aux; cin >> aux;
        arr[aux]++;
    }

    bool ok = true;
    for (int i = 1; i <= t; i++){
        if (arr[i] == 0) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "I become the guy." : "Oh, my keyboard!") << "\n";
}

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int c = 0, bic = 0, back = 0;
    for (int i = 0; i < n; i++){
        if (i % 3 == 0) c += arr[i];
        else if (i % 3 == 1) bic += arr[i];
        else back += arr[i];
    }

    if (max(c, max(bic, back)) == c) cout << "chest" << "\n";
    else if (max(c, max(bic, back)) == bic) cout << "biceps" << "\n";
    else cout << "back" << "\n";
}

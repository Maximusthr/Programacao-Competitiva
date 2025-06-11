#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    vector<int> arr(qtd);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end(), greater<int> ());

    bool ok = false;
    for (int i = 0; i < qtd-2; i++){
        if (arr[i] + arr[i+1] > arr[i+2] && arr[i] + arr[i+2] > arr[i+1] && arr[i+1] + arr[i+2] > arr[i]) {
            cout << "YES" << "\n";
            ok = true;
            break;
        }
    }

    if (!ok) cout << "NO" << "\n";
}

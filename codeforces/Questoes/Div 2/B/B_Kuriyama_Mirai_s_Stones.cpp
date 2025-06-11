#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;

    vector<ll> arr(qtd);
    for (auto &i : arr) cin >> i;

    vector<ll> copy = arr;
    sort(copy.begin(), copy.end());

    //prefix sum (arr)

    for (int i = 1; i < qtd; i++){
        arr[i] = arr[i] + arr[i-1];
        copy[i] = copy[i] + copy[i-1];
    }

    int q; cin >> q;
    while(q--){
        int a, b, c; cin >> a >> b >> c;
        b--;
        c--;

        if (a == 1){
            if (b == 0) cout << arr[c] << "\n";
            else cout << arr[c] - arr[b-1] << "\n";
        }
        else {
            if (b == 0) cout << copy[c] << "\n";
            else cout << copy[c] - copy[b-1] << "\n";
        }
    }
}
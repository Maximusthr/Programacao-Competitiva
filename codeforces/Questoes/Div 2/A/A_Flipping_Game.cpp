#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    int ans = 0;
    pair<int, int> idx;
    for (int i = 0; i < n; i++){
        if (arr[i] == 1) continue;
        int aux = 0;

        for (int j = i; j < n; j++){
            if (arr[j]) aux--;
            else aux++;

            if (aux > ans){
                idx = {i, j};
                ans = aux;
            }
        }
    }

    for (int i = idx.first; i <= idx.second; i++){
        arr[i] ^= 1;
    }

    ans = 0;
    for (int i = 0; i < n; i++){
        if (arr[i]) ans++;
    }

    cout << ans << "\n";
}
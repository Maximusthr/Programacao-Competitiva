#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;

    int seguidos = 0;
    int temp = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1'){
            temp++;
        }
        if (s[i] == '0' || i == n-1){
            seguidos = max(temp, seguidos);
            temp = 0;
        }
    }
    if (seguidos >= k){
        cout << "NO" << "\n";
        return;
    }

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    int maior = 0;
    bool achou = false;
    for (int i = n-1; i >= 0; i--){
        if (s[i] == '1') {
            achou = true;
            maior = max(maior, i);
        }
        if (achou && s[i] == '0'){
            swap(arr[maior], arr[i]);
            achou = false;
            maior = 0;
        }
    }
    cout << "YES" << "\n";
    for (auto x : arr) cout << x << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
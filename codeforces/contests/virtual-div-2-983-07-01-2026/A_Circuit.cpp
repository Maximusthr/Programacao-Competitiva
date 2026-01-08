#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    n <<= 1;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    sort(arr.begin(), arr.end());

    int menor = 0, maior = 0;
    for (int i = 0; i < n/2; i++){
        if (arr[i] != arr[n-i-1]) maior++;
        else break;
    }
    for (int i = 1; i < n; i += 2){
        if (arr[i] != arr[i-1]){
            menor++;
        }
    }

    cout << menor << " " << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
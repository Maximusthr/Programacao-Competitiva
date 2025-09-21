#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 1; i < n; i++){
        if (arr[i] % arr[0] != 0){
            swap(arr[i], arr[0]);
            break;
        }
    }

    int aux = arr[0];
    for (int i = 1; i < n; i++){
        aux = (aux % arr[i]);
    }

    cout << (aux != 0 ? "YES" : "NO") << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
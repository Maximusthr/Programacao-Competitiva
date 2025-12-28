// upsolve

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int lcm(int a, int b){
    return a * (b/__gcd(a, b));
}

void solve(){
    int n; cin >> n;

    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    for (int i = 0; i < n-1; i++){
        arr[i] /= __gcd(arr[i], arr[i+1]);
    }

    int maior = 1;
    bool achou = false;
    for (int i = 0; i < n-1; i++){
        maior = lcm(arr[i], maior);

    }

    cout << maior << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
// upsolve
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &i : arr) cin >> i;

    vector<int> prefix(n);
    prefix[0] = arr[0];

    for (int i = 1; i <n; i++){
        prefix[i] = min(prefix[i-1], arr[i]);
    }
    
    vector<int> sufix(n);
    sufix[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--){
        sufix[i] = max(sufix[i+1], arr[i]);
    }

    for (int i = 0; i < n; i++){
        cout << (arr[i] == prefix[i] || arr[i] == sufix[i] ? 1 : 0);
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
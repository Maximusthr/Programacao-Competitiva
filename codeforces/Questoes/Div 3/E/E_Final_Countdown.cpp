#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    reverse(s.begin(), s.end());

    vector<int> arr(n+1);

    for (int i = 0; i < n; i++){
        arr[i] = (s[i] - '0');
    }

    for (int i = n-2; i >= 0; i--){
        arr[i] += arr[i+1];
    }

    for (int i = 0; i < n; i++){
        arr[i+1] += arr[i]/10;

        arr[i] %= 10;
    }

    while(arr.back() == 0){
        arr.pop_back();
    }

    reverse(arr.begin(), arr.end());

    for (auto &i : arr) cout << i;
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
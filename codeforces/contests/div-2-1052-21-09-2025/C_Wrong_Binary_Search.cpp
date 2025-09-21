#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    vector<int> arr(n);
    iota(arr.begin(), arr.end(), 1);

    if (n == 1){
        if (s[0] == '0'){
            cout << "NO" << "\n";
            return;
        }
    }

    if (n-2 >= 0){
        if (s[n-2] == '1' && s[n-1] == '0'){
            cout << "NO" << "\n";
            return;
        }
    }

    for (int i = 0; i < n-1; i++){
        if (i == 0){
            if (s[i] == '0' && s[i+1] == '1'){
                cout << "NO" << "\n";
                return;
            }
        }
        else if (s[i] == '0' && s[i-1] == '1' && s[i+1] == '1'){
            cout << "NO" << "\n";
            return;
        }
    }

    for (int i = 0; i < n-1; i++){
        if (s[i] == '0' && s[i+1] == '0'){
            swap(arr[i], arr[i+1]);
        }
    }

    cout << "YES" << "\n";
    for (auto &c : arr) cout << c << " ";
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    vector<string> s(2);
    cin >> s[0] >> s[1];

    int row = 0;
    for (int i = 0; i < n; i++){
        if (s[row][i] >= '3'){
            if (s[row ^ 1][i] < '3'){
                break;
            }
            else row ^= 1;
        }

        if (i + 1 == n && row == 1) {
            cout << "YES" << "\n";
            return;
        }
    }   

    cout << "NO" << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
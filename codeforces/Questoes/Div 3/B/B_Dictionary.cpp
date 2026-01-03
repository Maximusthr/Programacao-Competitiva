#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int v1 = s[0] - 'a' + 1;
    int v2 = s[1] - 'a' + 1;

    int sum = 0;
    for (int i = 1; i <= v1; i++){
        for (int j = 1; j <= 26; j++){
            if (i == j) continue;
            sum++;

            if (i == v1 && j == v2){
                break;
            }
        }
    }
    
    cout << sum << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
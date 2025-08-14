#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 1; i <= n; i++){
        bool fim = true;
        map<string, int> sub_s;
        for (int j = 0; j <= n - i; j++){
            string sub = s.substr(j, i);
            sub_s[sub]++;
            if (sub_s[sub] > 1) {
                fim = false;
                break;
            }
        }

        if (fim){
            cout << i << "\n";
            return;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);

    solve();
}
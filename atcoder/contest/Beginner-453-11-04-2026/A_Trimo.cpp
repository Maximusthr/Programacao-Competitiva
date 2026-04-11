#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i < s.size(); i++){
        if (i == 0 && s[i] == 'o'){
            while(i < s.size() && s[i] == 'o'){
                i++;
            }
        }
        if (i == n) break;
        cout << s[i];
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    string s; cin >> s;

    int ans = 0;

    vector<char> c = {'B', 'R', 'G'};

    bool foi = false;
    for (int i = 1; i < n-1; i++){
        if (s[i] != s[i-1] && s[i] != s[i+1]) continue;

        if (i + 2 < n && s[i] == s[i+1] && s[i] != s[i-1]) {
            if (!foi && s[i+1] == s[i+2]) {
                foi = true;
                continue;
            }
        }

        for (auto v : c){
            if (v != s[i-1] && v != s[i+1]) {
                foi = false;
                s[i] = v;
                ans++;
                break;
            }
        }
    }

    if (n > 1){
        if (s[n-1] == s[n-2]){
            for (auto v : c){
                if (v != s[n-2]) {
                    s[n-1] = v;
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << "\n";
    cout << s << "\n";
}
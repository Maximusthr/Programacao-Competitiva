#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
 
    string s; cin >> s;
    
    if (s[0] == '0' && s.size() == 1){
        cout << 4 << "\n";
    }
    else {
        int v = 0;
        if (s.size() > 1){
            v = s[s.size()-2] - '0';
            v *= 10;
            v += (s[s.size()-1] - '0');
        }
        else {
            v = s[s.size() - 1] - '0';
        }

        ll ans = 1;    
        int res = v%4;

        // 2
        if (res == 0){
            res = 4;
        }
        ans += pow(2, res);

        // 3
        ans += pow(3, res);

        // 4
        res = pow(res, 2);
        ans += pow(4, res);

        cout << ans % 5 << "\n";
    }
}
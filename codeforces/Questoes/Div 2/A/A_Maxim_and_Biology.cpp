#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    string s; cin >> s;
    
    string ref = "ACTG";
    
    int ans = INF;
    for (int i = 0; i < n-3; i++){

        int prim = min(('A' - s[i] + 26) % 26, (s[i] - 'A' + 26 ) % 26);
        int seg = min(('C' - s[i+1] + 26) % 26, (s[i+1] - 'C' + 26) % 26);
        int ter = min(('T' - s[i+2] + 26) % 26, (s[i+2] - 'T' + 26) % 26);
        int qurt = min(('G' - s[i+3] + 26) % 26, (s[i+3] - 'G' + 26) % 26);

        ans = min(prim + seg + ter + qurt, ans);
    }

    cout << ans << "\n";
}

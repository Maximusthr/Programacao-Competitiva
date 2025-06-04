#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;
        string s; cin >> s;

        int q = 0;
        int a = 0;
        for (int i = 0; i < n; i++){
            if (s[i] == 'Q') q++;
            if (s[i] == 'A') {
                a++;
                if (q > 0) q--;
                a--;
            }
        }

        if (q == 0) cout << "Yes" << "\n";
        else cout << "No" << "\n";
    }
}
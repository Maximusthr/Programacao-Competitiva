#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    string s; cin >> s;

    if (n < 3) {
        cout << "No" << "\n";
        return 0;
    }

    if (s[n-3] == 't' && s[n-2] == 'e' && s[n-1] == 'a') cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
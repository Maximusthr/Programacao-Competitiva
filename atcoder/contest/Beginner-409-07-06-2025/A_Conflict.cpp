#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    string a, b; cin >> a >> b;

    bool ok = false;
    for (int i = 0; i < n; i++){
        if (a[i] == 'o' && b[i] == 'o'){
            ok = true;
            break;
        }
    }

    if (ok) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}
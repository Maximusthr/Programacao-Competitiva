#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k; cin >> n >> k;

    string s; cin >> s;

    int g = 0, t = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'G') g = i;
        else if (s[i] == 'T') t = i;
    }

    bool ok = false;
    if (g < t){
        for (int i = g; i < n; i += k){
            if (s[i] == 'T') {
                cout << "YES" << "\n";
                return 0;
            }
            else if (s[i] == '#'){
                cout << "NO" << "\n";
                return 0;
            }
        }
        cout << "NO" << "\n";
        return 0;
    }
    else if (g > t){
        for (int i = g; i >= 0; i -= k){
            if (s[i] == 'T') {
                cout << "YES" << "\n";
                return 0;
            }
            else if (s[i] == '#'){
                cout << "NO" << "\n";
                return 0;
            }
        }
        cout << "NO" << "\n";
        return 0;
    }
}
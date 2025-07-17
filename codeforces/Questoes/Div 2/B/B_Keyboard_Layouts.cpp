#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string a, b, c; cin >> a >> b >> c;

    string d;
    for (int i = 0; i < c.size(); i++){
        bool ok = false;
        for (int j = 0; j < a.size(); j++){
            if ((c[i] == a[j]) || ((c[i]+32) == a[j])){
                if ((c[i]+32) == a[j]) d += (b[j]-32);
                else d += b[j];
                ok = true;
                break;
            }
        }
        if (!ok) {
            d += c[i];
        }
    }

    cout << d << "\n";
}
//WA

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    string a, b; cin >> a >> b;
    
    bool ok;
    for (int i = 0; i < a.size(); i++){
        string c = a.substr(i, a.size());
        ok = true;
        for (int j = 0; j < b.size(); j++){
            if (c[j] != '?' && c[j] != b[j]){
                ok = false;
                break;
            }
        }
        if (ok){
            cout << "Yes"<< "\n";
            break;
        } 
    }
    
    if (!ok) cout << "No" << "\n";
}

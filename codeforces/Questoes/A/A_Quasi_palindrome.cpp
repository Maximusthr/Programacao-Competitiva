#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    int zero_ini = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') zero_ini++;
        else break;
    }
    int zero_last = 0;
    for (int i = s.size()-1; i >= 0; i--){
        if (s[i] == '0') zero_last++;
        else break;
    }

    int i = 0, j = s.size()-1;
    if (zero_ini > zero_last){
        i = zero_ini - zero_last;
    }
    else j -= (zero_last - zero_ini);

    bool ok = true;
    while (i < j){
        if (s[i] != s[j]){
            ok = false;
            break;
        }
        i++;
        j--;
    }

    if (ok) cout << "YES" << "\n";
    else cout << "NO" << "\n";
}
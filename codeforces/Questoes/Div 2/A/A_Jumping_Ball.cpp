#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    int n; cin >> n;

    string s; cin >> s;

    bool ok = false, pode = true;
    int valido = 0, temp = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '<' && !ok && pode){
            valido++;
        }

        else if (s[i] == '>'){
            ok = true;
            temp++;
        }
        else if (s[i] == '<' && ok){
            pode = false;
            ok = false;
            temp = 0;
        }
    }

    if (ok){
        valido += temp;
    }
    cout << valido << "\n";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    solve();
}
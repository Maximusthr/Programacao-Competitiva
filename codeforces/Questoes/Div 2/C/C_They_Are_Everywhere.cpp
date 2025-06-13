#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    
    string s; cin >> s;
    
    set<char> tipos;
    for (int i = 0; i < n; i++){
        tipos.insert(s[i]);
    }
    
    map<char, int> valores;
    int ans = INF, j = 0;

    for (int i = 0; i < n; i++){
        valores[s[i]]++;

        while (j + 1 <= i && valores[s[j]] > 1){
            valores[s[j]]--;
            j++;
        }

        if (valores.size() == tipos.size()) ans = min(ans, i - j + 1);
    }

    cout << ans << "\n";
}

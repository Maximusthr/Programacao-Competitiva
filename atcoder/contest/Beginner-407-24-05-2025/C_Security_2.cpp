#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;
    int tam = (int)s.size();

    int ans = 0;
    for (int i = 0; i < tam-1; i++){
        if ((s[i] - '0') >= (s[i+1] - '0')){
            ans += (s[i]-'0') - (s[i+1]-'0');
        }
        else {
            ans += (s[i]-'0' + 10) - (s[i+1]-'0');
        }
    }

    ans += tam + (s[tam-1]-'0');

    cout << ans << "\n";
}
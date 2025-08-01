#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    for (int i = 1; i < s.size(); i++){
        int j = i;
        while (j >= 1 && (s[j] > s[j-1])){
            if ((s[j]-'0') -1 == (s[j-1]-'0')) break;
            s[j] = ((s[j]-'0') - 1) + '0';
            swap(s[j], s[j-1]);
            j--;
        }
    }

    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
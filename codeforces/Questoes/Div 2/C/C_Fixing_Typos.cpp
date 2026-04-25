#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    int n = s.size();

    string ans;

    bool duplo = false;
    for (int i = 0; i < n; i++){
        if (i + 1 < n){
            if (s[i] == s[i+1]){
                int j = i+1;

                while(j + 1 < n && s[j] == s[j+1]) j++;
                ans.push_back(s[i]);
                if (!duplo) ans.push_back(s[i]);

                duplo ^= 1;
                i = j;
            }
            else {
                duplo = false;
                ans.push_back(s[i]);
            }
        }
        else {
            ans.push_back(s[i]);
            duplo = false;
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
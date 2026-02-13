#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    vector<int> tem(26);
    for (int i = 0; i < s.size(); i++){
        tem[s[i]-'a']++;
    }

    string ans;
    string t;
    for (int i = 0; i < s.size(); i++){
        t.push_back(s[i]);
        tem[t.back() - 'a']--;

        int menor = 0;
        while (menor < 26 && tem[menor] == 0) menor++;

        while (!t.empty() && t.back() <= menor + 'a'){
            ans.push_back(t.back());
            t.pop_back();
        }
    }

    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = s.size();

    stack<char> c;
    for (int i = n-1; i >= 0; i--){
        c.push(s[i]);

        if (c.size() >= 3){
            char c1 = c.top();
            c.pop();
            char c2 = c.top();
            c.pop();
            char c3 = c.top();
            c.pop();

            if (c1 == 'A' && c2 == 'B' && c3 == 'C') continue;

            c.push(c3);
            c.push(c2);
            c.push(c1);
        }
    }

    vector<char> ans;
    while(!c.empty()){
        ans.push_back(c.top());
        c.pop();
    }

    for (auto i : ans){
        cout << i;
    }
    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
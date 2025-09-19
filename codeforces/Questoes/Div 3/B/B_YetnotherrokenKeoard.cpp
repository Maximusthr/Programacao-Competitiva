#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;

    int n = (int)s.size();

    stack<int> pos_A;
    stack<int> pos_a;

    vector<int> nao_pode;

    for (int i = 0; i < n; i++){
        if (s[i] == 'B'){
            if (!pos_A.empty()){
                nao_pode.push_back(pos_A.top());
                pos_A.pop();
            }
        }
        else if (s[i] == 'b'){
            if (!pos_a.empty()){
                nao_pode.push_back(pos_a.top());
                pos_a.pop();
            }
        }
        else {
            if (s[i] >= 'A' && s[i] <= 'Z'){
                pos_A.push(i);
            }
            else pos_a.push(i);
        }
    }

    sort(nao_pode.begin(), nao_pode.end(), greater<int>());

    for (int i = 0; i < n; i++){
        if (s[i] == 'B' || s[i] == 'b') continue;
        if (!nao_pode.empty() && i == nao_pode.back()){
            nao_pode.pop_back();
            continue;
        }
        else cout << s[i];
    }

    cout << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
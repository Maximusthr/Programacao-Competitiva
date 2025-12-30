#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int oper(string s, bool type, int a, int b){
    int sum = 0;
    char eh = '1';
    if (type) eh = '0';
    
    vector<char> v;
    int aux = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == eh) {
            v.push_back(eh);
            if (aux > 0){
                sum += (aux * a) + b;
                aux = 0;
            }
        }
        else {
            aux++;
        }            
    }
    if (aux > 0){
        sum += (aux * a) + b;
    }

    sum += (v.size() * a) + b;

    return sum;
}

void solve(){
    int n, a, b; cin >> n >> a >> b;

    string s; cin >> s;

    if (b >= 0 || n == 1){
        cout << n * (b+a) << "\n";
        return;
    }

    int ans = max(oper(s, 0, a, b), oper(s, 1, a, b));
    cout << ans << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
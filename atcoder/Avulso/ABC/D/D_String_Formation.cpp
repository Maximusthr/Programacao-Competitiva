#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    deque<char> s;
    string aux; cin >> aux;
    for (int i = 0; i < aux.size(); i++){
        s.push_back(aux[i]); 
    }

    int n; cin >> n;

    bool inv = false;

    while(n--){
        int x; cin >> x;
        if (x == 1){
            inv ^= 1;
        }
        else if (x == 2){
            int x; cin >> x;
            char c; cin >> c;

            if (inv) {
                if (x == 1) s.push_back(c);
                else s.push_front(c);
            }
            else {
                if (x == 1) s.push_front(c);
                else s.push_back(c);
            }
        }
    }

    string ss;
    for (int i = 0; i < s.size(); i++){
        ss.push_back(s[i]);
    }

    if (inv) reverse(ss.begin(), ss.end());

    cout << ss << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
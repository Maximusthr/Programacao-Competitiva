#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

ll exp(ll a, ll b){ 
    ll x = 1;

    while (b > 0){
        if (b % 2) x *= a;
        a *= a;
        b /= 2;
    }

    return x;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    
    ll x = 1;
    ll ans = 0;

    bool chegou = false;

    stack<int> p;
    int aux = 0;

    for (int i = 0; i < n; i++){
        string s; cin >> s;

        if (s == "add"){
            ans += x;
            continue;
        }

        if (s == "for"){
            int num; cin >> num;

            if (x > exp(2, 32) - 1){
                aux++;
                continue;
            }

            p.push(num);

            if (chegou) x *= num;
            else {
                x = num;
                chegou = true;
            }
        }
        else if (aux == 0 && s == "end"){
            x /= p.top();
            p.pop();
        }
        else aux--;
    }

    if (ans > exp(2, 32) - 1){
        cout << "OVERFLOW!!!" << "\n";
    }
    else cout << ans << "\n";
}

#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void query(deque<char> s){
    cout << "? ";
    for (int i = 0; i < s.size(); i++){
        if (i == s.size()-1){
            cout << s[i] << endl;
        }
        else cout << s[i];
    }
}

void solve(){
    int n; cin >> n;

    deque<char> ini;
    ini.push_back('0');
    bool usou = false;
    bool acabou = false;
    int cont = 0;
    
    // vou adicionando até chegar no ponto final da string
    for (int i = 0; i < 2*n && ini.size() <= n; i++){
        query(ini);

        int ask; cin >> ask;

        if (ask && ini.size() == n) {
            acabou = true;
            break;
        }

        if (usou){  
            if (ask == 0){
                ini.pop_back();
                break;
            }
            else {
                ini.push_back('0');
                usou = false;
                continue;
            }
        }

        if (ask == 0){
            usou = true;
            ini.pop_back();
            ini.push_back('1');
        }
        else {
            ini.push_back('0');
        }
    }

    // processo reverso
    bool first = true;
    while(!acabou && true){
        if (ini.size() != n && first){
            ini.push_front('1');
            first = false;
        }
        query(ini);

        int ask; cin >> ask;

        if (ini.size() == n){
            if (ask == 0){
                char c = ini[0];
                ini.pop_front();

                if (c == '0') ini.push_front('1');
                else ini.push_front('0');
            }
            break;
        }

        if (ask == 0){
            char c = ini[0];
            ini.pop_front();

            if (c == '0') ini.push_front('1');
            else ini.push_front('0');
        }
        else if (ask) {
            ini.push_front('0');
        }
    }
    
    cout << "! ";
    for (int i = 0; i < n; i++){
        if (i == ini.size()-1){
            cout << ini[i] << endl;
        }
        else cout << ini[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
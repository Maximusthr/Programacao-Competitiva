#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    int n = s.size();

    struct P {
        char c;
        int pos;
        int qtd;
    };

    stack<P> st;
    int maior = 0, cont = 0;
    int abriu = 0;

    for (int i = 0; i < n; i++){
        if (s[i] == ')'){
            int qtd = 0;
            if (!st.empty()){
                P topo = st.top();
                st.pop();
                
                qtd = i - topo.pos + 1 + topo.qtd;
                if (qtd == maior) cont++;
                else if (qtd > maior) {
                    maior = qtd;
                    cont = 1;
                }
            }
            abriu = qtd;
        }
        else {
            st.push({'(', i, abriu});
            abriu = 0;
        }
    }

    if (maior == 0) cout << 0 << " " << 1 << "\n";
    else cout << maior << " " << cont << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
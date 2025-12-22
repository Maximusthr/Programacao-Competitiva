#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

void solve(){
    string s; cin >> s;
    int m; cin >> m;
    
    int n = s.size();

    int i = 0;
    while (i < n){
        int count = 0;
        int aux = m;
        int new_maior = -1;
        int pos = -1;
        for (int j = i+1; j < n; j++){
            if (s[i] < s[j] && s[j] > new_maior){
                if (j - i > aux) break;
                new_maior = s[j];
                count = j-i;
                pos = j;
            }
        }
        for (int j = pos; j > i; j--){
            swap(s[j], s[j-1]);
        }

        m -= count;
        i++;
    }

    cout << s << "\n";
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}
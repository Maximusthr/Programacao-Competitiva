#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int lcs_size[3010][3010];
string s, t, lcs;

void recupera(int i, int j){
    if (i >= s.size() || j >= t.size()) return;
    if (s[i] == t[j]){
        lcs.push_back(s[i]);
        return recupera(i+1, j+1);
    }   
    if (lcs_size[i+1][j] > lcs_size[i][j+1]) return recupera(i+1, j);
    return (recupera(i, j+1));
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    cin >> s >> t;

    for (int i = s.size()-1; i >= 0; i--){
        for (int j = t.size()-1; j >= 0; j--){
            if (s[i] == t[j]){
                lcs_size[i][j] = 1 + lcs_size[i+1][j+1];
            }
            else if (s[i] != t[j]){
                lcs_size[i][j] = max(lcs_size[i+1][j], lcs_size[i][j+1]);
            }
        }
    }

    recupera(0, 0);

    cout << lcs << "\n";
}
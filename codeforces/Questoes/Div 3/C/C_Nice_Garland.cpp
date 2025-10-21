#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    string s; cin >> s;

    if (n == 1){
        cout << 0 << "\n";
        cout << s << "\n";
        return 0;
    }
    else if (n == 2){
        if (s[0] != s[1]) cout << 0 << "\n";
        else {
            cout << 1 << "\n";
            if (s[0] == 'R') s[1] = 'G';
            else if (s[0] == 'G') s[1] = 'R';
            else s[1] = 'R';
        }

        cout << s << "\n";
        return 0;
    }
    
    // RGB - RBG - GBR - GRB - BRG - BGR
    vector<string> v = {"RGB", "RBG", "GBR", "GRB", "BRG", "BGR"};
    
    int ans = INF;
    string s_ans;
    for (int i = 0; i < 6; i++){
        int temp = 0;
        string aux = s;

        for (int k = 0; k < 3; k++){
            if (aux[k] != v[i][k]){
                aux[k] = v[i][k];
                temp++;
            }
        }

        for (int j = 0; j < n-3; j++){
            if (aux[j] != aux[j+3]){
                aux[j+3] = aux[j];
                temp++;
            }
        }

        if (temp < ans){
            ans = temp;
            s_ans = aux;
        }
    }

    cout << ans << "\n";
    cout << s_ans << "\n";
}
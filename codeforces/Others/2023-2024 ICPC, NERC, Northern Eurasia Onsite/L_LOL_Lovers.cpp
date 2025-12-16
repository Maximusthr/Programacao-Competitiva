#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    string s; cin >> s;

    int O = 0, L = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'O') O++;
        else L++;
    }

    // cada um tem 1 item
    int meu_O = 0, meu_L = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == 'O') {
            O--;
            meu_O++;
        }
        else if (s[i] == 'L'){
            L--;
            meu_L++;
        }

        if ((O > 0 || L > 0) && meu_O != O && meu_L != L){
            cout << meu_O + meu_L << "\n";
            return 0;
        }
    }

    cout << -1 << "\n";
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    sort(s.begin(), s.end());

    int zero = 0;
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0') zero++;
        else {
            cout << s[i];
            while (zero > 0){
                cout << 0;
                zero--;
            }
        }
    }
}
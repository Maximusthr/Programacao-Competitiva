#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    int a = s[0] - '0';

    for (int i = 1; i < (int)s.size()-1; i++){
        a = (a ^ (s[i]-'0'));
    }

    if (a == (s[(int)s.size()-1]-'0')) cout << "YES"<< "\n";
    else cout << "NO" << "\n";

}
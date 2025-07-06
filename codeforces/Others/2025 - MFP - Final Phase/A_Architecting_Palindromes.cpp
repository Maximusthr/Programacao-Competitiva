#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s; cin >> s;

    for (int i = 0; i < s.size(); i++){
        cout << s[i];
    }
    for (int i = s.size()-1; i >= 0; i--){
        cout << s[i];
    }
    cout << "\n";
}
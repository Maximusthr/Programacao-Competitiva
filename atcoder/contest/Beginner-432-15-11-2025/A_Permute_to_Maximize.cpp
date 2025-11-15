#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string s;
    for (int i = 0; i < 3; i++){
        string a; cin >> a;
        s += a;
    }

    sort(s.begin(), s.end(), greater<int> ());

    cout << s << "\n";
}
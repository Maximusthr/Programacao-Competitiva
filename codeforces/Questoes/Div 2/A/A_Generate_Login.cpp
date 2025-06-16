#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string a, b; cin >> a >> b;

    string name;

    name += a[0];

    for (int i = 1; i < a.size(); i++){
        if (a[i] < b[0]) name += a[i];
        else break;
    }

    name += b[0];
    // for (int i = 1; i < b.size(); i++){
    //     if (b[i] <= b[i-1]) break;
    //     else name += b[i];
    // }

    cout << name << "\n";
}

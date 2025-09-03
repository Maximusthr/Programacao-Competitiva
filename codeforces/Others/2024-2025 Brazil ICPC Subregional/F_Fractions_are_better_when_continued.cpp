#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int a = 1;
    int b = 1;
    int c = 1;
    for (int i = 1; i < n; i++){
        c = a + b;
        a = b;
        b = c;
    }

    cout << c << "\n";
}
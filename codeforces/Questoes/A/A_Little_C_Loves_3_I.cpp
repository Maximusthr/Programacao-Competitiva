#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;

    int a = n/3;
    int b = n/3;
    
    if (a % 3 == 0) a--;
    if (b % 3 == 0) b--;

    int c = n - a - b;
    if (c % 3 == 0){
        c--;
        a++;
        if (a % 3 == 0) {
            a++;
            c--;
        }
    }

    cout << a << " " << b << " " << c << "\n";
}
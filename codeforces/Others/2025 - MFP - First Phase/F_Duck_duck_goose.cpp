#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n, p, k; cin >> n >> p >> k;

    int i = p;
    while (k > 0){
        if (i == p){
            i++;
            continue;
        }

        i = (i % n) + 1;
        k--;
    }
    if (i == p) i = (i % n) + 1;

    cout << i << "\n";
}

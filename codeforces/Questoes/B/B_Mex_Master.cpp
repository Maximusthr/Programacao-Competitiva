#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

const int MAX = 4e5+5;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;

    while(t--){
        int n; cin >> n;

        int zero = 0;
        bool maior = false;
        for (int i = 0; i < n; i++){
            int x; cin >> x;
            if (x == 0) zero++;
            if (x >= 2) maior = true;
        }

        if (zero <= (n+1)/2){
            cout << "0" << "\n";
        }
        else if (zero == n || maior){
            cout << "1" << "\n";
        }
        else cout << 2 << "\n";
    }
}

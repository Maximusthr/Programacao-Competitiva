#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int x, y, z; cin >> x >> y >> z;

    int sum_a = 0, sum_b = 0, sum_c = 0;

    vector<int> a(x);
    for (int i = 0; i < x; i++){
        cin >> a[i];
        sum_a += a[i];
    }
    reverse(a.begin(), a.end());

    vector<int> b(y);
    for (int i = 0; i < y; i++){
        cin >> b[i];
        sum_b += b[i];
    }
    reverse(b.begin(), b.end());

    vector<int> c(z);
    for (int i = 0; i < z; i++){
        cin >> c[i];
        sum_c += c[i];
    }
    reverse(c.begin(), c.end());

    while(true){
        if (sum_a > sum_b || sum_a > sum_c){
            sum_a -= a.back();
            a.pop_back();
        }
        else if (sum_b > sum_a || sum_b > sum_c){
            sum_b -= b.back();
            b.pop_back();
        }
        else if (sum_c > sum_a || sum_c > sum_b){
            sum_c -= c.back();
            c.pop_back();
        }

        else {
            cout << sum_a << "\n";
            return 0;
        }
    }
}
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int query(int x, int bit){
    cout << "? " << x << " " << bit << endl;
    int a; cin >> a;
    return a;
}

void solve(){
    int n; cin >> n;

    vector<int> seq;
    vector<int> ok;
    for (int i = 1; i <= n; i++){
        ok.push_back(i);
    }

    vector<int> num(n+1);
    iota(num.begin(), num.end(), 0);

    int lg = 0;
    while(n > 0) {
        n /= 2;
        lg++;
    }
    
    int b = 0;
    while(b < lg){
        int one = 0, zero = 0;
        vector<int> on, zer;
        vector<int> on_num, zer_num;

        int one_n = 0, zero_n = 0;
        for (int i = 0; i < num.size(); i++){
            if (num[i] & (1 << b)){
                one_n++;
                on_num.push_back(num[i]);
            }
            else {
                zero_n++;
                zer_num.push_back(num[i]);
            }
        }

        for (int i = 0; i < ok.size(); i++){
            int x = query(ok[i], b);
            if (x == 1) {
                one++;
                on.push_back(ok[i]);
            }
            else {
                zero++;
                zer.push_back(ok[i]);
            }
        }
 
        if (zero != zero_n) {
            ok = zer;
            num = zer_num;
        }
        else {
            ok = on;
            num = on_num;
        }

        b++;    
    }

    cout << "! " << num[0] << endl;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    solve();
}

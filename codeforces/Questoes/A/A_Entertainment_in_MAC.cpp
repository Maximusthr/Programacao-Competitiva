#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        string x; cin >> x;

        if (x[0] < x[x.size()-1]) {
            cout << x << "\n";
            continue;
        }
        else if (x[0] == x[x.size()-1]){
            int ok = false; //verify if the string is ok
            int i = 1, j = x.size()-2;

            while (i < j){
                if (x[i] > x[j]) {
                    ok = true;
                    break;
                }
                else if (x[i] < x[j]) break;
                i++, j--;
            }
            if (!ok) {
                cout << x << "\n";
                continue;
            }
        }
        reverse(x.begin(), x.end());
        string new_string = x;
        reverse(x.begin(), x.end());
        new_string += x;

        cout << new_string << "\n";
    }
}

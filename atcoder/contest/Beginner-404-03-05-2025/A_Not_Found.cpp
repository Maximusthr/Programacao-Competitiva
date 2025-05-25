#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    string a = "abcdefghijklmnopqrstuvwxyz";

    string b; cin >> b;

    for (int i = 0; i < a.size(); i++){
        auto it = find(b.begin(), b.end(), a[i]);
        if (it == b.end()){
            cout << a[i] << "\n";
            break;
        }
    }
}
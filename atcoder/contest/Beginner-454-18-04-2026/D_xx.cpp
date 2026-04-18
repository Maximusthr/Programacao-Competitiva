#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

// upsolve

string verif(string x){
    int n = x.size();

    string temp;
    
    for (int i = 0; i < n; i++){
        temp.push_back(x[i]);
        while((int)temp.size() - 4 >= 0 && temp.substr(temp.size()-4, 4) == "(xx)"){
            
            temp.pop_back();
            temp.pop_back();
            temp.pop_back();
            temp.pop_back();
            temp.push_back('x');
            temp.push_back('x');
        }
    }

    return temp;
}

void solve(){
    string a, b; cin >> a >> b;

    if (a == b){
        cout << "Yes" << "\n";
        return;
    }

    string t1 = verif(a);
    string t2 = verif(b);

    if (t1 == t2) cout << "Yes" << "\n";
    else cout << "No" << "\n";

}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        solve();
    }
}
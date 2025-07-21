#include <bits/stdc++.h>

using namespace std;
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    
    int n; cin >> n;
    
    vector<string> a;
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        a.push_back(s);
    }

    sort(a.begin(), a.end(), [&](string &a, string &b){
        return (a + b < b + a);
    });

    for (int i = 0; i < n; i++){
        cout << a[i];
    }
    cout << "\n";
}
#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    vector<int> vec;

    for (int i = 0; i < 4; i++){
        int aux; cin >> aux;
        vec.push_back(aux);
    }

    string s; cin >> s;

    int res = 0;
    for (int i = 0; i < (int)s.size(); i++){
        int num = s[i] - '0';
        res += vec[num-1];
    }

    cout << res << "\n";
}

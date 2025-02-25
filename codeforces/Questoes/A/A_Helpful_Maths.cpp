#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string x; cin >> x;

    vector<int> num;

    for (int i = 0; i < (int)x.size(); i++){
        if (x[i] >= '0' && x[i] <= '9') num.push_back(x[i]-'0');
    }

    sort(num.begin(), num.end());

    cout << num[0];
    for (int i = 1; i < (int)num.size();i++){
        cout << '+' << num[i];
    }
    cout << "\n";
}

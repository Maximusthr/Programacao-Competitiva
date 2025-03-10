#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    string num; cin >> num;

    for (int i = (int)num.size()-1; i >= 0; i--){
        if (i == 0 && (num[i] - '0' == 9)) break;
        if (num[i] - '0' > 9 - (num[i] - '0')){
            num[i] = (9 - (num[i] - '0') + '0');
        }
    }

    cout << num << "\n";
}


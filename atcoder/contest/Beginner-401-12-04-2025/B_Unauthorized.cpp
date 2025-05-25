#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int n; cin >> n;

    bool ok = false;
    int sum = 0;
    for (int i = 0; i < n; i++){
        string x; cin >> x;
        if (x == "login") ok = true;
        else if (x == "logout") ok = false;
        else if (x == "private" && !ok) sum++;
    }

    cout << sum << "\n";
}
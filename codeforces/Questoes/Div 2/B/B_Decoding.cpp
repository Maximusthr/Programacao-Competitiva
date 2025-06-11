#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(NULL);

    int qtd; cin >> qtd;
    string x; cin >> x;

    deque<char> new_x;

    int pos = 0;
    new_x.push_back(x[pos]);
    x.erase(x.begin());

    while (x.size() > 1){
        if (x.size() % 2 == 0) new_x.push_front(x[pos]);
        else new_x.push_back(x[pos]);

        x.erase(x.begin());
    }

    if (x.size() >= 1) new_x.push_back(x[0]);

    for (int i = 0; i < (int)new_x.size(); i++){
        cout << new_x[i];
    }

    cout << "\n";
}

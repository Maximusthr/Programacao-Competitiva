#include <bits/stdc++.h>

using namespace std;

int main(){
    queue<char> times;

    for (int i = 0; i < 16; i++){
        times.push(i + 'A');
    }

    while(!times.empty()){
        int aux1, aux2; cin >> aux1 >> aux2;
        
        char x = times.front();
        times.pop();
        char y = times.front();
        times.pop();

        if (aux1 > aux2) times.push(x);
        else times.push(y);

        if ((int)times.size() == 1) {
            cout << times.front() << "\n";
            //times.pop();
            break;
        }
    }
}

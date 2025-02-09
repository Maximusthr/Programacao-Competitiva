#include <iostream>

using namespace std;

int main(){
    int n, p, q;
    char c;
    cin >> n;
    cin >> p >> c >> q;

    int result = 0;

    switch (c){
        case '+':
            result = p + q;
            n >= result ? (cout << "OK") :  (cout << "OVERFLOW");
            break;
        case '*':
            result = p * q;
            n >= result ? (cout << "OK") : (cout << "OVERFLOW");
            break;
    }
}
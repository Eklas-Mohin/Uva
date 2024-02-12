/**
 *    author: mohin    
**/

#include <bits/stdc++.h>

using namespace std;

long long binaryExponentiation(long long b, long long p, long long m) {
    if (p == 0) {
        return 1;
    }
    long long res = binaryExponentiation(b, p / 2, m);
    if (p % 2) {
        return ((res * res * b) % m);
    } else {
        return ((res * res) % m);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long b{}, p{}, m{}, ans{};
    while (cin >> b >> p >> m) {
        ans = binaryExponentiation(b, p, m);
        cout << (ans % m) << endl;
    }
    return 0;
}

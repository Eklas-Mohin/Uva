/**
 *    author: mohin    
**/

#include <bits/stdc++.h>

using namespace std;

long long binaryExponentiation(long long x, long long y, long long n) {
    if (y == 0) {
        return 1;
    }
    long long res = binaryExponentiation(x, y / 2, n);
    if (y % 2) {
        return (res * res * x) % n;
    } else {
        return (res * res) % n;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long b{}, p{}, m{}, ans{};
    while (cin >> b >> p >> m) {
        ans = binaryExponentiation(b, p, m);
        cout << ans << endl;
    }
    return 0;
}

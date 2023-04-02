#include <iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
const int MAXN = 4e6 + 5;
const int MOD = 1e9 + 7;

int fact[MAXN];
int ifact[MAXN];

int pow_mod(int a, int b) {
    int ans = 1;
    while (b) {
        if (b & 1) ans = (long long)ans * a % MOD;
        a = (long long)a * a % MOD;
        b >>= 1;
    }
    return ans;
}

int binom(int n, int k) {
    if (k < 0 || k > n) return 0;
    return (long long)fact[n] * ifact[k] % MOD * ifact[n - k] % MOD;
}

int lucas(int n, int k, int p) {
    if (n < 0 || k < 0 || k > n) return 0;
    if (n == 0 || k == 0 || k == n) return 1;
    return (long long)lucas(n / p, k / p, p) * binom(n % p, k % p) % p;
}

int main() {
    FIO;
    int n, k, m;
    cin >> m;
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (long long)fact[i - 1] * i % MOD;
        ifact[i] = pow_mod(fact[i], MOD - 2);
    }
    while (m--) {
        cin >> n >> k;
        cout << lucas(n, k, MOD) << '\n';
    }
    return 0;
}

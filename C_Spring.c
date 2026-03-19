#include <stdio.h>

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

long long lcm(long long a, long long b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        long long a, b, c, m;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &m);

        long long ab = lcm(a, b);
        long long ac = lcm(a, c);
        long long bc = lcm(b, c);
        long long abc = lcm(ab, c);

        long long A = m / a;
        long long B = m / b;
        long long C = m / c;

        long long AB = m / ab;
        long long AC = m / ac;
        long long BC = m / bc;
        long long ABC = m / abc;

        long long onlyA = A - AB - AC + ABC;
        long long onlyB = B - AB - BC + ABC;
        long long onlyC = C - AC - BC + ABC;

        long long onlyAB = AB - ABC;
        long long onlyAC = AC - ABC;
        long long onlyBC = BC - ABC;

        long long all = ABC;

        long long alice = onlyA * 6 + onlyAB * 3 + onlyAC * 3 + all * 2;
        long long bob   = onlyB * 6 + onlyAB * 3 + onlyBC * 3 + all * 2;
        long long carol = onlyC * 6 + onlyAC * 3 + onlyBC * 3 + all * 2;

        printf("%lld %lld %lld\n", alice, bob, carol);
    }

    return 0;
}
// https://cp-algorithms.com/algebra/euclid-algorithm.html
// https://youtu.be/0X_5V4CzddM?si=tb-OJZQhGgfK3C20

/*
Euclidean algorithm calculates the GCD of 2 numbers as:
gcd(a, b) = gcd(a - b, b), where a > b

gcd(a, b) = {
                a,                if b=0
                gcd(b, a % b)     otherwise
            }
*/

int gcd (int a, int b) {
    if (b == 0) return a;
    return gcd (b, a % b);
}

int lcm (int a, int b) {
    return a * b / gcd(a, b);
}
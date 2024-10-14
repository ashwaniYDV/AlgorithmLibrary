#include <bits/stdc++.h>
using namespace std;

int main() {
    auto factorial = [&](int n, auto&& self) -> int {
        if(n <= 1) return 1;
        return self(n - 1, self) + self(n - 2, self);
    };

    cout << factorial(2, factorial);
}





#include <bits/stdc++.h>
using namespace std;

int main() {
    auto factorial = [&](int n, auto&& factorial) -> int {
        if(n <= 1) return 1;
        return factorial(n - 1, factorial) + factorial(n - 2, factorial);
    };

    cout << factorial(10, factorial);
}

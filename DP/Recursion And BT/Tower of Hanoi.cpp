// https://youtu.be/q6RicK1FCUs


#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char src, char dest, char aux_rod) {
    if(n == 0) return;

    towerOfHanoi(n - 1, src, aux_rod, dest);
    cout << "Move disk " << n << " from rod " << src << " to rod " << dest << endl;
    towerOfHanoi(n - 1, aux_rod, dest, src);
}

int main() {
    // Number of disks
    int n = 3;
    // A, B and C are names of rods
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}



/*
Move disk 1 from rod A to rod C
Move disk 2 from rod A to rod B
Move disk 1 from rod C to rod B
Move disk 3 from rod A to rod C
Move disk 1 from rod B to rod A
Move disk 2 from rod B to rod C
Move disk 1 from rod A to rod C
*/

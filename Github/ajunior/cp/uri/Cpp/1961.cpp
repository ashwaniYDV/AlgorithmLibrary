#include <iostream>

using namespace std;

int main() {
    int jumpHeight, numOfPipes, pipePrior, nextPipe, frogLife = 1;

    cin >> jumpHeight >> numOfPipes >> pipePrior;

    for (int i = 1; i < numOfPipes; i++) {
        cin >> nextPipe;
        if ( (pipePrior + jumpHeight < nextPipe) || (pipePrior - jumpHeight > nextPipe) ) {
            frogLife = 0;
            break;
        } else {
            pipePrior = nextPipe;
        }
    }

    if (frogLife) cout << "YOU WIN\n";
    else cout << "GAME OVER\n";

    return EXIT_SUCCESS;
}

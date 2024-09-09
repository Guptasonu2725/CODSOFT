#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));  // Initialize random seed
    int randomNumber = rand() % 100 + 1, guess;

    cout << "Guess the number (1-100): ";
    do {
        cin >> guess;
        cout << (guess < randomNumber ? "Too low!" : guess > randomNumber ? "Too high!" : "Correct!") << endl;
    } while (guess != randomNumber);

    return 0;
}

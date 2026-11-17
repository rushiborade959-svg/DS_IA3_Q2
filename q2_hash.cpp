
/*
  Data Structures - Internal Activity 3
  Question 2: Hash Table with Recorded Development Log
  PRN: 202501100061
  Seed: 61
  Domain: Cold-Drink Flavours
  Hash Function: Mid-Square
  Collision Strategy: Separate Chaining
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getMiddleDigits(int key) {
    string square = to_string(key * key);

    while (square.length() < 4) {
        square = "0" + square;
    }

    int start = (square.length() - 2) / 2;
    return square.substr(start, 2);
}

int main() {
    vector<int> data = {
        61, 74, 87, 0, 13,
        26, 39, 52, 65, 78,
        91, 4, 17, 30, 43,
        56, 69, 82, 95, 8
    };

    cout << "Q2 Hash Table Project" << endl;
    cout << "PRN: 202501100061" << endl;
    cout << "\nMid-Square Calculation:\n";

    for (int key : data) {
        cout << "Key: " << key
             << " | Square: " << key * key
             << " | Middle digits: "
             << getMiddleDigits(key) << endl;
    }

    return 0;
}

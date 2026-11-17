
/*
  Data Structures - Internal Activity 3
  Question 2: Hash Table with Recorded Development Log

  PRN: 202501100061
  Seed S: 61
  Domain: Cold-Drink Flavours
  Dataset size: 20
  Hash Function: Mid-Square
  Collision Strategy: Separate Chaining
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "Q2 Hash Table Project" << endl;
    cout << "PRN: 202501100061" << endl;
    cout << "Domain: Cold-Drink Flavours" << endl;

    vector<int> data = {
        61, 74, 87, 0, 13,
        26, 39, 52, 65, 78,
        91, 4, 17, 30, 43,
        56, 69, 82, 95, 8
    };

    cout << "\nPersonalized Dataset:\n";

    for (int value : data) {
        cout << value << " ";
    }

    cout << endl;

    return 0;
}

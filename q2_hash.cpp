
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 29;

string getMiddleDigits(int key) {
    string square = to_string(key * key);

    while (square.length() < 4) {
        square = "0" + square;
    }

    int start = (square.length() - 2) / 2;
    return square.substr(start, 2);
}

int calculateHash(int key) {
    string middle = getMiddleDigits(key);
    int middleValue = stoi(middle);

    return middleValue % TABLE_SIZE;
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
    cout << "Table Size: " << TABLE_SIZE << endl;

    cout << "\nHash Index Calculation:\n";

    for (int key : data) {
        cout << "Key: " << key
             << " | Middle digits: " << getMiddleDigits(key)
             << " | Hash Index: " << calculateHash(key)
             << endl;
    }

    return 0;
}

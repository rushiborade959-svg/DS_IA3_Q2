
#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int TABLE_SIZE = 29;

// Mid-Square hashing
string getMiddleDigits(int key) {
    int square = key * key;
    string squareStr = to_string(square);

    while (squareStr.length() < 4) {
        squareStr = "0" + squareStr;
    }

    int start = (squareStr.length() - 2) / 2;
    return squareStr.substr(start, 2);
}

// Calculate hash index
int calculateHash(int key) {
    string middle = getMiddleDigits(key);
    return stoi(middle) % TABLE_SIZE;
}

int main() {
    // PRN: 202501100061
    // Domain: Cold-drink flavours
    // Collision handling: Separate Chaining

    vector<int> data = {
        61, 74, 87, 0, 13,
        26, 39, 52, 65, 78,
        91, 4, 17, 30, 43,
        56, 69, 82, 95, 8
    };

    cout << "Q2 Hash Table Project\n";
    cout << "PRN: 202501100061\n";
    cout << "Domain: Cold-drink flavours\n";
    cout << "Table Size: " << TABLE_SIZE << endl;

    cout << "\nHash Index Calculation:\n";

    for (int key : data) {
        cout << "Key: " << key
             << " | Middle digits: " << getMiddleDigits(key)
             << " | Hash Index: " << calculateHash(key)
             << endl;
    }

    // Implement Separate Chaining
    vector<vector<int>> table(TABLE_SIZE);

    for (int key : data) {
        int index = calculateHash(key);
        table[index].push_back(key);
    }

    cout << "\nHash Table using Separate Chaining:\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";

        if (table[i].empty()) {
            cout << "Empty";
        } else {
            for (int j = 0; j < table[i].size(); j++) {
                cout << table[i][j];

                if (j < table[i].size() - 1) {
                    cout << " -> ";
                }
            }
        }

        cout << endl;
    }

    cout << "\nCollision Details:\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i].size() > 1) {
            cout << "Index " << i << ": ";

            for (int j = 0; j < table[i].size(); j++) {
                cout << table[i][j];

                if (j < table[i].size() - 1) {
                    cout << " -> ";
                }
            }

            cout << " (Collision)\n";
        }
    }

    // Final validation
    int totalElements = 0;
    int collisionBuckets = 0;

    for (int i = 0; i < TABLE_SIZE; i++) {
        totalElements += table[i].size();

        if (table[i].size() > 1) {
            collisionBuckets++;
        }
    }

    cout << "\nFinal Validation:\n";
    cout << "Total input values: " << data.size() << endl;
    cout << "Total inserted elements: " << totalElements << endl;
    cout << "Collision buckets: " << collisionBuckets << endl;

    if (totalElements == data.size()) {
        cout << "Validation: SUCCESS\n";
    } else {
        cout << "Validation: FAILED\n";
    }

    return 0;
}

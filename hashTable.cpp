#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int main()
{
    int m;
    cin >> m;
    vector<list <int> > hashTable(m); // Can also do with an array -> list<int> array[ARRAY_SIZE]

    string input;
    
    while (true) {
        cin >> input;

        // Function to insert a key into hash table
        if (input.find("i") == 0) {
            string substr = input.substr(1);
            int element = stoi(substr);

            int key = element % m;
            hashTable[key].push_front(element);
        }

        // Function to output the hash table
        if (input == "o") {
            for (int i = 0; i < m; i++) {
                cout << i << ":";
                for (auto it = hashTable[i].begin(); it != hashTable[i].end(); it++) {
                    cout << *it << "->";
                }
                cout << ";" << endl;
            }
        }

        // Function to delete a key from hash table
        if (input.find("d") == 0) {
            string substr = input.substr(1);
            int searchValue = stoi(substr);

            int key = searchValue % m;
            auto element = find(hashTable[key].begin(), hashTable[key].end(), searchValue);
            if (element != hashTable[key].end()) {
                hashTable[key].erase(element);
                //hashTable[key].remove(key);
                cout << searchValue << ":DELETED;" << endl;
            }
            else {
                cout << searchValue << ":DELETE_FAILED;" << endl;
            }
        }

        // Function to search a key in hash table
        if (input.find("s") == 0) {
            string substr = input.substr(1);
            int searchValue = stoi(substr);

            int key = searchValue % m;
            auto element = find(hashTable[key].begin(), hashTable[key].end(), searchValue);
            int elementIndex = distance(hashTable[key].begin(), element);

            if (element != hashTable[key].end()) {
                cout << searchValue << ":FOUND_AT" << key << "," << elementIndex << ";" << endl;
            }
            else {
                cout << searchValue << ":NOT_FOUND;" << endl;
            }
        }

        // Function to exit the loop
        if (input == "e") {
            break;
        }
    }

    return 0;
}

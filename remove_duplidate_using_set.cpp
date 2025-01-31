#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    // Declare an unordered_map
    unordered_map<int, string> umap;

    // Insert elements
    umap[1] = "Apple";
    umap[2] = "Banana";
    umap[3] = "Cherry";
    umap[4] = "Mango";

    // Print all elements in the unordered_map
    cout << "Elements in unordered_map:\n";
    for (auto &entry : umap) {
        cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
    }

    // Search for a key
    int key = 2;
    auto it = umap.find(key);
    if (it != umap.end()) {
        cout << "\nFound: Key " << it->first << " -> " << it->second << endl;
    } else {
        cout << "\nKey " << key << " not found!" << endl;
    }

    // Erase an element
    umap.erase(3); // Removes key 3

    // Print after deletion
    cout << "\nAfter deleting key 3:\n";
    for (auto &entry : umap) {
        cout << "Key: " << entry.first << ", Value: " << entry.second << endl;
    }

    // Print size
    cout << "\nSize of unordered_map: " << umap.size() << endl;

    return 0;
}
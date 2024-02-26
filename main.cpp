#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include "sstream"
#include "queue"
#include <numeric>
#include <set>

using namespace std;

#include "./trie/208. Implement Trie (Prefix Tree).cpp"

int main() {
    // DATA

    // SOLUTION
    auto tr = Trie();
    tr.insert("apple");
    cout << tr.search("apple") << endl;
    cout << tr.search("app") << endl;
    cout << tr.startsWith("app") << endl;
}

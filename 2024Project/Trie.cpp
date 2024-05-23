#include "Trie.h"
// code adapted from GeeksforGeeks (2011)
void Trie::insert(string river) // inserts each character from the river string into the Trie data structure
{
    // memory leaks were occuring during testing, therefore smart pointers were used to handle memory deallocation automatically
    std::shared_ptr<TrieNode> current = root;
    for (int i = 0; i < river.length(); i++) {
        char ch = river[i];
        std::shared_ptr<TrieNode> node = current->children[ch];
        if (node == NULL) {
            node = std::make_shared<TrieNode>();
            current->children[ch] = node;
        }
        current = node;
    }
    current->endOfWord = river; // once the last node is reached the it is set to the river name
}

string Trie::search(string river) // Time complexity is O(k), must search length of river that is passed to check if it is contained within the Trie
{
    std::shared_ptr<TrieNode> current = root;
    for (int i = 0; i < river.length(); i++) {
        char ch = river[i];
        std::shared_ptr<TrieNode> node = current->children[ch];
        if (node == NULL) {
            return ""; // returns empty string if river does not exist
        }
        current = node; // current node updates
    }
    return current->endOfWord; // returns river if it exists in Trie structure
}
// end of adapted code
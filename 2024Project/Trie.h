#pragma once
#include <string>
#include <map>
#include <memory>
#include <boost/thread.hpp>

using std::map, std::string;

/**
* @file Trie.h
* @brief This file handles the Trie data structure.
*
*/

// code adapted from GeeksforGeeks (2011) and 
struct TrieNode // Structure for each Trie node
{ 
    map<char, std::shared_ptr<TrieNode>> children; /**< map. char paired with nodes relative to other chars */
    string endOfWord; /**< River name, once search or insert has reached the end of characters in a word */
};

/**
* Trie class.
* Adds data to a trie data structure
*
*/
class Trie 
{
public:
    // code adapted from GeeksforGeeks (2014)
    std::shared_ptr<TrieNode> root; /**< reference of trie root.*/
    /**
    * Constructor\n
    * instantiates a new trie node\n
    * Time complexity: O(1)
    */
    Trie() : root(std::make_shared<TrieNode>()) {}
    // end of adapted code

    /**
    * Insert\n
    * Time complexity: O(k)
    * @param word: river name
    */
    void insert(string word);

    /**
    * Search\n
    * Time complexity: O(k)
    * @param word: river name
    * @return river name
    */
    string search(string word);
};
// end of adapted code
#pragma once
#include "FileReading.h"
#include "Trie.h"
#include "Mode.h"

/**
* @file Rivers.h
* @brief This file handles the Rivers functionality
*
*
*/

using std::vector, std::string, std::unordered_map;

/**
* Rivers class.
* Produces a random river for the user
* 
*/
class Rivers
{
private:
	Trie trie; /**< Object of Trie class */
	Mode m; /**< Object of Mode class */
	FileReading fr; /**< Object of FileReading class */
	int modeSelect{}; /**< int variable. Stores number of selected mode */
	unordered_map<string, string> rivers; /**< unordered map. Stores rivers */
	vector<string> tempCont; /**< vector of string. Stores continents */
	std::mt19937_64 number; /**< mt19937 64 bit. Stores.....*/

	/**
	* River to Trie\n
	* After all rivers have been read from files. The rivers are then passed to the Trie Class. \n
	* Time complexity: O(n*k)
	* @see Trie()
	*/
	void riversToTrie();

public:

	
	/**
	* Constructor\n
	* Further Detail. \n
	* Time complexity:O(nlog(n))
	* 
	* @param filenames: vector of filenames
	*/
	Rivers(const std::vector<std::string>& filenames);

	/**
	* Get random River\n
	* Selects a random river.\n
	* Time complexity: O(k)
	* @return river
	*/
	std::string getRandomRiver();

	/**
	* Get Continent\n
	* Selects the continent of the river. \n
	* Time complexity: O(log(n))
	* @param river name
	* @retrun continent name
	*/
	std::string getContinent(std::string river);

	/**
	* Same Continent\n
	* Checks if the two rivers are from the same continent. \n
	* Time complexity: O(log(n))
	* @param river one
	* @param river two: 
	* @return bool value. True if same continent. False if not the same continent
	*/
	bool sameContinent(std::string river1, std::string river2);



	//No need to implement this until assignment 2
	/**
	* Set Mode\n
	* sets the mode of generation from user input \n
	* Time complexity: O(1)
	* @param mode
	*/
	void setMode(int mode)
	{
		modeSelect = mode;
		
	}
};
#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using std::vector, std::string, std::unordered_map;

/**
* @file Mode.h
* @brief This file handles the Mode the game uses.
*
*/

/**
* Mode class.
* Modes that change the probability of the river choices
*
*/
class Mode {
private:
	std::mt19937_64 number; /**< mt19937 64 bit variable. store the generator for the random number generation*/
	unordered_map<string, string>& rivers; /**< unordered map. Stores river names */
	vector<string>& tempCont; /**< vector of strings. Stores a reference to continents */
	vector<int> prevNum; /**< vector of ints. Stores a vector of previous river locations in the map. */
	std::pair<string, string> lastRiverCont; /**< pair of string and string. Stores the last continent and river*/
	
public:
	/**
	* Constructor.\n
	* Time complexity: O(1)
	* @param rivers
	* @param tempCont
	*/
	Mode(unordered_map<string, string>& rivers, vector<string>& tempCont);

	/**
	* Mode 1\n
	* Generates an equal probability of each continent to be selected \n
	* Time complexity: O(1)
	* @return river
	*/
	string mode1();

	/**
	* Mode 2\n
	* Generates an equal probability of each river being selected \n
	* Time complexity: O(n)
	* @return river
	*/
	string mode2();

	/**
	* Mode 3\n
	* Generates a 50% chance of the previous continent that was selected to be chosen again\n
	* Time complexity: O(n)
	* @return river
	*/
	string mode3();

	/**
	* River selection \n
	* Selects a river from a given continent \n
	* Time complexity: O(n)
	* @param continent
	* @return river
	*/
	string selectRiver(string continent);

	/**
	* Six calls\n
	* Once a river is selected it is not called for another six calls. \n
	* To ensure that the river selected has not been called within the past six calls. \n
	* Time complexity: O(1)
	* @param ranNum
	* @param dist
	* @return index of 
	*/
	int sixCalls(int ranNum, std::discrete_distribution<> dist);
};
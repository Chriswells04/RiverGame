#pragma once
#include "Rivers.h"
#include "Timer.h"
#include <ostream>
#include <istream>
#include <memory>
#define ASSIGNMENT_2				//uncomment to switch to assignment 2
#define RUN_PAUSE_TEST  			//uncomment to run pause test (for assignment 2 only)

/**
* @file Game.h
* @brief This file handles the Game functionality
* 
*/

using std::multimap;

/**
* Game class.
* creates an object of the game to be played
*
*/
class Game 
{
private:
	Timer t; /**< Object of timer class */
	Rivers& r; /**< Object of rivers class */
	Trie tr; /**< Object of trie class */
	char input{}; /**< char variable. Stores user input */
	int correctScores{}; /**< int variable. Stores correct scores */
	int totalQuestions{}; /**< int variable. Stores total questions answered */
	long long elapsedTime{}; /**< long long variable. Stores time elapsed */
	multimap<long long, string> sortTime; /**< Map. stores elapsed time paired with the two rivers formatted in one string to sort in order of time */
	vector<string> fastestTimes; /**< Vector of strings. Final format of both rivers and elapsed time built in one string */

	/**
	* Displays the correct output screen when questions are answered correctly \n
	* Time complexity: O(log n)
	* @param out output to screen
	* @param r1 river one
	* @param r2 river two
	*/
	void displayCorrect(std::ostream& out, string r1, string r2);

	/**
	* Checks if user input is correct \n
	* Time complexity: O(1)
	* @param out output to screen
	* @param r1 river one
	* @param r2 river two
	* @param sameCont boolean value
	*/
	void inputCheck(std::ostream& out, string r1, string r2, bool sameCont);
	

public:
	/**
	* Constructor \n
	* Time complexity: O(1)
	* @param rivers: reference to Rivers class
	*/
	Game(Rivers& rivers) : r(rivers) { }

	/**
	* Function that gets the correct scores. \n
	* Time complexity: O(1)
	* @return current score
	*/
	int getScore() { return correctScores; }

	/**
	* Function that gets the total questions answered. \n
	* Time complexity: O(1)
	* @return total questions answered
	*/
	int getTotal() { return totalQuestions; }

	/**
	* Function that sets the total for questions answered \n
	* Time complexity: O(1)
	* @param total total number of questions answered
	*/
	void setTotal(int total) { totalQuestions = total; }

	/**
	* resets scores and total questions to 0. \n
	* Time complexity: O(1)
	*/
	void reset() { correctScores = 0;totalQuestions = 0; }

	// this method should implement one round of the game only, 
	// it should return true if the player wishes to continue ('s' or 'd') and false otherwise ('q')

	/**
	* Plays one round of the game \n
	* Time complexity: O(1)
	* @param out output to screen
	* @param in user input
	* @return bool value. True to continue game. False to stop the game.
	*/
	bool playRound(std::ostream& out, std::istream& in);

	//No need to implement this until assignment 2 

	/**
	* Gets the fastest rivers \n
	* Time complexity: O(n)
	* @return list of fastest rivers
	*/
	std::vector<std::string> getFastest();

	/**
	* Function that sets the values in the Fastest rivers vector \n
	* Time complexity: O(1)
	* @param formattedRivers string in the format required to display in the scoreboard at end of game
	*/
	void setFastestRivers(string formattedRivers) {
		fastestTimes.push_back(formattedRivers);
	}

	/**
	* Function that sets the values in the sortime map \n
	* Time complexity: O(1) \n
	* @param time the time taken for the question to be answered
	* @param rivers the 2 rivers for the question in the format required for the scoreboard at end of game
	*/
	void setSortTimes(long long time, string rivers) {
		sortTime.insert({ time, rivers });
	}

	/**
	* Function that return the sorted times map
	* Time complexity: O(1)
	* @return map of sorted times paired with its rivers
	*/
	multimap<long long, string> getSortTimes() { return sortTime; }
};
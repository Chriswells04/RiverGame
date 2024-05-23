#pragma once
#include <chrono>	
#include "Game.h"
/**
* @file Timer.h
* @brief This file handles the Timer functionality
*
*/

/**
* Timer class.
* Sets and returns the time taken for a user to answer questions
*
*/
class Timer 
{
private:
	std::chrono::steady_clock::time_point t; /**< time. add detail  */
public:
	/**
	* Start.\n
	* when a user starts a question the timer is activated\n
	* Time complexity: O(1)
	*/
	void start() { t = std::chrono::steady_clock::now(); }
	/**
	* Elapsed time\n
	* Further Detail.\n
	* Time complexity: O(1)
	*
	* @return elapsed time taken for question to be answered
	*/
	long long elapsedTime() const {
		std::chrono::steady_clock::duration elapsed = std::chrono::steady_clock::now() - t;
		return duration_cast<std::chrono::milliseconds>(elapsed).count();
	}
};
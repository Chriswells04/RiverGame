#include "Game.h"

//Be sure to refer to in and out - NOT cin and cout in this code. Tests will fail otherwise
bool Game::playRound(std::ostream& out, std::istream& in) 
{
	string river1 = r.getRandomRiver(); // stores a random river 
	string river2 = r.getRandomRiver();

	out << river1 << std::endl; // displays random rivers
	out << river2 << std::endl;

	out << "Enter your choice: " << std::endl;

	t.start();
	in >> input; // take user input

	elapsedTime = t.elapsedTime();

	if (elapsedTime >= 10000) // if time is more than 10000 milliseconds (10 seconds) answer is false as time limit has been exceeded
	{ // causes bug where if time limit exceeded and user asks to exit continues to next question.
		out << "time limit exceeded" << std::endl;
		totalQuestions++;
		return true;
	}

	if ((char)tolower(input) == 's' || (char)tolower(input) == 'd')
	{
		if (input == 's') { inputCheck(out, river1, river2, true); }
		
		else { inputCheck(out, river1, river2, false); }
		
		return true;
	}
	if ((char)tolower(input) == 'q') { return false; }  
	
	else 
	{
		out << "incorrect Input " << std::endl;
		return true;
	}
	return false;
}

std::vector<std::string> Game::getFastest() // gets the fastest times recordered in nonincreasing order of speed
{
	for (multimap<long long, string>::iterator i = sortTime.begin(); i != sortTime.end(); i++)
	{
		fastestTimes.push_back(i->second + std::to_string(i->first)); // pushes the sorted times from a map onto a vector 
	}
	if (fastestTimes.size() > 5) // if more than 5 times, resize vector to hold only 5 times
	{
		fastestTimes.resize(5);
		return fastestTimes;
	}
	return fastestTimes;
}

void Game::displayCorrect(std::ostream& out, string r1, string r2) // displays when the user' answer is correct
{
	out << "correct: " << std::endl;
	sortTime.insert({ elapsedTime, (r1 + "," + r2 + ",") });// inserts the time it took the user to answer
	correctScores++; // increments total correct score by 1
}

void Game::inputCheck(std::ostream& out, string r1, string r2, bool sameCont) // checks depending on input of 's' or 'd' if the rivers are in the same continent or not
{
	if (r.sameContinent(r1, r2) == sameCont) { displayCorrect(out, r1, r2); }
	
	else { out << "incorrect: " << std::endl; }

	out << r1 << " is in " << r.getContinent(r1) << " and ";
	out << r2 << " is in " << r.getContinent(r2) << std::endl;
	totalQuestions++;
}
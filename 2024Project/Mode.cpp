#include "Mode.h"

Mode::Mode(unordered_map<string, string>& rivers, vector<string>& tempCont) : rivers(rivers), tempCont(tempCont) 
{
    std::random_device rd; // system implemented random number generator
    std::mt19937_64 ranNum(rd()); // random device used to radomly seed mersenne twister algorithm

    number = ranNum;
}

string Mode::mode1() // selects a river with each continent having equal probability
{
    std::discrete_distribution<> dist(double(tempCont.size()), 1.0);
    return selectRiver(tempCont[dist(number)]);
}

string Mode::mode2() // selects each river with each having equal probability
{
    std::discrete_distribution<> dist(double(rivers.size()), 1.0);
    int ranNum = dist(number);
    ranNum = sixCalls(ranNum, dist); // ensures a river doesnt occur for more than six calls
    auto it = rivers.begin();
    std::advance(it, ranNum % rivers.size());
    lastRiverCont = { it->first,it->second };

    return it->first; // returns the key from map which is the name of river (first stored value)
}

string Mode::mode3() // creates a 50% probability of producing rivers from the same continent
{
    int count{};
    for (const string cont : tempCont)
    {
        if (cont == lastRiverCont.second)break;// looks to match the continent last saved with a continent in a continent vector
        count++; // counts the position of the continent
    }

    std::vector<double> prob(tempCont.size());
    for (int i = 0; i < prob.size(); ++i)
    {
        if (i == count) { prob[i] = 0.5; }

        else { prob[i] = 0.5 / (tempCont.size() - 1); }
    }
    std::discrete_distribution<> dist(prob.begin(), prob.end());
    return selectRiver(tempCont[dist(number)]);
}

string Mode::selectRiver(string continent) // selects a river from a given continent
{
    for (const auto& pair : (rivers)) {
        if (pair.second == continent)
        {
            lastRiverCont = { pair.first,continent };
            return pair.first;
        }
    }
    return "";
}

int Mode::sixCalls(int ranNum, std::discrete_distribution<> dist) // ensures a river is not called again for another six calls after it was generated
{
    while (std::find(prevNum.begin(), prevNum.end(), ranNum) != prevNum.end()) { ranNum = dist(number); }
    prevNum.push_back(ranNum);

    if (prevNum.size() > 6) { prevNum.erase(prevNum.begin()); }
    return ranNum;
}
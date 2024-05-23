#include "Rivers.h"

Rivers::Rivers(const std::vector<std::string>& filenames) : m(rivers , tempCont)
{
    boost::mutex mt;
    boost::thread_group threads;

    for (string filename : filenames)
    {
        size_t pos = filename.find('.'); //finds position of ' . ' in filename
        string contName = filename.substr(0, pos); // splits and stores all the text up until the ' . '

        threads.add_thread(new boost::thread(&FileReading::readFile, &fr, filename, boost::ref(rivers), boost::ref(mt))); // adds a thread on the current instance
        tempCont.push_back(contName);
    }
    threads.join_all();

    riversToTrie(); // inserts rivers into Trie upon initializing 
}

std::string Rivers::getRandomRiver() // selects a mode to be used for selecting rivers
{
    switch (modeSelect)
    {
    case 1: { return m.mode1(); break; }
    case 3: { return m.mode3(); break; }
    default: { return m.mode2(); break; }
    }
}

bool Rivers::sameContinent(std::string r1, std::string r2) // checks if rivers are from the same continent
{
    if (rivers.find(r1) != rivers.end() && rivers.find(r2) != rivers.end())
    {
        return getContinent(r1) == getContinent(r2);
    }
    return false;
}

std::string Rivers::getContinent(std::string river) // gets a continent from the river that is given as a parameter
{
    if (trie.search(river) == river)
    {
        return rivers[river];
    }
    return "";
}

void Rivers::riversToTrie() // passes the rivers that have been read through the filereading into the trie data structure
{
    for (auto const& [key, val] : rivers)
    {
        trie.insert(key);
    }
}
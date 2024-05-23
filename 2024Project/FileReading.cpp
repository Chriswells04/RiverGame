#include "FileReading.h"

void FileReading::readFile(string filename, unordered_map<string, string>& river, boost::mutex& mt)
{ 
    string line;
    size_t pos = filename.find('.'); //finds position of ' . ' in filename
    string contName = filename.substr(0, pos); // splits and stores all the text up until the ' . ' 
    std::ifstream ifs(filename);
    
    try
    {
        if (!ifs)
        {
            throw fileReadingException();
        }
        while (getline(ifs, line))
        {
            addToMap(line, contName, river, mt);
        }
    }
    catch (fileReadingException& frex) {
        std::cerr << frex.what() << std::endl;
        std::cerr << "File could not be read" << std::endl;
    }
    ifs.close();
    
}

void FileReading::addToMap(string key, string value, unordered_map<string, string>& river, boost::mutex& mt)
{
    boost::unique_lock<boost::mutex> lock(mt);
    river[key] = value;
}

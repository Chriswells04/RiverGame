#pragma once
#include <iostream>
#include <unordered_map>
#include <boost/thread.hpp>
#include <fstream>

using std::vector, std::string, std::unordered_map;

/**
* @file FileReading.h
* @brief This file handles the FileReading.
*
*/

/**
* File reading custom exception class
* 
*/
class fileReadingException : public std::exception {
public:
    /**
    * What method \n
    * Creates a custom message for the custom exception
    * @return exception message to explain what was caught
    */
    virtual const char* what() const noexcept { return "File reading exception"; }
};

/**
* File Reading class.
* Reads files and process the data into a data structure
*
*/
class FileReading 
{
public:
    /**
    * Read file\n
    * reads a file that is selected.\n
    * Time complexity: O(n)
    * @param filename
    * @param unordered map for rivers paired with the continent it is from
    * @param mutex
    * 
    */
	void readFile(string filename, unordered_map<string, string>& river, boost::mutex& mt);

    /**
    * Add to map\n
    * adds the river name and continent to the map that is provided as a reference\n
    * Time complexity: O(1)
    * @param key: river name
    * @param value: continent name
    * @param unordered map for rivers paired with the continent it is from
    * @param mutex
    * 
    */
	void addToMap(string key, string value, unordered_map<string, string>& rivers, boost::mutex& mt);
};
#define BOOST_TEST_MAIN 
#include "Rivers.h"
#include "Game.h"
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <cstdlib>
namespace bdata = boost::unit_test::data;

const std::vector<std::string> files = { "Europe.txt","Asia.txt","Africa.txt","South America.txt" };
std::unordered_map<std::string, std::vector<std::string> > riverData = { {"Europe", {"Rhone","Rhine","Danube","Loire","Volga"}} ,
                                                                                {"Asia" , {"Jordan", "Hai", "Periyar", "Irtysh", "Syr Darya"}},
                                                                                {"Africa", {"Umgeni","Kasai","Wouri", "Kufue", "Mara"}},
                                                                                {"South America", {"Amazon","Orinoco","Paraguay","Rio Grande", "Amazon"}}
};
vector<string> rivers = { "Umgeni","Kasai","Wouri", "Kufue", "Mara" };

Rivers r(files);
Game g = Game(r);
Trie tr;
FileReading fr;

BOOST_DATA_TEST_CASE(datacase1, bdata::make({ "Jordan", "Umgeni" }) ^ bdata::make({ "Hai", "Kasai" }), river1, river2)
{
    // checks that 2 rivers from the same contininet retrun true
    BOOST_CHECK_EQUAL(r.sameContinent(river1, river2), true);
}

BOOST_DATA_TEST_CASE(randomCase1, bdata::random(0, 3) ^ bdata::random(0,4) ^ bdata::xrange(100), continent, river, index)
{
    for (auto& [key,value]: riverData)
    {
        // checks that the river selected is returning the same continent that it is from
        BOOST_CHECK_EQUAL(r.getContinent(value[river]), key);
    }    
}
   
BOOST_AUTO_TEST_CASE(fastestTimes) {
    vector<string> fastestTimes = g.getFastest();
    BOOST_CHECK(fastestTimes.empty());  

    map<int, string> sortedTimes;
    g.setSortTimes(250, "river1,river2,");
    g.setSortTimes(100, "river3,river4,");
    g.setSortTimes(300, "river5,river6,");
    g.setSortTimes(9999,"river7,river8,");
    g.setSortTimes(767, "river9,river10,");

    fastestTimes = g.getFastest();
    // checks that if there are more than 5 rivers in the vector above it should return 5 no matter what
    BOOST_CHECK_EQUAL(fastestTimes.size(), 5);

    // checks to see that the first item in the vector is the fastest time
    BOOST_CHECK_EQUAL(fastestTimes[0], "river3,river4,100");
}

BOOST_AUTO_TEST_CASE(TrieSearch) {
    tr.insert("Hous");
    string found = tr.search("Hous");
    // checks that the name inserted into trie is found
    BOOST_CHECK(tr.search("Hous") == found);
    // checks that something different is not passing instead
    BOOST_CHECK(tr.search("noName") != found);
}

unordered_map<string, string> riverTest;
boost::mutex mt;

BOOST_AUTO_TEST_CASE(fileReading) {
    fr.readFile("Toast.txt", riverTest, mt);
   
    // empty as the file does not exist
    BOOST_CHECK(riverTest.empty() == true);

    riverTest.insert({ "riverName", "ContName" });
    // false as the map now contains one element
    BOOST_CHECK(riverTest.empty() != true);
}

BOOST_AUTO_TEST_CASE(addToMap) {
    fr.addToMap("riverName", "contName", riverTest, mt);
    // checks that the the function is adding an item to the map data structure
    BOOST_CHECK(riverTest.size() == 1);
}

BOOST_AUTO_TEST_CASE(checkTotal) {
    g.setTotal(6);
    // checks total is equal to the amount set
    BOOST_CHECK(g.getTotal() == 6);

    g.reset();
    // checks that when reset, values get set back to 0
    BOOST_CHECK(g.getTotal() == 0);
}
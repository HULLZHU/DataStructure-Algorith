#include <iostream  >
#include <fstream>
#include <string>
#include <vector>
//#include <boost/lexical_cast.hpp> //Third Part Library provided by vendors
using namespace std;

struct Journal{
    //Attributes
    string title;
    vector <string> entries;

    //Constructors
    explicit Journal(const string &title) //Avoid Implicit conversion caused by single argument constructor
            : title{title} //Initialize argument title
    {
    };

    //methods
    void add(const string &entry);
};

void Journal::add(const string &entry)
{
    static int count = 1; //function-scope static variable
    entries.push_back(std::to_string(count++)+":"+entry);
}

struct PersistenceManager
{
    static void save(const Journal &journal, const string &filename)
    {
        ofstream file_writer(filename);//Open a file and create a file output stream object
        for(auto &str: journal.entries) //Iterator
            file_writer <<str<<endl;
    }
};

int main()
{
    PersistenceManager pm;

    Journal journal{"Dear Diary"};
    journal.add("I ate a bug");
    journal.add("I am a good guy");
    journal.add("Hello Ziqi");

    pm.save(journal,"journal.txt");

    return 0;
}
#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <iostream>
#include <ctime>
#include <list>
#include <boost/lexical_cast.hpp>
#include "boost/random.hpp"
//#include <boost/random/random_device.hpp>

std::list<std::string> names; // robot names
int seed = std::time(0);

namespace robot_name {

class robot {
public:
    mutable std::string n = "";
    std::string name() const;
    void reset();
};

std::string robot::name() const
{
    if (n == "") {
        std::string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        auto it = names.begin();
        //boost::random::random_device gen;
        do {
            boost::random::mt19937 gen(seed++);
            //std::cout << "seed = " << seed << "\n";

            for (auto i = 0; i < 2; i++) { // random character generation
                boost::random::uniform_int_distribution<> dist( 0, chars.size() - 1 );
                n += chars[ dist(gen) ];
            }

            for (auto i = 0; i < 3; i++) { // random number generation
                boost::random::uniform_int_distribution<> dist(0, 9);
                n += boost::lexical_cast<std::string>( dist(gen) );
            }

            names.push_back(n);

            it = std::find(names.begin(), names.end(), n);
        } while (it == names.end());

        names.push_back(n);
        std::cout << "n = " << n << "\n";
    }   
    return n;
}

void robot::reset() 
{
     n = ""; 
}

}

#endif
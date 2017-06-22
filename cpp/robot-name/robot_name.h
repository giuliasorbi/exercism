#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <iostream>
#include <ctime>
#include <list>
#include <random>
#include <boost/lexical_cast.hpp>
namespace robot_name {


std::string generate_name()
{
    std::string chars("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    std::string n = "";
    std::random_device rd;
    std::mt19937 gen(rd());
    
    for (auto i = 0; i < 2; i++) { // random character generation
        std::uniform_int_distribution<> dist( 0, chars.size() - 1 );
        n += chars[ dist(gen) ];
    }

    for (auto i = 0; i < 3; i++) { // random number generation
        std::uniform_int_distribution<> dist(0, 9);
        n += std::to_string ( dist(gen) );
    }
    return n;
}

class robot {
public:
    robot();
    std::string name() const;
    void reset();

    ~robot() {
        name_list.remove(m_name); // robot name list
    }; 

private:
    std::string m_name;
    static std::list<std::string> name_list; 
};

std::list<std::string> robot::name_list;

robot::robot() 
{
    auto it = name_list.end();

    do {  
        m_name = generate_name();
        it = std::find(name_list.begin(), name_list.end(), m_name);
    } while ( it != name_list.end() );

    name_list.push_back(m_name);
    //std::cout << "name = " << m_name << "\n";
}

std::string robot::name() const
{ 
    return m_name;
}

void robot::reset() 
{
    name_list.remove(m_name);
    m_name = generate_name();
}

}

#endif
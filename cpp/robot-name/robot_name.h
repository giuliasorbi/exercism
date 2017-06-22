#if !defined(ROBOT_NAME_H)
#define ROBOT_NAME_H
#include <iostream>
#include <list>

namespace robot_name {

class robot {
public:
    robot();
    std::string name() const;
    void reset();
    ~robot();

private:
    std::string m_name;
    static std::list<std::string> name_list; 
};

std::string generate_name();

}

#endif
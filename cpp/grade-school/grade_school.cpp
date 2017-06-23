#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "grade_school.h"

namespace grade_school {

school::school() {
    m_roster = {};
}

std::map<int, std::vector<std::string>> school::roster() const {
    return m_roster;
}

void school::add( std::string name, int grade ) {
    std::vector<std::string>::iterator it = std::upper_bound( m_roster[grade].begin(), m_roster[grade].end(), name ); 
    m_roster[grade].insert( it, name );
}

std::vector<std::string> school::grade(int g) const {
    try {
        return m_roster.at(g);
    }
    catch( std::out_of_range e ) {
        return {};
    }
}

}
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
    std::map<int, std::vector<std::string>> result = m_roster;
    for (auto &grade_names : result) {
        std::sort( grade_names.second.begin(), grade_names.second.end() ); 
    }
    return result;
}

void school::add( std::string name, int grade ) {
    m_roster[grade].push_back(name);
}

std::vector<std::string> school::grade(int g) const {
    std::vector <std::string> result;
    try {
        result = m_roster.at(g);
        std::sort(result.begin(), result.end() );
    }
    catch( std::out_of_range e ) {
        result = {};
    }
    return result;
}

}
#if !defined(GRADE_SCHOOL_H)
#define GRADE_SCHOOL_H
#include <iostream>
#include <map>
#include <vector>


namespace grade_school {

class school {
public:
    school();
    void add( std::string name, int grade );
    std::map<int, std::vector<std::string>> roster() const;
    std::vector<std::string> grade( int g) const ;

private:
    std::map<int, std::vector<std::string>> m_roster;
};

}


#endif
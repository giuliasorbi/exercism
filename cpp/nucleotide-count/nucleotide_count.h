#if !defined(NUCLEOTIDE_COUNT_H)
#define NUCLEOTIDE_COUNT_H
#include <iostream>
#include <map>

namespace dna {

class counter {
public: 
    counter(std::string dna);
    std::map <char, int> nucleotide_counts() const;
    int count(char nucleotide) const;
private:
     std::string m_dna;
};

}

#endif
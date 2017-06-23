#include <iostream>
#include <map>
#include "nucleotide_count.h"

namespace dna {

counter::counter( std::string dna ) {
    for ( auto i = 0; i < dna.size(); i++) {
        if( dna[i] != 'A' && dna[i] != 'T' && dna[i] != 'C' && dna[i] != 'G' ) {
            throw std::invalid_argument( std::to_string(dna[i])+" isn't a nucleotide\n" );
        }
    }   
    m_dna = dna;
}

std::map <char, int> counter::nucleotide_counts() const
{
    std::map<char,int> result { {'A', 0}, {'T', 0}, {'C', 0}, {'G', 0} };

    for ( auto i = 0; i < m_dna.size(); i++ ) {
        result[ m_dna[i] ] ++;
    }
    return result;
}

int counter::count(char nucleotide) const
{
    auto count = 0;
    for ( auto i = 0; i < m_dna.size(); i++ ) {
        if ( m_dna[i] == nucleotide ) {
            count++;
        }
    }

    if( (count == 0)  && (m_dna != "") ) {
        throw std::invalid_argument( std::to_string(nucleotide)+" isn't a nucleotide\n" );
    }
    return count;
}

}
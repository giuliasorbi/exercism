#if !defined(GIGASECOND_H)
#define GIGASECOND_H

#include <string>
#include <iostream>
#include <sstream>
#include <locale>
#include <ctime>
#include <iomanip>
#include "boost/date_time/posix_time/posix_time.hpp"

using namespace boost::posix_time;

namespace gigasecond {

ptime advance(ptime p) {

    std::tm t = to_tm(p);
    t.tm_isdst = 0;
    std::cout << t.tm_year << "-" << t.tm_mon << "-" << t.tm_mday <<"\n";
    std::cout << t.tm_hour << ":" << t.tm_min << ":" << t.tm_sec <<"\n";
    std::cout << t.tm_mday << " " << t.tm_wday << " " << t.tm_yday << "\n";
    std::cout << "DST flag:" << t.tm_isdst <<"\n";

    std::time_t time = mktime(&t); 
    std::cout << "time: " << time <<"\n";
    time += 1000000000;
    std::cout << "time: " << time <<"\n";
    
    t = *std::localtime(&time);
    std::cout << "DST flag:" << t.tm_isdst <<"\n";
    ptime tt = ptime_from_tm(t);
     
    return tt;
    
}

}



#endif

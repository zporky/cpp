
/*
 * calendar: list of dates, hours and associated events
 *
 */

#include <iostream>
#include <string>
#include "date.h"
#include "calendar.h"

int main()
{
    int your_mark = 1;
/*
    // default constructor: creates an empty list of events
    calendar my_calendar;  

    // inserting elements done ordered by date. insert returns bool
    my_calendar.insert(2015,5,18, 12, "Lunch");  
    my_calendar.insert(2015,5,18, 10, "C++ exam");  
    my_calendar.insert(2015,5,11,  8, "Practicing for C++ exam");

    if ( 3 == my_calendar.size() )
        ++your_mark;

    my_calendar.insert(2015,5,17,  8, "Reading C++ material");  // ok
    my_calendar.insert(2015,5,19, 20, "Party");      // ok, after exam
  
    // duplicated date+hour insert must return false
    if ( false == my_calendar.insert(2015,5,18, 10, "Other exam") // exists
          && 5 == my_calendar.size() )
        ++your_mark;

    // replace existing entries only. replace returns bool
    if ( true == my_calendar.replace(2015,5,19, 20, "More practicing")// exists
          && false == my_calendar.replace(2015,5,19, 22, "Party") // not exists
          && 5 == my_calendar.size()  )  
        ++your_mark;      

    // returns existing elements with their enty, otherwise return emty string
    if ( my_calendar.get(2015,5,18, 10) == "C++ exam"  // exists
          && my_calendar.get(2015,5,19, 22) == "" )    // not exists
        ++your_mark;

    std::cout << "my_calendar:" << std::endl;
    my_calendar.print();
    std::cout << std::endl;
*/
    std::cout << "Your mark is " << your_mark << std::endl;
    return 0;
} 




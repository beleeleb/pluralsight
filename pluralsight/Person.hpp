//
//  Person.hpp
//  pluralsight
//
//  Created by gali zorea on 13/08/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef Person_hpp
#define Person_hpp
#include <string>
#include <stdio.h>
class Person
{
private:
    std::string m_firstName;
    std::string m_lastName;
    int m_age;
    
public:
    Person(std::string o_firstName = "john", std::string o_lastName = "doe", int o_age = 123);
    ~Person();
    
};
#endif /* Person_hpp */

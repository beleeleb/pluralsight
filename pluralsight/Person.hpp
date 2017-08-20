//
//  Person.hpp
//  pluralsight
//
//  Created by gali zorea on 13/08/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef Person_hpp  //include guard
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
    std::string getName();
    int getAge() {return m_age;}; //inline functions
    void setAge(int newage){ m_age = newage;}; //inline functions
    
};
#endif /* Person_hpp */

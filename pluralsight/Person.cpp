//
//  Person.cpp
//  pluralsight
//
//  Created by gali zorea on 13/08/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "Person.hpp"
#include <iostream>
using namespace std;
Person::Person(std::string o_firstName, std::string o_lastName, int o_age):m_firstName(o_firstName), m_lastName(o_lastName), m_age(o_age)
{
    std::cout << "construct: " << "first - "<<m_firstName << " last - " << m_lastName << " age - " << m_age <<std::endl;
    
}

Person::~Person()
{
    std::cout << "destruct: " << m_firstName <<std::endl;
}

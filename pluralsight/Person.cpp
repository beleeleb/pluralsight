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
Person::Person(string o_firstName, std::string o_lastName, int o_age):m_firstName(o_firstName), m_lastName(o_lastName), m_age(o_age)
{
    std::cout << "construct: " << getName() <<std::endl;
}

Person::~Person()
{
    std::cout << "destruct: " << getName() <<std::endl;
}
std::string Person::getName() const
{
    return "first - " + m_firstName + " last - " + m_lastName + " age - " + to_string(getAge()); // could also use std::ostringstream  instead of to_string
}

bool Person::operator <  (const Person& p ) const
{
    return m_age < p.m_age;
}

bool Person::operator < (int num) const
{
    return m_age < num;
}


bool operator< (int num,const Person& p)
{
    return num < p.getAge(); //we could use p.m_age here because of decalring friend. No need here though because we already have a public function for the private member.
}
    

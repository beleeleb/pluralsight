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
Person::Person(string o_firstName, std::string o_lastName, int o_age):m_firstName(o_firstName), m_lastName(o_lastName), m_age(o_age), m_pResource(nullptr)
{
    std::cout << "construct Person: " << getName() <<std::endl;
}

Person::~Person()
{
    std::cout << "destruct Person: " << getName() <<std::endl;
    delete m_pResource;
}
std::string Person::getName() const
{
    return m_firstName + " " + m_lastName + " age: " + to_string(getAge()); // could also use std::ostringstream  instead of to_string
}

void Person::setName(string o_fname,string o_lname)
{
    m_firstName = o_fname;
    m_lastName = o_lname;
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

void Person::addResource()
{
    m_spResource.reset(); //decrement reference count or delete if 0
    m_spResource = std::make_shared<Resource>("shared ptr " + getName());
   delete m_pResource; //we have to ensure that previous alloc is deleted if exists. no problem to delete nullptr in the first time.
    m_pResource = new Resource("ptr " + getName());
}

Person::Person(const Person& p):m_firstName(p.m_firstName), m_lastName(p.m_lastName), m_age(p.m_age), m_pResource(new Resource("ptr copy " + p.getName())) //we have to alloc new resouce for the copy, since once both the source and the copied objects are deleted, we have to ensure we don't double free the same pointer.
{
    
}

Person& Person::operator=(const Person& p)
{
    m_firstName = p.m_firstName;
    m_lastName =p.m_lastName;
    m_age = p.m_age;
    delete m_pResource; //we have to ensure that we delete previous pointer (in contrary to copy constructor)
    m_pResource = new Resource("ptr assignment " + p.getName());
    return *this; //we return the derferenced pointer to ourselves in assignment operator overload
}




//
//  Person.cpp
//  pluralsight
//
//  Created by gali zorea on 13/08/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "Person.hpp"
#include "Noise.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;
Person::Person(string o_firstName, std::string o_lastName, int o_age):m_firstName(o_firstName), m_lastName(o_lastName), m_age(o_age)
#ifdef RULEOF3
, m_pResource(nullptr)
#endif
{
    Noise bloop("bloop");
    if(m_age <= 0)
    {
        throw invalid_argument("age cannot be zero or less");
    }
    
    
    std::cout << "construct Person: " << getName() <<std::endl;
}

#ifdef RULEOF3 //in case we are using a shared_ptr we will use the default dtor (and virtual for polymorphic ability)
Person::~Person()
{
    std::cout << "destruct Person: " << getName() <<std::endl;
    delete m_pResource;
}
#endif

std::string Person::getName() const
{
    return m_firstName + " " + m_lastName + " age: " + to_string(getAge()); // could also use std::ostringstream  instead of to_string
}

void Person::setName(string o_fname,string o_lname)
{
    m_firstName = o_fname;
    m_lastName = o_lname;
#ifdef RULEOF3          //we have to update the inner resource name as well
    if(m_pResource)
    m_pResource->setName(Person::getName());//we need to update resource values as well
#endif
}

void Person::setAge(int newage)
{
     m_age = newage;
#ifdef RULEOF3 //we have to update the inner resource name as well
    if(m_pResource)
     m_pResource->setName(Person::getName());//we need to update resource values as well
#endif
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
#ifndef RULEOF3

    m_spResource.reset(); //decrement reference count or delete if 0
    m_spResource = std::make_shared<Resource>("shared ptr " + getName());
#else
   delete m_pResource; //we have to ensure that previous alloc is deleted if exists. no problem to delete nullptr in the first time.
    m_pResource = new Resource("ptr " + getName());
#endif
}
#ifdef RULEOF3
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

#endif


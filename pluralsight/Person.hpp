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
    std::string getName() const;
    int getAge() const {return m_age;};  //inline functions
    void setAge(int newage) { m_age = newage;}; //inline functions - can't use const here since it changes a member
    bool operator < (const Person& p ) const ; //pass by reference, added const to ref since we are not changing it
    bool operator < (int num) const;
    friend bool operator< (int num, const Person& p); //we decalre friend here in order to allow access to private member, in case we don't have a public function allowing access to the private member. This can't be const since it's any case doesn't have access to members of the class.

};

bool operator< (int num, const Person& p); //pass by reference, added to const to ref, since we are not changing it
#endif /* Person_hpp */

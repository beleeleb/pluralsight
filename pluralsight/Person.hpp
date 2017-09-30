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
#include <memory> //for shared ptr
#include <stdio.h>
#include "Resource.hpp"
class Person
{
protected:                      //changed to be protected so that dervied classes may access these members
    std::string m_firstName;
    std::string m_lastName;
    int m_age;
private:
    Resource * m_pResource;
    std::shared_ptr<Resource> m_spResource;
    
public:
    Person(std::string o_firstName = "john", std::string o_lastName = "doe", int o_age = 123);
    Person(const Person& p); //copy constructor for handling copying when free resources are invloved *RULE OF 3*
    virtual ~Person(); //we add here the virtual since we want to invoke the dervied dtor as well as Person dtor. Rule of thumb is using virtual dtor every time we use virtual keyword in class
    void addResource();
    virtual std::string getName() const;//in case the tweeter handle is set in a base class pointer, the virtual keyword invokes the dervied getName, if it's missing, it would have used the base class getName - allows derived overridning
    void setName(std::string o_fname,std::string l_fname);

    int getAge() const {return m_age;};  //inline functions
    void setAge(int newage) { m_age = newage;}; //inline functions - can't use const here since it changes a member
    bool operator < (const Person& p ) const ; //pass by reference, added const to ref since we are not changing it
    bool operator < (int num) const;
    friend bool operator< (int num, const Person& p); //we decalre friend here in order to allow access to private member, in case we don't have a public function allowing access to the private member. This can't be const since it's any case doesn't have access to members of the class.
    Person& operator=(const Person& p); //assignmnet operator overload that takes in mind the resource issue;
    
    //when using shared ptr , no need for cctor, ator for shared ptr, also no need to delete sahred ptr in dtor!
    
    std::string getResourceName() const {return m_spResource->getName();};

};

bool operator< (int num, const Person& p); //pass by reference, added to const to ref, since we are not changing it
#endif /* Person_hpp */

//
//  Const.cpp
//  pluralsight
//
//  Created by gali zorea on 12/09/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "Const.hpp"
#include "Person.hpp"
#include <iostream>
using namespace std;
int doubleIt(const int &x) //in Order to accept intger literarls, it has to take the parameter as const
{
    
    return x*2;
}

void constExamples()
{
    int i = 3;
    const int ci = 4;
    // ci = i; //can't assign a new value to const value
    
    int j = 5;
    int multij = doubleIt(j);
    int multi10 = doubleIt(10);
    cout << "multij: " << multij << " multi10: " << multi10 << endl;
    
    Person nisha("nisha", "hug", 1);
    nisha.setAge(23);
    const Person cnisha("cnisha", "chug", 2);
    //cnisha.setAge(24); //If I use a member function of a const object, I have to use a const member function
    cout << cnisha.getName() << endl;

    int *pI = &i; //set the int ptr to the address of i
    //int *pII = &ci; //cannot use int ptr to point to a const type i
    const int *pII = &ci; //this should work
    
    const int * pcI = pI; //this causes the compiler to look at the value of pI as constant, so I can't change it lvalue;
    //*pcI = 4; //readonly
    pcI = &j; //no problem to change the pointing address since it's not constant
    
    int * const cpI = pI; // now the const pointer points only to this address, though we can alter it's content
    *pI = 5;
    //cpI = &j; //Not doable, since this is a const pointer.
    
    const int * const tuff = pI;
    //*tuff =  4; //Both are illegal
    //tuff = &j;
    
    int k = *tuff; // because it's readonly, no problem to read from tuff
    
    cout << "k: " <<k << "*cpI = "<< *cpI << "*pII"<<*pII<< endl;
    
    
}

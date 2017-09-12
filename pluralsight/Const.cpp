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
    //int i = 3;
    //const int ci = 4;
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
    
}

//
//  PtrsnRefs.cpp
//  pluralsight
//
//  Created by gali zorea on 02/09/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "PtrsnRefs.hpp"

#include <iostream>
#include "Person.hpp"
using namespace std;

void ptrsDemo()
{
    int a = 3;
    cout << "a: " << a << endl;
    int *aptr = &a;
    *aptr = 4;
    cout << "a: " << a << endl;
    
    int b = 100;
    aptr = &b;
    (*aptr)++;
    cout << "a: " << a << "*aptr: " << *aptr << endl;
    
    Person kate("kate", "greg", 43);
    Person* pkate = &kate;
    (*pkate).setAge(66);
    
    cout << "kate: " << kate.getName() <<endl;
    cout << "pkate: " << pkate->getName() <<endl;
    
    int & aref = a;
    aref = 5;
    
    cout << "a: " << a << " aref: " << aref << endl;
    
    Person& refkate = kate;
    refkate.setAge(555);
    
    cout << "refkate: " << refkate.getName() <<endl;
    
    int *badptr = nullptr;
    if(badptr)
    {
        *badptr = 5;
        cout << "*badptr: " << *badptr <<endl;
    }
    
    //int &badref; //The advantage of using ref other ptr, is that it already comes with a protection from uninitialised ref, so it won't compile.
    //badref = 5;
    
    //cout << "badref: " << badref <<endl;

}

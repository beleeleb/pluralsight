//
//  Accum.hpp
//  pluralsight
//
//  Created by gali zorea on 25/08/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef Accum_hpp
#define Accum_hpp
#include <iostream>
#include "Person.hpp"
template <class T>
class Accum
{
private:
    T total;
public:
    Accum(T value): total(value){}; //constructor - java style implementation
    T operator += (const T& t) {return total = total + t;};
    T getTotal(void) {return total;};
};

template <>
class Accum <Person>
{
private:
    int total;
public:
    Accum(int value): total(value){}; //constructor - java style implementation
    int operator += (Person& t) {return total = total + t.getAge();};
    int getTotal(void) {return total;};
};

#endif /* Accum_hpp */

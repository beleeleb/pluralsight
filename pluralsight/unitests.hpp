//
//  unitests.hpp
//  pluralsight
//
//  Created by gali zorea on 26/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef unitests_hpp
#define unitests_hpp

#include "collections.hpp"
#include "account.hpp"
#include "casts.hpp"
#include "Person.hpp"
#include "Tweeter.hpp"
#include "Accum.hpp"
#include "PtrsnRefs.hpp"
#include "Const.hpp"
#include "Resource.hpp"
#include "Stl.hpp"
template <class T>
T max(T& t1, T& t2)
{
    return t1 < t2 ? t2 : t1;
}



void bank_test(void);

void collections_test(void);

void casts_test(void);

void Person_class_test();
void factorial();
bool isPrime(int number);
void addThreeByVal(int number);
void addThreeByRef(int& number);
void immediateIF();
void operators_test();
void max_template_test();
void class_template_test();
void testPtrsnRefs();
void testConst();
void allocTest();
void memTest();
void inheritTest();
void cppCastings();
void stlTests();
#endif /* unitests1_hpp */

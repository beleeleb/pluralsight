//
//  casts.cpp
//  pluralsight
//
//  Created by gali zorea on 06/07/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "casts.hpp"
using namespace std;
void demo_casts(void)
{
    int i1 = 1;// three possible ways to declare and init primivtie types
    int i2;
    i2 = 2;
    int i3(3);
    cout << "cast_test i3: " <<i3 << endl;
    double d1 = 2.2;
    double d2 = i1; //this ok because double can contain int
    cout << "cast_test d2 " <<d2 << endl;
    
    int i5 = (int)1435555346663L;// three possible ways to declare and init primivtie types

    cout << "cast_test i5: " <<i5 << endl;

    int i4 = d1;// this will cause possible data loss because it will truncate the fragment. added (int) to avoid warning
    cout << "cast_test i4: " <<i4 << endl;

    bool flag = false;
    flag = i1; //added (bool) to avoid warning.
    flag = d1; //added (bool) to avoid warning.

    
}



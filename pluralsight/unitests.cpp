//
//  unitests.cpp
//  pluralsight
//
//  Created by gali zorea on 26/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "unitests.hpp"

void bank_test(void)
{
    const double start_amount =0.0;
    account a1(start_amount);
    
    for (auto item: a1.report())
    {
        cout << item << endl;
    }
    a1.deposit(30);
    
    a1.deposit(45);
    
    a1.withdraw(20);
    
    a1.withdraw(10);
    
    a1.withdraw(200);
    
    
    for (auto item: a1.report())
    {
        cout << item << endl;
    }

}
void collections_test(void)
{
     myvector();
}

void casts_test(void)
{
    demo_casts();
}

void Person_class_test()
{
    
    Person p1; //since no parameters are passed it will be constructed by default values
    
    Person p2("yan", "pelov", 12);
    
    Tweeter t1("moshe", "snow", 555, "@whatever");
}

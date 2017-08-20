//
//  unitests.cpp
//  pluralsight
//
//  Created by gali zorea on 26/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "unitests.hpp"
#include "Status.hpp"
using namespace std;
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
    cout << "curr age: "<< t1.getAge() << endl;
    t1.setAge(666);
    cout << "new age: "<< t1.getAge() <<endl;
    Status s = pending;
    s = approved;
}

void operators()
{
    cout << "factorial check: enter number" << endl;
    int number;
    cin >> number;
    if(isPrime(number) == true)
    {
        cout << number<<" is prime" << endl;
    }
    
    else
    {
        cout << number<<" isn't prime" << endl;
    }
    
    int testRefVal = 7;
    
    cout << "testRefVal, orig value: " << testRefVal << endl;
    addThreeByVal(testRefVal);
    cout << "testRefVal, add 3 by value to orig : " << testRefVal << endl;
    addThreeByRef(testRefVal);
    cout << "testRefVal, add 3 by ref to orig : " << testRefVal << endl;
    
}

bool isPrime(int number)
{
    int x;
    bool prime = true;
    for(x=2;;x++)
    {
        if(number%x == 0)
        {
            if(number/x > x)
            {
                prime = false;
                cout << "factor: " <<x <<endl;
                
                cout << "factor: " << number/x << endl;
            }
            
            else break;
        }
        
    }
    
    return prime;
}

void addThreeByRef(int& number)
{
    number += 3;
}

void addThreeByVal(int number)
{
    number += 3;
}

void immediateIF()
{
    int num = 1;
    while(num > 0)
    {
        cout << "enter num: " << endl;
        cin >> num;
        string s = num>0 ? "num is positive": "num is 0 or negative";
        cout << s << endl;
    }
}


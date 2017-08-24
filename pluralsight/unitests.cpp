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
    
    Person p2("zyan", "zpelov", 12);
    
    Tweeter t1("moshe", "snow", 555, "@whatever");
    cout << "curr age: "<< t1.getAge() << endl;
    t1.setAge(666);
    cout << "new age: "<< t1.getAge() <<endl;
    Status s = pending;
    s = approved;
    
    p1 < p2 ? (cout << "p1 is less then p2" << endl):(cout << "p1 is greater then p2" << endl);
    p1 < 300? (cout << "p1 is less then 300" << endl):(cout << "p1 is greater then 300" << endl);
    300 < p1? (cout << "300 is less then p1" << endl):(cout << "300 is greater then p1" << endl);

}

void factorial()
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
    for(x=2;;x++) //TODO: should alter algroithm to consider 0 and 1 as well, as these aren't primes
    {
        if(number%x == 0)
        {
            if(number/x >= x)
            {
                prime = false;
               // cout << "factor: " <<x <<endl;
                //cout << "factor: " << number/x << endl;
            }
            
            else break;
        }
        
    }
    if(prime)
        cout << "prime: " << number << endl;
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

void operators_test()
{
    int i;
    int count = 0;
    for (i = 2; i < 101; i++)
    {
        count += isPrime(i)?1:0;
        
    }
    
    cout << "there are " << count << " primes from 2 to 100" << endl;
    
    int j;
    
    cout << "enter num1: " << endl;
    cin >> i;
    cout << "enter num2: " <<endl;
    cin >> j;
    
    if(j && !(i % j) ) //j protects divide by zero
    {
        cout << i << " is a multiplie of "<< j<<endl;
    }
    
    else
    {
        cout << i << " is not multiplie of "<< j<<endl;
    }
}

//
//  unitests.cpp
//  pluralsight
//
//  Created by gali zorea on 26/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "unitests.hpp"
#include "Status.hpp"
#include "Noise.hpp"
#include <memory>
#include <stdexcept>
#include <cstring>
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

void max_template_test()
{
    string str1("aaa");
    string str2("bbb");
    Person p1("shimi", "tavori", 128);
    Person p2("miki", "buganim", 55);
    
    cout << "which str is bigger? " << max(str1,str2) << endl;
    cout << "which Person is bigger? " << max(p1, p2).getName() << endl;
    cout << "which num is bigger? " << max<double>(33, 4.5) << endl;//explict since compiler not sure whether we want here an int or double
}

void class_template_test()
{
    
    string s1("hello");
    string s2("world");
    
    Accum <int> running(0);
    Accum <string> string_total("");

    for (int i =1; i<101; i++)
    {
        cout << std::to_string(running+=i) << endl; //running+=i return type int not Accum <int>
    }
    
    cout << endl << "total is: " << running.getTotal() <<endl;

    
    string_total+=s1;
    string_total+=s2;

    cout << string_total.getTotal() <<endl;
    
    Accum <Person> pplSum(0); //using a specialized template for Person. we do so because we don't have an overload for += operator.
    Person p1("shosh", "bu", 123);
    Person p2("don", "kishot", 543);
    
    pplSum+=p1;
    pplSum+=p2;
    
    cout << "ppl sum: " << pplSum.getTotal()<< endl;
}

void testPtrsnRefs()
{
    ptrsDemo();
}

void testConst()
{
    constExamples();
}

void allocTest()
{
    Resource first("alon");
    string local_name = first.getName();
    cout << local_name << endl;
    
    Resource *rptr = new Resource("demo");
    string str  = rptr->getName();
    
    Resource *rptr2 = rptr;//makes a copy
    string str2 = rptr2->getName();
    cout << "str2: "<< str2 << endl;
    delete rptr;

    //string str3 = rptr->getName(); // use of dangling ptr
    //cout << "str3: "<< str3 << endl;
   /* rptr = nullptr;
    delete rptr; //no problem deleting a null ptr - just returns, if we wouldn't have set rptr to null, it would have cause a double free error
    delete rptr2; //delete the address of rptr when it's already set to null*/
    
}

void memTest()
{
    Person jake("jake", "ripper", 123);
    jake.addResource();
    jake.setName("jake2", "ripper2");
    jake.setAge(456);

   jake.addResource();
    Person jake2 = jake;
    jake = jake2;
    cout << "name of resource: " << jake.getResourceName() << endl;
}

void inheritTest()
{
    Tweeter hashtag("john", "travolta", 167, "atwork");
    cout << hashtag.getName() << endl;
    
    Person* dudu = new Person("dudu", "topaz", 47);
    Tweeter* shop = new Tweeter("don", "kishot", 33, "shopify");
    
    Person* pHandle = shop;
    cout << dudu->getName() << endl;
    cout << shop->getName() << endl;
    cout << pHandle->getName() << endl;
    delete dudu;
    delete pHandle;
    
    shared_ptr<Person> sp1 = make_shared<Person>("auto", "pilot", 3);
    auto sp2 = make_shared<Person>("auto", "vehicle", 4); //auto knows already what is the expetced return type
    
    shared_ptr<Person>sp3 = make_shared<Tweeter>("loko", "moto", 5, "walla"); //no problem setting a derived class pointer to a base class pointer, but if we do so with copying solid object, we will encounter slicing.
    cout << sp3->getName() << endl;
    
    Tweeter localT("eee", "aaa", 134, "athome");

    Person localP;// = localT; //slicing happens if we copy solid object to another
    Person& refP = localT; //slicing will be avoided if we use reference
    cout << localP.getName() << endl;
    cout << refP.getName() << endl;

}

void cppCastings()
{
    Tweeter t1("non", "greta", 333, "atschool");
    Person *p = &t1; //set p to point to tweeter, polymorphic
    cout << p->getName() << endl;
    //Tweeter* t2  = p; // no way to init dervied class from base without casting the handle to a dervied one.
    Tweeter* t2  = static_cast<Tweeter*>(p); // We need to use static_cast.
    cout << t2->getName() << endl;

    //int i = 6;
    //Tweeter* t3 = (Tweeter*)&i;  //we could c style cast to allow this but it won't check the validity of the type we are using
    //cout << t3->getName() << endl;

    //Tweeter* t4 = static_cast<Tweeter*>(&i);  //static cast will warn us at compile time here that we can't case from int* to Tweeter*.
    Resource something("check");
    Tweeter* t5 = dynamic_cast<Tweeter*>(&something); //dynamic_cast can only accept polymorphic and non primitive type. since Resource isn't related to Tweeter it's will fail to cast.

    if(t5!=nullptr) //it's suggested to test the dynamic cast return so that we don't blow if the cast failed
    {
        cout << t5->getName() << endl;
    }
    else
    {
        cout << "dynamic cast return nullptr" << endl;
    }

    
}

void stlTests()
{
    vectorTest();
}

void lambdasTest()
{
    vector <int>int_arr ;
    int_arr.push_back(5);
    int_arr.push_back(6);
    int_arr.push_back(4);
    int_arr.push_back(9);
    int_arr.push_back(1);
    
    for_each(int_arr.begin(), int_arr.end(), [](int lam_num){
        cout << "lam_num: " << lam_num << endl;
    }
             );
    
    for_each(int_arr.begin(), int_arr.end(), [](int lam_num)
         {
             if(lam_num%2)
             {
                 cout << lam_num << " is odd" << endl;
             }
             
             else
             {
                 cout << lam_num << " is even" << endl;
             }
         }
         );
    
    vector<int> cubed;
    transform(int_arr.begin(), int_arr.end(), back_inserter(cubed), [](int n){return  n*n*n;}); // since it's all in one line, it implicity knows the return value of the lambda. the cubing operation is done on each of the new elements insterted to the new cubed vector
    for_each(cubed.begin(), cubed.end(), [](int n) {cout << "n is : " << n << endl;} );
    
    vector <double> mixed;
    transform(int_arr.begin(), int_arr.end(), back_inserter(mixed), [](int n)->double
              {
                  if(n%2 == 0) //if even -  cube
                  {
                      return n*n*n;
                  }
                  
                  else
                  {
                      return n/2.0;
                  }
              }
          );
    for_each(mixed.begin(), mixed.end(), [](double n){cout << "mixed n: " << n << endl;});
    
    int x = 3;
    int y =8;
    
    vector <int> vec;
    vec.push_back(23);
    vec.push_back(5);
    vec.push_back(7);
    for_each(vec.begin(), vec.end(), [x,y](int n) //capturing x & y from scope by value - they are const
         {
                 if(n<=y && n>=x)
                 {
                     cout << n << " in range between " << x<< " and " << y << endl;
                 }
          }
     );
    
    x = 2;
    y=6;
    
    for_each(vec.begin(), vec.end(), [=](int n)//by = we mean capture everything from scope, though actually it capture only what it needs from scope
         {
             if(n<=y && n>=x)
             {
                 cout << n << " in range between " << x<< " and " << y << endl;
             }
         }
     );
    
    x=1;
    y=5;
    for_each(vec.begin(), vec.end(), [=](int& r) mutable //mutable allows changing the captured vars by value - though they won't be saved after lambda goes out of scope. we pass the parameter by reference to change the actual value in the vector after going out of scope.
             {
                 const int old = r;
                 r *=2;
                 x=y;
                 y = old;
             }
             );
    
    vec.clear(); //this method clears the values in the vec
    
    for(int i = 0; i< 10; ++i) {vec.push_back(i);}
    
    for_each(vec.begin(), vec.end(), [&x, &y](int& r)//capture x & y by reference so their modified values will be kept after going out of scope, same for the parameter
    {
        const int old = r;
        r *=2;
        x=y;
        y = old;
    });
    
    for_each(vec.begin(), vec.end(), [x, y](int m){cout << m << " "  ;});
    vec.clear();
    int i = 0;
    generate_n(back_inserter(vec), 10, [&]{return i++;}); // this function inserts to vector, for 10 times, the value we generate in the lambda, since we are doing so by reference, the value of i will be changed after going out of scope;
    
    
}
void exceptionTest()
{
    Noise oops("oops"); //since this is outside of the try, once the excpetion goes off, this object won't be destructed.
    //example of an std::out-of-range exception
    try{
        
    Noise beep("beep");
    auto testPtr = make_shared<Noise>("sleep"); //RAII Revisited, no need to destruct it manualy as the dtor is actiavted upon end of scope
    vector <int> v ;
    v.push_back(5);
    Person p("money", "matters", -1);
    cout << v.at(99) << endl;
    
    }
    
    //important to learn the differnet possible exception to check by reading stdexcept
    catch(out_of_range& e) //catch out of range exception by reference - important to keep expection hierarcy
    {
        cout << "out of range exception " << e.what() << endl;
    }
    
    catch(exception& e) //catch general exception by reference - it's important to keep it with reference so it will polymorphize to the right exception according to the exception hierarchy and not cause slicing which will resolve with losing the derived exception type!1
    {
        cout << e.what() << endl;
    }

}
int doubler(int i)
{
    return i*2;
}

int tripler(int i)
{
    return i *3;
}

typedef int (*func) (int);
typedef int(Utility::* UF)();
void c_legacy()
{

    
    func f;
    f = doubler;
    cout << f(2) << endl;
    f = tripler;
    cout << f(3) << endl;
    
    Utility u(4);
    UF action;
    action = &Utility::tripler;
    cout << "res1: " << (u.*action)()<< " res2: " << u.tripler() << endl; //we can use dereferning of function pointer to invoke the member function
    
    
    int ints[3];
    ints[0] = 3;
    *(ints +2) = 4;
    
    float floats[] = {1.0,2.0,3.0};
    int *Ia = new int[4];
    Ia[1] = 3;
    *(Ia+1) = 4;
    int localsz = sizeof(floats)/sizeof(floats[0]);
    int freesz = sizeof(Ia); //this return the size of pointer to int but not the size of the allocation.
    int freesz2 = sizeof(Ia[0]);
    
    cout << "localsz: " << localsz << endl;
    cout << "freesz: " << freesz << endl;
    cout << "freesz2: " << freesz2 << endl;
    delete[] Ia;
    
    char* str = new char[strlen("hello kate")];
    strcpy(str,"hello");
    strcat(str, "    kate"); //bad because it overrides the memory and adds '\0' as well, when allocating or using strcat we have into account that strcat adds extra '\0';
    
    char hello[] = {'w','o','r','l','d','\0'}; //we must add '\0' here, so that strlen won't read something it shouldn't until it finds '\0'.
    cout << "len of hello: " << strlen(hello) << endl;
    
    string good("hello"); //we get capacity and length
    good+= " world"; //we append with auto-resize
    char *old_str = new char[good.length() + 1]; //make sure we save 1 space for null terminator
    //s3 = s or s3 = s.c_srt() wont work here! we need to use strcpy
    strcpy(old_str, good.c_str());
    
    cout <<"old_str: "<< old_str << " good.length() " << good.length()<< " good cap: " << good.capacity() <<endl;
    
    delete []str;
    delete []old_str;
    
    

    
}

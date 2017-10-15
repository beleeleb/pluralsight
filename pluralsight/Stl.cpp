//
//  stl.cpp
//  pluralsight
//
//  Created by gali zorea on 30/09/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "Stl.hpp"
#include "Person.hpp"
#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

void printPerson(const Person & p)
{
    cout << "age is: " << p.getAge() << endl;
}

void printInt(int i)
{
    cout << "num is: " << i << endl;
}

bool isOdd(int num)
{
    return num%2;
}

void vectorTest()
{
    vector<int> v;
    v.push_back(5); //puts and element at the end of the vector
    v.push_back(3);
    v.push_back(9);
    v.push_back(4);
    
    for(auto i = v.begin(); i != v.end(); ++i) //auto recognizes that the type is iterator, v.end is past the end element in the vector
    {
        cout << *i << endl;
    }
    
    cout << endl;
    
    for(auto i = v.rbegin(); i != v.rend(); ++i) //reversed - rend is befoe the first element. we can't mix auto with reversred and oridnary iterators (say change the rend to end in this loop), it can only be of one type.
    {
        cout << *i << endl;
    }
    
    int j = v[2]; //we can also use it as array using vector overload capabilites
    
    cout << "\nv[2]: " << j << endl;
    
    Person p1 ("iter1", "---", 23);
    p1.addResource();
    
    Person p2("iter2", "---", 24);
    vector<Person> vp;
    vp.push_back(p1); //push_back takes const reference to avoid extra copy
    vp.push_back(p2); //When calling push_back with p2, vector is reallocating its storage, so it is basically allocating a new array, copying over the current contents (thus the call to the copy ctor of p1), storing the new value at the end and releasing the old storage array (thus the destructor invocations for the contents - dtor of p1). This could be by preallocting the size of the vector so that it would fit new elements or by passing pointer/shared pointers where extra copies aren't needed.
  // shared_ptr<Person> sp;
    //sp = std::make_shared<Person>("shared ptr ");
    //cout << sp->getName() << endl;
    
    
    for(auto pi = vp.begin(); pi != vp.end(); ++pi)
    {
        cout << pi->getName() << endl;
        pi->setAge(28);
    }
    
    for_each(vp.begin(), vp.end(), printPerson);
    
    auto o = find_if(v.begin(), v.end(), isOdd); //look for the first element that is odd between beg to end. if none found, we won't enter the while, but if we found we, we keep looking for more odd numbers inside the loop, thus we use another find_if inside from the cur place till the end.
    
    while(o!=v.end())
    {
        cout << "num: " << *o << endl;
        o = find_if(++o, v.end(), isOdd);
    }
    
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), printInt);
    
    unsigned long length = p1.getName().size();
    cout << "p1 length: " <<length<< endl;
    cout << "p1 5 sub string " << p1.getName().substr(0,5) << endl; // print the sub string between 0 to 5 chars
    

}

void mapTest()
{
    Person ahmad("ahamd", "mahmud", 24);
    Person luie("luie", "ck", 43);
    
    map<int,Person> people;
    people[ahmad.getAge()] = ahmad;
    people[luie.getAge()] = luie;
    
    Person dot("dot", "kaee", 65);
    pair<int,Person> p (dot.getAge(), dot);
    
    people.insert(p); //the members are sorted by key in the map
    
    
    for(auto mi = people.begin(); mi!=people.end(); ++mi)
    {
        cout << "name: " <<mi->second.getName() << " age:  "<< mi->first << endl;
    }
    
    auto found = people.find(43);
    cout << "\nfound name:" << found->second.getName() <<endl;
    
    //alterntaive to using find is by using square brackets.
    string name = people[65].getName();
    
    cout << "array find: " << name << endl;
    
}

 

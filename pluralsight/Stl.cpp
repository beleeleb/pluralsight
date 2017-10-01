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
using namespace std;
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
    
}



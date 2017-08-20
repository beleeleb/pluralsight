//
//  collections.cpp
//  pluralsight
//
//  Created by gali zorea on 20/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "collections.hpp"
using namespace std;

void myvector()
{
    vector <int> vi;
    
    for(int i = 0; i< 10; ++i)
    {
        vi.push_back(i);
    }
    
    vi.push_back(static_cast<int>(4.5));
    
    for(auto item: vi)
    {
        cout << item << " ";
    }
    
    cout << endl;
    
    cout << " print 3 words:" << endl;
    vector <string> vs;
    for(int i = 0; i < 3; ++i)
    {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    
    
    for(auto item: vs)
    {
        cout << item << " ";
    }
    
    cout << endl << "sizeof vs:" << vs.size()<<endl;
    vs[2] = "zzzz";
    
    //3 ways to print vector's content
    
    for(auto item: vs)
    {
        cout << item << " ";
    }
    
    for(unsigned int i = 0; i< vs.size(); ++i) //i should be uint since size returns such
    {
        cout << vs[i] << " ";
    }
    
    cout << endl;
    
    for(auto i = begin(vi); i!=end(vi); i++)
    {
        cout << *i << " ";
    }
    
    cout << endl;

    sort(begin(vs), end(vs));
    for(auto item: vs)
    {
        cout << item << " ";
    }
    
    cout << "num of ints: " << count (begin(vi), end(vi), 3)<<endl;
    cout << "num of t: " << count (begin(vs[0]), end(vs[1]), 't')<<endl;

}

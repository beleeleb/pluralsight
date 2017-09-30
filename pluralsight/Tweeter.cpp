//
//  Tweeter.cpp
//  pluralsight
//
//  Created by gali zorea on 13/08/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "Tweeter.hpp"
#include <iostream>

using namespace std;
Tweeter::Tweeter(std::string o_firstName, std::string o_lastName, int o_age, std::string o_tweethandle):Person(o_firstName, o_lastName, o_age), tweeterhandle(o_tweethandle)
{
    cout << "construct tweeter: " << tweeterhandle << endl;
}

Tweeter::~Tweeter()
{
    cout << "destruct tweeter: " << tweeterhandle << endl;
}

std::string Tweeter::getName() const
{
    return Person::getName() + " tweet: @" + tweeterhandle;
}

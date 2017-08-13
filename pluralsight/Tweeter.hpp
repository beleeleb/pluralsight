//
//  Tweeter.hpp
//  pluralsight
//
//  Created by gali zorea on 13/08/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef Tweeter_hpp
#define Tweeter_hpp

#include <stdio.h>
#include "Person.hpp"
#include <string>
class Tweeter: public Person
{
private:
    std::string tweeterhandle;
public:
    Tweeter(std::string o_firstName, std::string o_lastName, int o_age, std::string o_tweethandle);
    ~Tweeter();
};
#endif /* Tweeter_hpp */

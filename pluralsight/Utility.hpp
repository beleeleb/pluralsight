//
//  Utility.hpp
//  pluralsight
//
//  Created by gali zorea on 25/12/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef Utility_hpp
#define Utility_hpp

#include <stdio.h>
class Utility{
public:
    Utility(int a):x(a){}
    int tripler() {return x*3;}
    int doubler() {return x*2;}
private:
    int x;
};
#endif /* Utility_hpp */

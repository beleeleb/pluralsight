//
//  transaction.hpp
//  pluralsight
//
//  Created by gali zorea on 22/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef transaction_hpp
#define transaction_hpp

#include <stdio.h>
#include <string>
class transaction
{
private:
    std::string m_action;
    double m_amount;
public:
    void newAction(std::string action, double amount, double balance);
    std::string report();
};
#endif /* transaction_hpp */

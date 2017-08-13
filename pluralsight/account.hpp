//
//  account.hpp
//  pluralsight
//
//  Created by gali zorea on 22/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef account_hpp
#define account_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include "transaction.hpp"
class account
{
private:

    double m_amount;
    std::vector<transaction> m_transactions;
public:
    bool withdraw(double value);
    bool deposit(double value);
    std::vector <std::string>  report() const;
    account(double init_amount);

};




#endif /* account_hpp */

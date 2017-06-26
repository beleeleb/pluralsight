//
//  transaction.cpp
//  pluralsight
//
//  Created by gali zorea on 22/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "transaction.hpp"
using namespace std;
void transaction::newAction(string action, double amount, double balance)
{
    m_action = action;
    m_amount = amount;
    
    m_action += ": ";
    m_action += to_string(m_amount);
    
    m_action += ", balance: ";
    m_action += to_string(balance);
    

}

string transaction::report()
{

    return m_action;
}

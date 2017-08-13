//
//  account.cpp
//  pluralsight
//
//  Created by gali zorea on 22/06/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#include "account.hpp"
using namespace std;
bool account::withdraw(double value)
{
    if(value > 0 && value < m_amount)
    {
        m_amount -= value;
        transaction withdraw;
        withdraw.newAction("withdraw", value, m_amount);
        m_transactions.push_back(withdraw);
        return true;
    }

    return false;
}

account::account(double init_amount): m_amount(init_amount)
{
}
    

bool account::deposit(double value)
{
    if(value > 0)
    {
        m_amount += value;
        transaction deposit;
        deposit.newAction("deposit", value, m_amount);
        m_transactions.push_back(deposit);
        return true;
    }
    
    return false;
}

vector <string> account::report() const
{
    vector <string> report;
    
    for(auto item: m_transactions)
    {
        string addBalance = item.report();

        report.push_back(addBalance);
        
    }
    
    return report;
}

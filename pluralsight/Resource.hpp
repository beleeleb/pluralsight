//
//  Resource.hpp
//  pluralsight
//
//  Created by gali zorea on 17/09/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef Resource_hpp
#define Resource_hpp
#include <string>

class Resource{
private:
    std::string m_name;
public:
    Resource(std::string o_name);
    ~Resource();
    std::string getName() const {return m_name;}; //const since it doesn't change the member
};
#endif /* Resource_hpp */

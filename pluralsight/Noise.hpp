//
//  Noise.hpp
//  pluralsight
//
//  Created by gali zorea on 28/10/2017.
//  Copyright © 2017 gali zorea. All rights reserved.
//

#ifndef Noise_hpp
#define Noise_hpp
#include <string>
#include <iostream>
class Noise
{
private:
    std::string m_noise;
    
public:
    Noise(std::string o_incomingNoise): m_noise(o_incomingNoise){
        std::cout << "ctor noise: " << m_noise << std::endl;
    };
    ~Noise()
    {
        std::cout << "dtor noise: " << m_noise << std::endl;

    };
};
#include <stdio.h>

#endif /* Noise_hpp */

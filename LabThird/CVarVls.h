//
//  CVarVls.h
//  LabThird
//
//  Created by Александр on 13.11.17.
//  Copyright © 2017 hilton. All rights reserved.
//

#ifndef CVarVls_h
#define CVarVls_h
#include <iostream>

class CVarVls {
public:
    double getValue();
    void setValue(double tempValue);
    std::string getName();
    void setName(std::string tempName);
    private:
    double value;
    std::string name;
    
    
    
};

#endif /* CVarVls_h */

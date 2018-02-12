//
//  Interface.h
//  LabThird
//
//  Created by Александр on 15.11.17.
//  Copyright © 2017 hilton. All rights reserved.
//

#ifndef Interface_h
#define Interface_h
#include "ValuesInterface.h"
#include <iostream>
#include "CTree.h"
#include "CNode.h"
#include <string>

class Interface {
public:
    void start();
    
private:
    
    std::string *split(std::string str, char separator, int *length);
    
    void push(std::string *&array, int length, std::string newWord);
    
    void printHelp();
    
};



#endif /* Interface_h */

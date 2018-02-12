//
//  CNode.h
//  LabThird
//
//  Created by Александр on 09.11.17.
//  Copyright © 2017 hilton. All rights reserved.
//

#ifndef CNode_h
#define CNode_h

#define  IDENTITY_TYPE_CONST 1
#define  IDENTITY_TYPE_VAR 2
#define  IDENTITY_TYPE_OPER 3

#include <vector>
#include <iostream>
#include <string>
#include "Values.h"
#include "CVarVls.h"
#include <stdio.h>
#include <math.h>



class CNode {
private:
    
    std::string name2;
    int nodeType;
    double constant;
    double variable;
    std::string name;
    
    int operation;
    
public:
   std::vector<CNode *> children;
    ~CNode();
    CNode (const CNode& obj);
    void print();
    std::string toString();
    std::string getName();
    void setName(std::string string);
    CNode();
    std::string toString2();
    CNode(int identity);
    double result(std::vector<CVarVls> *tempVector);
    std::string printInterface();
    std::string toStringInterface();
    void getVariable(std::vector<std::string> *tempVector);
    int readFromFormula(std::vector<std::string> *tempVector, int *offset);
    int getNodeType();
    void makeMeRandom(int *counterLevels, int *counterVariables);
    
    int random(int min, int max); //range : [min, max)
   
    
    int getNumberOfNodes();
   

    
    void addToList(std::vector<CNode*>* list);
    
    
    
 

};

#endif /* CNode_h */

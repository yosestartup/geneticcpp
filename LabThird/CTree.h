//
//  CTree.h
//  LabThird
//
//  Created by Александр on 09.11.17.
//  Copyright © 2017 hilton. All rights reserved.
//

#ifndef CTree_h
#define CTree_h
#include "CNode.h"
#include <algorithm>
#include <sstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>


class CTree {

private:
 std::string vectorCode;
  

    CNode *root;
public:
    int rando(int min, int max);
    ~CTree();
    CNode getRoot();
    int treeFromStringWithout(std::string formula);
    void setRoot (CNode &tempRoot);
    std::string getVectorCode();
    void setVectorCode(std::string tempVectorCode);
    std::vector<std::string> stringer (std::string s);
    void operator= (CTree &tree);
    CTree operator+ (CTree &tree);
    CTree(CNode *rootNode);
    CTree();
    CTree (const CTree& obj);
      int treeFromString(std::string formula);
    bool mutated = false;
    
//    CNode* getRandomNode()
//    {
////        std::vector<CNode*> nodes_vec;
////
////        root->addToList(&nodes_vec);
////
////        int tempRand = rando(0, nodes_vec.size());
////        return nodes_vec.at(tempRand);
////    
//    }
    int getNumberOfNodes();
    void mutation();
    
    void krzyzowanie (CTree *tempTree);
    void mutateinside();
        
    
    void generateRandom();
};

#endif /* CTree_h */

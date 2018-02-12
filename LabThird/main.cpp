//
//  main.cpp
//  LabThird
//
//  Created by Александр on 09.11.17.
//  Copyright © 2017 hilton. All rights reserved.
//

#include <iostream>
#include "CNode.h"
#include "CTree.h"
#include "Values.h"
#include <sstream>
#include <vector>
#include <string>
#include "Interface.h"
#include "Genetics.h"
#include <fstream>
#include <algorithm>
#include <iterator>

std::vector<std::string> stringer (std::string s)
{
    //std::string s = "This is a string.";
    
    std::vector<std::string> array;
    std::stringstream ss(s);
    std::string tmp;
    while(std::getline(ss, tmp, ' '))
    {
        array.push_back(tmp);
    }
    
    return array;
  
    
}



int random(int min, int max) //range : [min, max)
{
    static bool first = true;
    if ( first )
    {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (max+1 - min);
}



int main(int argc, const char * argv[]) {

   
    Genetics *const2 = new Genetics();
     const2->initialize(startPopulation);
     const2->readFromFile();
     std::ofstream file;
     file.open(resultsPATH);
     for(int h = 0; h<const2->data.size(); h++)
          {
              const2->writeVarsAndWynik(const2->data.at(h));
              int i = numOfIterations;
              do{
                      const2->selection();
                      const2->krzyzownik(crossingProbability);
                      const2->mutation(mutationProbability);
                       i--;
                  
                   } while (i<lowerBorder);
      std::vector<int> finalers;
      for (int i=0; i<const2->population.size(); i++) {
          
        int tempRes = 0;
        tempRes = const2->population.at(i)->getRoot().result(&const2->vars);
        finalers.push_back(tempRes);
          
    }

    auto ii = min_element(begin(finalers), end(finalers), [=] (int x, int y)
                         {
                             return abs(x - const2->wynik) < abs(y - const2->wynik);
                         });
    
    double tem = std::distance(begin(finalers), ii); // Prints 2
    
    const2->finalTree = const2->population.at(tem);


    std::cout << const2->finalTree->getRoot().result(&const2->vars);
    std::cout << std::endl << printBoarder << std::endl;
    std::cout <<const2->finalTree->getRoot().toStringInterface();
    std::cout << std::endl << std::endl <<  std::endl;
     file << const2->finalTree->getRoot().toStringInterface() << std::endl;
              
     }
    
    file.close();

    
}

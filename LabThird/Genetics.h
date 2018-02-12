//
//  Genetics.h
//  LabThird
//
//  Created by Александр on 07.12.17.
//  Copyright © 2017 hilton. All rights reserved.
//

#ifndef Genetics_h
#define Genetics_h
#include "CTree.h"
class Genetics {

public:
    CTree *finalTree = new CTree;
    std::vector<CTree*> population;
    void initialize(int numberOfPopulation);
    std::vector<std::vector<double>> data;
    void readFromFile();
    std::vector <CVarVls> vars;
    void writeVarsAndWynik(std::vector<double> dataTemp);
    double wynik;
    void selection ();
    int numberOfLinies = 0;
    void krzyzownik (int szansa);
    std::vector<CTree*> tempParents;
    void mutation(int szansa);
    std::vector<CTree*> potomak;
    bool flag = false;
    ~Genetics();
};
#endif /* Genetics_h */

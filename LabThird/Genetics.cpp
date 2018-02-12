#include "Genetics.h"
#include <fstream>
#include <sstream>
int rando(int min, int max) //range : [min, max)
{
    static bool first = true;
    if ( first )
    {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (max+1 - min);
}
void Genetics::readFromFile()
{
    std::ifstream input(datatxtPATHH);
    std::string linebuffer;
  
    while( std::getline( input, linebuffer ) ) {
        numberOfLinies=numberOfLinies+1;
      //  std::cout<<linebuffer<<'\n';
    
  
        if (linebuffer.length() == 0)continue;
        std::vector<double> tempVector;
        std::string tempString;
        
        for(char& stringCharacter : linebuffer) {
            
           
            if(stringCharacter != FINISH)
            {
                tempString.push_back(stringCharacter);

            }
            else
            {
                
               // tempString.erase(tempString.begin());
                std::stringstream ss;
                ss << tempString;
                float tempFloat = 0;
                ss >> tempFloat;
                
                tempVector.push_back(tempFloat);
                tempString = nothing;
                
            }
            

        }

 data.push_back(tempVector);
        tempVector.clear();
    
    
    }
    
    
    
}


void Genetics::initialize(int numberOfPopulation)
{
    population.clear();
    for (int i = 0; i<numberOfPopulation; i++)
    {
        int n = 0;
        int b = 0;
        CTree *tree = new CTree();
        CNode *node = new CNode();
        node->makeMeRandom(&n, &b);
        tree->setRoot(*node);
        population.push_back(tree);
       // node->print();
        std::cout << std::endl;
    }
    
}
void Genetics::writeVarsAndWynik(std::vector<double> dataTemp)
{
   vars.clear();
   wynik = 0;
        CVarVls val1;
        val1.setName(x);
        val1.setValue(dataTemp.at(0));
        CVarVls val2;
        val2.setName(y);
        val2.setValue(dataTemp.at(1));
        vars.push_back(val1);
        vars.push_back(val2);
    wynik = dataTemp.at(2);
    
}








void Genetics::selection()

{
    tempParents.clear();
   if (population.size() == 1)
   {
       flag = true;
   }
   
    for (int i = 0; i < population.size(); i++)
    {
        int tempRandom1 = 0 + rand() % population.size();

    
        
        int formula1 = (wynik - population.at(tempRandom1)->getRoot().result(&vars))* (wynik - population.at(tempRandom1)->getRoot().result(&vars));
        
        
        
       int tempRandom2 = 0 + rand() % population.size();

        int formula2 = (wynik - population.at(tempRandom2)->getRoot().result(&vars))* (wynik - population.at(tempRandom2)->getRoot().result(&vars));
        
        
        if(formula1<formula2)
        {
            tempParents.push_back(population.at(tempRandom1));
        }
        else
        {
             tempParents.push_back(population.at(tempRandom2));
        }
        
    }
    
}
Genetics::~Genetics() {
 
    delete  finalTree;
    for(int i = 0; i<population.size(); i++)
    {
        delete population[i];
    }
    for(int i = 0; i<tempParents.size(); i++)
    
    {
        delete tempParents[i];
    }
    
    for(int i = 0; i<potomak.size(); i++)
    {
        delete potomak[i];
    }
 
    
}
  void Genetics::krzyzownik (int szansa)
{
     std::vector<std::vector<CTree*>> pary;
    potomak.clear();
 if(tempParents.size() % 2)
    {
    for (int i = 0; i<tempParents.size()/2; i++)
    {
       
       
    
        int tempRand = rando(0,szansa);
        if (tempRand == 0)
        {
            tempParents[i]->krzyzowanie(tempParents[i+1]);
            potomak.push_back(tempParents[i]);
            potomak.push_back(tempParents[i+1]);
        }
        else
        {
        potomak.push_back(tempParents[i]);
        potomak.push_back(tempParents[i+1]);
        }
        
    }
    }
    else
    {
        tempParents.pop_back();
        for (int i = 0; i<tempParents.size(); i+=2)
        {
            
            
            
            int tempRand = rando(0,szansa);
            if (tempRand == 0)
            {
                tempParents[i]->krzyzowanie(tempParents[i+1]);
                potomak.push_back(tempParents[i]);
                potomak.push_back(tempParents[i+1]);
            }
            else
            {
                potomak.push_back(tempParents[i]);
                potomak.push_back(tempParents[i+1]);
            }
            
        }

    }
}

void Genetics::mutation(int szansa)
{
    for(int i=0; i<potomak.size(); i++)
    {
        int tempRand = rando(0,szansa);
        if (tempRand == 0)
        {
          
            if(potomak[i]->mutated==false)
            {
                potomak[i]->mutation();
                
                potomak[i]->mutated = true;
                  int tempRand = rando(0,5);
                if(tempRand == 0)
                {
                            potomak[i]->mutated = false;
                }
                
            }
            else
            {
            
            }
        }
        else
        {
            
        }
        
    }

    population=potomak;
    
}






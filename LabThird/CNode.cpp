#include "CNode.h"
#include <iostream>
#include "Values.h"
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

CNode::~CNode() {
    for (int i = 0; i<children.size(); i++)
    {
        delete children[i];
    }
}
void CNode::addToList(std::vector<CNode*>* list)
{
    
    list->push_back(this);
    
    for(int i = 0; i<this->children.size(); i++)
    {
        this->children.at(i)->addToList(list);
    }
    
}
int CNode::getNumberOfNodes() {
    int res = 1;
    for (int i = 0; i < children.size(); ++i) {
        res += children[i]->getNumberOfNodes();
    }
    return res;
}

int CNode::random(int min, int max) //range : [min, max)
{
    static bool first = true;
    if ( first )
    {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (max+1 - min);
}
void CNode::makeMeRandom(int *counterLevels, int *counterVariables)

{
    
    if (*counterLevels<=3)                            //Operacji - OK
    {
        if(*counterVariables<2)                       //Zmienne - OK
        {
            int randomIntType = random(1, 3); //Zmienna albo operacja albo constanta
            nodeType = randomIntType;
        }
        else if (*counterVariables>2)               //Zmienne - NIE
        {
            int randomIntType = (rand() > RAND_MAX/2) ? 1 : 3;  //Operacja albo constanta
            nodeType = randomIntType;
        }
    }
    else if (*counterLevels>=3)                                                        //Operacji NIE
    {
        if(*counterVariables<2)                      //Zmienne - OK
        {
            int randomIntType = (rand() > RAND_MAX/2) ? 1 : 2;  //Constanta albo zmienna
            nodeType = randomIntType;
        }
        else if (*counterVariables>2)               //Zmienne - NIE
        {
            nodeType = IDENTITY_TYPE_CONST;   //Constanta
        }
        
    }
    
    
    if(nodeType == IDENTITY_TYPE_CONST)
    {
        constant = (random(0, 9));
    }
    else if(nodeType == IDENTITY_TYPE_OPER)
    {
        int i_child_count = 0;
        *counterLevels = *counterLevels+1;
        operation = (random(1, 6));
        
        if (operation == 1 || operation == 2 || operation == 3 || operation == 4)
        {
            
            i_child_count = 2;
            //Two random children
            
        }
        else if (operation == 5 || operation == 6)
        {
            i_child_count = 1;
            //One random children
        }
        
        CNode  *child;
        
        for  (int ii = 0; ii < i_child_count; ii++)
        {
            
            child = new CNode();
            child->makeMeRandom(counterLevels, counterVariables);
            children.push_back(child);
        }
        
    }
    else if (nodeType == IDENTITY_TYPE_VAR)
    {
        *counterVariables = *counterVariables + 1;
        if(*counterVariables == 0)
            
        {
            setName("x");
        }
        else
        {
            setName("y");
        }
        
    }
    else
    {
        nodeType = IDENTITY_TYPE_CONST;
        constant = (random(0, 9));
    }
    
    
    
}

CNode::CNode(const CNode& obj) {
    
        nodeType = obj.nodeType;
        constant = obj.constant;
        variable = obj.variable;
        operation = obj.operation;
        name = obj.name;
        name2 = obj.name2;
    
        for (int i = 0; i<obj.children.size(); i++)
        {
            CNode *node = new CNode(*obj.children[i]);
            children.push_back(node);
        }
    }

void CNode::print()
{
    if (nodeType == IDENTITY_TYPE_CONST)
    {
        std::cout << toString() << std::endl;
    }
    else if (nodeType == IDENTITY_TYPE_VAR)
    {
        std::cout << toString() << std::endl;
    }
    else if (nodeType == IDENTITY_TYPE_OPER)
    {
        std::cout << toString(); //toString();
        std::cout << brToLeft;
        for (int i = 0; i<children.size(); i++)
        {
            std::cout << children[i]->toString() ;
            std::cout << coma;
        }
        std::cout << brToRight << std::endl;
        for (int i = 0; i<children.size(); i++)
        {
            children[i]->print();
        }
    }
}

std::string CNode::toString()
{
    
    if (nodeType == IDENTITY_TYPE_CONST)
    {
        return std::to_string(constant);
    }
    else if (nodeType == IDENTITY_TYPE_VAR)
    {
        return name;
    }
    else if (nodeType == IDENTITY_TYPE_OPER)
    {
        switch (operation)
        {
            case (plus):
        {
                return wordPlus;
            
        }
            case (minus):
        {
                return wordMinus;
            
        }
            case (multiply):
        {
            return wordMultiply;
            
        }
            case (division):
        {
                return wordDivide;
            
        }
            case (sinus):
        {
                return  wordSin;
            
        }
            case (cosinus):
        {
                return wordCos;
            
        }
                
            default:
        {
            return nothing;
        }
            
             
        }
    
        
    }
    
    else
    {
        return nothing;
    }
    
}
std::string CNode::toString2()
{
    std::string string;
    if (nodeType == IDENTITY_TYPE_CONST)
    {
        string+=std::to_string(constant);
        string+=space;
    }
    else if (nodeType == IDENTITY_TYPE_VAR)
    {
        string+=name;
        string+=space;
    }
    else if (nodeType == IDENTITY_TYPE_OPER)
    {
        switch (operation)
        {
            case (plus):
            {
                string+=symbPlus;
                string+=space;
                
            }
            case (minus):
            {
                string+=symbMinus;
                string+=space;
                
            }
            case (multiply):
            {
                string+=symbMultiply;
                string+=space;
                
            }
            case (division):
            {
                string+=symbDivide;
                string+=space;
                
            }
            case (sinus):
            {
                string+=symbSin;
                string+=space;
                
            }
            case (cosinus):
            {
                string+=symbCos;
                string+=space;
                
            }
                
            default:
            {
               string+=nothing;
            }
                
                
        }
        
        
    }
    
    else
    {
        return nothing;
    }
    
    return string;
}
std::string CNode::getName()
{
    return name;
}

void CNode::setName(std::string string)
{
    name = string;
}

CNode::CNode()
{
    
}

CNode::CNode(int identity)
{
    if (identity == IDENTITY_TYPE_CONST)
    {
        constant = 0;
        nodeType = identity;
    }
    else if (identity ==  IDENTITY_TYPE_VAR)
    {
        variable = 0;
        nodeType = identity;
        
    }
    else if (identity == IDENTITY_TYPE_OPER)
    {
        operation = 0;
        nodeType = identity;
    }
}

double CNode::result(std::vector<CVarVls> *tempVector)
{
    
    if (nodeType == IDENTITY_TYPE_VAR)
    {
        //std::cout << getName();
        double temp = 0;
        for(int i = 0; i<tempVector->size(); i++)
        {
            //std::cout << node.getName();
            if(getName() == tempVector->at(i).getName())
            {
                temp = tempVector->at(i).getValue();
            }
        }
        return temp;
        
    }
    
    if(nodeType == IDENTITY_TYPE_CONST)
    {
        return constant;
    }
    else if (nodeType == IDENTITY_TYPE_OPER)
    {
        double tempResult = 0;
        bool isFirst = true;
        for (int i = 0; i<children.size(); i++)
        {
            if(operation == minus)
            {
                if(isFirst == true)
                {
                    tempResult += children[i]->result(tempVector);
                    isFirst = false;
                }
                else
                {
                    tempResult -= children[i]->result(tempVector);
                }
            }
            
            else if (operation == plus)
            {
                tempResult += children[i]->result(tempVector);
            }
            
            else if (operation == superplus)
            {
                tempResult += children[i]->result(tempVector);
            }
            
            else if (operation == multiply)
            {
                if(isFirst == true)
                {
                    tempResult += children[i]->result(tempVector);
                    isFirst = false;
                }
                else
                {
                    tempResult *= children[i]->result(tempVector);
                }
            }
            
            else if (operation == division)
            {
                if(isFirst == true)
                {
                    tempResult += children[i]->result(tempVector);
                    isFirst = false;
                }
                else
                {
                    if(children[i]->result(tempVector) == 0)
                    {
                        
                    }
                    else
                    {
                    tempResult /= children[i]->result(tempVector);
                    }
                }
            }
            
            else if (operation == sinus)
            {
                tempResult =   (double)sin(children[i]->constant);
            }
            
            else  if (operation == cosinus)
            {
                tempResult = (double)cos(children[i]->constant);
            }
            
            
            
            
        }
        return tempResult;
    }
    
    
    return 1;
}


std::string CNode::toStringInterface()
{
    std::string string = nothing;
    if (nodeType == IDENTITY_TYPE_CONST)
    {
        string.append(std::to_string(constant));
    }
    else if (nodeType == IDENTITY_TYPE_VAR)
    {
        string.append(getName());
    }
    else if (nodeType == IDENTITY_TYPE_OPER)
    {
        if (operation == plus)
        {
            string.append(symbPlus);
            string.append(space);
        }
        else if (operation == minus)
        {
            string.append(symbMinus);
            string.append(space);
        }
        else if (operation == superplus)
        {
            string.append(symbSPlus);
            string.append(space);
        }
        else if (operation == multiply)
        {
            string.append(symbMultiply);
            string.append(space);
        }
        else if (operation == division)
        {
            string.append(symbDivide);
            string.append(space);
        }
        else if (operation == cosinus)
        {
            string.append(symbCos);
            string.append(space);
        }
        else if (operation == sinus)
        {
            string.append(symbSin);
            string.append(space);
        }
        
        for(int i = 0; i<children.size(); i++)
        {
            string.append(children[i]->toStringInterface());
            string.append(space);
            
        }
        
        
        
        
    }
    
    else
    {
        return nothing;
    }
    
    return string;
    
    
}


std::string CNode::printInterface()
{
    std::string string = nothing;
    
    if (nodeType == IDENTITY_TYPE_CONST)
    {
        string.append(toStringInterface());
        string.append(space);
    }
    else if (nodeType == IDENTITY_TYPE_VAR)
    {
        string.append(toStringInterface());
        string.append(space);
    }
    else if (nodeType == IDENTITY_TYPE_OPER)
    {
        
        
        
        string.append(toStringInterface());
        
        
        
        
    }
    string.erase(string.size() - 1);
    return string;
}
int CNode::getNodeType()
{
    return nodeType;
}
void CNode::getVariable(std::vector<std::string> *tempVector)
{
    if (nodeType == IDENTITY_TYPE_VAR)
    {
        bool b_am_i_there = false;
        
        for (int i = 0; i<tempVector->size(); i++)
        {
            if (tempVector->at(i) == name)
            {
                b_am_i_there = true;
            }
        }
        if(b_am_i_there != true)
        {
            tempVector->push_back(name);
        }
        
    }
    else
    {
        for (int i = 0; i<children.size(); i++)
        {
            children[i]->getVariable(tempVector);
            
        }
    }
}


int CNode::readFromFormula(std::vector<std::string> *tempVector, int *offset)
{
    int i_child_count = 0;
    if (*offset > tempVector->size())
    {
        nodeType = IDENTITY_TYPE_CONST;
        constant = 1;
        return -1;
    }
    else if (*offset == tempVector->size())
    {
        nodeType = IDENTITY_TYPE_CONST;
        constant = 1;
        return 1;
    }
    
    
    
    
    
    if (tempVector->at(*offset) == symbPlus)
    {
        nodeType = IDENTITY_TYPE_OPER;
        operation = plus;
        i_child_count = 2;
        
    }
    else if (tempVector->at(*offset) == symbSPlus)
    {
        nodeType = IDENTITY_TYPE_OPER;
        operation = superplus;
        i_child_count = 3;
    }
    else if (tempVector->at(*offset) == symbMinus)
    {
        nodeType = IDENTITY_TYPE_OPER;
        operation = minus;
        i_child_count = 2;
    }
    else if (tempVector->at(*offset) == symbMultiply)
    {
        nodeType = IDENTITY_TYPE_OPER;
        operation = multiply;
        i_child_count = 2;
        
        
    }
    else if (tempVector->at(*offset) == symbDivide)
    {
        nodeType = IDENTITY_TYPE_OPER;
        operation = division;
        i_child_count = 2;
    }
    
    else  if(is_number(tempVector->at(*offset)) == true)
    {
        nodeType = IDENTITY_TYPE_CONST;
        constant = std::stoi(tempVector->at(*offset));
        //return 1;
    }
    else if (tempVector->at(*offset) == symbSin)
    {
        nodeType = IDENTITY_TYPE_OPER;
        operation = sinus;
        i_child_count = 1;
    }
    else if (tempVector->at(*offset) == symbCos)
    {
        nodeType = IDENTITY_TYPE_OPER;
        operation = cosinus;
        i_child_count = 1;
    }
    else
    {
        nodeType = IDENTITY_TYPE_VAR;
        
        setName(tempVector->at(*offset));
        
        i_child_count =  0;
        
    }
    
    
    CNode  *child;
    
    for  (int ii = 0; ii < i_child_count; ii++)
    {
        child = new CNode();
        
        *offset = *offset + 1;
        
        
        child->readFromFormula(tempVector, offset);
        
        children.push_back(child);
    }
    
    return 0;
    
}







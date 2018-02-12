#include "CTree.h"
//random method

std::string CTree::getVectorCode()
{
    return vectorCode;
}
void CTree::setVectorCode(std::string tempVectorCode)
{
    vectorCode = tempVectorCode;
}

CNode CTree::getRoot()
{
    return *root;
}
void CTree::setRoot(CNode &tempRoot)
{
    root = &tempRoot;
}
int CTree::getNumberOfNodes() {
    return this->root->getNumberOfNodes();
}
int CTree::rando(int min, int max) //range : [min, max)
{
    static bool first = true;
    if ( first )
    {
        srand(time(NULL)); //seeding for the first time only!
        first = false;
    }
    return min + rand() % (max+1 - min);
}
std::vector<std::string> CTree::stringer (std::string s)
{
    
    std::vector<std::string> array;
    std::stringstream ss(s);
    std::string tmp;
    while(std::getline(ss, tmp, ' '))
    {
        array.push_back(tmp);
    }
    return array;
}

int CTree::treeFromString(std::string formula)
{
    int result = 0;
    vectorCode = formula;
    std::vector<std::string> vector = stringer(formula);
    if(root != NULL)
    {
        delete root;
    }
    int off = 0;
    root = new CNode();
    result = root->readFromFormula(&vector, &off);
  
    if(vector.size() > off+1)
    {
        result = 1;
    }
    else if(vector.size() == off)
    {
        result = -1;
    }
    return result;

}

int CTree::treeFromStringWithout(std::string formula)
{
     int result = 0;
    vectorCode = formula;
    std::vector<std::string> vector = stringer(formula);

    int off = 0;
    root = new CNode();
    result = root->readFromFormula(&vector, &off);
    if(vector.size() > off+1)
    {
        result = 1;
    }
    else if(vector.size() == off)
    {
        result = -1;
    }
    return result;
    
}



void CTree::operator= (CTree &tree)
{
    if  (root != NULL)  delete root;
    this->root = new CNode(*tree.root);
}

CTree CTree::operator+ (CTree &tree)
{
    CTree cresult(*this);
    cresult.vectorCode.erase( cresult.vectorCode.end()-1 );
    std::string newString(cresult.vectorCode + tree.vectorCode);
    cresult.treeFromString(newString);
    return cresult;
}

CTree::CTree(CNode *rootNode)
{
    root = rootNode;
}
void CTree::krzyzowanie (CTree *tempTree)
{
    
    if (tempTree->root->children.size() != 0 && this->root->children.size() != 0 ) {
             int secRand = rand() % tempTree->root->children.size();
        
        int firstRand = rand() % this->root->children.size();
   
        CNode *temp = this->root->children[firstRand];
        this->root->children[firstRand] = tempTree->root->children[secRand];
        tempTree->root->children[secRand] = temp;
    }
    
}

void CTree::mutateinside() {
    if(this->root->children.size() != 0)
    {
        if(this->root->children.size() == 2) //если операция
        {
            int n = 0;
            int b = 0;
            this->root->children[0]->makeMeRandom(&n, &b);
            
            int n1 = 0;
            int b2 = 0;
            
            this->root->children[1]->makeMeRandom(&n1, &b2);
            
        }
        
        else if (this->root->children.size() == 1)
        {
             if(this->root->children[0]->getNodeType() == IDENTITY_TYPE_OPER)
                  {
                   int n = 0;
                   int b = 0;
                   this->root->children[0]->children[0]->makeMeRandom(&n, &b);
                    int n1 = 0;
                    int b2 = 0;
                     this->root->children[0]->children[1]->makeMeRandom(&n1, &b2);
                      
                       }
             else if(this->root->children[0]->getNodeType() != IDENTITY_TYPE_OPER)
             {
                 int n = 0;
                 int b = 0;
                 this->root->children[0]->makeMeRandom(&n, &b);
             }
         }
        else
        {
            int n = 0;
            int b = 0;
            this->root->makeMeRandom(&n, &b);
    
        }
        

        
    }
}
void CTree::mutation() {
    
    
    
    if(this->root->children.size() != 0)
    {
        int n = 0;
        int b = 0;
        int indexThis = rand() % this->root->children.size();
        CNode *temp = this->root->children[indexThis];
        temp->makeMeRandom(&n, &b);
        root->children[indexThis] = temp;
        
    }
    else
    {
        int n = 0;
        int b = 0;
        this->root->makeMeRandom(&n, &b);
        
    }
}

CTree::~CTree()
{
    delete root;
}

CTree::CTree()
{
    
}
void CTree::generateRandom()
{


}



CTree::CTree (const CTree& obj)
{
    root = new CNode(*obj.root);
    vectorCode = obj.vectorCode;
    
}

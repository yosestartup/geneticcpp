#include "Interface.h"
#include <iterator>
#include <vector>
using namespace std;


void Interface::start() {
    std::string line;
     std::vector <CVarVls> varObj; //объекты варс
    std::vector <std::string> varName; //название стринг варс
    CTree *tree = new CTree();
    bool end = false;
    int commandsLength = 0;
    std::string *commandsArray;
    string command;
    printHelp();
    do {
        commandsLength = 0;
        getline(std::cin, line);
        commandsArray = split(line, ' ', &commandsLength);
        command = commandsArray[0];
        
        if (line == sEND) {
            end = true;
            
        } else if (line == sHELP) {
            printHelp();
            
        }else if (line == sPRINT_LEVELS) {
            tree->getRoot().print();
        } else if (line == sVARS) {
            std::vector<std::string> vector;
            tree->getRoot().getVariable(&vector);
            for (int i = 0; i<vector.size(); i++)
            {
                std::cout << vector[i];
            }
            
        } else if (command == sJOIN) {
            
            
            
            
            CTree *temporary = new CTree();
            std::string string;
            string.clear();
            for (int i = 1; i<commandsLength; i++)
            {
                string.append(commandsArray[i]);
                string.append(sSPA);
                std::cout << commandsArray[i] << endl;
            }
            string.pop_back();
            
            
            if(string.find_first_not_of(sONLY_AVAILABLE) != std::string::npos)
            {
                std::cout << sINVALID_WORD << std::endl;
            }
            else
            {
               
                int  i_result;
                i_result = temporary->treeFromStringWithout(string);
                CTree finalTree = *tree + *temporary;
                tree = new CTree(finalTree);
                std::string response;
                switch (i_result){
                    case -1: response = sREQUEST_RESPONSE_LITTLE;
                        break;
                    case 0: response = sREQUEST_RESPONSE_OK;
                        break;
                    case 1: response = sREQUEST_RESPONSE_MUCH;
                        break;
                    default:break;
                }
                std::cout << response << std::endl;
            }
            
     
        } else if (command == sEnter) {
     //      bool isInvalidWord = false;
            //tree.treeFromString(*commandsArray);
           
//
            std::string string;
            for (int i = 1; i<commandsLength; i++)
            {
                string.append(commandsArray[i]);
                string.append(sSPA);

            }
            string.pop_back();
            if(string.find_first_not_of(sONLY_AVAILABLE) != std::string::npos)
            {
               
               
                    std::cout << sINVALID_WORD << std::endl;
                
                
            }
            else
            {
            tree->setVectorCode(string);
                
                int  i_result;
           i_result = tree->treeFromString(string);
            std::string response;
                switch (i_result){
                case -1: response = sREQUEST_RESPONSE_LITTLE;
                    break;
                case 0: response = sREQUEST_RESPONSE_OK;
                    break;
                case 1: response = sREQUEST_RESPONSE_MUCH;
                    break;
                default:break;
            }
            std::cout << response << std::endl;
            }
        } else if (line == sPRINT) {
           
        
            std::string array;
            array = tree->getRoot().printInterface();
            std::cout << array;
            
        } else if (command == sCOMP) {
            
            varName.clear();
            varObj.clear();
            tree->getRoot().getVariable(&varName);
            
            std::string string;
            for (int i = 1; i<commandsLength; i++)
            {
                string.append(commandsArray[i]);
            }
            
            
          if(string.find_first_not_of(sONLY_AVAILABLE_VAR) != std::string::npos)
            {
                std::cout << sINVALID_WORD << std::endl;
            }
            else if(string.size()> varName.size())
            {
                std::cout <<  sA_LOT;
            }
            else if (string.size() < varName.size())
            {
                std::cout << sLITTLE;
            }
            else
            {
                
                varName.clear();
                varObj.clear();
                tree->getRoot().getVariable(&varName);
                for (int i = 1; i<commandsLength; i++)
                {
                    CVarVls variableObject;
                    variableObject.setName(varName[i-1]);
                    variableObject.setValue(std::stoi(commandsArray[i]));
                    varObj.push_back(variableObject);
                    
                }
                std::cout << tree->getRoot().result(&varObj);
            }
            

        } else if (line == sEXIT){
            end = true;
        }
    } while (!end);
}

std::string *Interface::split(string str, char separator, int *length) {
    string *arrayOfWords;
    arrayOfWords = new string[1];
    string word;
    
    for (int i = 0; i <= str.length(); i++) {
        if ((i == str.length() || str[i] == separator) && word.length() > 0) {
            push(arrayOfWords, *length, word);
            (*length)++;
            word = sNOTHING;
        } else if (str[i] != separator) {
            word += str[i];
        }
    }
    return arrayOfWords;
}

void Interface::push(string *&array, int length, string newWord) {
    string *newArray;
    newArray = new string[length + 1];
    
    for (int i = 0; i < length; i++) {
        newArray[i] = array[i];
    }
    
    newArray[length] = move(newWord);
    delete[] array;
    array = newArray;
}

void Interface::printHelp() {
    std::cout << HELP_TO_PRINT << std::endl;
}


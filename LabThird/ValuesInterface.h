//
//  ValuesInterface.h
//  LabThird
//
//  Created by Александр on 15.11.17.
//  Copyright © 2017 hilton. All rights reserved.
//

#ifndef ValuesInterface_h
#define ValuesInterface_h
#include <string>

const std::string sEND = "end";
const std::string sHELP = "help";
const std::string sEnter = "enter";
const std::string sPRINT = "print";
const std::string sCOMP = "comp";
const std::string sEXIT = "exit";
const std::string sVARS = "vars";
const std::string sJOIN = "join";
const std::string sVARS_PREP3 = " int arguments.";
const std::string sVARS_PREP2 = "You entered wrong number of arguments. There should be ";
const std::string sVARS_PREP = "Variables: ";
const std::string sREQUEST_RESPONSE_LITTLE = "Too little arguments. Trying to fix it by filling in empty spaces with value \"1\".";
const std::string sREQUEST_RESPONSE_OK = "The expression is OK. Tree is ready.";
const std::string sREQUEST_RESPONSE_MUCH = "You entered too much arguments. Unnecessary expressions will be skipped.";
const std::string sTHIS_IS_YOUR_EXPRESSION = "Processed expression is: ";
const std::string sEXP_RESULT = "Result of expression is = ";
const std::string sINVALID_WORD = "You entered word that contains not allowed chars. This word will be skipped.";

const std::string  HELP_TO_PRINT =
"List of possible commands and it's parameters:\nenter <prefix expression> - request an expression\nprint - show prefix expression\nvars - show variables\ncomp <val0> <val1> ... <valn-1> - request to calculate an expression replacing each variable by corresponding values\nhelp - show list of commands\njoin <prefix expression> - join an expression to existing expression\nexit - shout down program\n";

const std::string sSPA = " ";
const std::string sNOTHING = "";
const std::string sPRINT_LEVELS = "print_levels";
const std::string sONLY_AVAILABLE = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890_+ */-";
const std::string sONLY_AVAILABLE_VAR = "01234567890 ";
const std::string sA_LOT = "OH. A LOt of arguments. try again";
const std::string sLITTLE = "HAHA. give me more arguments, dude";

#endif /* ValuesInterface_h */

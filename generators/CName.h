//
// Author: Belov Vladislav
//

#ifndef _C_NAME_H_
#define _C_NAME_H_

#include "QObject"

#define CHAR_TYPE wchar_t
#define STRING_TYPE QString

#include "CNumber.h"

class CName : QObject
{
    Q_OBJECT
public:
    CName(double seed = 0);
    STRING_TYPE NextName();
private:
    //int minLength;
    //int maxLength;
    //static const double first[26];
    //static const double next[26][26];
    int getFirstSymbol();
    int getNextSymbol(int prev);
    CNumber gen;
};

#endif // _C_NAME_H_

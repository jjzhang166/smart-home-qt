#ifndef GLOBALVAL_H
#define GLOBALVAL_H

#include <QString>

#define DEBUG_ON

class GlobalVal
{
public:
    GlobalVal();
    static QString ip;
    static QString port;
};

#endif // GLOBALVAL_H

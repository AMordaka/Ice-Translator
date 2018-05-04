#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <Ice/Ice.h>
#include <Printer.h>

using namespace std;
using namespace Demo;

class TranslatorI : public Translator
{
public:
    virtual words translate(const string& s, const Ice::Current&);
    virtual void test(const Ice::Current&);
};

#endif 
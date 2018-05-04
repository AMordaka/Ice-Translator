#include "Translator.h"
#include <Ice/Ice.h>
#include <Printer.h>

myDictionary dictionary;

words TranslatorI::translate(const string& s, const Ice::Current&)
{
    words rewords = dictionary[s];
    if(rewords.size() == 0){
        throw NoSuchWord();
    }
    return rewords;
}

void TranslatorI::test(const Ice::Current&){
    words lulz;
    lulz.push_back("hello");
    lulz.push_back("hey");
    dictionary["hej"] = lulz;
}
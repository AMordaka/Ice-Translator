#include <Ice/Ice.h>
#include <Printer.h>
#include "Translator.h"

using namespace std;
using namespace Demo;







int main(int argc, char* argv[])
{
    try
    {
        Ice::CommunicatorHolder ich(argc, argv);
        Ice::ObjectAdapterPtr adapter =
            ich->createObjectAdapterWithEndpoints("SimplePrinterAdapter", "default -p 10000");
        Ice::ObjectPtr object = new TranslatorI;
        adapter->add(object, ich->stringToIdentity("SimplePrinter"));
        adapter->activate();
        ich->waitForShutdown();
    } 
    catch(const std::exception& e)
    {
        cerr << e.what() << endl;
        return 1;
    }
    return 0;
}

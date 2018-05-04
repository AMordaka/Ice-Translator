#include <Ice/Ice.h>
#include <Printer.h>

using namespace std;
using namespace Demo;

int
main(int argc, char* argv[])
{
    try
    {
        Ice::CommunicatorHolder ich(argc, argv);
        Ice::ObjectPrx base = ich->stringToProxy("SimplePrinter:default -p 10000");
        TranslatorPrx printer = TranslatorPrx::checkedCast(base);
        if(!printer)
        {
            throw "Invalid proxy";
        }
        string s;
        printer->test();
        while(1){
            try{
                cout << "Podaj slowo";
                cin >> s;
                words lulz = printer->translate(s);
                vector<string>::iterator it;
                for(it = lulz.begin(); it != lulz.end(); it++){
                    cout << *it << endl;
                }
            }
            catch (NoSuchWord e){
                    cerr << e << endl;
            }
        }
        
    } 
    catch(const std::exception& ex)
    {
        cerr << ex.what() << endl;
        return 1;
    }
    return 0;
}

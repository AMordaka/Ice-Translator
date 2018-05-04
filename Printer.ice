module Demo
{
    exception NoSuchWord{};
    
    sequence<string> words;
    dictionary<string,words> myDictionary;

    interface Translator
    {
        words translate(string s) throws NoSuchWord;
        void test();
    }
}

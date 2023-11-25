#include <string>

using std::string;
    
class stack
{
    public:
    stack(int c);
    void push(int elem);
    void pop();
    bool overflowing();
    bool underflowing();
    void printstack();
    string checkifnumber(string ch);
    void endprogram();
    ~stack();

    private:
    int *data = NULL;
    int capacity;
    int top;
};
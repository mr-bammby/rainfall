#include <iostream>
#include <cstring>
#include <unistd.h>

class N
{
private:
    // vtable pointer is implicitly at offset 0x00 (4 bytes)
    char annotation[100]; // offset 0x04 
    int value;            // offset 0x68 (104 in decimal)

public:
    // _ZN1NC1Ei in assembly
    N(int val)
    {
        value = val;
    }

    // _ZN1N13setAnnotationEPc in assembly
    void setAnnotation(char* str)
    {
        size_t len = strlen(str);
        memcpy(this->annotation, str, len); 
    }

    // _ZN1NplERS_ in assembly
    // Mangling 'pl' = plus,
    virtual int operator+(N& rhs)
    {
        return this->value + rhs.value;
    }

    // _ZN1NmiERS_ in assembly
    // Mangling 'mi' = minus
    virtual int operator-(N& rhs)
    {
        return this->value - rhs.value;
    }
};

int main(int argc, char** argv)
{
    if (argc <= 1)
    {
        _exit(1); 
    }

    // _Znwj is operator new(unsigned int). Size of an obj is 108bytes
    N* obj1 = new N(5); 
    N* obj2 = new N(6); 

    obj1->setAnnotation(argv[1]);

    // Assuming operator+ is the first virtual function in the vtable:
    // This is true in level9 binary but can depend on compiler
    *obj2 + *obj1; 

    // We could also call first function in 
    /*
    void** vptr = *(void***)obj2; 

    // vptr[0] is a raw pointer to the first virtual function
    // We cast it to a function pointer type and execute it
    typedef int(*VirtFun)(*N this, &N rhs);
    VirtFun firstFunc = (VirtFun)vptr[0];

    // Call the function, passing the object itself as the 'this' pointer
    firstFunc(obj1);
    */

    return 0;
}

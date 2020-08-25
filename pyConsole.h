#ifndef PYCONSOLE_H
#define PYCONSOLE_H
#define PY_SSIZE_T_CLEAN

#include <stdio.h>
#include <python3.8/Python.h>

class pyConsole
{

public:
    pyConsole(/* args */);
    ~pyConsole();
    void test();
};

//Constructor
pyConsole::pyConsole()
{
    // Examples 
    
    //http://mateusz.loskot.net/post/2011/12/01/python-sys-stdout-redirection-in-cpp/

}

//Deconstructor
pyConsole::~pyConsole()
{

}

void pyConsole::test(){
    wchar_t *program = Py_DecodeLocale("./embeddingPythonCmake", NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);  // optional but recommended 

    Py_Initialize();
    PyRun_SimpleString(
        "from time import time,ctime\n"
        "print('Today is', ctime(time()))\n"
    );
    //Py_FinalizeEx(); //Notice that Py_FinalizeEx() does not free all memory allocated by the Python interpreter, e.g. memory allocated by extension modules currently cannot be released.
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    PyMem_RawFree(program);
}




#endif //PYCONSOLE_H
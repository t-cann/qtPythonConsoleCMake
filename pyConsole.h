#ifndef PYCONSOLE_H
#define PYCONSOLE_H
#define PY_SSIZE_T_CLEAN

#include <QDebug>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>
#include <stdio.h>
#include <python3.8/Python.h>
#include <string>


class pyConsole
{
private:
    wchar_t *program;
    bool hasError();

public:
    pyConsole(char *argv[]);
    ~pyConsole();
    void test();
    void runString(const char *);

    QString ObjectToString(PyObject*);
};

//Constructor
pyConsole::pyConsole(char *argv[])
{
    // Examples 
    //http://mateusz.loskot.net/post/2011/12/01/python-sys-stdout-redirection-in-cpp/
    

    program = Py_DecodeLocale((char*)argv[0], NULL); //
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);  // optional but recommended 

    std::string stdOutErr =
"import sys\n\
class CatchOutErr:\n\
    def __init__(self):\n\
        self.value = ''\n\
    def write(self, txt):\n\
        self.value += txt\n\
catchOutErr = CatchOutErr()\n\
oldstdout = sys.stdout\n\
sys.stdout = catchOutErr\n\
oldstderr = sys.stderr\n\
sys.stderr = catchOutErr\n\
"; //this is python code to redirect stdouts/stderr

    Py_Initialize();

    PyRun_SimpleString("print('>>> Start of Python Output / Constructor PyConsole')");

    PyObject *pModule = PyImport_AddModule("__main__"); //create main module
    PyRun_SimpleString(stdOutErr.c_str()); //invoke code to redirect
    
    test();
    PyRun_SimpleString("print(1+1)"); //this is ok stdout
    //PyRun_SimpleString("1+a"); //this creates an error
    //runString("5*10");

    PyObject *catcher = PyObject_GetAttrString(pModule,"catchOutErr"); //get our catchOutErr created above
    PyErr_Print(); //make python print any errors

    PyObject *output = PyObject_GetAttrString(catcher,"value"); //get the stdout and stderr from our catchOutErr object

    qDebug().noquote() <<"Catcher Output:\n\n" + pyConsole::ObjectToString(output).toUtf8(); // In Unicode format \n new line charaters how to remove?

    PyRun_SimpleString("sys.stdout = oldstdout");



}

//Deconstructor
pyConsole::~pyConsole()
{
    PyRun_SimpleString("print('<<< End of Python Output / Deconstructor PyConsole')");

        //Py_FinalizeEx(); //Notice that Py_FinalizeEx() does not free all memory allocated by the Python interpreter, e.g. memory allocated by extension modules currently cannot be released.
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    Py_Finalize();
    PyMem_RawFree(program);
}

//Function to Test Functionality and run Debug
void pyConsole::test(){
    
    PyRun_SimpleString(
        "from time import time,ctime\n"
        "print('Today is', ctime(time()))\n"
    );
    PyRun_SimpleString("1+3");

}

void pyConsole::runString(const char *command){
    PyRun_SimpleString(command);
}

//https://ubuverse.com/embedding-the-python-interpreter-in-a-qt-application/

QString pyConsole::ObjectToString(PyObject *poVal)
{
    QString val;

    if(poVal != NULL)
    {
        if(PyUnicode_Check(poVal))
        {
            // Convert Python Unicode object to UTF8 and return pointer to buffer
            const char *str = PyUnicode_AsUTF8(poVal);

            if(!hasError())
            {
                val = QString(str);
            }
        }

        // Release reference to object
        Py_XDECREF(poVal);
    }

    return val;
}

bool pyConsole::hasError()
{
    bool error = false;

    if(PyErr_Occurred())
    {
        // Output error to stderr and clear error indicator
        PyErr_Print();
        error = true;
    }

    return error;
}


#endif //PYCONSOLE_H
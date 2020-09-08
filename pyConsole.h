#ifndef PYCONSOLE_H
#define PYCONSOLE_H


#define PY_SSIZE_T_CLEAN

// #include <conio.h>
#include <Python.h>
#include <QDebug>
#include <QString>
#include <string>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>


using namespace std;

class pyConsole
{
private:
    wchar_t *program;
    bool hasError();
public:
    pyConsole(char* argv[]);
    ~pyConsole();
    void test();
    void runCommand(char* command);
    void PythonPrinting(string inputStr);
    QString ObjectToString(PyObject *poVal);
};

pyConsole::pyConsole(char* argv[])
{
    program = Py_DecodeLocale(argv[0], NULL);
    if (program == NULL) {
        fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
        exit(1);
    }
    Py_SetProgramName(program);  /* optional but recommended */
    Py_Initialize();

    //PySys_GetObject();
    pyConsole::PythonPrinting("print('PythonPrint')");

    PyRun_SimpleString("print('>>> Start of Python Output')");
    PyRun_SimpleString("from time import time,ctime\n"
                       "print('Today is', ctime(time()))\n");

}

pyConsole::~pyConsole()
{
    PyRun_SimpleString("print('<<< End of Python Output')");
    if (Py_FinalizeEx() < 0) {
        exit(120);
    }
    Py_Finalize();
    PyMem_RawFree(program);
}

void pyConsole::runCommand(char* command){
    PyRun_SimpleString(command);
}

void   pyConsole::test(){
    /* static PyObject* redirection_stdoutredirect(PyObject *self, PyObject *args)
    {
        const char *string;
        if(!PyArg_ParseTuple(args, "s", &string))
            return NULL;
        //pass string onto somewhere
        Py_INCREF(Py_None);
        return Py_None;
    }

    static PyMethodDef RedirectionMethods[] = {
        {"stdoutredirect", redirection_stdoutredirect, METH_VARARGS,
            "stdout redirection helper"},
        {NULL, NULL, 0, NULL}
    };
     */

        //https://docs.python.org/3.6/c-api/intro.html#embedding-python <-- Where Python looks for modules !?
    
    /* PyObject *sys = PyImport_ImportModule("sys");
    PyObject* io_stdout = PyFile_FromFile(stdout, "stdout", "a", nullptr);  PyFile_FromFile Python 2 Feature. 
    PyObject_SetAttrString(sys, "stdout", io_stdout);
    PyObject* io_stderr = PyFile_FromFile(stderr, "stderr", "a", nullptr);
    PyObject_SetAttrString(sys, "stderr", io_stderr);
    PyObject* io_stdin = PyFile_FromFile(stdin, "stdin", "r", nullptr);
    PyObject_SetAttrString(sys, "stdin", io_stdin); */

    /* Py_InitModule("redirection", RedirectionMethods);
    PyRun_SimpleString("\
        import redirection\n\
        import sys\n\
        class StdoutCatcher:\n\
        def write(self, stuff):\n\
            redirection.stdoutredirect(stuff)\n\
        sys.stdout = StdoutCatcher()"); */

    
    //https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop
    //PyRun_InteractiveLoop(,);

    // https://blog.numerix-dsp.com/2013/08/how-to-pass-c-array-to-python-solution.html?m=1


}

//Example:
//https://www.semicolonworld.com/question/57295/how-to-catch-python-stdout-in-c-code
void pyConsole::PythonPrinting(string inputStr){ 
     string stdOutErr =
    "import sys\n\
class CatchOut:\n\
    def __init__(self):\n\
        self.value = ''\n\
    def write(self, txt):\n\
        self.value += txt\n\
catchOut = CatchOut()\n\
sys.stdout = catchOut\n\
sys.stderr = catchOut\n\
    "; //this is python code to redirect stdouts/stderr

    PyObject *pModule = PyImport_AddModule("__main__"); //create main module
    PyRun_SimpleString(stdOutErr.c_str()); //invoke code to redirect
    PyRun_SimpleString(inputStr.c_str());
    PyObject *catcher = PyObject_GetAttrString(pModule,"catchOut");
    PyObject *output = PyObject_GetAttrString(catcher,"value");
    
    //qInfo() <<  output;
    qInfo() <<  output;
    qInfo() << &output;
    qInfo() << ObjectToString(output);


    //printf("Here's the output: %s\n", PyByte_AsString(output)); 

    //Put in Main: 
    //PythonPrinting("1+5");

    }

//Use fulllink ::
//https://ubuverse.com/embedding-the-python-interpreter-in-a-qt-application/
QString pyConsole::ObjectToString(PyObject *poVal)
{
    QString val;

    if(poVal != NULL)
    {
        if(PyUnicode_Check(poVal))
        {
            // Convert Python Unicode object to UTF8 and return pointer to buffer
            char *str = PyUnicode_AsUTF8(poVal);

            if(!hasError())
            {
                val = QString(str);
            }
        }

        // Release reference to object
        Py_XDECREF(poVal);https://ubuverse.com/embedding-the-python-interpreter-in-a-qt-application/l
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


#endif
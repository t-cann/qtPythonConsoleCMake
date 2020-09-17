#ifndef PYCONSOLE_H
#define PYCONSOLE_H
#define PY_SSIZE_T_CLEAN


#include <Python.h> //#include <python3.8/Python.h> can use this notation to chose specific versions of python if got wide imports.
#include <QDebug>
#include <QString>
#include <string>
#include <QStringList>
#include <QDir>
#include <QFileInfo>


class pyConsole
{
private:
    wchar_t *program;
    bool hasError();

    PyObject *pModule;
    PyObject *catcher;
    PyObject *output;
    
    QString ObjectToString(PyObject*);
    void runString(const char *);
    void displayDateandTime();
    void stringtoConsole(QString valName = "name", QString value = "Thomas");
    void inttoConsole(QString valName = "age", int value = 6);
    void doubletoConsole(QString valName = "pi", double value = 3.14159 );
    void arraytoConsole(QString valName = "array");

public:
    pyConsole();
    ~pyConsole();
    QString pyRun(QString);
};


#endif //PYCONSOLE_H

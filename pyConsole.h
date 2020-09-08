#ifndef PYCONSOLE_H
#define PYCONSOLE_H


#define PY_SSIZE_T_CLEAN


#include <Python.h>
#include <QDebug>
#include <QString>
#include <string>
#include <QString>
#include <QStringList>
#include <QDir>
#include <QFileInfo>


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


#endif //PYCONSOLE_H

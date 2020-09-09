#ifndef PYCONSOLE_H
#define PYCONSOLE_H
#define PY_SSIZE_T_CLEAN


#include <Python.h>
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
    PyObject *catcher;
    PyObject *output;
    PyObject *pModule;

public:
    pyConsole();
    ~pyConsole();
    void test();
    void runString(const char *);
    QString pyRun(QString);
    QString ObjectToString(PyObject*);
};


#endif //PYCONSOLE_H

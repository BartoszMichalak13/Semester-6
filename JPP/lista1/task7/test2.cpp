#include <Python.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <a> <b> <c>\n", argv[0]);
        return 1;
    }    

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    // Initialize the Python interpreter
    Py_Initialize();

    // Add the directory containing library_recursion.py to the Python path
    // PyRun_SimpleString("import sys\nsys.path.append('/home/bartek/Desktop/sem6/Semester-6/JPP/task3/')");
    PyRun_SimpleString("import sys\nsys.path.append('../task3/')");

    // Import the Python module
    PyObject* pModule_recursive = PyImport_ImportModule("library_recursive");
    PyObject* pModule_loop = PyImport_ImportModule("library_loop");

    // Check if the module is imported successfully
    if (pModule_recursive == NULL) {
        PyErr_Print();
        return 1;
    }
    // Check if the module is imported successfully
    if (pModule_loop == NULL) {
        PyErr_Print();
        return 1;
    }

    // Get references to the functions
    PyObject* pFactorialFunc_recursive = PyObject_GetAttrString(pModule_recursive, "factorial");
    PyObject* pGCDFunc_recursive = PyObject_GetAttrString(pModule_recursive, "gcd");
    PyObject* pSolveDiophantineFunc_recursive = PyObject_GetAttrString(pModule_recursive, "solve_diophantine");

    PyObject* pFactorialFunc_loop = PyObject_GetAttrString(pModule_loop, "factorial");
    PyObject* pGCDFunc_loop = PyObject_GetAttrString(pModule_loop, "gcd");
    PyObject* pSolveDiophantineFunc_loop = PyObject_GetAttrString(pModule_loop, "solve_diophantine");

    // Call individual functions with appropriate arguments
    PyObject* pFactorialResult_recursive = PyObject_CallFunction(pFactorialFunc_recursive, "i", a);
    PyObject* pGCDResult_recursive = PyObject_CallFunction(pGCDFunc_recursive, "ii", a, b);
    PyObject* pDiophantineResult_recursive = PyObject_CallFunction(pSolveDiophantineFunc_recursive, "iii", a, b, c);

    PyObject* pFactorialResult_loop = PyObject_CallFunction(pFactorialFunc_loop, "i", a);
    PyObject* pGCDResult_loop = PyObject_CallFunction(pGCDFunc_loop, "ii", a, b);
    PyObject* pDiophantineResult_loop = PyObject_CallFunction(pSolveDiophantineFunc_loop, "iii", a, b, c);

    // Extract values from the results if needed
    long factorialResult_recursive = PyLong_AsLong(pFactorialResult_recursive);
    long gcdResult_recursive = PyLong_AsLong(pGCDResult_recursive);

    long factorialResult_loop = PyLong_AsLong(pFactorialResult_loop);
    long gcdResult_loop = PyLong_AsLong(pGCDResult_loop);

    // Extract Diophantine solution x and y
    PyObject* pX_recursive = PyObject_GetAttrString(pDiophantineResult_recursive, "x");
    PyObject* pY_recursive = PyObject_GetAttrString(pDiophantineResult_recursive, "y");
    long x_recursive = PyLong_AsLong(pX_recursive);
    long y_recursive = PyLong_AsLong(pY_recursive);

    PyObject* pX_loop = PyObject_GetAttrString(pDiophantineResult_loop, "x");
    PyObject* pY_loop = PyObject_GetAttrString(pDiophantineResult_loop, "y");
    long x_loop = PyLong_AsLong(pX_loop);
    long y_loop = PyLong_AsLong(pY_loop);

    // Print the results
    printf("Factorial_recursive of %d: %ld\n", a, factorialResult_recursive);
    printf("GCD_recursive of %d and %d: %ld\n", a, b, gcdResult_recursive);
    printf("Diophantine_recursive solution: x = %ld, y = %ld\n", x_recursive, y_recursive);

    printf("Factorial_loop of %d: %ld\n", a, factorialResult_loop);
    printf("GCD_loop of %d and %d: %ld\n", a, b, gcdResult_loop);
    printf("Diophantine_loop solution: x = %ld, y = %ld\n", x_loop, y_loop);

    // Cleanup
    Py_DECREF(pFactorialFunc_recursive);
    Py_DECREF(pGCDFunc_recursive);
    Py_DECREF(pSolveDiophantineFunc_recursive);
    Py_DECREF(pModule_recursive);
    Py_DECREF(pFactorialResult_recursive);
    Py_DECREF(pGCDResult_recursive);
    Py_DECREF(pDiophantineResult_recursive);
    Py_DECREF(pX_recursive);
    Py_DECREF(pY_recursive);

    Py_DECREF(pFactorialFunc_loop);
    Py_DECREF(pGCDFunc_loop);
    Py_DECREF(pSolveDiophantineFunc_loop);
    Py_DECREF(pModule_loop);
    Py_DECREF(pFactorialResult_loop);
    Py_DECREF(pGCDResult_loop);
    Py_DECREF(pDiophantineResult_loop);
    Py_DECREF(pX_loop);
    Py_DECREF(pY_loop);

    // Finalize the Python interpreter
    Py_Finalize();

    return 0;
}

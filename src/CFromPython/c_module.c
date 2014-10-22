/*  Example of wrapping cos function from math.h with the Python-C-API. */

#include <Python.h>
#include <math.h>

/*  wrapped cosine function */
static PyObject* cos_func(PyObject* self, PyObject* args) {
	double value;
	double answer;

	/*  parse the input, from python float to c double */
	if (!PyArg_ParseTuple(args, "d", &value))
		return NULL;
	/* if the above function returns -1, an appropriate Python exception will
	 * have been set, and the function simply returns NULL
	 */

	/* call cos from libm */
	answer = cos(value);

	/*  construct the output from cos, from c double to python float */
	return Py_BuildValue("f", answer);
}


static PyObject* sin_func(PyObject* self, PyObject* args) {
	double value;
	double answer;

	if (!PyArg_ParseTuple(args, "d", &value))
		return NULL;

	answer = sin(value);

	return Py_BuildValue("f", answer);
}


/*  define functions in module */
static PyMethodDef CosMethods[] = { { "cos_func", cos_func, METH_VARARGS,
		"evaluate the cosine" }, { NULL, NULL, 0, NULL } };

static PyMethodDef SinMethods[] = { { "sin_func", sin_func, METH_VARARGS,
		"evaluate the sine" }, { NULL, NULL, 0, NULL } };


/* module initialization */
PyMODINIT_FUNC

initc_module(void) {
	(void) Py_InitModule("c_module", CosMethods);
	(void) Py_InitModule("c_module", SinMethods);
}

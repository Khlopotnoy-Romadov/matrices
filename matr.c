#include <Python.h>
#include <math.h>
#include <time.h>

static PyObject *add(PyObject *self, PyObject *args) {
    PyObject* mtr1;
    PyObject* mtr2;
    int i, j, n;
    double res1, res2;


    if (!PyArg_ParseTuple(args, "OO", &mtr1, &mtr2)){
        return NULL;
    }

	n = PyList_GET_SIZE(mtr1);

    double **A = (double**)malloc(n * sizeof(double*));
    double **B = (double**)malloc(n * sizeof(double*));
    double **C = (double**)malloc(n * sizeof(double*));

    for (i=0; i<n; i++){
	A[i] = (double*)malloc(n * sizeof(double));
	B[i] = (double*)malloc(n * sizeof(double));
	C[i] = (double*)malloc(n * sizeof(double));
    }

    for (i=0; i<n; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(mtr1, i);
	for (j=0; j<n; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;
	}
    }


    for (i=0; i<n; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(mtr2, i);
	for (j=0; j<n; j++){
	    res2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
	    B[i][j] = res2;
	}
    }


    for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
            C[i][j] = A[i][j]+B[i][j];
	    }
    }


    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyFloat_FromDouble(C[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(A[i]);
	free(B[i]);
	free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return my_list;
}

static PyObject *multiply(PyObject *self, PyObject *args) {
    PyObject* mtr1;
    PyObject* mtr2;
    int i, j, k, n;
    double res1, res2;


    if (!PyArg_ParseTuple(args, "OO", &mtr1, &mtr2)){
        return NULL;
    }

	n = PyList_GET_SIZE(mtr1);

    double **A = (double**)malloc(n * sizeof(double*));
    double **B = (double**)malloc(n * sizeof(double*));
    double **C = (double**)malloc(n * sizeof(double*));

    for (i=0; i<n; i++){
	A[i] = (double*)malloc(n * sizeof(double));
	B[i] = (double*)malloc(n * sizeof(double));
	C[i] = (double*)malloc(n * sizeof(double));
    }

    for (i=0; i<n; i++){
        PyObject* item1 = PySequence_Fast_GET_ITEM(mtr1, i);
	for (j=0; j<n; j++){
	    res1 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item1, j));
	    A[i][j] = res1;
	}
    }


    for (i=0; i<n; i++){
        PyObject* item2 = PySequence_Fast_GET_ITEM(mtr2, i);
	for (j=0; j<n; j++){
	    res2 = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item2, j));
	    B[i][j] = res2;
	}
    }


    for(i=0; i<n; i++){
	    for(j=0; j<n; j++){
            C[i][j] = 0;
            for(k=0; k<n; k++){
                C[i][j] += A[i][k] * B[k][j];
            }
	    }
    }


    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyFloat_FromDouble(C[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(A[i]);
	free(B[i]);
	free(C[i]);
    }
    free(A);
    free(B);
    free(C);
    return my_list;
}

static PyObject *identity_matrix(PyObject *self, PyObject *args)
{
    int n;
    int i, j;

    if (!PyArg_ParseTuple(args, "i", &n)){
        return NULL;
    }

    double **M = (double**)malloc(n * sizeof(double*));

    for (i=0; i<n; i++){
	M[i] = (double*)malloc(n * sizeof(double));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                M[i][j] = 1.0;
            } else {
                M[i][j] = 0.0;
            }
        }
    }

    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyFloat_FromDouble(M[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(M[i]);
    }
    free(M);
    return my_list;
}

static PyObject *mul_on_number(PyObject *self, PyObject *args)
{
    PyObject* list;
    int i, j, c, n;
    float res;


    if (!PyArg_ParseTuple(args, "Oi", &list, &c)){
        return NULL;
    }
	n = PyList_GET_SIZE(list);


    double **M = (double**)malloc(n * sizeof(double*));
    for (i=0; i<n; i++){
	M[i] = (double*)malloc(n * sizeof(double));
	}

    for (i=0; i<n; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i);
	for (j=0; j<n; j++){
	    res = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item, j));
	    M[i][j] = res;
	}
    }


    for(i=0; i<n; i++)
{
	for(j=0; j<n; j++)
	M[i][j] = M[i][j] * c;
}



    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyFloat_FromDouble(M[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(M[i]);
    }
    free(M);
    return my_list;

}

static PyObject *random_matrix(PyObject *self, PyObject *args)
{
    int n;
    int i, j;
    srand(time(0));

    if (!PyArg_ParseTuple(args, "i", &n)){
        return NULL;
    }

    double **M = (double**)malloc(n * sizeof(double*));

    for (i=0; i<n; i++){
	M[i] = (double*)malloc(n * sizeof(double));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = floor(rand() % 100 + 2);
        }
    }

    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyFloat_FromDouble(M[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(M[i]);
    }
    free(M);
    return my_list;
}

static PyObject *random_symm_matrix(PyObject *self, PyObject *args)
{
    int n;
    int i, j, r;
    srand(time(0));

    if (!PyArg_ParseTuple(args, "i", &n)){
        return NULL;
    }

    double **M = (double**)malloc(n * sizeof(double*));

    for (i=0; i<n; i++){
	M[i] = (double*)malloc(n * sizeof(double));
    }

    for (i = 0; i < n; i++) {
        for (j = i; j < n; j++) {
            r = floor(rand() % 100 + 2);
            M[i][j] = r;
            M[j][i] = r;
        }
    }

    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyFloat_FromDouble(M[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(M[i]);
    }
    free(M);
    return my_list;
}

static PyObject *random_diag_matrix(PyObject *self, PyObject *args)
{
    int n;
    int i, j;
    srand(time(0));


    if (!PyArg_ParseTuple(args, "i", &n)){
        return NULL;
    }

    double **M = (double**)malloc(n * sizeof(double*));

    for (i=0; i<n; i++){
	M[i] = (double*)malloc(n * sizeof(double));
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i == j) {
                M[i][j] = floor(rand() % 100 + 2);;
            } else {
                M[i][j] = 0.0;
            }
        }
    }

    PyObject *my_list = PyList_New(0);
    for (i=0; i<n; i++){
	PyObject *new_list = PyList_New(n);
	for (int j=0; j<n; j++){
	    PyObject *the_object = PyFloat_FromDouble(M[i][j]);
	    PyList_SetItem(new_list, j, the_object);
	}

	PyList_Append(my_list, new_list);
    }



    for (i=0;i<n;i++){
	free(M[i]);
    }
    free(M);
    return my_list;
}

static PyObject *matrix_transpose(PyObject *self, PyObject *args)
{
    PyObject* list;
    int i, j, c, L;
    float res;

    if (!PyArg_ParseTuple(args, "O", &list))
    {
        return NULL;
    }
	L = PyList_GET_SIZE(list);

	double **A = (double**)malloc(L * sizeof(double*));
    	for (i=0; i<L; i++)
		{
		A[i] = (double*)malloc(L * sizeof(double));
		}

    for (i=0; i<L; i++){
        PyObject* item = PySequence_Fast_GET_ITEM(list, i);
	for (j=0; j<L; j++){
	    res = PyFloat_AsDouble(PySequence_Fast_GET_ITEM(item, j));
	    A[i][j] = res;
			   }
    		       }

	double **B = (double**)malloc(L * sizeof(double*));
    	for (i=0; i<L; i++)
		{
		B[i] = (double*)malloc(L * sizeof(double));
		}

    for(i = 0; i < L; i++)
{
	for(j = 0; j < L; j++)
	B[j][i] = A[i][j];
}
 	PyObject *my_list = PyList_New(0);
    	for (i=0; i<L; i++){
		PyObject *new_list = PyList_New(L);
		for (int j=0; j<L; j++)
			{
	   		PyObject *the_object = PyFloat_FromDouble(B[i][j]);
	   		PyList_SetItem(new_list, j, the_object);
			}

	PyList_Append(my_list, new_list);
    			}



    for (i=0;i<L;i++){
	free(A[i]);
	free(B[i]);
    }
    free(A);
    free(B);
   return my_list;

}


static PyObject* solve(PyObject* self, PyObject* args) {
    int i, j, k, n;
    double m;
    PyObject *matrix, *rhs, *item, *row;
    if (!PyArg_ParseTuple(args, "OO", &matrix, &rhs) || !PyList_Check(matrix) || !PyList_Check(rhs)) {
        PyErr_SetString(PyExc_TypeError, "Arguments must be a list of lists and a list");
        return NULL;
    }
    n = PyList_Size(matrix);
    double **A = (double**)malloc(n * sizeof(double*));
    double *b = (double*)malloc(n * sizeof(double));
    double *x = (double*)malloc(n * sizeof(double));
    for (i = 0; i < n; ++i) {
        row = PyList_GetItem(matrix, i);
        A[i] = (double*)malloc(n * sizeof(double));
        for (j = 0; j < n; ++j) {
            item = PyList_GetItem(row, j);
            A[i][j] = PyLong_AsLong(item);
        }
        item = PyList_GetItem(rhs, i);
        b[i] = PyLong_AsLong(item);
    }
    for (k = 0; k < n; ++k) {
        m = fabs(A[k][k]);
        j = k;
        for (i = k + 1; i < n; ++i) {
            if (fabs(A[i][k]) > m) {
                m = fabs(A[i][k]);
                j = i;
            }
        }
        if (j != k) {
            for (i = 0; i < n; ++i) {
                m = A[k][i];
                A[k][i] = A[j][i];
                A[j][i] = m;
            }
            m = b[k];
            b[k] = b[j];
            b[j] = m;
        }
        for (i = k + 1; i < n; ++i) {
            m = A[i][k] / A[k][k];
            for (j = k; j < n; ++j) {
                A[i][j] -= m * A[k][j];
            }
            b[i] -= m * b[k];
        }
    }
    for (i = n - 1; i >= 0; --i) {
        x[i] = b[i] / A[i][i];
        for (k = i - 1; k >= 0; --k) {
            b[k] -= A[k][i] * x[i];
        }
    }
    PyObject* result = PyList_New(n);

for (i = 0; i < n; ++i) {
        PyList_SetItem(result, i, PyFloat_FromDouble(x[i]));
        free(A[i]);
    }
    free(A);
    free(b);
    free(x);
    return result;
}

static PyMethodDef ownmod_methods[] = {
    {
        "multiply",
        multiply,
        METH_VARARGS,
        "matrix multiplication function"
    },
    {
	"add",
	add,
	METH_VARARGS,
	"matrix sum"
    }, {
	"identity_matrix",
	identity_matrix,
	METH_VARARGS,
	"id"
    },{
	"mul_on_number",
	mul_on_number,
	METH_VARARGS,
	"mon"
    },{
	"random_matrix",
	random_matrix,
	METH_VARARGS,
	"random"
    },{
	"random_symm_matrix",
	random_symm_matrix,
	METH_VARARGS,
	"random simmetric matrix"
    },{
	"random_diag_matrix",
	random_diag_matrix,
	METH_VARARGS,
	"random diagonal matrix"
    },{
	"matrix_transpose",
	matrix_transpose,
	METH_VARARGS,
	"matrix transposition"
    },{
	"solve",
	solve,
	METH_VARARGS,
	"solve"
    },
    { NULL, NULL, 0, NULL }
};

static PyModuleDef simple_module = {
    /* Info about module */
    PyModuleDef_HEAD_INIT,
    "matrices", // matrices.__name__
    "matrices multiplication documentation", // pokoev.__doc__
    -1,
    ownmod_methods, // methods are here
    NULL,NULL,NULL
};

PyMODINIT_FUNC PyInit_matrices(void)
{
    PyObject* m;
    // creating module object
    m = PyModule_Create(&simple_module);
    if (m == NULL)
        return NULL;

    return m;}

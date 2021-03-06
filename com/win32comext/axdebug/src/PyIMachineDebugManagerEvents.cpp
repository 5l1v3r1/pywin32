// This file implements the IMachineDebugManagerEvents Interface and Gateway for Python.
// Generated by makegw.py

#include "stdafx.h"
#include "PythonCOM.h"
#include "PythonCOMServer.h"
#include "PyIMachineDebugManagerEvents.h"

// @doc - This file contains autoduck documentation
// ---------------------------------------------------
//
// Interface Implementation

PyIMachineDebugManagerEvents::PyIMachineDebugManagerEvents(IUnknown *pdisp) : PyIUnknown(pdisp) { ob_type = &type; }

PyIMachineDebugManagerEvents::~PyIMachineDebugManagerEvents() {}

/* static */ IMachineDebugManagerEvents *PyIMachineDebugManagerEvents::GetI(PyObject *self)
{
    return (IMachineDebugManagerEvents *)PyIUnknown::GetI(self);
}

// @pymethod |PyIMachineDebugManagerEvents|onAddApplication|Description of onAddApplication.
PyObject *PyIMachineDebugManagerEvents::onAddApplication(PyObject *self, PyObject *args)
{
    IMachineDebugManagerEvents *pIMDME = GetI(self);
    if (pIMDME == NULL)
        return NULL;
    // @pyparm <o PyIRemoteDebugApplication>|pda||Description for pda
    // @pyparm int|dwAppCookie||Description for dwAppCookie
    PyObject *obpda;
    IRemoteDebugApplication *pda;
    DWORD dwAppCookie;
    if (!PyArg_ParseTuple(args, "Oi:onAddApplication", &obpda, &dwAppCookie))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpda, IID_IRemoteDebugApplication, (void **)&pda, FALSE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    PY_INTERFACE_PRECALL;
    HRESULT hr = pIMDME->onAddApplication(pda, dwAppCookie);
    pda->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @pymethod |PyIMachineDebugManagerEvents|onRemoveApplication|Description of onRemoveApplication.
PyObject *PyIMachineDebugManagerEvents::onRemoveApplication(PyObject *self, PyObject *args)
{
    IMachineDebugManagerEvents *pIMDME = GetI(self);
    if (pIMDME == NULL)
        return NULL;
    // @pyparm <o PyIRemoteDebugApplication>|pda||Description for pda
    // @pyparm int|dwAppCookie||Description for dwAppCookie
    PyObject *obpda;
    IRemoteDebugApplication *pda;
    DWORD dwAppCookie;
    if (!PyArg_ParseTuple(args, "Oi:onRemoveApplication", &obpda, &dwAppCookie))
        return NULL;
    BOOL bPythonIsHappy = TRUE;
    if (!PyCom_InterfaceFromPyInstanceOrObject(obpda, IID_IRemoteDebugApplication, (void **)&pda, FALSE /* bNoneOK */))
        bPythonIsHappy = FALSE;
    if (!bPythonIsHappy)
        return NULL;
    PY_INTERFACE_PRECALL;
    HRESULT hr = pIMDME->onRemoveApplication(pda, dwAppCookie);
    pda->Release();
    PY_INTERFACE_POSTCALL;
    if (FAILED(hr))
        return OleSetOleError(hr);
    Py_INCREF(Py_None);
    return Py_None;
}

// @object PyIMachineDebugManagerEvents|Description of the interface
static struct PyMethodDef PyIMachineDebugManagerEvents_methods[] = {
    {"onAddApplication", PyIMachineDebugManagerEvents::onAddApplication,
     1},  // @pymeth onAddApplication|Description of onAddApplication
    {"onRemoveApplication", PyIMachineDebugManagerEvents::onRemoveApplication,
     1},  // @pymeth onRemoveApplication|Description of onRemoveApplication
    {NULL}};

PyComTypeObject PyIMachineDebugManagerEvents::type("PyIMachineDebugManagerEvents", &PyIUnknown::type,
                                                   sizeof(PyIMachineDebugManagerEvents),
                                                   PyIMachineDebugManagerEvents_methods,
                                                   GET_PYCOM_CTOR(PyIMachineDebugManagerEvents));
// ---------------------------------------------------
//
// Gateway Implementation

STDMETHODIMP PyGMachineDebugManagerEvents::onAddApplication(
    /* [in] */ IRemoteDebugApplication __RPC_FAR *pda,
    /* [in] */ DWORD dwAppCookie)
{
    PY_GATEWAY_METHOD;
    PyObject *obpda;
    obpda = PyCom_PyObjectFromIUnknown(pda, IID_IRemoteDebugApplication, TRUE);
    HRESULT hr = InvokeViaPolicy("onAddApplication", NULL, "Oi", obpda, dwAppCookie);
    Py_XDECREF(obpda);
    return hr;
}

STDMETHODIMP PyGMachineDebugManagerEvents::onRemoveApplication(
    /* [in] */ IRemoteDebugApplication __RPC_FAR *pda,
    /* [in] */ DWORD dwAppCookie)
{
    PY_GATEWAY_METHOD;
    PyObject *obpda;
    obpda = PyCom_PyObjectFromIUnknown(pda, IID_IRemoteDebugApplication, TRUE);
    HRESULT hr = InvokeViaPolicy("onRemoveApplication", NULL, "Oi", obpda, dwAppCookie);
    Py_XDECREF(obpda);
    return hr;
}

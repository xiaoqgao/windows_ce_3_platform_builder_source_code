//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
//
// This source code is licensed under Microsoft Shared Source License
// Version 1.0 for Windows CE.
// For a copy of the license visit http://go.microsoft.com/fwlink/?LinkId=3223.
//
//+----------------------------------------------------------------------------
//
//
// File:    ensoapop.cpp
//
// Contents:
//
//  implementation file
//
//        IEnumOperations Interface implemenation
//
//-----------------------------------------------------------------------------
#include "headers.h"
#include "enwsdlop.h"

#ifdef UNDER_CE
#include "WinCEUtils.h"
#endif


BEGIN_INTERFACE_MAP(CEnumWSDLOperations)
    ADD_IUNKNOWN(CEnumWSDLOperations, IEnumWSDLOperations)
    ADD_INTERFACE(CEnumWSDLOperations, IEnumWSDLOperations)
END_INTERFACE_MAP(CEnumWSDLOperations)




/////////////////////////////////////////////////////////////////////////////





/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: CENumWSDLOperations::CENumWSDLOperations()
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
CEnumWSDLOperations::CEnumWSDLOperations()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: CENumWSDLOperations::~CENumWSDLOperations()
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
CEnumWSDLOperations::~CEnumWSDLOperations()
{
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: HRESULT CEnumWSDLOperations::Next(long celt, IWSDLOperation **ppWSDLOperation, long *pulFetched)
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Next(long celt, IWSDLOperation **ppWSDLOperation, long *pulFetched)
{
    return(m_operationList.Next(celt, ppWSDLOperation, pulFetched));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: HRESULT CEnumWSDLOperations::Skip(long celt)
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Skip(long celt)
{
    return(m_operationList.Skip(celt));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: HRESULT CEnumWSDLOperations::Reset(void)
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Reset(void)
{
    return(m_operationList.Reset());
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: HRESULT CEnumWSDLOperations::Clone(IEnumWSDLOperations **ppenum)
//
//  parameters:
//
//  description:
//
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Clone(IEnumWSDLOperations **ppenum)
{
    HRESULT hr = S_OK;
    CEnumWSDLOperations *pOpers;
    pOpers = new CSoapObject<CEnumWSDLOperations>(INITIAL_REFERENCE);
    CHK_BOOL(pOpers, E_OUTOFMEMORY);

    CHK(pOpers->Copy(this));
    pOpers->Reset();
    *ppenum = pOpers;
Cleanup:
    return (hr);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function:HRESULT CEnumWSDLOperations::Copy(CEnumWSDLOperations *pOrg)
//
//  parameters:
//
//  description:
// 
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Copy(CEnumWSDLOperations *pOrg)
{
    return (pOrg->m_operationList.Clone(m_operationList));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function:HRESULT CEnumWSDLOperations::Find(BSTR bstrOperationToFind, IWSDLOperation **ppIWSDLOperation)
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Find(BSTR bstrOperationToFind, IWSDLOperation **ppIWSDLOperation)
{
    return(m_operationList.Find(bstrOperationToFind, ppIWSDLOperation));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: HRESULT CEnumWSDLOperations::Add(IWSDLOperation *pWSDLOperation)
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Add(IWSDLOperation *pWSDLOperation)
{
    return(m_operationList.Add(pWSDLOperation));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////////////////////////////
//  function: HRESULT CEnumWSDLOperations::Size(long *pulSize)
//
//  parameters:
//
//  description:
//
//  returns:
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT CEnumWSDLOperations::Size(long *pulSize)
{
    return(m_operationList.Size(pulSize));
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

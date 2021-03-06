// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CATITreeNodeEventPublisher.h
// Define the CATITreeNodeEventPublisher interface
//
//===================================================================
//
// Usage notes:
//   New interface: describe its use here
//
//===================================================================
//
//  Feb 2010  Creation: Code generated by the CAA wizard  user
//===================================================================
#ifndef CATITreeNodeEventPublisher_H
#define CATITreeNodeEventPublisher_H

#include "ktTreeNodeInterface.h"
#include "CATBaseUnknown.h"

#ifndef LOCAL_DEFINITION_FOR_IID
extern ExportedByktTreeNodeInterface IID IID_CATITreeNodeEventPublisher;
#else
extern "C" const IID IID_CATITreeNodeEventPublisher ;
#endif

//------------------------------------------------------------------

/**
* Interface representing xxx.
*
* <br><b>Role</b>: Components that implement
* CATITreeNodeEventPublisher are ...
* <p>
* Do not use the CATITreeNodeEventPublisher interface for such and such

*
* @example
*  // example is optional
*  CATITreeNodeEventPublisher* currentDisplay = NULL;
*  rc = window-&gt;QueryInterface(IID_CATITreeNodeEventPublisher,
*                                     (void**) &amp;currentDisplay);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktTreeNodeInterface CATITreeNodeEventPublisher: public CATBaseUnknown
{
  CATDeclareInterface;

  public:

    /**
     * Remember that interfaces define only virtual pure methods.
     * Dont forget to document your methods.
     * <dl>
     * <dt><b>Example:</b>
     * <pre>
     *       
           *   MyFunction does this and that
           *   @param Arg1
           *      The first argument of MyFunction.
           *   @return
           *      Error code of function.
           * 
     * virtual int MyFunction (int Arg1) = 0;
     * </pre>
     * </dl>
     */

  // No constructors or destructors on this pure virtual base class
  // --------------------------------------------------------------

	  virtual HRESULT PublishTreeNodeSelectEvent() = 0;

	  virtual HRESULT PublishTreeNodeCxtMenuEvent() = 0;
};

//------------------------------------------------------------------

#endif

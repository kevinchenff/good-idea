// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CAATreeNodeEventAgent.h
// Header definition of CAATreeNodeEventAgent
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2010  Creation: Code generated by the CAA wizard  user
//===================================================================
#ifndef CAATreeNodeEventAgent_H
#define CAATreeNodeEventAgent_H

#include "ktTreeNodeImplement.h"
#include "CATEventSubscriber.h"

#include "CATNavigBox.h"

//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href CAATreeNodeEventAgent constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new CAATreeNodeEventAgent;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class CAATreeNodeEventAgent: public CATEventSubscriber
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     CAATreeNodeEventAgent (CATNavigBox * pNavigBox);
     virtual ~CAATreeNodeEventAgent ();



	 void GetCurrentSelectNode (CATBaseUnknown ** pCurrentSelectTreeNode);

	 void AddTreeNodeObjToListen(CATBaseUnknown * piTreeNodeObj);

	 void RemoveTreeNodeObjToListen(CATBaseUnknown * piTreeNodeObj);



	 void TreeNodeSelectNotifAgent(CATCallbackEvent event,
									void * client,
									CATNotification * iNotification,
									CATSubscriberData data,
									CATCallback callback);

	void TreeNodeCxtMenuNotifAgent(CATCallbackEvent event,
								void * client,
								CATNotification * iNotification,
								CATSubscriberData data,
								CATCallback callback);


  // Copy constructor and equal operator
  // -----------------------------------
  CAATreeNodeEventAgent (CAATreeNodeEventAgent &);
  CAATreeNodeEventAgent& operator=(CAATreeNodeEventAgent&);


  private:

	CATBaseUnknown * CurrentSelectTreeNode;
	CATNavigBox * pMonitorNavigBox;

};

//-----------------------------------------------------------------------

#endif

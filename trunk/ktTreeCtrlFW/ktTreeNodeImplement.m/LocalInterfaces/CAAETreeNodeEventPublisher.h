// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CAAETreeNodeEventPublisher.h
// Provide implementation to interface
//    CATITreeNodeEventPublisher

//
//===================================================================
//
// Usage notes:
//
//===================================================================
//CAA2 Wizard Generation Report
//EXTENSION:	CATTreeNodeObj
//EXTENSIONTYPE:	DataExtension

//    TIE: CATITreeNodeEventPublisher

//End CAA2 Wizard Generation Report
//
//  Feb 2010  Creation: Code generated by the CAA wizard  user
//===================================================================
#ifndef CAAETreeNodeEventPublisher_H
#define CAAETreeNodeEventPublisher_H

#include "CATEventSubscriber.h"

//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* It implements the interfaces :
*  <ol>
*  <li>@href CATITreeNodeEventPublisher
*  </ol>
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class CAAETreeNodeEventPublisher: public CATEventSubscriber

{
  CATDeclareClass;

  public:

  // Standard constructors and destructors for an implementation class
  // -----------------------------------------------------------------
     CAAETreeNodeEventPublisher ();
     virtual ~CAAETreeNodeEventPublisher ();

    /**
     * Implements a function from an interface.
     * @href CATITreeNodeEventPublisher#PublishTreeNodeSelectEvent
     */
     HRESULT PublishTreeNodeSelectEvent () ;

    /**
     * Implements a function from an interface.
     * @href CATITreeNodeEventPublisher#PublishTreeNodeCxtMenuEvent
     */
     HRESULT PublishTreeNodeCxtMenuEvent () ;


  private:
  // The copy constructor and the equal operator must not be implemented
  // -------------------------------------------------------------------
  CAAETreeNodeEventPublisher (CAAETreeNodeEventPublisher &);
  CAAETreeNodeEventPublisher& operator=(CAAETreeNodeEventPublisher&);

};

//-----------------------------------------------------------------------

#endif

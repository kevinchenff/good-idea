// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// TreeNodeCxtMenuNotif.cpp
// Header definition of TreeNodeCxtMenuNotif
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2010  Creation: Code generated by the CAA wizard  user
//===================================================================
#include "TreeNodeCxtMenuNotif.h"
 
CATImplementClass( TreeNodeCxtMenuNotif,
                   Implementation, 
                   CATNotification,
                   CATNull );
 
//-----------------------------------------------------------------------------
// TreeNodeCxtMenuNotif : constructor
//-----------------------------------------------------------------------------
TreeNodeCxtMenuNotif::TreeNodeCxtMenuNotif():
    CATNotification(),_pRequestCxtMenuTreeNode(NULL)
{
}

//-----------------------------------------------------------------------------
// TreeNodeCxtMenuNotif : destructor
//-----------------------------------------------------------------------------
TreeNodeCxtMenuNotif::~TreeNodeCxtMenuNotif()
{
	if (_pRequestCxtMenuTreeNode != NULL)
	{
		_pRequestCxtMenuTreeNode -> Release();
		_pRequestCxtMenuTreeNode = NULL;
	}
}
 
//-----------------------------------------------------------------------------
// TreeNodeCxtMenuNotif : copy constructor
//-----------------------------------------------------------------------------
TreeNodeCxtMenuNotif::TreeNodeCxtMenuNotif(TreeNodeCxtMenuNotif& original):
   CATNotification(original)
{
}
 
//-----------------------------------------------------------------------------
// TreeNodeCxtMenuNotif : equal operator
//-----------------------------------------------------------------------------
TreeNodeCxtMenuNotif& TreeNodeCxtMenuNotif::operator=(TreeNodeCxtMenuNotif& original)
{
   CATNotification::operator=(original);
   return *this;
}
 
CATBaseUnknown * TreeNodeCxtMenuNotif::GetRequestCxtMenuTreeNode()
{
	if (_pRequestCxtMenuTreeNode != NULL)
	{
		_pRequestCxtMenuTreeNode -> AddRef();
		return _pRequestCxtMenuTreeNode;
	}
	else
	{
		return NULL;
	}
}

void  TreeNodeCxtMenuNotif::SetRequestCxtMenuTreeNode(CATBaseUnknown * pTreeNode)
{
	if (_pRequestCxtMenuTreeNode != NULL)
	{
		_pRequestCxtMenuTreeNode -> Release();
		_pRequestCxtMenuTreeNode = NULL;
	}

	_pRequestCxtMenuTreeNode = pTreeNode;

	_pRequestCxtMenuTreeNode -> AddRef();
}
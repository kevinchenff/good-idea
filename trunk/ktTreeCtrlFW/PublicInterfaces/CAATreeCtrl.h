// COPYRIGHT Dassault Systemes 2010
//===================================================================
//
// CAATreeCtrl.h
// Header definition of CAATreeCtrl
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Feb 2010  Creation: Code generated by the CAA wizard  user
//===================================================================
#ifndef CAATreeCtrl_H
#define CAATreeCtrl_H

#include "ktTreeCtrlModule.h"
#include "CATDlgContainer.h"

#include "CATNavigBox.h"

#include "CATListOfCATBaseUnknown.h"

class CAATreeNodeEventAgent;

//-----------------------------------------------------------------------

/**
* Class representing xxx.
*
* <br><b>Role</b>: Provide the basic class function...
* <p>
* Do not use the @href CAATreeCtrl constructor to
* do such and such but instead...
*
* @example
*  // example is optional
*  pObject = new CAATreeCtrl;
*  pObject->SetXXX(...);
*
* @href ClassReference, Class#MethodReference, #InternalMethod...
*/
class ExportedByktTreeCtrlModule CAATreeCtrl: public CATDlgContainer
{
  CATDeclareClass;

  public:

  // Standard constructors and destructors
  // -------------------------------------
     CAATreeCtrl (CATDialog*  iParent,const CATString& iObjectName, CATDlgStyle iStyle = NULL);
     virtual ~CAATreeCtrl ();

  // Copy constructor and equal operator
  // -----------------------------------
  CAATreeCtrl (CAATreeCtrl &);
  CAATreeCtrl& operator=(CAATreeCtrl&);


  //��õ�ǰ��ѡ��Ľڵ�
  void GetSelectedTreeNode (CATBaseUnknown ** pSelectedTreeNode);

  //ʹ���ؼ���һ���ڵ���Ϊѡ��״̬
  void SelectTreeNode (CATBaseUnknown * pTreeNode);


  //�õ������ڵ��������õĹ�������
  void GetTreeNodeData(CATBaseUnknown * pTreeNode, void **oContent);

  //�������ڵ��ϵĹ�������
  void SetTreeNodeData(CATBaseUnknown * pTreeNode, void * iContent);

  //�õ����ڵ���Ҽ������˵�
  CATDlgContextualMenu * GetTreeNodeContextualMenu(CATBaseUnknown * pTreeNode);


  //�õ����ڵ�����ʾ���ı�
  void GetTreeNodeText(CATBaseUnknown * pTreeNode, CATUnicodeString & oName);

  //�������ڵ�����ʾ���ı�
  void SetTreeNodeText(CATBaseUnknown * pTreeNode, const CATUnicodeString & iName);


  //Ϊ���ؼ�����һ�����ڵ�
  void AddRootTreeNode(CATBaseUnknown * pTreeRootNode);

  void AddRootTreeNode(CATUnicodeString TreeNodeText, CATUnicodeString TreeNodeIcon);


  //Ϊ���ؼ����ӽڵ���ӽڵ�
  void AddChildTreeNode(CATBaseUnknown * pFatherTreeNode, CATBaseUnknown * pChildTreeNodeToAdd);

  void AddChildTreeNode(CATBaseUnknown * pFatherTreeNode, CATUnicodeString TextOfChildTreeNodeToAdd, CATUnicodeString TreeNodeIcon);


  //�����ؼ����Ƴ�һ�����ڵ�
  void RemoveTreeNode(CATBaseUnknown * pTreeNode);

  //�Ƴ����ؼ������нڵ�
  void RemoveAllTreeNode();

  //�õ��ڸ��ڵ㼶��Ϊ���ΪiTreeNodeRank�ĸ��ڵ�
  void GetRootTreeNodeAt(int iTreeNodeRank, CATBaseUnknown **  opTreeNodeObject);

  //�õ��ڸ��ڵ㼶��ĳ�ڵ�����
  void GetCertainRootTreeNodeLocate(int &oTreeNodeRank, CATBaseUnknown *ipTreeNodeObject);

  //�õ���pFatherTreeNode�������ΪiTreeNodeRank�Ľڵ�
  void GetChildTreeNodeAt(CATBaseUnknown * pFatherTreeNode, int iTreeNodeRank, CATBaseUnknown **  opTreeNodeObject);

  //�õ���pFatherTreeNode����ĳ�ڵ�����
  void GetCertainChildTreeNodeLocate(CATBaseUnknown * pFatherTreeNode, int &oTreeNodeRank, CATBaseUnknown * ipTreeNodeObject);

  //�õ���pTreeNode�ڵ�ĸ��ڵ�
  void GetFatherTreeNode(CATBaseUnknown * pTreeNode, CATBaseUnknown ** opFatherTreeNode);

  //�õ���pTreeNode�ڵ����һ���ֵܽڵ�
  void GetNextSiblingTreeNode(CATBaseUnknown * pTreeNode, CATBaseUnknown **opSiblingTreeNode);

  //�õ���pTreeNode�ڵ����һ���ֵܽڵ�
  void GetPrevSiblingTreeNode(CATBaseUnknown * pTreeNode, CATBaseUnknown **opSiblingTreeNode);

  //�õ���pTreeNode�ڵ����ӽڵ�����
  void GetChildTreeNodeCount(CATBaseUnknown * pTreeNode, int * oCount);

  //�õ����ؼ������и��ڵ�����
  void GetRootTreeNodeCount(int * oCount);

  //չ��һ���ڵ�
  void ExpandTreeNode (CATBaseUnknown * pTreeNode);



private:

  void OnTreeCtrlReSizeCB(CATCommand* cmd, CATNotification* evt, CATCommandClientData data);

  void OnTreeNodeSelectCB(CATCallbackEvent event, void * client, CATNotification * iNotification,
						CATSubscriberData data, CATCallback callback);

  void OnTreeNodeCxtMenuCB(CATCallbackEvent event, void * client, CATNotification * iNotification,
						CATSubscriberData data, CATCallback callback);


private:
	//CATIA CAA������ʾ��
	CATNavigBox * _pNavigBox;

	//�������ڵ���¼��������������ڵ���ؼ���ͨѶ
	CAATreeNodeEventAgent * _pTreeEventListener;

	//���ؼ��ĸ��ڵ�ָ���б�
	CATLISTP(CATBaseUnknown) * _pRootTreeNodeObjList;

};

//-----------------------------------------------------------------------

#endif
/*******************************************
   
   
   				@ Tree
				@ int binary
				@ Tree.h
						

********************************************/
#ifndef _TREE_H_
#define _TREE_H_

struct TreeNode {
	TreeNode* 	Left;
	TreeNode* 	Right;
	TreeNode*	Parent;
	int			Value;		
};

struct TreeHead {
	TreeNode* Next;	
};

typedef TreeHead* PTreeHead;
typedef TreeNode* PTreeNode;

#define _TREE_ROOT(T) (T->Next)
#define _TREE_LEFT(T) (T->Left)
#define _TREE_RIGHT(T) (T->Right)
#define _TREE_PARENT(T) (T->Parent)
#define _TREE_NODE_KEY(T) (T->Value)
#define _INIT_NODE(T,v) do\
				{\
					T->Left = NULL;\
					T->Right = NULL;\
					T->Parent = NULL;\
					T->Value = v;\
				}while(0)
#define _COPY_NODE(dest,src) do\
				{\
					dest->Left = src->Left;\
					dest->Right = src->Right;\
					dest->Value = src->Value;\
					dest->Parent = src->Parent;\
				}while(0)

extern int TreeInsert(PTreeHead head,PTreeNode node);
extern int MidTraverse(PTreeNode node);
extern PTreeHead TreeNew();
extern PTreeNode TreeSucceed(PTreeHead head);
extern PTreeNode TreeMin(PTreeNode node);
extern PTreeNode TreeMax(PTreeNode node);

#endif

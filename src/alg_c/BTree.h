/*******************************************
   
   
   				@ Black Tree
				@ int binary
				@ BlackTree.h
						

********************************************/
#ifndef _BLACK_TREE_H_
#define _BLACK_TREE_H_

enum COLOR {
	RED		=	1,
	BLACK	=	2,		
};

struct BTreeNode {
	BTreeNode* 	Left;
	BTreeNode* 	Right;
	BTreeNode* 	Parent;
	int			Value;
	int			Color;	
};

struct BTreeHead {
	BTreeNode* Next;	
};

typedef BTreeNode* PBTreeNode;
typedef BTreeHead* PBTreeHead;

PBTreeNode NIL = NULL;

#define _BTREE_PARENT(x) (x->Parent)
#define _BTREE_LEFT(x) (x->Left)
#define _BTREE_RIGHT(x) (x->Right)
#define _BTREE_VALUE(x) (x->Value)
#define _BTREE_COLOR(x) (x->Color)
#define _SET_BTREE_HEAD(head,x) (head->Next = x)
#define _IS_NIL(x) ((!x->Left && !x->Right)?true:false)

#define _INIT_BTREE_NODE(x) do\
				{\
					x->Left = NULL;\
					x->Right = NULL;\
					x->Color = BLACK;\
					x->Value = 0;\
					x->Parent = NULL;\
				}while(0)

// when x->right exist,you can left rotate
#define _LEFT_ROTATE(head,x) do\
			{\
				PBTreeNode y = _BTREE_RIGHT(x);\
				x->Right = y->Left;\
				y->Left->Parent = x;\
				y->Left = x;\
				y->Parent = x->Parent;\
				if(_BTREE_PARENT(x) && _BTREE_LEFT(_BTREE_PARENT(x)) == x) \
					x->Parent->Left = y;\
				else if(_BTREE_PARENT(x) && _BTREE_RIGHT(_BTREE_PARENT(x)) == x)\
					x->Parent->Right = y;\
				else\
					head->Next = y;\
				x->Parent = y;\
			}while(0)

// when x->left exist, you can right rotate
#define _RIGHT_ROTATE(head,x)	do\
			{\
				PBTreeNode y = _BTREE_LEFT(x);\
				x->Left = y->Right;\
				y->Right->Parent = x;\
				y->Right = x;\
				y->Parent = x->Parent;\
				if(_BTREE_PARENT(x) && _BTREE_LEFT(_BTREE_PARENT(x)) == x)\
					x->Parent->Left = y;\
				else if(_BTREE_PARENT(x) && _BTREE_RIGHT(_BTREE_PARENT(x)) == x)\
					x->Parent->Right = y;\
				else\
					head->Next = y;\
				x->Parent = y;\
			}while(0)

extern PBTreeHead BTreeNew();
extern int BTreeNIL(PBTreeNode p);
extern int BTreeInsert(PBTreeNode root,PBTreeNode node);
extern int BTreeMidTraverse(PBTreeNode root);
#endif

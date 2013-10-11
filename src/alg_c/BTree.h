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

typedef BTreeNode* PBTreeNode;

#define _BTREE_PARENT(x) (x->Parent)
#define _BTREE_LEFT(x) (x->Left)
#define _BTREE_RIGHT(x) (x->Right)
#define _INIT_BTREE_NODE(x) do\
				{\
					x->Left = NULL;\
					x->Right = NULL;\
					x-Color = RED;\
				}while(0)
// when y is x->right ,you can left rotate
#define _LEFT_ROTATE(x,y) do\
			{\
				x->Right = y->Left;\
				y->Left->Parent = x;\
				y->Left = x;\
				y->Parent = x->Parent;\
				if(_BTREE_LEFT(_BTREE_PARENT(x)) == x) {\
					x->Parent->Left = y;\
				} else {\
					x->Parent->Right = y;\
				}\
				x->Parent = y;\
			}while(0)
// when x is y->left , you can right rotate
#define _RIGHT_ROTATE(y,x)	do\
			{\
				y->Left = x->Right;\
				x->Right->Parent = y;\
				x->Parent = y->Parent;\
				if(_BTREE_LEFT(_BTREE_PARENT(y)) == y) {\
					y->Parent->Left = x;\
				} else {\
					y->Parent->Right = x;\
				}\
				y->Parent = x;\
			}while(0)

extern PBTreeNode BTreeNew();
extern PBTreeNode BTreeNIL(PBTreeNode p);
#endif

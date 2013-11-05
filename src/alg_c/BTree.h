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

typedef BTreeNode* pBTreeNode;
typedef BTreeHead* pBTreeHead;

// NIL是叶子节点，节点的颜色为黑，其他域为NULL
// 如果有需要，可以将NIL定义为实际存在的节点
// 下面所有的宏定义都包括了对NIL的处理(即，将NIL当成正常的节点)
pBTreeNode NIL = NULL;

#define _BTREE_PARENT(x) (x->Parent)
#define _BTREE_LEFT(x) (x->Left)
#define _BTREE_RIGHT(x) (x->Right)
#define _BTREE_VALUE(x) (x->Value)
#define _SET_BTREE_HEAD(head,x) (head->Next = x)
#define _IS_NIL(x) ((!x->Left && !x->Right)?true:false)
#define _BTREE_COLOR(x) ((x == NIL) ? BLACK:x->Color)
#define _SET_COLOR(x,color) do\
				{\
					if (x != NIL)\
						x->Color = color;\
				}while(0)
// when x->right exist,you can left rotate
#define _LEFT_ROTATE(head,x) do\
			{\
				pBTreeNode y = _BTREE_RIGHT(x);\
				x->Right = y->Left;\
				if(y->Left != NIL)\
					y->Left->Parent = x;\
				y->Left = x;\
				/*如果x不是变量而是_BTREE_PARENT(_BTREE_PARENT(z))*/\
				/*y->Parent的改变会连带改变_BTREE_PARENT(_BTREE_PARENT(z))*/\
				/*原因在于y = _BTREE_PARENT(z)*/\
				y->Parent = _BTREE_PARENT(x);\
				if(_BTREE_PARENT(x) != NIL && _BTREE_LEFT(_BTREE_PARENT(x)) == x) \
					x->Parent->Left = y;\
				else if(_BTREE_PARENT(x) != NIL && _BTREE_RIGHT(_BTREE_PARENT(x)) == x)\
					x->Parent->Right = y;\
				else\
					head->Next = y;\
				x->Parent = y;\
			}while(0)

// when x->left exist, you can right rotate
#define _RIGHT_ROTATE(head,x)	do\
			{\
				pBTreeNode y = _BTREE_LEFT(x);\
				x->Left = y->Right;\
				if(y->Right != NIL)\
					y->Right->Parent = x;\
				y->Right = x;\
				/*如果x不是变量而是_BTREE_PARENT(_BTREE_PARENT(z))*/\
				/*y->Parent的改变会连带改变_BTREE_PARENT(_BTREE_PARENT(z))*/\
				/*原因在于y = _BTREE_PARENT(z)*/\
				y->Parent = _BTREE_PARENT(x);\
				if(_BTREE_PARENT(x) == NIL)\
					head->Next = y;\
				else if(_BTREE_LEFT(_BTREE_PARENT(x)) == x)\
					x->Parent->Left = y;\
				else if(_BTREE_RIGHT(_BTREE_PARENT(x)) == x)\
					x->Parent->Right = y;\
				x->Parent = y;\
			}while(0)

extern pBTreeHead BTreeNew();
extern int BTreeNIL(pBTreeNode p);
extern int BTreeInsert(pBTreeNode root,pBTreeNode node);
extern int BTreeMidTraverse(pBTreeNode root);
extern int BTreeDel(pBTreeNode root,pBTreeNode node);
#endif

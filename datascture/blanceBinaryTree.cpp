#include <iostream>
using namespace std;
/************************************************************************/
/*                    平衡二叉树---AVL                                  */
/************************************************************************/
#define LH +1	//左高
#define EH  0	//等高
#define RH -1	//右高
typedef int ElemType;

//平衡二叉树节点结构
typedef struct BSTNode{
	//数据
	ElemType data;
	//节点的平衡因子
	int bf;
	//左右孩子指针
	struct BSTNode *lchild, *rchild;
}*PBSTree;

//对以*p为根的二叉排序树作右旋处理
void R_Rotate(PBSTree* p)
{
	//lc指向*p左子树根节点
	PBSTree lc = (*p)->lchild;
	//*p的左子树挂接lc的右子树
	(*p)->lchild = lc->rchild;
	lc->rchild = *p;
	*p = lc;
}

//对以*p为根的二叉排序树作左旋处理
void L_Rotate(PBSTree* p)
{
	//rc指向*p的右子树的根节点
	PBSTree rc = (*p)->rchild;
	//*P的右子树挂接rc的左子树
	(*p)->rchild = rc->lchild;
	rc->lchild = *p;
	*p = rc;
}

//对以指针T所指节点为根的二叉树作左平衡旋转处理
void LeftBalance(PBSTree* T)
{
	PBSTree lc, rd;
	//lc指向T左子树根节点
	lc = (*T)->lchild;
	//检查*T左子树的平衡度,并做相应处理
	switch (lc->bf)
	{
		//新节点插入在*T的左孩子的左子树上,要做单右旋处理
	case LH:
		(*T)->bf = lc->bf = EH;
		R_Rotate(T);
		break;
		//新节点插入在*T的左孩子的右子树上,要做双旋处理
	case RH:
		//rd指向*T左孩子的右子树根节点
		rd = lc->rchild;
		//修改*T及其左孩子的平衡因子
		switch (rd->bf)
		{
		case LH:
			(*T)->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		//对*T的左子树做左旋平衡处理
		L_Rotate(&(*T)->lchild);
		//对*T做右旋平衡处理
		R_Rotate(T);
		break;
	}
}

//对以指针T所指节点为根的二叉树作右平衡旋转处理
void RightBalance(PBSTree* T)
{
	PBSTree lc, rd;
	//lc指向*T的右子树的根节点
	lc = (*T)->rchild;
	//检查*T的右子树的平衡度,并做相应的平衡处理
	switch (lc->bf)
	{
		//新节点插入在*T的右孩子的右子树上,要做单左旋处理
	case RH:
		(*T)->bf = lc->bf = EH;
		L_Rotate(T);
		break;
		//新节点插入在*T的右孩子的左子树上,要做双旋处理
	case LH:
		//rd指向*T的右孩子的左子树根节点
		rd = lc->lchild;
		//修改*T及其右孩子的平衡因子
		switch (rd->bf)
		{
		case LH:
			(*T)->bf = EH;
			lc->bf = RH;
			break;
		case EH:
			(*T)->bf = lc->bf = EH;
			break;
		case RH:
			(*T)->bf = EH;
			lc->bf = LH;
			break;
		}
		rd->bf = EH;
		//对*T的右子树做左旋平衡处理
		R_Rotate(&(*T)->rchild);
		//对*T做左旋平衡处理
		L_Rotate(T);
		break;
	}
}

//往平衡二叉树中插入节点e
int InsertAVL(PBSTree* T, ElemType e, bool* taller)
{
	//如果是空树
	if ((*T) == NULL)
	{
		//创建新节点
		(*T) = new BSTNode;
		//平衡
		(*T)->bf = EH;
		//初始化
		(*T)->data = e;
		(*T)->lchild = NULL;
		(*T)->rchild = NULL;
		//插入新节点,树长高,置taller为true
		*taller = true;
	}
	//如果插入重复值,直接返回
	else if (e == (*T)->data)
	{
		*taller = false;
		return 0;
	}
	//待插入的值 小于 根节点
	else if (e < (*T)->data)
	{
		//值重复
		if (!InsertAVL(&(*T)->lchild, e, taller))
			return 0;
		//节点插入到左子树,左子树长高
		if (*taller)
		{
			//检查T的平衡度
			switch ((*T)->bf)
			{
				//原本左子树比右子树高,需要做平衡处理
			case LH:
				LeftBalance(T);
				*taller = false;
				break;
				//原本左右子树等高,现在左子树增高,使树增高
			case  EH:
				(*T)->bf = LH;
				*taller = true;
				break;
				//原本右子树比左子树高,现在左右子树等高
			case RH:
				(*T)->bf = EH;
				*taller = false;
				break;
			}
		}
	}
	//待插入的值 大于 根节点
	else
	{
		//值重复
		if (!InsertAVL(&(*T)->rchild, e, taller))
			return 0;
		//新节点已插入到T的右子树中, 右子树长高
		if (*taller)
		{
			//检查T的平衡度
			switch ((*T)->bf)
			{
				//原本左子树比右子树高,现在左右子树等高
			case LH:
				(*T)->bf = EH;
				*taller = false;
				break;
				//原本左右子树等高,现在右子树长高使树长高
			case EH:
				(*T)->bf = RH;
				*taller = true;
				break;
				//原本右子树比左子树高,需要做右平衡处理
			case  RH:
				RightBalance(T);
				*taller = false;
				break;
			}
		}
	}
	return 1;
}

//根据指定值查找节点
bool FindNode(PBSTree root, ElemType e, PBSTree* pos)
{
	//定义辅助指针变量,指向根节点
	PBSTree pt = root;
	//指针初始化
	(*pos) = NULL;
	//从根节点开始向下查找
	while (pt)
	{
		if (pt->data == e)
		{
			//找到节点，pos指向该节点并返回true
			(*pos) = pt;
			return true;
		}
		else if (pt->data > e)
		{
			//如果指定的值比根节点大,查找左子树
			pt = pt->lchild;
		}
		else
		{
			//如果指定的值比根节点小,查找右子树
			pt = pt->rchild;
		}
	}
	return false;
}

//中序遍历
void InorderTra(PBSTree root)
{
	//遍历左子树
	if (root->lchild != NULL)
	{
		InorderTra(root->lchild);
	}
	//访问根节点
	cout << root->data << " ";
	//遍历右子树
	if (root->rchild != NULL)
	{
		InorderTra(root->rchild);
	}
}

#if 1
int main()
{
	int i, nArr[] = { 4, 5, 7, 2, 1, 3, 6 };
	PBSTree root = NULL, pos;
	bool taller;
	for (i = 0; i<sizeof(nArr) / sizeof(int); i++)
	{
		InsertAVL(&root, nArr[i], &taller);
	}
	InorderTra(root);
	cout << endl << "start find 103 ..." << endl;
	if (FindNode(root, 103, &pos))
	{
		cout << "Find this Node " << pos->data << endl;
	}
	else
	{
		cout << "Not find this Node。" << endl;
	}

	cout << endl << "start find 7 ..." << endl;
	if (FindNode(root, 7, &pos))
	{
		cout << "Find this Node " << pos->data << endl;
	}
	else
	{
		cout << "Not find this Node" << endl;;
	}

	system("pause");
	return 0;
}
#endif

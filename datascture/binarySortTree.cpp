#include <iostream>
using namespace std;

//二叉查找树结点描述
typedef int KeyType;
typedef struct Node
{
    KeyType key;        //关键字  - int
    struct Node *left;  //左孩子指针
    struct Node *right; //右孩子指针
                        //struct Node * parent;
} Node, *PNode;

//往二叉查找树中插入结点
//插入的话，可能要改变根结点的地址，所以传的是二级指针
void insertBST(PNode *root, KeyType key)
{
    //初始化插入结点
    PNode p = new Node;
    p->key = key;
    p->left = p->right = NULL;
    //空树时，直接作为根结点
    if ((*root) == NULL)
    {
        *root = p;
        return;
    }
    //插入到当前结点（*root）的左孩子
    if ((*root)->left == NULL && (*root)->key > key)
    {
        (*root)->left = p;
        return;
    }
    //插入到当前结点（*root）的右孩子
    if ((*root)->right == NULL && (*root)->key < key)
    {
        (*root)->right = p;
        return;
    }
    //本次循环没有插入节点, 删除创建的节点
    delete p;
    //查找左子树
    if ((*root)->key > key)
    {
        insertBST(&(*root)->left, key);
    }
    //查找右子树
    else if ((*root)->key < key)
    {
        insertBST(&(*root)->right, key);
    }
}

//根据关键字删除某个结点,删除成功返回1,否则返回0
//如果把根结点删掉，那么要改变根结点的地址，所以传二级指针
bool deleteBST(PNode *root, KeyType key)
{
    //空树直接返回
    if (*root == NULL)
    {
        return false;
    }
    //如果找到值为key的节点
    if (key == (*root)->key)
    {
        PNode q, s; // 节点类型的指针
        //右子树空则只需重接它的左子树（待删结点是叶子也走此分支)
        if ((*root)->right == NULL)
        {
            //保存要删除的节点的地址
            q = *root;
            //左子树向上移动
            // 指针重新指向了其左子树的地址
            *root = (*root)->left;
            //删除节点,释放内存
            delete q;
        }
        //左子树为空,只需重接它的右子树
        else if ((*root)->left == NULL)
        {
            //保存要删除的节点的地址
            q = *root;
            //右子树向上移动
            *root = (*root)->right;
            //删除节点, 释放内存
            free(q);
        }
        //左右子树均不空
        else
        {
            //保存要删除的节点的地址
            q = *root;
            //保存待删除节点左孩子地址
            s = (*root)->left;
            //向右到尽头（找待删结点的前驱,按照中序遍历找到的节点是待删除节点的前驱）
            while (s->right)
            {
                // q为s的父节点
                q = s;
                s = s->right;
            }
            //s指向被删结点的直接前驱（将被删结点前驱的值取代被删结点的值）
            (*root)->key = s->key;
            //节点发生了下移,即root的左子树不是叶子节点
            if (q != *root)
            {
                //重接q的右子树
                q->right = s->left;
            }
            else
            {
                //q没有移动还是指向root
                //重接q的左子树
                q->left = s->left;
            }
            free(s);
        }
        return true;
    }
    //查找左子树
    else if (key < (*root)->key)
    {
        return deleteBST(&(*root)->left, key);
    }
    //查找右子树
    else if (key > (*root)->key)
    {
        return deleteBST(&(*root)->right, key);
    }
    return false;
}

//查找元素,找到返回关键字的结点指针，没找到返回NULL
PNode searchBST(PNode root, KeyType key)
{
    //没找到的话root为NULL
    if (root == NULL)
    {
        return NULL;
    }
    //查找右子树
    if (key > root->key)
    {
        return searchBST(root->right, key);
    }
    //查找左子树
    else if (key < root->key)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return root;
    }
}

//查找最小关键字,空树时返回NULL
PNode searchMinBST(PNode root)
{
    //空树
    if (root == NULL)
    {
        return NULL;
    }
    //找到最左的孩子
    if (root->left == NULL)
    {
        return root;
    }
    //一直往左孩子找，直到没有左孩子的结点
    else
    {
        return searchMinBST(root->left);
    }
}

//查找最大关键字,空树时返回NULL
PNode searchMaxBST(PNode root)
{
    //空树
    if (root == NULL)
    {
        return NULL;
    }
    //找到最右的孩子
    if (root->right == NULL)
    {
        return root;
    }
    //一直往右孩子找，直到没有右孩子的结点
    else
    {
        return searchMaxBST(root->right);
    }
}

//创建一棵二叉查找树
void createBST(PNode *root, KeyType *keyArray, int length)
{
    //逐个结点插入二叉树中
    for (int i = 0; i < length; i++)
    {
        insertBST(root, keyArray[i]);
    }
}

//中序遍历二叉排序树
void inorderTraversalBST(PNode root)
{
    if (root != NULL)
    {
        //遍历左子树
        inorderTraversalBST(root->left);
        //打印根节点
        cout << root->key << " ";
        //遍历右子树
        inorderTraversalBST(root->right);
    }
}

//创建二叉排序树以及遍历
void test01()
{
    PNode root = NULL;
    KeyType nodeArray[11] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    //创建二叉查找树
    cout << "正在创建二叉查找树..." << endl;
    createBST(&root, nodeArray, 11);
    cout << "二叉查找树创建完毕!!!" << endl
         << endl;

    //遍历二叉查找树
    cout << "中序遍历二叉查找树(升序排列):" << endl;
    inorderTraversalBST(root);
    cout << endl
         << endl;
}

//查找指定的节点，和插入过程类似
void test02()
{
    PNode root = NULL;
    KeyType nodeArray[11] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    //创建二叉查找树
    cout << "正在创建二叉查找树..." << endl;
    createBST(&root, nodeArray, 11);
    cout << "二叉查找树创建完毕!!!" << endl
         << endl;

    //遍历二叉查找树
    cout << "中序遍历二叉查找树(升序排列):" << endl;
    inorderTraversalBST(root);
    cout << endl
         << endl;

    cout << "中序遍历二叉树查找:" << endl;
    PNode node = searchBST(root, 17);
    if (node != NULL)
    {
        cout << "找到指定节点: " << node->key << endl;
    }
    else
    {
        cout << "没有找到指定的节点!!!" << endl;
    }
    cout << endl;
}

//查找极值
void test03()
{
    PNode root = NULL;
    KeyType nodeArray[11] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    //创建二叉查找树
    cout << "正在创建二叉查找树..." << endl;
    createBST(&root, nodeArray, 11);
    cout << "二叉查找树创建完毕!!!" << endl
         << endl;

    //遍历二叉查找树
    cout << "中序遍历二叉查找树(升序排列):" << endl;
    inorderTraversalBST(root);
    cout << endl
         << endl;

    //查找最小节点
    PNode minNode = searchMinBST(root);
    if (minNode != NULL)
    {
        cout << "找到最小值: " << minNode->key << endl;
    }
    else
    {
        cout << "这棵树为空树!!!" << endl;
    }
    cout << endl;

    //查找最大节点
    PNode maxNode = searchMaxBST(root);
    if (maxNode != NULL)
    {
        cout << "找到最大值: " << maxNode->key << endl;
    }
    else
    {
        cout << "这棵树为空树!!!" << endl;
    }
    cout << endl;
}

void test04()
{

    PNode root = NULL;
    KeyType nodeArray[11] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};

    //创建二叉查找树
    cout << "正在创建二叉查找树..." << endl;
    createBST(&root, nodeArray, 11);
    cout << "二叉查找树创建完毕!!!" << endl
         << endl;

    //遍历二叉查找树
    cout << "中序遍历二叉查找树(升序排列):" << endl;
    inorderTraversalBST(root);
    cout << endl
         << endl;

    //删除指定节点
    bool bl = deleteBST(&root, 18);
    if (bl)
    {
        cout << "删除节点成功!!!" << endl;
    }
    else
    {
        cout << "删除节点失败!!!" << endl;
    }
    //遍历二叉查找树
    cout << "中序遍历二叉查找树(升序排列):" << endl;
    inorderTraversalBST(root);
    cout << endl
         << endl;
}

int main()
{
    test01();

    test02();

    test03();

    test04();

    return 0;
}

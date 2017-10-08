/*
 * File Name: tree.cpp
 * Author: xuhaoguang (hgxu1993@163.com)
 * Created Time: Sat Sep 16 20:28:19 2017
 * copyright (c) 2017 for xuhaoguang. All Right Reserved
 * @brief: 
*/ 

#include <iostream>
#include <deque>
#include <stack>
using namespace std;

//二叉树节点
class BinTreeNode{
public:
    BinTreeNode(const int &item, 
                BinTreeNode *lPtr = NULL,
                BinTreeNode *rPtr = NULL
                ) : data(item), left(lPtr), right(rPtr){
    };
    
    ~BinTreeNode(){
        delete left;
        delete right;
    } 
    
    // 在函数体内声明和定义的函数会被自动编译为内联函数
    void set_data(int item){  //inline void set_data(int item){
        data = item;
    } 

    int get_data() const{
        return data;
    } 

    void set_left(BinTreeNode *t){
        left = t;
    } 

    BinTreeNode* get_left() const{
        return left;
    } 

    void set_right(BinTreeNode *t){
        right = t;
    } 

    BinTreeNode* get_right() const{
        return right;
    }

private:
    int data;
    BinTreeNode *left, *right;
};

// 二叉树
class BinTree{
public:
    BinTree(BinTreeNode *t = NULL) : root(t){
    };

    ~BinTree(){
        delete root;
    } 

    void set_root(BinTreeNode *t){
        root = t;
    } 

    BinTreeNode* get_root() const{
        return root;
    } 

    BinTreeNode* create_tree();

    //前序遍历
    void pre_order(BinTreeNode *t) const;

    //中序遍历
    void in_order(BinTreeNode *t) const;
    
    //后序遍历
    void post_order(BinTreeNode *t) const;

    //层次遍历
    void level_order(BinTreeNode *t) const;

    //求二叉树叶子节点的个数
    int get_leaf_num(BinTreeNode *t) const;

    //求二叉树高度
    int get_tree_height(BinTreeNode *t) const;

    //交换二叉树左右子树
    void swap_left_right(BinTreeNode *t);

    //判断节点是否在二叉树中
    bool is_in_tree(BinTreeNode *r, BinTreeNode *t) const;

    //求两个节点在二叉树中的最近公共祖先
    BinTreeNode* get_nearest_common_father(BinTreeNode *r, BinTreeNode *p1, BinTreeNode *p2) const;

    //打印路径：路径上的节点的Value之和为Sum
    void print_rout(BinTreeNode *r, int sum) const;

private:
    BinTreeNode *root;
}; 

//@briefs: 递归创建二叉树
//@parmas：
//@return：BinTreeNode 根节点
BinTreeNode* BinTree::create_tree(){
    char item;
    BinTreeNode *t, *t_l, *t_r;
    cin >> item; //61#23#45#
 
    if(item != '#'){// '#' means none node
        BinTreeNode *tmp = new BinTreeNode(item - 48);
        t = tmp;
        t_l = create_tree();
        t->set_left(t_l);
        t_r = create_tree();
        t->set_right(t_r);
        return t;
    }else{
        t = NULL;
        return t;
    } 
}

//@briefs: 前序遍历二叉树
//@parmas：BinTreeNode*
//@return：
void BinTree::pre_order(BinTreeNode *t) const{
   BinTreeNode* tmpNode = t;
   if(tmpNode != NULL){
       cout << tmpNode->get_data() << " ";
       pre_order(tmpNode->get_left());
       pre_order(tmpNode->get_right());
   } 
} 

//@briefs: 中序遍历二叉树
//@parmas：BinTreeNode*
//@return：
void BinTree::in_order(BinTreeNode *t) const{
   BinTreeNode* tmpNode = t;
   if(tmpNode != NULL){
       in_order(tmpNode->get_left());
       cout << tmpNode->get_data() << " ";
       in_order(tmpNode->get_right());
   } 
}

//@briefs: 后序遍历二叉树
//@parmas：BinTreeNode*
//@return：
void BinTree::post_order(BinTreeNode *t) const{
   BinTreeNode* tmpNode = t;
   if(tmpNode != NULL){
       post_order(tmpNode->get_left());
       post_order(tmpNode->get_right());
       cout << tmpNode->get_data() << " ";
   } 
}

//@briefs: 层次遍历二叉树
//@parmas：BinTreeNode*
//@return：
void BinTree::level_order(BinTreeNode *t) const{
    if(t == NULL){
        return;
    } 
    
    deque<BinTreeNode*> q;
    q.push_back(t);

    while(!q.empty()){
        BinTreeNode* pTmpNode = q.front();
        cout << pTmpNode->get_data() << " ";
        q.pop_front();

        if(pTmpNode->get_left() != NULL){
            q.push_back(pTmpNode->get_left());
        }
        
        if(pTmpNode->get_right() != NULL){
            q.push_back(pTmpNode->get_right());
        }
    } 
} 

//@briefs: 求二叉树叶子节点个数
//@parmas：BinTreeNode*
//@return：int
int BinTree::get_leaf_num(BinTreeNode *t) const{
    if(t == NULL){
        return 0;
    } 

    if(t->get_left() == NULL && t->get_right() == NULL){
        return 1;
    } 

    return get_leaf_num(t->get_left()) + get_leaf_num(t->get_right());
} 

//@briefs: 求二叉树树的高度
//@parmas：BinTreeNode*
//@return：int
int BinTree::get_tree_height(BinTreeNode *t) const{
    if(t == NULL){
        return 0;
    } 

    if(t->get_left() == NULL && t->get_right() == NULL){
        return 1;
    } 

    int l_height = get_tree_height(t->get_left());
    int r_height = get_tree_height(t->get_right());

    return l_height >= r_height ? l_height+1 : r_height+1;
} 

//@briefs: 交换二叉树左右子树
//@parmas：BinTreeNode*
//@return：
void BinTree::swap_left_right(BinTreeNode *t){
    if(t == NULL){
        return;
    } 

    BinTreeNode *pTmpNode = t->get_left();
    t->set_left(t->get_right());
    t->set_right(pTmpNode);
    
    swap_left_right(t->get_left());
    swap_left_right(t->get_right());
} 

//@briefs: 判断节点是否在二叉树中
//@parmas：BinTreeNode*, BinTreeNode*
//@return：bool
bool BinTree::is_in_tree(BinTreeNode *r, BinTreeNode *t) const{
    if(r == NULL){
        return false;
    }else if(r == t){
        return true;
    }else{
        bool has = false;
        if(r->get_left() != NULL){
            has = is_in_tree(r->get_left(), t);
        } 

        if(r->get_right() != NULL){
            has = is_in_tree(r->get_right(), t);
        } 

        return has;
    } 
} 

//@briefs: 获取二叉树中两个节点的最近公共祖先
//@parmas：BinTreeNode*, BinTreeNode*, BinTreeNode*, 
//@return：BinTreeNode*
BinTreeNode* BinTree::get_nearest_common_father(BinTreeNode *r, BinTreeNode *p1, BinTreeNode *p2) const{
    if(is_in_tree(p1, p2)){
        return p1;
    } 

    if(is_in_tree(p2, p1)){
        return p1;
    }

    bool p1_in_left, p1_in_right, p2_in_left, p2_in_right;
    p1_in_left = is_in_tree(r->get_left(), p1);
    p1_in_right = is_in_tree(r->get_right(), p1);
    p2_in_left = is_in_tree(r->get_left(), p2);
    p2_in_right = is_in_tree(r->get_right(), p2);

    if((p1_in_left && p2_in_right) || (p2_in_left && p1_in_right)){
        return r;
    }else if(p1_in_left && p2_in_left){
        return get_nearest_common_father(r->get_left(), p1, p2);
    }else if(p1_in_right && p2_in_right){
        return get_nearest_common_father(r->get_right(), p1, p2);
    }else{
        return NULL;
    } 
} 

//@briefs: 打印路径，满足路径中节点的value之和为sum
//@parmas：BinTreeNode*, int 
//@return：
stack<BinTreeNode *>dfs_s;
stack<BinTreeNode *>print_s;
void BinTree::print_rout(BinTreeNode *r,int sum)const{
    if(r == NULL)
    {
        return;
    }
    sum -= r->get_data();
    dfs_s.push(r);
    if(sum <= 0)
    {
        if(sum == 0)
        {
            while(!dfs_s.empty())
            {
                print_s.push(dfs_s.top());
                dfs_s.pop();
            }
            while(!print_s.empty())
            {
                cout<<print_s.top()->get_data()<<" ";
                dfs_s.push(print_s.top());
                print_s.pop();
            }
            cout<<endl;
        }
        sum += r->get_data();
        dfs_s.pop();
        return;
    }
 	print_rout(r->get_left(),sum);
 	print_rout(r->get_right(),sum);
    sum += r->get_data();
    dfs_s.pop();
}

int main(){
    BinTree *bintree;
    BinTreeNode *root = bintree->create_tree();
    //bintree->set_root(bintree->create_tree()); 
    //cout << "root value = " << bintree->get_root()->get_data() << endl;
    bintree->pre_order(root);
    cout << endl;
    
    bintree->in_order(root);
    cout << endl;

    bintree->post_order(root);
    cout << endl;

    bintree->level_order(root);
    cout << endl;

    cout << bintree->get_leaf_num(root) << endl;
    cout << bintree->get_tree_height(root) << endl;

    //bintree->swap_left_right(root);
    bintree->pre_order(root);
    cout << endl;
    
    bintree->in_order(root);
    cout << endl;

    bintree->post_order(root);
    cout << endl;

    bintree->level_order(root);
    cout << endl;
    
    BinTreeNode *p1 = root->get_left();
    BinTreeNode *p2 = root->get_right();
    //BinTreeNode *p1 = bintree->get_root()->get_left();
    //BinTreeNode *p2 = bintree->get_root()->get_right();
    //BinTreeNode *p3 = bintree->get_root()->get_right()->get_right()->get_right();
    
    BinTreeNode *p = bintree->get_nearest_common_father(root, p1, p2);
    cout << "nearest father of p1 and p2 is " << p->get_data() << endl;
    return 0;
} 

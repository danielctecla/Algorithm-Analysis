#include <iostream>
#include <vector>
#include <string>

#define endl '\n'
#define ll long long
#define lli long long int
#define ld long double
#define fore(i,a,b) for (int i = a; i < b; i++)
#define forr(i,a,b) for (int i = a; i > b; i--)
#define forn(i,n) for (int i = 0; i < n; i++)
#define fi first
#define se second
#define pb push_back
#define all(v) v.begin(), v.end()
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeFromList(vector<int>& values, int index) {
    if (index >= values.size() || values[index] == -1) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(values[index]);
    root->left = buildTreeFromList(values, 2 * index + 1);
    root->right = buildTreeFromList(values, 2 * index + 2);
    return root;
}

void printTree(TreeNode* root, int depth = 0, char prefix = ' ') {
    if (root != nullptr) {
        printTree(root->right, depth + 1, '/');
        cout <<string(4 * depth, ' ') << prefix << "-- " << root->val << endl;
        printTree(root->left, depth + 1, '\\');
    }
}

void pushTwoNewNodes (vector<int> &values){
    values[values.size()-1] = 2;
    values.push_back(2);
    values.push_back(4);
}
/*  ---------------------------------ALGORITMO DEL SEGUNDO MÍNIMO DE UN ARBOL BINARIO------------------------------- */
int sol(TreeNode* node,int &value,int *a){
    (*a)++;
    if(node->left == NULL){
        (*a)++;
        return node->val;
    }else{
        (*a)++;
        int l = sol( node->left, value, a);
        (*a)++;
        int r = sol( node->right, value, a);        
        
        (*a)++;
        if(l != value && r != value){
            (*a)++;
            (*a)++;
            return min(l,r);
        }else{
            (*a)++;
            return max( l, r);
        }             
    }
}

int findSecondMinimumValue(TreeNode* root,int *a) {
    int last = sol(root,root->val, a);
    return (last == root->val) ? -1:last;
}

int  main(){
    /*------------------- ALGORITMO POR CASOS -----------------------*/
    fast_io;
    vector<int> values = {2,2,2,2,4,2,3};
    int a = 0;
    TreeNode* root = buildTreeFromList(values, 0);
    cout<<"Arbol Binario: "<<endl;
    printTree(root);
    cout << "Input = [";
    forn(i,values.size()){
        cout << values[i];
        if (i < values.size() - 1) cout << ",";
    }
    cout << "]" <<endl;
    cout<<"Output: "<<findSecondMinimumValue(root,&a)<<endl<<endl;

    /*-------------------- PARTE DE ANALISIS-------------------------*/
    // cout<<"Contador de iteraciones para el algoritmo"<<endl<<endl;
    // vector<int> analysis = {2};
    // TreeNode* rt;
    // char Excel[]="Comportamiento.csv";
    // FILE *pOutput_ = fopen(Excel,"w");

    // forn(i,100){
    //     a = 0;
    //     pushTwoNewNodes(analysis);
    //     rt = buildTreeFromList(analysis, 0);
    //     cout << "Input = [";
    //     forn(i,analysis.size()){
    //         cout << analysis[i];
    //         if (i < analysis.size() - 1) cout << ",";
    //     }
    //     cout << "]" <<endl;
    //     cout<<"Output: "<<findSecondMinimumValue(rt,&a)<<endl;
    //     fprintf(pOutput_,"%d,%d\n",analysis.size(),a);
    // }
    // pOutput_ = fopen(Excel,"r");
    // fclose(pOutput_);
}


#include <iostream>

class preorder{
    int * inorder;
    int * postorder;
    int * in_idx;
    int n;
    
public:
    preorder(int n){
        this->n = n;
        
        inorder = new int[n];
        in_idx = new int[n+1];
        for(int i = 0; i < n; i++){
            std::cin >> inorder[i];
            in_idx[inorder[i]] = i;
        }
        
        postorder = new int[n];
        for(int i = 0; i < n; i++){
            std::cin >> postorder[i];
        }
    } 
    
    void make_preorder(int s1, int e1, int s2, int e2){
        int root = postorder[e2];
        std::cout << root << " ";
        
        int r_idx = in_idx[root];
        
        if(r_idx > s1){
            make_preorder(s1, r_idx-1, s2, s2 + (r_idx-1) - s1);
        }
        
        if(r_idx < e1){ 
            make_preorder(r_idx+1, e1, e2-1 - (e1 - (r_idx+1)), e2-1);
        }
    }
    
};




int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    
   preorder pr = preorder(n);
    
    pr.make_preorder(0, n-1, 0, n-1);
    
    std::cout << "\n";
    
    return 0;
}
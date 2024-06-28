#include "fichier.h"
#include "expr.h"

int Exprinterro(struct element_token_valeur ** element_token, struct Node * root){
    int valider = 1;   
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    // EXPRINT -> EXPR .
     if ((*element_token)->tokenCodageId == 53 || (*element_token)->tokenCodageId == 20 || (*element_token)->tokenCodageId == 47 || (*element_token)->tokenCodageId == 54 || (*element_token)->tokenCodageId == 56 || (*element_token)->tokenCodageId == 57 || (*element_token)->tokenCodageId == 61 || (*element_token)->tokenCodageId == 19 || (*element_token)->tokenCodageId == 22 || (*element_token)->tokenCodageId == 39){
        root->children[0] = createNode("EXPR", root);
                 root->numChildren = 1;

        return Expr(element_token, root->children[0]);
        
    }
    root->numChildren = 0;
    return valider;
}
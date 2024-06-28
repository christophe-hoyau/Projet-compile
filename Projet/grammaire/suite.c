#include "fichier.h"
#include "expr.h"

int Suite(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider =1;

    
    //SUITE ->  .

    // SUITE -> ':=' EXPR  ';' .  
    // :=
    if ((*element_token)->tokenCodageId == 11){
    root->children[0] = createNode(":=", root);
        (*element_token) = (*element_token)->next;
    // EXPR
    root->children[1] = createNode("EXPR", root);
    valider = Expr(element_token, root->children[1]);
    if (valider == -1){
        return -1;
    }
    (*element_token) = (*element_token)->next;
    if((*element_token)->tokenCodageId == 5){
        root->children[2] = createNode(";", root);
        (*element_token) = (*element_token)->next;
        root->numChildren = 3;
        return valider;
    }
    }
    return valider;
    
    }
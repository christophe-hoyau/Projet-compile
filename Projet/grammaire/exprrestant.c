#include "fichier.h"
#include "expr.h"
#include "operateur.h"

int Exprrestant(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider=1;
   
    //EXPRRESTANT -> OPERATEUR EXPR
    // si on a -, =, /=, <, <=, >, >=, +, *, /, rem, and alors on appelle la fonction Operateur
    if ((*element_token)->tokenCodageId == 39 || (*element_token)->tokenCodageId == 32 || (*element_token)->tokenCodageId == 33 || (*element_token)->tokenCodageId == 34 || (*element_token)->tokenCodageId == 35 || (*element_token)->tokenCodageId == 36 || (*element_token)->tokenCodageId == 37 || (*element_token)->tokenCodageId == 38 || (*element_token)->tokenCodageId == 40 || (*element_token)->tokenCodageId == 41 || (*element_token)->tokenCodageId == 42 || (*element_token)->tokenCodageId == 43){
        root->children[0] = createNode("OPERATEUR", root);
        valider = Operateur(element_token, root->children[0]);
        if (valider == -1){
            return -1;
        }
        root->children[1] = createNode("EXPR", root);
            root->numChildren = 2;
        // Appel de la fonction Expr
       return Expr(element_token, root->children[1]);
    
    }
    root->numChildren = 0;
    return valider;
}
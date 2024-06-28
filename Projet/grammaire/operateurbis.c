#include "fichier.h"
#include "operateurter.h"

int Operateurbis(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider = 1;
    // OPERATEURBIS -> then
    if ((*element_token)->tokenCodageId == 44){
        root->children[0] = createNode("then", root);
        (*element_token) = (*element_token)->next;
        root->numChildren = 1;
        return valider;
    }
    // OPERATEURBIS -> or OPERATEURTER 
    else if ((*element_token)->tokenCodageId == 45){
        root->children[0] = createNode("or", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("OPERATEURTER", root);
        valider = Operateurter(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }
        root->numChildren = 2;
       
    }
    return valider;
}
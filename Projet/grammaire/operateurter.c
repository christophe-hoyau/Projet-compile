#include "fichier.h"

int Operateurter(struct element_token_valeur ** element_token, struct Node * root){
    int valider = 1;
    // OPERATEURTER -> else 
    if ((*element_token)->tokenCodageId == 27){
        root->children[0] = createNode("else", root);
        (*element_token) = (*element_token)->next;
        root->numChildren = 1;
        return valider;
    }
    root->numChildren = 0;
    return valider;
}
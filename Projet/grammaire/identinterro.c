#include "fichier.h"

int Identinterro(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(1 * sizeof(struct Node*));
    int valider=1;
    if ((*element_token)->tokenCodageId==53){
        root->children[0] = createNode((*element_token)->valeur[0], root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    root->numChildren = 0;
    return valider;
}
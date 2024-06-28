#include "fichier.h"
#include "declter.h"

int Declbis(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider = 1;
    // DECLBIS ->  ;
    if ((*element_token)->tokenCodageId == 5){
        (*element_token) = (*element_token)->next;
        root->numChildren = 0;
        return valider;
    }
    // DECLBIS -> is DECLTER
    if ((*element_token)->tokenCodageId == 4){
        root->children[0] = createNode("is", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("DECLTER", root);
        root->numChildren = 2;
        valider = Declter(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }
    }
    return valider;
}
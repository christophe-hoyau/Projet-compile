#include "fichier.h"

int Identpoint(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider=1;
    if ((*element_token)->tokenCodageId==46){
        root->children[0] = createNode(".", root);
        (*element_token) = (*element_token)->next;
        if ((*element_token)->tokenCodageId != 53){
            printf(GREEN"Erreur : il faut un ident \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        root->children[1] = createNode((*element_token)->valeur[0], root);
        root->numChildren = 2;
        (*element_token) = (*element_token)->next;
        return Identpoint(element_token, root->children[1]);
        
    }
    root->numChildren = 0;
    return valider;
}
#include "fichier.h"

int Type(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(sizeof(struct Node*));
    int valider=1;
    
    if ((*element_token)->tokenCodageId != 53 && (*element_token)->tokenCodageId != 47 && 
    (*element_token)->tokenCodageId != 48 && 
    (*element_token)->tokenCodageId != 49 && 
    (*element_token)->tokenCodageId != 50){
        printf(GREEN"Erreur : il faut un type \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;  
    }
    root->children[0] = createNode((*element_token)->valeur[0], root);
    root->numChildren = 1;
    (*element_token) = (*element_token)->next;

    return valider;
}
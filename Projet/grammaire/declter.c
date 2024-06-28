#include "fichier.h"
#include "champsplus.h"

int Declter(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(4 * sizeof(struct Node*));
    int valider = 1;
    // DECLTER -> record CHAMPSPLUS end record ';'

    if ((*element_token)->tokenCodageId!= 8){
        printf(GREEN"Erreur : il faut un 'record' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    root->children[0] = createNode("record", root);
    
    (*element_token) = (*element_token)->next;
    root->children[1] = createNode("CHAMPSPLUS", root);
    valider = Champsplus(element_token, root->children[1]);
    if (valider == -1){
        return -1;
    }

    if ((*element_token)->tokenCodageId != 9){
        printf(GREEN"Erreur : il faut un 'end' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    } 
    root->children[2] = createNode("end", root);
    (*element_token) = (*element_token)->next;
    
    if ((*element_token)->tokenCodageId != 8){
        printf(GREEN"Erreur : il faut un 'record' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    root->children[3] = createNode("record", root);
    (*element_token) = (*element_token)->next;
    if ((*element_token)->tokenCodageId != 5){
        printf(GREEN"Erreur : il faut un ';' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    root->children[4] = createNode(";", root);
    root->numChildren = 5;
    (*element_token) = (*element_token)->next;

    return valider;
}
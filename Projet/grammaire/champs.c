#include "fichier.h"
#include "type.h"


int Champs(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(40 * sizeof(struct Node*));
    int valider = 1;
    // CHAMPS -> IDENTPLUSVIRGULE ':' TYPE ';'
    int a=0; // a =1 si on a un ident et 0 si ,
    int b=0;
    while ((*element_token)->tokenCodageId==53 || (*element_token)->tokenCodageId==5){

        if ((*element_token)->tokenCodageId==53 && a==0){
            a=1;
            root->children[b] = createNode("IDENTPLUSVIRGULE", root);
            b++;
            (*element_token) = (*element_token)->next;
        }
        else if ((*element_token)->tokenCodageId==5 && a==1){
            a=0;
            root->children[b] = createNode(":", root);
            b++;
            (*element_token) = (*element_token)->next;
        }
        else{
            printf(GREEN"Erreur : il faut un ident ou une virgule \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
    }
    if (a==0){
        printf(GREEN"Erreur : il faut un ident  \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }

    if ((*element_token)->tokenCodageId!=10){
        printf(GREEN"Erreur : il faut un ':' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    root->children[b] = createNode(":", root);
    (*element_token) = (*element_token)->next;
    root->children[b+1] = createNode("TYPE", root);
    valider = Type(element_token,root->children[b+1]);
    if (valider == -1){
        return -1;
    }

    if ((*element_token)->tokenCodageId!=5){
        printf(GREEN"Erreur : il faut un ';' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        
        return -1;
    }
    root->children[b+2] = createNode(";", root);
    root->numChildren = b+3;
    (*element_token) = (*element_token)->next;
    return valider;
}
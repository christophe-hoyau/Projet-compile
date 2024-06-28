#include "fichier.h"
#include "expr.h"
#include "instrplus.h"

int Boucle1(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(4 * sizeof(struct Node*));
    int valider =1 ;
    // BOUCLE1 ->  elsif EXPR then INSTRPLUS  BOUCLE1
    
    if ((*element_token)->tokenCodageId == 26){
    root->children[0] = createNode("elsif", root);
    // elsif
    if ((*element_token)->tokenCodageId != 26){
        printf(GREEN"Erreur : il faut un 'elsif' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    // EXPR
    (*element_token) = (*element_token)->next;
    root->children[1] = createNode("EXPR", root);
    valider = Expr(element_token, root->children[1]);
    if (valider == -1){
        return -1;
    }
    // then
    if ((*element_token)->tokenCodageId != 27){
        printf(GREEN"Erreur : il faut un 'then' \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;
    }
    root->children[2] = createNode("then", root);
    // INSTRPLUS
    (*element_token) = (*element_token)->next;
    root->children[3] = createNode("INSTRPLUS", root);
    valider = Instrplus(element_token, root->children[3]);
    if (valider == -1){
        return -1;
    }

    
    if ((*element_token)->tokenCodageId == 26){
        root->children[4] = createNode("BOUCLE1", root);
        root->numChildren = 5;
        valider = Boucle1(element_token, root->children[4]);
        if (valider == -1){
            return -1;
        }
    }
    
    }
    root->numChildren = 0;
    
return valider;
}
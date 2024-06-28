#include "fichier.h"
#include "parampluspointvirgule.h"

int Paramsinterro(struct element_token_valeur ** element_token, struct Node * root){

    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider =1;

    // si ce n'est pas un return ou ( alors on return -1
    if ((*element_token)->tokenCodageId != 14 && (*element_token)->tokenCodageId != 20){
        printf(GREEN"Erreur : il faut un return ou un ( \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
        return -1;  
    }
    // si c'est un return alors Paramsinterro -> epsilon
    else if ((*element_token)->tokenCodageId == 14){
        root->numChildren = 0;
        return valider;
    }
    // PARAMSINTERRO -> PARAMS .
    else if ((*element_token)->tokenCodageId==20){
        root->children[0] = createNode("PARAMS", root);
        (*element_token) = (*element_token)->next;
        
        // changer l'adresse de element_token
        if ((*element_token)->tokenCodageId != 53){
            printf(GREEN"Erreur : il faut un ident \n Ligne : %d\n Colonne : %d\n"RESET,(*element_token)->line,(*element_token)->column);
            return -1;
        }
        
        else {
            root->children[1] = createNode("PARAMPLUSPOINTVIRGULE", root);
            root->numChildren = 2;

        valider = Parampluspointvirgule(element_token, root->children[0]);
        if (valider == -1){
            return -1;
        }
        }
    }
    return valider;
}
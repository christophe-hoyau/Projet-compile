#include "fichier.h"
#include "champs.h"
#include "champsplus.h"

int Champsplus(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider = 1;
    // CHAMPSPLUS -> CHAMPS CHAMPSPLUS2
    if ((*element_token)->tokenCodageId==53){
        root->children[0] = createNode("CHAMPS", root);
        valider = Champs(element_token,root->children[0]);
        if (valider==-1){
            return -1;
        }
        root->children[1] = createNode("CHAMPSPLUS2", root);
        valider = Champsplus(element_token,root->children[1]);
        if (valider==-1){
            return -1;
        }
        root->numChildren = 2;
    }
    return valider;
}
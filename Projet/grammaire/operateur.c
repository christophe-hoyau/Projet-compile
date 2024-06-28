#include "fichier.h"
#include "operateurbis.h"

int Operateur(struct element_token_valeur ** element_token, struct Node * root){
    root->children = (struct Node**)malloc(2*sizeof(struct Node*));
    int valider=1;
    // OPERATEUR -> '=' 
    if ((*element_token)->tokenCodageId==32){
        root->children[0] = createNode("=", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '/='
    else if ((*element_token)->tokenCodageId==33){
        root->children[0] = createNode("/=", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '<'
    else if ((*element_token)->tokenCodageId==34){
        root->children[0] = createNode("<", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '<='
    else if ((*element_token)->tokenCodageId==35){
        root->children[0] = createNode("<=", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '>'
    else if ((*element_token)->tokenCodageId==36){
        root->children[0] = createNode(">", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '>='
    else if ((*element_token)->tokenCodageId==37){
        root->children[0] = createNode(">=", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '+'
    else if ((*element_token)->tokenCodageId==38){
        root->children[0] = createNode("+", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '-'
    else if ((*element_token)->tokenCodageId==39){
        root->children[0] = createNode("-", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '*'
    else if ((*element_token)->tokenCodageId==40){
        root->children[0] = createNode("*", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> '/'
    else if ((*element_token)->tokenCodageId==41){
        root->children[0] = createNode("/", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> 'rem'
    else if ((*element_token)->tokenCodageId==42){
        root->children[0] = createNode("rem", root);
        root->numChildren = 1;
        (*element_token) = (*element_token)->next;
        return valider;
    }
    // OPERATEUR -> and OPERATEURBIS
    else if ((*element_token)->tokenCodageId==43){
        root->children[0] = createNode("and", root);
        (*element_token) = (*element_token)->next;
        root->children[1] = createNode("OPERATEURBIS", root);
        valider = Operateurbis(element_token, root->children[1]);
        if (valider == -1){
            return -1;
        }
        root->numChildren = 2;
        return valider;
    }
    return valider;
}
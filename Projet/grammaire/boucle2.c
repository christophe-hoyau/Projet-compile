#include "fichier.h"
#include "instrplus.h"

int Boucle2 ( struct element_token_valeur ** element_token, struct Node * root) {
    root->children = (struct Node**)malloc(2 * sizeof(struct Node*));
    int valider=1 ;
    // BOUCLE2 ->  else INSTRPLUS  
    if ((*element_token)->tokenCodageId == 27){
    
    root->children[0] = createNode("else", root);


    (*element_token) = (*element_token)->next;
    // INSTRPLUS
      root->children[1] = createNode("INSTRPLUS", root);
      root->numChildren = 2;
    return Instrplus(element_token, root->children[1]);
    
}
    root->numChildren = 0;
    return valider;
}
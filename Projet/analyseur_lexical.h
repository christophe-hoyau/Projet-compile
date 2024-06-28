#pragma once
#include "header.h"
#include <cairo.h>

#define MAX_LENGTH 1000
#define MAX_WORD_SIZE 20

struct element_token_valeur {
    int tokenCodageId;
    // la valeur est nul si c'est pas un string ou un entier ou une variable
    char * valeur[MAX_LENGTH]; // valeur[0] = valeur du token
    int line;
    int column;
    struct element_token_valeur * next;
};

struct linked_list_token_valeur {
    struct element_token_valeur * head;
};

// Structure pour représenter un nœud de l'arbre abstrait
 struct Node {
    char word[MAX_WORD_SIZE];
    struct Node** children;
    struct Node* parent;
    size_t numChildren;
};

int codage_token(ada_token_type tokenName);

//Fonction qui supprime les commentaires du fichier source en Ada 

void supprimer_commentaires(FILE* fichier_entree, FILE* fichier_sortie); 

//Fonction qui prends un mot et le compare avec les mots d'une liste et renvoie l'index du token correspondant

int comparer_mot(const char* mot, const char** liste_mots, const int* liste_indices, int taille_liste); 

// Fonction qui utilise la fonction comparer_mot pour comparer un mot avec les différents types de tokens et renvoie l'index du token correspondant sinon -1
int index_token_word( char* mot);
//Fonction qui renvoie 1 si c’est un float et -1 sinon
int estUnFloat(char*mot);

//Fonction qui renvoie 1 si c’est un entier et -1 sinon
int estUnEntier(char*mot);



//Fonction qui renvoie 1 si c'est un char et -1 sinon
int estUnChar(char*mot);

//Fonction qui renvoie 1 si c'est un boolean et -1 sinon
int estUnBoolean(char*mot);

//fonction qui lit les mots du fichier 
void litMotFichier(FILE* fichier, struct linked_list_token_valeur * list_token);



//Creer la fonction afficher liste des tokens ligne par ligne 
void afficher_liste_tokens(struct linked_list_token_valeur * list_token);

// retourne la longueur de la liste
int longueur_liste_token(struct linked_list_token_valeur * list_token);

struct Node * createNode(const char* word, struct Node* parent);

void drawTree(struct Node* root, cairo_t* cr, double x, double y, double level);

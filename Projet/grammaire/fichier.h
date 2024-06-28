#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <assert.h>
#include "../analyseur_lexical.h"


#define RED   "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE  "\033[1;34m"
#define RESET "\033[0m"

// fonction fichier qui prend en entrée un tableau d'entier et renvoie un 1 si ça marche et -1 sinon
int Fichier(struct linked_list_token_valeur * list_token, struct Node * root);
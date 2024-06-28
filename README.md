# Projet Compilation - Langage Ada

Ce projet est une application Ada qui nécessite la bibliothèque Cairo afin d'afficher l'arbre. Assurez-vous de suivre les instructions ci-dessous pour compiler et exécuter le programme avec succès.

De plus, afin de visualiser l'arbre, il faut que votre éditeur de code ait un color thème clair.

## Prérequis

- Cairo (la bibliothèque de rendu graphique)

## Compilation

Avant de compiler le projet, assurez-vous d'avoir installé cairo. 

Sur macOS : 
            
            brew install cairo 

            brew install pkg-config

Sur linux : 
            
            apt install cairo 

            apt install pkg-config

Pour trouver votre chemin après installation de cairo : pkg-config --libs cairo

### Configuration de la bibliothèque Cairo

Avant de compiler, veuillez modifier le chemin de la bibliothèque Cairo dans le fichier `makefile` :

```makefile
# makefile
# Changer le chemin de la librairie Cairo ci-dessous
CFLAGS = -Wall -Wextra -Werror -I/opt/homebrew/opt/ncurses/include -I/opt/homebrew/Cellar/cairo/1.18.0/include/cairo


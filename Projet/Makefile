CC = gcc
CFLAGS = -Wall -Wextra -Werror -I/usr/local/Cellar/cairo/1.18.0/include -I/usr/local/Cellar/cairo/1.18.0/include/cairo
NAME = main
SRC = main.c analyseur_lexical.c grammaire/fichier.c grammaire/declstar.c grammaire/decl.c grammaire/type.c grammaire/suite.c grammaire/expr.c grammaire/paramsinterro.c grammaire/parampluspointvirgule.c grammaire/instrplus.c grammaire/instr.c grammaire/exprsimple.c grammaire/expracces.c grammaire/exprplusvirgule.c grammaire/identpoint.c grammaire/exprrestant.c grammaire/operateur.c grammaire/operateurbis.c grammaire/operateurter.c grammaire/instrbis.c  grammaire/declter.c grammaire/declbis.c grammaire/champs.c  grammaire/champsplus.c grammaire/boucle1.c grammaire/boucle2.c grammaire/identinterro.c grammaire/exprinterro.c
OBJ = $(SRC:.c=.o)

CAIRO_CFLAGS = $(shell pkg-config --cflags cairo)
CAIRO_LIBS = $(shell pkg-config --libs cairo)

.PHONY: all run clean

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(CAIRO_CFLAGS) -o $(NAME) $(OBJ) $(CAIRO_LIBS)

run: $(NAME)
	./$(NAME)

clean:
	rm -f $(OBJ) $(NAME)

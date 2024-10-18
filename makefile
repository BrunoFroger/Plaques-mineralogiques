#############################################################
#                   M a k e f i l e 
# 
#     généré automatiquement le 16/09/2024 à 16:21:50
#         avec buildMakefile (version du  2 Sep 2023)
#                 (c) B. Froger 
# 
#############################################################

#------------------------------------------------------------
# Définition des variables
#------------------------------------------------------------
# de compilation
CC=g++
CCFLAGS=-Werror -Wall 
LDFLAGS= 

# de definition des répertoires
SRCDIR=src
INCDIR=inc
OBJDIR=obj
BINDIR=bin
INSTALLDIR=~/bin

# de definition des listes de fichiers a traiter
SRCCPP=$(wildcard $(SRCDIR)/*.cpp)
SRCC=$(wildcard $(SRCDIR)/*.c)
TMPCPP=$(patsubst %.cpp, %.o, $(SRCCPP))
TMPC=$(patsubst %.c, %.o, $(SRCC))
TMP=$(TMPCPP) $(TMPC)
OBJ=$(patsubst $(SRCDIR)/%.o, $(OBJDIR)/%.o, $(TMP))
EXEC = $(BINDIR)/calculPlaques

# des autres variables
ENTETE = $(info ******************************) $(info *) $(info *   M A K E (calculPlaques)) $(info *) $(info ******************************)

#------------------------------------------------------------
# Définition des règles génériques
#------------------------------------------------------------
ALL : $(info $(ENTETE)) $(EXEC)

$(EXEC): $(OBJ)
	@$(CC) $(LDFLAGS) $(OBJ) -o $@
	@echo "Edition de lien de $@ OK"

#------------------------------------------------------------
# Définition des règles pour chaque fichier source
#------------------------------------------------------------
$(OBJDIR)/affichePlaque.o: $(SRCDIR)/affichePlaque.cpp \
	$(INCDIR)/plaque.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/analyseParametres.o: $(SRCDIR)/analyseParametres.cpp \
	$(INCDIR)/checkValidite.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/calculPlaque.o: $(SRCDIR)/calculPlaque.cpp \
	$(INCDIR)/plaque.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/checkBlocChiffres.o: $(SRCDIR)/checkBlocChiffres.cpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/checkBlocLettres.o: $(SRCDIR)/checkBlocLettres.cpp \
	$(INCDIR)/checkBlocLettres.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/checkValidite.o: $(SRCDIR)/checkValidite.cpp \
	$(INCDIR)/plaque.hpp \
	$(INCDIR)/decomposePlaque.hpp \
	$(INCDIR)/checkBlocLettres.hpp \
	$(INCDIR)/checkBlocChiffres.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/decomposePlaque.o: $(SRCDIR)/decomposePlaque.cpp \
	$(INCDIR)/plaque.hpp \
	$(INCDIR)/affichePlaque.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp \
	$(INCDIR)/checkValidite.hpp \
	$(INCDIR)/tests.hpp \
	$(INCDIR)/analyseParametres.hpp \
	$(INCDIR)/calculPlaque.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

$(OBJDIR)/tests.o: $(SRCDIR)/tests.cpp \
	$(INCDIR)/checkValidite.hpp \
	$(INCDIR)/decomposePlaque.hpp \
	$(INCDIR)/plaque.hpp \
	$(INCDIR)/checkBlocLettres.hpp \
	$(INCDIR)/checkBlocChiffres.hpp
	@$(CC) $(CCFLAGS) $< -c -o $@
	@echo "Compilation de $< OK"

#------------------------------------------------------------
# Définition des règles utilitaires
#------------------------------------------------------------
clean: 
	@rm -f $(OBJDIR)/* $(BINDIR)/*
	@echo "Clean OK"

info: 
	@echo "Liste des variables du makefile"
	@echo "CC         = " $(CC)
	@echo "CCFLAGS    = " $(CCFLAGS)
	@echo "LDFLAGS    = " $(LDFLAGS)
	@echo "SRCDIR     = " $(SRCDIR)
	@echo "INCDIR     = " $(INCDIR)
	@echo "OBJDIR     = " $(OBJDIR)
	@echo "BINDIR     = " $(BINDIR)
	@echo "INSTALLDIR = " $(INSTALLDIR)
	@echo "SRCCPP     = " $(SRCCPP)
	@echo "SRCC       = " $(SRCC)
	@echo "TMPCPP     = " $(TMPCPP)
	@echo "TMPC       = " $(TMPC)
	@echo "TMP        = " $(TMP)
	@echo "OBJ        = " $(OBJ)
	@echo "EXEC       = " $(EXEC)

install: 
	@make
	@rm -f $(INSTALLDIR)/calculPlaques
	@cp -f $(BINDIR)/calculPlaques ~/bin
	@chmod +x $(INSTALLDIR)/calculPlaques
	@echo "installation de calculPlaques dans ~/bin OK"

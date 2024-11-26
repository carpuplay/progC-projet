 # Variables
CC = gcc                 # Compilateur
CFLAGS = -Wall 
OBJ = testdate.o date.o evenement.o     # Fichiers objets nécessaires
TARGET = program         # Nom de l'exécutable final

# Règle principale : créer l'exécutable
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Règle pour compiler main.o
testdate.o: testdate.c date.h
	$(CC) $(CFLAGS) -c testdate.c

# Règle pour compiler date.o
date.o: date.c date.h
	$(CC) $(CFLAGS) -c date.c

evenement.o: evenement.c evenement.h date.h
	$(CC) $(CFLAGS) -c evenement.c

# Nettoyer les fichiers générés
clean:
	rm -f $(OBJ) $(TARGET)

# Règle phony pour éviter les conflits avec des fichiers nommés "clean"
.PHONY: clean

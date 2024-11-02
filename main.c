#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char titre[50];
    char description[100];
    char date_echeance[11]; // Format : AAAA-MM-JJ
    int priorite;
} Tache; // D�finition de la structure

// Fonction pour valider le format et la validit� de la date
bool validerDate(char date[]) {
    int annee, mois, jour;
    if (sscanf(date, "%d-%d-%d", &annee, &mois, &jour) != 3) {
        return false; // Pas au bon format
    }

    // Validation de l'ann�e, du mois et du jour
    if (annee < 2024) return false; // L'ann�e doit �tre 2024 ou plus
    if (mois < 1 || mois > 12) return false;
    if (jour < 1 || jour > 31) return false;

    // V�rification suppl�mentaire pour les jours dans le mois (simplifi�e)
    if ((mois == 4 || mois == 6 || mois == 9 || mois == 11) && jour > 30) return false;
    if (mois == 2 && jour > 29) return false; // V�rification simplifi�e; ne valide pas correctement les ann�es bissextiles

    return true;
}

// Fonction pour ajouter une t�che
int ajouterTache(Tache taches[], int nombre_taches) {
    if (nombre_taches < 100) {
        printf("Entrez le titre de la tache : ");
        scanf(" %[^\n]", taches[nombre_taches].titre);
        printf("Entrez la description de la tache : ");
        scanf(" %[^\n]", taches[nombre_taches].description);

        // Boucle jusqu'� ce qu'une date valide soit entr�e
        while (true) {
            printf("Entrez la date d'echeance (AAAA-MM-JJ) : ");
            scanf(" %[^\n]", taches[nombre_taches].date_echeance);
            if (validerDate(taches[nombre_taches].date_echeance)) {
                break; // Date valide, sortir de la boucle
            } else {
                printf("Date invalide. Veuillez entrer une date valide au format AAAA-MM-JJ et a partir de 2024.\n");
            }
        }

        // Boucle jusqu'� ce qu'une priorit� valide soit entr�e
        while (true) {
            printf("Entrez la priorite de la tache (1 pour Haute, 0 pour Basse) : ");
            scanf("%d", &taches[nombre_taches].priorite);
            if (taches[nombre_taches].priorite == 0 || taches[nombre_taches].priorite == 1) {
                break; // Priorit� valide, sortir de la boucle
            } else {
                printf("Priorite invalide. Veuillez entrer 0 pour Basse ou 1 pour Haute.\n");
            }
        }

        nombre_taches++;
        printf("Tache ajoutee avec succes !\n");
    } else {
        printf("Limite de taches atteinte.\n");
    }
    return nombre_taches;
}

// Fonction pour afficher toutes les t�ches
void afficherTaches(Tache taches[], int nombre_taches) {
    if (nombre_taches == 0) {
        printf("Aucune tache disponible.\n");
    } else {
        for (int i = 0; i < nombre_taches; i++) {
            printf("Tache %d :\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Date d'echeance : %s\n", taches[i].date_echeance);
            printf("Priorite : %s\n", taches[i].priorite ? "Haute" : "Basse");
            printf("--------------------------\n");
        }
    }
}

// Fonction pour modifier une t�che existante
int modifierTache(Tache taches[], int nombre_taches) {
    int index;
    printf("Entrez le numero de la tache � modifier : ");
    scanf("%d", &index);
    if (index > 0 && index <= nombre_taches) {
        index--; // Ajustement pour l'index bas� sur 0
        printf("Entrez le nouveau titre : ");
        scanf(" %[^\n]", taches[index].titre);
        printf("Entrez la nouvelle description : ");
        scanf(" %[^\n]", taches[index].description);

        // Boucle jusqu'� ce qu'une date valide soit entr�e
        while (true) {
            printf("Entrez la nouvelle date d'echeance (AAAA-MM-JJ) : ");
            scanf(" %[^\n]", taches[index].date_echeance);
            if (validerDate(taches[index].date_echeance)) {
                break; // Date valide, sortir de la boucle
            } else {
                printf("Date invalide. Veuillez entrer une date valide au format AAAA-MM-JJ et a partir de 2024.\n");
            }
        }

        // Boucle jusqu'� ce qu'une priorit� valide soit entr�e
        while (true) {
            printf("Entrez la nouvelle priorite (1 pour Haute, 0 pour Basse) : ");
            scanf("%d", &taches[index].priorite);
            if (taches[index].priorite == 0 || taches[index].priorite == 1) {
                break; // Priorit� valide, sortir de la boucle
            } else {
                printf("Priorite invalide. Veuillez entrer 0 pour Basse ou 1 pour Haute.\n");
            }
        }

        printf("Tache modifiee avec succes !\n");
    } else {
        printf("Numero de tache invalide.\n");
    }
    return nombre_taches;
}

// Fonction pour supprimer une t�che
int supprimerTache(Tache taches[], int nombre_taches) {
    int index;
    printf("Entrez le numero de la tache � supprimer : ");
    scanf("%d", &index);
    if (index > 0 && index <= nombre_taches) {
        index--; // Ajustement pour l'index bas� sur 0
        for (int i = index; i < nombre_taches - 1; i++) {
            taches[i] = taches[i + 1]; // D�caler les t�ches vers la gauche
        }
        nombre_taches--; // R�duire le nombre de t�ches
        printf("Tache supprimee avec succes !\n");
    } else {
        printf("Numero de tache invalide.\n");
    }
    return nombre_taches;
}

// Fonction pour filtrer les t�ches par priorit�
void filtrerTachesParPriorite(Tache taches[], int nombre_taches) {
    if (nombre_taches == 0) {
        printf("Aucune tache disponible.\n");
        return;
    }
    int priorite_filtre, trouve = 0;
    printf("Entrez la priorite pour filtrer (1 pour Haute, 0 pour Basse) : ");
    scanf("%d", &priorite_filtre);
    printf("Taches avec priorite %s :\n", priorite_filtre ? "Haute" : "Basse");

    for (int i = 0; i < nombre_taches; i++) {
        if (taches[i].priorite == priorite_filtre) {
            printf("Tache %d :\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Date d'echeance : %s\n", taches[i].date_echeance);
            printf("--------------------------\n");
            trouve = 1;
        }
    }
    if (!trouve) {
        printf("Aucune tache trouvee avec priorite %s.\n", priorite_filtre ? "Haute" : "Basse");
    }
}

// Fonction principale pour ex�cuter l'application de gestion des t�ches
int main() {
    Tache taches[100]; // Augmenter la taille du tableau pour permettre jusqu'� 100 t�ches
    int nombre_taches = 0, choix = -1;

    while (choix != 6) {
        printf("Application de gestion des taches\n");
        printf("1. Ajouter une tache\n2. Afficher les taches\n3. Modifier une tache\n4. Supprimer une tache\n5. Filtrer les taches par priorite\n6. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choix);
        printf("-----------------------------\n");

        switch (choix) {
            case 1:
                nombre_taches = ajouterTache(taches, nombre_taches);
                break;
            case 2:
                afficherTaches(taches, nombre_taches);
                break;
            case 3:
                nombre_taches = modifierTache(taches, nombre_taches);
                break;
            case 4:
                nombre_taches = supprimerTache(taches, nombre_taches);
                break;
            case 5:
                filtrerTachesParPriorite(taches, nombre_taches);
                break;
            case 6:
                printf("Sortie...\n");
                break;
            default:
            printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    }
    return 0;
}

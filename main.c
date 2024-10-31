#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include <stdio.h>

typedef struct {
    char titre[50];
    char description[100];
    char due_date[11]; // Format : AAAA-MM-JJ
    int priority;
} Tache;

int addTask(Tache taches[], int task_count) {
    if (task_count < 100) {
        printf("Entrez le titre de la tache : ");
        scanf(" %[^\n]", taches[task_count].titre);
        printf("Entrez la description de la tache : ");
        scanf(" %[^\n]", taches[task_count].description);
        printf("Entrez la date d'echeance (AAAA-MM-JJ) : ");
        scanf(" %[^\n]", taches[task_count].due_date);
        printf("Entrez la priorite de la tache (1 pour Haute, 0 pour Basse) : ");
        scanf("%d", &taches[task_count].priority);
        task_count++;
        printf("Tache ajoutee avec succes !\n");
    } else {
        printf("Limite de taches atteinte.\n");
    }
    return task_count;
}

void displayTasks(Tache taches[], int task_count) {
    if (task_count == 0) {
        printf("Aucune tache disponible.\n");
    } else {
        for (int i = 0; i < task_count; i++) {
            printf("Tache %d :\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Date d'echeance : %s\n", taches[i].due_date);
            printf("Priorite : %s\n", taches[i].priority ? "Haute" : "Basse");
            printf("--------------------------\n");
        }
    }
}

int modifyTask(Tache taches[], int task_count) {
    int index;
    printf("Entrez le numero de la tache a modifier : ");
    scanf("%d", &index);
    if (index > 0 && index <= task_count) {
        index--; // Ajustement pour l'index basé sur 0
        printf("Entrez le nouveau titre : ");
        scanf(" %[^\n]", taches[index].titre);
        printf("Entrez la nouvelle description : ");
        scanf(" %[^\n]", taches[index].description);
        printf("Entrez la nouvelle date d'échéance (AAAA-MM-JJ) : ");
        scanf(" %[^\n]", taches[index].due_date);
        printf("Entrez la nouvelle priorité (1 pour Haute, 0 pour Basse) : ");
        scanf("%d", &taches[index].priority);
        printf("Tâche modifiée avec succès !\n");
    } else {
        printf("Numero de tache invalide.\n");
    }
    return task_count;
}

int deleteTask(Tache taches[], int task_count) {
    int index;
    printf("Entrez le numéro de la tâche à supprimer : ");
    scanf("%d", &index);
    if (index > 0 && index <= task_count) {
        index--; // Ajustement pour l'index basé sur 0
        for (int i = index; i < task_count - 1; i++) {
            taches[i] = taches[i + 1]; // Décaler les tâches vers la gauche
        }
        task_count--; // Réduire le nombre de tâches
        printf("Tache supprimee avec succes !\n");
    } else {
        printf("Numero de tache invalide.\n");
    }
    return task_count;
}

void filterTasksByPriority(Tache taches[], int task_count) {
    if (task_count == 0) {
        printf("Aucune tache disponible.\n");
        return;
    }
    int filter_priority, found = 0;
    printf("Entrez la priorite pour filtrer (1 pour Haute, 0 pour Basse) : ");
    scanf("%d", &filter_priority);
    printf("Taches avec priorite %s :\n", filter_priority ? "Haute" : "Basse");

    for (int i = 0; i < task_count; i++) {
        if (taches[i].priority == filter_priority) {
            printf("Tache %d :\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].description);
            printf("Date d'echeance : %s\n", taches[i].due_date);
            printf("--------------------------\n");
            found = 1;
        }
    }
    if (!found) {
        printf("Aucune tache trouvee avec priorite %s.\n", filter_priority ? "Haute" : "Basse");
    }
}

int main() {
    Tache taches[10];
    int task_count = 0, choice = -1;

    while (choice != 0) {
        printf("Application de gestion des taches\n");
        printf("1. Ajouter une tache\n2. Afficher les taches\n3. Modifier une tache\n4. Supprimer une tache\n5. Filtrer les taches par priorite\n6. Quitter\n");
        printf("Choisissez une option : ");
        scanf("%d", &choice);
        printf("-----------------------------\n");

        switch (choice) {
            case 1:
                task_count = addTask(taches, task_count);
                break;
            case 2:
                displayTasks(taches, task_count);
                break;
            case 3:
                task_count = modifyTask(taches, task_count);
                break;
            case 4:
                task_count = deleteTask(taches, task_count);
                break;
            case 5:
                filterTasksByPriority(taches, task_count);
                break;
            case 6:
                printf("Sortie...\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                break;
        }
    }
    return 0;
}





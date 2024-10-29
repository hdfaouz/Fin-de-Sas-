#include<stdio.h>
#include<stdlib.h>
#define max 50

typedef struct{
	int jour;
	int mois;
	int annee;
}date;

typedef struct{
	char titre[40];
	char description[100];
	date dt;
	char priorite[10];

}tache;




tache add(){
	tache ta;

	printf("entrer le titre de tache :");
	scanf("%s", &ta.titre);

	printf("entrer la description de tache :");
	scanf("%s", &ta.description);

	printf("entrer la date de tache\n");

	printf("jour :");
	scanf("%d", &ta.dt.jour);

	printf("mois :");
	scanf("%d", &ta.dt.mois);

	printf("annee :");
	scanf("%d", &ta.dt.annee);

	printf("entrer la priorite de tache");
	scanf("%s", &ta.priorite);

	return ta;
}


void afficher(tache ta){

	printf("\n Titre : %s\n", ta.titre);
    printf("\n description : %s\n", ta.description);
    printf("\n----date de creation----\n");
    printf("\n %d / %d / %d \n", ta.dt.jour,  ta.dt.mois,  ta.dt.annee);
    printf("\n priorite : %s\n", ta.priorite);
}


void edit(tache ta[], int index){

	printf("modifier les information de :%s\n", ta[index].titre);

        printf("entrer le nouveu titre :");
        scanf("%s", &ta[index].titre);

        printf("entrer le nouveu description :");
        scanf("%d", &ta[index].description);

        printf("modifier la date de creation");

        printf("entrer la nouvelle jour :");
        scanf("%s", &ta[index].dt.jour);

        printf("entrer la nouvelle mois :");
        scanf("%s", &ta[index].dt.mois);

        printf("entrer la nouvelle annee :");
        scanf("%s", &ta[index].dt.annee);

        printf("entrer le nouveu priorité :");
        scanf("%s", &ta[index].priorite);
}










int main(){

    return 0;
}


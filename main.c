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
int main()
{

    return 0;
}

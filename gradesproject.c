#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	char category[5][50];
	int p[5]; //"p" for percent
	int c = 0;
	int hasmore = 1;
	while (hasmore != 0 && c < 5)
	{
		printf("Please enter a category into the gradebook (you can enter up to 5 categories).\n");
		scanf("%s", category[c]);
		printf("Please enter the integer percent value out of 100 for this category.\n");
		scanf("%d", &p[c]);
		printf("Would you like to add another category into the gradebook? Enter 1 for yes or 0 for no.\n");
		scanf("%d", &hasmore);
		//printf("%d", hasmore);
		c++;
	}

	c--;	

	int sum = 0;
	for (int i = 0; i <= c; i++)
	{
		sum = sum + p[i];
	}
	
	if (sum != 100)
	{
		printf("Your percentage values do not add up to 100. Please restart and re-enter the categories.\n");
		exit(0);
	}

	//printf("c = %d.\n", c);
	int numberOfAssgn[5];	
	int earned[5][20];
	int full[5][20];
	for (int i = 0; i <= c; i++)
	{
		char assignment[5][20][50];
		int a = 0;
		int assignhasmore = 1;
	
		while (assignhasmore != 0 && a < 20)
		{
			printf("Please enter an assignment name into: \"%s\". You can enter up to 20 assignments.\n", category[i]);
			scanf("%s", assignment[i][a]);
			//printf("assignment=%s\n", assignment[i][a]);
			printf("Please enter the integer value of points this assignment is worth.\n");
			scanf("%d", &full[i][a]);
			//printf("full=%d\n", full[i][a]);
			printf("Please enter the integer value of points the student earned on this assignment.\n");
			scanf("%d", &earned[i][a]);
			//printf("earned=%d\n", earned[i][a]);
			printf("Would you like to add another assignment to this category? Enter 1 for yes or 0 for no.\n");
			scanf("%d", &assignhasmore);
			a++;
		}
		//a--;
		numberOfAssgn[i]=a;	
	}
	

	float miniaverage[5];
	float sumEarned[5];
        float sumFull[5];
	for (int i = 0; i <= c; i++)
	{			
		sumEarned[i]=0;
		sumFull[i]=0;

		//printf("numberOfAssgn=%d\n", numberOfAssgn[i]);
		for (int j = 0; j < numberOfAssgn[i]; j++)
		{
			sumEarned[i] = sumEarned[i] + earned[i][j];
			sumFull[i] = sumFull[i] + full[i][j];

		}

		//printf("sumEarned=%f; sumFull=%f, percent=%d\n", sumEarned[i], sumFull[i], p[i]);
		miniaverage[i] = (sumEarned[i]/sumFull[i]) * p[i];
		//printf("miniaverage for %s is %f\n", category[i], miniaverage[i]);
	}
	
	float finalgrade = 0;
	for (int i = 0; i <= c; i++)
	{
	  // printf("miniaverage is %f\n", miniaverage[i]);
	  finalgrade = finalgrade + miniaverage[i];
	}

	printf("Your final grade is: %f percent.\n", finalgrade);
}
		

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h> //dla DLB_MAX
#include <unistd.h>
#define N 100
#define M 35
#define a 3
#define b 5


double pascalx(double T)
{
    double x=0;
    x=(a*cos(T)+b)*sin(T);
    return x;
}
double pascaly (double T)
{double y=0;
    y=(a*cos(T)+b)*cos(T);
    return y;
}


int main()
{
    srand(time(NULL));
    int result = rand()%2 +0;
    char tab[M][N];
    int i=0;
    int j=0;
    double T=0;

    int x, y;
    int delta_x =35 ;
    int delta_y =5 ;

    for(T=0;;T+=0.2)
    {
        int result = rand()%10 +0;
        x = (int)(4.5*pascalx(T)) + delta_x;
        y = (int)(2.5*pascaly(T)) + delta_y;

        printf("%d\t%d\n", x, y);

        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {

                tab[i][j] = ' '; //czyszczenie tablicy
                if (result==0)
                {
                   if (i>14 && i< 31)
                    {
                        if ((i==15 && j==16) ||
                            (i==16 && j<18 && j>14)||
                            (i==17 && j<19 && j>13)||
                            (i==18 && j<20 && j>12)||
                            (i==19 && j<21 && j>11)||
                            (i==20 && j<22 && j>10)||
                            (i==21 && j<23 && j>9)||
                            (i==22 && j<24 && j>8)||
                            (i==23 && j<25 && j>7)||
                            (i==24 && j<26 && j>6)||
                            (i==25 && j<27 && j>5)||
                            (i==26 && j<28 && j>4)||
                            (i==27 && j<29 && j>3)||
                            (i==28 && j<30 && j>2)||
                            (i==29 && j<31 && j>1)||
                            (i==30 && j<32 && j>0))
                            tab[i][j] = '#'; // Góra

                    }
                }
            }
        }
        if (tab[y][x]=='#')
            {
            tab[y][x] = '*';
            }
        else
            {
            tab[y][x]='D';//samolocik
            }
        for(i=0;i<M;i++)
        {
            for(j=0;j<N;j++)
            {
                printf("%c", tab[i][j]);

            }
            printf("\n");
        }

        if (tab[y][x]=='*')
            {
            goto endprogram;
            }
            if(T >= DBL_MAX-1) T = 0;
        usleep(150000);
        system("cls");
    }

            endprogram:
                printf("SAMOLOCIK SIE ROZBIL");
return 0;
}

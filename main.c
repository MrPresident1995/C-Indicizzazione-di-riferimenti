#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20
#define MAX 80

void esecuzione(FILE* fp_in, FILE* fp_out, FILE* fp_ind);

int main()
{
    FILE* fp_in;
    FILE* fp_out;
    FILE* fp_ind;

    //APERTURA + CONTROLLO FILE
    fp_in= fopen("Testo.txt", "r");
    fp_out= fopen("Testo modificato.txt", "w");
    fp_ind= fopen("Indice.txt", "w");
    if((fp_in==NULL)||(fp_out==NULL)||(fp_ind==NULL))
    {
        printf("ERRORE APERTURA FILE");
        return -1;
    }

    //ESECUZIONE
    esecuzione(fp_in, fp_out, fp_ind);

    //CHIUSURA
    printf("Operazione eseguita");
    fclose(fp_in);
    fclose(fp_out);
    fclose(fp_ind);
    return 0;
}

void esecuzione(FILE* fp_in, FILE* fp_out, FILE* fp_ind)
{
    int i;
    int flag;
    int cont;
    int esiste;
    int cont_ind;
    int num_ind;
    char car;
    char indice[MAX];
    char reg_indici[max][MAX];

    flag= 0;
    cont= 1;
    esiste= 0;
    cont_ind= 1;
    while((car=fgetc(fp_in))!=EOF)
    {
        if((car=='$')&&(flag==0)) //INIZIO INDICE
        {
            flag= 1;
            car= fgetc(fp_in);
        }
        if((car=='$')&&(flag==1)) //FINE INDICE + CONTROLLO ESISTENZA
        {
            flag= 0;
            indice[cont-1]= '\0';
            for(i=0; i<cont_ind; i++)
                if(strcmp(reg_indici[i], indice)==0)
                {
                    esiste= 1;
                    num_ind= i+1;
                }
            if(esiste==0) //NON ESISTE
            {
                fprintf(fp_out, "[%d]", cont_ind); //STAMPA SU TESTO
                fprintf(fp_ind, "[%d] ", cont_ind); //AGGIUNGE ELEMENTO AGLI INDICI
                for(i=0; i<cont; i++)
                {
                    fprintf(fp_ind, "%c", indice[i]);
                    reg_indici[cont_ind-1][i]= indice[i];
                }
                fprintf(fp_ind, "\n");
                cont_ind++;
                cont= 1;

            }
            else //ESISTE
            {
                fprintf(fp_out, "[%d]", num_ind);
                esiste= 0;
                cont= 1;
            }
        }
        if((car!='$')&&(flag==1)) //CARATTERE DENTRO INDICE
        {
            indice[cont-1]= car;
            cont++;
        }
        if((car!='$')&&(flag==0)) //CARATTERE FUORI INDICE
            fprintf(fp_out, "%c", car);
    }


}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Max 50
#define Maxelem 30

typedef struct
{
    char nome[Max];
    char impiego[Max];
}tipopersona;

void inserisci(tipopersona persone[],int *tail) //funzione che inserisce i clienti che si mettono in fila
{
    char tmpt1[Max];
    char tmpt2[Max];

    printf("inserisci nome cliente\n");
    scanf("%s",tmpt1);
    strcpy(persone[*tail].nome,tmpt1);
    printf("inserisci impiego cliente\n");
    scanf("%s",tmpt2);
    strcpy(persone[*tail].impiego,tmpt2);
    *tail = *tail+1;
    *tail = (*tail)%Maxelem;
}
void rimuovi(tipopersona persone[], int *tail, int *head)    //funzione che va a rimuovere il cliente in testa chiamandolo allo sportello
{
    char a[10], b[10];
    printf("E' chiamato allo sportello %s,%s\n", persone[*head].nome, persone[*head].impiego);
    strcpy(a,persone[*tail].nome);
    strcpy(b,persone[*tail].impiego);
    *head = *head+1;
    *head = (*head)%Maxelem;
}
void stampa(tipopersona persone[],int *head, int *tail)
{
    int i;
    printf("La coda è:\n");
    for(i=*head; i!=*tail; i=(i+1)%Maxelem)
    {
        printf("%d\n",persone[i]);
    }
}

int main()
{
  tipopersona persone[Maxelem];
  int input, testa, coda;
  testa = 0;
  char a[10];
  int z,i;
  printf("numero persone da inserire\n");
  scanf("%d",&z);
  for(i=0;i<z;i++)
  {
      inserisci(persone,&coda);
  }
  do
  {
      printf("Per chiamare il cliente allo sportello premi 1\n");
      scanf("%d",&input);
      rimuovi(persone,&coda,&testa);
  }while((input==1)&&(coda!=testa));
  printf("La coda e' vuota\n");
  system("PAUSE");
  return 0;
}

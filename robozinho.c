    #include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

//@gabrielbolner
main()
{    setlocale(LC_ALL, "Portuguese");
    int tam;//tamanho da matriz
    printf("Digite o tamanho da matriz\n");
        scanf("%i",&tam);
    char mat[tam][tam];
    int l=0,c=0, metade,ld,cd,ok,li,ci,la,ca;
    for (l=0; l<tam; l++)
    {
        for (c=0; c<tam; c++)
        {
            (mat[l][c] = '#');
        }
    }
    printf("\n");

    metade=(tam/2);
    mat[metade][metade] = 'o';


    //mostra a matriz com o buraco ao centro
    for (l=0; l<tam; l++)
    {
        printf("\n");
        for (c=0; c<tam; c++)
        {
            printf ("%c",mat[l][c]);
        }
    }

    //ler posicao atual
    printf("\n");
    printf("Digite o local inicial\n");
    do
    {
        ok=10;

        printf("Linha: ");
        scanf("%i",&li);

        printf("\n");
        printf("Coluna: ");
        scanf("%i",&ci);
        printf("\n");
        mat[li][ci] = 'A';
        //validar
        if ((li >= 0) && (ci>=0))
        {
            ok=0;
        }
        else
        {
            ok=1;
            printf("Inválido,digite novamente\n");
        }
        if ((li<tam) && (ci<tam))
        {
            ok=0;
        }
        else
        {
            ok=1;
            printf("Inválido,digite novamente\n");
        }
    }
    while(ok!=0);


    //ler posicao de destino
    printf("\n");
    printf("Digite o ponto de destino\n");
    do
    {
        printf("Linha: ");
        scanf("%i",&ld);
        printf("\n");
        printf("Coluna: ");
        scanf("%i",&cd);
        printf("\n");
        mat[ld][cd] = 'B';
        //validar
        if ((ld >= 0) && (cd>=0))
        {
            ok=0;
        }
        else
        {
            ok=1;
            printf("Inválido,digite novamente\n");
        }
        if ((ld<tam) && (cd<tam))
        {
            ok=0;

        }
        else
        {
            ok=1;
            printf("Inválido,digite novamente\n");
        }
    }
    while(ok!=0);



//mostra a matriz com os pontos A e B
    for (l=0; l<tam; l++)
    {
        printf("\n");
        for (c=0; c<tam; c++)
        {
            printf ("%c",mat[l][c]);
        }
    }
    printf("\n");

// começam os ifs
    la=li;
    ca=ci;




//if (li>ci){
//la=li+1;
//mat[la][ca] = 'x';

//primeira situação (baixo direita)
    if ((la<ld)&&(ca<cd))
    {
        do
        {
             if ((la==(metade-1)) && (ca==(metade-1))){
                mat[la][ca] = 'x';
                la++;
                mat[la][ca] = 'x';
            }

            la++;
            ca++;
            mat[la][ca] = 'x';

        }
        while ((la!=ld-1)&&(ca!=cd));
    }





    //segunda situação (cima esquerda)
        if ((la>ld)&&(ca>cd))
    {
        do
        {
              if ((la==(metade+1)) && (ca==(metade+1))){
                mat[la][ca] = 'x';
                la--;
                mat[la][ca] = 'x';
            }
            la--;
            ca--;
            mat[la][ca] = 'x';
        }
        while ((la!=ld-1)&&(ca!=cd-1));
    }

    //terceira situação (esquerda)
        if ((la==ld)&&(ca>cd))
    {
        do
        {
              if ((ca==(metade+1))){
                mat[la][ca] = 'x';
                la++;
                mat[la][ca] = 'x';
                ca--;
                mat[la][ca] = 'x';
                ca--;
                mat[la][ca] = 'x';
                la--;
                mat[la][ca] = 'x';
            }
            ca--;
            mat[la][ca] = 'x';
        }
        while (ca!=cd);
    }

    //quarta situação (direita)
        if ((la==ld)&&(ca<cd))
    {
        do
        {

              if ((ca==(metade-1))){
                mat[la][ca] = 'x';
                la++;
                mat[la][ca] = 'x';
                ca++;
                mat[la][ca] = 'x';
                ca++;
                mat[la][ca] = 'x';
                la--;
                mat[la][ca] = 'x';
            }
            ca++;
            mat[la][ca] = 'x';
        }
        while (ca!=cd);
    }

        //quinta situação (cima)
        if ((la>ld)&&(ca==cd))
    {    do
        {
            la--;
            mat[la][ca] = 'x';
        }
        while (la!=ld);
    }

            //sexta situação (baixo)
        if ((la<ld)&&(ca==cd))
    {    do
        {
            la++;
            mat[la][ca] = 'x';
        }
        while (la!=ld);
    }
                //setima situação (cima direita)

        if ((la>ld)&&(ca<cd))
    {
        do
        {
            la--;
            ca++;
            mat[la][ca] = 'x';
        }
        while ((la!=ld-1)&&(ca!=cd));
    }

                //oitava situação (baixo esquerda)
    if ((la<ld)&&(ca>cd))
    {
        do
        {
            la++;
            ca--;
            mat[la][ca] = 'x';
        }
        while ((la!=ld-1)&&(ca!=cd));
    }




    //mostra a matriz com os pontos A e B e o Caminho
    for (l=0; l<tam; l++)
    {
        printf("\n");
        for (c=0; c<tam; c++)
        {
            printf ("%c",mat[l][c]);
        }
    }
    printf("\n");
}

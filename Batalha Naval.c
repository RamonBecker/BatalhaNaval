#include <stdio.h>
#include <stdlib.h>
#include<locale.h>
#include<windows.h>

void gera_Matriz(char matriz[][10], int numJogador);

void atualiza_Matriz(char matriz[][10],int numJogador);

void mostraMatrizGerada(char matrizJog1[][10], int numJogador1, char matrizJog2[][10], int numJogador2);

void inicializaMatriz(char matriz[][10]);

int main(){

    setlocale(LC_ALL,"");

    char copyMatrizJog1[10][10], copyMatrizJog2[10][10], matrizJogado1[10][10], matrizJogado2[10][10], nElementos [] = {'1','2','3','4','5','6','7'};

    int linha, coluna, numAcertosJogadasJog1 = 0, numAcertosJogadasJog2 = 0;


   gera_Matriz(matrizJogado1,1);

   gera_Matriz(matrizJogado2,2);

   inicializaMatriz(copyMatrizJog1);
   inicializaMatriz(copyMatrizJog2);


   while(1){
        mostraMatrizGerada(copyMatrizJog1, 1, copyMatrizJog2,2);
        while(1){
            int cont = 0;

            printf("\t\tJogador 1 - Sua vez de Jogar !! \n\n ");

            printf("Digite a Linha : ");
            scanf(" %d", &linha);

            printf("\nDigite a Coluna : ");
            scanf(" %d", &coluna);

            if(linha > 10 && coluna > 10){
                printf("\n\nNão é possível esta Jogada, Digite Novamente\n\n");
            }
            else if(copyMatrizJog2[linha][coluna] == 'O' || copyMatrizJog2[linha][coluna] == 'X'){
                printf("\n\nVoce já Jogou nesta Posição, Digite Novamente\n\n");
            }

            else {
                cont = 1;

            }

            if(cont == 1)
                break;
        }

        int flag = 0;

        for(int i = 0 ; i < 7 ; i ++){
            if(matrizJogado2[linha][coluna] == nElementos[i]){
               flag = 1;
            }
        }

        if (flag == 1){
            printf("\n\nVoce acertou um Navio !!!");
            copyMatrizJog2[linha][coluna] = 'O';
            numAcertosJogadasJog1++;
        }
        else {

            printf("\n\nTiro na Água !!!");
            copyMatrizJog2[linha][coluna] = 'X';
        }

         if(numAcertosJogadasJog1 == 26){
            printf("\n\nJogador 1 Foi o Vencedor");
            break;

         }

    mostraMatrizGerada(copyMatrizJog1, 1, copyMatrizJog2,2);

        while(1){
            int cont = 0;
            printf("\t\tJogador 2 - Sua vez de Jogar !! \n\n ");

            printf("Digite a Linha : ");
            scanf(" %d", &linha);

            printf("\nDigite a Coluna : ");
            scanf(" %d", &coluna);

            if(linha > 10 && coluna > 10){
                printf("\n\nNão é possível esta Jogada, Digite Novamente\n\n");
            }
            else if(copyMatrizJog1[linha][coluna] == 'O' || copyMatrizJog1[linha][coluna] == 'X'){
                printf("\n\nVoce já Jogou nesta Posição, Digite Novamente\n\n");
            }

            else {
                cont = 1;

            }

            if(cont == 1)
                break;
        }


        int flag1 = 0;

         for(int i = 0 ; i < 7 ; i ++){
            if(matrizJogado1[linha][coluna] == nElementos[i]){
                    flag1 = 1;
            }
        }

        if(flag1 == 1){
            printf("\n\nVoce acertou um Navio !!");
            copyMatrizJog1[linha][coluna] = 'O';
            numAcertosJogadasJog2++;
        }
        else {
            printf("\n\nTiro na Água");
            copyMatrizJog1[linha][coluna] = 'X';

        }

         mostraMatrizGerada(copyMatrizJog1, 1, copyMatrizJog2,2);

         if(numAcertosJogadasJog2 == 26){
              printf("\n\nJogador 2 Foi o Vencedor");
              break;

         }


   }


}
void gera_Matriz(char matriz[][10], int numJogador){

    int contador = 0;

    int linha, coluna;

    char nElementos [] = {'1','2','3','4','5','6'};

    for(int i = 0 ; i < 10 ; i ++){
        for(int j = 0 ; j < 10 ;  j ++){
            matriz[i][j] = '0';
        }
    }

   atualiza_Matriz(matriz, numJogador);

   while(contador < 7) {

        if(contador == 0){ // Preenche a 1 Peça !!
            int  cont = 0 , primeiraVerificacao = 0;
            while(1){
                printf("\n");
                printf("\nPeça : %d - Tamanho da Peça: 5 Vertical \n",contador+1);

                printf("\nDigite a linha : ");
                scanf(" %d", &linha);

                printf("\nDigite a coluna : ");
                scanf(" %d", &coluna);


                for(int i = 0 ; i < 5 ; i ++){
                    if(linha < 10 && coluna < 10 && linha + i < 10){
                        primeiraVerificacao = 1;
                    }else{

                        primeiraVerificacao = 0 ;
                        atualiza_Matriz(matriz, numJogador);
                        printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                        break;
                    }

                }

                if(primeiraVerificacao == 1 ){
                     for(int i = 0 ; i < 5 ; i ++){
                            matriz[linha + i][coluna] = '1';
                            cont = 1;
                     }
                }

            if(cont == 1 ){
                break;
            }
        }
    }

    if(contador == 1){ // Preenche a 2 Peça !!
         int  cont = 0 , primeiraVerificacao = 0,segundoVerificacao = 0;
            while(1){
                printf("\n");
                printf("\nPeça : %d - Tamanho da Peça: 4 Horizontal \n",contador+1);

                printf("\nDigite a linha : ");
                scanf(" %d", &linha);

                printf("\nDigite a coluna : ");
                scanf(" %d", &coluna);


                for(int i = 0 ; i < 4 ; i ++){
                    if(linha < 10 && coluna < 10 && coluna + i < 10){
                            primeiraVerificacao = 1;
                    }else{
                        primeiraVerificacao = 0 ;
                        atualiza_Matriz(matriz, numJogador);
                        printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                        break;
                    }

                }

                if( primeiraVerificacao == 1 ){

                      for(int i = 0 ; i < 4 ; i ++){
                            if(matriz[linha][coluna+i] != '1'){
                                matriz[linha][coluna+i] ='2';
                                cont = 1;
                            }
                            else {

                                for(int i = 0 ; i < 4 ;i ++){
                                    if(matriz[linha][coluna+i]=='2'){
                                        matriz[linha][coluna+i] ='0';
                                    }
                                }
                                cont = 0;
                                atualiza_Matriz(matriz, numJogador);
                             printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");

                                break;
                            }
                      }


                }

            if(cont == 1 ){
                break;
            }
        }
    }


    if(contador == 2){ // Preenche a 3 Peça !!
         int  cont = 0 , primeiraVerificacao = 0,segundoVerificacao = 0;
            while(1){
                printf("\n");
                printf("\nPeça : %d - Tamanho da Peça: 4 Horizontal \n",contador+1);

                printf("\nDigite a linha : ");
                scanf(" %d", &linha);

                printf("\nDigite a coluna : ");
                scanf(" %d", &coluna);


                for(int i = 0 ; i < 4 ; i ++){
                    if(linha < 10 && coluna < 10 && coluna + i < 10){
                            primeiraVerificacao = 1;
                    }else{
                        primeiraVerificacao = 0 ;
                        atualiza_Matriz(matriz, numJogador);
                        printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                        break;
                    }

                }

                if( primeiraVerificacao == 1 ){

                      for(int i = 0 ; i < 4 ; i ++){
                            for(int j = 0 ; j < 2 ; j ++){
                                if(matriz[linha][coluna+i] != nElementos[j]){
                                    segundoVerificacao = 1;
                                }
                                else{

                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                                    segundoVerificacao = 0;
                                    break;
                                }

                            }

                            if(segundoVerificacao == 1){
                                matriz[linha][coluna + i] = '3';
                                cont = 1;

                            }
                            else {

                                    for(int i = 0 ; i < 4 ;i ++){
                                        if(matriz[linha][coluna+i]=='3'){
                                            matriz[linha][coluna+i] ='0';
                                        }
                                    }
                                    cont = 0;
                                    atualiza_Matriz(matriz, numJogador);
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");

                                    break;
                            }

                      }


                }

            if(cont == 1 ){
                break;
            }
        }
    }

     if(contador == 3){ // Preenche a 4 Peça !!
         int  cont = 0 , primeiraVerificacao = 0, segundoVerificacao = 0;
            while(1){
                printf("\n");
                printf("\nPeça : %d - Tamanho da Peça: 4 Vertical \n",contador+1);

                printf("\nDigite a linha : ");
                scanf(" %d", &linha);

                printf("\nDigite a coluna : ");
                scanf(" %d", &coluna);


                for(int i = 0 ; i < 4 ; i ++){
                    if(linha < 10 && coluna < 10 && linha + i < 10){
                            primeiraVerificacao = 1;
                    }else{
                        primeiraVerificacao = 0 ;
                        atualiza_Matriz(matriz, numJogador);
                        printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                        break;
                    }

                }

                if( primeiraVerificacao == 1 ){

                      for(int i = 0 ; i < 4 ; i ++){
                            for(int j = 0 ; j < 3 ; j ++){
                                if(matriz[linha+i][coluna] != nElementos[j]){
                                    segundoVerificacao = 1;
                                }
                                else{
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                                    segundoVerificacao = 0;
                                    break;
                                }

                            }

                            if(segundoVerificacao == 1){
                                matriz[linha+i][coluna] = '4';
                                cont = 1;
                            }
                            else {

                                    for(int i = 0 ; i < 4 ;i ++){
                                        if(matriz[linha+i][coluna]=='4'){
                                            matriz[linha+i][coluna] ='0';
                                        }
                                    }
                                    cont = 0;
                                    atualiza_Matriz(matriz, numJogador);
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");

                                    break;
                            }

                      }


                }

            if(cont == 1 ){
                break;
            }
        }
    }

    if(contador == 4){ // Preenche a 5 Peça !!
         int  cont = 0 , primeiraVerificacao = 0, segundoVerificacao = 0;
            while(1){
                printf("\n");
                printf("\nPeça : %d - Tamanho da Peça: 3 Horizontal \n",contador+1);

                printf("\nDigite a linha : ");
                scanf(" %d", &linha);

                printf("\nDigite a coluna : ");
                scanf(" %d", &coluna);


                for(int i = 0 ; i < 3 ; i ++){
                    if(linha < 10 && coluna < 10 && coluna + i < 10){
                            primeiraVerificacao = 1;
                    }else{
                        primeiraVerificacao = 0 ;
                        atualiza_Matriz(matriz, numJogador);
                        printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                        break;
                    }

                }

                if( primeiraVerificacao == 1 ){

                      for(int i = 0 ; i < 3 ; i ++){
                            for(int j = 0 ; j < 4 ; j ++){
                                if(matriz[linha][coluna+i] != nElementos[j]){
                                    segundoVerificacao = 1;
                                }
                                else{
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                                    segundoVerificacao = 0;
                                    break;
                                }

                            }

                            if(segundoVerificacao == 1){
                                matriz[linha][coluna+i] = '5';
                                cont = 1;
                            }
                            else {

                                    for(int i = 0 ; i < 3 ;i ++){
                                        if(matriz[linha][coluna+i]=='5'){
                                            matriz[linha][coluna+i] ='0';
                                        }
                                    }
                                    cont = 0;
                                    atualiza_Matriz(matriz, numJogador);
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");

                                    break;
                            }

                      }


                }

            if(cont == 1 ){
                break;
            }
        }
    }

    if(contador == 5){ // Preenche a 6 Peça !!
         int  cont = 0 , primeiraVerificacao = 0, segundoVerificacao = 0;
            while(1){
                printf("\n");
                printf("\nPeça : %d - Tamanho da Peça: 3 Vertical \n",contador+1);

                printf("\nDigite a linha : ");
                scanf(" %d", &linha);

                printf("\nDigite a coluna : ");
                scanf(" %d", &coluna);


                for(int i = 0 ; i < 3 ; i ++){
                    if(linha < 10 && coluna < 10 && linha + i < 10){
                            primeiraVerificacao = 1;
                    }else{
                        primeiraVerificacao = 0 ;
                        atualiza_Matriz(matriz, numJogador);
                        printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                        break;
                    }

                }

                if( primeiraVerificacao == 1 ){

                      for(int i = 0 ; i < 3 ; i ++){
                            for(int j = 0 ; j < 5 ; j ++){
                                if(matriz[linha+i][coluna] != nElementos[j]){
                                    segundoVerificacao = 1;
                                }
                                else{
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                                    segundoVerificacao = 0;
                                    break;
                                }

                            }

                            if(segundoVerificacao == 1){
                                matriz[linha+i][coluna] = '6';
                                cont = 1;
                            }
                            else {

                                    for(int i = 0 ; i < 3 ;i ++){
                                        if(matriz[linha+i][coluna]=='6'){
                                            matriz[linha+i][coluna] ='0';
                                        }
                                    }
                                    cont = 0;
                                    atualiza_Matriz(matriz, numJogador);
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");

                                    break;
                            }

                      }


                }

            if(cont == 1 ){
                break;
            }
        }
    }


    if(contador == 6){ // Preenche a 7 Peça !!
         int  cont = 0 , primeiraVerificacao = 0, segundoVerificacao = 0;
            while(1){
                printf("\n");
                printf("\nPeça : %d - Tamanho da Peça: 3 Vertical \n",contador+1);

                printf("\nDigite a linha : ");
                scanf(" %d", &linha);

                printf("\nDigite a coluna : ");
                scanf(" %d", &coluna);


                for(int i = 0 ; i < 3 ; i ++){
                    if(linha < 10 && coluna < 10 && linha + i < 10){
                            primeiraVerificacao = 1;
                    }else{
                        primeiraVerificacao = 0 ;
                        atualiza_Matriz(matriz, numJogador);
                        printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                        break;
                    }

                }

                if( primeiraVerificacao == 1 ){

                      for(int i = 0 ; i < 3 ; i ++){
                            for(int j = 0 ; j < 6 ; j ++){
                                if(matriz[linha+i][coluna] != nElementos[j]){
                                    segundoVerificacao = 1;
                                }
                                else{
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");
                                    segundoVerificacao = 0;
                                    break;
                                }

                            }

                            if(segundoVerificacao == 1){
                                matriz[linha+i][coluna] = '7';
                                cont = 1;
                            }
                            else {

                                    for(int i = 0 ; i < 3 ;i ++){
                                        if(matriz[linha+i][coluna]=='7'){
                                            matriz[linha+i][coluna] ='0';
                                        }
                                    }
                                    cont = 0;
                                    atualiza_Matriz(matriz,numJogador);
                                    printf("\nNão foi possível colocar esta peça, Digite novamente !!\n");

                                    break;
                            }

                      }


                }

            if(cont == 1 ){
                break;
            }
        }
    }

       atualiza_Matriz(matriz, numJogador);

        contador++;

        printf("\n\n");
    }
 system("pause");
 system("cls");
}



void atualiza_Matriz(char matriz[][10], int numJogador){

         system("cls");

        printf("\t\t\tJOGADOR : %d", numJogador);

        printf("\n\n\t\t\tColuna\n\n");
        printf("\t     0   1   2   3   4   5   6   7   8   9");

        printf("\n\n");

        printf("Linha");
        for(int i = 0 ; i < 10 ; i ++){
                printf("\t%d  ", i);
           for(int k = 0 ; k < 10 ; k ++){
               printf("| %c ", matriz[i][k]);
            }
           printf("\n");
        }
}



void mostraMatrizGerada(char matrizJog1[][10], int numJogador1, char matrizJog2[][10], int numJogador2){

     Sleep(3000);

     system("cls");
    printf("\t\t\tBATALHA NAVAL\n\n");
    printf("\t\t X - Tiro Na ÁGUA\n\n");
    printf("\t\t O - Acertou um Návio\n\n");

     printf("\t\t\tTABULEIRO JOGADOR : %d", numJogador1);

        printf("\n\n\t\t\tColuna\n\n");

        printf("\t     0   1   2   3   4   5   6   7   8   9");

        printf("\n\n");

        printf("Linha");

        for(int i = 0 ; i < 10 ; i ++){
                printf("\t%d  ", i);
           for(int j = 0 ; j < 10 ; j ++){
               printf("| %c ", matrizJog1[i][j]);
            }
           printf("\n");
        }
    printf("\n\n\n");


       printf("\t\t\tTABULEIRO JOGADOR : %d", numJogador2);

        printf("\n\n\t\t\tColuna\n\n");

        printf("\t     0   1   2   3   4   5   6   7   8   9");

        printf("\n\n");

        printf("Linha");
        for(int i = 0 ; i < 10 ; i ++){
                printf("\t%d  ", i);
           for(int j = 0 ; j < 10 ; j ++){
               printf("| %c ", matrizJog2[i][j]);
            }
           printf("\n");
        }
    printf("\n\n");

}



void inicializaMatriz(char matriz[][10]){

        for(int i = 0 ; i < 10 ; i ++){
           for(int j = 0 ; j < 10 ; j ++){
                matriz[i][j] = '#';
            }
        }

}

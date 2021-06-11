#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>

/* A) TELA DO GITHUB */
void github(){
    int tempo = 50;
    printf("\n **** O c�digo-fonte deste jogo est� dispon�vel gratuitamente **** "); Sleep(tempo);
    printf("\n      no reposit�rio do GitHub de Guilherme Cordeiro. Acesse:  \n\n"); Sleep(tempo);
    printf("\n                        @@@@@@@@@@@@@@@@@@@                        "); Sleep(tempo);
    printf("\n                    @@@@@@@@@@@@@@@@@@@@@@@@@@@                    "); Sleep(tempo);
    printf("\n                 @@@@@@  @@@@@@@@@@@@@@@@@  @@@@@@                 "); Sleep(tempo);
    printf("\n               @@@@@@@    @@@@@@@@@@@@@@@    @@@@@@@               "); Sleep(tempo);
    printf("\n             @@@@@@@@                         @@@@@@@@             "); Sleep(tempo);
    printf("\n            @@@@@@@@@                         @@@@@@@@@            "); Sleep(tempo);
    printf("\n           @@@@@@@@@                           @@@@@@@@@           "); Sleep(tempo);
    printf("\n           @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n           @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n           @@@@@@@@                             @@@@@@@@           "); Sleep(tempo);
    printf("\n           @@@@@@@@@                           @@@@@@@@@           "); Sleep(tempo);
    printf("\n            @@@@@@@@@@                       @@@@@@@@@@            "); Sleep(tempo);
    printf("\n             @@@@   @@@@@@@@           @@@@@@@@@@@@@@@             "); Sleep(tempo);
    printf("\n              @@@@@   @@@@@@           @@@@@@@@@@@@@@              "); Sleep(tempo);
    printf("\n                @@@@@                  @@@@@@@@@@@@                "); Sleep(tempo);
    printf("\n                   @@@@@@@@@           @@@@@@@@@                   "); Sleep(tempo);
    printf("\n                      @@@@@@           @@@@@@                  \n\n"); Sleep(tempo);
    printf("\n              +-------------------------------------+              "); Sleep(tempo);
    printf("\n              |   https://github.com/gui-cordeiro   |              "); Sleep(tempo);
    printf("\n              +-------------------------------------+            \n"); Sleep(tempo);
    return;
}

/* B) MODELO DAS PERGUNTAS */
int newPergunta(int questao, char l1, char l2, char l3, char l4, char altResp, char letrResp, int pts, int acertos){
    int tempo = 50;
    int acertoCont;
    char opt;
    printf("\n * SEUS PONTOS: %d", pts);Sleep(tempo);
    printf("\n * SEUS ACERTOS: %d\n", acertos);Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                PERGUNTA N� %d                  |", questao);Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printAlfabeto(letrResp);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+\n");Sleep(tempo);
    printf("\n Qual � a letra correspondente?\n");Sleep(tempo);
    printf("\n a) '%c'", l1);Sleep(tempo);
    printf("\n b) '%c'", l2);Sleep(tempo);
    printf("\n c) '%c'", l3);Sleep(tempo);
    printf("\n d) '%c'", l4);Sleep(tempo);
    printf("\n\n Alternativa: ");
    scanf(" %c",&opt);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    if(tolower(opt) == altResp){
        printf("\n |                CERTA RESPOSTA!                | ");Sleep(tempo);
        printf("\n |           VOC� GANHOU: 150 PONTOS!            | ");Sleep(tempo);
        acertoCont = 1;
    }else{
        printf("\n |     VOC� ERROU... RESPOSTA CORRETA: \"%c)\"      | ", tolower(altResp));Sleep(tempo);
        printf("\n |           VOC� GANHOU: 50 PONTOS.             | ");Sleep(tempo);
        acertoCont = 0;
    }
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    return acertoCont;
}

/* C) TELA DE APRESENTA��O */
void apresentacao(){
    int tempo = 50;
    addFade(7, 0, 0);
    printf("                                 **** Criado por Guilherme Cordeiro - 2017, 2021 ****                                \n\n");
    printf("+---------------------------------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("|      ##  #######   ######    #######     ########   #######     ########  ########     ###    #### ##       ########|\n");Sleep(tempo);
    printf("|      ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##     ##   ## ##    ##  ##       ##      |\n");Sleep(tempo);
    printf("|      ## ##     ## ##        ##     ##    ##     ## ##     ##    ##     ## ##     ##  ##   ##   ##  ##       ##      |\n");Sleep(tempo);
    printf("|      ## ##     ## ##   #### ##     ##    ##     ## ##     ##    ########  ########  ##     ##  ##  ##       ######  |\n");Sleep(tempo);
    printf("|##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##   ##   #########  ##  ##       ##      |\n");Sleep(tempo);
    printf("|##    ## ##     ## ##    ##  ##     ##    ##     ## ##     ##    ##     ## ##    ##  ##     ##  ##  ##       ##      |\n");Sleep(tempo);
    printf("| ######   #######   ######    #######     ########   #######     ########  ##     ## ##     ## #### ######## ########|\n");Sleep(tempo);
    printf("+---------------------------------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(2, 50, 1);
    printf("                                   **** Pressione qualquer tecla para iniciar ****");
    getch();
    addFade(8, 0, 0);
    addFade(22, 32, 1);
    system("cls");
    return;
}

/* D) ALFABETO EM BRAILE */
void printAlfabeto(char letra){
    int tempo = 50;
    switch(tolower(letra)){
        case 'a':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'b':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'c':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'd':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'e':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'f':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'g':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'h':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'i':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'j':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            break;
        case 'k':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'l':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'm':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'n':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'o':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'p':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'q':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'r':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 's':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 't':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            break;
        case 'u':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'v':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'w':
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            break;
        case 'x':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |    |                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'y':
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
        case 'z':
            printf("\n |                   |o   |                      |");Sleep(tempo);
            printf("\n |                   |   o|                      |");Sleep(tempo);
            printf("\n |                   |o  o|                      |");Sleep(tempo);
            break;
    }
}

/* E) INICIO DO JOGO */
int inicioJogo(char nivel[9]){
    int tempo = 50;
    int opt = 0;
    char nome[40];
    do{
        system("cls");Sleep(tempo);
        printf("\n     **** OP��O SELECIONADA : 'Jogar - N�VEL %s' **** \n", nivel);Sleep(tempo);
        printf("\n           Confirma? ('1' para Sim, '2' para N�o): ");
        scanf("%d",&opt);
        addFade(25, 0, 0);
        addFade(5, 30, 1);
        if(opt == 2){
            return 0;
        }else if(opt != 1){
            system("cls");
            printf("\n Op��o inv�lida! Por favor, digite um n�mero v�lido entre '1' e '2'...");
            addFade(1, 50, 1);
            printf("\n        **** Pressione qualquer tecla para continuar ****");
            getch();
        }
    }while(opt != 1);
    system("cls");
    printf("\n *** Boas vindas ao \"Jogo do Braile\" - Dificuldade '%s'! ***", nivel);Sleep(tempo);
    addFade(2, 50, 1);
    printf("\n - Para come�ar, digite o seu nome: ");
    scanf(" %s",&nome);
    addFade(25, 0, 0);
    addFade(5, 30, 1);
    system("cls");
    printf("\n\n * Ol� '%s'! � um prazer enorme ter voc� aqui jogando! *       ",nome);
    addFade(4, 50, 1);
    printf("   ########  #### ##     ## #### ########  ########    ###             ######  ######## #### \n");Sleep(tempo);
    printf("   ##     ##  ##  ##     ##  ##  ##     ##    ##      ## ##           ##    ## ##       #### \n");Sleep(tempo);
    printf("   ##     ##  ##  ##     ##  ##  ##     ##    ##     ##   ##          ##       ##       #### \n");Sleep(tempo);
    printf("   ##     ##  ##  ##     ##  ##  ########     ##    ##     ## #######  ######  ######    ##  \n");Sleep(tempo);
    printf("   ##     ##  ##   ##   ##   ##  ##   ##      ##    #########               ## ##            \n");Sleep(tempo);
    printf("   ##     ##  ##    ## ##    ##  ##    ##     ##    ##     ##         ##    ## ##       #### \n");Sleep(tempo);
    printf("   ########  ####    ###    #### ##     ##    ##    ##     ##          ######  ######## #### \n");Sleep(tempo);
    addFade(3, 50, 1);
    printf("               +---------------------------------------------------------------+\n");Sleep(tempo);
    printf("               |                         * ATEN��O! *                          |\n");Sleep(tempo);
    printf("               +---------------------------------------------------------------+\n");Sleep(tempo);
    printf("               | As letras em braile aparecer�o na pr�xima tela. Preparado(a)? |\n");Sleep(tempo);
    printf("               +---------------------------------------------------------------+");
    addFade(2, 50, 1);
    printf("                      **** Pressione qualquer tecla para continuar ****");
    getch();
    addFade(5, 0, 0);
    addFade(25, 30, 1);
    system("cls");
    return 1;
}

/* F) FIM DO JOGO (TABELA DE ESTAT�STICAS) */
void fimJogo(int nivel, char frase[100], int pts, int acertos, int numPerg){
    int tempo = 50;
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n |           SEU DESEMPENHO             |");Sleep(tempo);
    printf("\n +--------------------------------------+");Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    if(numPerg < 10){
        printf("\n |         N� de acertos: %d / %d         |", acertos, numPerg);
    }else if(acertos < 10){
        printf("\n |         N� de acertos: %d / %d        |", acertos, numPerg);
    }else{
        printf("\n |        N� de acertos: %d / %d        |", acertos, numPerg);
    }
    Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    if(pts < 1000){
    printf("\n |        N� total de pontos: %d       |", pts);
    }else{
    printf("\n |       N� total de pontos: %d       |", pts);
    }
    Sleep(tempo);
    printf("\n |                                      |");Sleep(tempo);
    printf("\n +--------------------------------------+");
    Sleep(1000);
    if(((nivel == 1 && acertos <= 2) || (nivel == 2 && acertos <= 3)) || ((nivel == 3 && acertos <= 3) || (nivel == 4 && acertos <= 8))){
        printf("\n\n\n Bom. . . Voc� precisa aprender um pouco mais de braile. N�o desanime, tente novamente!");
    }
    else if(((nivel == 1 && acertos <= 3) || (nivel == 2 && acertos <= 6)) || ((nivel == 3 && acertos <= 6) || (nivel == 4 && acertos <= 15))){
        printf("\n\n\n Voc� tem potencial, mas precisa se esfor�ar um pouco mais!");
    }
    else if(((nivel == 1 && acertos <= 4) || (nivel == 2 && acertos <= 9)) || ((nivel == 3 && acertos <= 9) || (nivel == 4 && acertos <= 22))){
        printf("\n\n\n Muito bem! Voc� realmente mandou bem, mas um pouquinho mais de empenho n�o faz mal para ningu�m!");
    }
    else if(((nivel == 1 && acertos == 5) || (nivel == 2 && acertos == 10)) || ((nivel == 3 && acertos == 11) || (nivel == 4 && acertos == 26))){
        printf("\n\n\n Meus parab�ns! Voc� acertou todas as quest�es e provou do que � capaz!");
    }
    Sleep(1500);
    printf("\n\n\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getch();
    addFade(12, 0, 0);
    addFade(18, 30, 1);
    system("cls");
    printf("\n   * %s *", frase);Sleep(tempo);
    printf("\n\n                         Selecione-o no menu!\n\n");Sleep(tempo);
    printf("\n                     **** OBRIGADO POR JOGAR! ****\n");
    addFade(5, 50, 1);
    banner();
    addFade(5, 50, 1);
    printf("         **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    addFade(6, 0, 0);
    addFade(24, 30, 1);
    return;
}

/* G) ANIMA��O DE TRANSI��O DE TELA */
void addFade(int rep, int millis, int isLento){
    for(int cont = 0; cont < rep; cont ++){
            printf("\n");
            if(isLento != 0) Sleep(millis);
    }
}

/* H) BANNER DE APRESENTA��O */
void banner(){
    int tempo = 50;
    printf("\n              +-------------------------------------------+");Sleep(tempo);
    printf("\n              |        Jogo do Braile - 2017, 2021        |");Sleep(tempo);
    printf("\n              +-------------------------------------------+");Sleep(tempo);
    printf("\n              |      Criado por: Guilherme Cordeiro       |");Sleep(tempo);
    printf("\n              +-------------------------------------------+\n");Sleep(tempo);
    return;
}


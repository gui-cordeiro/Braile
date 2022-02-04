#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <locale.h>
#include <math.h>
#include <string.h>

/* 0) Menu principal */
int menu(int erro){
    int tempo = 50, i = 0, a = 0;
    char opt[100];
    char optMenu [7][24] = {"  Jogar - N�VEL F�CIL  "," Jogar - N�VEL M�DIO I "," Jogar - N�VEL M�DIO II"," Jogar - N�VEL DIF�CIL ","  Instru��es do Jogo   ","   Cr�ditos do Jogo    ","     Sair do Jogo      "};
    titulo("-", "Menu Principal");
    fflush(stdin);
    if (erro == 0) {
        addFade(3, tempo, 0);
    }
    printf("\n\t\t\t\t _____                 _____     _         _         _ \n");Sleep(tempo);
    printf("\t\t\t\t|     |___ ___ _ _    |  _  |___|_|___ ___|_|___ ___| |\n");Sleep(tempo);
    printf("\t\t\t\t| | | | -_|   | | |   |   __|  _| |   |  _| | . | .'| |\n");Sleep(tempo);
    printf("\t\t\t\t|_|_|_|___|_|_|___|   |__|  |_| |_|_|_|___|_|  _|__,|_|\n");Sleep(tempo);
    printf("\t\t\t\t                                            |_|        \n");Sleep(tempo);
    printf("\t\t\t\t      (Insira a op��o desejada e pressione ENTER)");
    addFade(3, 50, 1);
    printf("\t\t\t\t      +-------------------------+---------------+");Sleep(tempo);
    printf("\n\t\t\t\t      |       DESCRI��O         | NUM. DA OP��O | ");Sleep(tempo);
    printf("\n\t\t\t\t      +-------------------------+---------------+ ");Sleep(tempo);
    for (int c = 0; c < 7; c ++) {
        printf("\n\t\t\t\t      +-------------------------+---------------+ ");Sleep(tempo);
        printf("\n\t\t\t\t      | %s |       %d       | ", optMenu[c], c + 1);Sleep(tempo);
    }
    printf("\n\t\t\t\t      +-------------------------+---------------+");addFade(2, 50, 1);
    printf("\t\t\t\t\t          Para onde vamos? -> ");
    fgets(opt, 100, stdin);
    while (opt[i] != '\0') {
        if ((opt[i] == ' ') || ((opt[i] >= 'a' && opt[i] <= 'z') || (opt[i] >= 'A' && opt[i] <= 'Z'))) {
            return 0;
        }
        i ++;
    }
    a = atoi(opt);
    return a;
}

/* 1) Jogar - N�VEL F�CIL */
void opcao1(){
    int cont = 10, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    char nome[40];
    if(confirmarJogo("F�CIL") == 0) return 0;
    boasVindas01("F�CIL");
    printf(" -> Antes de come�ar, digite o seu nome: ");
    scanf("%s", nome);
    fflush(stdin);
    boasVindas02(nome);
    printf("\n           As letras em braile nesta dificuldade s�o:  \n");Sleep(tempo);
    printf("\n          A          E          I          O          U \n");Sleep(tempo);
    printf("\n        |o   |     |o   |     |   o|     |o   |     |o   |");Sleep(tempo);
    printf("\n        |    |     |   o|     |o   |     |   o|     |    |");Sleep(tempo);
    printf("\n        |    |     |    |     |    |     |o   |     |o  o|");addFade(2, 50, 1);
    printf("         * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("                    Tempo restante: %d segundos",cont);Sleep(tempo);
    Sleep(800);
    system("cls");
    cont --;
    do{
        printf("\n           As letras em braile nesta dificuldade s�o:  \n");
        printf("\n          A          E          I          O          U \n");
        printf("\n        |o   |     |o   |     |   o|     |o   |     |o   |");
        printf("\n        |    |     |   o|     |o   |     |   o|     |    |");
        printf("\n        |    |     |    |     |    |     |o   |     |o  o|\n");
        printf("\n         * Tente memorizar as letras acima e boa sorte! *\n");
        if(cont != 1){
            printf("\n                    Tempo restante: %d segundos",cont);
        }else{
            printf("\n                    Tempo restante: %d segundo",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    if(newPergunta(1, 'A', 'I', 'E', 'U', 3, 'E', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'U', 'I', 'O', 'A', 1, 'U', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'E', 'O', 'I', 'A', 4, 'A', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'I', 'O', 'U', 'E', 1, 'I', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'O', 'A', 'U', 'E', 1, 'O', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if (acertos == 5) {
        fimJogo(1, "FOI MAM�O COM A��CAR, N�O FOI? COMO �? VOC� QUER UM DESAFIO? ENT�O V� AO N�VEL 'M�DIO I'!", nome, pts, acertos, numPerg);
    } else {
        fimJogo(1, "BOA TENTATIVA, MAS N�O DESISTA! TENTE NOVAMENTE NESTE MODO, VOC� CONSEGUE!", nome, pts, acertos, numPerg);
    }
    return;
}

/* 2) Jogar - N�VEL M�DIO I */
void opcao2(){
    int cont = 15, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    char nome[40];
    if(confirmarJogo("M�DIO I") == 0) return 0;
    boasVindas01("M�DIO I");
    printf(" -> Antes de come�ar, digite o seu nome: ");
    scanf("%s", nome);
    fflush(stdin);
    boasVindas02(nome);
    printf("\n           As letras em braile nesta dificuldade s�o:     \n");Sleep(tempo);
    printf("\n          B          C          D          F          G    \n");Sleep(tempo);
    printf("\n        |o   |     |o  o|     |o  o|     |o  o|     |o  o|   ");Sleep(tempo);
    printf("\n        |o   |     |    |     |   o|     |o   |     |o  o|   ");Sleep(tempo);
    printf("\n        |    |     |    |     |    |     |    |     |    | \n");Sleep(tempo);
    printf("\n          H          J          K          L          M    \n");Sleep(tempo);
    printf("\n        |o   |     |   o|     |o   |     |o   |     |o  o|   ");Sleep(tempo);
    printf("\n        |o  o|     |o  o|     |    |     |o   |     |    |   ");Sleep(tempo);
    printf("\n        |    |     |    |     |o   |     |o   |     |o   | \n");Sleep(tempo);
    printf("\n         * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("                    Tempo restante: %d segundos",cont);Sleep(tempo);
    Sleep(1000);
    system("cls");
    cont --;
    do{
        printf("\n           As letras em braile nesta dificuldade s�o:     \n");
        printf("\n          B          C          D          F          G    \n");
        printf("\n        |o   |     |o  o|     |o  o|     |o  o|     |o  o|   ");
        printf("\n        |o   |     |    |     |   o|     |o   |     |o  o|   ");
        printf("\n        |    |     |    |     |    |     |    |     |    | \n");
        printf("\n          H          J          K          L          M    \n");
        printf("\n        |o   |     |   o|     |o   |     |o   |     |o  o|   ");
        printf("\n        |o  o|     |o  o|     |    |     |o   |     |    |   ");
        printf("\n        |    |     |    |     |o   |     |o   |     |o   | \n");
        printf("\n         * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
        if(cont == 1){
            printf("                    Tempo restante: %d segundo",cont);
        }
        else{
            printf("                    Tempo restante: %d segundos",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    if(newPergunta(1, 'G', 'D', 'M', 'J', 1, 'G', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'C', 'H', 'L', 'B', 3, 'L', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'B', 'F', 'J', 'C', 4, 'C', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'G', 'J', 'D', 'M', 2, 'J', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'D', 'B', 'M', 'H', 3, 'M', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(6, 'B', 'J', 'H', 'D', 1, 'B', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(7, 'K', 'F', 'B', 'H', 1, 'K', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(8, 'M', 'D', 'C', 'H', 4, 'H', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(9, 'G', 'D', 'K', 'F', 2, 'D', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(10, 'F', 'M', 'B', 'J', 1, 'F', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if (acertos == 10) {
        fimJogo(2, "SIGA ADIANTE! CONTINUE O SEU APRENDIZADO JOGANDO O N�VEL 'M�DIO II'!", nome, pts, acertos, numPerg);
    } else {
        fimJogo(2, "BOA TENTATIVA, MAS N�O DESISTA! TENTE NOVAMENTE NESTE MODO, VOC� CONSEGUE!", nome, pts, acertos, numPerg);
    }
    return;
}

/* 3) Jogar - N�VEL M�DIO II */
void opcao3(){
    int cont = 15, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    char nome[40];
    if(confirmarJogo("M�DIO II") == 0) return 0;
    boasVindas01("M�DIO II");
    printf(" -> Antes de come�ar, digite o seu nome: ");
    scanf("%s", nome);
    fflush(stdin);
    boasVindas02(nome);
    printf("\n           As letras em braile nesta dificuldade s�o:      \n");Sleep(tempo);
    printf("\n          N          P          Q          R          S    \n");Sleep(tempo);
    printf("\n        |o  o|     |o  o|     |o  o|     |o   |     |   o|   ");Sleep(tempo);
    printf("\n        |   o|     |o   |     |o  o|     |o  o|     |o   |   ");Sleep(tempo);
    printf("\n        |o   |     |o   |     |o   |     |o   |     |o   | \n");Sleep(tempo);
    printf("\n          T          V          W          X          Y    \n");Sleep(tempo);
    printf("\n        |   o|     |o   |     |   o|     |o  o|     |o  o|   ");Sleep(tempo);
    printf("\n        |o  o|     |o   |     |o  o|     |    |     |   o|   ");Sleep(tempo);
    printf("\n        |o   |     |o  o|     |   o|     |o  o|     |o  o| \n");Sleep(tempo);
    printf("\n                                Z     \n");Sleep(tempo);
    printf("\n                              |o   |    ");Sleep(tempo);
    printf("\n                              |   o|    ");Sleep(tempo);
    printf("\n                              |o  o| ");addFade(1, 50, 1);
    printf("\n         * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("                    Tempo restante: %d segundos",cont);
    Sleep(800);
    system("cls");
    cont --;
    do{
        printf("\n           As letras em braile nesta dificuldade s�o:     \n");
        printf("\n          N          P          Q          R          S    \n");
        printf("\n        |o  o|     |o  o|     |o  o|     |o   |     |   o|   ");
        printf("\n        |   o|     |o   |     |o  o|     |o  o|     |o   |   ");
        printf("\n        |o   |     |o   |     |o   |     |o   |     |o   | \n");
        printf("\n          T          V          W          X          Y    \n");
        printf("\n        |   o|     |o   |     |   o|     |o  o|     |o  o|   ");
        printf("\n        |o  o|     |o   |     |o  o|     |    |     |   o|   ");
        printf("\n        |o   |     |o  o|     |   o|     |o  o|     |o  o| \n");
        printf("\n                                Z     \n");
        printf("\n                              |o   |    ");
        printf("\n                              |   o|    ");
        printf("\n                              |o  o| \n");
        printf("\n         * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
        if(cont != 0){
        printf("                   Tempo restante: %d segundos",cont);
        }else{
        printf("                   Tempo restante: %d segundo",cont);
        }
        Sleep(1000);
        system("cls");
        cont --;
    }while(cont > 0);
    if(newPergunta(1, 'V', 'W', 'T', 'N', 1, 'V', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'P', 'S', 'Q', 'R', 3, 'Q', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'N', 'P', 'T', 'Y', 4, 'Y', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'Z', 'T', 'S', 'Y', 2, 'T', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'R', 'Z', 'P', 'W', 2, 'Z', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(6, 'V', 'W', 'Z', 'N', 4, 'N', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(7, 'N', 'S', 'P', 'Y', 2, 'S', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(8, 'S', 'Q', 'W', 'Y', 3, 'W', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(9, 'R', 'Q', 'P', 'Y', 1, 'R', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(10, 'Z', 'X', 'P', 'T', 2, 'X', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(11, 'X', 'W', 'S', 'P', 4, 'P', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if (acertos == 11) {
        fimJogo(3, "BOM TRABALHO! AGORA V� ADIANTE AO SEU �LTIMO DESAFIO, AO TEMIDO N�VEL 'DIF�CIL'!", nome, pts, acertos, numPerg);
    } else {
        fimJogo(3, "BOA TENTATIVA, MAS N�O DESISTA! TENTE NOVAMENTE NESTE MODO, VOC� CONSEGUE!", nome, pts, acertos, numPerg);
    }
    return;
}

/* 4) Jogar - N�VEL DIF�CIL */
void opcao4(){
    int cont = 30, tempo = 50, numPerg = 0;
    int conf = 0, pts = 0, acertos = 0;
    char nome[40];
    if(confirmarJogo("DIF�CIL") == 0) return 0;
    boasVindas01("DIF�CIL");
    printf(" -> Antes de come�ar, digite o seu nome: ");
    scanf("%s", nome);
    fflush(stdin);
    boasVindas02(nome);
    printf("\n                                 As letras em braille nesta dificuldade s�o:\n");
    printf("\n          A          B          C          D          E          F          G          H          I     \n");Sleep(tempo);
    printf("\n        |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|    ");Sleep(tempo);
    printf("\n        |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |    ");Sleep(tempo);
    printf("\n        |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |  \n");Sleep(tempo);
    printf("\n          J          K          L          M          N          O          P          Q          R     \n");Sleep(tempo);
    printf("\n        |   o|     |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |    ");Sleep(tempo);
    printf("\n        |o  o|     |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|    ");Sleep(tempo);
    printf("\n        |    |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |  \n");Sleep(tempo);
    printf("\n                S          T          U          V          W          X          Y          Z          \n");Sleep(tempo);
    printf("\n              |   o|     |   o|     |o   |     |o   |     |   o|     |o  o|     |o  o|     |o   |         ");Sleep(tempo);
    printf("\n              |o   |     |o  o|     |    |     |o   |     |o  o|     |    |     |   o|     |   o|         ");Sleep(tempo);
    printf("\n              |o   |     |o   |     |o  o|     |o  o|     |   o|     |o  o|     |o  o|     |o  o|       \n");Sleep(tempo);
    printf("\n                               * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
    printf("                                          Tempo restante: %d segundos",cont);
    Sleep(800);
    system("cls");
    cont --;
    do{
        printf("\n                                 As letras em braille nesta dificuldade s�o:\n");
        printf("\n          A          B          C          D          E          F          G          H          I     \n");
        printf("\n        |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|    ");
        printf("\n        |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |    ");
        printf("\n        |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |  \n");
        printf("\n          J          K          L          M          N          O          P          Q          R     \n");
        printf("\n        |   o|     |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |    ");
        printf("\n        |o  o|     |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|    ");
        printf("\n        |    |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |  \n");
        printf("\n                S          T          U          V          W          X          Y          Z          \n");
        printf("\n              |   o|     |   o|     |o   |     |o   |     |   o|     |o  o|     |o  o|     |o   |         ");
        printf("\n              |o   |     |o  o|     |    |     |o   |     |o  o|     |    |     |   o|     |   o|         ");
        printf("\n              |o   |     |o   |     |o  o|     |o  o|     |   o|     |o  o|     |o  o|     |o  o|       \n");
        printf("\n                               * Tente memorizar as letras acima e boa sorte! *");addFade(2, 50, 1);
        if(cont != 1){
            printf("                                          Tempo restante: %d segundos",cont);
        }else{
            printf("                                          Tempo restante: %d segundo",cont);
        }
        Sleep(950);
        system("cls");
        cont --;
    }while(cont > 0);

    if(newPergunta(1, 'G', 'D', 'M', 'A', 1, 'G', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(2, 'V', 'I', 'U', 'N', 1, 'V', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(3, 'Q', 'S', 'P', 'R', 1, 'Q', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(4, 'C', 'H', 'L', 'E', 3, 'L', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(5, 'A', 'H', 'E', 'Z', 3, 'E', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(6, 'B', 'F', 'J', 'C', 4, 'C', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(7, 'N', 'U', 'T', 'Y', 4, 'Y', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(8, 'Z', 'T', 'S', 'Y', 2, 'T', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(9, 'G', 'J', 'A', 'O', 2, 'J', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(10, 'U', 'C', 'H', 'P', 1, 'U', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(11, 'D', 'B', 'M', 'O', 3, 'M', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(12, 'R', 'Z', 'P', 'A', 2, 'Z', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(13, 'I', 'W', 'E', 'N', 4, 'N', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(14, 'B', 'J', 'H', 'U', 1, 'B', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(15, 'A', 'K', 'I', 'B', 1, 'A', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(16, 'K', 'F', 'B', 'O', 1, 'K', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(17, 'N', 'S', 'F', 'W', 2, 'S', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(18, 'A', 'W', 'Q', 'U', 2, 'W', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(19, 'M', 'D', 'E', 'H', 4, 'H', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(20, 'O', 'I', 'M', 'Y', 2, 'I', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(21, 'G', 'D', 'K', 'I', 2, 'D', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(22, 'R', 'A', 'P', 'I', 1, 'R', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(23, 'E', 'X', 'P', 'T', 2, 'X', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(24, 'F', 'M', 'J', 'P', 1, 'F', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(25, 'O', 'J', 'U', 'P', 1, 'O', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;
    if(newPergunta(26, 'P', 'E', 'S', 'O', 1, 'P', pts, acertos) == 1){
        pts += 150; acertos ++;
    }else pts += 50; numPerg ++;

    if (acertos == 26) {
        fimJogo(4, "MEUS PARAB�NS! VOC� PROVOU COM MAESTRIA QUE � EXPERT NO BRAILE!", nome, pts, acertos, numPerg);
    } else {
        fimJogo(4, "BOA TENTATIVA, MAS N�O DESISTA! TENTE NOVAMENTE NESTE MODO, VOC� CONSEGUE!", nome, pts, acertos, numPerg);
    }
    return;
}

/* 5) Instru��es do Jogo */
int opcao5(){
    int tempo = 50, finalopt = 0, erro = 0;
    char opt[100];
    system("cls");
    do {
        if (erro == 0) {
            addFade(4, 50, 0);
        }
        printf("\t\t\t\t     _____                     __                 \n");Sleep(tempo);
        printf("\t\t\t\t    |     |___ _____ ___    __|  |___ ___ ___ ___ \n");Sleep(tempo);
        printf("\t\t\t\t    |   --| . |     | . |  |  |  | . | . | .'|  _|\n");Sleep(tempo);
        printf("\t\t\t\t    |_____|___|_|_|_|___|  |_____|___|_  |__,|_|  \n");Sleep(tempo);
        printf("\t\t\t\t                                     |___|        \n");Sleep(tempo);

        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     |                               O QUE � O 'JOGO DO BRAILE'?                                |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     | O 'Jogo do Braile' � um simples jogo de mem�ria sob a forma de quiz, cujo objetivo do(a) |\n");Sleep(tempo);
        printf("\t     | jogador(a) � acertar o m�ximo de perguntas poss�veis. Ele tem o intuito de ensinar o     |\n");Sleep(tempo);
        printf("\t     | sistema de escrita t�til 'Braile', de forma simples e l�dica, para pessoas sem           |\n");Sleep(tempo);
        printf("\t     | defici�ncia visual.                                                                      |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     |                                  COMO O JOGO FUNCIONA?                                   |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
        printf("\t     | Neste jogo, cada pergunta � composta por:                                                |\n");Sleep(tempo);
        printf("\t     |                                                                                          |\n");Sleep(tempo);
        printf("\t     | * Uma letra que ser� exibida em destaque, escrita de acordo com a grafia do 'Braile'; e  |\n");Sleep(tempo);
        printf("\t     | * Quatro outras letras (alternativas) escritas de acordo com o alfabeto latino.          |\n");Sleep(tempo);
        printf("\t     |                                                                                          |\n");Sleep(tempo);
        printf("\t     | Para responder tais perguntas, � necess�rio memorizar as letras que aparecer�o na tela   |\n");Sleep(tempo);
        printf("\t     | por alguns segundos.                                                                     |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
        addFade(3, 50, 1);
        printf("\t\t\tDESEJA VER UM EXEMPLO DE UMA PERGUNTA? ('S' para Sim, 'N' para N�o): ");
        fgets(opt, 100, stdin);
        finalopt = verifyOpt(opt, 1);
        system("cls");
        if (finalopt == 0) {
            erro ++;
            printf("\n");
            telaErro();
            addFade(1, 50, 1);
        } else if (finalopt == 2) {
            return 0;
        }
    } while (finalopt != 1);
    printf("\n **** EXEMPLO DE UMA PERGUNTA **** \n");Sleep(tempo);
    printf("\n Esta tela mostra um exemplo de uma pergunta. Como dito anteriormente, cada pergunta apresenta: ");Sleep(tempo);
    printf("\n\n 1) Uma letra que ficar� em destaque, escrita de acordo com a grafia do 'Braile'; e ");Sleep(tempo);
    printf("\n 2) Quatro outras letras (alternativas) escritas de acordo com o alfabeto latino.\n");Sleep(tempo);
    printf("\n Observe esta pergunta: ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual � a letra correspondente?                 ");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n Alternativa: ___ ");Sleep(tempo);
    printf("\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso o(a) jogador(a) acerte a quest�o, ganhar� 150 pontos!");Sleep(tempo);
    printf("\n");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual � a letra correspondente?");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n\n Alternativa: d ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                CERTA RESPOSTA!                | ");Sleep(tempo);
    printf("\n |           VOC� GANHOU: +150 PONTOS!           | ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n\n **** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n Caso contr�rio, ganhar� apenas 50 pontos: \n");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |             EXEMPLO DE PERGUNTA               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n |                   |o  o|                      |");Sleep(tempo);
    printf("\n |                   |   o|                      |");Sleep(tempo);
    printf("\n |                   |    |                      |");Sleep(tempo);
    printf("\n |                                               |");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n Qual � a letra correspondente?");Sleep(tempo);
    printf("\n\n a) A");Sleep(tempo);
    printf("\n b) B");Sleep(tempo);
    printf("\n c) C");Sleep(tempo);
    printf("\n d) D");Sleep(tempo);
    printf("\n\n Op��o : b ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n |     VOC� ERROU... RESPOSTA CORRETA: \"d)\"      | ");Sleep(tempo);
    printf("\n |           VOC� GANHOU: +50 PONTOS!            | ");Sleep(tempo);
    printf("\n +-----------------------------------------------+");Sleep(tempo);
    printf("\n\n**** Pressione qualquer tecla para continuar **** ");
    getche();
    system("cls");
    printf("\n No final do jogo, a tela de estat�sticas ser� exibida. Nele, � poss�vel observar:\n");Sleep(tempo);
    printf("\n   * O n�mero total de acertos do(a) jogador(a); e");Sleep(tempo);
    printf("\n   * A pontua��o final referente ao(�) mesmo(a).\n\n");Sleep(tempo);
    printf("\n                +--------------------------------------+");Sleep(tempo);
    printf("\n                |           SEU DESEMPENHO             |");Sleep(tempo);
    printf("\n                +--------------------------------------+");Sleep(tempo);
    printf("\n                |                                      |");Sleep(tempo);
    printf("\n                |        N� de acertos : 8 / 10        |");Sleep(tempo);
    printf("\n                |                                      |");Sleep(tempo);
    printf("\n                |       N� total de pontos : 1200      |");Sleep(tempo);
    printf("\n                |                                      |");Sleep(tempo);
    printf("\n                +--------------------------------------+");Sleep(tempo);
    addFade(2, 50, 1);
    banner();
    addFade(2, 50, 1);
    printf("\n **** Pressione qualquer tecla para retornar ao menu **** ");
    getche();
    system("cls");
    //addFade(30, 25, 1);
    return 0;
}

/* 6) Cr�ditos do Jogo */
void opcao6(){
    int tempo = 50;
    system("cls");
    printf("\t\t\t\t\t               ___                  \n");Sleep(tempo);
    printf("\t\t\t\t\t    _____     /__/  _ _ _           \n");Sleep(tempo);
    printf("\t\t\t\t\t   |     |___ ___ _| |_| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t\t\t   |   --|  _| -_| . | |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t\t\t   |_____|_| |___|___|_|_| |___|___|");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t +-----------------------------------------------------------------------------------+ ");Sleep(tempo);
    printf("\n\t\t | Este jogo foi originalmente desenvolvido como forma de avalia��o parcial para o   | ");Sleep(tempo);
    printf("\n\t\t | trabalho final do 1� ano do Curso T�cnico em Inform�tica, ofertado pelo Instituto | ");Sleep(tempo);
    printf("\n\t\t | Federal do Paran� - Campus Colombo. Tal trabalho foi apresentado no ano de 2017   | ");Sleep(tempo);
    printf("\n\t\t | sob o nome 'Acessibilidade das pessoas com defici�ncia visual na atualidade'.     | ");Sleep(tempo);
    printf("\n\t\t +-----------------------------------------------------------------------------------+ \n");Sleep(tempo);


    printf("\t\t\t      _____               _         _               _           \n");Sleep(tempo);
    printf("\t\t\t     |  _  |___ ___ ___ _| |___ ___|_|_____ ___ ___| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t     |     | . |  _| .'| . | -_|  _| |     | -_|   |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t     |__|__|_  |_| |__,|___|___|___|_|_|_|_|___|_|_|_| |___|___|\n");Sleep(tempo);
    printf("\t\t\t           |___|                                                \n");Sleep(tempo);
    printf("\t\t\t      (Membros da equipe original - Obrigado por todo o apoio!) \n");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n     -> Arthur Ogg - 'https://github.com/Arthur-Diesel'\n");Sleep(tempo);
    printf("\n     -> Guilherme Cordeiro - 'https://github.com/gui-cordeiro'\n");Sleep(tempo);
    printf("\n     -> Jo�o Lucas - Nenhum contato dele foi encontrado, mas fica aqui registrado o enorme agradecimento a ele!\n");Sleep(tempo);
    printf("\n     -> Lucas Pereira - 'https://github.com/Luc45-Pereira'\n");Sleep(tempo);
    printf("\n     -> Matheus Delay - 'https://twitter.com/DelayMath'\n");Sleep(tempo);
    banner();
    printf("\n\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getch();
    system("cls");
    github();
    printf("\n\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    //addFade(30, 25, 1);
    system("cls");
}


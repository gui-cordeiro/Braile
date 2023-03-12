/*
 * -> C�digo-Fonte do Jogo do Braile
 * -> Desenvolvido por: Guilherme Cordeiro
 * -> Ano: 2017, 2023
 */

/* 0) MENU PRINCIPAL */
int menu(int lin1, int col1, int qtd, char lista[][40]) {
    int opt = 1, lin2, col2, linhaSelecionada, i, tamMaxItem, tecla, limpar, espacamento, popup;
    titulo("-", "Menu Principal");

    topBannerContent("MENU");

    addFade(3, 50, 1);

    //Calculando as coordenadas
    tamMaxItem = strlen(lista[0]);

    //Tamanho m�ximo dos itens
    for(i = 1; i < qtd; i ++) {
        tamMaxItem = (strlen(lista[i]) > tamMaxItem) ? strlen(lista[i]) : tamMaxItem;
    }

    lin2 = lin1 + (qtd * 2 + 2);
    col2 = col1 + tamMaxItem + 3;

    //Montando a tela do menu
    textColor(WHITE, _BLUE);

    box(lin1, col1, lin2, col2);
    setlocale(LC_ALL, "C");
    textColor(WHITE, _BLACK);
    linhaCol(lin1 - 1, col1 + 12); printf("%c", 30);
    linhaCol(lin2 + 1, col1 + 12); printf("%c", 31);
    textColor(WHITE, _BLUE);
    setlocale(LC_ALL, "Portuguese");

    //La�o das op��es
    while(1){
        linhaSelecionada = lin1 + 2;
        for(i = 0; i < qtd; i ++) {
            if((i + 1) == opt) {
                textColor(BLUE, _WHITE);
                //PlaySound(TEXT("..\\sounds\\select.wav"), NULL, SND_ASYNC);
            } else {
                textColor(WHITE, _BLUE);
            }
            espacamento = (tamMaxItem - strlen(lista[i])) / 2; //Criar espa�amento para centralizar op��es no menu
            linhaCol(linhaSelecionada, col1 + 2 + espacamento);
            printf("%s", lista[i]);
            linhaSelecionada += 2;
        }

        textColor(WHITE, _BLACK);

        bottomBannerContent(opt);

        //Aguarda teclas
        linhaCol(1,1);
        tecla = getch();
        if (tecla == 0 || tecla == 224) tecla = getch();
        /*if (GetAsyncKeyState(VK_UP)&1)
            printf("Seta pra cima pressionada!");
        else if (GetAsyncKeyState(VK_DOWN)&1)
            printf("Seta pra baixo pressionada!");
        else if (GetAsyncKeyState(VK_LEFT)&1)
            printf("Seta pra esquerda pressionada!");
        else if (GetAsyncKeyState(VK_RIGHT)&1)
            printf("Seta pra direita pressionada!");
        else if (GetAsyncKeyState(VK_RETURN)&1)
            printf("Tecla ENTER pressionada!");*/
        if (tecla == 72 || (tecla == 119) || (tecla == 87)) { //Seta pra cima
            if(opt == 1) opt = qtd;
            else if (opt > 1) opt --;
        } else if (tecla == 80 || (tecla == 115) || (tecla == 83)) { //Seta pra baixo
            if (opt == qtd) opt = 1;
            else if (opt < qtd) opt ++;
        } else if (tecla == 13) { //ENTER
            break;
        } else if (tecla == 27) { //ESC
            opt = 9;
            break;
        } else if (tecla == 49) opt = 1;
        else if (tecla == 50) opt = 2;
        else if (tecla == 51) opt = 3;
        else if (tecla == 52) opt = 4;
        else if (tecla == 53) opt = 5;
        else if (tecla == 54) opt = 6;
        else if (tecla == 55) opt = 7;
        else if (tecla == 56) opt = 8;
        /*else if (tecla == 112 || tecla == 80) {
            char popupItens[][40] = {"SIM", "N�O"};
            while(popup != 2) {
                popup = modeloMenu(15, 50, 2, popupItens);
            }
            popup = 1;
            cleanScreen(6);
        }*/
    }
    //PlaySound(TEXT("..\\sounds\\confirm.wav"), NULL, SND_ASYNC);
    textColor(WHITE, _BLACK);
    return opt;
}

/* 1) JOGAR - N�VEL F�CIL */
void opcao1(){
    int cont = 20;
    int pts = 0, acertos = 0, erros = 0, pontos = 0, tecla = 0;
    int ordem[5];
    int progresso[5] = {2,2,2,2,2};
    char letras[5] = {'A', 'E', 'I', 'O', 'U'};
    char altAtuais[3] = {' ', ' ', ' '};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;

    if(confirmarJogo("F�CIL", progresso) == 0) return 0;
    topBannerContent("F�CIL");
    currentProgressionBanner("F�CIL", progresso, acertos, erros, pontos);

    titulo("F�CIL", "O jogo come�ar� em breve...");

    setlocale(LC_ALL, "C");
    linhaCol(14, 37); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("As letras em braile nesta dificuldade s�o");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(17, 37); printf("A          E          I          O          U ");
    linhaCol(18, 35); printf("|o   |     |o   |     |   o|     |o   |     |o   |");
    linhaCol(19, 35); printf("|    |     |   o|     |o   |     |   o|     |    |");
    linhaCol(20, 35); printf("|    |     |    |     |    |     |o   |     |o  o|");

    setlocale(LC_ALL, "C");
    linhaCol(23, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras acima e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");

    linhaCol(25, 45); printf("Tempo restante: %d segundo(s)",cont);
    do{
        //if (cont < 3) PlaySound(TEXT("..\\sounds\\countdown.wav"), NULL, SND_ASYNC);
        linhaCol(25, 45); printf("Tempo restante: %d segundo(s) ", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont > 0);
    fflush(stdin);
    cleanScreen(2);
    //PlaySound(TEXT("..\\sounds\\start.wav"), NULL, SND_ASYNC);
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 5; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta n� ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("F�CIL", tituloPergunta);

        perguntaEscolhida = ordem[numPergunta - 1];

        if (numPergunta == 1) { // Primeira pergunta
            altAtuais[0] = '-';
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        } else if (numPergunta == totPerguntas) {// �ltima pergunta
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = '-';
        } else { // Demais perguntas
            altAtuais[0] = letras[ordem[numPergunta - 2] - 1];
            altAtuais[1] = letras[ordem[numPergunta - 1] - 1];
            altAtuais[2] = letras[ordem[numPergunta] - 1];
        }

        if (newPergunta("F�CIL", numPergunta, altAtuais[0], altAtuais[1], altAtuais[2], &acertos, &erros, &pts, progresso) == true){
        } else {
        }
    }
    fimJogo("F�CIL", pts, acertos, totPerguntas);
    return;
}

/* 2) JOGAR - N�VEL M�DIO I */
void opcao2(){/*
    int cont = 35;
    int conf = 0, pts = 0, acertos = 0;
    int ordem[10];
    int progresso[10] = {2,2,2,2,2,2,2,2,2,2};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    char tituloPergunta[15];
    char numPerguntaChar[3];
    int perguntaEscolhida = 0;
    if(confirmarJogo("M�DIO I", progresso) == 0) return 0;
    topBannerContent("M�DIO I");
    currentProgressionBanner("M�DIO I", progresso);
    titulo("M�DIO I", "O jogo come�ar� em breve...");
    setlocale(LC_ALL, "C");
    linhaCol(12, 37); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("As letras em braile nesta dificuldade s�o");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(15, 37); printf("B          C          D          F          G   ");
    linhaCol(16, 35); printf("|o   |     |o  o|     |o  o|     |o  o|     |o  o|");
    linhaCol(17, 35); printf("|o   |     |    |     |   o|     |o   |     |o  o|");
    linhaCol(18, 35); printf("|    |     |    |     |    |     |    |     |    |");
    linhaCol(20, 37); printf("H          J          K          L          M   ");
    linhaCol(21, 35); printf("|o   |     |   o|     |o   |     |o   |     |o  o|");
    linhaCol(22, 35); printf("|o  o|     |o  o|     |    |     |o   |     |    |");
    linhaCol(23, 35); printf("|    |     |    |     |o   |     |o   |     |o   |");
    setlocale(LC_ALL, "C");
    linhaCol(26, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras acima e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(28, 45); printf("Tempo restante: %d segundo(s)",cont);
    Sleep(1000);
    cont --;
    do{
        //if (cont < 3) PlaySound(TEXT("..\\sounds\\countdown.wav"), NULL, SND_ASYNC);
        linhaCol(28, 45); printf("Tempo restante: %d segundo(s) ", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont >= 0);
    system("cls");
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 10; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta n� ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("M�DIO I", tituloPergunta);

        perguntaEscolhida = ordem[numPergunta - 1];
        switch(perguntaEscolhida){
            case 1:
                if(newPergunta(2, numPergunta, 'B', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 2:
                if(newPergunta(2, numPergunta, 'C', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 3:
                if(newPergunta(2, numPergunta, 'D', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 4:
                if(newPergunta(2, numPergunta, 'F', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 5:
                if(newPergunta(2, numPergunta, 'G', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 6:
                if(newPergunta(2, numPergunta, 'H', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 7:
                if(newPergunta(2, numPergunta, 'J', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 8:
                if(newPergunta(2, numPergunta, 'K', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 9:
                if(newPergunta(2, numPergunta, 'L', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 10:
                if(newPergunta(2, numPergunta, 'M', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
        }
    }
    fimJogo("M�DIO I", pts, acertos, totPerguntas);*/
    return;
}

/* 3) JOGAR - N�VEL M�DIO II */
void opcao3(){/*
    int cont = 40;
    int conf = 0, pts = 0, acertos = 0;
    int ordem[11];
    int progresso[11] = {2,2,2,2,2,2,2,2,2,2,2};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    int perguntaEscolhida = 0;
    char tituloPergunta[15];
    char numPerguntaChar[3];
    if(confirmarJogo("M�DIO II", progresso) == 0) return 0;
    topBannerContent("M�DIO II");
    titulo("M�DIO II", "O jogo come�ar� em breve...");
    setlocale(LC_ALL, "C");
    linhaCol(10, 37); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("As letras em braile nesta dificuldade s�o");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(12, 37); printf("N          P          Q          R          S");
    linhaCol(13, 35); printf("|o  o|     |o  o|     |o  o|     |o   |     |   o|");
    linhaCol(14, 35); printf("|   o|     |o   |     |o  o|     |o  o|     |o   |");
    linhaCol(15, 35); printf("|o   |     |o   |     |o   |     |o   |     |o   |");
    linhaCol(17, 37); printf("T          V          W          X          Y ");
    linhaCol(18, 35); printf("|   o|     |o   |     |   o|     |o  o|     |o  o|");
    linhaCol(19, 35); printf("|o  o|     |o   |     |o  o|     |    |     |   o|");
    linhaCol(20, 35); printf("|o   |     |o  o|     |   o|     |o  o|     |o  o|");
    linhaCol(22, 59); printf("Z");
    linhaCol(23, 57); printf("|o   |");
    linhaCol(24, 57); printf("|   o|");
    linhaCol(25, 57); printf("|o  o|");
    setlocale(LC_ALL, "C");
    linhaCol(28, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras acima e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(30, 45); printf("Tempo restante: %d segundo(s)",cont);
    Sleep(1000);
    cont --;
    do{
        //if (cont < 3) PlaySound(TEXT("..\\sounds\\countdown.wav"), NULL, SND_ASYNC);
        linhaCol(30, 45); printf("Tempo restante: %d segundo(s) ", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont >= 0);
    system("cls");
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 11; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta n� ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("M�DIO II", tituloPergunta);
        perguntaEscolhida = ordem[numPergunta - 1];
        switch(perguntaEscolhida){
            case 1:
                if(newPergunta(3, numPergunta, 'N', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 2:
                if(newPergunta(3, numPergunta, 'P', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 3:
                if(newPergunta(3, numPergunta, 'Q', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 4:
                if(newPergunta(3, numPergunta, 'R', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 5:
                if(newPergunta(3, numPergunta, 'S', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 6:
                if(newPergunta(3, numPergunta, 'T', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 7:
                if(newPergunta(3, numPergunta, 'V', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 8:
                if(newPergunta(3, numPergunta, 'W', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 9:
                if(newPergunta(3, numPergunta, 'X', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 10:
                if(newPergunta(3, numPergunta, 'Y', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 11:
                if(newPergunta(3, numPergunta, 'Z', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
        }
    }
    fimJogo("M�DIO II", pts, acertos, totPerguntas);*/
    return;
}

/* 4) JOGAR - N�VEL DIF�CIL */
void opcao4(){/*
    int cont = 60;
    int conf = 0, pts = 0, acertos = 0;
    int ordem[26];
    int progresso[26] = {2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2};
    size_t totPerguntas = sizeof(ordem)/sizeof(ordem[0]);
    int perguntaEscolhida = 0;
    char tituloPergunta[15];
    char numPerguntaChar[3];
    if(confirmarJogo("DIF�CIL", progresso) == 0) return 0;


    topBannerContent("DIF�CIL");
    titulo("DIF�CIL", "O jogo come�ar� em breve...");
    setlocale(LC_ALL, "C");
    linhaCol(10, 37); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("As letras em braile nesta dificuldade s�o");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(12, 16); printf("A          B          C          D          E          F          G          H          I");
    linhaCol(13, 14); printf("|o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |     |   o|");
    linhaCol(14, 14); printf("|    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|     |o   |");
    linhaCol(15, 14); printf("|    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |     |    |");
    linhaCol(17, 16); printf("J          K          L          M          N          O          P          Q          R");
    linhaCol(18, 14); printf("|   o|     |o   |     |o   |     |o  o|     |o  o|     |o   |     |o  o|     |o  o|     |o   |");
    linhaCol(19, 14); printf("|o  o|     |    |     |o   |     |    |     |   o|     |   o|     |o   |     |o  o|     |o  o|");
    linhaCol(20, 14); printf("|    |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |     |o   |");
    linhaCol(22, 21); printf("S          T          U          V          W          X          Y          Z");
    linhaCol(23, 19); printf("|   o|     |   o|     |o   |     |o   |     |   o|     |o  o|     |o  o|     |o   |");
    linhaCol(24, 19); printf("|o   |     |o  o|     |    |     |o   |     |o  o|     |    |     |   o|     |   o|");
    linhaCol(25, 19); printf("|o   |     |o   |     |o  o|     |o  o|     |   o|     |o  o|     |o  o|     |o  o|");

    setlocale(LC_ALL, "C");
    linhaCol(28, 36); printf("%c ", 254);
    setlocale(LC_ALL, "Portuguese");
    printf("Tente memorizar as letras acima e boa sorte!");
    setlocale(LC_ALL, "C");
    printf(" %c", 254);
    setlocale(LC_ALL, "Portuguese");
    linhaCol(30, 45); printf("Tempo restante: %d segundo(s)",cont);
    Sleep(1000);
    cont --;
    do{
        //if (cont < 3) PlaySound(TEXT("..\\sounds\\countdown.wav"), NULL, SND_ASYNC);
        linhaCol(30, 45); printf("Tempo restante: %d segundo(s) ", cont);
        for (int fast = 0; fast < 78; fast ++) {
            Sleep(10);
            if (GetAsyncKeyState(VK_SHIFT)) {
                Sleep(80);
                break;
            }
        }
        cont --;
    }while(cont >= 0);
    system("cls");
    gerarSeqPerguntas(ordem, totPerguntas);
    for (int numPergunta = 1; numPergunta <= 26; numPergunta ++) {
        strcpy(tituloPergunta, "Pergunta n� ");
        if (numPergunta < 10) strcat(tituloPergunta, "0");
        sprintf(numPerguntaChar, "%d", numPergunta);
        strcat(tituloPergunta, numPerguntaChar);
        titulo("DIF�CIL", tituloPergunta);
        perguntaEscolhida = ordem[numPergunta - 1];
        switch(perguntaEscolhida){
            case 1:
                if(newPergunta(4, numPergunta, 'A', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 2:
                if(newPergunta(4, numPergunta, 'B', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 3:
                if(newPergunta(4, numPergunta, 'C', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 4:
                if(newPergunta(4, numPergunta, 'D', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 5:
                if(newPergunta(4, numPergunta, 'E', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 6:
                if(newPergunta(4, numPergunta, 'F', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 7:
                if(newPergunta(4, numPergunta, 'G', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 8:
                if(newPergunta(4, numPergunta, 'H', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 9:
                if(newPergunta(4, numPergunta, 'I', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 10:
                if(newPergunta(4, numPergunta, 'J', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 11:
                if(newPergunta(4, numPergunta, 'K', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 12:
                if(newPergunta(4, numPergunta, 'L', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 13:
                if(newPergunta(4, numPergunta, 'M', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 14:
                if(newPergunta(4, numPergunta, 'N', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 15:
                if(newPergunta(4, numPergunta, 'O', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 16:
                if(newPergunta(4, numPergunta, 'P', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 17:
                if(newPergunta(4, numPergunta, 'Q', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 18:
                if(newPergunta(4, numPergunta, 'R', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 19:
                if(newPergunta(4, numPergunta, 'S', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 20:
                if(newPergunta(4, numPergunta, 'T', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 21:
                if(newPergunta(4, numPergunta, 'U', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 22:
                if(newPergunta(4, numPergunta, 'V', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 23:
                if(newPergunta(4, numPergunta, 'W', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 24:
                if(newPergunta(4, numPergunta, 'X', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 25:
                if(newPergunta(4, numPergunta, 'Y', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
            case 26:
                if(newPergunta(4, numPergunta, 'Z', pts, acertos) == 1){
                    pts += 150; acertos ++;
                }else pts += 50;
            break;
        }
    }
    fimJogo("DIF�CIL", pts, acertos, totPerguntas);*/
    return;
}

/* 5) Ranking dos Jogadores*/
void opcao5(){
    int tecla;
    titulo("-", "Ranking dos Jogadores");
    cleanScreen(1);
    linhaCol(35, 7); printf("Essa aqui � a futura tela do ranking de jogadores, que est� em desenvolvimento. Aproveite a musiquinha! :D");
    linhaCol(36, 41); printf("Pressione a tecla ENTER pra sair daqui.");
    while(1) {
        tecla = getch();
        tecla = (tecla == 0 || tecla == 224) ? getch() : tecla;
        if (tecla == 13) break;
    }
    cleanScreen(1);
}

/* 6) INSTRU��ES DO JOGO */
int opcao6(){
    titulo("-", "Tela de Instru��es");
    int finalopt = 0, erro = 0;
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
        addFade(1, tempo, 1);
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
        printf("\t     | * Uma letra exibida em destaque e de acordo com o sistema 'Braile' de escrita; e         |\n");Sleep(tempo);
        printf("\t     | * Quatro letras referentes �s alternativas, exibidas de acordo com o alfabeto latino.    |\n");Sleep(tempo);
        printf("\t     |                                                                                          |\n");Sleep(tempo);
        printf("\t     | Para responder tais perguntas, � necess�rio memorizar as letras que aparecer�o na tela   |\n");Sleep(tempo);
        printf("\t     | por alguns segundos.                                                                     |\n");Sleep(tempo);
        printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
        addFade(3, tempo, 1);
        showCursor();
        printf("\t\t        DESEJA VER UM EXEMPLO DO JOGO? (Digite 'S' para Sim ou 'N' para N�o): ");
        fgets(opt, 100, stdin);
        hideCursor();
        finalopt = verifyOpt(opt, 1);
        if (finalopt == 0) {
            system("cls");
            erro ++;
            printf("\n");
            telaErro();
            addFade(1, tempo, 1);
        } else if (finalopt == 2) {
            addFade(2, 0, 0);
            addFade(37, 25, 1);
            system("cls");
            return 0;
        }
    } while (finalopt != 1);
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("EXEMPLO");
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Como dito anteriormente, neste jogo cada pergunta � composta por:                        |\n");Sleep(tempo);
    printf("\t     |                                                                                          |\n");Sleep(tempo);
    printf("\t     | * Uma letra exibida em destaque e de acordo com o sistema 'Braile' de escrita; e         |\n");Sleep(tempo);
    printf("\t     | * Quatro letras referentes �s alternativas, exibidas de acordo com o alfabeto latino.    |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |     Letra escrita em Braile (EM DESTAQUE)     |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |                                               |");Sleep(tempo);
    printAlfabeto('E', 34, true);
    printf("\n\t\t\t\t   |                                               |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\n\t\t\t\t\t     * Alternativas propostas *\n\n");Sleep(tempo);
    printf("\n\t\t\t\t\t      a) --> A        c) --> E");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n\t\t\t\t\t      b) --> I        d) --> O");Sleep(tempo);
    addFade(4, tempo, 1);
    printf("\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getche();
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("EXEMPLO");
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Respondendo a quest�o corretamente, voc� ganhar� 150 pontos! Veja o exemplo a seguir:    |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |     Letra escrita em Braile (EM DESTAQUE)     |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |                                               |");Sleep(tempo);
    printAlfabeto('E', 34, true);
    printf("\n\t\t\t\t   |                                               |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\n\t\t\t\t\t      a) --> A        c) --> E");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n\t\t\t\t\t      b) --> I        d) --> O");Sleep(tempo);
    printf("\n\n\t\t\t\t\t       +--------------------+\n");Sleep(tempo);
    printf("\n\t\t\t\t\t\tInsira sua op��o : c");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t   |                CERTA RESPOSTA!                | ");Sleep(tempo);
    printf("\n\t\t\t\t   |           VOC� GANHOU: +150 PONTOS!           | ");Sleep(tempo);
    printf("\n\t\t\t\t   +----------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getche();
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("EXEMPLO");
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Caso erre a resposta, apenas 50 pontos ser�o somados � sua pontua��o. Veja o exemplo:    |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |     Letra escrita em Braile (EM DESTAQUE)     |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t   |                                               |");Sleep(tempo);
    printAlfabeto('E', 34, true);
    printf("\n\t\t\t\t   |                                               |\n");Sleep(tempo);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\n\t\t\t\t\t      a) --> A        c) --> E");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n\t\t\t\t\t      b) --> I        d) --> O");Sleep(tempo);
    printf("\n\n\t\t\t\t\t       +--------------------+\n");Sleep(tempo);
    printf("\n\t\t\t\t\t\tInsira sua op��o : a");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t   +-----------------------------------------------+");Sleep(tempo);
    printf("\n\t\t\t\t   |     VOC� ERROU... RESPOSTA CORRETA: \"c)\"      | ");Sleep(tempo);
    printf("\n\t\t\t\t   |           VOC� GANHOU: +50 PONTOS!            | ");Sleep(tempo);
    printf("\n\t\t\t\t   +----------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getche();
    system("cls");
    addFade(1, tempo, 1);
    exibirBannerDificuldade("EXEMPLO");
    addFade(2, tempo, 1);
    printf("\t     +------------------------------------------------------------------------------------------+\n");Sleep(tempo);
    printf("\t     | Ao encerrar o quiz, ser� poss�vel analisar o seu desempenho final. Nele voc� poder� ver: |\n");Sleep(tempo);
    printf("\t     |                                                                                          |\n");Sleep(tempo);
    printf("\t     | * O \"N�mero de perguntas respondidas corretamente\" / \"N�mero total de perguntas\"; e      |\n");Sleep(tempo);
    printf("\t     | * A pontua��o total com base nos acertos e erros cometidos durante o quiz.               |\n");Sleep(tempo);
    printf("\t     |                                                                                          |\n");Sleep(tempo);
    printf("\t     | Divirta-se com o \"Jogo do Braile\"!                                                       |\n");Sleep(tempo);
    printf("\t     +------------------------------------------------------------------------------------------+");Sleep(tempo);
    addFade(3, tempo, 1);
    printf("\t\t\t\t       +---------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t       |       EXEMPLO DAS ESTAT�STICAS        |\n");Sleep(tempo);
    printf("\t\t\t\t       +---------------------------------------+\n");Sleep(tempo);
    printf("\t\t\t\t       |                                       |\n");Sleep(tempo);
    printf("\t\t\t\t       |        Total de ACERTOS: 5 / 5        |\n");
    printf("\t\t\t\t       |                                       |\n");Sleep(tempo);
    printf("\t\t\t\t       |         Total de PONTOS: 750          |\n");
    printf("\t\t\t\t       |                                       |\n");Sleep(tempo);
    printf("\t\t\t\t       +---------------------------------------+");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t\t\t\t\t\t *****");Sleep(tempo);
    addFade(1, tempo, 1);
    banner();
    addFade(2, 50, 1);
    printf("\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getche();
    addFade(39, 25, 1);
    system("cls");
    return 0;
}

/* 7) CR�DITOS DO JOGO */
void opcao7(){
    system("cls");
    titulo("-", "Cr�ditos do Jogo");
    printf("\t\t\t\t\t                __                  \n");Sleep(tempo);
    printf("\t\t\t\t\t    _____      /_/  _ _ _           \n");Sleep(tempo);
    printf("\t\t\t\t\t   |     |___ ___ _| |_| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t\t\t   |   --|  _| -_| . | |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t\t\t   |_____|_| |___|___|_|_| |___|___|");Sleep(tempo);
    addFade(2, tempo, 1);
    printf("\t\t +-----------------------------------------------------------------------------------+ ");Sleep(tempo);
    printf("\n\t\t | Este jogo foi originalmente desenvolvido como forma de uma avalia��o parcial do   | ");Sleep(tempo);
    printf("\n\t\t | trabalho final do 1� ano do Curso T�cnico em Inform�tica, ofertado pelo Instituto | ");Sleep(tempo);
    printf("\n\t\t | Federal do Paran� - Campus Colombo. Tal trabalho foi apresentado no ano de 2017   | ");Sleep(tempo);
    printf("\n\t\t | sob o nome 'Acessibilidade das pessoas com defici�ncia visual na atualidade'.     | ");Sleep(tempo);
    printf("\n\t\t +-----------------------------------------------------------------------------------+ \n");Sleep(tempo);


    printf("\t\t\t      _____               _         _               _           \n");Sleep(tempo);
    printf("\t\t\t     |  _  |___ ___ ___ _| |___ ___|_|_____ ___ ___| |_ ___ ___ \n");Sleep(tempo);
    printf("\t\t\t     |     | . |  _| .'| . | -_|  _| |     | -_|   |  _| . |_ -|\n");Sleep(tempo);
    printf("\t\t\t     |__|__|_  |_| |__,|___|___|___|_|_|_|_|___|_|_|_| |___|___|\n");Sleep(tempo);
    printf("\t\t\t           |___|                                                \n");Sleep(tempo);
    printf("\t\t\t(Membros da equipe do trabalho original - Obrigado por todo o apoio!) \n");Sleep(tempo);
    addFade(1, tempo, 1);
    printf("\n     -> Arthur Ogg - 'https://github.com/Arthur-Diesel'\n");Sleep(tempo);
    printf("\n     -> Guilherme Cordeiro - 'https://github.com/gui-cordeiro'\n");Sleep(tempo);
    printf("\n     -> Jo�o Lucas - Nenhum contato dele foi encontrado, mas fica aqui registrado o agradecimento a ele!\n");Sleep(tempo);
    printf("\n     -> Lucas Pereira - 'https://github.com/Luc45-Pereira'\n");Sleep(tempo);
    printf("\n     -> Matheus Delay - 'https://twitter.com/DelayMath'\n");Sleep(tempo);
    banner();
    printf("\n\t\t\t\t   **** Pressione qualquer tecla para continuar ****");
    getch();
    system("cls");
    addFade(4, 50, 0);
    exibirTelaGitHub();
    printf("\n\t\t\t       **** Pressione qualquer tecla para retornar ao menu ****");
    getch();
    addFade(39, 25, 1);
    system("cls");
}

/* 8) SAIR DO JOGO */
void opcao8(){
    system("cls");
    PlaySound(TEXT("..\\sounds\\ending.wav"), NULL, SND_ASYNC);
    titulo("-", "Obrigado por Jogar!");
    exibirBannerDificuldade("AGRADECIMENTO");
    Sleep(1500);
    addFade(2, 50, 1);
    exibirTelaGitHub();
    Sleep(1100);
    printf("\n\t\t\t\t  **** Pressione qualquer tecla para sair do jogo ****");
    getchar();
    PlaySound(TEXT("..\\sounds\\intro.wav"), NULL, SND_ASYNC);
    titulo("-", "Saindo do Jogo...");
    addFade(2, 0, 0);
    addFade(37, 175, 1);
    system("cls");
    system("mode con:cols=120 lines=30");
    showCursor();
}

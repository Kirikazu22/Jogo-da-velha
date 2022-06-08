#include <iostream>
#include <windows.h>
 
using namespace std;

// variável board armazena o tabuleiro
int board[3][3];
// variável linha recebe a linha do tabuleiro que o usuário deseja jogar
int linha=0;
// variável coluna recebe a coluna do tabuleiro que o usuário deseja jogar
int coluna=0;
// caso sim, a variável confirm reinicia o jogo, caso não o jogo é finalizado
int confirm=0;
// variável point1 para armazenar a pontuação do jogador 1
int point1=0;
// variável point2 para armazenar a pontuação do jogador 2
int point2=0;
// variável a verifica se o erro está na linha ou na coluna
int a=0;
// variável b verifica se o erro aconteceu com o jogador 1 ou 2
int b=0;
// variável fim serve para verificar se a partida acabou
bool fim=false;
// variável player1 armazena o nome do jogador 1
string player1;
// variável player2 armazena o nome do jogador 2
string player2;

// função start zera o valor de todas as posições do tabuleiro
void start(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            board[i][j]=0;
        }
    }
}

// função play imprime o nome e a pontuação dos jogadores e pergunta ao usuário se ele deseja jogar novamente ou sair do jogo
void play(){
    cout<<"\n\n"<<player1<<": "<<point1;
    cout<<"\t"<<player2<<": "<<point2;
    cout<<"\n\n1. Play"<<endl;
    cout<<"0. Quit"<<endl;
    // variável confirm recebe o valor que o usuário digitar
    cin >> confirm;
    system("cls");
    // quando a variável fim recebe o valor 'false' a partida é finalizada dentro da classe main
    fim=false;
}

// função check_imp imprime um ' ' quando a posição do tabuleiro tiver valor 0, imprime 'x' quando tiver valor 1 e 'o' quando tiver valor 2
void check_imp(int plinha, int pcoluna){
    if(board[plinha][pcoluna]==0){
        cout<<" ";
    }else if(board[plinha][pcoluna]==1){
        cout<<"x";
    }else if(board[plinha][pcoluna]==2){
        cout<<"o";
    }
}

// função show imprime o tabuleiro
void show(){
    system("cls");
        for(int row=0; row<3 ;row++){
            cout<<" ";
            check_imp(row, 0);
            cout <<" | ";
            check_imp(row, 1);
            cout <<" | ";
            check_imp(row, 2);
            cout<<endl;
                if(row!=2){
                    cout<<"-----------";
                }
            cout<<endl; 
        }
}

// função endgame verifica se o jogo acabou
bool endgame(){
    // if para verificar se o jogador 1 ganhou
    if((board[0][0]==1 && board[1][0]==1 && board[2][0]==1)||(board[0][1]==1 && board[1][1]==1 && board[2][1]==1)||
    (board[0][2]==1 && board[1][2]==1 && board[2][2]==1)||(board[0][0]==1 && board[0][1]==1 && board[0][2]==1)||
    (board[1][0]==1 && board[1][1]==1 && board[1][2]==1)||(board[2][0]==1 && board[2][1]==1 && board[2][2]==1)||
    (board[0][0]==1 && board[1][1]==1 && board[2][2]==1)||(board[2][0]==1 && board[1][1]==1 && board[0][2]==1)){
        // imprime 'o nome do jogador 1' foi o vencedor!
        cout<<player1<<" foi o vencedor!\n";
        // adiciona um ponto ao jogador 1
        point1++;
        // fim recebe o valor 'true' para que partida acabe na função main
        fim=true;
        // retorna o valor 'true' para que a função play acabe na função game
        return true;
    //senão, if para verificar se o jogador 2 ganhou e executa o mesmo procedimento que o if anterior
    }else if((board[0][0]==2 && board[1][0]==2 && board[2][0]==2)||(board[0][1]==2 && board[1][1]==2 && board[2][1]==2)||
    (board[0][2]==2 && board[1][2]==2 && board[2][2]==2)||(board[0][0]==2 && board[0][1]==2 && board[0][2]==2)||
    (board[1][0]==2 && board[1][1]==2 && board[1][2]==2)||(board[2][0]==2 && board[2][1]==2 && board[2][2]==2)||
    (board[0][0]==2 && board[1][1]==2 && board[2][2]==2)||(board[2][0]==2 && board[1][1]==2 && board[0][2]==2)){
        cout<<player2<<" foi o vencedor!\n";
        point2++;
        fim=true;
        return true;
    //senão, if para verificar se o jogo empatou e executa o mesmo procedimento que o if anterior
    }else if(board[0][0]!=0 && board[0][1]!=0 && board[0][2]!=0 && board[1][0]!=0 && board[1][1]!=0 && board[1][2]!=0 && 
    board[2][0]!=0 && board[2][1]!=0 && board[2][2]!=0){
        cout<<"Empate!\n";
        fim=true;
        return true;
    }
    //senão, retorna o valor 'false' para que a função play continue na função game
    return false;
}

// função error imprime tudo que já foi feito quando o usuário digitar uma opção inválida (serve para complementar a função check)
void error(){
    show();
        // if b==0 o erro ocorreu com o jogador 1
        if(b==0){
            // if a==0 o erro ocorreu com a linha
            if(a==0){
                cout<<player1<<":"<<endl;
                cout<<"linha: ";
            // senão, if a==1 o erro ocorreu com a coluna
            }else{
                cout<<player1<<":"<<endl;
                cout<<"linha: "<<linha<<endl;
                cout<<"coluna: ";
            }
        // senão, if b==1 o erro ocorreu com o jogador 2
        }else{
            // if a==0 o erro ocorreu com a linha
            if(a==0){
                cout<<player2<<":"<<endl;
                cout<<"linha: ";
            // senão, if a==1 o erro ocorreu com a coluna
            }else{
                cout<<player2<<":"<<endl;
                cout<<"linha: "<<linha<<endl;
                cout<<"coluna: ";
            }
        }  
}

// função check verifica se o jogador digitou uma opção válida
int check(){
    // variável num recebe o valor digitado pelo usuário
    int num;
        // while é executada até que o valor seja válido
        while (scanf("%d", &num) != 1){
            static char temp[256];
            fgets(temp, sizeof(temp), stdin);
            // quando a opção digitada não for válida, a função error é executada para imprimir o que já foi feito
            error();
        }
    // retorna o valor digitado pelo usuário, quando ele for válido
    return num;
}

// função game é a função principal do jogo, que executa todas as funções necessárias para o funcionamento do jogo
void game(){
    // variável valid serve para verificar se a posição escolhida pelo jogador está disponível
    bool valid=false;
        // loop do, while é executado até que a posição escolhida pelo jogador seja válida
        do{
            cout<<player1<<":"<<endl;
            cout<<"linha: ";
            // linha=check() utiliza a função check para ler e verificar se o jogador digitou uma opção válida
            linha=check();
            // a=1 indica que a linha escolhida é válida
            a=1;
            cout<<"coluna: ";
            // coluna=check() utiliza a função check para ler e verificar se o jogador digitou uma opção válida
            coluna=check();
            // a=0 indica que a coluna escolhida é válida
            a=0;
                // linha-1 e coluna-1 são utilizados para que o jogador escolha a posição no tabuleiro de 1 a 3 e não de 0 a 2
                // if a posição estiver vazia, a variável valid recebe o valor 'true' e a posição é preenchida
                if(board[linha-1][coluna-1]==0){
                    board[linha-1][coluna-1]=1;
                    // valid=true indica que a posição escolhida é válida para finalizar o loop
                    valid=true;
                }
            // show() atualiza o tabuleiro
            show();
            // b=1 indica que o jogador 1 já jogou
            b=1;
        }while(valid==false);
            // valid é resetada para que a função o próximo loop possa ser executado sem problemas
            valid=false;
                // if(endgame()==false) verifica se o jogo acabou na vez do jogador 1, se não, passa a vez para o jogador 2 onde ocorre
                // o mesmo procedimento do jogador 1
                if(endgame()==false){
                    do{
                        cout<<player2<<":"<<endl;
                        cout<<"linha: ";
                        linha=check();
                        a=1;
                        cout<<"coluna: ";
                        coluna=check();
                        a=0;
                            if(board[linha-1][coluna-1]==0){
                                board[linha-1][coluna-1]=2;
                                valid=true;
                            }
                        show();
                        // b=2 indica que o jogador 2 já jogou
                        b=0;
                        // endgame() verifica se o jogo acabou na vez do jogador 2
                        endgame();
                    }while(valid==false);
                }   
    // valid é resetada para que a função o próximo o primeiro loop seja executado sem problemas
    valid=false;
}

// função main chama todas as funções necessárias e executa o jogo
int main(){
    cout<<"Digite o nome do primeiro jogador: ";
    // player1 recebe o nome digitado pelo usuário
    cin>>player1;
    system("cls");
    cout<<"Digite o nome do segundo jogador: ";
    // player2 recebe o nome digitado pelo usuário
    cin>>player2;
        // loop do, while é executada enquanto o usuário selecionar a opção '1' para jogar novamente
    system("cls");
        do{
            // start() zera as posições da variável board para que o jogo possa jogado novamente
            start();
                // loop do, while é executado enquanto o jogo não acabar, representando as jogadas
                do{
                    // atualiza o tabuleiro
                    show();
                    // game() executa as funções necessárias para o funcionamento do jogo
                    game();
                }while(fim==false);
                    // play() imprime o nome do vercedor a pontuação do jogador 1 e do jogador 2 e as opções de jogo
                    play();
        }while (confirm == 1);
}
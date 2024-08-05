#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

void limpa_tela() { 
    system("clear");
}

// Função que gera palavra aleatoriamente para o jogo
string retorna_palavra_aleatoria() {
    // Determina as palavras que serão escolhidas aleatoriamente
    string palavras[3] = {"Abacaxi", "Manga", "Morango"};
    // Cria uma variável -> gera um número aleatório -> divide nº aleatório por 3 -> resulta em 0, 1 ou 2
    int indice_aleatorio = rand() % 3;
    // Retorna a palavra escolhida de forma aleatória
    return palavras[indice_aleatorio];
}

// Função que retorna palavra com máscara
string retorna_mascara_da_palavra(string palavra, int tamanho_da_palavra) {
    // Declara contador auxiliar e string vazia para armazenar a máscara posteriormente
    int contador = 0;
    string mascara_da_palavra;
    // Laço para adicionar underline para cada letra da palavra
    while(contador < tamanho_da_palavra) {
        mascara_da_palavra += "_";
        contador += 1;
    }
    return mascara_da_palavra;
}

void exibe_status(string mascara_da_palavra, int tamanho_da_palavra, int tentativas_restantes) {
    cout << "\nA palavra é: " << mascara_da_palavra << " (tamanho: " << tamanho_da_palavra << " letras)\n";
    cout << "\n\nTentativas restantes: " << tentativas_restantes;
}

// Função para atualizar a máscara da palavra
void atualiza_mascara(string &mascara, string palavra, char letra) {
    for (int i = 0; i < palavra.size(); i++) {
        if (palavra[i] == letra) {
            mascara[i] = letra;
        }
    }
}

// Função jogar sozinho utilizando palavra aleatória
void jogar_sozinho() {
    // Declara variável palavra e chama função que escolhe uma palavra aleatoriamente para o jogo
    string palavra = retorna_palavra_aleatoria();
    // Declara variável que calcula o número de letras da palavra escolhida
    int tamanho_da_palavra = palavra.size();
    // Chama a função de criar máscara para palavra escolhida
    string mascara_da_palavra = retorna_mascara_da_palavra(palavra, tamanho_da_palavra);
    // Laço de tentativas do usuário
    int tentativas = 0, maximo_de_tentativas = 5;
    char letra;
    bool acertou = false;

    while (tentativas < maximo_de_tentativas && mascara_da_palavra != palavra) {
        // Chama função de status das tentativas
        exibe_status(mascara_da_palavra, tamanho_da_palavra, maximo_de_tentativas - tentativas);

        cout << "\n\nDigite uma letra: ";
        cin >> letra;
        cout << "\n- - - - - - - - - - - - - - - - - - - - - \n";
        
        acertou = false;
        for (int i = 0; i < tamanho_da_palavra; i++) {
            if (palavra[i] == letra) {
                mascara_da_palavra[i] = letra;
                acertou = true;
            }
        }

        if (!acertou) {
            tentativas++;
        }

        limpa_tela();
    }

    if (mascara_da_palavra == palavra) {
        cout << "Parabéns! Você acertou a palavra: " << palavra << endl;
    } else {
        cout << "Você perdeu! A palavra era: " << palavra << endl;
    }
}

// Função menu inicial
void menu_inicial() {
    int opcao = 0;
    
    // Cria laço até usuário escolher uma opção válida
    while (opcao < 1 || opcao > 3) {
        // Saudação ao usuário
        cout << "Bem vindo ao jogo da forca \n\n";
        // Pede para usuário escolher uma opção 
        cout << "1- JOGAR\n";
        cout << "2- SOBRE\n";
        cout << "3- SAIR\n";
        cout << "Escolha uma opção acima e aperte enter: ";
        cin >> opcao;
        
        switch (opcao) {
            case 1:
                // Inicia o jogo
                jogar_sozinho();
                break;
            case 2:
                // Apresenta informações sobre o jogo
                cout << "\nCriado em 2023 por Ricardo Formagio\n";
                break;
            case 3:
                // Sai do jogo
                cout << "\nVocê saiu do jogo\n";
                break;
        }
    }
}

int main() {
    // Para gerar números realmente aleatórios
    srand((unsigned)time(NULL));
    menu_inicial();
    return 0;
}
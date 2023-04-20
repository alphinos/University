#include <stdio.h>
#define N_PONTOS 6

void printf_recursivo(int n_pontos, int pontos[]) {
  static int camsUtilizadas[N_PONTOS];
  static int totalCorredores[N_PONTOS];
  static int pontosObservados[N_PONTOS];

  int qtd = 0;

  int maior = -1;
  static int somaTot = 0;

  // Condição de parada da função recursiva
  if (somaTot >= N_PONTOS) {
    for (int i = 0; i < N_PONTOS; i++) {
      if (camsUtilizadas[i] == 1) {
        printf("O ponto %d deve receber uma câmera!\n", i);
      }
    }

    return;
  }

  // Atribui o total de corredores que cada ponto se conecta ao vetor totalCorredores
  // Para cada conexão com outro ponto que cada ponto possui, adiciona-se 1
  for (int i = 0; i < N_PONTOS; i++) {
    qtd = 0;
    for (int j = 0; j < N_PONTOS; j++) {
      if (pontos[N_PONTOS * i + j] == 1) {
        qtd++;
      }
    }
    totalCorredores[i] = qtd;
  }

  // Encontra-se o maior elemento do vetor totalCorredores
  for (int i = 0; i < N_PONTOS; i++) {
    for (int j = i; j < N_PONTOS; j++) {
      if (totalCorredores[i] > maior) {
        maior = totalCorredores[i];
      }
    }
  }

  // Realiza as operações de atribuição
  for (int i = 0; i < N_PONTOS; i++) {
    if (totalCorredores[i] == maior) {
      if (pontosObservados[i]){
        continue;
      }
      //Zera a linha com maior pontos, marca os pontos observados e incrementa o total de pontos
      for (int j = 0; j < N_PONTOS; j++){
        if (pontos[N_PONTOS * i + j]){
          pontos[N_PONTOS * i + j] = 0;
          pontosObservados[j] = 1;
          somaTot++;
        }
      }
      //Marca o maior ponto como observado, marca uma câmera ali e incrementa o total de pontos
      if (camsUtilizadas[i] == 0) {
        camsUtilizadas[i] = 1;
        pontosObservados[i] = 1;
        somaTot++;
        break;
      }
    }
  }

  //Zera os pontos já observados
  for (int i = 0; i < N_PONTOS; i++) {
    if (pontosObservados[i]) {
      for (int j = 0; j < N_PONTOS; j++){
        pontos[N_PONTOS*i + j] = 0;
      }
    }
  }

  printf_recursivo(n_pontos, pontos);
}

int main() {

  int m[N_PONTOS * N_PONTOS] = {0, 1, 0, 1, 0, 0,
                                1, 0, 0, 0, 1, 0,
                                0, 0, 0, 0, 1, 1,
                                1, 0, 0, 0, 0, 1,
                                0, 1, 1, 0, 0, 0,
                                0, 0, 1, 1, 0, 0};

  int M[N_PONTOS * N_PONTOS] = {0, 1, 0, 0, 0, 0,
                                1, 0, 1, 1, 0, 1,
                                0, 1, 0, 1, 1, 1,
                                0, 1, 1, 0, 1, 1,
                                0, 0, 1, 1, 0, 1, 
                                0, 1, 1, 1, 1, 0};

  int Mat[N_PONTOS * N_PONTOS] = {0, 1, 0, 0, 0, 0,
                                  1, 0, 1, 0, 0, 0,
                                  0, 1, 0, 1, 1, 1,
                                  0, 0, 1, 0, 0, 0,
                                  0, 0, 1, 0, 0, 0,
                                  0, 0, 1, 0, 0, 0};

  int mapa[N_PONTOS * N_PONTOS] = {0, 0, 1, 1, 0,
                                   0, 0, 1, 1, 1,
                                   1, 1, 0, 1, 0,
                                   1, 1, 1, 0, 0,
                                   0, 1, 0, 0, 0};

  int mapa2[N_PONTOS * N_PONTOS] = {0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0,
                                    0, 0, 0, 0, 0};

  int mapa3[N_PONTOS * N_PONTOS] = {0, 1, 1, 1, 1,
                                    1, 0, 1, 1, 1,
                                    1, 1, 0, 1, 1,
                                    1, 1, 1, 0, 1,
                                    1, 1, 1, 1, 0};

  printf_recursivo(N_PONTOS, M);

  return 0;
}
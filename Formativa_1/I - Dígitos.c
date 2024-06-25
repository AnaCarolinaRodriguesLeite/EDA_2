#include <stdio.h>
#include <string.h>
#include <assert.h>

void incrementar_numero(char *numero) {
  int transbordo = 1;

  for (int i = strlen(numero) - 1; i >= 0; i--) {
    int novo_valor = (numero[i] - '0') + transbordo;
    transbordo = 0;

    if (novo_valor >= 10) {
      transbordo = 1;
      novo_valor -= 10;
    }
    numero[i] = '0' + novo_valor;
  }

  if (transbordo) {
    memmove(numero + 1, numero, strlen(numero) + 1);
    numero[0] = '1';
  }
}

int main() {
  int quantidade_digitos;
  char numero_completo[10001];

  scanf("%d", &quantidade_digitos);
  assert(quantidade_digitos > 0);

  for (int i = 0; i < quantidade_digitos; i++) {
    char digito;
    scanf(" %c", &digito);
    numero_completo[i] = digito;
  }

  numero_completo[quantidade_digitos] = '\0';
  assert(numero_completo[0] != '0');
  
  for (int tamanho_prefixo = 1; tamanho_prefixo <= strlen(numero_completo); tamanho_prefixo++) {
    char prefixo[10001];
    
    strncpy(prefixo, numero_completo, tamanho_prefixo);
    
    prefixo[tamanho_prefixo] = '\0';
    int posicao_atual = 0;
    int prefixo_repetitivo = 1;
    char multiplicador[10001]; 
    strcpy(multiplicador, prefixo);

    while (posicao_atual < strlen(numero_completo)) {
      if (posicao_atual + strlen(multiplicador) - 1 >= strlen(numero_completo)) {
        prefixo_repetitivo = 0;
        break;
      }
      
      for (int i = posicao_atual; i < posicao_atual + strlen(multiplicador); i++) {
        if (numero_completo[i] != multiplicador[i - posicao_atual]) {
          prefixo_repetitivo = 0;
          break;
        }
      }

      if (!prefixo_repetitivo) {
        break;
      }
      posicao_atual += strlen(multiplicador);
      incrementar_numero(multiplicador);
    }
    
    if (prefixo_repetitivo) {
      printf("%s\n", prefixo);
      return 0;
    }
  }
  return 1;
}

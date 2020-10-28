// ----------------------------------------------------------------
// ESPECIFICAÇÃO: O programa deve determinar se um identificador
// é ou não válido. Um identificador válido deve começar com uma
// letra e conter apenas letras ou dígitos. Além disto, deve ter
// no mínimo 1 caractere e no máximo 6 caracteres de comprimento
// ----------------------------------------------------------------

#include <stdio.h>

int valid_s(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
    return 1;
  else
    return 0;
}

int valid_f(char ch) {
  if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')) || ((ch >= '0') && (ch <= '9')))
    return 1;
  else
    return 0;
}

int identifier(char* input){
	char achar;
  int  length, valid_id;
  length = 0;
  printf("Identificador: ");
  achar = *input;
  input++;
  valid_id = valid_s(achar);
  if(valid_id) {
    length = 1;
  }
  achar = *input;
  input ++;
  while(achar != '\0') {
    if(!(valid_f(achar))) {
      valid_id = 0;
    }
    length++;
    achar = *input;
    input++;
  }
  if (valid_id && (length >= 1) && (length < 6)) {
    printf("Valido\n");
    return 0;
  }
  else {
    printf("Invalido\n");
    return 1;
  }
}

int main(int argc, char *argv[]) {
  return identifier(argv[1]);
}

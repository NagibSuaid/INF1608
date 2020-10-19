#ifndef IMPORTED_RAIZ
#define IMPORTED_RAIZ

int bissecao (double a, double b, int p, double (*f) (double x), double* r);
/* Encontra uma raiz da funcao f dentro do intervalo [a,b] com p digitos de precisão
Armazena a raiz encontrada em r e retorna o numero de chamadas a funcao realizadas*/

int IQI (double x0, double x1, int p, double (*f) (double x), double* r);
/* Encontra uma raiz da funcao f idealmewnte proxima de x0 e x1 com p digitos de precisão
em f(raiz). Armazena a raiz encontrada em r e retorna o numero de chamadas a funcao realizadas,
ou 0 se a função não convergir*/

#endif
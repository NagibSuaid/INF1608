
/*preenche o vetor x com a solucao aproximada do problema e retorna
a norma-2 do resíduo*/
double MMQ (int m, int n, double** A, double* b, double* x);

/*ajusta um modelo periodico baseado em um conjunto de pontos
o vetor de coeficientes e preenchido e o erro do ajuste e retornado
v = c0 + c1t + c2 sin 2πt + c3 cos 2πt + c4 sin 4πt + c5 cos 4πt*/
double periodico (int n, double* t, double* v, double* c);

/*faz uma previsão de um novo ponto no modelo baseado no vetores de coeficiente
v = c0 + c1t + c2 sin 2πt + c3 cos 2πt + c4 sin 4πt + c5 cos 4πt*/
double previsao (double* c, double t);

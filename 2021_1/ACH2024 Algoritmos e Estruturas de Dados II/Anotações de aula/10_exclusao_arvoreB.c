# Propriedades de uma arvore B de ordem m 

- no min ([m/2 - 1]up) chave
- no max m-1 chaves


# Altura de uma arvore B de ordem m com N chaves

- pior caso : cada pagina ([m/2]up - 1) chave
- d <= 1 + log_([m/2]up)((N+1)/2)
- N = 1milhao, m = 512, d <= 3.37 seeks 


# Exclusao

- exclusao so na folha (eficiencia), underflow :
(1) redistribuicao	=> local 
(2) concatenacao	=> arvore toda (portanto, mais caro)


# Redistribuicao 

- redistribui as chaves do irmao, com chave mediano na pagina de cima
- troca de lugar entre pais e filhos => nao se propaga pra nivel superior, nem modifica a altura 


# Concatenacao 

- destroi uma pagina e uma chave do pai
- underflow do pai? -> concatena


# Seis casos a considerar na exclusao 

- exclusao de chave na folha, sem underflow
- exclusao de uma chave interior
- exclusao causando underflow com possibilidade de redistribuicao
- exclusao causando underflow sem possibilidade de redistribuicao (e portanto precisa concatenar)
- underflow da pagina pai
- reducao da altura da arvore


# Complexidade de tempo

- == altura
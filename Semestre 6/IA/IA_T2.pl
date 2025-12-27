% Base de Conhecimento (BC)
problema(preparo_fisico) :- preparo_fisico(ruim).  %1
problema(equipe_tecnica) :- atritos(constantes), situacao_psicologica(ruim).  %2
problema(time) :- preparo_fisico(bom), atritos(raros), situacao_de_gols(ruim). %3
problema(insatisfacao_financeira) :- atritos(constantes), salarios(atrasados).  %4
problema(nenhum) :- preparo_fisico(bom), situacao_de_gols(boa), salarios(em_dia).  %5
atritos(raros) :- not(atritos(constantes)). %6 (NOVA)
atritos(constantes) :- jogador(X), tecnico(Y), discute(X, Y).  %7
atritos(constantes) :- jogador(X), jogador(Y), X \== Y, discute(X, Y).  %8
situacao_psicologica(ruim) :- jogador(X), suspenso(X).  %9
situacao_de_gols(ruim) :- gols_sofridos(X), gols_feitos(Y), maior(X,Y).  %10
situacao_de_gols(boa) :- gols_sofridos(X), gols_feitos(Y), not(maior(X,Y)).  %11
suspenso(X) :- cartao_vermelho(X).  %12
preparo_fisico(ruim) :- jogador(X), faltou_treino(X).  %13
preparo_fisico(ruim) :- jogador(X), lento(X).  %14
preparo_fisico(bom) :- not(preparo_fisico(ruim)). %15 (NOVA)
maior(X, Y) :- X > Y.  %16 (NOVA)

% Situação 01
% jogador(jorge).
% jogador(maria).
% cartao_vermelho(jorge).
% lento(maria).
% tecnico(t1).
% discute(jorge, t1).
% gols_sofridos(1).
% gols_feitos(2).
% salarios(atrasados).
% faltou_treino(nao_faltou).

% Situação 02
% jogador(lucas).
% jogador(joana).
% jogador(henry).
% jogador(luana).
% lento(ninguem_lento).
% cartao_vermelho(joana).
% discute(ninguemA, ninguemB).
% gols_sofridos(5).
% gols_feitos(3).
% tecnico(t0).
% faltou_treino(nao_faltou).
% salarios(nao_atrasados).

% Situação 3
jogador(julia).
jogador(joao).
tecnico(t2).
cartao_vermelho(joao).
faltou_treino(ninguem_faltou).
lento(ninguem_lento).
discute(ninguemA,ninguemB).
gols_sofridos(2).
gols_feitos(4).
salarios(em_dia).
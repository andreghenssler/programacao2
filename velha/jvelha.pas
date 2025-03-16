program jogo;
uses crt, SysUtils; // Para converter Inteiro para String
var
    tabela: array[1..3,1..3] of string;
    jogador, c,l,i, sorteio: integer;
    opc: char;
    nomejogaor1, nomejogaor2,qComeca: string;
    escolha1, escolha2,escolha: char;


procedure iniciaJogo;
begin
clrscr;
    i:=1;
    // Inicia o jogo com a inicialização de cada posição 
    for l:=1 to 3 do
        begin
            for c:=1 to 3 do
                begin
                    tabela[l,c]:= IntToStr(i);
                    i+=1;
                end;
        end;
end;

procedure imprimirJogo(); // Imprime o Jogo da Tela
begin
    clrscr;
    writeln('|--- Jogo da Velha --|');
    for l:=1 to 3 do
        begin        
            writeln('|------|------|------|');
            for c:=1 to 3 do
                begin
                    write('| ' ,tabela[l,c]:3,'  ');
                end;
            writeln('|');
        end;
    
    writeln('|------|------|------|');
end;

procedure nomeJogador;
begin
clrscr;
    write('Nome do Jogador 1: ');
    readln(nomejogaor1);
    write('O jogador ', nomejogaor1,', pode escolher entre X ou  O ');
    readln(escolha1);
    write('Nome do Jogador 2: ');
    readln(nomejogaor2);
    if (escolha1 = 'x') or (escolha1 = 'X') then
        begin
            writeln('O Jogador ', nomejogaor2,', ficou com O');
            escolha2:='O';
            escolha1:='X';
        end
    else
        begin
            writeln('O Jogador ', nomejogaor2,', ficou com X');
            escolha2:='X';
            escolha1:='O';
        end;
    writeln('Clique enter para comecar');
    readln();
end;

function atualizaJogador():integer;
begin
    sorteio:= random(2);
    if sorteio = 1 then
        jogador:= 2
    else
        jogador:=1;
    atualizaJogador:=jogador;

end;

// Verificara quem ganhou por linha
function ganhouPorLinha():boolean;
var
    linha:integer;
begin
    ganhouPorLinha:=false;
    for linha:=1 to 3 do
        begin
            if(tabela[linha,1]='X') and (tabela[linha,2]='X') and (tabela[linha,3]='X') or
              (tabela[linha,1]='O') and (tabela[linha,2]='O') and (tabela[linha,3]='O') then
                ganhouPorLinha:=true;
        end;
end;

// Verificara quem ganhou por coluna
function ganhouPorColuna():boolean;
var
    coluna,x:integer;
begin
    ganhouPorColuna:=false;
    x:=1;
    if((tabela[1,1]='X') and (tabela[2,1]='X') and (tabela[3,1]='X')) or
      ((tabela[1,2]='X') and (tabela[2,2]='X') and (tabela[3,2]='X')) or
      ((tabela[1,3]='X') and (tabela[2,3]='X') and (tabela[3,3]='X')) or
      ((tabela[1,1]='O') and (tabela[2,1]='O') and (tabela[3,1]='O')) or
      ((tabela[1,2]='O') and (tabela[2,2]='O') and (tabela[3,2]='O')) or
      ((tabela[1,3]='O') and (tabela[2,3]='O') and (tabela[3,3]='O')) then
        ganhouPorColuna:=true;
end;

// Verificara quem ganhou pela diagnol pricipal
function ganhoupeladiagprincipal():boolean;
var
    coluna,x:integer;
begin
    ganhoupeladiagprincipal:=false;
    //x:=1;
    if(tabela[1,1]='X') and (tabela[2,2]='X') and (tabela[3,3]='X') or (tabela[1,1]='O') and (tabela[2,2]='O') and (tabela[3,3]='O') then
        ganhoupeladiagprincipal:=true
    else
        ganhoupeladiagprincipal:=false;
end;

// Verificara quem ganhou pela diagnol segundaria
function ganhoupeladiagsundaria():boolean;
var
    coluna,x:integer;
begin
    ganhoupeladiagsundaria:=false;
    //x:=1;
    if(tabela[1,3]='X') and (tabela[2,2]='X') and (tabela[3,1]='X') or (tabela[3,3]='O') and (tabela[2,2]='O') and (tabela[3,1]='O') then
        ganhoupeladiagsundaria:=true
    else
        ganhoupeladiagsundaria:=false;
end;

procedure posicao();
var mudarJogador:integer;
begin
    mudarJogador:=atualizaJogador;
    i:=0;
    imprimirJogo;
    repeat
        if mudarJogador = 1 then
            escolha:=escolha1
        else
            escolha:=escolha2;
        write('Escolha uma posicao para comecar, jogardor ', mudarJogador,': ');
        readln(opc);
        case opc of
            '1': tabela[1,1]:= escolha;
            '2': tabela[1,2]:= escolha;
            '3': tabela[1,3]:= escolha;
            '4': tabela[2,1]:= escolha;
            '5': tabela[2,2]:= escolha;
            '6': tabela[2,3]:= escolha;
            '7': tabela[3,1]:= escolha;
            '8': tabela[3,2]:= escolha;
            '9': tabela[3,3]:= escolha;
            else
                write('Invalido, Final de Jogo');
        end;
        
        //atualizaJogador();
        imprimirJogo;
        i+=1;
        {Se o jogador atual for o 1, então o proximo é o 2}
        if mudarJogador = 1 then
            mudarJogador+=1
        else
            mudarJogador-=1;
    until (i=9) or (ganhouPorLinha) or (ganhouPorColuna) or (ganhoupeladiagprincipal) or (ganhoupeladiagsundaria);
end;

procedure resultado();
begin
    clrscr;
    imprimirJogo;
    writeln('Ganhou por Linha ' ,ganhouPorLinha);
    writeln('Ganhou por coluna ',ganhouPorColuna);
    writeln('Ganhou pela diagonal Principal ',ganhoupeladiagprincipal);
    writeln('Ganhou pela diagonal Segundaria ',ganhoupeladiagsundaria);
    writeln('Final de Jogo ... ');
end;

begin
    randomize();
    iniciaJogo; // Chama a procedimento que inicia o jogo
    imprimirJogo; // Inicia o jogo imprimindo a tabela vazia, sem nenhuma posição
    nomeJogador;

    // Soteio quem começa o Jogo    
    if(atualizaJogador = 1) then
        writeln('Quem comeca a Jogar e o jogador ', nomejogaor1)
    else
        writeln('Quem comeca a Jogar e o jogador ', nomejogaor2);
    
    posicao;
    resultado();
    readln();
end.

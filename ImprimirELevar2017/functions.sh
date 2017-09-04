
## FUNCTIONS DE CRIAÇÃO E TESTE
## ESCREVER AO FINAL DO ARQUIVO ~/.bashrc

## Function de criação de arquivos
## USO: cria arquivo(.cpp)

function cria(){
	arq=$(echo $1 | cut -f1 -d.)
	cat ~/modelo.cpp > $arq.cpp
	> $arq.in > $arq.sol > my.sol
	geany $arq.* my.sol $arq.cpp
}

## Function de compilação, execução e teste
## USO: roda arquivo(.cpp)

function roda(){
	arq=$(echo $1 | cut -f1 -d.)
	g++ -Wall -std=c++11 -lm -g $arq.cpp &&
	echo "### COMPILOU ###" &&
	time ./a.out < $arq.in > my.sol && 
	diff $arq.sol my.sol
}

# Top-K-Elementos# Top-K-elementos
---

É bastante frequentemente necessário, ao analisar conjuntos de dados, identificar a porção mais relevante ou valiosa dentro de uma grande quantidade de informações. Isso implica em discernir os elementos mais significativos dentre aqueles de menor importância. A partir desse procedimento, é viável conduzir análises de dados e obter conclusões pertinentes a respeito das informações, algo inviável de ser realizado manualmente devido à magnitude do volume de dados.

Este projeto propõe uma solução para tal desafio, empregando uma combinação de uma tabela hash e uma estrutura de heap para analisar palavras em textos. O propósito é identificar os "top k elementos" dentro do conjunto de dados, ou seja, identificar os elementos que mais se repetem (aparecem em maior quantidade) em relação aos demais.

Por meio da aplicação da tabela hash e da estrutura de heap, é possível fornecer uma abordagem computacionalmente eficaz para enfrentar esse problema. Isso assegura que o processo seja escalável mesmo quando lidando com conjuntos de dados relativamente volumosos, mesmo em sistemas com recursos modestos.

Em síntese, este trabalho realiza a leitura e análise de diversos textos submetidos pelo usuário. O resultado é a identificação dos k elementos mais frequentes entre os textos analisados, sendo que o valor de k é predefinido como 20.

## Entrada

- O software recebe um arquivo contendo texto no qual cada sentença requer finalização com um sinal de pontuação.
- Cada parágrafo é separado por uma linha em branco.
- Uma palavra é definida como uma sequência de letras demarcada por espaços ou sinais de pontuação adjacentes.
- Os arquivos de entrada seguem a convenção "input{n}.data", onde n representa o número sequencial a partir de 1.
- A análise do texto exclui as "stop words", tais como "a", "e", "mas", etc. A relação de "stop words" é disponibilizada através de um arquivo denominado "stopwords.txt" presente no diretório do conjunto de dados.

## Implementação

Inicialmente, uma tabela hash é criada para armazenar todas as palavras presentes nos textos. Cada vez que uma palavra é identificada, sua frequência na tabela hash é incrementada. A detecção das palavras é realizada por meio da leitura de cada byte do arquivo por vez. Dessa forma, cada conjunto de bytes delimitado por marcadores de término é considerado uma palavra.

As marcas de terminação usadas são: 
- espaço; nova linha; ```!```; ```?```; ```.```;
- ```,```; ```(```; ```)```; ```;```; ```/```; 
- ```:```; ```—```; ```"```; ```\```;

A contagem dos elementos é realizada com complexidade O(n), onde n representa o número de palavras. Importa ressaltar que todas as palavras contidas no arquivo "stopwords.txt" são desconsideradas pelo programa e não são adicionadas à tabela hash.

A codificação UTF-8, provida pelas bibliotecas do C++, também foi empregada. Adicionalmente, o programa não faz diferenciação entre letras maiúsculas e minúsculas. Dessa forma, palavras como "CÓDIGO" e "código" são tratadas como iguais. Acentuação é levada em consideração, ou seja, "código" e "codigo" são interpretadas como distintas.

A estrutura de dados utilizada para a hash foi o unordered_map do C++, uma classe que emprega uma tabela hash para armazenar pares chave-valor definidos pelo template. A escolha dessa estrutura permite que o acesso aos valores (neste caso, as frequências) através das chaves (as palavras) seja praticamente constante, com complexidade O(1). A função hash empregada não é padronizada pela linguagem e varia conforme o compilador. No contexto do projeto, usando o compilador g++, foi utilizada a função hash MurmurHashUnaligned2 da versão 11, que emprega operações bitwise para calcular o valor da hash.

Posteriormente, é criado um heap de tamanho k (20). O heap é inicializado com os primeiros valores da tabela hash e é atualizado conforme necessário. A atualização do heap ocorre ao comparar cada palavra remanescente na hash com o menor valor presente no heap, ou seja, a palavra com a menor frequência. Caso a contagem seja superior ao menor valor do heap, o elemento do heap é removido e o novo elemento é inserido. A função heapify é utilizada a cada inserção para manter a estrutura do heap correta.

As funções utilizadas para isso são make_heap, push_heap e pop_heap. make_heap inicializa o heap no vetor, push_heap é usado para adicionar uma palavra e pop_heap para remover uma palavra. Tais funções têm uma complexidade de tempo de aproximadamente O(2*log{n}), onde n é a quantidade de elementos inseridos, e cada operação requer uma comparação.

Dessa forma, a lista dos k maiores elementos é construída a partir da tabela completa. Ao final do processamento de toda a tabela, o heap resultante é impresso na tela.

## Decisões de Implementação
A opção foi por utilizar um heap mínimo devido à sua conveniência para localizar o menor valor presente no heap. Ao adotar um heap mínimo, é possível verificar e remover o elemento raiz a qualquer momento, o que otimiza as operações de remoção e busca do menor elemento.


É optado por transferir o arquivo todo da memória secundária para a principal para ser realizada a leitura do arquivo, tal decisão apresenta tanto pontos fortes, como pontos fracos:

### Características gerais:
- Eficiente leitura dos arquivos;
- Redução do acesso à memória secundária, geralmente resultando em execução mais rápida.
- O programa não é capaz de processar arquivos excessivamente volumosos para a memória principal;
- Em caso de arquivos excessivamente grandes, há a possibilidade de consumo considerável de memória, levando a um desempenho insatisfatório.

## Resultados

### Exemplo de entrada

![entrada1](/img/entrada1.png)

Segundo arquivo:

![entrada2](/img/entrada2.png)

### Exemplo de saída

![saída](/img/saída.png)

## Conclusão

O desenvolvimento e a aplicação das estruturas de hash e heap neste projeto fornecem uma visão concreta sobre como resolver desafios complexos de manipulação de dados de forma eficiente. Embora a abordagem possa ser considerada fundamental e com propósitos educativos, ela demonstra a capacidade de extrair informações essenciais de conjuntos de dados extensos de maneira otimizada.

O desafio de tomar decisões estratégicas e implementar soluções com base nessas estruturas enriquece a compreensão de como lidar com problemas computacionais variados. Nesse sentido, o projeto oferece uma oportunidade valiosa de aprendizado. Ele não apenas explora as nuances das estruturas e implementações na linguagem, mas também incentiva a exploração de abordagens mais eficazes para resolver problemas, graças à aplicação criteriosa de estruturas de dados inteligentes.

## Compilação e Execução

Esse código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução.
O arquivo Makefile supporta as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

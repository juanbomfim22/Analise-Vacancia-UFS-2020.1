Projeto POO
====

Implementação de uma interface gráfica (GUI) em C++ com um módulo de exploração de base de dados e gráficos de colunas empilhadas utilizando o framework Qt.


Autor 
----

- Juan Garbellotte Bomfim

Graduando em Engenharia de Computação pela Universidade Federal de Sergipe (UFS).

Motivação
---------
Esse projeto é fruto da disciplina Programação Orientada a Objetos, do Departamento de Computação da UFS, ministrada pelo Prof. Dr. Leonardo Nogueira Matos no 3º período do curso Engenharia de Computação do semestre 2020.1.

Descrição
---

O projeto funciona a partir de informações das turmas, coletadas previamente de um repositório de dados não-estruturado público para alunos da UFS, obtidas através da seção "Ensino > Consultar Turma" no Portal do Discente do SIGAA. 

Diante de diversas informações obtidas na busca, foram filtrados os dados referentes à modalidade Graduação do período 2020.1 e escolhidas quatro categorias para cada Departamento:

* **Componente**: dada pela sigla sem os números. Exemplo: ADMI.
* **Situação**: Aberta, A Definir Docente ou Consolidada.
* **Matriculados**: quantidade de alunos matriculados no departamento.
* **Capacidade**: quantidade de vagas disponiveis no departamento.

Com essas informações, foi elaborada uma interface gráfica que dispõe colunas empilhadas com base na escolha do usuário. 

1. O caminho para informações sobre Turma no SIGAA  
![UFS1](https://imgur.com/tqGvXZb.png)
2. Consulta dos departamentos
![UFS2](https://imgur.com/ntdY1fr.png)
3. Dados escolhidos
![UFS3](https://imgur.com/BJT4l8H.png)

Detalhes de implementação
---

Para modelar o problema de tratar os dados, foram criadas duas classes (além da MainWindow): Universidade e Turma. Elas contêm as funções necessárias para realizar o tratamento dos dados e a criação da plotagem.

Considerações:

* Uma Turma sempre é um vetor com quatro posições:
> {COMPONENTE, SITUAÇÃO, MATRICULADOS, CAPACIDADE}
>{ADM, ABERTA, 13, 39}

* Uma Turma contém dados da soma de todas as matrículas e capacidades das situações para um departamento. 
> A Turma COMP: {COMP, ABERTA, 6070, 7038} diz que o Departamento de Computação possui apenas turmas abertas com um total de 6070 matriculados e 7038 de capacidade. 
Já a Turma AGRAS: {AGRAS, ABERTA, 1672, 2064},{AGRAS, A_DEFINIR_DOCENTE, 39, 48}, {AGRAS, CONSOLIDADA, 87, 120} representa três opções de situação.
* Os arquivos `qcustomplot.cpp` e `qcustomplot.h` são necessários para o _display_ do gráfico.


Diagrama de classes
---
![DIAGRAMA DE CLASSES](https://imgur.com/KBPndAi.png)

Funcionalidades
--------

O programa permite que o usuário escolha quantas e quaisquer componentes (Turmas) de modo a realizar a comparação da vacância das vagas ofertadas, em um gráfico de colunas empilhadas. O comparativo entre matriculados e capacidade tem a observação facilitada utilizando o _scroll_ do mouse para aumentar ou diminuir o _zoom_ do gráfico.


4. Interface do usuário  
![GUI1](https://i.imgur.com/qZoZVaM.png)
5. Várias seleções são possíveis  
![GUI2](https://imgur.com/I1QyZ22.png)


Instalação
------------

Utilize os arquivos com extensão ".pro" no Qt Creator. Quanto aos arquivo de dados "dados.csv", coloque-o dentro das pastas dos caminhos: 
```
\build-ProjetoPOO-Desktop_Qt_5_15_2_MinGW_64_bit-Release
```
e também no 
```
\build-ProjetoPOO-Desktop_Qt_5_15_2_MinGW_64_bit-Release\debug
```
para garantir a leitura dos dados.



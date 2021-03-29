Projeto POO
====

Implementação de uma interface gráfica (GUI) em C++ com um módulo de exploração de base de dados e gráficos de colunas empilhadas utilizando o framework Qt.


Autor 
----

> Juan Garbellotte Bomfim

Graduando em Engenharia de Computação pela Universidade Federal de Sergipe (UFS).

Motivação
---------
Esse projeto é fruto da disciplina Programação Orientada a Objetos, do Departamento de Computação da UFS, ministrada pelo Prof. Dr. Leonardo Nogueira Matos no 3º período do curso Engenharia de Computação do semestre 2020.1.

Descrição
---

O projeto funciona a partir de informações das turmas, coletadas previamente de um repositório de dados não-estruturado e público para alunos da UFS. Os dados foram obtidos através da seção "Ensino > Consultar Turma" no Portal do Discente do SIGAA. Com isso, filtraram-se os dados referentes à modalidade Graduação do período 2020.1 quatro categorias foram escolhidas para cada Departamento:

* **Componente**: dada pela sigla sem os números. Exemplo: ADMI.
* **Situação**: Aberta, A Definir Docente ou Consolidada.
* **Matriculados**: quantidade de alunos matriculados no departamento.
* **Capacidade**: quantidade de vagas disponiveis no departamento.

Com essas informações, foi elaborada uma interface gráfica que dispõe colunas empilhadas com base na escolha do usuário. 

1. Dados escolhidos
![UFS3](https://imgur.com/BJT4l8H.png)

Diagrama de classes
---
![DIAGRAMA DE CLASSES](https://imgur.com/KBPndAi.png)

Funcionalidades
--------

O programa permite que o usuário escolha quantas e quaisquer componentes (Turmas) de modo a realizar a comparação da vacância das vagas ofertadas, em um gráfico de colunas empilhadas. O comparativo entre matriculados e capacidade tem a observação facilitada utilizando o _scroll_ do mouse para aumentar ou diminuir o _zoom_ do gráfico.


2. Interface do usuário  
![GUI1](https://i.imgur.com/qZoZVaM.png)
3. Várias seleções são possíveis  
![GUI2](https://imgur.com/I1QyZ22.png)

Bibliotecas e Frameworks
-----------

Na versão mais recente:
- [Qt Creator](https://www.qt.io/product/development-tools)
- [QCustomPlot](https://www.qcustomplot.com/index.php/introduction)

Instalação
------------

Baixe os arquivos necessários para a plotagem [aqui](https://www.qcustomplot.com/release/2.1.0/QCustomPlot-source.tar.gz):
1. Descompacte a pasta baixada e coloque `qcustomplot.h` e `qcustomplot.cpp` na pasta `files` deste repositório.
2. Utilize os arquivos com extensão ".pro" no Qt Creator.
3. Coloque o arquivo de dados encontrado em `dados/dados.csv` dentro das pastas dos caminhos `\build-ProjetoPOO-Desktop_Qt_5_15_2_MinGW_64_bit-Release` e `\build-ProjetoPOO-Desktop_Qt_5_15_2_MinGW_64_bit-Release\debug`.


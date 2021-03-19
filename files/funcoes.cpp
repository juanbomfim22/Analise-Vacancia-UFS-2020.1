#include "funcoes.h"

Universidade::Universidade(){}

Universidade::~Universidade(){}

Universidade::Universidade(const QString& nomeUniversidade, const QString& anoPeriodo){
    this->nomeCompleto = nomeUniversidade;
    this->anoPeriodo = anoPeriodo;
}

QString Universidade::getNomeCompleto(){
    return this->nomeCompleto;
}

QString Universidade::getAnoPeriodo(){
    return this->anoPeriodo;
}

QString Turma::getComponente(){
    return this->turma[0];
};

QString Turma::getSituacao(){
    return this->turma[1];
};

int Turma::getMatriculados(){
    return this->turma[2].toInt();
};

int Turma::getCapacidade(){
    return this->turma[3].toInt();
};

Turma::Turma(){}

Turma::Turma(const QString& nome, const QString& ano) : Universidade{nome, ano}{}

Turma::~Turma(){}

bool Turma::foiCancelada(){
    return (this->turma[1] == "CANCELADA");
}

void Turma::setTurma(const QVector<QString>& v){
    this->turma = v;
}

/*
 * Dada uma string e um delimitador, divide a string em todas as ocorrências
*/
QVector<QString> split(const string& s, const string& delimitador) {
    size_t pos_start = 0, pos_end, delim_len = delimitador.length();
    QString token;
    QVector<QString> res;
    while((pos_end = s.find (delimitador, pos_start)) != string::npos) {
        token = QString::fromStdString(s.substr (pos_start, pos_end - pos_start));
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }
    res.push_back (QString::fromStdString(s.substr (pos_start)));
    return res;
}

/*
 * Retorna um vetor com todas as Turma escolhidas pelo usuário
 * e seus respectivos dados. EX:
 * => {{ADM, ABERTA, 20, 34}}
 * => {{COMP, ABERTA, 87, 194}, {COMP, A_DEFINIR_DOCENTE, 30, 40}, {AGRO, ABERTA, 1, 2}}
*/
QVector<Turma> findDataOfComponente(const QVector<QString>& componentesEscolhidas, const QVector<Turma>& todasTurmas){
    QVector<Turma> data;
    for(QString componente : componentesEscolhidas){
        for(Turma turma : todasTurmas){
            if(turma.getComponente() == componente && !turma.foiCancelada())
                data.push_back(turma);
        }
    }
    return data;
}

/*
 * Retorna um vetor com a soma das quantidades de alunos da coluna escolhida.
 * Para a coluna só existem duas possibilidades: MATRICULADOS/CAPACIDADE.
*/
QVector<int> totalComponente(const QString& coluna, const QVector<QString>& componentesEscolhidas, const QVector<Turma>& turmasEscolhidas){
    QVector<int> total;
    for(QString componente : componentesEscolhidas){
        int parcial = 0;
        for(Turma turma : turmasEscolhidas){
            if(turma.getComponente() == componente && !turma.foiCancelada()){
                if(coluna == "MATRICULADOS"){
                    parcial += turma.getMatriculados();
                }
                if(coluna == "CAPACIDADE"){
                    parcial+= turma.getCapacidade();
                }
            }
        }
        total.push_back(parcial);
    }
    return total;
}

/*
 * Retorna os dados com a porcentagem final de cada situação.
 * Esse porcentagem servirá para ser aplicada como dado no gráfico.
 * Será 0 se a situação não existir para aquela Turma.
 * EX:                       ZOO | MEDL
 *     ABERTA: =>           {3.34, 40.34}
 *     CONSOLIDADA =>       {0,    20.23}
 *     A_DEFINIR_DOCENTE => {10.29, 1.19}
*/
QVector<double> findDataOfSituacao(const QString& situacao, const QVector<QString>& componentesEscolhidas, const QVector<Turma>& turmasEscolhidas, const QVector<int>& total){ //const vector<string>& componentesEscolhidas){
      QVector<double> v;
      int cont = 0;
      for(QString nomeComponente : componentesEscolhidas){
          bool foiEscolhida = false;
          for(Turma turma : turmasEscolhidas){
              if(turma.getComponente() == nomeComponente && situacao == turma.getSituacao()){
                 double porcentagem = (100 * turma.getMatriculados())/total[cont];
                 foiEscolhida = true;
                 cont++;
                 v << porcentagem;
              }
          }
          if(!foiEscolhida){
             v << 0;
          }
      }
      return v;
}

/*
 * Lê o arquivo do caminho (dados.csv) e processa os dados
 * O resultado é um vetor de Turma.
*/
QVector<Turma> processData(const string& path, Universidade& UNI){
    string line, delimitador = ",";
    QVector<Turma> todasTurmas;
    ifstream myfile(path);
    if (myfile.is_open()){
        while (getline (myfile,line) ){
          //Turma turma(UNI.getNomeCompleto(), UNI.getAnoPeriodo());
          Turma turma;
          turma.setTurma(split(line, delimitador));
          todasTurmas.push_back(turma);
        }
        myfile.close();
    }
    else cout << "Unable to open file";
    return todasTurmas;
}

/*
 * Retorna o vetor de strings com todas as ocorrências da coluna "idx" informada.
 * Coluna 0: "COMPONENTE".
 * Coluna 1: "SITUACAO".
 * Coluna 2: "MATRICULADOS".
 * Coluna 3: "CAPACIDADE".
*/
QVector<QString> getAllComponentes(const QVector<Turma>& total){
    QVector<QString> courses;
    for(Turma t : total )
        courses.push_back(t.getComponente());
    return courses;
}

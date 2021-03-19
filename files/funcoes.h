#ifndef FUNCOES_H
#define FUNCOES_H

#include <QDir>
#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Universidade{
protected:
    QString nomeCompleto, anoPeriodo;
public:
    Universidade(const QString&, const QString&);
    Universidade();
    ~Universidade();
    QString getNomeCompleto();
    QString getAnoPeriodo();
};

class Turma : public Universidade{

private:
    QVector<QString> turma;
public:
    Turma(const QString&, const QString&);
    Turma();
    ~Turma();
    bool foiCancelada();
    void setTurma(const QVector<QString>&);
    QString getComponente();
    QString getSituacao();
    int getMatriculados();
    int getCapacidade();
    operator QString() const{return "Turma(" + turma[0] + ", " + turma[1] + ", " + turma[2] + ", " + turma[3] + ")";}
};

QVector<QString>       split(const string& s, const string& delimitador);
QVector<Turma>         processData(const string&, Universidade&);
QVector<QString>       getAllComponentes(const QVector<Turma>&);
QVector<Turma>         findDataOfComponente(const QVector<QString>&, const QVector<Turma>&);
QVector<int>           totalComponente(const QString&, const QVector<QString>&, const QVector<Turma>&);
QVector<double>        findDataOfSituacao(const QString&, const QVector<QString>&, const QVector<Turma>&, const QVector<int>&);

#endif // FUNCOES_H

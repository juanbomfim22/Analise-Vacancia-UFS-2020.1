#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void initialize();
    void addInListWidgetBox();

    void hidePlot();
    void unhidePlot();
    void makePlot();

    void clearTextLabels();
    void addTextLabels(size_t tam, const QVector<int>&, const QVector<int>&);

    void on_btn_criar_planilha_clicked();
    void on_listWidget_itemClicked(QListWidgetItem *item);

    QVector<double>  getTicksFrom(const QVector<int>&);
    QVector<int>     getCheckedIndexes();
    QVector<QString> getLabelsFrom(const QVector<int>&);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

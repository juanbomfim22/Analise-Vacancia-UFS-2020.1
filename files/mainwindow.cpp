#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "funcoes.h"
#include "qcustomplot.h"
#include <QListWidgetItem>

// MUDE AQUI
string PATH = "dados.csv";
QVector<QCPItemText *> allTexts;
QVector<Turma> todasTurmas;

/*
 * Ao abrir a GUI, esconde o gráfico e popula
 * os elementos da lista de componentes
*/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    initialize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Inicializa as variáveis e a interface GUI
*/
void MainWindow::initialize(){
    Universidade UFS("Universidade Federal de Sergipe", "2020.1");

    todasTurmas = processData(PATH, UFS);

    ui->setupUi(this);
    ui->label_2->setText(UFS.getNomeCompleto() + " - " + UFS.getAnoPeriodo());

    hidePlot();
    addInListWidgetBox();
}

/*
 * Adiciona dinamicamente caixas de seleção no ListWidgetBox
 * com os nomes das componentes provenientes do arquivo de dados (deve ser um .csv);
*/
void MainWindow::addInListWidgetBox(){
    QVector<QString> componentes = getAllComponentes(todasTurmas);

    // Elimina duplicatas do vetor componentes
    componentes.erase(unique(componentes.begin(), componentes.end()), componentes.end());

    for(int i = 0; i < componentes.size(); i++){
        QListWidgetItem *item = new QListWidgetItem;
        item->setText(componentes[i]);
        item->setCheckState(Qt::Unchecked);
        ui->listWidget->addItem(item);
    }
}

/*
 * Retorna um vetor com indices de 1 a N, onde N é a quantidade
 * de caixas de seleção selecionadas pelo usuario antes de clicar em "Mostrar Dados".
 * Ex: ADMIN, AGROS, MEDL => [1,2,3]
*/
QVector<double> MainWindow::getTicksFrom(const QVector<int>& indexes){
    QVector<double> ticks;
    int cont = 1;
    for(int i: indexes){
        if(ui->listWidget->item(i)->checkState() == Qt::Checked){
            ticks << cont;
            cont++;
        }
    }
    return ticks;
}

/*
 * Reajusta as dimensões do gráfico para escondê-lo
*/
void MainWindow::hidePlot(){
    ui->my_plot->resize(0,0);
}

/*
 * Reajusta as dimensões do gráfico para mostrá-lo
*/
void MainWindow::unhidePlot(){
    ui->my_plot->resize(440,370);
}

/*
 * Pega o nome de todas as componentes escolhidas pela caixa de seleção
*/
QVector<QString> MainWindow::getLabelsFrom(const QVector<int>& indexes){
    QVector<QString> labels;
    for(int i : indexes){
        labels << ui->listWidget->item(i)->text();
    }
    return labels;
}

/*
 * Limpa o texto numérico mostrado acima de cada barra da plotagem
*/
void MainWindow::clearTextLabels(){
   if(!allTexts.empty()){
       for(QCPItemText * item: allTexts){
           ui->my_plot->removeItem(item);
       }
   }
}

/*
 * Para cada barra escolhida, adiciona o texto numérico
 * mostrado acima da plotagem com ajuste de altura.
 * Cada caixa de texto:
 *   M: XXX
 *   C: XXX
 * da plotagem Gráfico de Colunas é um ponteiro
 * armazenado na variável global "allTexts".
*/
void MainWindow::addTextLabels(size_t tam, const QVector<int>& matriculas, const QVector<int>& capacidade){
    for(size_t i = 1; i < tam + 1; i++){
        // Estilos e ajustes
        QCPItemText *textLabel = new QCPItemText(ui->my_plot);
        textLabel->setClipToAxisRect(false);
        textLabel->position->setAxes(ui->my_plot->xAxis,ui->my_plot->yAxis);
        textLabel->position->setType(QCPItemPosition::ptPlotCoords);
        textLabel->position->setCoords(i, 7 + (100*matriculas[i-1])/capacidade[i-1]);
        textLabel->setPen(QPen(Qt::black));
        textLabel->setColor(Qt::white);
        textLabel->setText("M: " + QString::number(matriculas[i-1]) + "\n" + "C: "+QString::number(capacidade[i-1]));
        textLabel->setFont(QFont("Sans" , 10, QFont::Bold));

        allTexts.push_back(textLabel);
    }
}

/*
 * Elabora o gráfico, realizando os devidos cálculos,
 * ajustes, formatações e estilizações.
*/
void MainWindow::makePlot(){
    // graph styles
    QLinearGradient gradient(0, 0, 0, 400);
    gradient.setColorAt(0, QColor(90, 90, 90));
    gradient.setColorAt(0.38, QColor(105, 105, 105));
    gradient.setColorAt(1, QColor(70, 70, 70));
    ui->my_plot->setBackground(QBrush(gradient));

    //cria cada categoria da legenda
    QCPBars *aDefinirDocente = new QCPBars(ui->my_plot->xAxis, ui->my_plot->yAxis);
    QCPBars *consolidada = new QCPBars(ui->my_plot->xAxis, ui->my_plot->yAxis);
    QCPBars *aberta = new QCPBars(ui->my_plot->xAxis, ui->my_plot->yAxis);

    //configuracoes iniciais das legendas
    aberta->setAntialiased(false);
    aDefinirDocente->setAntialiased(false);
    consolidada->setAntialiased(false);
    aberta->setStackingGap(1);
    aDefinirDocente->setStackingGap(1);
    consolidada->setStackingGap(1);

    // set names and colors:
    aberta->setName("Aberta");
    aberta->setPen(QPen(QColor(0, 168, 140).lighter(130)));
    aberta->setBrush(QColor(0, 168, 140));
    aDefinirDocente->setName("A definir docente");
    aDefinirDocente->setPen(QPen(QColor(250, 170, 20).lighter(150)));
    aDefinirDocente->setBrush(QColor(250, 170, 20));
    consolidada->setName("Consolidada");
    consolidada->setPen(QPen(QColor(111, 9, 176).lighter(170)));
    consolidada->setBrush(QColor(111, 9, 176));

    // empilha as categorias na legenda:
    consolidada->moveAbove(aberta);
    aDefinirDocente->moveAbove(consolidada);

    // cria as componentes e adiciona o nome das componentes no eixo horizontal
    QVector<int> indexes = getCheckedIndexes();
    QVector<double> ticks = getTicksFrom(indexes);
    QVector<QString> componentesEscolhidas = getLabelsFrom(indexes);
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(ticks, componentesEscolhidas);

    // prepara o eixo x
    ui->my_plot->xAxis->setTicker(textTicker);
    ui->my_plot->xAxis->setTickLabelRotation(60);
    ui->my_plot->xAxis->setSubTicks(false);
    ui->my_plot->xAxis->setTickLength(0, 10);
    ui->my_plot->xAxis->setRange(0, 5);
    ui->my_plot->xAxis->setBasePen(QPen(Qt::white));
    ui->my_plot->xAxis->setTickPen(QPen(Qt::white));
    ui->my_plot->xAxis->grid()->setVisible(true);
    ui->my_plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
    ui->my_plot->xAxis->setTickLabelColor(Qt::white);
    ui->my_plot->xAxis->setLabelColor(Qt::white);

    // prepara o eixo y
    ui->my_plot->yAxis->setRange(0, 101);
    ui->my_plot->yAxis->setRangeLower(0);
    ui->my_plot->yAxis->setPadding(4); // a bit more space to the left border
    ui->my_plot->yAxis->setLabel("Matriculados/Capacidade em %");
    ui->my_plot->yAxis->setBasePen(QPen(Qt::white));
    ui->my_plot->yAxis->setTickPen(QPen(Qt::white));
    ui->my_plot->yAxis->setSubTickPen(QPen(Qt::white));
    ui->my_plot->yAxis->grid()->setSubGridVisible(true);
    ui->my_plot->yAxis->setTickLabelColor(Qt::white);
    ui->my_plot->yAxis->setLabelColor(Qt::white);
    ui->my_plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
    ui->my_plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

    // fitlragem dos dados
    QVector<Turma> turmasEscolhidas = findDataOfComponente(componentesEscolhidas, todasTurmas);
    QVector<int> capacidadesEscolhidas = totalComponente("CAPACIDADE", componentesEscolhidas, todasTurmas);
    QVector<int> matriculasEscolhidas = totalComponente("MATRICULADOS", componentesEscolhidas, todasTurmas);
    QVector<double> abertaData = findDataOfSituacao("ABERTA",componentesEscolhidas, turmasEscolhidas, capacidadesEscolhidas);
    QVector<double> consolidadaData = findDataOfSituacao("CONSOLIDADA",componentesEscolhidas, turmasEscolhidas, capacidadesEscolhidas);
    QVector<double> aDefinirDocenteData = findDataOfSituacao("A_DEFINIR_DOCENTE",componentesEscolhidas, turmasEscolhidas, capacidadesEscolhidas);

    // popula as barras
    aberta->setData(ticks, abertaData);
    aDefinirDocente->setData(ticks, aDefinirDocenteData);
    consolidada->setData(ticks, consolidadaData);

    // adiciona caixas de texto
    addTextLabels(indexes.size(), matriculasEscolhidas, capacidadesEscolhidas);

    // setup legenda
    ui->my_plot->legend->setVisible(true);
    ui->my_plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
    ui->my_plot->legend->setBrush(QColor(255, 255, 255, 100));
    ui->my_plot->legend->setBorderPen(Qt::NoPen);
    QFont legendFont = font();
    legendFont.setPointSize(10);
    ui->my_plot->legend->setFont(legendFont);

    // configuracoes de display
    ui->my_plot->setInteractions(QCP::iRangeZoom | QCP::iRangeDrag);
    ui->my_plot->axisRect()->setRangeDrag(Qt::Horizontal);
    ui->my_plot->axisRect()->setRangeZoom(Qt::Horizontal);
    ui->my_plot->axisRect()->setRangeZoomAxes(ui->my_plot->xAxis, NULL); //To block y axis zoom NULL axis as horizontal
    ui->my_plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignRight|Qt::AlignBottom);
    ui->my_plot->replot();
}

/*
 * Cria a plotagem no clique do botão:
 * btn_criar_planilha, antes limpando algum gráfico anterior
*/
void MainWindow::on_btn_criar_planilha_clicked()
{
    ui->my_plot->clearPlottables();
    clearTextLabels();
    unhidePlot();
    makePlot();
}

/* Pega o respectivo indice das caixas de elementos selecionadas,
 * considerando que todos os elementos estão indexados de 0 a N-1;
*/

QVector<int> MainWindow::getCheckedIndexes(){
    QVector<int> v;
    int quantity = ui->listWidget->count();
    for(int i = 0; i < quantity; ++i){
        if(ui->listWidget->item(i)->checkState() == Qt::Checked)
            v << i;
    }
    return v;
}

/*
 * Altera a cor do item da listWidget
 * caso o item seja selecionado ou desselecionado
*/
void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QColor color = item->checkState() == Qt::Checked ? QColor(64,78,130) : QColor(0,0,0);
    item->setForeground(color);
}

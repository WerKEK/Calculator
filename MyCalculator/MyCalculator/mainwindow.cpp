#include "mainwindow.h"
#include "ui_mainwindow.h"

double firstNum;
QString curSign;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(SetLabelText()));
    connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(dotButtonClicked()));
    connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_multiply, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_percent, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->pushButton_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetLabelText(){

    QPushButton* button = (QPushButton*)sender();
    QString labelText;
    double number = (ui->label->text() + button->text()).toDouble();

    labelText = QString::number(number, 'g', 15);

    ui->label->setText(labelText);
}

void MainWindow::dotButtonClicked(){
    if(!(ui->label->text().contains('.')))
        ui->label->setText(ui->label->text() + ".");
}
void MainWindow::operations(){
    QPushButton* button = (QPushButton*)sender();

    QString labelText;
    double number;

    number = (ui->label->text()).toDouble();

    if(button->objectName() == ui->pushButton_plus_minus->objectName()){

        changeSign(number);
    }
    else if(button->objectName() == ui->pushButton_percent->objectName()){

        toPercent(number);
    }

    labelText = QString::number(number, 'g', 15);
    ui->label->setText(labelText);
}

void MainWindow::math_operations(){
    QPushButton* button = (QPushButton*)sender();
    firstNum = ui->label->text().toDouble();
    ui->label->setText("");

    curSign = button->text();
}

void MainWindow::changeSign(double& number){
    number *= -1;
}
void MainWindow::toPercent(double& number){
    number *= 0.01;
}

void MainWindow::on_pushButton_ac_clicked()
{
    ui->label->setText("0");
}

void MainWindow::on_pushButton_equals_clicked()
{
    double resultNum, secondNum;
    QString labelText;

    secondNum = ui->label->text().toDouble();

    if(curSign == "/"){
        if(secondNum == 0)
            ui->label->setText("0");
        else{
            resultNum = firstNum / secondNum;
            labelText = QString::number(resultNum, 'g', 15);
            ui->label->setText(labelText);
            ui->pushButton_divide->setChecked(false);
        }

    }else if(curSign == "-"){
        resultNum = firstNum - secondNum;
        labelText = QString::number(resultNum, 'g', 15);
        ui->label->setText(labelText);
        ui->pushButton_minus->setChecked(false);

    }else if(curSign == "X"){
        resultNum = firstNum * secondNum;
        labelText = QString::number(resultNum, 'g', 15);
        ui->label->setText(labelText);
        ui->pushButton_multiply->setChecked(false);

    }else if(curSign == "+"){
        resultNum = firstNum + secondNum;
        labelText = QString::number(resultNum, 'g', 15);
        ui->label->setText(labelText);
        ui->pushButton_plus->setChecked(false);
    }
}


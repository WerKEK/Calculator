#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void SetLabelText();
    void dotButtonClicked();
    void operations();
    void math_operations();
    void changeSign(double& number);
    void toPercent(double& number);
private slots:
    void on_pushButton_ac_clicked();
    void on_pushButton_equals_clicked();
};
#endif // MAINWINDOW_H

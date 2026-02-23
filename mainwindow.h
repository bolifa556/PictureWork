#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QCloseEvent>
#include <QProcess>
#include <QThread>
#include <QListWidget>
#include <QLineSeries>
#include <QChart>
#include <QChartView>
#include <QValueAxis>
#include <QImage>
#include <QFileInfo>
#include <QDebug>
#include <QTextEdit>

#include "colorset.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void closeEvent(QCloseEvent *event) override;
private slots:
    void on_RetaList_clicked(const QModelIndex &index);
    void on_GoHome_pressed();
    void onList1SelectionChanged();
    void onList2SelectionChanged();

    void on_RetaList_2_clicked(const QModelIndex &index);


    void on_ChooseFile_clicked();

    void on_CalculateButton_clicked();

    void on_chooseXmlFile_clicked();

    void on_chooseCsvFile_clicked();

    void on_model_button_clicked();


    void on_openpdf_clicked();

    void on_drawchoosecsv_clicked();

    void on_drawreadcsv_clicked();

    void on_headersList_itemClicked(QListWidgetItem *item);

    void on_drawcsvline_textChanged(const QString &arg1);



    void on_searchComponent_textChanged(const QString &arg1);


    void on_drawbutton_clicked();

    void on_deletePicture_clicked();

    void on_endcalculation_clicked();

    void on_choose_input_clicked();

    void on_choose_output_clicked();

    void on_changeBackground_button_clicked();

    void ChangeBackgroundColor(const QString &inputPath, const QString &outputPath, const QString &color);

    void on_ColorSet_button_clicked();

    QList<int> extractNumbers(const QString &str);

private:
    Ui::MainWindow *ui;
    ColorSet *colorsetwindow = new ColorSet;
    QString retapath="D:/MYPC/Reta/RETA/reta.exe";
    QString Retamodelpath="D:/MYPC/Reta/Reta3DModel/Reta3DModel.exe";
    QString pdfpath="D:/MYPC/Reta/RETA/UsersGuide.pdf";
    std::vector<QProcess*> processes;   //线程

    // 设置标签页
    QTextEdit *outputWidget = new QTextEdit(this);
};



#endif // MAINWINDOW_H

#ifndef COLORSET_H
#define COLORSET_H

#include <QWidget>
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
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

namespace Ui {
class ColorSet;
}

class ColorSet : public QWidget
{
    Q_OBJECT

public:
    explicit ColorSet(QWidget *parent = nullptr);
    ~ColorSet();
    void readColor();
    void writeColorset();
    QString ColorRangeTojson(const QList<QList<int>>& colorRange);
    QString TargetColorTojson(const QRgb& color);
    void createColorFile(QString colorfilePath);


    QString color[6][3];

protected:
    void closeEvent(QCloseEvent *event) override {
        // 在这里执行关闭前的操作（例如弹出确认对话框）
        writeColorset();
        readColor();
    }

private slots:

private:
    Ui::ColorSet *ui;
    QString colorsetPath;
};

#endif // COLORSET_H

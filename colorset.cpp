#include "colorset.h"
#include "ui_colorset.h"


ColorSet::ColorSet(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ColorSet)
{
    ui->setupUi(this);
}

ColorSet::~ColorSet()
{
    delete ui;
}

void ColorSet::readColor()
{
    // 读取颜色文件
    QFile file(colorsetPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << colorsetPath;
    }

    QTextStream in(&file);

    // 读取文件数据
    int currentRow = 0;
    while (!in.atEnd()) {
        QString line = in.readLine();
        if (currentRow == 0) {
            currentRow++;
            continue;
        }
        else{
            QStringList fields = line.split(',');
            color[currentRow-1][0] = fields[1].trimmed();
            color[currentRow-1][1] = fields[2].trimmed();
            color[currentRow-1][2] = fields[3].trimmed();
            currentRow++;
        }
    }
    file.close();

    // 设置文本
    // 颜色变化范围
    ui->Range_red_r->setText(color[0][0]);
    ui->Range_red_g->setText(color[0][1]);
    ui->Range_red_b->setText(color[0][2]);

    ui->Range_blue_r->setText(color[1][0]);
    ui->Range_blue_g->setText(color[1][1]);
    ui->Range_blue_b->setText(color[1][2]);

    ui->Range_white_r->setText(color[2][0]);
    ui->Range_white_g->setText(color[2][1]);
    ui->Range_white_b->setText(color[2][2]);
    // 目标颜色
    ui->red_r->setText(color[3][0]);
    ui->red_g->setText(color[3][1]);
    ui->red_b->setText(color[3][2]);

    ui->blue_r->setText(color[4][0]);
    ui->blue_g->setText(color[4][1]);
    ui->blue_b->setText(color[4][2]);

    ui->white_r->setText(color[5][0]);
    ui->white_g->setText(color[5][1]);
    ui->white_b->setText(color[5][2]);
}

void ColorSet::createColorFile(QString colorfilePath){
    colorsetPath = colorfilePath;
    // 检查文件是否存在
    if (!QFile::exists(colorfilePath)) {
        QFile file(colorfilePath);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            // 写入CSV文件
            // 颜色名称数组
            QString colorNames[6] = {
                "range_red",
                "range_green",
                "range_blue",
                "red",
                "green",
                "blue"
            };
            // 写入标题行
            out << "color,r,g,b\n";
            // 写入数据行
            for (int i = 0; i < 6; i++) {
                out << colorNames[i] << ","
                    << 0 << ","
                    << 0 << ","
                    << 0 << "\n";
            }
            file.close();
            qDebug() << "ColorSet.csv created successfully.";
        } else {
            qDebug() << "Failed to create ColorSet.csv.";
        }
    }else{
        QFileInfo fileInfo(colorsetPath);
        qDebug() << "ColorSet.csv already exist:"<<fileInfo.absoluteFilePath();
    }

}

void ColorSet::writeColorset()
{
    // 打开文件进行写入
    QFile file(colorsetPath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件进行写入";
    }

    QTextStream out(&file);
    //读取当前数据
    // 颜色名称数组
    QString colorNames[6] = {
        "range_red",
        "range_green",
        "range_blue",
        "red",
        "green",
        "blue"
    };
    // 颜色数据数组
    QString wcolor[6][3] = {
        {ui->Range_red_r->text(), ui->Range_red_g->text(), ui->Range_red_b->text()},
        {ui->Range_blue_r->text(), ui->Range_blue_g->text(), ui->Range_blue_b->text()},
        {ui->Range_white_r->text(), ui->Range_white_g->text(), ui->Range_white_b->text()},
        {ui->red_r->text(), ui->red_g->text(), ui->red_b->text()},
        {ui->blue_r->text(), ui->blue_g->text(), ui->blue_b->text()},
        {ui->white_r->text(), ui->white_g->text(), ui->white_b->text()},
    };


    // 写入标题行
    out << "color,r,g,b\n";
    // 写入数据行
    for (int i = 0; i < 6; i++) {
        out << colorNames[i] << ","
            << wcolor[i][0] << ","
            << wcolor[i][1] << ","
            << wcolor[i][2] << "\n";
    }

    file.close();
    qDebug() << "CSV文件已成功写入";
}

QString ColorSet::ColorRangeTojson(const QList<QList<int>>& colorRange)
{
    QJsonArray jsonArray;
    for (const QList<int>& row : colorRange) {
        QJsonArray jsonRow;
        for (int value : row) {
            jsonRow.append(value);
        }
        jsonArray.append(jsonRow);
    }

    QJsonDocument doc(jsonArray);
    return doc.toJson(QJsonDocument::Compact);
}

QString ColorSet::TargetColorTojson(const QRgb& color){
    QJsonObject colorObj;
    colorObj["r"] = qRed(color);
    colorObj["g"] = qGreen(color);
    colorObj["b"] = qBlue(color);
    QJsonDocument doc(colorObj);
    return doc.toJson(QJsonDocument::Compact);
}


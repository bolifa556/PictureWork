#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "TextProcess.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stack->setCurrentIndex(0);
    // 读取颜色文件
    colorsetwindow->setWindowTitle("颜色设置");
    colorsetwindow->createColorFile(QCoreApplication::applicationDirPath() + "/ColorSet.csv");
    colorsetwindow->readColor();
    // 设置输出文本框
    outputWidget->setReadOnly(true);
    ui->work_output->addTab(outputWidget,"处理信息");
}

MainWindow::~MainWindow()
{
    // 确保窗口销毁时终止线程
    for(QProcess* m_process:processes)m_process->kill();
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent *event) {
    // 关闭窗口时终止线程
    for(QProcess* m_process:processes)m_process->kill();
    event->accept();
}

void MainWindow::on_choose_input_clicked()
{
    QString m_lastSelectedPath = QDir::homePath();
    QStringList filePaths = QFileDialog::getOpenFileNames(
        this,
        tr("选择多个文件"),
        m_lastSelectedPath,// 默认打开的路径（这里是用户主目录）
        tr("图片文件 (*.png *.jpg *.bmp);;所有文件 (*.*)")
        );
    ui->input_path->setText("");
    if (!filePaths.isEmpty()) {
        foreach (const QString &filePath, filePaths) {
            ui->input_path->setText(ui->input_path->text()+filePath+";");
        }
    }
    if (!filePaths.isEmpty()) {
        m_lastSelectedPath = filePaths.first(); // 记住这次选择的路径
    }
}


void MainWindow::on_choose_output_clicked()
{
    // 选择照片路径
    QStringList pathList = ui->input_path->text().split(";", Qt::SkipEmptyParts);

    QString folderPath = QFileDialog::getExistingDirectory(
        this,                 // 父窗口
        tr("选择文件夹"),     // 对话框标题
        pathList.isEmpty()?QDir::homePath():QFileInfo(pathList.first()).absolutePath(),     // 默认打开的路径（这里是照片选择路径）
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
        );
    if (!folderPath.isEmpty()) {
        ui->output_path->setText(folderPath);
    }
}

void MainWindow::on_changeBackground_button_clicked()
{
    // 获取需要改变的颜色
    QString color = ui->chooseColor->currentText();
    // 获取输入图片路径和输出路径
    QStringList InputPathList = ui->input_path->text().split(";", Qt::SkipEmptyParts);
    QString OutputPathfolder = ui->output_path->text();
    // 改变图片
    foreach (const QString &inputpath, InputPathList) {
        // 处理图片
        ChangeBackgroundColor(inputpath,OutputPathfolder,color);
    }

}

void MainWindow::ChangeBackgroundColor(const QString &inputPath, const QString &outputPath, const QString &color)
{
    // 加载图片
    QImage img(inputPath);
    if (img.isNull()) {
        qWarning() << "Failed to load image:" << inputPath;
        return;
    }
    QImage modifiedImage = img.copy();
    // 转换为RGB格式
    modifiedImage = modifiedImage.convertToFormat(QImage::Format_RGB888);

    // 获取文本颜色数据
    QRgb targetColor;
    QList<int> colorRange_r,colorRange_g,colorRange_b;

    // 设置目标颜色
    if(color=="红色"){
        targetColor = qRgb(colorsetwindow->color[3][0].toInt(), colorsetwindow->color[3][1].toInt(), colorsetwindow->color[3][2].toInt());
    }else if(color=="蓝色"){
        targetColor = qRgb(colorsetwindow->color[4][0].toInt(), colorsetwindow->color[4][1].toInt(), colorsetwindow->color[4][2].toInt());
    }else if(color=="白色"){
        targetColor = qRgb(colorsetwindow->color[5][0].toInt(), colorsetwindow->color[5][1].toInt(), colorsetwindow->color[5][2].toInt());
    }

    // 判断待转换颜色（以左上角第（100，100）处为判断颜色）
    QRgb target_pixel = modifiedImage.pixel(100, 100);
    bool isfind = false;
    int size = 0;
    for(int j = 0;j < 3;j++){
        colorRange_r = extractNumbers(colorsetwindow->color[j][0]);
        colorRange_g = extractNumbers(colorsetwindow->color[j][1]);
        colorRange_b = extractNumbers(colorsetwindow->color[j][2]);
        size = colorRange_r.size();
        for(int i=1;i<size;i++){
            // 判断是否在给定范围
            if (qRed(target_pixel) >= colorRange_r[2*i-2] && qRed(target_pixel) <= colorRange_r[2*i-1]
                && qGreen(target_pixel) >= colorRange_g[2*i-2] && qGreen(target_pixel) <= colorRange_g[2*i-1]
                && qBlue(target_pixel) >= colorRange_b[2*i-2] && qBlue(target_pixel) <= colorRange_b[2*i-1])
            {
                // 在此范围内，则待转变颜色为j
                isfind = true;
                break;
            }
        }
        if(isfind)break;
    }

    // 将待转变颜色和目标颜色转变为json格式
    QList<QList<int>> colorRange;
    colorRange.append(colorRange_r);
    colorRange.append(colorRange_g);
    colorRange.append(colorRange_b);
    QString colorRange_json = colorsetwindow->ColorRangeTojson(colorRange);
    QString targetcolor_json = colorsetwindow->TargetColorTojson(targetColor);

    // 获取原图片名称
    QFileInfo fileInfo(inputPath);
    // 获取输出地址
    QString output_filepath = QDir(outputPath).filePath("change_" + fileInfo.fileName());
    // 获取python可执行文件路径
    QString exePath = QDir::currentPath() + "/changeBackground.exe";
    //QString exePath = "D:/MYPC/QT/QTProject/PictureWork/build/Desktop_Qt_6_5_3_MinGW_64_bit-Release/release/changeBackground.exe";
    outputWidget->append("exepath:"+exePath);

    // 创建进程并设置参数
    QProcess process;
    QStringList arguments;
    arguments<<inputPath<<output_filepath<<colorRange_json<<targetcolor_json;

    // 启动进程
    process.start(exePath, arguments);

    // 等待完成
    if (process.waitForFinished(30000)) {   //30s超时
        QByteArray output = process.readAllStandardOutput();
        QByteArray error = process.readAllStandardError();

        if (process.exitCode() == 0) {
            outputWidget->append("Python output:" + output);
        } else {
            outputWidget->append("Python error:" + error);
        }
    } else {
        outputWidget->append("Process timed out");
    }
}


QList<int> MainWindow::extractNumbers(const QString &str) {
    QList<int> numbers;
    QRegularExpression re("(\\d+)"); // 匹配连续的数字
    QRegularExpressionMatchIterator it = re.globalMatch(str);
    while (it.hasNext()) {
        QRegularExpressionMatch match = it.next();
        numbers.append(match.captured(1).toInt());
    }
    return numbers;
}

void MainWindow::on_ColorSet_button_clicked()
{
    colorsetwindow->readColor();
    colorsetwindow->show();
}





































void MainWindow::on_GoHome_pressed()
{
    ui->stack->setCurrentIndex(0);
}


void MainWindow::on_ChooseFile_clicked()
{
    QString line=QFileDialog::getOpenFileName(this, tr("选择xml文件"), "", tr("xml文件 (*xml*)"));
    if(line.endsWith(".xml"))ui->input_path->setText(line);
}


void MainWindow::onList1SelectionChanged() {
    // 当listWidget1的选中项发生变化时，清空listWidget2的选中项
    if (ui->RetaList->selectedItems().count() > 0) {
        ui->RetaList->clearSelection();
    }
}
void MainWindow::onList2SelectionChanged() {
    // 当listWidget2的选中项发生变化时，清空listWidget1的选中项
    if (ui->RetaList_2->selectedItems().count() > 0) {
        ui->RetaList_2->clearSelection();
    }
}

void MainWindow::on_RetaList_clicked(const QModelIndex &index)
{
    if(index.row()==0){
        ui->stack->setCurrentIndex(1);
    }
    onList2SelectionChanged();
}

void MainWindow::on_RetaList_2_clicked(const QModelIndex &index)
{
    if(index.row()==0){
        ui->stack->setCurrentIndex(2);
    }else if(index.row()==1){
        ui->stack->setCurrentIndex(3);
    }
    onList1SelectionChanged();
}




void MainWindow::on_CalculateButton_clicked()
{
    QString Xmlfilepath=ui->input_path->text();
    if(!Xmlfilepath.endsWith(".xml")){
        // 如果不是以 ".xml" 结尾，弹出错误消息
        QMessageBox::critical(nullptr, "错误", "请选择xml文件");
    }else{
        // 设置工作目录
        QFileInfo fileInfo(Xmlfilepath);
        QDir::setCurrent(fileInfo.absolutePath());
        qDebug()<<Xmlfilepath;

        // 新建标签页
        QString filename;//标签页的名字
        if(Xmlfilepath.contains("\\")){
            filename=Xmlfilepath.mid(Xmlfilepath.lastIndexOf("\\")+1);//标签页的名字
        }else{
            filename=Xmlfilepath.mid(Xmlfilepath.lastIndexOf("/")+1);//标签页的名字
        }
        QTextEdit *outputWidget = new QTextEdit(this);//标签页的内容
        outputWidget->setReadOnly(true);
        ui->work_output->addTab(outputWidget,filename);

        // 进行计算
        QStringList arguments;
        arguments << "-i" << Xmlfilepath;
        QProcess* m_process = new QProcess(this); // 在主线程中创建QProcess
        m_process->start(retapath, arguments);
        processes.push_back(m_process);

        connect(m_process, &QProcess::readyReadStandardOutput, this, [m_process, outputWidget]() {
            readStandardOutput(m_process, outputWidget);
        });

    }
}


void MainWindow::on_chooseXmlFile_clicked()
{
    QString line=QFileDialog::getOpenFileName(this, tr("选择xml文件"), "", tr("xml文件 (*xml*)"));
    if(line.endsWith(".xml"))ui->xmlline->setText(line);
}


void MainWindow::on_chooseCsvFile_clicked()
{
    QString line=QFileDialog::getOpenFileName(this, tr("选择csv文件"), "", tr("csv文件 (*csv*)"));
    if(line.endsWith(".csv"))ui->csvline->setText(line);
}


void MainWindow::on_model_button_clicked()
{
    QString Xmlfilepath=ui->xmlline->text();
    QString Csvfilepath=ui->csvline->text();

    if(!Xmlfilepath.endsWith(".xml")){
        // 如果不是以 ".xml" 结尾，弹出错误消息
        QMessageBox::critical(nullptr, "错误", "请选择xml文件");
    }else{
        // 建模
        QStringList arguments;
        arguments << Xmlfilepath << Csvfilepath;

        QProcess* m_process = new QProcess(this); // 在主线程中创建QProcess
        m_process->start(Retamodelpath, arguments);
        processes.push_back(m_process);
    }
}




void MainWindow::on_openpdf_clicked()
{
    if (!QFile::exists(pdfpath)) {
        qDebug() << "文件不存在：" << pdfpath;
        return;
    }else{
        //QProcess::startDetached(pdfpath);
        QProcess::startDetached("cmd", QStringList() << "/c" << pdfpath);
    }

}


void MainWindow::on_drawchoosecsv_clicked()
{
    QString line=QFileDialog::getOpenFileName(this, tr("选择csv文件"), "", tr("csv文件 (*csv*)"));
    if(line.endsWith(".csv"))
    ui->drawcsvline->setText(line);
}


void MainWindow::on_drawreadcsv_clicked()
{
    ui->headersList->clear();
    ui->headersList2->clear();
    // 读取文件
    QString Csvfilepath=ui->drawcsvline->text();
    if(!Csvfilepath.endsWith(".csv")){
        // 如果不是以 ".csv" 结尾，弹出错误消息
        QMessageBox::critical(nullptr, "错误", "请选择csv文件");
        return;
    }
    QFile file(Csvfilepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << Csvfilepath;
        return;
    }

    // 读取标题行
    QTextStream in(&file);
    QString headerLine = in.readLine();  // 读取标题行
    file.close();

    // 处理标题行，取每个标题第一个:之前的内容，并合并重复标题
    QStringList headers = headerLine.split(',');  // 假设CSV文件使用逗号分隔
    QSet<QString> uniqueHeaders;  // 用于存储唯一的标题
    for (const QString &header : headers) {
        QString trimmedHeader = header.trimmed();  // 去除前后空格
        int colonIndex = trimmedHeader.indexOf(':');
        if (colonIndex != -1) {
            trimmedHeader = trimmedHeader.left(colonIndex);  // 提取冒号之前的内容
        }
        uniqueHeaders.insert(trimmedHeader);  // 添加到集合中，自动去重
    }
    // 排序标题
    QStringList sortedHeaders = uniqueHeaders.values();
    sortedHeaders.sort();

    // 将处理后的标题显示在一个可滚动的列表框中
    for (const QString &header : sortedHeaders) {
        if(header=="time"||header=="step")continue;
        ui->headersList->addItem(header);  // 将每个唯一的标题添加到列表框中
    }
}


void MainWindow::on_headersList_itemClicked(QListWidgetItem *item)
{
    ui->headersList2->clear();
    // 读取文件
    QString Csvfilepath=ui->drawcsvline->text();
    if(!Csvfilepath.endsWith(".csv")){
        // 如果不是以 ".csv" 结尾，弹出错误消息
        QMessageBox::critical(nullptr, "错误", "请选择csv文件");
        return;
    }
    QFile file(Csvfilepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << Csvfilepath;
        return;
    }
    // 读取标题行
    QTextStream in(&file);
    QString headerLine = in.readLine();  // 读取标题行
    file.close();
    QStringList headers = headerLine.split(',');  // 假设CSV文件使用逗号分隔

    // 根据item的名称，选择标题添加到第二个列表框中
    for (const QString &header : headers) {
        QString trimmedHeader = header.trimmed();  // 去除前后空格
        int colonIndex = trimmedHeader.indexOf(':');
        if (colonIndex != -1) {
            trimmedHeader = trimmedHeader.left(colonIndex);  // 提取冒号之前的内容
        }
        if(trimmedHeader==item->text())
        ui->headersList2->addItem(header);
    }
}


void MainWindow::on_drawcsvline_textChanged(const QString &arg1)
{
    ui->headersList->clear();
    ui->headersList2->clear();
}

void MainWindow::on_searchComponent_textChanged(const QString &arg1)
{
    // 遍历所有列表框1的选项
    for (int i = 0; i < ui->headersList->count(); ++i) {
        QListWidgetItem *item = ui->headersList->item(i);
        if (item->text().contains(ui->searchComponent->text())) {
            item->setHidden(false); // 显示包含 text 的项
        } else {
            item->setHidden(true); // 隐藏不包含 text 的项
        }
    }

}


void MainWindow::on_drawbutton_clicked()
{
    // 读取文件
    QString Csvfilepath=ui->drawcsvline->text();
    if(!Csvfilepath.endsWith(".csv")){
        // 如果不是以 ".csv" 结尾，弹出错误消息
        QMessageBox::critical(nullptr, "错误", "请选择csv文件");
        return;
    }
    QFile file(Csvfilepath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件:" << Csvfilepath;
        return;
    }

    // 读取标题行
    QTextStream in(&file);
    QStringList headers = in.readLine().split(',');

    // 获取列标
    int timeIndex = headers.indexOf("time");
    int columnIndex = headers.indexOf(ui->headersList2->currentItem()->text());

    // 将相应数据录入QPoint中
    QVector<QPointF> dataPoints;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');

        if (fields.size() > qMax(timeIndex, columnIndex)) {
            double time = fields[timeIndex].toDouble();
            double value = fields[columnIndex].toDouble();
            dataPoints.append(QPointF(time, value));
        }
    }
    file.close();

    // 创建图表
    QLineSeries *series = new QLineSeries();
    for (const QPointF &point : dataPoints) {
        series->append(point);
    }

    QChart *chart = new QChart();
    chart->addSeries(series);

    // 创建X轴和Y轴
    QValueAxis *axisX = new QValueAxis;
    axisX->setTitleText("Time");
    axisX->setRange(dataPoints.first().x(), dataPoints.last().x()); // 根据数据范围设置X轴范围

    QValueAxis *axisY = new QValueAxis;
    //axisY->setTitleText("Temperature");

    // 将坐标轴附加到图表
    chart->addAxis(axisX, Qt::AlignBottom);
    chart->addAxis(axisY, Qt::AlignLeft);

    // 将系列附加到坐标轴
    series->attachAxis(axisX);
    series->attachAxis(axisY);

    // 设置图表标题
    //chart->setTitle("Temperature vs Time");

    // 设置线条样式（例如虚线）
    QPen pen(Qt::blue);
    pen.setStyle(Qt::DashLine);
    series->setPen(pen);

    // 隐藏图例
    chart->legend()->hide();

    // 设置图表边距为0，去除空白区域
    chart->setMargins(QMargins(0, 0, 0, 0)); // 左、上、右、下边距
    chart->setBackgroundRoundness(0); // 去除背景圆角

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // 添加图表到新的标签页
    int newTabIndex = ui->pictureTab->addTab(chartView, ui->headersList2->currentItem()->text());
    ui->pictureTab->setCurrentIndex(newTabIndex);

}


void MainWindow::on_deletePicture_clicked()
{
    int currentIndex = ui->pictureTab->currentIndex();
    // 删除该页
    ui->pictureTab->removeTab(currentIndex);
}


void MainWindow::on_endcalculation_clicked()
{
    int currentIndex = ui->work_output->currentIndex();
    if (currentIndex != -1){
        // 结束当前页进程
        processes[currentIndex]->kill();
        processes.erase(processes.begin()+currentIndex);
        // 删除该页
        ui->work_output->removeTab(currentIndex);
    }
}















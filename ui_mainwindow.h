/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_11;
    QFrame *mainFrame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *Listframe;
    QVBoxLayout *verticalLayout;
    QFrame *home_head;
    QHBoxLayout *horizontalLayout;
    QPushButton *GoHome;
    QLabel *label_3;
    QFrame *line;
    QLabel *label;
    QListWidget *RetaList;
    QLabel *label_2;
    QListWidget *RetaList_2;
    QStackedWidget *stack;
    QWidget *homepage;
    QVBoxLayout *verticalLayout_14;
    QFrame *title;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame_18;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *openpdf;
    QWidget *retapage;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_6;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *input_path;
    QPushButton *choose_input;
    QLabel *label_13;
    QFrame *frame_20;
    QHBoxLayout *horizontalLayout_12;
    QLineEdit *output_path;
    QPushButton *choose_output;
    QFrame *frame_21;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *chooseColor;
    QPushButton *changeBackground_button;
    QPushButton *ColorSet_button;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *work_output;
    QWidget *page_4;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_7;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_7;
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *xmlline;
    QPushButton *chooseXmlFile;
    QLabel *label_8;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *csvline;
    QPushButton *chooseCsvFile;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *model_button;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QWidget *page_3;
    QGridLayout *gridLayout;
    QFrame *frame_12;
    QVBoxLayout *verticalLayout_13;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_12;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *drawcsvline;
    QPushButton *drawchoosecsv;
    QPushButton *drawreadcsv;
    QFrame *frame_13;
    QHBoxLayout *horizontalLayout_9;
    QFrame *frame_14;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame_16;
    QHBoxLayout *horizontalLayout_7;
    QLineEdit *searchComponent;
    QPushButton *pushButton_2;
    QListWidget *headersList;
    QFrame *frame_15;
    QVBoxLayout *verticalLayout_12;
    QPushButton *drawbutton;
    QListWidget *headersList2;
    QFrame *frame_17;
    QVBoxLayout *verticalLayout_15;
    QTabWidget *pictureTab;
    QPushButton *deletePicture;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(983, 499);
        MainWindow->setCursor(QCursor(Qt::ArrowCursor));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_11 = new QHBoxLayout(centralwidget);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        mainFrame = new QFrame(centralwidget);
        mainFrame->setObjectName("mainFrame");
        mainFrame->setStyleSheet(QString::fromUtf8("QFrame#mainFrame{\n"
"background-color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        mainFrame->setFrameShape(QFrame::StyledPanel);
        mainFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(mainFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Listframe = new QFrame(mainFrame);
        Listframe->setObjectName("Listframe");
        Listframe->setMinimumSize(QSize(0, 0));
        Listframe->setMaximumSize(QSize(130, 16777215));
        Listframe->setStyleSheet(QString::fromUtf8("QFrame#Listframe{\n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(113, 109, 252, 255), stop:1 rgba(164, 124, 255, 255));\n"
"	border-top-left-radius:10px;\n"
"	border-bottom-left-radius:10px;\n"
"}\n"
"\n"
""));
        Listframe->setFrameShape(QFrame::StyledPanel);
        Listframe->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(Listframe);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        home_head = new QFrame(Listframe);
        home_head->setObjectName("home_head");
        home_head->setStyleSheet(QString::fromUtf8("QFrame{\n"
"	background-color: transparent;\n"
"}"));
        home_head->setFrameShape(QFrame::StyledPanel);
        home_head->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(home_head);
        horizontalLayout->setObjectName("horizontalLayout");
        GoHome = new QPushButton(home_head);
        GoHome->setObjectName("GoHome");
        GoHome->setCursor(QCursor(Qt::ArrowCursor));
        GoHome->setStyleSheet(QString::fromUtf8("QPushButton#GoHome{\n"
"border-radius: 10px;\n"
"background-color: transparent;\n"
"background-image: url(:/new/prefix1/resource/icon/cube.svg);\n"
"}\n"
"\n"
"\n"
""));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/resource/icon/whiteHome.svg"), QSize(), QIcon::Normal, QIcon::Off);
        GoHome->setIcon(icon);
        GoHome->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(GoHome);

        label_3 = new QLabel(home_head);
        label_3->setObjectName("label_3");
        QFont font;
        font.setPointSize(15);
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label_3);


        verticalLayout->addWidget(home_head);

        line = new QFrame(Listframe);
        line->setObjectName("line");
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        label = new QLabel(Listframe);
        label->setObjectName("label");
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 0);\n"
"background-color: transparent;\n"
"padding-left: 0px;"));

        verticalLayout->addWidget(label);

        RetaList = new QListWidget(Listframe);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/resource/icon/calculate.svg"), QSize(), QIcon::Normal, QIcon::Off);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QFont font2;
        font2.setPointSize(9);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(RetaList);
        __qlistwidgetitem->setFont(font2);
        __qlistwidgetitem->setBackground(brush1);
        __qlistwidgetitem->setForeground(brush);
        __qlistwidgetitem->setIcon(icon1);
        RetaList->setObjectName("RetaList");
        RetaList->setStyleSheet(QString::fromUtf8(" QListView {\n"
"border-radius: 20px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: transparent;\n"
"}\n"
"QListView::item{\n"
"background-color: transparent;\n"
"height:40px;\n"
"padding-left:12px;\n"
"}\n"
"QListView::item:hover {\n"
"background-color: rgba(216, 216, 216, 50);\n"
"}\n"
"QListView::item:selected{\n"
"background-color: rgba(255, 248, 241,50);\n"
"color: rgb(16,15,35);\n"
"/*border-bottom:2px solid rgb(119,111,255);*/\n"
"}\n"
""));

        verticalLayout->addWidget(RetaList);

        label_2 = new QLabel(Listframe);
        label_2->setObjectName("label_2");
        QFont font3;
        font3.setPointSize(12);
        font3.setBold(false);
        label_2->setFont(font3);
        label_2->setCursor(QCursor(Qt::ArrowCursor));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(85, 0, 127);\n"
"background-color: transparent;\n"
"padding-left:0px;"));
        label_2->setLineWidth(1);
        label_2->setTextFormat(Qt::AutoText);

        verticalLayout->addWidget(label_2);

        RetaList_2 = new QListWidget(Listframe);
        RetaList_2->setObjectName("RetaList_2");
        RetaList_2->setStyleSheet(QString::fromUtf8("QListView {\n"
"border-radius: 20px;\n"
"color: rgb(0, 0, 0);\n"
"background-color: transparent\n"
"}\n"
"QListView::item{\n"
"background-color: transparent;\n"
"height:40px;\n"
"padding-left:12px;\n"
"}\n"
"QListView::item:hover {\n"
"background-color: rgba(216, 216, 216, 50);\n"
"}\n"
"QListView::item:selected{\n"
"background-color: rgba(255, 248, 241,50);\n"
"color: rgb(16,15,35);\n"
"/*border-bottom:2px solid rgb(119,111,255);*/\n"
"}"));

        verticalLayout->addWidget(RetaList_2);


        horizontalLayout_2->addWidget(Listframe);

        stack = new QStackedWidget(mainFrame);
        stack->setObjectName("stack");
        stack->setStyleSheet(QString::fromUtf8(""));
        stack->setLineWidth(1);
        homepage = new QWidget();
        homepage->setObjectName("homepage");
        homepage->setStyleSheet(QString::fromUtf8("background-color: white"));
        verticalLayout_14 = new QVBoxLayout(homepage);
        verticalLayout_14->setObjectName("verticalLayout_14");
        title = new QFrame(homepage);
        title->setObjectName("title");
        title->setFrameShape(QFrame::StyledPanel);
        title->setFrameShadow(QFrame::Raised);
        horizontalLayout_10 = new QHBoxLayout(title);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        frame_18 = new QFrame(title);
        frame_18->setObjectName("frame_18");
        frame_18->setFrameShape(QFrame::StyledPanel);
        frame_18->setFrameShadow(QFrame::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_18);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_4 = new QLabel(frame_18);
        label_4->setObjectName("label_4");
        QFont font4;
        font4.setPointSize(20);
        label_4->setFont(font4);

        verticalLayout_9->addWidget(label_4, 0, Qt::AlignHCenter|Qt::AlignBottom);

        label_5 = new QLabel(frame_18);
        label_5->setObjectName("label_5");
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("padding-top:12px;"));

        verticalLayout_9->addWidget(label_5, 0, Qt::AlignHCenter|Qt::AlignTop);


        horizontalLayout_10->addWidget(frame_18);


        verticalLayout_14->addWidget(title);

        openpdf = new QPushButton(homepage);
        openpdf->setObjectName("openpdf");
        openpdf->setCursor(QCursor(Qt::OpenHandCursor));
        openpdf->setStyleSheet(QString::fromUtf8("color: rgb(85, 170, 255);\n"
"background-color: transparent;\n"
"border-radius:10px;"));

        verticalLayout_14->addWidget(openpdf, 0, Qt::AlignLeft);

        stack->addWidget(homepage);
        retapage = new QWidget();
        retapage->setObjectName("retapage");
        verticalLayout_3 = new QVBoxLayout(retapage);
        verticalLayout_3->setObjectName("verticalLayout_3");
        frame_2 = new QFrame(retapage);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(frame_2);
        label_6->setObjectName("label_6");
        label_6->setFont(font1);
        label_6->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_2->addWidget(label_6);

        frame = new QFrame(frame_2);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        input_path = new QLineEdit(frame);
        input_path->setObjectName("input_path");
        input_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(input_path);

        choose_input = new QPushButton(frame);
        choose_input->setObjectName("choose_input");
        choose_input->setStyleSheet(QString::fromUtf8("QPushButton#ChooseFile{\n"
"border-radius: 10px;\n"
"background-color: transparent;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/resource/icon/choosefile.svg"), QSize(), QIcon::Normal, QIcon::Off);
        choose_input->setIcon(icon2);

        horizontalLayout_3->addWidget(choose_input);


        verticalLayout_2->addWidget(frame);


        verticalLayout_3->addWidget(frame_2);

        label_13 = new QLabel(retapage);
        label_13->setObjectName("label_13");
        label_13->setFont(font1);
        label_13->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_3->addWidget(label_13);

        frame_20 = new QFrame(retapage);
        frame_20->setObjectName("frame_20");
        frame_20->setFrameShape(QFrame::StyledPanel);
        frame_20->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_20);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        output_path = new QLineEdit(frame_20);
        output_path->setObjectName("output_path");
        output_path->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(output_path);

        choose_output = new QPushButton(frame_20);
        choose_output->setObjectName("choose_output");
        choose_output->setStyleSheet(QString::fromUtf8("QPushButton#ChooseFile{\n"
"border-radius: 10px;\n"
"background-color: transparent;\n"
"}"));
        choose_output->setIcon(icon2);

        horizontalLayout_12->addWidget(choose_output);


        verticalLayout_3->addWidget(frame_20);

        frame_21 = new QFrame(retapage);
        frame_21->setObjectName("frame_21");
        frame_21->setMinimumSize(QSize(200, 0));
        frame_21->setMaximumSize(QSize(200, 16777215));
        frame_21->setFrameShape(QFrame::StyledPanel);
        frame_21->setFrameShadow(QFrame::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_21);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        chooseColor = new QComboBox(frame_21);
        chooseColor->addItem(QString());
        chooseColor->addItem(QString());
        chooseColor->addItem(QString());
        chooseColor->setObjectName("chooseColor");
        chooseColor->setMaximumSize(QSize(50, 16777215));
        chooseColor->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_13->addWidget(chooseColor);

        changeBackground_button = new QPushButton(frame_21);
        changeBackground_button->setObjectName("changeBackground_button");
        changeBackground_button->setMinimumSize(QSize(100, 0));
        changeBackground_button->setMaximumSize(QSize(200, 16777215));

        horizontalLayout_13->addWidget(changeBackground_button);

        ColorSet_button = new QPushButton(frame_21);
        ColorSet_button->setObjectName("ColorSet_button");
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/resource/icon/setting.svg"), QSize(), QIcon::Normal, QIcon::Off);
        ColorSet_button->setIcon(icon3);

        horizontalLayout_13->addWidget(ColorSet_button);


        verticalLayout_3->addWidget(frame_21, 0, Qt::AlignHCenter);

        frame_3 = new QFrame(retapage);
        frame_3->setObjectName("frame_3");
        frame_3->setStyleSheet(QString::fromUtf8("background-color: rgba(237, 241, 247, 255);"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setObjectName("verticalLayout_4");
        work_output = new QTabWidget(frame_3);
        work_output->setObjectName("work_output");
        work_output->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_4->addWidget(work_output);


        verticalLayout_3->addWidget(frame_3);

        stack->addWidget(retapage);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        verticalLayout_8 = new QVBoxLayout(page_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        frame_7 = new QFrame(page_4);
        frame_7->setObjectName("frame_7");
        frame_7->setFrameShape(QFrame::StyledPanel);
        frame_7->setFrameShadow(QFrame::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_7);
        verticalLayout_7->setObjectName("verticalLayout_7");
        frame_6 = new QFrame(frame_7);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::StyledPanel);
        frame_6->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_6);
        verticalLayout_5->setObjectName("verticalLayout_5");
        label_7 = new QLabel(frame_6);
        label_7->setObjectName("label_7");
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_5->addWidget(label_7);

        frame_4 = new QFrame(frame_6);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_4);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        xmlline = new QLineEdit(frame_4);
        xmlline->setObjectName("xmlline");
        xmlline->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(xmlline);

        chooseXmlFile = new QPushButton(frame_4);
        chooseXmlFile->setObjectName("chooseXmlFile");
        chooseXmlFile->setStyleSheet(QString::fromUtf8("QPushButton#ChooseFile{\n"
"border-radius: 10px;\n"
"background-color: transparent;\n"
"}"));
        chooseXmlFile->setIcon(icon2);

        horizontalLayout_4->addWidget(chooseXmlFile);


        verticalLayout_5->addWidget(frame_4);

        label_8 = new QLabel(frame_6);
        label_8->setObjectName("label_8");
        label_8->setFont(font1);
        label_8->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_5->addWidget(label_8);

        frame_5 = new QFrame(frame_6);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_5);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        csvline = new QLineEdit(frame_5);
        csvline->setObjectName("csvline");
        csvline->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(csvline);

        chooseCsvFile = new QPushButton(frame_5);
        chooseCsvFile->setObjectName("chooseCsvFile");
        chooseCsvFile->setStyleSheet(QString::fromUtf8("QPushButton#ChooseFile{\n"
"border-radius: 10px;\n"
"background-color: transparent;\n"
"}"));
        chooseCsvFile->setIcon(icon2);

        horizontalLayout_5->addWidget(chooseCsvFile);


        verticalLayout_5->addWidget(frame_5);


        verticalLayout_7->addWidget(frame_6);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::StyledPanel);
        frame_9->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_9);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        model_button = new QPushButton(frame_9);
        model_button->setObjectName("model_button");

        horizontalLayout_8->addWidget(model_button, 0, Qt::AlignHCenter|Qt::AlignTop);


        verticalLayout_7->addWidget(frame_9);

        frame_8 = new QFrame(frame_7);
        frame_8->setObjectName("frame_8");
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(237,241,247);"));
        frame_8->setFrameShape(QFrame::StyledPanel);
        frame_8->setFrameShadow(QFrame::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_8);
        verticalLayout_6->setObjectName("verticalLayout_6");
        label_9 = new QLabel(frame_8);
        label_9->setObjectName("label_9");

        verticalLayout_6->addWidget(label_9);

        label_10 = new QLabel(frame_8);
        label_10->setObjectName("label_10");

        verticalLayout_6->addWidget(label_10);

        label_11 = new QLabel(frame_8);
        label_11->setObjectName("label_11");

        verticalLayout_6->addWidget(label_11);


        verticalLayout_7->addWidget(frame_8);


        verticalLayout_8->addWidget(frame_7);

        stack->addWidget(page_4);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        gridLayout = new QGridLayout(page_3);
        gridLayout->setObjectName("gridLayout");
        frame_12 = new QFrame(page_3);
        frame_12->setObjectName("frame_12");
        frame_12->setFrameShape(QFrame::StyledPanel);
        frame_12->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(frame_12);
        verticalLayout_13->setObjectName("verticalLayout_13");
        frame_11 = new QFrame(frame_12);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::StyledPanel);
        frame_11->setFrameShadow(QFrame::Raised);
        verticalLayout_10 = new QVBoxLayout(frame_11);
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_12 = new QLabel(frame_11);
        label_12->setObjectName("label_12");
        label_12->setFont(font1);
        label_12->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout_10->addWidget(label_12);

        frame_10 = new QFrame(frame_11);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::StyledPanel);
        frame_10->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_10);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        drawcsvline = new QLineEdit(frame_10);
        drawcsvline->setObjectName("drawcsvline");
        drawcsvline->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(drawcsvline);

        drawchoosecsv = new QPushButton(frame_10);
        drawchoosecsv->setObjectName("drawchoosecsv");
        drawchoosecsv->setStyleSheet(QString::fromUtf8("QPushButton#ChooseFile{\n"
"border-radius: 10px;\n"
"background-color: transparent;\n"
"}"));
        drawchoosecsv->setIcon(icon2);

        horizontalLayout_6->addWidget(drawchoosecsv);

        drawreadcsv = new QPushButton(frame_10);
        drawreadcsv->setObjectName("drawreadcsv");

        horizontalLayout_6->addWidget(drawreadcsv);


        verticalLayout_10->addWidget(frame_10);


        verticalLayout_13->addWidget(frame_11);

        frame_13 = new QFrame(frame_12);
        frame_13->setObjectName("frame_13");
        frame_13->setStyleSheet(QString::fromUtf8("background-color: rgb(237,241,247);"));
        frame_13->setFrameShape(QFrame::StyledPanel);
        frame_13->setFrameShadow(QFrame::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_13);
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        frame_14 = new QFrame(frame_13);
        frame_14->setObjectName("frame_14");
        frame_14->setFrameShape(QFrame::StyledPanel);
        frame_14->setFrameShadow(QFrame::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_14);
        verticalLayout_11->setObjectName("verticalLayout_11");
        frame_16 = new QFrame(frame_14);
        frame_16->setObjectName("frame_16");
        frame_16->setFrameShape(QFrame::StyledPanel);
        frame_16->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_16);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        horizontalLayout_7->setContentsMargins(0, -1, 0, -1);
        searchComponent = new QLineEdit(frame_16);
        searchComponent->setObjectName("searchComponent");
        searchComponent->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_7->addWidget(searchComponent, 0, Qt::AlignLeft);

        pushButton_2 = new QPushButton(frame_16);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("border-radius:10px;\n"
"background-color: transparent;"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/resource/icon/search.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon4);

        horizontalLayout_7->addWidget(pushButton_2);


        verticalLayout_11->addWidget(frame_16);

        headersList = new QListWidget(frame_14);
        headersList->setObjectName("headersList");

        verticalLayout_11->addWidget(headersList);


        horizontalLayout_9->addWidget(frame_14);

        frame_15 = new QFrame(frame_13);
        frame_15->setObjectName("frame_15");
        frame_15->setFrameShape(QFrame::StyledPanel);
        frame_15->setFrameShadow(QFrame::Raised);
        verticalLayout_12 = new QVBoxLayout(frame_15);
        verticalLayout_12->setObjectName("verticalLayout_12");
        drawbutton = new QPushButton(frame_15);
        drawbutton->setObjectName("drawbutton");
        drawbutton->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(225, 225, 225);"));

        verticalLayout_12->addWidget(drawbutton);

        headersList2 = new QListWidget(frame_15);
        headersList2->setObjectName("headersList2");

        verticalLayout_12->addWidget(headersList2);


        horizontalLayout_9->addWidget(frame_15);

        frame_17 = new QFrame(frame_13);
        frame_17->setObjectName("frame_17");
        frame_17->setFrameShape(QFrame::StyledPanel);
        frame_17->setFrameShadow(QFrame::Raised);
        verticalLayout_15 = new QVBoxLayout(frame_17);
        verticalLayout_15->setObjectName("verticalLayout_15");
        pictureTab = new QTabWidget(frame_17);
        pictureTab->setObjectName("pictureTab");

        verticalLayout_15->addWidget(pictureTab);

        verticalLayout_15->setStretch(0, 100);

        horizontalLayout_9->addWidget(frame_17);

        horizontalLayout_9->setStretch(0, 1);
        horizontalLayout_9->setStretch(1, 1);
        horizontalLayout_9->setStretch(2, 100);

        verticalLayout_13->addWidget(frame_13);


        gridLayout->addWidget(frame_12, 0, 0, 1, 1);

        deletePicture = new QPushButton(page_3);
        deletePicture->setObjectName("deletePicture");
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/resource/icon/delete.svg"), QSize(), QIcon::Normal, QIcon::Off);
        deletePicture->setIcon(icon5);

        gridLayout->addWidget(deletePicture, 1, 0, 1, 1, Qt::AlignRight);

        stack->addWidget(page_3);

        horizontalLayout_2->addWidget(stack);


        horizontalLayout_11->addWidget(mainFrame);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stack->setCurrentIndex(1);
        work_output->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        GoHome->setText(QString());
        label_3->setText(QCoreApplication::translate("MainWindow", "Smr", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\347\205\247\347\211\207\345\244\204\347\220\206", nullptr));

        const bool __sortingEnabled = RetaList->isSortingEnabled();
        RetaList->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = RetaList->item(0);
        ___qlistwidgetitem->setText(QCoreApplication::translate("MainWindow", "\346\224\271\350\203\214\346\231\257", nullptr));
        RetaList->setSortingEnabled(__sortingEnabled);

        label_2->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\254\242\350\277\216\346\202\250\344\275\277\347\224\250\347\205\247\347\211\207\347\274\226\350\276\221\345\231\250\357\274\201", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\347\233\256\345\211\215\345\217\257\344\273\245\346\233\264\346\224\271\347\205\247\347\211\207\350\203\214\346\231\257\357\274\210\346\224\257\346\214\201\347\272\242\343\200\201\350\223\235\343\200\201\347\231\275\344\270\211\350\211\262\357\274\211", nullptr));
        openpdf->setText(QCoreApplication::translate("MainWindow", "\350\257\246\347\273\206\344\277\241\346\201\257\350\257\267\346\237\245\351\230\205\346\212\200\346\234\257\346\226\207\346\241\243", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\347\205\247\347\211\207\350\267\257\345\276\204\357\274\210\347\205\247\347\211\207\346\226\207\344\273\266\345\244\271\346\210\226\350\200\205\347\205\247\347\211\207\357\274\211", nullptr));
        choose_input->setText(QString());
        label_13->setText(QCoreApplication::translate("MainWindow", "\350\257\267\351\200\211\346\213\251\350\276\223\345\207\272\350\267\257\345\276\204", nullptr));
        choose_output->setText(QString());
        chooseColor->setItemText(0, QCoreApplication::translate("MainWindow", "\347\272\242\350\211\262", nullptr));
        chooseColor->setItemText(1, QCoreApplication::translate("MainWindow", "\350\223\235\350\211\262", nullptr));
        chooseColor->setItemText(2, QCoreApplication::translate("MainWindow", "\347\231\275\350\211\262", nullptr));

        changeBackground_button->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\346\224\271\345\217\230\350\203\214\346\231\257", nullptr));
        ColorSet_button->setText(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245xml\346\226\207\344\273\266\357\274\232", nullptr));
        chooseXmlFile->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245csv\346\226\207\344\273\266\357\274\232", nullptr));
        chooseCsvFile->setText(QString());
        model_button->setText(QCoreApplication::translate("MainWindow", "\345\273\272\346\250\241", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\346\263\250\346\204\217\344\272\213\351\241\271\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "1.\345\215\225\347\272\257\350\276\223\345\205\245xml\346\226\207\344\273\266\346\227\266\357\274\214\344\274\232\346\240\271\346\215\256\350\257\245xml\346\226\207\344\273\266\345\273\272\347\253\2133D\346\250\241\345\236\213", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "2.\345\220\214\346\227\266\350\276\223\345\205\245csv\346\226\207\344\273\266\357\274\214\344\274\232\345\234\250\345\273\272\347\253\2133D\346\250\241\345\236\213\347\232\204\345\220\214\346\227\266\357\274\214\345\260\206\346\270\251\345\272\246\347\255\211\350\275\254\345\214\226\344\270\272\351\242\234\350\211\262\350\256\276\347\275\256\347\273\2313D\346\250\241\345\236\213\357\274\214\345\271\266\350\256\276\347\275\256\346\227\266\351\227\264\350\275\264\344\273\245\344\276\233\350\260\203\346\225\264\343\200\202", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245csv\346\226\207\344\273\266\357\274\232", nullptr));
        drawchoosecsv->setText(QString());
        drawreadcsv->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226", nullptr));
        pushButton_2->setText(QString());
        drawbutton->setText(QCoreApplication::translate("MainWindow", "\347\273\230\345\233\276", nullptr));
        deletePicture->setText(QCoreApplication::translate("MainWindow", "\345\210\240\351\231\244", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

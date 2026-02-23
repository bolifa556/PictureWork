#include "TextProcess.h"


void readStandardOutput(QProcess* process,QTextEdit *outputTextEdit) {
    // 读取标准输出
    QByteArray output = process->readAllStandardOutput();
    QString text = QString::fromUtf8(output);



    // 根据内容选择调用 insertColoredText 或 insertColoredError
    if (text.contains("[31m")) {
        insertColoredError(outputTextEdit, text);
    } else {
        insertColoredText(outputTextEdit, text);
    }

    //outputTextEdit->append(text);
}

// 解析 ANSI 转义序列并添加颜色
void insertColoredText(QTextEdit* textWidget, const QString& text) {
    QStringList lines = text.split("\n");
    for (QString& line : lines) {
        if (line.contains("[32m")) {
            QString fixedLine = line.replace("[32m", "").replace("[0n", "").replace("[0m", "");
            highlightBetweenBrackets(textWidget, fixedLine, QColor(Qt::green));
        } else if (line.contains("[34m")) {
            QString fixedLine = line.replace("[34m", "").replace("[0n", "").replace("[0m", "");
            highlightBetweenBrackets(textWidget, fixedLine, QColor(Qt::blue));
        } else if (line.contains("[33m")) {
            QString fixedLine = line.replace("[33m", "").replace("[0n", "").replace("[0m", "");
            highlightBetweenBrackets(textWidget, fixedLine, QColor(Qt::red));
        } else {
            textWidget->append(line);
            textWidget->append("");
        }
    }
}

// 处理报错信息
void insertColoredError(QTextEdit* textWidget, QString& text) {
    if (text.contains("[31m")) {
        QString fixedText = text.replace("[31m", "").replace("[0n", "").replace("[0m", "");
        highlightBetweenBrackets(textWidget, fixedText, QColor(Qt::red));
    }else{
        textWidget->append(text);
    }
    textWidget->append("");
}

// 去掉字符串中方框并设置方框间字符颜色
void highlightBetweenBrackets(QTextEdit* textWidget, QString text, const QColor& color) {
    int start = 0;
    while (true) {
        // 找到第一个方框的位置
        int startIdx = text.indexOf("", start);
        if (startIdx == -1) {
            // 如果没有找到更多的方框，插入剩余的文本并退出
            textWidget->append(text.mid(start));
            //textWidget->insertPlainText(text.mid(start));
            break;
        }

        // 找到第二个方框的位置
        int endIdx = text.indexOf("", startIdx + 1);
        if (endIdx == -1) {
            // 如果没有找到结束方框，插入剩余的文本并退出
            textWidget->append(text.mid(start));
            //textWidget->insertPlainText(text.mid(start));
            break;
        }

        // 提取方框之间的内容
        QString content = text.mid(startIdx + 1, endIdx - startIdx - 1);

        // 插入方框前的文本
        QTextEdit line;
        line.setTextColor(Qt::black); // 重置颜色
        line.insertPlainText(text.mid(start, startIdx - start));
        // 插入方框之间的内容并设置颜色
        line.setTextColor(color);
        line.insertPlainText(content);

        // 导入输入文本框中
        textWidget->append(line.toHtml());

        // 更新起始位置
        start = endIdx + 1;
    }
}

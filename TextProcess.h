#ifndef TEXTPROCESS_H
#define TEXTPROCESS_H

#include <QTextEdit>
#include <QByteArray>
#include <QString>
#include <QColor>
#include <QProcess>

void readStandardOutput(QProcess* process,QTextEdit *outputTextEdit);
void insertColoredText(QTextEdit* textWidget, const QString& text);
void insertColoredError(QTextEdit* textWidget, QString& text);
void highlightBetweenBrackets(QTextEdit* textWidget, QString text, const QColor& color);

#endif // TEXTPROCESS_H


#include <QApplication>
#include <QRegularExpression>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget mainWindow;

    auto vbox = new QVBoxLayout(&mainWindow);
    auto lineEdit = new QLineEdit(&mainWindow);
    auto label = new QLabel(&mainWindow);
    label->setAlignment(Qt::AlignHCenter);

    vbox->addWidget(lineEdit);
    vbox->addWidget(label);


    QObject::connect(lineEdit,&QLineEdit::textEdited,[label](QString currentText)
    {
        QRegularExpression exp("^(\\+)\\d{11}$");
        if(exp.match(currentText).hasMatch())
        {
            label->setText("Ok");
            label->setStyleSheet("QLabel {color : green; font-weight: bold;}");
        }
        else
        {
            label->setText("Not Ok");
            label->setStyleSheet("QLabel {color : red; font-weight: bold;}");
        }
    });

    mainWindow.show();

    return a.exec();
}

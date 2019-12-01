#include "registerWidget.h"

RegisterWidget::RegisterWidget(QWidget* parent)
 : QWidget(parent)
{
    register_button_ = new QPushButton("Regiser", this);
    cancel_button_ = new QPushButton("Cancel", this);

    login_le_ = new QLineEdit(this);
    passw_le_ = new QLineEdit(this);
    passw_le_ -> setEchoMode(QLineEdit::Password);
    passw_le_ -> setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    passw_conf_le_ = new QLineEdit(this);
    passw_conf_le_ -> setEchoMode(QLineEdit::Password);
    passw_conf_le_ -> setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);

    role_box_ = new QComboBox(this);
    role_box_ -> addItem("Enrolee");
    role_box_ -> addItem("Commission officer");
    role_box_ -> addItem("Commission head");

    gl_ = new QGridLayout(this);

    gl_ -> addWidget(new QLabel("Your username", this), 0, 0);
    gl_ -> addWidget(new QLabel("Your password", this), 1, 0);
    gl_ -> addWidget(new QLabel("Confirm password", this), 2, 0);
    gl_ -> addWidget(new QLabel("Choose your role", this), 3, 0);

    gl_ -> addWidget(login_le_, 0, 1);
    gl_ -> addWidget(passw_le_, 1, 1);
    gl_ -> addWidget(passw_conf_le_, 2, 1);
    gl_ -> addWidget(role_box_, 3, 1);

    QHBoxLayout* hbl = new QHBoxLayout(this);
    hbl -> addWidget(cancel_button_);
    hbl -> addWidget(register_button_);

    gl_ -> addLayout(hbl, 4, 1);

    db_handler_ = new DbManeger(this);
    connectToDb();

    connect(register_button_, SIGNAL(clicked()), this, SLOT(registerUser()));
    connect(cancel_button_, SIGNAL(clicked()), this, SLOT(close()));

}

void RegisterWidget::connectToDb()
{
    db_handler_-> connect("127.0.0.1:3306", "loginadmin", "000000");
}

void RegisterWidget::registerUser()
{
    if (passw_le_->text() != passw_conf_le_->text()) {
        std::cerr << "[ ERR ] passwords are not equal " << passw_le_ -> text().toStdString() << " neq " << passw_conf_le_ -> text().toStdString() << "\n";
        return;
    }

    switch (role_box_ -> currentIndex()) {
        case 0 :
        {
            db_handler_ -> callToDb("call mydb.create_enrollee_user('" + login_le_ -> text().toStdString() + "', '" + passw_le_ -> text().toStdString() + "')");
            break;
        }

        case 1 :
        {
            db_handler_ -> callToDb("call mydb.create_officer_user('" + login_le_ -> text().toStdString() + "', '" + passw_le_ -> text().toStdString() + "')");
            break;
        }

        case 2 :
        {
            db_handler_ -> callToDb("call mydb.create_head_user('" + login_le_ -> text().toStdString() + "', '" + passw_le_ -> text().toStdString() + "')");
            break;
        }

        default :
        {
            std::cerr << "[ ERR ] Unknown error\n";
            return;
        }

        std::clog << "[ OK ] User " << login_le_->text().toStdString() << " registered" << "\n";
    }

    close();
}

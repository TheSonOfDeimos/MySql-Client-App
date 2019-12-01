#include "loginwidget.h"

LoginWidget::LoginWidget(QWidget* parent)
    : QWidget(parent)
{
    grid_layout_ = new QGridLayout(this);
    setLayout(grid_layout_);

    host_line_edit_ = new QLineEdit(this);
    user_line_edit_ = new QLineEdit(this);
    password_line_edit_ = new QLineEdit(this);
    password_line_edit_ -> setEchoMode(QLineEdit::Password);
    password_line_edit_ -> setInputMethodHints(Qt::ImhHiddenText| Qt::ImhNoPredictiveText|Qt::ImhNoAutoUppercase);
    db_name_line_edit_ = new QLineEdit(this);
    button_connect_ = new QPushButton("Connect", this);
    button_register_ = new QPushButton("Register", this);

    grid_layout_->addWidget(host_line_edit_, 0, 1);
    grid_layout_->addWidget(user_line_edit_, 1, 1);
    grid_layout_->addWidget(password_line_edit_, 2, 1);
    grid_layout_->addWidget(db_name_line_edit_, 3, 1);

    QHBoxLayout* hbl = new QHBoxLayout(this);
    hbl -> addWidget(button_connect_);
    hbl -> addWidget(button_register_);
    grid_layout_->addLayout(hbl, 4, 1);


    grid_layout_->addWidget(new QLabel("Host", this), 0, 0);
    grid_layout_->addWidget(new QLabel("Username", this), 1, 0);
    grid_layout_->addWidget(new QLabel("Password", this), 2, 0);
    grid_layout_->addWidget(new QLabel("Data base name", this), 3, 0);

    connect(button_connect_, SIGNAL(clicked()), this, SLOT(connectToDb()));
    connect(button_register_, SIGNAL(clicked()), this, SLOT(showRegisterUser()));
}

void LoginWidget::setDbHandler(DbManeger *handl)
{
    db_handler_ = handl;
}

std::string LoginWidget::getHost()
{
    return host_line_edit_ -> text().toStdString();
}

std::string LoginWidget::getUser()
{
    return user_line_edit_ -> text().toStdString();
}

std::string LoginWidget::getPassword()
{
    return password_line_edit_ -> text().toStdString();
}

std::string LoginWidget::getDbName()
{
    return db_name_line_edit_ -> text().toStdString();
}

void LoginWidget::connectToDb()
{
    db_handler_-> connect(getHost(), getUser(), getPassword());
    db_handler_ -> setShema(getDbName());
    //db_handler_ -> checkGrants();
    emit connected_signal();

}

void LoginWidget::showRegisterUser()
{
    register_dlg_ = new RegisterWidget(nullptr);
    register_dlg_ -> show();
}

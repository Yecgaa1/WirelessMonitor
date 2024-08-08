//
// Created by xtx on 2023/11/27.
//

// You may need to build the project (run Qt uic code generator) to get "ui_IICDeviceEach.h" resolved

#include "IICDeviceEach.h"

#include "CH339Control.h"
#include "ui_IICDeviceEach.h"

IICDeviceEach::IICDeviceEach(QWidget *parent) : RepeaterWidget(parent), ui_(new Ui::IICDeviceEach) {
    ui_->setupUi(this);

    ui_->LRSplitter->setStretchFactor(0, 1);
    ui_->LRSplitter->setStretchFactor(1, 3);

    ui_->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui_->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //新建消息提示栏
    // sInfoBar = new FluShortInfoBar(FluShortInfoBarType::Info, window());
    // sInfoBar->setFixedWidth(270);

    python_work_ = new PythonWorkWithI2C();
    //test
    connect(ui_->ConfigAutoScan, &QPushButton::clicked, this, [&] {
        qDebug() << python_work_->ReciveDataFromI2C("3B", "FB92FFD01E3E");
        qDebug() << python_work_->ReciveDataFromI2C("43", "07DF0AC0F512");
        // sInfoBar->showInfoBarWithText("Hello");
    });

    EnumDevice();
    connect(ui_->ConnectCH, &QPushButton::clicked, this, &IICDeviceEach::OpenDevice);

    connect(ui_->ADDR_W, &QLineEdit::textChanged, this, [&](const QString &text) {
        //ui_->ADDR_W的值为转换为char存储
        ui_->ADDR_W->setText(text.toUpper());
        if (text.toUInt(nullptr, 16) > 15) {
            ADDR_W = text.toUInt(nullptr, 16);

            if (ui_->isRW1->isChecked()) {
                //读地址为写地址+1
                ADDR_R = ADDR_W + 1;
                ui_->ADDR_R->setText(QString::number(ADDR_W + 1, 16).toUpper());
            }
        }
    });
    connect(ui_->applyI2C, &QPushButton::clicked, this, &IICDeviceEach::CH347InitI2C);

    connect(ui_->ADDR_R, &QLineEdit::textChanged, this, [&](const QString &text) {
        ADDR_R = text.toUInt(nullptr, 16);
    });
    // connect(ui_->)
}

IICDeviceEach::~IICDeviceEach() {
    delete ui_;
}
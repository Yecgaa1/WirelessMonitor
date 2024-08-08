//
// Created by xtx on 2023/11/27.
//

#ifndef WIRELESSMONITOR_COMPONENTS_IICDEVICEBASIC_IICDEVICEEACH_H_
#define WIRELESSMONITOR_COMPONENTS_IICDEVICEBASIC_IICDEVICEEACH_H_

#include <FluShortInfoBar.h>

#include "RepeaterWidget.h"
#include "PythonWorkWithI2C.h"
#include "atlmem.h"
#include "ui_IICDeviceEach.h"
QT_BEGIN_NAMESPACE

namespace Ui {
class IICDeviceEach;
}

QT_END_NAMESPACE
class PythonWork;
class IICDeviceEach : public RepeaterWidget {
        Q_OBJECT

    public:
        explicit IICDeviceEach(QWidget *parent = nullptr);
        ~IICDeviceEach() override;
        Ui::IICDeviceEach *ui_;
        ULONG EnumDevice();
        BOOL OpenDevice();
        BOOL CloseDevice();
        uint8_t ADDR_W;
        uint8_t ADDR_R;

        FluShortInfoBar *sInfoBar;

        BOOL CH347InitI2C();

        BOOL CH347WriteI2C(uint8_t Addr, uint8_t DataAddr, uint8_t *Data, uint8_t DataLen);
        BOOL CH347ReadI2C(uint8_t DeviceReadAddr, uint8_t DataAddr, uint8_t *Data, uint8_t DataLen,bool hasDataAddr=true);

        void Loadxlsx();
    private:
        PythonWork *python_work_;
};

#endif //WIRELESSMONITOR_COMPONENTS_IICDEVICEBASIC_IICDEVICEEACH_H_

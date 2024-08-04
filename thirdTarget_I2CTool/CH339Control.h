//
// Created by xtx on 24-8-3.
//

#ifndef CH339CONTROL_H
#define CH339CONTROL_H

#include "atlmem.h"
#include "IICDeviceEach.h"
#include "CH347DLL.H"


typedef struct _USB_DEVICE_DESCRIPTOR {
    UCHAR bLength;
    UCHAR bDescriptorType;
    USHORT bcdUSB;
    UCHAR bDeviceClass;
    UCHAR bDeviceSubClass;
    UCHAR bDeviceProtocol;
    UCHAR bMaxPacketSize0;
    USHORT idVendor;
    USHORT idProduct;
    USHORT bcdDevice;
    UCHAR iManufacturer;
    UCHAR iProduct;
    UCHAR iSerialNumber;
    UCHAR bNumConfigurations;
} USB_DEVICE_DESCRIPTOR, *PUSB_DEVICE_DESCRIPTOR;
#pragma pack()

class CH339Control {
    public:
        explicit CH339Control(IICDeviceEach *ui) {
            ui_=ui;
        }
        static ULONG EnumDevice();
    private:
        IICDeviceEach *ui_;
};

#endif //CH339CONTROL_H

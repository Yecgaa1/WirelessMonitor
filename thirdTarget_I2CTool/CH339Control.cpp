//
// Created by xtx on 24-8-3.
//

#include "CH339Control.h"

#include <iostream>

//枚举设备
ULONG CH339Control::EnumDevice()
{
    ULONG i,oLen,DevCnt = 0;
    USB_DEVICE_DESCRIPTOR DevDesc = {0};
    CHAR tem[256] = "";
    mDeviceInforS DevInfor = {0};

    // SendDlgItemMessage(SpiI2cGpioDebugHwnd,IDC_ObjList,CB_RESETCONTENT,0,0);
    for(i=0;i<16;i++)
    {
        if(CH347OpenDevice(i) != INVALID_HANDLE_VALUE)
        {
            oLen = sizeof(USB_DEVICE_DESCRIPTOR);
            CH347GetDeviceInfor(i,&DevInfor);

            if(DevInfor.ChipMode == 3) //模式3此接口为JTAG/I2C
                continue;

            std::cout<<(tem,"%d# %s",i,DevInfor.FuncDescStr);
            // SendDlgItemMessage(SpiI2cGpioDebugHwnd,IDC_ObjList,CB_ADDSTRING,0,(LPARAM)(LPCTSTR)tem);
            // memcpy(&SpiI2cDevInfor[DevCnt],&DevInfor,sizeof(DevInfor));
            DevCnt++;
        }
        CH347CloseDevice(i);
    }
    if(DevCnt)
    {
        // SendDlgItemMessage(SpiI2cGpioDebugHwnd,IDC_ObjList,CB_SETCURSEL,0,0);
        // SetFocus(GetDlgItem(SpiI2cGpioDebugHwnd,IDC_ObjList));
    }
    return DevCnt;
}
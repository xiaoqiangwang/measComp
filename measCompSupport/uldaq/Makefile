TOP=..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

LIBRARY_IOC = uldaq

ULDAQ = $(TOP)/uldaq

USR_CXXFLAGS += -I/opt/local/include

INC += uldaq.h
uldaq_SRCS += AiDevice.cpp
uldaq_SRCS += IoDevice.cpp
uldaq_SRCS += DevMemInfo.cpp
uldaq_SRCS += UlException.cpp
uldaq_SRCS += AoDevice.cpp
uldaq_SRCS += AoInfo.cpp
uldaq_SRCS += CtrInfo.cpp
uldaq_SRCS += TmrDevice.cpp
uldaq_SRCS += CtrConfig.cpp
uldaq_SRCS += DaqEventHandler.cpp
uldaq_SRCS += DaqDeviceManager.cpp
uldaq_SRCS += DaqOInfo.cpp
uldaq_SRCS += DaqDevice.cpp
uldaq_SRCS += AiChanInfo.cpp
uldaq_SRCS += DioDevice.cpp
uldaq_SRCS += DaqODevice.cpp
uldaq_SRCS += DioInfo.cpp
uldaq_SRCS += AiInfo.cpp
uldaq_SRCS += CtrDevice.cpp
uldaq_SRCS += TmrInfo.cpp
uldaq_SRCS += DioPortInfo.cpp
uldaq_SRCS += DaqIDevice.cpp
uldaq_SRCS += DioConfig.cpp
uldaq_SRCS += AiConfig.cpp
uldaq_SRCS += DaqIInfo.cpp
uldaq_SRCS += ulc.cpp
uldaq_SRCS += UlDaqDeviceManager.cpp
uldaq_SRCS += AoConfig.cpp
uldaq_SRCS += main.cpp
uldaq_SRCS += DaqDeviceInfo.cpp
uldaq_SRCS += DaqDeviceConfig.cpp

SRC_DIRS += ${ULDAQ}/interfaces


SRC_DIRS += ${ULDAQ}/usb
uldaq_SRCS += Usb1208hs.cpp
uldaq_SRCS += UsbIotech.cpp
uldaq_SRCS += Usb1608g.cpp
uldaq_SRCS += UsbCtrx.cpp
uldaq_SRCS += UsbScanTransferIn.cpp
uldaq_SRCS += Usb9837x.cpp
uldaq_SRCS += UsbDio32hs.cpp
uldaq_SRCS += UsbEndpoint.cpp
uldaq_SRCS += Usb1608fsPlus.cpp
uldaq_SRCS += UsbScanTransferOut.cpp
uldaq_SRCS += UsbDaqDevice.cpp
uldaq_SRCS += UsbQuad08.cpp
uldaq_SRCS += Usb20x.cpp
uldaq_SRCS += Usb1808.cpp
uldaq_SRCS += UsbDtDevice.cpp
uldaq_SRCS += Usb26xx.cpp
uldaq_SRCS += Usb1208fsPlus.cpp
uldaq_SRCS += UsbFpgaDevice.cpp

SRC_DIRS += ${ULDAQ}/usb/ctr
uldaq_SRCS += CtrUsb9837x.cpp
uldaq_SRCS += CtrUsbQuad08.cpp
uldaq_SRCS += CtrUsbCtrx.cpp
uldaq_SRCS += CtrUsb1808.cpp
uldaq_SRCS += CtrUsb1208hs.cpp
uldaq_SRCS += CtrUsbBase.cpp
uldaq_SRCS += CtrHidBase.cpp
uldaq_SRCS += CtrUsbDio24.cpp
uldaq_SRCS += CtrHid.cpp

SRC_DIRS += ${ULDAQ}/usb/daqi
uldaq_SRCS += DaqIUsbCtrx.cpp
uldaq_SRCS += DaqIUsbBase.cpp
uldaq_SRCS += DaqIUsb9837x.cpp
uldaq_SRCS += DaqIUsb1808.cpp

SRC_DIRS += ${ULDAQ}/usb/fw
uldaq_SRCS += DtFx2FwLoader.cpp
uldaq_SRCS += Fx2FwLoader.cpp

SRC_DIRS += ${ULDAQ}/usb/daqo
uldaq_SRCS += DaqOUsb1808.cpp
uldaq_SRCS += DaqOUsbBase.cpp

SRC_DIRS += ${ULDAQ}/usb/tmr
uldaq_SRCS += TmrUsbBase.cpp
uldaq_SRCS += TmrUsbQuad08.cpp
uldaq_SRCS += TmrUsb1808.cpp
uldaq_SRCS += TmrUsb1208hs.cpp

SRC_DIRS += ${ULDAQ}/usb/ai
uldaq_SRCS += AiUsb1208hs.cpp
uldaq_SRCS += AiUsb1608g.cpp
uldaq_SRCS += AiUsb9837x.cpp
uldaq_SRCS += AiUsb1208fsPlus.cpp
uldaq_SRCS += AiUsbBase.cpp
uldaq_SRCS += AiUsb20x.cpp
uldaq_SRCS += AiUsb1808.cpp
uldaq_SRCS += AiUsb26xx.cpp
uldaq_SRCS += AiUsb1608fsPlus.cpp

SRC_DIRS += ${ULDAQ}/usb/ao
uldaq_SRCS += AoUsb9837x.cpp
uldaq_SRCS += AoUsb26xx.cpp
uldaq_SRCS += AoUsb1208hs.cpp
uldaq_SRCS += AoUsb1808.cpp
uldaq_SRCS += AoUsbBase.cpp
uldaq_SRCS += AoUsb1608g.cpp
uldaq_SRCS += AoUsb1208fsPlus.cpp
uldaq_SRCS += AoUsb20x.cpp

SRC_DIRS += ${ULDAQ}/usb/dio
uldaq_SRCS += DioUsbQuad08.cpp
uldaq_SRCS += DioUsb1208fsPlus.cpp
uldaq_SRCS += UsbDOutScan.cpp
uldaq_SRCS += DioUsbCtrx.cpp
uldaq_SRCS += DioUsb1608g.cpp
uldaq_SRCS += DioUsb1808.cpp
uldaq_SRCS += DioUsb1208hs.cpp
uldaq_SRCS += DioUsb26xx.cpp
uldaq_SRCS += UsbDInScan.cpp
uldaq_SRCS += DioUsbBase.cpp
uldaq_SRCS += DioUsbDio32hs.cpp

SRC_DIRS += ${ULDAQ}/hid
uldaq_SRCS += UsbDio24.cpp
uldaq_SRCS += hid_mac.cpp
uldaq_SRCS += UsbSsrxx.cpp
uldaq_SRCS += hid_linux.cpp
uldaq_SRCS += UsbPdiso8.cpp
uldaq_SRCS += UsbTempAi.cpp
uldaq_SRCS += UsbErbxx.cpp
uldaq_SRCS += Usb3100.cpp
uldaq_SRCS += UsbTemp.cpp
uldaq_SRCS += HidDaqDevice.cpp
uldaq_SRCS += UsbDio96h.cpp

SRC_DIRS += ${ULDAQ}/hid/ai
uldaq_SRCS += AiHidBase.cpp
uldaq_SRCS += AiUsbTempAi.cpp
uldaq_SRCS += AiUsbTemp.cpp

SRC_DIRS += ${ULDAQ}/hid/ao
uldaq_SRCS += AoUsb3100.cpp
uldaq_SRCS += AoHidBase.cpp

SRC_DIRS += ${ULDAQ}/hid/dio
uldaq_SRCS += DioUsbErbxx.cpp
uldaq_SRCS += DioHidAux.cpp
uldaq_SRCS += DioUsbDio24.cpp
uldaq_SRCS += DioHidBase.cpp
uldaq_SRCS += DioUsbSsrxx.cpp
uldaq_SRCS += DioUsbDio96h.cpp
uldaq_SRCS += DioUsbPdiso8.cpp

SRC_DIRS += ${ULDAQ}/utility
uldaq_SRCS += FnLog.cpp
uldaq_SRCS += ErrorMap.cpp
uldaq_SRCS += EuScale.cpp
uldaq_SRCS += Endian.cpp
uldaq_SRCS += UlLock.cpp
uldaq_SRCS += SuspendMonitor.cpp
uldaq_SRCS += Nist.cpp
uldaq_SRCS += ThreadEvent.cpp
#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

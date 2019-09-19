#include <stdio.h>
#include <vector>

namespace uldaq {
#include "uldaq.h"
}

#include "cbw_linux.h"

// Range conversion table cbw -> uldaq
uldaq::Range cbw_uldaq_range(int range)
{
    switch(range) {
    case BIP20VOLTS: return uldaq::Range(4);
    case BIP10VOLTS: return uldaq::Range(5);
    case BIP5VOLTS: return uldaq::Range(6);
    case BIP4VOLTS: return uldaq::Range(7);
    case BIP2PT5VOLTS: return uldaq::Range(8);
    case BIP2VOLTS: return uldaq::Range(9);
    case BIP1PT25VOLTS: return uldaq::Range(10);
    case BIP1VOLTS: return uldaq::Range(11);
    case BIPPT625VOLTS: return uldaq::Range(12);
    case BIPPT312VOLTS: return uldaq::Range(23);
    case BIPPT156VOLTS: return uldaq::Range(24);
    case BIPPT078VOLTS: return uldaq::Range(18);
    }
}

// System functions

int cbAddBoard(const char *boardName, const char *address)
{
    return NOERRORS;
}

int cbGetConfig(int InfoType, int BoardNum, int DevNum,
                int ConfigItem, int *ConfigVal)
{
    uldaq::DaqDeviceDescriptor deviceDesc;
    long long infoValue;
    uldaq::UlError status = uldaq::ERR_NO_ERROR;

    switch (InfoType) {
    case BOARDINFO:
        switch (ConfigItem) {
        case BIBOARDTYPE:
            status = uldaq::ulGetDaqDeviceDescriptor(BoardNum, &deviceDesc);
            *ConfigVal = deviceDesc.productId;
        break;
        case BINUMADCHANS:
            status = uldaq::ulAIGetInfo(BoardNum, uldaq::AI_INFO_NUM_CHANS, 0, &infoValue);
            *ConfigVal = infoValue;
        break;
        case BINUMDACHANS:
            status = uldaq::ulAOGetInfo(BoardNum, uldaq::AO_INFO_NUM_CHANS, 0, &infoValue);
            *ConfigVal = infoValue;
        break;
        case BIADRES:
            status = uldaq::ulAIGetInfo(BoardNum, uldaq::AI_INFO_RESOLUTION, 0, &infoValue);
            *ConfigVal = infoValue;
         break;
        case BIDACRES:
            status = uldaq::ulAOGetInfo(BoardNum, uldaq::AO_INFO_RESOLUTION, 0, &infoValue);
            *ConfigVal = infoValue;
        break;
        case BIDINUMDEVS:
            status = uldaq::ulDIOGetInfo(BoardNum, uldaq::DIO_INFO_NUM_PORTS, 0, &infoValue);
            *ConfigVal = infoValue;
        break;
        case BINUMTEMPCHANS:
            status = uldaq::ulAIGetInfo(BoardNum, uldaq::AI_INFO_NUM_CHANS_BY_TYPE, uldaq::AI_TC, &infoValue);
            *ConfigVal = infoValue;
        break;
        }
    break;
    case  DIGITALINFO:
        switch (ConfigItem) {
        case DIDEVTYPE:
           status = uldaq::ulDIOGetInfo(BoardNum, uldaq::DIO_INFO_PORT_TYPE, DevNum, &infoValue);
            *ConfigVal = infoValue;
        break;
        case DIINMASK:
            status = uldaq::ulDIOGetConfig(BoardNum, uldaq::DIO_CFG_PORT_DIRECTION_MASK, DevNum, &infoValue);
            *ConfigVal = ~infoValue;
        break;
        case DIOUTMASK:
            status = uldaq::ulDIOGetConfig(BoardNum, uldaq::DIO_CFG_PORT_DIRECTION_MASK, DevNum, &infoValue);
            *ConfigVal = infoValue;
        break;
        case DINUMBITS:
            status = uldaq::ulDIOGetInfo(BoardNum, uldaq::DIO_INFO_NUM_BITS, DevNum, &infoValue);
            *ConfigVal = infoValue;
        break;
        }
    break;
    }

    return status;
}

int cbSetConfig(int InfoType, int BoardNum, int DevNum, int ConfigItem, int ConfigVal)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;

    switch (InfoType) {
    case BOARDINFO:
        switch (ConfigItem) {
        case BIADCHANTYPE:
            switch (ConfigVal) {
            case AI_CHAN_TYPE_VOLTAGE:
            status = uldaq::ulAISetConfig(BoardNum, uldaq::AI_CFG_CHAN_TYPE, 0, uldaq::AI_VOLTAGE);
            break;
            case AI_CHAN_TYPE_TC:
            status = uldaq::ulAISetConfig(BoardNum, uldaq::AI_CFG_CHAN_TYPE, 0, uldaq::AI_TC);
            break;
            }
        break;
        case BICHANTCTYPE:
            status = uldaq::ulAISetConfig(BoardNum, uldaq::AI_CFG_CHAN_TC_TYPE, 0, ConfigVal);
        break;
        case BIADTRIGCOUNT:

        break;
        case BIDACTRIGCOUNT:

        break;
        }
    break;
    }

    return status;
 }

int cbGetBoardName(int BoardNum, char *BoardName)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;

    uldaq::DaqDeviceDescriptor deviceDesc;
    status = uldaq::ulGetDaqDeviceDescriptor(BoardNum, &deviceDesc);
    strcpy(BoardName, deviceDesc.productName);
    
    return status;
}

int cbGetErrMsg(int ErrCode, char *ErrMsg)
{
    return uldaq::ulGetErrMsg(uldaq::UlError(ErrCode), ErrMsg);
}

int cbSetAsynUser(int BoardNum, asynUser *pasynUser)
{
    return uldaq::ERR_NO_ERROR;
}

HGLOBAL cbWinBufAlloc(long NumPoints)
{
    return calloc(NumPoints, sizeof(short));
}

HGLOBAL cbScaledWinBufAlloc(long NumPoints)
{
    return calloc(NumPoints, sizeof(double));
}

HGLOBAL cbWinBufAlloc32(long NumPoints)
{
    return calloc(NumPoints, sizeof(int));
}

int cbStopIOBackground(int BoardNum, int FunctionType)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;

    switch(FunctionType) {
    case AIFUNCTION:
        status = uldaq::ulAInScanStop(BoardNum);
    break;
    case AOFUNCTION:
        status = uldaq::ulAOutScanStop(BoardNum);
    break;
    }

    return status;
}

int cbGetIOStatus(int BoardNum, short *Status, long *CurCount, long *CurIndex,int FunctionType)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    uldaq::ScanStatus scanStatus;
    uldaq::TransferStatus xferStatus;

    switch(FunctionType) {
    case AIFUNCTION:
        status = uldaq::ulAInScanStatus(BoardNum, &scanStatus, &xferStatus);
        *Status = scanStatus;
        *CurCount = xferStatus.currentScanCount;
        *CurIndex = xferStatus.currentIndex;
    break;
    case AOFUNCTION:
        status = uldaq::ulAOutScanStatus(BoardNum, &scanStatus, &xferStatus);
        *Status = scanStatus;
        *CurCount = xferStatus.currentScanCount;
        *CurIndex = xferStatus.currentIndex;
    break;
    }

    return status;
}

      
int cbAIn(int BoardNum, int Chan, int Gain, USHORT *DataValue)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    uldaq::AInFlag flags = uldaq::AInFlag(uldaq::AIN_FF_NOSCALEDATA|uldaq::AIN_FF_NOCALIBRATEDATA);
    double data = 0;
    status = ulAIn(BoardNum, Chan,
            uldaq::AI_DIFFERENTIAL,
            cbw_uldaq_range(Gain),
            flags, &data);
    *DataValue = data;

    return status;
}

int cbAIn32(int BoardNum, int Chan, int Gain, ULONG *DataValue, int Options)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    uldaq::AInFlag flags = uldaq::AInFlag(uldaq::AIN_FF_NOSCALEDATA|uldaq::AIN_FF_NOCALIBRATEDATA);
    double data = 0;
    status = ulAIn(BoardNum, Chan,
            uldaq::AI_DIFFERENTIAL,
            cbw_uldaq_range(Gain),
            flags, &data);
    *DataValue = data;

    return status;
}

int cbAInScan(int BoardNum, int LowChan, int HighChan, long Count,
              long *Rate, int Gain, HGLOBAL MemHandle, int Options)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    ULONG flags = uldaq::AINSCAN_FF_NOCALIBRATEDATA;
    ULONG options = 0;
    double rate = 0;

    if (!(Options & SCALEDATA))
        flags |= uldaq::AINSCAN_FF_NOSCALEDATA;

    if (Options & EXTTRIGGER)
        options |= uldaq::SO_EXTTRIGGER;
    if (Options & EXTCLOCK)
        options |= uldaq::SO_EXTCLOCK;
    if (Options & CONTINUOUS)
        options |= uldaq::SO_CONTINUOUS;
    if (Options & RETRIGMODE)
        options |= uldaq::SO_RETRIGGER;
    if (Options & BURSTMODE)
        options |= uldaq::SO_BURSTMODE;

    status = ulAInScan(BoardNum, LowChan, HighChan,
            uldaq::AI_DIFFERENTIAL, cbw_uldaq_range(Gain), Count, &rate,
            uldaq::ScanOption(options), uldaq::AInScanFlag(flags),
            (double *)MemHandle);

    *Rate = rate;

    return status;
}

int cbALoadQueue(int BoardNum, short *ChanArray, short *GainArray, int NumChans)
{
    uldaq::AiQueueElement *queue = (uldaq::AiQueueElement*)calloc(NumChans, sizeof(uldaq::AiQueueElement));
    for (int i=0; i<NumChans; i++) {
        queue[i].inputMode = uldaq::AI_DIFFERENTIAL;
        queue[i].channel = ChanArray[i];
        queue[i].range = cbw_uldaq_range(GainArray[i]);
    }

    return ulAInLoadQueue(BoardNum, queue, NumChans);
}

int cbAOut(int BoardNum, int Chan, int Gain, USHORT DataValue)
{
    uldaq::AOutFlag flags = uldaq::AOutFlag(uldaq::AIN_FF_NOSCALEDATA|uldaq::AIN_FF_NOCALIBRATEDATA);
    return ulAOut(BoardNum, Chan,
            cbw_uldaq_range(Gain),
            flags, DataValue);
}

int cbAOutScan(int BoardNum, int LowChan, int HighChan,
               long Count, long *Rate, int Gain,
               HGLOBAL MemHandle, int Options)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    ULONG flags = uldaq::AINSCAN_FF_NOCALIBRATEDATA|uldaq::AINSCAN_FF_NOSCALEDATA;
    ULONG options = 0;
    double rate = 0;
    double *data = (double *)calloc(Count*(HighChan-LowChan+1), sizeof(double));

    // Copy out data
    for(int i=0; i<Count*(HighChan-LowChan+1); i++) {
        data[i] = ((USHORT *)MemHandle)[i];
    }

    if (Options & EXTTRIGGER)
        options |= uldaq::SO_EXTTRIGGER;
    if (Options & EXTCLOCK)
        options |= uldaq::SO_EXTCLOCK;
    if (Options & CONTINUOUS)
        options |= uldaq::SO_CONTINUOUS;
    if (Options & RETRIGMODE)
        options |= uldaq::SO_RETRIGGER;

    status = ulAOutScan(BoardNum, LowChan, HighChan,
            cbw_uldaq_range(Gain), Count, &rate,
            uldaq::ScanOption(options), uldaq::AOutScanFlag(flags),
            data);

    *Rate = rate;
    free(data);
    return status;
}


// Counter functions
int cbC9513Config(int BoardNum, int CounterNum, int GateControl,
                  int CounterEdge, int CountSource,
                  int SpecialGate, int Reload, int RecycleMode,
                  int BCDMode, int CountDirection,
                  int OutputControl)
{
    return uldaq::ERR_NO_ERROR;
}

int cbC9513Init(int BoardNum, int ChipNum, int FOutDivider,
                int FOutSource, int Compare1, int Compare2,
                int TimeOfDay)
{
    return uldaq::ERR_NO_ERROR;
}

int cbCIn32(int BoardNum, int CounterNum, ULONG *Count)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    unsigned long long data = 0;

    status = uldaq::ulCIn(BoardNum, CounterNum, &data);
    *Count = data;

    return status;
}

int cbCLoad32(int BoardNum, int RegNum, ULONG LoadValue)
{
    return uldaq::ulCLoad(BoardNum, RegNum, uldaq::CRT_COUNT, LoadValue);
}

int cbCInScan(int BoardNum, int FirstCtr,int LastCtr, LONG Count,
              LONG *Rate, HGLOBAL MemHandle, ULONG Options)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    double rate = 0;
    unsigned long long *data = (unsigned long long *)calloc(Count*(LastCtr-FirstCtr+1), sizeof(unsigned long long));

    ULONG options = 0;
    ULONG flags = 0;

    if (Options & CTR16BIT)
        flags |= uldaq::CINSCAN_FF_CTR16_BIT;
    else if (Options & CTR32BIT)
        flags |= uldaq::CINSCAN_FF_CTR32_BIT;

    if (Options & NOCLEAR)
        flags |= uldaq::CINSCAN_FF_NOCLEAR;

    if (Options & SINGLEIO)
        options |= uldaq::SO_SINGLEIO;
    if (Options & EXTTRIGGER)
        options |= uldaq::SO_EXTTRIGGER;
    if (Options & EXTCLOCK)
        options |= uldaq::SO_EXTCLOCK;

    uldaq::ulCInScan(BoardNum, FirstCtr, LastCtr, Count,
            &rate, uldaq::ScanOption(options), uldaq::CInScanFlag(flags),
            data);
    *Rate = rate;

    // Copy back data
    if (Options & CTR16BIT) {
        USHORT *p16 = (USHORT *)MemHandle;
        for (int i=0; i<Count*(LastCtr-FirstCtr+1); i++)
            p16[i] = data[i];
    } else if (Options & CTR32BIT) {
        ULONG *p32 = (ULONG *)MemHandle;
        for (int i=0; i<Count*(LastCtr-FirstCtr+1); i++)
            p32[i] = data[i];
    }

    free(data);
    return status;
}

int cbCConfigScan(int BoardNum, int CounterNum, int Mode,int DebounceTime,
                  int DebounceMode, int EdgeDetection,
                  int TickSize, int MappedChannel)
{
    ULONG type = 0;
    ULONG mode = 0;
    uldaq::CounterDebounceMode debounceMode = uldaq::CDM_NONE;
    uldaq::CounterDebounceTime debounceTime = uldaq::CDT_DEBOUNCE_0ns;

    ULONG tick = TickSize + 1;
    uldaq::CounterEdgeDetection edge = uldaq::CED_RISING_EDGE;

    if (EdgeDetection == CTR_FALLING_EDGE)
        edge = uldaq::CED_FALLING_EDGE;

    if (DebounceMode == CTR_TRIGGER_AFTER_STABLE)
        debounceMode = uldaq::CDM_TRIGGER_AFTER_STABLE;
    else if (DebounceMode == CTR_TRIGGER_BEFORE_STABLE)
        debounceMode = uldaq::CDM_TRIGGER_BEFORE_STABLE;

    if (DebounceTime < CTR_DEBOUNCE_NONE)
        debounceTime = uldaq::CounterDebounceTime(DebounceTime + 1);
    else
        debounceMode = uldaq::CDM_NONE;

    if (Mode & CLEAR_ON_READ)
        mode |= uldaq::CMM_CLEAR_ON_READ;
    if (Mode & OUTPUT_ON)
        mode |= uldaq::CMM_OUTPUT_ON;
    if (Mode & COUNT_DOWN_ON)
        mode |= uldaq::CMM_COUNT_DOWN;
    if (Mode & DECREMENT_ON)
        mode |= uldaq::CMM_DECREMENT_ON;

    return ulCConfigScan(BoardNum, CounterNum, 
            uldaq::CounterMeasurementType(type),
            uldaq::CounterMeasurementMode(mode),
            edge,
            uldaq::CounterTickSize(tick),
            debounceMode, debounceTime,
            uldaq::CF_DEFAULT);
}


// Digital I/O functions
int cbDBitOut(int BoardNum, int PortType, int BitNum, USHORT BitValue)
{
    return ulDBitOut(BoardNum, uldaq::DigitalPortType(PortType), BitNum, BitValue);
}

int cbDConfigPort(int BoardNum, int PortType, int Direction)
{
    uldaq::DigitalDirection direction = uldaq::DD_INPUT;
    if (Direction == DIGITALOUT)
        direction = uldaq::DD_OUTPUT;

    return ulDConfigPort(BoardNum, uldaq::DigitalPortType(PortType), direction);
}

int cbDConfigBit(int BoardNum, int PortType, int BitNum, int Direction)
{
    uldaq::DigitalDirection direction = uldaq::DD_INPUT;
    if (Direction == DIGITALOUT)
        direction = uldaq::DD_OUTPUT;

    return ulDConfigBit(BoardNum, uldaq::DigitalPortType(PortType), BitNum, direction);
}

int cbDIn(int BoardNum, int PortType, USHORT *DataValue)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    unsigned long long data = 0;

    status = ulDIn(BoardNum, uldaq::DigitalPortType(PortType), &data);
    *DataValue = data;

    return status;
}

int cbDIn32(int BoardNum, int PortType, UINT *DataValue)
{
    uldaq::UlError status = uldaq::ERR_NO_ERROR;
    unsigned long long data = 0;

    status = ulDIn(BoardNum, uldaq::DigitalPortType(PortType), &data);
    *DataValue = data;

    return status;
}

int cbDOut(int BoardNum, int PortType, USHORT DataValue)
{
    return ulDOut(BoardNum, uldaq::DigitalPortType(PortType), DataValue);
}

int cbDOut32(int BoardNum, int PortType, UINT DataValue)
{
    return ulDOut(BoardNum, uldaq::DigitalPortType(PortType), DataValue);
}

// Pulse functions
int cbPulseOutStart(int BoardNum, int TimerNum, double *Frequency, 
                    double *DutyCycle, unsigned int PulseCount, 
                    double *InitialDelay, int IdleState, int Options)
{
    uldaq::TmrIdleState idleState = uldaq::TMRIS_LOW;
    if (IdleState != 0)
        idleState = uldaq::TMRIS_HIGH;

    return uldaq::ulTmrPulseOutStart(BoardNum, TimerNum, Frequency,
            DutyCycle, PulseCount,
            InitialDelay, idleState, uldaq::PO_DEFAULT);
}

int cbPulseOutStop(int BoardNum, int TimerNum)
{
    return uldaq::ulTmrPulseOutStop(BoardNum, TimerNum);
}


// Temperature functions
int cbTIn(int BoardNum, int Chan, int Scale, float *TempValue, int Options)
{
    double temp = 0;
    uldaq::UlError status = uldaq::ulTIn(BoardNum, Chan, 
            uldaq::TempScale(Scale), uldaq::TIN_FF_DEFAULT, &temp);
    *TempValue = temp;
    return status;
}

// Trigger functions
int cbSetTrigger(int BoardNum, int TrigType, USHORT LowThreshold,
                 USHORT HighThreshold)
{
}

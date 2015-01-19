/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */

#include "s3eExt.h"
#include "IwDebug.h"
#include "s3eDevice.h"


#include "s3eHidController.h"


#ifndef S3E_EXT_SKIP_LOADER_CALL_LOCK
// For MIPs (and WP8) platform we do not have asm code for stack switching
// implemented. So we make LoaderCallStart call manually to set GlobalLock
#if defined __mips || defined S3E_ANDROID_X86 || (defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP))
#define LOADER_CALL_LOCK
#endif
#endif

/**
 * Definitions for functions types passed to/from s3eExt interface
 */
typedef       bool(*s3eHidControllerIsConnected_t)();
typedef       bool(*s3eHidControllerUpdate_t)();
typedef      float(*s3eHidControllerGetStick1XAxis_t)();
typedef      float(*s3eHidControllerGetStick1YAxis_t)();
typedef      float(*s3eHidControllerGetStick2XAxis_t)();
typedef      float(*s3eHidControllerGetStick2YAxis_t)();
typedef      float(*s3eHidControllerGetLeftTrigger_t)();
typedef      float(*s3eHidControllerGetRightTrigger_t)();
typedef       bool(*s3eHidControllerGetButtonX_t)();
typedef       bool(*s3eHidControllerGetButtonY_t)();
typedef       bool(*s3eHidControllerGetButtonA_t)();
typedef       bool(*s3eHidControllerGetButtonB_t)();
typedef       bool(*s3eHidControllerGetButtonDPadLeft_t)();
typedef       bool(*s3eHidControllerGetButtonDPadRight_t)();
typedef       bool(*s3eHidControllerGetButtonDPadUp_t)();
typedef       bool(*s3eHidControllerGetButtonDPadDown_t)();
typedef       bool(*s3eHidControllerGetButtonLShoulderDown_t)();
typedef       bool(*s3eHidControllerGetButtonRShoulderDown_t)();
typedef       bool(*s3eHidControllerGetButtonStart_t)();
typedef       bool(*s3eHidControllerGetButtonSelect_t)();
typedef       bool(*s3eHidControllerUpdateLegacy_t)(float dt);

/**
 * struct that gets filled in by s3eHidControllerRegister
 */
typedef struct s3eHidControllerFuncs
{
    s3eHidControllerIsConnected_t m_s3eHidControllerIsConnected;
    s3eHidControllerUpdate_t m_s3eHidControllerUpdate;
    s3eHidControllerGetStick1XAxis_t m_s3eHidControllerGetStick1XAxis;
    s3eHidControllerGetStick1YAxis_t m_s3eHidControllerGetStick1YAxis;
    s3eHidControllerGetStick2XAxis_t m_s3eHidControllerGetStick2XAxis;
    s3eHidControllerGetStick2YAxis_t m_s3eHidControllerGetStick2YAxis;
    s3eHidControllerGetLeftTrigger_t m_s3eHidControllerGetLeftTrigger;
    s3eHidControllerGetRightTrigger_t m_s3eHidControllerGetRightTrigger;
    s3eHidControllerGetButtonX_t m_s3eHidControllerGetButtonX;
    s3eHidControllerGetButtonY_t m_s3eHidControllerGetButtonY;
    s3eHidControllerGetButtonA_t m_s3eHidControllerGetButtonA;
    s3eHidControllerGetButtonB_t m_s3eHidControllerGetButtonB;
    s3eHidControllerGetButtonDPadLeft_t m_s3eHidControllerGetButtonDPadLeft;
    s3eHidControllerGetButtonDPadRight_t m_s3eHidControllerGetButtonDPadRight;
    s3eHidControllerGetButtonDPadUp_t m_s3eHidControllerGetButtonDPadUp;
    s3eHidControllerGetButtonDPadDown_t m_s3eHidControllerGetButtonDPadDown;
    s3eHidControllerGetButtonLShoulderDown_t m_s3eHidControllerGetButtonLShoulderDown;
    s3eHidControllerGetButtonRShoulderDown_t m_s3eHidControllerGetButtonRShoulderDown;
    s3eHidControllerGetButtonStart_t m_s3eHidControllerGetButtonStart;
    s3eHidControllerGetButtonSelect_t m_s3eHidControllerGetButtonSelect;
    s3eHidControllerUpdateLegacy_t m_s3eHidControllerUpdateLegacy;
} s3eHidControllerFuncs;

static s3eHidControllerFuncs g_Ext;
static bool g_GotExt = false;
static bool g_TriedExt = false;
static bool g_TriedNoMsgExt = false;

static bool _extLoad()
{
    if (!g_GotExt && !g_TriedExt)
    {
        s3eResult res = s3eExtGetHash(0x159afc69, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        else
            s3eDebugAssertShow(S3E_MESSAGE_CONTINUE_STOP_IGNORE,                 "error loading extension: s3eHidController");

        g_TriedExt = true;
        g_TriedNoMsgExt = true;
    }

    return g_GotExt;
}

static bool _extLoadNoMsg()
{
    if (!g_GotExt && !g_TriedNoMsgExt)
    {
        s3eResult res = s3eExtGetHash(0x159afc69, &g_Ext, sizeof(g_Ext));
        if (res == S3E_RESULT_SUCCESS)
            g_GotExt = true;
        g_TriedNoMsgExt = true;
        if (g_TriedExt)
            g_TriedExt = true;
    }

    return g_GotExt;
}

s3eBool s3eHidControllerAvailable()
{
    _extLoadNoMsg();
    return g_GotExt ? S3E_TRUE : S3E_FALSE;
}

bool s3eHidControllerIsConnected()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[0] func: s3eHidControllerIsConnected"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerIsConnected();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerUpdate()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[1] func: s3eHidControllerUpdate"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerUpdate();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

float s3eHidControllerGetStick1XAxis()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[2] func: s3eHidControllerGetStick1XAxis"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    float ret = g_Ext.m_s3eHidControllerGetStick1XAxis();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

float s3eHidControllerGetStick1YAxis()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[3] func: s3eHidControllerGetStick1YAxis"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    float ret = g_Ext.m_s3eHidControllerGetStick1YAxis();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

float s3eHidControllerGetStick2XAxis()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[4] func: s3eHidControllerGetStick2XAxis"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    float ret = g_Ext.m_s3eHidControllerGetStick2XAxis();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

float s3eHidControllerGetStick2YAxis()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[5] func: s3eHidControllerGetStick2YAxis"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    float ret = g_Ext.m_s3eHidControllerGetStick2YAxis();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

float s3eHidControllerGetLeftTrigger()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[6] func: s3eHidControllerGetLeftTrigger"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    float ret = g_Ext.m_s3eHidControllerGetLeftTrigger();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

float s3eHidControllerGetRightTrigger()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[7] func: s3eHidControllerGetRightTrigger"));

    if (!_extLoad())
        return 0;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    float ret = g_Ext.m_s3eHidControllerGetRightTrigger();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonX()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[8] func: s3eHidControllerGetButtonX"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonX();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonY()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[9] func: s3eHidControllerGetButtonY"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonY();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonA()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[10] func: s3eHidControllerGetButtonA"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonA();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonB()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[11] func: s3eHidControllerGetButtonB"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonB();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonDPadLeft()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[12] func: s3eHidControllerGetButtonDPadLeft"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonDPadLeft();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonDPadRight()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[13] func: s3eHidControllerGetButtonDPadRight"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonDPadRight();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonDPadUp()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[14] func: s3eHidControllerGetButtonDPadUp"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonDPadUp();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonDPadDown()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[15] func: s3eHidControllerGetButtonDPadDown"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonDPadDown();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonLShoulderDown()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[16] func: s3eHidControllerGetButtonLShoulderDown"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonLShoulderDown();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonRShoulderDown()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[17] func: s3eHidControllerGetButtonRShoulderDown"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonRShoulderDown();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonStart()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[18] func: s3eHidControllerGetButtonStart"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonStart();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerGetButtonSelect()
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[19] func: s3eHidControllerGetButtonSelect"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerGetButtonSelect();

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

bool s3eHidControllerUpdateLegacy(float dt)
{
    IwTrace(HIDCONTROLLER_VERBOSE, ("calling s3eHidController[20] func: s3eHidControllerUpdateLegacy"));

    if (!_extLoad())
        return false;

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallStart(S3E_TRUE, NULL);
#endif

    bool ret = g_Ext.m_s3eHidControllerUpdateLegacy(dt);

#ifdef LOADER_CALL_LOCK
    s3eDeviceLoaderCallDone(S3E_TRUE, NULL);
#endif

    return ret;
}

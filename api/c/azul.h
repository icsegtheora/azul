#ifndef AZUL_H
#define AZUL_H

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/* C89 port for "restrict" keyword from C99 */
#if __STDC__ != 1
#    define restrict __restrict
#else
#    ifndef __STDC_VERSION__
#        define restrict __restrict
#    else
#        if __STDC_VERSION__ < 199901L
#            define restrict __restrict
#        endif
#    endif
#endif

/* cross-platform define for ssize_t (signed size_t) */
#ifdef _WIN32
    #include <windows.h>
    #ifdef _MSC_VER
        typedef SSIZE_T ssize_t;
    #endif
#else
    #include <sys/types.h>
#endif

/* cross-platform define for __declspec(dllimport) */
#ifdef _WIN32
    #define DLLIMPORT __declspec(dllimport)
#else
    #define DLLIMPORT
#endif


struct AzRefAny;
typedef struct AzRefAny AzRefAny;
struct AzLayoutCallbackInfo;
typedef struct AzLayoutCallbackInfo AzLayoutCallbackInfo;
struct AzStyledDom;
typedef struct AzStyledDom AzStyledDom;
typedef AzStyledDom (*AzMarshaledLayoutCallbackType)(AzRefAny* restrict A, AzRefAny* restrict B, AzLayoutCallbackInfo C);

typedef AzStyledDom (*AzLayoutCallbackType)(AzRefAny* restrict A, AzLayoutCallbackInfo B);

struct AzCallbackInfo;
typedef struct AzCallbackInfo AzCallbackInfo;
enum AzUpdate;
typedef enum AzUpdate AzUpdate;
typedef AzUpdate (*AzCallbackType)(AzRefAny* restrict A, AzCallbackInfo B);

struct AzIFrameCallbackInfo;
typedef struct AzIFrameCallbackInfo AzIFrameCallbackInfo;
struct AzIFrameCallbackReturn;
typedef struct AzIFrameCallbackReturn AzIFrameCallbackReturn;
typedef AzIFrameCallbackReturn (*AzIFrameCallbackType)(AzRefAny* restrict A, AzIFrameCallbackInfo B);

struct AzRenderImageCallbackInfo;
typedef struct AzRenderImageCallbackInfo AzRenderImageCallbackInfo;
struct AzImageRef;
typedef struct AzImageRef AzImageRef;
typedef AzImageRef (*AzRenderImageCallbackType)(AzRefAny* restrict A, AzRenderImageCallbackInfo B);

struct AzTimerCallbackInfo;
typedef struct AzTimerCallbackInfo AzTimerCallbackInfo;
struct AzTimerCallbackReturn;
typedef struct AzTimerCallbackReturn AzTimerCallbackReturn;
typedef AzTimerCallbackReturn (*AzTimerCallbackType)(AzRefAny* restrict A, AzRefAny* restrict B, AzTimerCallbackInfo C);

typedef AzUpdate (*AzWriteBackCallbackType)(AzRefAny* restrict A, AzRefAny B, AzCallbackInfo C);

struct AzThreadSender;
typedef struct AzThreadSender AzThreadSender;
struct AzThreadReceiver;
typedef struct AzThreadReceiver AzThreadReceiver;
typedef void (*AzThreadCallbackType)(AzRefAny A, AzThreadSender B, AzThreadReceiver C);

typedef void (*AzRefAnyDestructorType)(void* restrict A);

struct AzCheckBoxState;
typedef struct AzCheckBoxState AzCheckBoxState;
typedef AzUpdate (*AzCheckBoxOnToggleCallbackType)(AzRefAny* restrict A, AzCheckBoxState* const B, AzCallbackInfo* restrict C);

struct AzColorInputState;
typedef struct AzColorInputState AzColorInputState;
typedef AzUpdate (*AzColorInputOnValueChangeCallbackType)(AzRefAny* restrict A, AzColorInputState* const B, AzCallbackInfo* restrict C);

struct AzTextInputState;
typedef struct AzTextInputState AzTextInputState;
struct AzOnTextInputReturn;
typedef struct AzOnTextInputReturn AzOnTextInputReturn;
typedef AzOnTextInputReturn (*AzTextInputOnTextInputCallbackType)(AzRefAny* restrict A, AzTextInputState* const B, AzCallbackInfo* restrict C);

typedef AzOnTextInputReturn (*AzTextInputOnVirtualKeyDownCallbackType)(AzRefAny* restrict A, AzTextInputState* const B, AzCallbackInfo* restrict C);

typedef AzUpdate (*AzTextInputOnFocusLostCallbackType)(AzRefAny* restrict A, AzTextInputState* const B, AzCallbackInfo* restrict C);

struct AzNumberInputState;
typedef struct AzNumberInputState AzNumberInputState;
typedef AzUpdate (*AzNumberInputOnValueChangeCallbackType)(AzRefAny* restrict A, AzNumberInputState* const B, AzCallbackInfo* restrict C);

typedef void (*AzParsedFontDestructorFnType)(void* restrict A);

struct AzInstantPtr;
typedef struct AzInstantPtr AzInstantPtr;
typedef AzInstantPtr (*AzInstantPtrCloneFnType)(AzInstantPtr* const A);

typedef void (*AzInstantPtrDestructorFnType)(AzInstantPtr* restrict A);

struct AzThreadCallback;
typedef struct AzThreadCallback AzThreadCallback;
struct AzThread;
typedef struct AzThread AzThread;
typedef AzThread (*AzCreateThreadFnType)(AzRefAny A, AzRefAny B, AzThreadCallback C);

union AzInstant;
typedef union AzInstant AzInstant;
typedef AzInstant (*AzGetSystemTimeFnType)();

typedef bool (*AzCheckThreadFinishedFnType)(const void* A);

union AzThreadSendMsg;
typedef union AzThreadSendMsg AzThreadSendMsg;
typedef bool (*AzLibrarySendThreadMsgFnType)(const void* A, AzThreadSendMsg B);

union AzOptionThreadReceiveMsg;
typedef union AzOptionThreadReceiveMsg AzOptionThreadReceiveMsg;
typedef AzOptionThreadReceiveMsg (*AzLibraryReceiveThreadMsgFnType)(const void* A);

union AzOptionThreadSendMsg;
typedef union AzOptionThreadSendMsg AzOptionThreadSendMsg;
typedef AzOptionThreadSendMsg (*AzThreadRecvFnType)(const void* A);

union AzThreadReceiveMsg;
typedef union AzThreadReceiveMsg AzThreadReceiveMsg;
typedef bool (*AzThreadSendFnType)(const void* A, AzThreadReceiveMsg B);

typedef void (*AzThreadDestructorFnType)(AzThread* restrict A);

typedef void (*AzThreadReceiverDestructorFnType)(AzThreadReceiver* restrict A);

typedef void (*AzThreadSenderDestructorFnType)(AzThreadSender* restrict A);

struct AzStyleFontFamilyVec;
typedef struct AzStyleFontFamilyVec AzStyleFontFamilyVec;
typedef void (*AzStyleFontFamilyVecDestructorType)(AzStyleFontFamilyVec* restrict A);

struct AzAccessibilityStateVec;
typedef struct AzAccessibilityStateVec AzAccessibilityStateVec;
typedef void (*AzAccessibilityStateVecDestructorType)(AzAccessibilityStateVec* restrict A);

struct AzMenuItemVec;
typedef struct AzMenuItemVec AzMenuItemVec;
typedef void (*AzMenuItemVecDestructorType)(AzMenuItemVec* restrict A);

struct AzTessellatedSvgNodeVec;
typedef struct AzTessellatedSvgNodeVec AzTessellatedSvgNodeVec;
typedef void (*AzTessellatedSvgNodeVecDestructorType)(AzTessellatedSvgNodeVec* restrict A);

struct AzXmlNodeVec;
typedef struct AzXmlNodeVec AzXmlNodeVec;
typedef void (*AzXmlNodeVecDestructorType)(AzXmlNodeVec* restrict A);

struct AzFmtArgVec;
typedef struct AzFmtArgVec AzFmtArgVec;
typedef void (*AzFmtArgVecDestructorType)(AzFmtArgVec* restrict A);

struct AzInlineLineVec;
typedef struct AzInlineLineVec AzInlineLineVec;
typedef void (*AzInlineLineVecDestructorType)(AzInlineLineVec* restrict A);

struct AzInlineWordVec;
typedef struct AzInlineWordVec AzInlineWordVec;
typedef void (*AzInlineWordVecDestructorType)(AzInlineWordVec* restrict A);

struct AzInlineGlyphVec;
typedef struct AzInlineGlyphVec AzInlineGlyphVec;
typedef void (*AzInlineGlyphVecDestructorType)(AzInlineGlyphVec* restrict A);

struct AzInlineTextHitVec;
typedef struct AzInlineTextHitVec AzInlineTextHitVec;
typedef void (*AzInlineTextHitVecDestructorType)(AzInlineTextHitVec* restrict A);

struct AzMonitorVec;
typedef struct AzMonitorVec AzMonitorVec;
typedef void (*AzMonitorVecDestructorType)(AzMonitorVec* restrict A);

struct AzVideoModeVec;
typedef struct AzVideoModeVec AzVideoModeVec;
typedef void (*AzVideoModeVecDestructorType)(AzVideoModeVec* restrict A);

struct AzDomVec;
typedef struct AzDomVec AzDomVec;
typedef void (*AzDomVecDestructorType)(AzDomVec* restrict A);

struct AzIdOrClassVec;
typedef struct AzIdOrClassVec AzIdOrClassVec;
typedef void (*AzIdOrClassVecDestructorType)(AzIdOrClassVec* restrict A);

struct AzNodeDataInlineCssPropertyVec;
typedef struct AzNodeDataInlineCssPropertyVec AzNodeDataInlineCssPropertyVec;
typedef void (*AzNodeDataInlineCssPropertyVecDestructorType)(AzNodeDataInlineCssPropertyVec* restrict A);

struct AzStyleBackgroundContentVec;
typedef struct AzStyleBackgroundContentVec AzStyleBackgroundContentVec;
typedef void (*AzStyleBackgroundContentVecDestructorType)(AzStyleBackgroundContentVec* restrict A);

struct AzStyleBackgroundPositionVec;
typedef struct AzStyleBackgroundPositionVec AzStyleBackgroundPositionVec;
typedef void (*AzStyleBackgroundPositionVecDestructorType)(AzStyleBackgroundPositionVec* restrict A);

struct AzStyleBackgroundRepeatVec;
typedef struct AzStyleBackgroundRepeatVec AzStyleBackgroundRepeatVec;
typedef void (*AzStyleBackgroundRepeatVecDestructorType)(AzStyleBackgroundRepeatVec* restrict A);

struct AzStyleBackgroundSizeVec;
typedef struct AzStyleBackgroundSizeVec AzStyleBackgroundSizeVec;
typedef void (*AzStyleBackgroundSizeVecDestructorType)(AzStyleBackgroundSizeVec* restrict A);

struct AzStyleTransformVec;
typedef struct AzStyleTransformVec AzStyleTransformVec;
typedef void (*AzStyleTransformVecDestructorType)(AzStyleTransformVec* restrict A);

struct AzCssPropertyVec;
typedef struct AzCssPropertyVec AzCssPropertyVec;
typedef void (*AzCssPropertyVecDestructorType)(AzCssPropertyVec* restrict A);

struct AzSvgMultiPolygonVec;
typedef struct AzSvgMultiPolygonVec AzSvgMultiPolygonVec;
typedef void (*AzSvgMultiPolygonVecDestructorType)(AzSvgMultiPolygonVec* restrict A);

struct AzSvgPathVec;
typedef struct AzSvgPathVec AzSvgPathVec;
typedef void (*AzSvgPathVecDestructorType)(AzSvgPathVec* restrict A);

struct AzVertexAttributeVec;
typedef struct AzVertexAttributeVec AzVertexAttributeVec;
typedef void (*AzVertexAttributeVecDestructorType)(AzVertexAttributeVec* restrict A);

struct AzSvgPathElementVec;
typedef struct AzSvgPathElementVec AzSvgPathElementVec;
typedef void (*AzSvgPathElementVecDestructorType)(AzSvgPathElementVec* restrict A);

struct AzSvgVertexVec;
typedef struct AzSvgVertexVec AzSvgVertexVec;
typedef void (*AzSvgVertexVecDestructorType)(AzSvgVertexVec* restrict A);

struct AzU32Vec;
typedef struct AzU32Vec AzU32Vec;
typedef void (*AzU32VecDestructorType)(AzU32Vec* restrict A);

struct AzXWindowTypeVec;
typedef struct AzXWindowTypeVec AzXWindowTypeVec;
typedef void (*AzXWindowTypeVecDestructorType)(AzXWindowTypeVec* restrict A);

struct AzVirtualKeyCodeVec;
typedef struct AzVirtualKeyCodeVec AzVirtualKeyCodeVec;
typedef void (*AzVirtualKeyCodeVecDestructorType)(AzVirtualKeyCodeVec* restrict A);

struct AzCascadeInfoVec;
typedef struct AzCascadeInfoVec AzCascadeInfoVec;
typedef void (*AzCascadeInfoVecDestructorType)(AzCascadeInfoVec* restrict A);

struct AzScanCodeVec;
typedef struct AzScanCodeVec AzScanCodeVec;
typedef void (*AzScanCodeVecDestructorType)(AzScanCodeVec* restrict A);

struct AzCssDeclarationVec;
typedef struct AzCssDeclarationVec AzCssDeclarationVec;
typedef void (*AzCssDeclarationVecDestructorType)(AzCssDeclarationVec* restrict A);

struct AzCssPathSelectorVec;
typedef struct AzCssPathSelectorVec AzCssPathSelectorVec;
typedef void (*AzCssPathSelectorVecDestructorType)(AzCssPathSelectorVec* restrict A);

struct AzStylesheetVec;
typedef struct AzStylesheetVec AzStylesheetVec;
typedef void (*AzStylesheetVecDestructorType)(AzStylesheetVec* restrict A);

struct AzCssRuleBlockVec;
typedef struct AzCssRuleBlockVec AzCssRuleBlockVec;
typedef void (*AzCssRuleBlockVecDestructorType)(AzCssRuleBlockVec* restrict A);

struct AzF32Vec;
typedef struct AzF32Vec AzF32Vec;
typedef void (*AzF32VecDestructorType)(AzF32Vec* restrict A);

struct AzU16Vec;
typedef struct AzU16Vec AzU16Vec;
typedef void (*AzU16VecDestructorType)(AzU16Vec* restrict A);

struct AzU8Vec;
typedef struct AzU8Vec AzU8Vec;
typedef void (*AzU8VecDestructorType)(AzU8Vec* restrict A);

struct AzCallbackDataVec;
typedef struct AzCallbackDataVec AzCallbackDataVec;
typedef void (*AzCallbackDataVecDestructorType)(AzCallbackDataVec* restrict A);

struct AzDebugMessageVec;
typedef struct AzDebugMessageVec AzDebugMessageVec;
typedef void (*AzDebugMessageVecDestructorType)(AzDebugMessageVec* restrict A);

struct AzGLuintVec;
typedef struct AzGLuintVec AzGLuintVec;
typedef void (*AzGLuintVecDestructorType)(AzGLuintVec* restrict A);

struct AzGLintVec;
typedef struct AzGLintVec AzGLintVec;
typedef void (*AzGLintVecDestructorType)(AzGLintVec* restrict A);

struct AzStringVec;
typedef struct AzStringVec AzStringVec;
typedef void (*AzStringVecDestructorType)(AzStringVec* restrict A);

struct AzStringPairVec;
typedef struct AzStringPairVec AzStringPairVec;
typedef void (*AzStringPairVecDestructorType)(AzStringPairVec* restrict A);

struct AzNormalizedLinearColorStopVec;
typedef struct AzNormalizedLinearColorStopVec AzNormalizedLinearColorStopVec;
typedef void (*AzNormalizedLinearColorStopVecDestructorType)(AzNormalizedLinearColorStopVec* restrict A);

struct AzNormalizedRadialColorStopVec;
typedef struct AzNormalizedRadialColorStopVec AzNormalizedRadialColorStopVec;
typedef void (*AzNormalizedRadialColorStopVecDestructorType)(AzNormalizedRadialColorStopVec* restrict A);

struct AzNodeIdVec;
typedef struct AzNodeIdVec AzNodeIdVec;
typedef void (*AzNodeIdVecDestructorType)(AzNodeIdVec* restrict A);

struct AzNodeVec;
typedef struct AzNodeVec AzNodeVec;
typedef void (*AzNodeVecDestructorType)(AzNodeVec* restrict A);

struct AzStyledNodeVec;
typedef struct AzStyledNodeVec AzStyledNodeVec;
typedef void (*AzStyledNodeVecDestructorType)(AzStyledNodeVec* restrict A);

struct AzTagIdToNodeIdMappingVec;
typedef struct AzTagIdToNodeIdMappingVec AzTagIdToNodeIdMappingVec;
typedef void (*AzTagIdToNodeIdMappingVecDestructorType)(AzTagIdToNodeIdMappingVec* restrict A);

struct AzParentWithNodeDepthVec;
typedef struct AzParentWithNodeDepthVec AzParentWithNodeDepthVec;
typedef void (*AzParentWithNodeDepthVecDestructorType)(AzParentWithNodeDepthVec* restrict A);

struct AzNodeDataVec;
typedef struct AzNodeDataVec AzNodeDataVec;
typedef void (*AzNodeDataVecDestructorType)(AzNodeDataVec* restrict A);


struct AzApp {
    void* ptr;
};
typedef struct AzApp AzApp;

enum AzAppLogLevel {
   AzAppLogLevel_Off,
   AzAppLogLevel_Error,
   AzAppLogLevel_Warn,
   AzAppLogLevel_Info,
   AzAppLogLevel_Debug,
   AzAppLogLevel_Trace,
};
typedef enum AzAppLogLevel AzAppLogLevel;

enum AzLayoutSolver {
   AzLayoutSolver_Default,
};
typedef enum AzLayoutSolver AzLayoutSolver;

enum AzVsync {
   AzVsync_Enabled,
   AzVsync_Disabled,
   AzVsync_DontCare,
};
typedef enum AzVsync AzVsync;

enum AzSrgb {
   AzSrgb_Enabled,
   AzSrgb_Disabled,
   AzSrgb_DontCare,
};
typedef enum AzSrgb AzSrgb;

enum AzHwAcceleration {
   AzHwAcceleration_Enabled,
   AzHwAcceleration_Disabled,
   AzHwAcceleration_DontCare,
};
typedef enum AzHwAcceleration AzHwAcceleration;

struct AzLayoutPoint {
    ssize_t x;
    ssize_t y;
};
typedef struct AzLayoutPoint AzLayoutPoint;

struct AzLayoutSize {
    ssize_t width;
    ssize_t height;
};
typedef struct AzLayoutSize AzLayoutSize;

struct AzIOSHandle {
    void* restrict ui_window;
    void* restrict ui_view;
    void* restrict ui_view_controller;
};
typedef struct AzIOSHandle AzIOSHandle;

struct AzMacOSHandle {
    void* restrict ns_window;
    void* restrict ns_view;
};
typedef struct AzMacOSHandle AzMacOSHandle;

struct AzXlibHandle {
    uint64_t window;
    void* restrict display;
};
typedef struct AzXlibHandle AzXlibHandle;

struct AzXcbHandle {
    uint32_t window;
    void* restrict connection;
};
typedef struct AzXcbHandle AzXcbHandle;

struct AzWaylandHandle {
    void* restrict surface;
    void* restrict display;
};
typedef struct AzWaylandHandle AzWaylandHandle;

struct AzWindowsHandle {
    void* restrict hwnd;
    void* restrict hinstance;
};
typedef struct AzWindowsHandle AzWindowsHandle;

struct AzWebHandle {
    uint32_t id;
};
typedef struct AzWebHandle AzWebHandle;

struct AzAndroidHandle {
    void* restrict a_native_window;
};
typedef struct AzAndroidHandle AzAndroidHandle;

enum AzXWindowType {
   AzXWindowType_Desktop,
   AzXWindowType_Dock,
   AzXWindowType_Toolbar,
   AzXWindowType_Menu,
   AzXWindowType_Utility,
   AzXWindowType_Splash,
   AzXWindowType_Dialog,
   AzXWindowType_DropdownMenu,
   AzXWindowType_PopupMenu,
   AzXWindowType_Tooltip,
   AzXWindowType_Notification,
   AzXWindowType_Combo,
   AzXWindowType_Dnd,
   AzXWindowType_Normal,
};
typedef enum AzXWindowType AzXWindowType;

struct AzPhysicalPositionI32 {
    int32_t x;
    int32_t y;
};
typedef struct AzPhysicalPositionI32 AzPhysicalPositionI32;

struct AzPhysicalSizeU32 {
    uint32_t width;
    uint32_t height;
};
typedef struct AzPhysicalSizeU32 AzPhysicalSizeU32;

struct AzLogicalPosition {
    float x;
    float y;
};
typedef struct AzLogicalPosition AzLogicalPosition;

struct AzLogicalSize {
    float width;
    float height;
};
typedef struct AzLogicalSize AzLogicalSize;

struct AzIconKey {
    size_t id;
};
typedef struct AzIconKey AzIconKey;

enum AzVirtualKeyCode {
   AzVirtualKeyCode_Key1,
   AzVirtualKeyCode_Key2,
   AzVirtualKeyCode_Key3,
   AzVirtualKeyCode_Key4,
   AzVirtualKeyCode_Key5,
   AzVirtualKeyCode_Key6,
   AzVirtualKeyCode_Key7,
   AzVirtualKeyCode_Key8,
   AzVirtualKeyCode_Key9,
   AzVirtualKeyCode_Key0,
   AzVirtualKeyCode_A,
   AzVirtualKeyCode_B,
   AzVirtualKeyCode_C,
   AzVirtualKeyCode_D,
   AzVirtualKeyCode_E,
   AzVirtualKeyCode_F,
   AzVirtualKeyCode_G,
   AzVirtualKeyCode_H,
   AzVirtualKeyCode_I,
   AzVirtualKeyCode_J,
   AzVirtualKeyCode_K,
   AzVirtualKeyCode_L,
   AzVirtualKeyCode_M,
   AzVirtualKeyCode_N,
   AzVirtualKeyCode_O,
   AzVirtualKeyCode_P,
   AzVirtualKeyCode_Q,
   AzVirtualKeyCode_R,
   AzVirtualKeyCode_S,
   AzVirtualKeyCode_T,
   AzVirtualKeyCode_U,
   AzVirtualKeyCode_V,
   AzVirtualKeyCode_W,
   AzVirtualKeyCode_X,
   AzVirtualKeyCode_Y,
   AzVirtualKeyCode_Z,
   AzVirtualKeyCode_Escape,
   AzVirtualKeyCode_F1,
   AzVirtualKeyCode_F2,
   AzVirtualKeyCode_F3,
   AzVirtualKeyCode_F4,
   AzVirtualKeyCode_F5,
   AzVirtualKeyCode_F6,
   AzVirtualKeyCode_F7,
   AzVirtualKeyCode_F8,
   AzVirtualKeyCode_F9,
   AzVirtualKeyCode_F10,
   AzVirtualKeyCode_F11,
   AzVirtualKeyCode_F12,
   AzVirtualKeyCode_F13,
   AzVirtualKeyCode_F14,
   AzVirtualKeyCode_F15,
   AzVirtualKeyCode_F16,
   AzVirtualKeyCode_F17,
   AzVirtualKeyCode_F18,
   AzVirtualKeyCode_F19,
   AzVirtualKeyCode_F20,
   AzVirtualKeyCode_F21,
   AzVirtualKeyCode_F22,
   AzVirtualKeyCode_F23,
   AzVirtualKeyCode_F24,
   AzVirtualKeyCode_Snapshot,
   AzVirtualKeyCode_Scroll,
   AzVirtualKeyCode_Pause,
   AzVirtualKeyCode_Insert,
   AzVirtualKeyCode_Home,
   AzVirtualKeyCode_Delete,
   AzVirtualKeyCode_End,
   AzVirtualKeyCode_PageDown,
   AzVirtualKeyCode_PageUp,
   AzVirtualKeyCode_Left,
   AzVirtualKeyCode_Up,
   AzVirtualKeyCode_Right,
   AzVirtualKeyCode_Down,
   AzVirtualKeyCode_Back,
   AzVirtualKeyCode_Return,
   AzVirtualKeyCode_Space,
   AzVirtualKeyCode_Compose,
   AzVirtualKeyCode_Caret,
   AzVirtualKeyCode_Numlock,
   AzVirtualKeyCode_Numpad0,
   AzVirtualKeyCode_Numpad1,
   AzVirtualKeyCode_Numpad2,
   AzVirtualKeyCode_Numpad3,
   AzVirtualKeyCode_Numpad4,
   AzVirtualKeyCode_Numpad5,
   AzVirtualKeyCode_Numpad6,
   AzVirtualKeyCode_Numpad7,
   AzVirtualKeyCode_Numpad8,
   AzVirtualKeyCode_Numpad9,
   AzVirtualKeyCode_NumpadAdd,
   AzVirtualKeyCode_NumpadDivide,
   AzVirtualKeyCode_NumpadDecimal,
   AzVirtualKeyCode_NumpadComma,
   AzVirtualKeyCode_NumpadEnter,
   AzVirtualKeyCode_NumpadEquals,
   AzVirtualKeyCode_NumpadMultiply,
   AzVirtualKeyCode_NumpadSubtract,
   AzVirtualKeyCode_AbntC1,
   AzVirtualKeyCode_AbntC2,
   AzVirtualKeyCode_Apostrophe,
   AzVirtualKeyCode_Apps,
   AzVirtualKeyCode_Asterisk,
   AzVirtualKeyCode_At,
   AzVirtualKeyCode_Ax,
   AzVirtualKeyCode_Backslash,
   AzVirtualKeyCode_Calculator,
   AzVirtualKeyCode_Capital,
   AzVirtualKeyCode_Colon,
   AzVirtualKeyCode_Comma,
   AzVirtualKeyCode_Convert,
   AzVirtualKeyCode_Equals,
   AzVirtualKeyCode_Grave,
   AzVirtualKeyCode_Kana,
   AzVirtualKeyCode_Kanji,
   AzVirtualKeyCode_LAlt,
   AzVirtualKeyCode_LBracket,
   AzVirtualKeyCode_LControl,
   AzVirtualKeyCode_LShift,
   AzVirtualKeyCode_LWin,
   AzVirtualKeyCode_Mail,
   AzVirtualKeyCode_MediaSelect,
   AzVirtualKeyCode_MediaStop,
   AzVirtualKeyCode_Minus,
   AzVirtualKeyCode_Mute,
   AzVirtualKeyCode_MyComputer,
   AzVirtualKeyCode_NavigateForward,
   AzVirtualKeyCode_NavigateBackward,
   AzVirtualKeyCode_NextTrack,
   AzVirtualKeyCode_NoConvert,
   AzVirtualKeyCode_OEM102,
   AzVirtualKeyCode_Period,
   AzVirtualKeyCode_PlayPause,
   AzVirtualKeyCode_Plus,
   AzVirtualKeyCode_Power,
   AzVirtualKeyCode_PrevTrack,
   AzVirtualKeyCode_RAlt,
   AzVirtualKeyCode_RBracket,
   AzVirtualKeyCode_RControl,
   AzVirtualKeyCode_RShift,
   AzVirtualKeyCode_RWin,
   AzVirtualKeyCode_Semicolon,
   AzVirtualKeyCode_Slash,
   AzVirtualKeyCode_Sleep,
   AzVirtualKeyCode_Stop,
   AzVirtualKeyCode_Sysrq,
   AzVirtualKeyCode_Tab,
   AzVirtualKeyCode_Underline,
   AzVirtualKeyCode_Unlabeled,
   AzVirtualKeyCode_VolumeDown,
   AzVirtualKeyCode_VolumeUp,
   AzVirtualKeyCode_Wake,
   AzVirtualKeyCode_WebBack,
   AzVirtualKeyCode_WebFavorites,
   AzVirtualKeyCode_WebForward,
   AzVirtualKeyCode_WebHome,
   AzVirtualKeyCode_WebRefresh,
   AzVirtualKeyCode_WebSearch,
   AzVirtualKeyCode_WebStop,
   AzVirtualKeyCode_Yen,
   AzVirtualKeyCode_Copy,
   AzVirtualKeyCode_Paste,
   AzVirtualKeyCode_Cut,
};
typedef enum AzVirtualKeyCode AzVirtualKeyCode;

enum AzWindowFrame {
   AzWindowFrame_Normal,
   AzWindowFrame_Minimized,
   AzWindowFrame_Maximized,
   AzWindowFrame_Fullscreen,
};
typedef enum AzWindowFrame AzWindowFrame;

struct AzDebugState {
    bool  profiler_dbg;
    bool  render_target_dbg;
    bool  texture_cache_dbg;
    bool  gpu_time_queries;
    bool  gpu_sample_queries;
    bool  disable_batching;
    bool  epochs;
    bool  echo_driver_messages;
    bool  show_overdraw;
    bool  gpu_cache_dbg;
    bool  texture_cache_dbg_clear_evicted;
    bool  picture_caching_dbg;
    bool  primitive_dbg;
    bool  zoom_dbg;
    bool  small_screen;
    bool  disable_opaque_pass;
    bool  disable_alpha_pass;
    bool  disable_clip_masks;
    bool  disable_text_prims;
    bool  disable_gradient_prims;
    bool  obscure_images;
    bool  glyph_flashing;
    bool  smart_profiler;
    bool  invalidation_dbg;
    bool  tile_cache_logging_dbg;
    bool  profiler_capture;
    bool  force_picture_invalidation;
};
typedef struct AzDebugState AzDebugState;

enum AzMouseCursorType {
   AzMouseCursorType_Default,
   AzMouseCursorType_Crosshair,
   AzMouseCursorType_Hand,
   AzMouseCursorType_Arrow,
   AzMouseCursorType_Move,
   AzMouseCursorType_Text,
   AzMouseCursorType_Wait,
   AzMouseCursorType_Help,
   AzMouseCursorType_Progress,
   AzMouseCursorType_NotAllowed,
   AzMouseCursorType_ContextMenu,
   AzMouseCursorType_Cell,
   AzMouseCursorType_VerticalText,
   AzMouseCursorType_Alias,
   AzMouseCursorType_Copy,
   AzMouseCursorType_NoDrop,
   AzMouseCursorType_Grab,
   AzMouseCursorType_Grabbing,
   AzMouseCursorType_AllScroll,
   AzMouseCursorType_ZoomIn,
   AzMouseCursorType_ZoomOut,
   AzMouseCursorType_EResize,
   AzMouseCursorType_NResize,
   AzMouseCursorType_NeResize,
   AzMouseCursorType_NwResize,
   AzMouseCursorType_SResize,
   AzMouseCursorType_SeResize,
   AzMouseCursorType_SwResize,
   AzMouseCursorType_WResize,
   AzMouseCursorType_EwResize,
   AzMouseCursorType_NsResize,
   AzMouseCursorType_NeswResize,
   AzMouseCursorType_NwseResize,
   AzMouseCursorType_ColResize,
   AzMouseCursorType_RowResize,
};
typedef enum AzMouseCursorType AzMouseCursorType;

enum AzRendererType {
   AzRendererType_Hardware,
   AzRendererType_Software,
};
typedef enum AzRendererType AzRendererType;

struct AzMacWindowOptions {
    uint8_t _reserved;
};
typedef struct AzMacWindowOptions AzMacWindowOptions;

struct AzWasmWindowOptions {
    uint8_t _reserved;
};
typedef struct AzWasmWindowOptions AzWasmWindowOptions;

enum AzFullScreenMode {
   AzFullScreenMode_SlowFullScreen,
   AzFullScreenMode_FastFullScreen,
   AzFullScreenMode_SlowWindowed,
   AzFullScreenMode_FastWindowed,
};
typedef enum AzFullScreenMode AzFullScreenMode;

enum AzWindowTheme {
   AzWindowTheme_DarkMode,
   AzWindowTheme_LightMode,
};
typedef enum AzWindowTheme AzWindowTheme;

struct AzTouchState {
    uint8_t unused;
};
typedef struct AzTouchState AzTouchState;

struct AzMarshaledLayoutCallbackInner {
    AzMarshaledLayoutCallbackType cb;
};
typedef struct AzMarshaledLayoutCallbackInner AzMarshaledLayoutCallbackInner;

struct AzLayoutCallbackInner {
    AzLayoutCallbackType cb;
};
typedef struct AzLayoutCallbackInner AzLayoutCallbackInner;

struct AzCallback {
    AzCallbackType cb;
};
typedef struct AzCallback AzCallback;

enum AzUpdateImageType {
   AzUpdateImageType_Background,
   AzUpdateImageType_Content,
};
typedef enum AzUpdateImageType AzUpdateImageType;

enum AzUpdate {
   AzUpdate_DoNothing,
   AzUpdate_RefreshDom,
   AzUpdate_RefreshDomAllWindows,
};
typedef enum AzUpdate AzUpdate;

struct AzNodeId {
    size_t inner;
};
typedef struct AzNodeId AzNodeId;

struct AzDomId {
    size_t inner;
};
typedef struct AzDomId AzDomId;

struct AzPositionInfoInner {
    float x_offset;
    float y_offset;
    float static_x_offset;
    float static_y_offset;
};
typedef struct AzPositionInfoInner AzPositionInfoInner;

enum AzAnimationRepeat {
   AzAnimationRepeat_NoRepeat,
   AzAnimationRepeat_Loop,
   AzAnimationRepeat_PingPong,
};
typedef enum AzAnimationRepeat AzAnimationRepeat;

enum AzAnimationRepeatCountTag {
   AzAnimationRepeatCountTag_Times,
   AzAnimationRepeatCountTag_Infinite,
};
typedef enum AzAnimationRepeatCountTag AzAnimationRepeatCountTag;

struct AzAnimationRepeatCountVariant_Times { AzAnimationRepeatCountTag tag; size_t payload; };
typedef struct AzAnimationRepeatCountVariant_Times AzAnimationRepeatCountVariant_Times;
struct AzAnimationRepeatCountVariant_Infinite { AzAnimationRepeatCountTag tag; };
typedef struct AzAnimationRepeatCountVariant_Infinite AzAnimationRepeatCountVariant_Infinite;
union AzAnimationRepeatCount {
    AzAnimationRepeatCountVariant_Times Times;
    AzAnimationRepeatCountVariant_Infinite Infinite;
};
typedef union AzAnimationRepeatCount AzAnimationRepeatCount;

struct AzIFrameCallback {
    AzIFrameCallbackType cb;
};
typedef struct AzIFrameCallback AzIFrameCallback;

struct AzRenderImageCallback {
    AzRenderImageCallbackType cb;
};
typedef struct AzRenderImageCallback AzRenderImageCallback;

struct AzTimerCallback {
    AzTimerCallbackType cb;
};
typedef struct AzTimerCallback AzTimerCallback;

struct AzWriteBackCallback {
    AzWriteBackCallbackType cb;
};
typedef struct AzWriteBackCallback AzWriteBackCallback;

struct AzThreadCallback {
    AzThreadCallbackType cb;
};
typedef struct AzThreadCallback AzThreadCallback;

struct AzRefCount {
    void* ptr;
};
typedef struct AzRefCount AzRefCount;

enum AzOn {
   AzOn_MouseOver,
   AzOn_MouseDown,
   AzOn_LeftMouseDown,
   AzOn_MiddleMouseDown,
   AzOn_RightMouseDown,
   AzOn_MouseUp,
   AzOn_LeftMouseUp,
   AzOn_MiddleMouseUp,
   AzOn_RightMouseUp,
   AzOn_MouseEnter,
   AzOn_MouseLeave,
   AzOn_Scroll,
   AzOn_TextInput,
   AzOn_VirtualKeyDown,
   AzOn_VirtualKeyUp,
   AzOn_HoveredFile,
   AzOn_DroppedFile,
   AzOn_HoveredFileCancelled,
   AzOn_FocusReceived,
   AzOn_FocusLost,
};
typedef enum AzOn AzOn;

enum AzHoverEventFilter {
   AzHoverEventFilter_MouseOver,
   AzHoverEventFilter_MouseDown,
   AzHoverEventFilter_LeftMouseDown,
   AzHoverEventFilter_RightMouseDown,
   AzHoverEventFilter_MiddleMouseDown,
   AzHoverEventFilter_MouseUp,
   AzHoverEventFilter_LeftMouseUp,
   AzHoverEventFilter_RightMouseUp,
   AzHoverEventFilter_MiddleMouseUp,
   AzHoverEventFilter_MouseEnter,
   AzHoverEventFilter_MouseLeave,
   AzHoverEventFilter_Scroll,
   AzHoverEventFilter_ScrollStart,
   AzHoverEventFilter_ScrollEnd,
   AzHoverEventFilter_TextInput,
   AzHoverEventFilter_VirtualKeyDown,
   AzHoverEventFilter_VirtualKeyUp,
   AzHoverEventFilter_HoveredFile,
   AzHoverEventFilter_DroppedFile,
   AzHoverEventFilter_HoveredFileCancelled,
   AzHoverEventFilter_TouchStart,
   AzHoverEventFilter_TouchMove,
   AzHoverEventFilter_TouchEnd,
   AzHoverEventFilter_TouchCancel,
};
typedef enum AzHoverEventFilter AzHoverEventFilter;

enum AzFocusEventFilter {
   AzFocusEventFilter_MouseOver,
   AzFocusEventFilter_MouseDown,
   AzFocusEventFilter_LeftMouseDown,
   AzFocusEventFilter_RightMouseDown,
   AzFocusEventFilter_MiddleMouseDown,
   AzFocusEventFilter_MouseUp,
   AzFocusEventFilter_LeftMouseUp,
   AzFocusEventFilter_RightMouseUp,
   AzFocusEventFilter_MiddleMouseUp,
   AzFocusEventFilter_MouseEnter,
   AzFocusEventFilter_MouseLeave,
   AzFocusEventFilter_Scroll,
   AzFocusEventFilter_ScrollStart,
   AzFocusEventFilter_ScrollEnd,
   AzFocusEventFilter_TextInput,
   AzFocusEventFilter_VirtualKeyDown,
   AzFocusEventFilter_VirtualKeyUp,
   AzFocusEventFilter_FocusReceived,
   AzFocusEventFilter_FocusLost,
};
typedef enum AzFocusEventFilter AzFocusEventFilter;

enum AzWindowEventFilter {
   AzWindowEventFilter_MouseOver,
   AzWindowEventFilter_MouseDown,
   AzWindowEventFilter_LeftMouseDown,
   AzWindowEventFilter_RightMouseDown,
   AzWindowEventFilter_MiddleMouseDown,
   AzWindowEventFilter_MouseUp,
   AzWindowEventFilter_LeftMouseUp,
   AzWindowEventFilter_RightMouseUp,
   AzWindowEventFilter_MiddleMouseUp,
   AzWindowEventFilter_MouseEnter,
   AzWindowEventFilter_MouseLeave,
   AzWindowEventFilter_Scroll,
   AzWindowEventFilter_ScrollStart,
   AzWindowEventFilter_ScrollEnd,
   AzWindowEventFilter_TextInput,
   AzWindowEventFilter_VirtualKeyDown,
   AzWindowEventFilter_VirtualKeyUp,
   AzWindowEventFilter_HoveredFile,
   AzWindowEventFilter_DroppedFile,
   AzWindowEventFilter_HoveredFileCancelled,
   AzWindowEventFilter_Resized,
   AzWindowEventFilter_Moved,
   AzWindowEventFilter_TouchStart,
   AzWindowEventFilter_TouchMove,
   AzWindowEventFilter_TouchEnd,
   AzWindowEventFilter_TouchCancel,
   AzWindowEventFilter_FocusReceived,
   AzWindowEventFilter_FocusLost,
   AzWindowEventFilter_CloseRequested,
   AzWindowEventFilter_ThemeChanged,
};
typedef enum AzWindowEventFilter AzWindowEventFilter;

enum AzComponentEventFilter {
   AzComponentEventFilter_AfterMount,
   AzComponentEventFilter_BeforeUnmount,
   AzComponentEventFilter_NodeResized,
   AzComponentEventFilter_DefaultAction,
   AzComponentEventFilter_Selected,
};
typedef enum AzComponentEventFilter AzComponentEventFilter;

enum AzApplicationEventFilter {
   AzApplicationEventFilter_DeviceConnected,
   AzApplicationEventFilter_DeviceDisconnected,
};
typedef enum AzApplicationEventFilter AzApplicationEventFilter;

enum AzAccessibilityRole {
   AzAccessibilityRole_TitleBar,
   AzAccessibilityRole_MenuBar,
   AzAccessibilityRole_ScrollBar,
   AzAccessibilityRole_Grip,
   AzAccessibilityRole_Sound,
   AzAccessibilityRole_Cursor,
   AzAccessibilityRole_Caret,
   AzAccessibilityRole_Alert,
   AzAccessibilityRole_Window,
   AzAccessibilityRole_Client,
   AzAccessibilityRole_MenuPopup,
   AzAccessibilityRole_MenuItem,
   AzAccessibilityRole_Tooltip,
   AzAccessibilityRole_Application,
   AzAccessibilityRole_Document,
   AzAccessibilityRole_Pane,
   AzAccessibilityRole_Chart,
   AzAccessibilityRole_Dialog,
   AzAccessibilityRole_Border,
   AzAccessibilityRole_Grouping,
   AzAccessibilityRole_Separator,
   AzAccessibilityRole_Toolbar,
   AzAccessibilityRole_StatusBar,
   AzAccessibilityRole_Table,
   AzAccessibilityRole_ColumnHeader,
   AzAccessibilityRole_RowHeader,
   AzAccessibilityRole_Column,
   AzAccessibilityRole_Row,
   AzAccessibilityRole_Cell,
   AzAccessibilityRole_Link,
   AzAccessibilityRole_HelpBalloon,
   AzAccessibilityRole_Character,
   AzAccessibilityRole_List,
   AzAccessibilityRole_ListItem,
   AzAccessibilityRole_Outline,
   AzAccessibilityRole_OutlineItem,
   AzAccessibilityRole_Pagetab,
   AzAccessibilityRole_PropertyPage,
   AzAccessibilityRole_Indicator,
   AzAccessibilityRole_Graphic,
   AzAccessibilityRole_StaticText,
   AzAccessibilityRole_Text,
   AzAccessibilityRole_PushButton,
   AzAccessibilityRole_CheckButton,
   AzAccessibilityRole_RadioButton,
   AzAccessibilityRole_ComboBox,
   AzAccessibilityRole_DropList,
   AzAccessibilityRole_ProgressBar,
   AzAccessibilityRole_Dial,
   AzAccessibilityRole_HotkeyField,
   AzAccessibilityRole_Slider,
   AzAccessibilityRole_SpinButton,
   AzAccessibilityRole_Diagram,
   AzAccessibilityRole_Animation,
   AzAccessibilityRole_Equation,
   AzAccessibilityRole_ButtonDropdown,
   AzAccessibilityRole_ButtonMenu,
   AzAccessibilityRole_ButtonDropdownGrid,
   AzAccessibilityRole_Whitespace,
   AzAccessibilityRole_PageTabList,
   AzAccessibilityRole_Clock,
   AzAccessibilityRole_SplitButton,
   AzAccessibilityRole_IpAddress,
   AzAccessibilityRole_Nothing,
};
typedef enum AzAccessibilityRole AzAccessibilityRole;

enum AzAccessibilityState {
   AzAccessibilityState_Unavailable,
   AzAccessibilityState_Selected,
   AzAccessibilityState_Focused,
   AzAccessibilityState_Checked,
   AzAccessibilityState_Readonly,
   AzAccessibilityState_Default,
   AzAccessibilityState_Expanded,
   AzAccessibilityState_Collapsed,
   AzAccessibilityState_Busy,
   AzAccessibilityState_Offscreen,
   AzAccessibilityState_Focusable,
   AzAccessibilityState_Selectable,
   AzAccessibilityState_Linked,
   AzAccessibilityState_Traversed,
   AzAccessibilityState_Multiselectable,
   AzAccessibilityState_Protected,
};
typedef enum AzAccessibilityState AzAccessibilityState;

enum AzTabIndexTag {
   AzTabIndexTag_Auto,
   AzTabIndexTag_OverrideInParent,
   AzTabIndexTag_NoKeyboardFocus,
};
typedef enum AzTabIndexTag AzTabIndexTag;

struct AzTabIndexVariant_Auto { AzTabIndexTag tag; };
typedef struct AzTabIndexVariant_Auto AzTabIndexVariant_Auto;
struct AzTabIndexVariant_OverrideInParent { AzTabIndexTag tag; uint32_t payload; };
typedef struct AzTabIndexVariant_OverrideInParent AzTabIndexVariant_OverrideInParent;
struct AzTabIndexVariant_NoKeyboardFocus { AzTabIndexTag tag; };
typedef struct AzTabIndexVariant_NoKeyboardFocus AzTabIndexVariant_NoKeyboardFocus;
union AzTabIndex {
    AzTabIndexVariant_Auto Auto;
    AzTabIndexVariant_OverrideInParent OverrideInParent;
    AzTabIndexVariant_NoKeyboardFocus NoKeyboardFocus;
};
typedef union AzTabIndex AzTabIndex;

enum AzMenuPopupPosition {
   AzMenuPopupPosition_BottomLeftOfCursor,
   AzMenuPopupPosition_BottomRightOfCursor,
   AzMenuPopupPosition_TopLeftOfCursor,
   AzMenuPopupPosition_TopRightOfCursor,
   AzMenuPopupPosition_BottomOfHitRect,
   AzMenuPopupPosition_LeftOfHitRect,
   AzMenuPopupPosition_TopOfHitRect,
   AzMenuPopupPosition_RightOfHitRect,
   AzMenuPopupPosition_AutoCursor,
   AzMenuPopupPosition_AutoHitRect,
};
typedef enum AzMenuPopupPosition AzMenuPopupPosition;

enum AzMenuItemState {
   AzMenuItemState_Normal,
   AzMenuItemState_Greyed,
   AzMenuItemState_Disabled,
};
typedef enum AzMenuItemState AzMenuItemState;

enum AzNodeTypeKey {
   AzNodeTypeKey_Body,
   AzNodeTypeKey_Div,
   AzNodeTypeKey_Br,
   AzNodeTypeKey_P,
   AzNodeTypeKey_Img,
   AzNodeTypeKey_IFrame,
};
typedef enum AzNodeTypeKey AzNodeTypeKey;

struct AzCssNthChildPattern {
    uint32_t repeat;
    uint32_t offset;
};
typedef struct AzCssNthChildPattern AzCssNthChildPattern;

enum AzCssPropertyType {
   AzCssPropertyType_TextColor,
   AzCssPropertyType_FontSize,
   AzCssPropertyType_FontFamily,
   AzCssPropertyType_TextAlign,
   AzCssPropertyType_LetterSpacing,
   AzCssPropertyType_LineHeight,
   AzCssPropertyType_WordSpacing,
   AzCssPropertyType_TabWidth,
   AzCssPropertyType_Cursor,
   AzCssPropertyType_Display,
   AzCssPropertyType_Float,
   AzCssPropertyType_BoxSizing,
   AzCssPropertyType_Width,
   AzCssPropertyType_Height,
   AzCssPropertyType_MinWidth,
   AzCssPropertyType_MinHeight,
   AzCssPropertyType_MaxWidth,
   AzCssPropertyType_MaxHeight,
   AzCssPropertyType_Position,
   AzCssPropertyType_Top,
   AzCssPropertyType_Right,
   AzCssPropertyType_Left,
   AzCssPropertyType_Bottom,
   AzCssPropertyType_FlexWrap,
   AzCssPropertyType_FlexDirection,
   AzCssPropertyType_FlexGrow,
   AzCssPropertyType_FlexShrink,
   AzCssPropertyType_JustifyContent,
   AzCssPropertyType_AlignItems,
   AzCssPropertyType_AlignContent,
   AzCssPropertyType_BackgroundContent,
   AzCssPropertyType_BackgroundPosition,
   AzCssPropertyType_BackgroundSize,
   AzCssPropertyType_BackgroundRepeat,
   AzCssPropertyType_OverflowX,
   AzCssPropertyType_OverflowY,
   AzCssPropertyType_PaddingTop,
   AzCssPropertyType_PaddingLeft,
   AzCssPropertyType_PaddingRight,
   AzCssPropertyType_PaddingBottom,
   AzCssPropertyType_MarginTop,
   AzCssPropertyType_MarginLeft,
   AzCssPropertyType_MarginRight,
   AzCssPropertyType_MarginBottom,
   AzCssPropertyType_BorderTopLeftRadius,
   AzCssPropertyType_BorderTopRightRadius,
   AzCssPropertyType_BorderBottomLeftRadius,
   AzCssPropertyType_BorderBottomRightRadius,
   AzCssPropertyType_BorderTopColor,
   AzCssPropertyType_BorderRightColor,
   AzCssPropertyType_BorderLeftColor,
   AzCssPropertyType_BorderBottomColor,
   AzCssPropertyType_BorderTopStyle,
   AzCssPropertyType_BorderRightStyle,
   AzCssPropertyType_BorderLeftStyle,
   AzCssPropertyType_BorderBottomStyle,
   AzCssPropertyType_BorderTopWidth,
   AzCssPropertyType_BorderRightWidth,
   AzCssPropertyType_BorderLeftWidth,
   AzCssPropertyType_BorderBottomWidth,
   AzCssPropertyType_BoxShadowLeft,
   AzCssPropertyType_BoxShadowRight,
   AzCssPropertyType_BoxShadowTop,
   AzCssPropertyType_BoxShadowBottom,
   AzCssPropertyType_ScrollbarStyle,
   AzCssPropertyType_Opacity,
   AzCssPropertyType_Transform,
   AzCssPropertyType_TransformOrigin,
   AzCssPropertyType_PerspectiveOrigin,
   AzCssPropertyType_BackfaceVisibility,
};
typedef enum AzCssPropertyType AzCssPropertyType;

struct AzColorU {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
};
typedef struct AzColorU AzColorU;

enum AzSizeMetric {
   AzSizeMetric_Px,
   AzSizeMetric_Pt,
   AzSizeMetric_Em,
   AzSizeMetric_Percent,
};
typedef enum AzSizeMetric AzSizeMetric;

struct AzFloatValue {
    ssize_t number;
};
typedef struct AzFloatValue AzFloatValue;

enum AzBoxShadowClipMode {
   AzBoxShadowClipMode_Outset,
   AzBoxShadowClipMode_Inset,
};
typedef enum AzBoxShadowClipMode AzBoxShadowClipMode;

enum AzLayoutAlignContent {
   AzLayoutAlignContent_Stretch,
   AzLayoutAlignContent_Center,
   AzLayoutAlignContent_Start,
   AzLayoutAlignContent_End,
   AzLayoutAlignContent_SpaceBetween,
   AzLayoutAlignContent_SpaceAround,
};
typedef enum AzLayoutAlignContent AzLayoutAlignContent;

enum AzLayoutAlignItems {
   AzLayoutAlignItems_Stretch,
   AzLayoutAlignItems_Center,
   AzLayoutAlignItems_FlexStart,
   AzLayoutAlignItems_FlexEnd,
};
typedef enum AzLayoutAlignItems AzLayoutAlignItems;

enum AzLayoutBoxSizing {
   AzLayoutBoxSizing_ContentBox,
   AzLayoutBoxSizing_BorderBox,
};
typedef enum AzLayoutBoxSizing AzLayoutBoxSizing;

enum AzLayoutFlexDirection {
   AzLayoutFlexDirection_Row,
   AzLayoutFlexDirection_RowReverse,
   AzLayoutFlexDirection_Column,
   AzLayoutFlexDirection_ColumnReverse,
};
typedef enum AzLayoutFlexDirection AzLayoutFlexDirection;

enum AzLayoutDisplay {
   AzLayoutDisplay_None,
   AzLayoutDisplay_Flex,
   AzLayoutDisplay_Block,
   AzLayoutDisplay_InlineBlock,
};
typedef enum AzLayoutDisplay AzLayoutDisplay;

enum AzLayoutFloat {
   AzLayoutFloat_Left,
   AzLayoutFloat_Right,
};
typedef enum AzLayoutFloat AzLayoutFloat;

enum AzLayoutJustifyContent {
   AzLayoutJustifyContent_Start,
   AzLayoutJustifyContent_End,
   AzLayoutJustifyContent_Center,
   AzLayoutJustifyContent_SpaceBetween,
   AzLayoutJustifyContent_SpaceAround,
   AzLayoutJustifyContent_SpaceEvenly,
};
typedef enum AzLayoutJustifyContent AzLayoutJustifyContent;

enum AzLayoutPosition {
   AzLayoutPosition_Static,
   AzLayoutPosition_Relative,
   AzLayoutPosition_Absolute,
   AzLayoutPosition_Fixed,
};
typedef enum AzLayoutPosition AzLayoutPosition;

enum AzLayoutFlexWrap {
   AzLayoutFlexWrap_Wrap,
   AzLayoutFlexWrap_NoWrap,
};
typedef enum AzLayoutFlexWrap AzLayoutFlexWrap;

enum AzLayoutOverflow {
   AzLayoutOverflow_Scroll,
   AzLayoutOverflow_Auto,
   AzLayoutOverflow_Hidden,
   AzLayoutOverflow_Visible,
};
typedef enum AzLayoutOverflow AzLayoutOverflow;

enum AzAngleMetric {
   AzAngleMetric_Degree,
   AzAngleMetric_Radians,
   AzAngleMetric_Grad,
   AzAngleMetric_Turn,
   AzAngleMetric_Percent,
};
typedef enum AzAngleMetric AzAngleMetric;

enum AzDirectionCorner {
   AzDirectionCorner_Right,
   AzDirectionCorner_Left,
   AzDirectionCorner_Top,
   AzDirectionCorner_Bottom,
   AzDirectionCorner_TopRight,
   AzDirectionCorner_TopLeft,
   AzDirectionCorner_BottomRight,
   AzDirectionCorner_BottomLeft,
};
typedef enum AzDirectionCorner AzDirectionCorner;

enum AzExtendMode {
   AzExtendMode_Clamp,
   AzExtendMode_Repeat,
};
typedef enum AzExtendMode AzExtendMode;

enum AzShape {
   AzShape_Ellipse,
   AzShape_Circle,
};
typedef enum AzShape AzShape;

enum AzRadialGradientSize {
   AzRadialGradientSize_ClosestSide,
   AzRadialGradientSize_ClosestCorner,
   AzRadialGradientSize_FarthestSide,
   AzRadialGradientSize_FarthestCorner,
};
typedef enum AzRadialGradientSize AzRadialGradientSize;

enum AzStyleBackgroundRepeat {
   AzStyleBackgroundRepeat_NoRepeat,
   AzStyleBackgroundRepeat_Repeat,
   AzStyleBackgroundRepeat_RepeatX,
   AzStyleBackgroundRepeat_RepeatY,
};
typedef enum AzStyleBackgroundRepeat AzStyleBackgroundRepeat;

enum AzBorderStyle {
   AzBorderStyle_None,
   AzBorderStyle_Solid,
   AzBorderStyle_Double,
   AzBorderStyle_Dotted,
   AzBorderStyle_Dashed,
   AzBorderStyle_Hidden,
   AzBorderStyle_Groove,
   AzBorderStyle_Ridge,
   AzBorderStyle_Inset,
   AzBorderStyle_Outset,
};
typedef enum AzBorderStyle AzBorderStyle;

enum AzStyleCursor {
   AzStyleCursor_Alias,
   AzStyleCursor_AllScroll,
   AzStyleCursor_Cell,
   AzStyleCursor_ColResize,
   AzStyleCursor_ContextMenu,
   AzStyleCursor_Copy,
   AzStyleCursor_Crosshair,
   AzStyleCursor_Default,
   AzStyleCursor_EResize,
   AzStyleCursor_EwResize,
   AzStyleCursor_Grab,
   AzStyleCursor_Grabbing,
   AzStyleCursor_Help,
   AzStyleCursor_Move,
   AzStyleCursor_NResize,
   AzStyleCursor_NsResize,
   AzStyleCursor_NeswResize,
   AzStyleCursor_NwseResize,
   AzStyleCursor_Pointer,
   AzStyleCursor_Progress,
   AzStyleCursor_RowResize,
   AzStyleCursor_SResize,
   AzStyleCursor_SeResize,
   AzStyleCursor_Text,
   AzStyleCursor_Unset,
   AzStyleCursor_VerticalText,
   AzStyleCursor_WResize,
   AzStyleCursor_Wait,
   AzStyleCursor_ZoomIn,
   AzStyleCursor_ZoomOut,
};
typedef enum AzStyleCursor AzStyleCursor;

enum AzStyleBackfaceVisibility {
   AzStyleBackfaceVisibility_Hidden,
   AzStyleBackfaceVisibility_Visible,
};
typedef enum AzStyleBackfaceVisibility AzStyleBackfaceVisibility;

enum AzStyleTextAlign {
   AzStyleTextAlign_Left,
   AzStyleTextAlign_Center,
   AzStyleTextAlign_Right,
};
typedef enum AzStyleTextAlign AzStyleTextAlign;

struct AzCheckBoxOnToggleCallback {
    AzCheckBoxOnToggleCallbackType cb;
};
typedef struct AzCheckBoxOnToggleCallback AzCheckBoxOnToggleCallback;

struct AzCheckBoxState {
    bool  checked;
};
typedef struct AzCheckBoxState AzCheckBoxState;

struct AzColorInputOnValueChangeCallback {
    AzColorInputOnValueChangeCallbackType cb;
};
typedef struct AzColorInputOnValueChangeCallback AzColorInputOnValueChangeCallback;

struct AzTextInputSelectionRange {
    size_t from;
    size_t to;
};
typedef struct AzTextInputSelectionRange AzTextInputSelectionRange;

struct AzTextInputOnTextInputCallback {
    AzTextInputOnTextInputCallbackType cb;
};
typedef struct AzTextInputOnTextInputCallback AzTextInputOnTextInputCallback;

struct AzTextInputOnVirtualKeyDownCallback {
    AzTextInputOnVirtualKeyDownCallbackType cb;
};
typedef struct AzTextInputOnVirtualKeyDownCallback AzTextInputOnVirtualKeyDownCallback;

struct AzTextInputOnFocusLostCallback {
    AzTextInputOnFocusLostCallbackType cb;
};
typedef struct AzTextInputOnFocusLostCallback AzTextInputOnFocusLostCallback;

enum AzTextInputValid {
   AzTextInputValid_Yes,
   AzTextInputValid_No,
};
typedef enum AzTextInputValid AzTextInputValid;

struct AzNumberInputState {
    float previous;
    float number;
    float min;
    float max;
};
typedef struct AzNumberInputState AzNumberInputState;

struct AzNumberInputOnValueChangeCallback {
    AzNumberInputOnValueChangeCallbackType cb;
};
typedef struct AzNumberInputOnValueChangeCallback AzNumberInputOnValueChangeCallback;

struct AzNode {
    size_t parent;
    size_t previous_sibling;
    size_t next_sibling;
    size_t last_child;
};
typedef struct AzNode AzNode;

struct AzCascadeInfo {
    uint32_t index_in_parent;
    bool  is_last_child;
};
typedef struct AzCascadeInfo AzCascadeInfo;

struct AzStyledNodeState {
    bool  normal;
    bool  hover;
    bool  active;
    bool  focused;
};
typedef struct AzStyledNodeState AzStyledNodeState;

struct AzTagId {
    uint64_t inner;
};
typedef struct AzTagId AzTagId;

struct AzCssPropertyCache {
    void* restrict ptr;
};
typedef struct AzCssPropertyCache AzCssPropertyCache;

struct AzGlVoidPtrConst {
    void* ptr;
};
typedef struct AzGlVoidPtrConst AzGlVoidPtrConst;

struct AzGlVoidPtrMut {
    void* restrict ptr;
};
typedef struct AzGlVoidPtrMut AzGlVoidPtrMut;

struct AzGlShaderPrecisionFormatReturn {
    int32_t _0;
    int32_t _1;
    int32_t _2;
};
typedef struct AzGlShaderPrecisionFormatReturn AzGlShaderPrecisionFormatReturn;

enum AzVertexAttributeType {
   AzVertexAttributeType_Float,
   AzVertexAttributeType_Double,
   AzVertexAttributeType_UnsignedByte,
   AzVertexAttributeType_UnsignedShort,
   AzVertexAttributeType_UnsignedInt,
};
typedef enum AzVertexAttributeType AzVertexAttributeType;

enum AzIndexBufferFormat {
   AzIndexBufferFormat_Points,
   AzIndexBufferFormat_Lines,
   AzIndexBufferFormat_LineStrip,
   AzIndexBufferFormat_Triangles,
   AzIndexBufferFormat_TriangleStrip,
   AzIndexBufferFormat_TriangleFan,
};
typedef enum AzIndexBufferFormat AzIndexBufferFormat;

enum AzGlType {
   AzGlType_Gl,
   AzGlType_Gles,
};
typedef enum AzGlType AzGlType;

struct AzU8VecRef {
    uint8_t* ptr;
    size_t len;
};
typedef struct AzU8VecRef AzU8VecRef;

struct AzU8VecRefMut {
    uint8_t* restrict ptr;
    size_t len;
};
typedef struct AzU8VecRefMut AzU8VecRefMut;

struct AzF32VecRef {
    float* ptr;
    size_t len;
};
typedef struct AzF32VecRef AzF32VecRef;

struct AzI32VecRef {
    int32_t* ptr;
    size_t len;
};
typedef struct AzI32VecRef AzI32VecRef;

struct AzGLuintVecRef {
    uint32_t* ptr;
    size_t len;
};
typedef struct AzGLuintVecRef AzGLuintVecRef;

struct AzGLenumVecRef {
    uint32_t* ptr;
    size_t len;
};
typedef struct AzGLenumVecRef AzGLenumVecRef;

struct AzGLintVecRefMut {
    int32_t* restrict ptr;
    size_t len;
};
typedef struct AzGLintVecRefMut AzGLintVecRefMut;

struct AzGLint64VecRefMut {
    int64_t* restrict ptr;
    size_t len;
};
typedef struct AzGLint64VecRefMut AzGLint64VecRefMut;

struct AzGLbooleanVecRefMut {
    uint8_t* restrict ptr;
    size_t len;
};
typedef struct AzGLbooleanVecRefMut AzGLbooleanVecRefMut;

struct AzGLfloatVecRefMut {
    float* restrict ptr;
    size_t len;
};
typedef struct AzGLfloatVecRefMut AzGLfloatVecRefMut;

struct AzRefstr {
    uint8_t* ptr;
    size_t len;
};
typedef struct AzRefstr AzRefstr;

struct AzGLsyncPtr {
    void* ptr;
};
typedef struct AzGLsyncPtr AzGLsyncPtr;

struct AzTextureFlags {
    bool  is_opaque;
    bool  is_video_texture;
};
typedef struct AzTextureFlags AzTextureFlags;

struct AzImageRef {
    void* data;
    void* copies;
};
typedef struct AzImageRef AzImageRef;

enum AzRawImageFormat {
   AzRawImageFormat_R8,
   AzRawImageFormat_R16,
   AzRawImageFormat_RG16,
   AzRawImageFormat_BGRA8,
   AzRawImageFormat_RGBAF32,
   AzRawImageFormat_RG8,
   AzRawImageFormat_RGBAI32,
   AzRawImageFormat_RGBA8,
};
typedef enum AzRawImageFormat AzRawImageFormat;

enum AzEncodeImageError {
   AzEncodeImageError_EncoderNotAvailable,
   AzEncodeImageError_InsufficientMemory,
   AzEncodeImageError_DimensionError,
   AzEncodeImageError_InvalidData,
   AzEncodeImageError_Unknown,
};
typedef enum AzEncodeImageError AzEncodeImageError;

enum AzDecodeImageError {
   AzDecodeImageError_InsufficientMemory,
   AzDecodeImageError_DimensionError,
   AzDecodeImageError_UnsupportedImageFormat,
   AzDecodeImageError_Unknown,
};
typedef enum AzDecodeImageError AzDecodeImageError;

struct AzFontRef {
    void* data;
    void* copies;
};
typedef struct AzFontRef AzFontRef;

struct AzSvg {
    void* restrict ptr;
};
typedef struct AzSvg AzSvg;

struct AzSvgXmlNode {
    void* restrict ptr;
};
typedef struct AzSvgXmlNode AzSvgXmlNode;

struct AzSvgCircle {
    float center_x;
    float center_y;
    float radius;
};
typedef struct AzSvgCircle AzSvgCircle;

struct AzSvgPoint {
    float x;
    float y;
};
typedef struct AzSvgPoint AzSvgPoint;

struct AzSvgRect {
    float width;
    float height;
    float x;
    float y;
    float radius_top_left;
    float radius_top_right;
    float radius_bottom_left;
    float radius_bottom_right;
};
typedef struct AzSvgRect AzSvgRect;

struct AzSvgVertex {
    float x;
    float y;
};
typedef struct AzSvgVertex AzSvgVertex;

enum AzShapeRendering {
   AzShapeRendering_OptimizeSpeed,
   AzShapeRendering_CrispEdges,
   AzShapeRendering_GeometricPrecision,
};
typedef enum AzShapeRendering AzShapeRendering;

enum AzTextRendering {
   AzTextRendering_OptimizeSpeed,
   AzTextRendering_OptimizeLegibility,
   AzTextRendering_GeometricPrecision,
};
typedef enum AzTextRendering AzTextRendering;

enum AzImageRendering {
   AzImageRendering_OptimizeQuality,
   AzImageRendering_OptimizeSpeed,
};
typedef enum AzImageRendering AzImageRendering;

enum AzFontDatabase {
   AzFontDatabase_Empty,
   AzFontDatabase_System,
};
typedef enum AzFontDatabase AzFontDatabase;

enum AzIndentTag {
   AzIndentTag_None,
   AzIndentTag_Spaces,
   AzIndentTag_Tabs,
};
typedef enum AzIndentTag AzIndentTag;

struct AzIndentVariant_None { AzIndentTag tag; };
typedef struct AzIndentVariant_None AzIndentVariant_None;
struct AzIndentVariant_Spaces { AzIndentTag tag; uint8_t payload; };
typedef struct AzIndentVariant_Spaces AzIndentVariant_Spaces;
struct AzIndentVariant_Tabs { AzIndentTag tag; };
typedef struct AzIndentVariant_Tabs AzIndentVariant_Tabs;
union AzIndent {
    AzIndentVariant_None None;
    AzIndentVariant_Spaces Spaces;
    AzIndentVariant_Tabs Tabs;
};
typedef union AzIndent AzIndent;

enum AzSvgFitToTag {
   AzSvgFitToTag_Original,
   AzSvgFitToTag_Width,
   AzSvgFitToTag_Height,
   AzSvgFitToTag_Zoom,
};
typedef enum AzSvgFitToTag AzSvgFitToTag;

struct AzSvgFitToVariant_Original { AzSvgFitToTag tag; };
typedef struct AzSvgFitToVariant_Original AzSvgFitToVariant_Original;
struct AzSvgFitToVariant_Width { AzSvgFitToTag tag; uint32_t payload; };
typedef struct AzSvgFitToVariant_Width AzSvgFitToVariant_Width;
struct AzSvgFitToVariant_Height { AzSvgFitToTag tag; uint32_t payload; };
typedef struct AzSvgFitToVariant_Height AzSvgFitToVariant_Height;
struct AzSvgFitToVariant_Zoom { AzSvgFitToTag tag; float payload; };
typedef struct AzSvgFitToVariant_Zoom AzSvgFitToVariant_Zoom;
union AzSvgFitTo {
    AzSvgFitToVariant_Original Original;
    AzSvgFitToVariant_Width Width;
    AzSvgFitToVariant_Height Height;
    AzSvgFitToVariant_Zoom Zoom;
};
typedef union AzSvgFitTo AzSvgFitTo;

enum AzSvgFillRule {
   AzSvgFillRule_Winding,
   AzSvgFillRule_EvenOdd,
};
typedef enum AzSvgFillRule AzSvgFillRule;

struct AzSvgTransform {
    float sx;
    float kx;
    float ky;
    float sy;
    float tx;
    float ty;
};
typedef struct AzSvgTransform AzSvgTransform;

enum AzSvgLineJoin {
   AzSvgLineJoin_Miter,
   AzSvgLineJoin_MiterClip,
   AzSvgLineJoin_Round,
   AzSvgLineJoin_Bevel,
};
typedef enum AzSvgLineJoin AzSvgLineJoin;

enum AzSvgLineCap {
   AzSvgLineCap_Butt,
   AzSvgLineCap_Square,
   AzSvgLineCap_Round,
};
typedef enum AzSvgLineCap AzSvgLineCap;

struct AzSvgDashPattern {
    float offset;
    float length_1;
    float gap_1;
    float length_2;
    float gap_2;
    float length_3;
    float gap_3;
};
typedef struct AzSvgDashPattern AzSvgDashPattern;

struct AzMsgBox {
    size_t _reserved;
};
typedef struct AzMsgBox AzMsgBox;

enum AzMsgBoxIcon {
   AzMsgBoxIcon_Info,
   AzMsgBoxIcon_Warning,
   AzMsgBoxIcon_Error,
   AzMsgBoxIcon_Question,
};
typedef enum AzMsgBoxIcon AzMsgBoxIcon;

enum AzMsgBoxYesNo {
   AzMsgBoxYesNo_Yes,
   AzMsgBoxYesNo_No,
};
typedef enum AzMsgBoxYesNo AzMsgBoxYesNo;

enum AzMsgBoxOkCancel {
   AzMsgBoxOkCancel_Ok,
   AzMsgBoxOkCancel_Cancel,
};
typedef enum AzMsgBoxOkCancel AzMsgBoxOkCancel;

struct AzFileDialog {
    size_t _reserved;
};
typedef struct AzFileDialog AzFileDialog;

struct AzColorPickerDialog {
    size_t _reserved;
};
typedef struct AzColorPickerDialog AzColorPickerDialog;

struct AzSystemClipboard {
    void* _native;
};
typedef struct AzSystemClipboard AzSystemClipboard;

struct AzInstantPtrCloneFn {
    AzInstantPtrCloneFnType cb;
};
typedef struct AzInstantPtrCloneFn AzInstantPtrCloneFn;

struct AzInstantPtrDestructorFn {
    AzInstantPtrDestructorFnType cb;
};
typedef struct AzInstantPtrDestructorFn AzInstantPtrDestructorFn;

struct AzSystemTick {
    uint64_t tick_counter;
};
typedef struct AzSystemTick AzSystemTick;

struct AzSystemTimeDiff {
    uint64_t secs;
    uint32_t nanos;
};
typedef struct AzSystemTimeDiff AzSystemTimeDiff;

struct AzSystemTickDiff {
    uint64_t tick_diff;
};
typedef struct AzSystemTickDiff AzSystemTickDiff;

struct AzTimerId {
    size_t id;
};
typedef struct AzTimerId AzTimerId;

enum AzTerminateTimer {
   AzTerminateTimer_Terminate,
   AzTerminateTimer_Continue,
};
typedef enum AzTerminateTimer AzTerminateTimer;

struct AzThreadId {
    size_t id;
};
typedef struct AzThreadId AzThreadId;

struct AzThread {
    void* ptr;
};
typedef struct AzThread AzThread;

struct AzThreadSender {
    void* ptr;
};
typedef struct AzThreadSender AzThreadSender;

struct AzThreadReceiver {
    void* ptr;
};
typedef struct AzThreadReceiver AzThreadReceiver;

struct AzCreateThreadFn {
    AzCreateThreadFnType cb;
};
typedef struct AzCreateThreadFn AzCreateThreadFn;

struct AzGetSystemTimeFn {
    AzGetSystemTimeFnType cb;
};
typedef struct AzGetSystemTimeFn AzGetSystemTimeFn;

struct AzCheckThreadFinishedFn {
    AzCheckThreadFinishedFnType cb;
};
typedef struct AzCheckThreadFinishedFn AzCheckThreadFinishedFn;

struct AzLibrarySendThreadMsgFn {
    AzLibrarySendThreadMsgFnType cb;
};
typedef struct AzLibrarySendThreadMsgFn AzLibrarySendThreadMsgFn;

struct AzLibraryReceiveThreadMsgFn {
    AzLibraryReceiveThreadMsgFnType cb;
};
typedef struct AzLibraryReceiveThreadMsgFn AzLibraryReceiveThreadMsgFn;

struct AzThreadRecvFn {
    AzThreadRecvFnType cb;
};
typedef struct AzThreadRecvFn AzThreadRecvFn;

struct AzThreadSendFn {
    AzThreadSendFnType cb;
};
typedef struct AzThreadSendFn AzThreadSendFn;

struct AzThreadDestructorFn {
    AzThreadDestructorFnType cb;
};
typedef struct AzThreadDestructorFn AzThreadDestructorFn;

struct AzThreadReceiverDestructorFn {
    AzThreadReceiverDestructorFnType cb;
};
typedef struct AzThreadReceiverDestructorFn AzThreadReceiverDestructorFn;

struct AzThreadSenderDestructorFn {
    AzThreadSenderDestructorFnType cb;
};
typedef struct AzThreadSenderDestructorFn AzThreadSenderDestructorFn;

enum AzStyleFontFamilyVecDestructorTag {
   AzStyleFontFamilyVecDestructorTag_DefaultRust,
   AzStyleFontFamilyVecDestructorTag_NoDestructor,
   AzStyleFontFamilyVecDestructorTag_External,
};
typedef enum AzStyleFontFamilyVecDestructorTag AzStyleFontFamilyVecDestructorTag;

struct AzStyleFontFamilyVecDestructorVariant_DefaultRust { AzStyleFontFamilyVecDestructorTag tag; };
typedef struct AzStyleFontFamilyVecDestructorVariant_DefaultRust AzStyleFontFamilyVecDestructorVariant_DefaultRust;
struct AzStyleFontFamilyVecDestructorVariant_NoDestructor { AzStyleFontFamilyVecDestructorTag tag; };
typedef struct AzStyleFontFamilyVecDestructorVariant_NoDestructor AzStyleFontFamilyVecDestructorVariant_NoDestructor;
struct AzStyleFontFamilyVecDestructorVariant_External { AzStyleFontFamilyVecDestructorTag tag; AzStyleFontFamilyVecDestructorType payload; };
typedef struct AzStyleFontFamilyVecDestructorVariant_External AzStyleFontFamilyVecDestructorVariant_External;
union AzStyleFontFamilyVecDestructor {
    AzStyleFontFamilyVecDestructorVariant_DefaultRust DefaultRust;
    AzStyleFontFamilyVecDestructorVariant_NoDestructor NoDestructor;
    AzStyleFontFamilyVecDestructorVariant_External External;
};
typedef union AzStyleFontFamilyVecDestructor AzStyleFontFamilyVecDestructor;

enum AzAccessibilityStateVecDestructorTag {
   AzAccessibilityStateVecDestructorTag_DefaultRust,
   AzAccessibilityStateVecDestructorTag_NoDestructor,
   AzAccessibilityStateVecDestructorTag_External,
};
typedef enum AzAccessibilityStateVecDestructorTag AzAccessibilityStateVecDestructorTag;

struct AzAccessibilityStateVecDestructorVariant_DefaultRust { AzAccessibilityStateVecDestructorTag tag; };
typedef struct AzAccessibilityStateVecDestructorVariant_DefaultRust AzAccessibilityStateVecDestructorVariant_DefaultRust;
struct AzAccessibilityStateVecDestructorVariant_NoDestructor { AzAccessibilityStateVecDestructorTag tag; };
typedef struct AzAccessibilityStateVecDestructorVariant_NoDestructor AzAccessibilityStateVecDestructorVariant_NoDestructor;
struct AzAccessibilityStateVecDestructorVariant_External { AzAccessibilityStateVecDestructorTag tag; AzAccessibilityStateVecDestructorType payload; };
typedef struct AzAccessibilityStateVecDestructorVariant_External AzAccessibilityStateVecDestructorVariant_External;
union AzAccessibilityStateVecDestructor {
    AzAccessibilityStateVecDestructorVariant_DefaultRust DefaultRust;
    AzAccessibilityStateVecDestructorVariant_NoDestructor NoDestructor;
    AzAccessibilityStateVecDestructorVariant_External External;
};
typedef union AzAccessibilityStateVecDestructor AzAccessibilityStateVecDestructor;

enum AzMenuItemVecDestructorTag {
   AzMenuItemVecDestructorTag_DefaultRust,
   AzMenuItemVecDestructorTag_NoDestructor,
   AzMenuItemVecDestructorTag_External,
};
typedef enum AzMenuItemVecDestructorTag AzMenuItemVecDestructorTag;

struct AzMenuItemVecDestructorVariant_DefaultRust { AzMenuItemVecDestructorTag tag; };
typedef struct AzMenuItemVecDestructorVariant_DefaultRust AzMenuItemVecDestructorVariant_DefaultRust;
struct AzMenuItemVecDestructorVariant_NoDestructor { AzMenuItemVecDestructorTag tag; };
typedef struct AzMenuItemVecDestructorVariant_NoDestructor AzMenuItemVecDestructorVariant_NoDestructor;
struct AzMenuItemVecDestructorVariant_External { AzMenuItemVecDestructorTag tag; AzMenuItemVecDestructorType payload; };
typedef struct AzMenuItemVecDestructorVariant_External AzMenuItemVecDestructorVariant_External;
union AzMenuItemVecDestructor {
    AzMenuItemVecDestructorVariant_DefaultRust DefaultRust;
    AzMenuItemVecDestructorVariant_NoDestructor NoDestructor;
    AzMenuItemVecDestructorVariant_External External;
};
typedef union AzMenuItemVecDestructor AzMenuItemVecDestructor;

enum AzTessellatedSvgNodeVecDestructorTag {
   AzTessellatedSvgNodeVecDestructorTag_DefaultRust,
   AzTessellatedSvgNodeVecDestructorTag_NoDestructor,
   AzTessellatedSvgNodeVecDestructorTag_External,
};
typedef enum AzTessellatedSvgNodeVecDestructorTag AzTessellatedSvgNodeVecDestructorTag;

struct AzTessellatedSvgNodeVecDestructorVariant_DefaultRust { AzTessellatedSvgNodeVecDestructorTag tag; };
typedef struct AzTessellatedSvgNodeVecDestructorVariant_DefaultRust AzTessellatedSvgNodeVecDestructorVariant_DefaultRust;
struct AzTessellatedSvgNodeVecDestructorVariant_NoDestructor { AzTessellatedSvgNodeVecDestructorTag tag; };
typedef struct AzTessellatedSvgNodeVecDestructorVariant_NoDestructor AzTessellatedSvgNodeVecDestructorVariant_NoDestructor;
struct AzTessellatedSvgNodeVecDestructorVariant_External { AzTessellatedSvgNodeVecDestructorTag tag; AzTessellatedSvgNodeVecDestructorType payload; };
typedef struct AzTessellatedSvgNodeVecDestructorVariant_External AzTessellatedSvgNodeVecDestructorVariant_External;
union AzTessellatedSvgNodeVecDestructor {
    AzTessellatedSvgNodeVecDestructorVariant_DefaultRust DefaultRust;
    AzTessellatedSvgNodeVecDestructorVariant_NoDestructor NoDestructor;
    AzTessellatedSvgNodeVecDestructorVariant_External External;
};
typedef union AzTessellatedSvgNodeVecDestructor AzTessellatedSvgNodeVecDestructor;

enum AzXmlNodeVecDestructorTag {
   AzXmlNodeVecDestructorTag_DefaultRust,
   AzXmlNodeVecDestructorTag_NoDestructor,
   AzXmlNodeVecDestructorTag_External,
};
typedef enum AzXmlNodeVecDestructorTag AzXmlNodeVecDestructorTag;

struct AzXmlNodeVecDestructorVariant_DefaultRust { AzXmlNodeVecDestructorTag tag; };
typedef struct AzXmlNodeVecDestructorVariant_DefaultRust AzXmlNodeVecDestructorVariant_DefaultRust;
struct AzXmlNodeVecDestructorVariant_NoDestructor { AzXmlNodeVecDestructorTag tag; };
typedef struct AzXmlNodeVecDestructorVariant_NoDestructor AzXmlNodeVecDestructorVariant_NoDestructor;
struct AzXmlNodeVecDestructorVariant_External { AzXmlNodeVecDestructorTag tag; AzXmlNodeVecDestructorType payload; };
typedef struct AzXmlNodeVecDestructorVariant_External AzXmlNodeVecDestructorVariant_External;
union AzXmlNodeVecDestructor {
    AzXmlNodeVecDestructorVariant_DefaultRust DefaultRust;
    AzXmlNodeVecDestructorVariant_NoDestructor NoDestructor;
    AzXmlNodeVecDestructorVariant_External External;
};
typedef union AzXmlNodeVecDestructor AzXmlNodeVecDestructor;

enum AzFmtArgVecDestructorTag {
   AzFmtArgVecDestructorTag_DefaultRust,
   AzFmtArgVecDestructorTag_NoDestructor,
   AzFmtArgVecDestructorTag_External,
};
typedef enum AzFmtArgVecDestructorTag AzFmtArgVecDestructorTag;

struct AzFmtArgVecDestructorVariant_DefaultRust { AzFmtArgVecDestructorTag tag; };
typedef struct AzFmtArgVecDestructorVariant_DefaultRust AzFmtArgVecDestructorVariant_DefaultRust;
struct AzFmtArgVecDestructorVariant_NoDestructor { AzFmtArgVecDestructorTag tag; };
typedef struct AzFmtArgVecDestructorVariant_NoDestructor AzFmtArgVecDestructorVariant_NoDestructor;
struct AzFmtArgVecDestructorVariant_External { AzFmtArgVecDestructorTag tag; AzFmtArgVecDestructorType payload; };
typedef struct AzFmtArgVecDestructorVariant_External AzFmtArgVecDestructorVariant_External;
union AzFmtArgVecDestructor {
    AzFmtArgVecDestructorVariant_DefaultRust DefaultRust;
    AzFmtArgVecDestructorVariant_NoDestructor NoDestructor;
    AzFmtArgVecDestructorVariant_External External;
};
typedef union AzFmtArgVecDestructor AzFmtArgVecDestructor;

enum AzInlineLineVecDestructorTag {
   AzInlineLineVecDestructorTag_DefaultRust,
   AzInlineLineVecDestructorTag_NoDestructor,
   AzInlineLineVecDestructorTag_External,
};
typedef enum AzInlineLineVecDestructorTag AzInlineLineVecDestructorTag;

struct AzInlineLineVecDestructorVariant_DefaultRust { AzInlineLineVecDestructorTag tag; };
typedef struct AzInlineLineVecDestructorVariant_DefaultRust AzInlineLineVecDestructorVariant_DefaultRust;
struct AzInlineLineVecDestructorVariant_NoDestructor { AzInlineLineVecDestructorTag tag; };
typedef struct AzInlineLineVecDestructorVariant_NoDestructor AzInlineLineVecDestructorVariant_NoDestructor;
struct AzInlineLineVecDestructorVariant_External { AzInlineLineVecDestructorTag tag; AzInlineLineVecDestructorType payload; };
typedef struct AzInlineLineVecDestructorVariant_External AzInlineLineVecDestructorVariant_External;
union AzInlineLineVecDestructor {
    AzInlineLineVecDestructorVariant_DefaultRust DefaultRust;
    AzInlineLineVecDestructorVariant_NoDestructor NoDestructor;
    AzInlineLineVecDestructorVariant_External External;
};
typedef union AzInlineLineVecDestructor AzInlineLineVecDestructor;

enum AzInlineWordVecDestructorTag {
   AzInlineWordVecDestructorTag_DefaultRust,
   AzInlineWordVecDestructorTag_NoDestructor,
   AzInlineWordVecDestructorTag_External,
};
typedef enum AzInlineWordVecDestructorTag AzInlineWordVecDestructorTag;

struct AzInlineWordVecDestructorVariant_DefaultRust { AzInlineWordVecDestructorTag tag; };
typedef struct AzInlineWordVecDestructorVariant_DefaultRust AzInlineWordVecDestructorVariant_DefaultRust;
struct AzInlineWordVecDestructorVariant_NoDestructor { AzInlineWordVecDestructorTag tag; };
typedef struct AzInlineWordVecDestructorVariant_NoDestructor AzInlineWordVecDestructorVariant_NoDestructor;
struct AzInlineWordVecDestructorVariant_External { AzInlineWordVecDestructorTag tag; AzInlineWordVecDestructorType payload; };
typedef struct AzInlineWordVecDestructorVariant_External AzInlineWordVecDestructorVariant_External;
union AzInlineWordVecDestructor {
    AzInlineWordVecDestructorVariant_DefaultRust DefaultRust;
    AzInlineWordVecDestructorVariant_NoDestructor NoDestructor;
    AzInlineWordVecDestructorVariant_External External;
};
typedef union AzInlineWordVecDestructor AzInlineWordVecDestructor;

enum AzInlineGlyphVecDestructorTag {
   AzInlineGlyphVecDestructorTag_DefaultRust,
   AzInlineGlyphVecDestructorTag_NoDestructor,
   AzInlineGlyphVecDestructorTag_External,
};
typedef enum AzInlineGlyphVecDestructorTag AzInlineGlyphVecDestructorTag;

struct AzInlineGlyphVecDestructorVariant_DefaultRust { AzInlineGlyphVecDestructorTag tag; };
typedef struct AzInlineGlyphVecDestructorVariant_DefaultRust AzInlineGlyphVecDestructorVariant_DefaultRust;
struct AzInlineGlyphVecDestructorVariant_NoDestructor { AzInlineGlyphVecDestructorTag tag; };
typedef struct AzInlineGlyphVecDestructorVariant_NoDestructor AzInlineGlyphVecDestructorVariant_NoDestructor;
struct AzInlineGlyphVecDestructorVariant_External { AzInlineGlyphVecDestructorTag tag; AzInlineGlyphVecDestructorType payload; };
typedef struct AzInlineGlyphVecDestructorVariant_External AzInlineGlyphVecDestructorVariant_External;
union AzInlineGlyphVecDestructor {
    AzInlineGlyphVecDestructorVariant_DefaultRust DefaultRust;
    AzInlineGlyphVecDestructorVariant_NoDestructor NoDestructor;
    AzInlineGlyphVecDestructorVariant_External External;
};
typedef union AzInlineGlyphVecDestructor AzInlineGlyphVecDestructor;

enum AzInlineTextHitVecDestructorTag {
   AzInlineTextHitVecDestructorTag_DefaultRust,
   AzInlineTextHitVecDestructorTag_NoDestructor,
   AzInlineTextHitVecDestructorTag_External,
};
typedef enum AzInlineTextHitVecDestructorTag AzInlineTextHitVecDestructorTag;

struct AzInlineTextHitVecDestructorVariant_DefaultRust { AzInlineTextHitVecDestructorTag tag; };
typedef struct AzInlineTextHitVecDestructorVariant_DefaultRust AzInlineTextHitVecDestructorVariant_DefaultRust;
struct AzInlineTextHitVecDestructorVariant_NoDestructor { AzInlineTextHitVecDestructorTag tag; };
typedef struct AzInlineTextHitVecDestructorVariant_NoDestructor AzInlineTextHitVecDestructorVariant_NoDestructor;
struct AzInlineTextHitVecDestructorVariant_External { AzInlineTextHitVecDestructorTag tag; AzInlineTextHitVecDestructorType payload; };
typedef struct AzInlineTextHitVecDestructorVariant_External AzInlineTextHitVecDestructorVariant_External;
union AzInlineTextHitVecDestructor {
    AzInlineTextHitVecDestructorVariant_DefaultRust DefaultRust;
    AzInlineTextHitVecDestructorVariant_NoDestructor NoDestructor;
    AzInlineTextHitVecDestructorVariant_External External;
};
typedef union AzInlineTextHitVecDestructor AzInlineTextHitVecDestructor;

enum AzMonitorVecDestructorTag {
   AzMonitorVecDestructorTag_DefaultRust,
   AzMonitorVecDestructorTag_NoDestructor,
   AzMonitorVecDestructorTag_External,
};
typedef enum AzMonitorVecDestructorTag AzMonitorVecDestructorTag;

struct AzMonitorVecDestructorVariant_DefaultRust { AzMonitorVecDestructorTag tag; };
typedef struct AzMonitorVecDestructorVariant_DefaultRust AzMonitorVecDestructorVariant_DefaultRust;
struct AzMonitorVecDestructorVariant_NoDestructor { AzMonitorVecDestructorTag tag; };
typedef struct AzMonitorVecDestructorVariant_NoDestructor AzMonitorVecDestructorVariant_NoDestructor;
struct AzMonitorVecDestructorVariant_External { AzMonitorVecDestructorTag tag; AzMonitorVecDestructorType payload; };
typedef struct AzMonitorVecDestructorVariant_External AzMonitorVecDestructorVariant_External;
union AzMonitorVecDestructor {
    AzMonitorVecDestructorVariant_DefaultRust DefaultRust;
    AzMonitorVecDestructorVariant_NoDestructor NoDestructor;
    AzMonitorVecDestructorVariant_External External;
};
typedef union AzMonitorVecDestructor AzMonitorVecDestructor;

enum AzVideoModeVecDestructorTag {
   AzVideoModeVecDestructorTag_DefaultRust,
   AzVideoModeVecDestructorTag_NoDestructor,
   AzVideoModeVecDestructorTag_External,
};
typedef enum AzVideoModeVecDestructorTag AzVideoModeVecDestructorTag;

struct AzVideoModeVecDestructorVariant_DefaultRust { AzVideoModeVecDestructorTag tag; };
typedef struct AzVideoModeVecDestructorVariant_DefaultRust AzVideoModeVecDestructorVariant_DefaultRust;
struct AzVideoModeVecDestructorVariant_NoDestructor { AzVideoModeVecDestructorTag tag; };
typedef struct AzVideoModeVecDestructorVariant_NoDestructor AzVideoModeVecDestructorVariant_NoDestructor;
struct AzVideoModeVecDestructorVariant_External { AzVideoModeVecDestructorTag tag; AzVideoModeVecDestructorType payload; };
typedef struct AzVideoModeVecDestructorVariant_External AzVideoModeVecDestructorVariant_External;
union AzVideoModeVecDestructor {
    AzVideoModeVecDestructorVariant_DefaultRust DefaultRust;
    AzVideoModeVecDestructorVariant_NoDestructor NoDestructor;
    AzVideoModeVecDestructorVariant_External External;
};
typedef union AzVideoModeVecDestructor AzVideoModeVecDestructor;

enum AzDomVecDestructorTag {
   AzDomVecDestructorTag_DefaultRust,
   AzDomVecDestructorTag_NoDestructor,
   AzDomVecDestructorTag_External,
};
typedef enum AzDomVecDestructorTag AzDomVecDestructorTag;

struct AzDomVecDestructorVariant_DefaultRust { AzDomVecDestructorTag tag; };
typedef struct AzDomVecDestructorVariant_DefaultRust AzDomVecDestructorVariant_DefaultRust;
struct AzDomVecDestructorVariant_NoDestructor { AzDomVecDestructorTag tag; };
typedef struct AzDomVecDestructorVariant_NoDestructor AzDomVecDestructorVariant_NoDestructor;
struct AzDomVecDestructorVariant_External { AzDomVecDestructorTag tag; AzDomVecDestructorType payload; };
typedef struct AzDomVecDestructorVariant_External AzDomVecDestructorVariant_External;
union AzDomVecDestructor {
    AzDomVecDestructorVariant_DefaultRust DefaultRust;
    AzDomVecDestructorVariant_NoDestructor NoDestructor;
    AzDomVecDestructorVariant_External External;
};
typedef union AzDomVecDestructor AzDomVecDestructor;

enum AzIdOrClassVecDestructorTag {
   AzIdOrClassVecDestructorTag_DefaultRust,
   AzIdOrClassVecDestructorTag_NoDestructor,
   AzIdOrClassVecDestructorTag_External,
};
typedef enum AzIdOrClassVecDestructorTag AzIdOrClassVecDestructorTag;

struct AzIdOrClassVecDestructorVariant_DefaultRust { AzIdOrClassVecDestructorTag tag; };
typedef struct AzIdOrClassVecDestructorVariant_DefaultRust AzIdOrClassVecDestructorVariant_DefaultRust;
struct AzIdOrClassVecDestructorVariant_NoDestructor { AzIdOrClassVecDestructorTag tag; };
typedef struct AzIdOrClassVecDestructorVariant_NoDestructor AzIdOrClassVecDestructorVariant_NoDestructor;
struct AzIdOrClassVecDestructorVariant_External { AzIdOrClassVecDestructorTag tag; AzIdOrClassVecDestructorType payload; };
typedef struct AzIdOrClassVecDestructorVariant_External AzIdOrClassVecDestructorVariant_External;
union AzIdOrClassVecDestructor {
    AzIdOrClassVecDestructorVariant_DefaultRust DefaultRust;
    AzIdOrClassVecDestructorVariant_NoDestructor NoDestructor;
    AzIdOrClassVecDestructorVariant_External External;
};
typedef union AzIdOrClassVecDestructor AzIdOrClassVecDestructor;

enum AzNodeDataInlineCssPropertyVecDestructorTag {
   AzNodeDataInlineCssPropertyVecDestructorTag_DefaultRust,
   AzNodeDataInlineCssPropertyVecDestructorTag_NoDestructor,
   AzNodeDataInlineCssPropertyVecDestructorTag_External,
};
typedef enum AzNodeDataInlineCssPropertyVecDestructorTag AzNodeDataInlineCssPropertyVecDestructorTag;

struct AzNodeDataInlineCssPropertyVecDestructorVariant_DefaultRust { AzNodeDataInlineCssPropertyVecDestructorTag tag; };
typedef struct AzNodeDataInlineCssPropertyVecDestructorVariant_DefaultRust AzNodeDataInlineCssPropertyVecDestructorVariant_DefaultRust;
struct AzNodeDataInlineCssPropertyVecDestructorVariant_NoDestructor { AzNodeDataInlineCssPropertyVecDestructorTag tag; };
typedef struct AzNodeDataInlineCssPropertyVecDestructorVariant_NoDestructor AzNodeDataInlineCssPropertyVecDestructorVariant_NoDestructor;
struct AzNodeDataInlineCssPropertyVecDestructorVariant_External { AzNodeDataInlineCssPropertyVecDestructorTag tag; AzNodeDataInlineCssPropertyVecDestructorType payload; };
typedef struct AzNodeDataInlineCssPropertyVecDestructorVariant_External AzNodeDataInlineCssPropertyVecDestructorVariant_External;
union AzNodeDataInlineCssPropertyVecDestructor {
    AzNodeDataInlineCssPropertyVecDestructorVariant_DefaultRust DefaultRust;
    AzNodeDataInlineCssPropertyVecDestructorVariant_NoDestructor NoDestructor;
    AzNodeDataInlineCssPropertyVecDestructorVariant_External External;
};
typedef union AzNodeDataInlineCssPropertyVecDestructor AzNodeDataInlineCssPropertyVecDestructor;

enum AzStyleBackgroundContentVecDestructorTag {
   AzStyleBackgroundContentVecDestructorTag_DefaultRust,
   AzStyleBackgroundContentVecDestructorTag_NoDestructor,
   AzStyleBackgroundContentVecDestructorTag_External,
};
typedef enum AzStyleBackgroundContentVecDestructorTag AzStyleBackgroundContentVecDestructorTag;

struct AzStyleBackgroundContentVecDestructorVariant_DefaultRust { AzStyleBackgroundContentVecDestructorTag tag; };
typedef struct AzStyleBackgroundContentVecDestructorVariant_DefaultRust AzStyleBackgroundContentVecDestructorVariant_DefaultRust;
struct AzStyleBackgroundContentVecDestructorVariant_NoDestructor { AzStyleBackgroundContentVecDestructorTag tag; };
typedef struct AzStyleBackgroundContentVecDestructorVariant_NoDestructor AzStyleBackgroundContentVecDestructorVariant_NoDestructor;
struct AzStyleBackgroundContentVecDestructorVariant_External { AzStyleBackgroundContentVecDestructorTag tag; AzStyleBackgroundContentVecDestructorType payload; };
typedef struct AzStyleBackgroundContentVecDestructorVariant_External AzStyleBackgroundContentVecDestructorVariant_External;
union AzStyleBackgroundContentVecDestructor {
    AzStyleBackgroundContentVecDestructorVariant_DefaultRust DefaultRust;
    AzStyleBackgroundContentVecDestructorVariant_NoDestructor NoDestructor;
    AzStyleBackgroundContentVecDestructorVariant_External External;
};
typedef union AzStyleBackgroundContentVecDestructor AzStyleBackgroundContentVecDestructor;

enum AzStyleBackgroundPositionVecDestructorTag {
   AzStyleBackgroundPositionVecDestructorTag_DefaultRust,
   AzStyleBackgroundPositionVecDestructorTag_NoDestructor,
   AzStyleBackgroundPositionVecDestructorTag_External,
};
typedef enum AzStyleBackgroundPositionVecDestructorTag AzStyleBackgroundPositionVecDestructorTag;

struct AzStyleBackgroundPositionVecDestructorVariant_DefaultRust { AzStyleBackgroundPositionVecDestructorTag tag; };
typedef struct AzStyleBackgroundPositionVecDestructorVariant_DefaultRust AzStyleBackgroundPositionVecDestructorVariant_DefaultRust;
struct AzStyleBackgroundPositionVecDestructorVariant_NoDestructor { AzStyleBackgroundPositionVecDestructorTag tag; };
typedef struct AzStyleBackgroundPositionVecDestructorVariant_NoDestructor AzStyleBackgroundPositionVecDestructorVariant_NoDestructor;
struct AzStyleBackgroundPositionVecDestructorVariant_External { AzStyleBackgroundPositionVecDestructorTag tag; AzStyleBackgroundPositionVecDestructorType payload; };
typedef struct AzStyleBackgroundPositionVecDestructorVariant_External AzStyleBackgroundPositionVecDestructorVariant_External;
union AzStyleBackgroundPositionVecDestructor {
    AzStyleBackgroundPositionVecDestructorVariant_DefaultRust DefaultRust;
    AzStyleBackgroundPositionVecDestructorVariant_NoDestructor NoDestructor;
    AzStyleBackgroundPositionVecDestructorVariant_External External;
};
typedef union AzStyleBackgroundPositionVecDestructor AzStyleBackgroundPositionVecDestructor;

enum AzStyleBackgroundRepeatVecDestructorTag {
   AzStyleBackgroundRepeatVecDestructorTag_DefaultRust,
   AzStyleBackgroundRepeatVecDestructorTag_NoDestructor,
   AzStyleBackgroundRepeatVecDestructorTag_External,
};
typedef enum AzStyleBackgroundRepeatVecDestructorTag AzStyleBackgroundRepeatVecDestructorTag;

struct AzStyleBackgroundRepeatVecDestructorVariant_DefaultRust { AzStyleBackgroundRepeatVecDestructorTag tag; };
typedef struct AzStyleBackgroundRepeatVecDestructorVariant_DefaultRust AzStyleBackgroundRepeatVecDestructorVariant_DefaultRust;
struct AzStyleBackgroundRepeatVecDestructorVariant_NoDestructor { AzStyleBackgroundRepeatVecDestructorTag tag; };
typedef struct AzStyleBackgroundRepeatVecDestructorVariant_NoDestructor AzStyleBackgroundRepeatVecDestructorVariant_NoDestructor;
struct AzStyleBackgroundRepeatVecDestructorVariant_External { AzStyleBackgroundRepeatVecDestructorTag tag; AzStyleBackgroundRepeatVecDestructorType payload; };
typedef struct AzStyleBackgroundRepeatVecDestructorVariant_External AzStyleBackgroundRepeatVecDestructorVariant_External;
union AzStyleBackgroundRepeatVecDestructor {
    AzStyleBackgroundRepeatVecDestructorVariant_DefaultRust DefaultRust;
    AzStyleBackgroundRepeatVecDestructorVariant_NoDestructor NoDestructor;
    AzStyleBackgroundRepeatVecDestructorVariant_External External;
};
typedef union AzStyleBackgroundRepeatVecDestructor AzStyleBackgroundRepeatVecDestructor;

enum AzStyleBackgroundSizeVecDestructorTag {
   AzStyleBackgroundSizeVecDestructorTag_DefaultRust,
   AzStyleBackgroundSizeVecDestructorTag_NoDestructor,
   AzStyleBackgroundSizeVecDestructorTag_External,
};
typedef enum AzStyleBackgroundSizeVecDestructorTag AzStyleBackgroundSizeVecDestructorTag;

struct AzStyleBackgroundSizeVecDestructorVariant_DefaultRust { AzStyleBackgroundSizeVecDestructorTag tag; };
typedef struct AzStyleBackgroundSizeVecDestructorVariant_DefaultRust AzStyleBackgroundSizeVecDestructorVariant_DefaultRust;
struct AzStyleBackgroundSizeVecDestructorVariant_NoDestructor { AzStyleBackgroundSizeVecDestructorTag tag; };
typedef struct AzStyleBackgroundSizeVecDestructorVariant_NoDestructor AzStyleBackgroundSizeVecDestructorVariant_NoDestructor;
struct AzStyleBackgroundSizeVecDestructorVariant_External { AzStyleBackgroundSizeVecDestructorTag tag; AzStyleBackgroundSizeVecDestructorType payload; };
typedef struct AzStyleBackgroundSizeVecDestructorVariant_External AzStyleBackgroundSizeVecDestructorVariant_External;
union AzStyleBackgroundSizeVecDestructor {
    AzStyleBackgroundSizeVecDestructorVariant_DefaultRust DefaultRust;
    AzStyleBackgroundSizeVecDestructorVariant_NoDestructor NoDestructor;
    AzStyleBackgroundSizeVecDestructorVariant_External External;
};
typedef union AzStyleBackgroundSizeVecDestructor AzStyleBackgroundSizeVecDestructor;

enum AzStyleTransformVecDestructorTag {
   AzStyleTransformVecDestructorTag_DefaultRust,
   AzStyleTransformVecDestructorTag_NoDestructor,
   AzStyleTransformVecDestructorTag_External,
};
typedef enum AzStyleTransformVecDestructorTag AzStyleTransformVecDestructorTag;

struct AzStyleTransformVecDestructorVariant_DefaultRust { AzStyleTransformVecDestructorTag tag; };
typedef struct AzStyleTransformVecDestructorVariant_DefaultRust AzStyleTransformVecDestructorVariant_DefaultRust;
struct AzStyleTransformVecDestructorVariant_NoDestructor { AzStyleTransformVecDestructorTag tag; };
typedef struct AzStyleTransformVecDestructorVariant_NoDestructor AzStyleTransformVecDestructorVariant_NoDestructor;
struct AzStyleTransformVecDestructorVariant_External { AzStyleTransformVecDestructorTag tag; AzStyleTransformVecDestructorType payload; };
typedef struct AzStyleTransformVecDestructorVariant_External AzStyleTransformVecDestructorVariant_External;
union AzStyleTransformVecDestructor {
    AzStyleTransformVecDestructorVariant_DefaultRust DefaultRust;
    AzStyleTransformVecDestructorVariant_NoDestructor NoDestructor;
    AzStyleTransformVecDestructorVariant_External External;
};
typedef union AzStyleTransformVecDestructor AzStyleTransformVecDestructor;

enum AzCssPropertyVecDestructorTag {
   AzCssPropertyVecDestructorTag_DefaultRust,
   AzCssPropertyVecDestructorTag_NoDestructor,
   AzCssPropertyVecDestructorTag_External,
};
typedef enum AzCssPropertyVecDestructorTag AzCssPropertyVecDestructorTag;

struct AzCssPropertyVecDestructorVariant_DefaultRust { AzCssPropertyVecDestructorTag tag; };
typedef struct AzCssPropertyVecDestructorVariant_DefaultRust AzCssPropertyVecDestructorVariant_DefaultRust;
struct AzCssPropertyVecDestructorVariant_NoDestructor { AzCssPropertyVecDestructorTag tag; };
typedef struct AzCssPropertyVecDestructorVariant_NoDestructor AzCssPropertyVecDestructorVariant_NoDestructor;
struct AzCssPropertyVecDestructorVariant_External { AzCssPropertyVecDestructorTag tag; AzCssPropertyVecDestructorType payload; };
typedef struct AzCssPropertyVecDestructorVariant_External AzCssPropertyVecDestructorVariant_External;
union AzCssPropertyVecDestructor {
    AzCssPropertyVecDestructorVariant_DefaultRust DefaultRust;
    AzCssPropertyVecDestructorVariant_NoDestructor NoDestructor;
    AzCssPropertyVecDestructorVariant_External External;
};
typedef union AzCssPropertyVecDestructor AzCssPropertyVecDestructor;

enum AzSvgMultiPolygonVecDestructorTag {
   AzSvgMultiPolygonVecDestructorTag_DefaultRust,
   AzSvgMultiPolygonVecDestructorTag_NoDestructor,
   AzSvgMultiPolygonVecDestructorTag_External,
};
typedef enum AzSvgMultiPolygonVecDestructorTag AzSvgMultiPolygonVecDestructorTag;

struct AzSvgMultiPolygonVecDestructorVariant_DefaultRust { AzSvgMultiPolygonVecDestructorTag tag; };
typedef struct AzSvgMultiPolygonVecDestructorVariant_DefaultRust AzSvgMultiPolygonVecDestructorVariant_DefaultRust;
struct AzSvgMultiPolygonVecDestructorVariant_NoDestructor { AzSvgMultiPolygonVecDestructorTag tag; };
typedef struct AzSvgMultiPolygonVecDestructorVariant_NoDestructor AzSvgMultiPolygonVecDestructorVariant_NoDestructor;
struct AzSvgMultiPolygonVecDestructorVariant_External { AzSvgMultiPolygonVecDestructorTag tag; AzSvgMultiPolygonVecDestructorType payload; };
typedef struct AzSvgMultiPolygonVecDestructorVariant_External AzSvgMultiPolygonVecDestructorVariant_External;
union AzSvgMultiPolygonVecDestructor {
    AzSvgMultiPolygonVecDestructorVariant_DefaultRust DefaultRust;
    AzSvgMultiPolygonVecDestructorVariant_NoDestructor NoDestructor;
    AzSvgMultiPolygonVecDestructorVariant_External External;
};
typedef union AzSvgMultiPolygonVecDestructor AzSvgMultiPolygonVecDestructor;

enum AzSvgPathVecDestructorTag {
   AzSvgPathVecDestructorTag_DefaultRust,
   AzSvgPathVecDestructorTag_NoDestructor,
   AzSvgPathVecDestructorTag_External,
};
typedef enum AzSvgPathVecDestructorTag AzSvgPathVecDestructorTag;

struct AzSvgPathVecDestructorVariant_DefaultRust { AzSvgPathVecDestructorTag tag; };
typedef struct AzSvgPathVecDestructorVariant_DefaultRust AzSvgPathVecDestructorVariant_DefaultRust;
struct AzSvgPathVecDestructorVariant_NoDestructor { AzSvgPathVecDestructorTag tag; };
typedef struct AzSvgPathVecDestructorVariant_NoDestructor AzSvgPathVecDestructorVariant_NoDestructor;
struct AzSvgPathVecDestructorVariant_External { AzSvgPathVecDestructorTag tag; AzSvgPathVecDestructorType payload; };
typedef struct AzSvgPathVecDestructorVariant_External AzSvgPathVecDestructorVariant_External;
union AzSvgPathVecDestructor {
    AzSvgPathVecDestructorVariant_DefaultRust DefaultRust;
    AzSvgPathVecDestructorVariant_NoDestructor NoDestructor;
    AzSvgPathVecDestructorVariant_External External;
};
typedef union AzSvgPathVecDestructor AzSvgPathVecDestructor;

enum AzVertexAttributeVecDestructorTag {
   AzVertexAttributeVecDestructorTag_DefaultRust,
   AzVertexAttributeVecDestructorTag_NoDestructor,
   AzVertexAttributeVecDestructorTag_External,
};
typedef enum AzVertexAttributeVecDestructorTag AzVertexAttributeVecDestructorTag;

struct AzVertexAttributeVecDestructorVariant_DefaultRust { AzVertexAttributeVecDestructorTag tag; };
typedef struct AzVertexAttributeVecDestructorVariant_DefaultRust AzVertexAttributeVecDestructorVariant_DefaultRust;
struct AzVertexAttributeVecDestructorVariant_NoDestructor { AzVertexAttributeVecDestructorTag tag; };
typedef struct AzVertexAttributeVecDestructorVariant_NoDestructor AzVertexAttributeVecDestructorVariant_NoDestructor;
struct AzVertexAttributeVecDestructorVariant_External { AzVertexAttributeVecDestructorTag tag; AzVertexAttributeVecDestructorType payload; };
typedef struct AzVertexAttributeVecDestructorVariant_External AzVertexAttributeVecDestructorVariant_External;
union AzVertexAttributeVecDestructor {
    AzVertexAttributeVecDestructorVariant_DefaultRust DefaultRust;
    AzVertexAttributeVecDestructorVariant_NoDestructor NoDestructor;
    AzVertexAttributeVecDestructorVariant_External External;
};
typedef union AzVertexAttributeVecDestructor AzVertexAttributeVecDestructor;

enum AzSvgPathElementVecDestructorTag {
   AzSvgPathElementVecDestructorTag_DefaultRust,
   AzSvgPathElementVecDestructorTag_NoDestructor,
   AzSvgPathElementVecDestructorTag_External,
};
typedef enum AzSvgPathElementVecDestructorTag AzSvgPathElementVecDestructorTag;

struct AzSvgPathElementVecDestructorVariant_DefaultRust { AzSvgPathElementVecDestructorTag tag; };
typedef struct AzSvgPathElementVecDestructorVariant_DefaultRust AzSvgPathElementVecDestructorVariant_DefaultRust;
struct AzSvgPathElementVecDestructorVariant_NoDestructor { AzSvgPathElementVecDestructorTag tag; };
typedef struct AzSvgPathElementVecDestructorVariant_NoDestructor AzSvgPathElementVecDestructorVariant_NoDestructor;
struct AzSvgPathElementVecDestructorVariant_External { AzSvgPathElementVecDestructorTag tag; AzSvgPathElementVecDestructorType payload; };
typedef struct AzSvgPathElementVecDestructorVariant_External AzSvgPathElementVecDestructorVariant_External;
union AzSvgPathElementVecDestructor {
    AzSvgPathElementVecDestructorVariant_DefaultRust DefaultRust;
    AzSvgPathElementVecDestructorVariant_NoDestructor NoDestructor;
    AzSvgPathElementVecDestructorVariant_External External;
};
typedef union AzSvgPathElementVecDestructor AzSvgPathElementVecDestructor;

enum AzSvgVertexVecDestructorTag {
   AzSvgVertexVecDestructorTag_DefaultRust,
   AzSvgVertexVecDestructorTag_NoDestructor,
   AzSvgVertexVecDestructorTag_External,
};
typedef enum AzSvgVertexVecDestructorTag AzSvgVertexVecDestructorTag;

struct AzSvgVertexVecDestructorVariant_DefaultRust { AzSvgVertexVecDestructorTag tag; };
typedef struct AzSvgVertexVecDestructorVariant_DefaultRust AzSvgVertexVecDestructorVariant_DefaultRust;
struct AzSvgVertexVecDestructorVariant_NoDestructor { AzSvgVertexVecDestructorTag tag; };
typedef struct AzSvgVertexVecDestructorVariant_NoDestructor AzSvgVertexVecDestructorVariant_NoDestructor;
struct AzSvgVertexVecDestructorVariant_External { AzSvgVertexVecDestructorTag tag; AzSvgVertexVecDestructorType payload; };
typedef struct AzSvgVertexVecDestructorVariant_External AzSvgVertexVecDestructorVariant_External;
union AzSvgVertexVecDestructor {
    AzSvgVertexVecDestructorVariant_DefaultRust DefaultRust;
    AzSvgVertexVecDestructorVariant_NoDestructor NoDestructor;
    AzSvgVertexVecDestructorVariant_External External;
};
typedef union AzSvgVertexVecDestructor AzSvgVertexVecDestructor;

enum AzU32VecDestructorTag {
   AzU32VecDestructorTag_DefaultRust,
   AzU32VecDestructorTag_NoDestructor,
   AzU32VecDestructorTag_External,
};
typedef enum AzU32VecDestructorTag AzU32VecDestructorTag;

struct AzU32VecDestructorVariant_DefaultRust { AzU32VecDestructorTag tag; };
typedef struct AzU32VecDestructorVariant_DefaultRust AzU32VecDestructorVariant_DefaultRust;
struct AzU32VecDestructorVariant_NoDestructor { AzU32VecDestructorTag tag; };
typedef struct AzU32VecDestructorVariant_NoDestructor AzU32VecDestructorVariant_NoDestructor;
struct AzU32VecDestructorVariant_External { AzU32VecDestructorTag tag; AzU32VecDestructorType payload; };
typedef struct AzU32VecDestructorVariant_External AzU32VecDestructorVariant_External;
union AzU32VecDestructor {
    AzU32VecDestructorVariant_DefaultRust DefaultRust;
    AzU32VecDestructorVariant_NoDestructor NoDestructor;
    AzU32VecDestructorVariant_External External;
};
typedef union AzU32VecDestructor AzU32VecDestructor;

enum AzXWindowTypeVecDestructorTag {
   AzXWindowTypeVecDestructorTag_DefaultRust,
   AzXWindowTypeVecDestructorTag_NoDestructor,
   AzXWindowTypeVecDestructorTag_External,
};
typedef enum AzXWindowTypeVecDestructorTag AzXWindowTypeVecDestructorTag;

struct AzXWindowTypeVecDestructorVariant_DefaultRust { AzXWindowTypeVecDestructorTag tag; };
typedef struct AzXWindowTypeVecDestructorVariant_DefaultRust AzXWindowTypeVecDestructorVariant_DefaultRust;
struct AzXWindowTypeVecDestructorVariant_NoDestructor { AzXWindowTypeVecDestructorTag tag; };
typedef struct AzXWindowTypeVecDestructorVariant_NoDestructor AzXWindowTypeVecDestructorVariant_NoDestructor;
struct AzXWindowTypeVecDestructorVariant_External { AzXWindowTypeVecDestructorTag tag; AzXWindowTypeVecDestructorType payload; };
typedef struct AzXWindowTypeVecDestructorVariant_External AzXWindowTypeVecDestructorVariant_External;
union AzXWindowTypeVecDestructor {
    AzXWindowTypeVecDestructorVariant_DefaultRust DefaultRust;
    AzXWindowTypeVecDestructorVariant_NoDestructor NoDestructor;
    AzXWindowTypeVecDestructorVariant_External External;
};
typedef union AzXWindowTypeVecDestructor AzXWindowTypeVecDestructor;

enum AzVirtualKeyCodeVecDestructorTag {
   AzVirtualKeyCodeVecDestructorTag_DefaultRust,
   AzVirtualKeyCodeVecDestructorTag_NoDestructor,
   AzVirtualKeyCodeVecDestructorTag_External,
};
typedef enum AzVirtualKeyCodeVecDestructorTag AzVirtualKeyCodeVecDestructorTag;

struct AzVirtualKeyCodeVecDestructorVariant_DefaultRust { AzVirtualKeyCodeVecDestructorTag tag; };
typedef struct AzVirtualKeyCodeVecDestructorVariant_DefaultRust AzVirtualKeyCodeVecDestructorVariant_DefaultRust;
struct AzVirtualKeyCodeVecDestructorVariant_NoDestructor { AzVirtualKeyCodeVecDestructorTag tag; };
typedef struct AzVirtualKeyCodeVecDestructorVariant_NoDestructor AzVirtualKeyCodeVecDestructorVariant_NoDestructor;
struct AzVirtualKeyCodeVecDestructorVariant_External { AzVirtualKeyCodeVecDestructorTag tag; AzVirtualKeyCodeVecDestructorType payload; };
typedef struct AzVirtualKeyCodeVecDestructorVariant_External AzVirtualKeyCodeVecDestructorVariant_External;
union AzVirtualKeyCodeVecDestructor {
    AzVirtualKeyCodeVecDestructorVariant_DefaultRust DefaultRust;
    AzVirtualKeyCodeVecDestructorVariant_NoDestructor NoDestructor;
    AzVirtualKeyCodeVecDestructorVariant_External External;
};
typedef union AzVirtualKeyCodeVecDestructor AzVirtualKeyCodeVecDestructor;

enum AzCascadeInfoVecDestructorTag {
   AzCascadeInfoVecDestructorTag_DefaultRust,
   AzCascadeInfoVecDestructorTag_NoDestructor,
   AzCascadeInfoVecDestructorTag_External,
};
typedef enum AzCascadeInfoVecDestructorTag AzCascadeInfoVecDestructorTag;

struct AzCascadeInfoVecDestructorVariant_DefaultRust { AzCascadeInfoVecDestructorTag tag; };
typedef struct AzCascadeInfoVecDestructorVariant_DefaultRust AzCascadeInfoVecDestructorVariant_DefaultRust;
struct AzCascadeInfoVecDestructorVariant_NoDestructor { AzCascadeInfoVecDestructorTag tag; };
typedef struct AzCascadeInfoVecDestructorVariant_NoDestructor AzCascadeInfoVecDestructorVariant_NoDestructor;
struct AzCascadeInfoVecDestructorVariant_External { AzCascadeInfoVecDestructorTag tag; AzCascadeInfoVecDestructorType payload; };
typedef struct AzCascadeInfoVecDestructorVariant_External AzCascadeInfoVecDestructorVariant_External;
union AzCascadeInfoVecDestructor {
    AzCascadeInfoVecDestructorVariant_DefaultRust DefaultRust;
    AzCascadeInfoVecDestructorVariant_NoDestructor NoDestructor;
    AzCascadeInfoVecDestructorVariant_External External;
};
typedef union AzCascadeInfoVecDestructor AzCascadeInfoVecDestructor;

enum AzScanCodeVecDestructorTag {
   AzScanCodeVecDestructorTag_DefaultRust,
   AzScanCodeVecDestructorTag_NoDestructor,
   AzScanCodeVecDestructorTag_External,
};
typedef enum AzScanCodeVecDestructorTag AzScanCodeVecDestructorTag;

struct AzScanCodeVecDestructorVariant_DefaultRust { AzScanCodeVecDestructorTag tag; };
typedef struct AzScanCodeVecDestructorVariant_DefaultRust AzScanCodeVecDestructorVariant_DefaultRust;
struct AzScanCodeVecDestructorVariant_NoDestructor { AzScanCodeVecDestructorTag tag; };
typedef struct AzScanCodeVecDestructorVariant_NoDestructor AzScanCodeVecDestructorVariant_NoDestructor;
struct AzScanCodeVecDestructorVariant_External { AzScanCodeVecDestructorTag tag; AzScanCodeVecDestructorType payload; };
typedef struct AzScanCodeVecDestructorVariant_External AzScanCodeVecDestructorVariant_External;
union AzScanCodeVecDestructor {
    AzScanCodeVecDestructorVariant_DefaultRust DefaultRust;
    AzScanCodeVecDestructorVariant_NoDestructor NoDestructor;
    AzScanCodeVecDestructorVariant_External External;
};
typedef union AzScanCodeVecDestructor AzScanCodeVecDestructor;

enum AzCssDeclarationVecDestructorTag {
   AzCssDeclarationVecDestructorTag_DefaultRust,
   AzCssDeclarationVecDestructorTag_NoDestructor,
   AzCssDeclarationVecDestructorTag_External,
};
typedef enum AzCssDeclarationVecDestructorTag AzCssDeclarationVecDestructorTag;

struct AzCssDeclarationVecDestructorVariant_DefaultRust { AzCssDeclarationVecDestructorTag tag; };
typedef struct AzCssDeclarationVecDestructorVariant_DefaultRust AzCssDeclarationVecDestructorVariant_DefaultRust;
struct AzCssDeclarationVecDestructorVariant_NoDestructor { AzCssDeclarationVecDestructorTag tag; };
typedef struct AzCssDeclarationVecDestructorVariant_NoDestructor AzCssDeclarationVecDestructorVariant_NoDestructor;
struct AzCssDeclarationVecDestructorVariant_External { AzCssDeclarationVecDestructorTag tag; AzCssDeclarationVecDestructorType payload; };
typedef struct AzCssDeclarationVecDestructorVariant_External AzCssDeclarationVecDestructorVariant_External;
union AzCssDeclarationVecDestructor {
    AzCssDeclarationVecDestructorVariant_DefaultRust DefaultRust;
    AzCssDeclarationVecDestructorVariant_NoDestructor NoDestructor;
    AzCssDeclarationVecDestructorVariant_External External;
};
typedef union AzCssDeclarationVecDestructor AzCssDeclarationVecDestructor;

enum AzCssPathSelectorVecDestructorTag {
   AzCssPathSelectorVecDestructorTag_DefaultRust,
   AzCssPathSelectorVecDestructorTag_NoDestructor,
   AzCssPathSelectorVecDestructorTag_External,
};
typedef enum AzCssPathSelectorVecDestructorTag AzCssPathSelectorVecDestructorTag;

struct AzCssPathSelectorVecDestructorVariant_DefaultRust { AzCssPathSelectorVecDestructorTag tag; };
typedef struct AzCssPathSelectorVecDestructorVariant_DefaultRust AzCssPathSelectorVecDestructorVariant_DefaultRust;
struct AzCssPathSelectorVecDestructorVariant_NoDestructor { AzCssPathSelectorVecDestructorTag tag; };
typedef struct AzCssPathSelectorVecDestructorVariant_NoDestructor AzCssPathSelectorVecDestructorVariant_NoDestructor;
struct AzCssPathSelectorVecDestructorVariant_External { AzCssPathSelectorVecDestructorTag tag; AzCssPathSelectorVecDestructorType payload; };
typedef struct AzCssPathSelectorVecDestructorVariant_External AzCssPathSelectorVecDestructorVariant_External;
union AzCssPathSelectorVecDestructor {
    AzCssPathSelectorVecDestructorVariant_DefaultRust DefaultRust;
    AzCssPathSelectorVecDestructorVariant_NoDestructor NoDestructor;
    AzCssPathSelectorVecDestructorVariant_External External;
};
typedef union AzCssPathSelectorVecDestructor AzCssPathSelectorVecDestructor;

enum AzStylesheetVecDestructorTag {
   AzStylesheetVecDestructorTag_DefaultRust,
   AzStylesheetVecDestructorTag_NoDestructor,
   AzStylesheetVecDestructorTag_External,
};
typedef enum AzStylesheetVecDestructorTag AzStylesheetVecDestructorTag;

struct AzStylesheetVecDestructorVariant_DefaultRust { AzStylesheetVecDestructorTag tag; };
typedef struct AzStylesheetVecDestructorVariant_DefaultRust AzStylesheetVecDestructorVariant_DefaultRust;
struct AzStylesheetVecDestructorVariant_NoDestructor { AzStylesheetVecDestructorTag tag; };
typedef struct AzStylesheetVecDestructorVariant_NoDestructor AzStylesheetVecDestructorVariant_NoDestructor;
struct AzStylesheetVecDestructorVariant_External { AzStylesheetVecDestructorTag tag; AzStylesheetVecDestructorType payload; };
typedef struct AzStylesheetVecDestructorVariant_External AzStylesheetVecDestructorVariant_External;
union AzStylesheetVecDestructor {
    AzStylesheetVecDestructorVariant_DefaultRust DefaultRust;
    AzStylesheetVecDestructorVariant_NoDestructor NoDestructor;
    AzStylesheetVecDestructorVariant_External External;
};
typedef union AzStylesheetVecDestructor AzStylesheetVecDestructor;

enum AzCssRuleBlockVecDestructorTag {
   AzCssRuleBlockVecDestructorTag_DefaultRust,
   AzCssRuleBlockVecDestructorTag_NoDestructor,
   AzCssRuleBlockVecDestructorTag_External,
};
typedef enum AzCssRuleBlockVecDestructorTag AzCssRuleBlockVecDestructorTag;

struct AzCssRuleBlockVecDestructorVariant_DefaultRust { AzCssRuleBlockVecDestructorTag tag; };
typedef struct AzCssRuleBlockVecDestructorVariant_DefaultRust AzCssRuleBlockVecDestructorVariant_DefaultRust;
struct AzCssRuleBlockVecDestructorVariant_NoDestructor { AzCssRuleBlockVecDestructorTag tag; };
typedef struct AzCssRuleBlockVecDestructorVariant_NoDestructor AzCssRuleBlockVecDestructorVariant_NoDestructor;
struct AzCssRuleBlockVecDestructorVariant_External { AzCssRuleBlockVecDestructorTag tag; AzCssRuleBlockVecDestructorType payload; };
typedef struct AzCssRuleBlockVecDestructorVariant_External AzCssRuleBlockVecDestructorVariant_External;
union AzCssRuleBlockVecDestructor {
    AzCssRuleBlockVecDestructorVariant_DefaultRust DefaultRust;
    AzCssRuleBlockVecDestructorVariant_NoDestructor NoDestructor;
    AzCssRuleBlockVecDestructorVariant_External External;
};
typedef union AzCssRuleBlockVecDestructor AzCssRuleBlockVecDestructor;

enum AzF32VecDestructorTag {
   AzF32VecDestructorTag_DefaultRust,
   AzF32VecDestructorTag_NoDestructor,
   AzF32VecDestructorTag_External,
};
typedef enum AzF32VecDestructorTag AzF32VecDestructorTag;

struct AzF32VecDestructorVariant_DefaultRust { AzF32VecDestructorTag tag; };
typedef struct AzF32VecDestructorVariant_DefaultRust AzF32VecDestructorVariant_DefaultRust;
struct AzF32VecDestructorVariant_NoDestructor { AzF32VecDestructorTag tag; };
typedef struct AzF32VecDestructorVariant_NoDestructor AzF32VecDestructorVariant_NoDestructor;
struct AzF32VecDestructorVariant_External { AzF32VecDestructorTag tag; AzF32VecDestructorType payload; };
typedef struct AzF32VecDestructorVariant_External AzF32VecDestructorVariant_External;
union AzF32VecDestructor {
    AzF32VecDestructorVariant_DefaultRust DefaultRust;
    AzF32VecDestructorVariant_NoDestructor NoDestructor;
    AzF32VecDestructorVariant_External External;
};
typedef union AzF32VecDestructor AzF32VecDestructor;

enum AzU16VecDestructorTag {
   AzU16VecDestructorTag_DefaultRust,
   AzU16VecDestructorTag_NoDestructor,
   AzU16VecDestructorTag_External,
};
typedef enum AzU16VecDestructorTag AzU16VecDestructorTag;

struct AzU16VecDestructorVariant_DefaultRust { AzU16VecDestructorTag tag; };
typedef struct AzU16VecDestructorVariant_DefaultRust AzU16VecDestructorVariant_DefaultRust;
struct AzU16VecDestructorVariant_NoDestructor { AzU16VecDestructorTag tag; };
typedef struct AzU16VecDestructorVariant_NoDestructor AzU16VecDestructorVariant_NoDestructor;
struct AzU16VecDestructorVariant_External { AzU16VecDestructorTag tag; AzU16VecDestructorType payload; };
typedef struct AzU16VecDestructorVariant_External AzU16VecDestructorVariant_External;
union AzU16VecDestructor {
    AzU16VecDestructorVariant_DefaultRust DefaultRust;
    AzU16VecDestructorVariant_NoDestructor NoDestructor;
    AzU16VecDestructorVariant_External External;
};
typedef union AzU16VecDestructor AzU16VecDestructor;

enum AzU8VecDestructorTag {
   AzU8VecDestructorTag_DefaultRust,
   AzU8VecDestructorTag_NoDestructor,
   AzU8VecDestructorTag_External,
};
typedef enum AzU8VecDestructorTag AzU8VecDestructorTag;

struct AzU8VecDestructorVariant_DefaultRust { AzU8VecDestructorTag tag; };
typedef struct AzU8VecDestructorVariant_DefaultRust AzU8VecDestructorVariant_DefaultRust;
struct AzU8VecDestructorVariant_NoDestructor { AzU8VecDestructorTag tag; };
typedef struct AzU8VecDestructorVariant_NoDestructor AzU8VecDestructorVariant_NoDestructor;
struct AzU8VecDestructorVariant_External { AzU8VecDestructorTag tag; AzU8VecDestructorType payload; };
typedef struct AzU8VecDestructorVariant_External AzU8VecDestructorVariant_External;
union AzU8VecDestructor {
    AzU8VecDestructorVariant_DefaultRust DefaultRust;
    AzU8VecDestructorVariant_NoDestructor NoDestructor;
    AzU8VecDestructorVariant_External External;
};
typedef union AzU8VecDestructor AzU8VecDestructor;

enum AzCallbackDataVecDestructorTag {
   AzCallbackDataVecDestructorTag_DefaultRust,
   AzCallbackDataVecDestructorTag_NoDestructor,
   AzCallbackDataVecDestructorTag_External,
};
typedef enum AzCallbackDataVecDestructorTag AzCallbackDataVecDestructorTag;

struct AzCallbackDataVecDestructorVariant_DefaultRust { AzCallbackDataVecDestructorTag tag; };
typedef struct AzCallbackDataVecDestructorVariant_DefaultRust AzCallbackDataVecDestructorVariant_DefaultRust;
struct AzCallbackDataVecDestructorVariant_NoDestructor { AzCallbackDataVecDestructorTag tag; };
typedef struct AzCallbackDataVecDestructorVariant_NoDestructor AzCallbackDataVecDestructorVariant_NoDestructor;
struct AzCallbackDataVecDestructorVariant_External { AzCallbackDataVecDestructorTag tag; AzCallbackDataVecDestructorType payload; };
typedef struct AzCallbackDataVecDestructorVariant_External AzCallbackDataVecDestructorVariant_External;
union AzCallbackDataVecDestructor {
    AzCallbackDataVecDestructorVariant_DefaultRust DefaultRust;
    AzCallbackDataVecDestructorVariant_NoDestructor NoDestructor;
    AzCallbackDataVecDestructorVariant_External External;
};
typedef union AzCallbackDataVecDestructor AzCallbackDataVecDestructor;

enum AzDebugMessageVecDestructorTag {
   AzDebugMessageVecDestructorTag_DefaultRust,
   AzDebugMessageVecDestructorTag_NoDestructor,
   AzDebugMessageVecDestructorTag_External,
};
typedef enum AzDebugMessageVecDestructorTag AzDebugMessageVecDestructorTag;

struct AzDebugMessageVecDestructorVariant_DefaultRust { AzDebugMessageVecDestructorTag tag; };
typedef struct AzDebugMessageVecDestructorVariant_DefaultRust AzDebugMessageVecDestructorVariant_DefaultRust;
struct AzDebugMessageVecDestructorVariant_NoDestructor { AzDebugMessageVecDestructorTag tag; };
typedef struct AzDebugMessageVecDestructorVariant_NoDestructor AzDebugMessageVecDestructorVariant_NoDestructor;
struct AzDebugMessageVecDestructorVariant_External { AzDebugMessageVecDestructorTag tag; AzDebugMessageVecDestructorType payload; };
typedef struct AzDebugMessageVecDestructorVariant_External AzDebugMessageVecDestructorVariant_External;
union AzDebugMessageVecDestructor {
    AzDebugMessageVecDestructorVariant_DefaultRust DefaultRust;
    AzDebugMessageVecDestructorVariant_NoDestructor NoDestructor;
    AzDebugMessageVecDestructorVariant_External External;
};
typedef union AzDebugMessageVecDestructor AzDebugMessageVecDestructor;

enum AzGLuintVecDestructorTag {
   AzGLuintVecDestructorTag_DefaultRust,
   AzGLuintVecDestructorTag_NoDestructor,
   AzGLuintVecDestructorTag_External,
};
typedef enum AzGLuintVecDestructorTag AzGLuintVecDestructorTag;

struct AzGLuintVecDestructorVariant_DefaultRust { AzGLuintVecDestructorTag tag; };
typedef struct AzGLuintVecDestructorVariant_DefaultRust AzGLuintVecDestructorVariant_DefaultRust;
struct AzGLuintVecDestructorVariant_NoDestructor { AzGLuintVecDestructorTag tag; };
typedef struct AzGLuintVecDestructorVariant_NoDestructor AzGLuintVecDestructorVariant_NoDestructor;
struct AzGLuintVecDestructorVariant_External { AzGLuintVecDestructorTag tag; AzGLuintVecDestructorType payload; };
typedef struct AzGLuintVecDestructorVariant_External AzGLuintVecDestructorVariant_External;
union AzGLuintVecDestructor {
    AzGLuintVecDestructorVariant_DefaultRust DefaultRust;
    AzGLuintVecDestructorVariant_NoDestructor NoDestructor;
    AzGLuintVecDestructorVariant_External External;
};
typedef union AzGLuintVecDestructor AzGLuintVecDestructor;

enum AzGLintVecDestructorTag {
   AzGLintVecDestructorTag_DefaultRust,
   AzGLintVecDestructorTag_NoDestructor,
   AzGLintVecDestructorTag_External,
};
typedef enum AzGLintVecDestructorTag AzGLintVecDestructorTag;

struct AzGLintVecDestructorVariant_DefaultRust { AzGLintVecDestructorTag tag; };
typedef struct AzGLintVecDestructorVariant_DefaultRust AzGLintVecDestructorVariant_DefaultRust;
struct AzGLintVecDestructorVariant_NoDestructor { AzGLintVecDestructorTag tag; };
typedef struct AzGLintVecDestructorVariant_NoDestructor AzGLintVecDestructorVariant_NoDestructor;
struct AzGLintVecDestructorVariant_External { AzGLintVecDestructorTag tag; AzGLintVecDestructorType payload; };
typedef struct AzGLintVecDestructorVariant_External AzGLintVecDestructorVariant_External;
union AzGLintVecDestructor {
    AzGLintVecDestructorVariant_DefaultRust DefaultRust;
    AzGLintVecDestructorVariant_NoDestructor NoDestructor;
    AzGLintVecDestructorVariant_External External;
};
typedef union AzGLintVecDestructor AzGLintVecDestructor;

enum AzStringVecDestructorTag {
   AzStringVecDestructorTag_DefaultRust,
   AzStringVecDestructorTag_NoDestructor,
   AzStringVecDestructorTag_External,
};
typedef enum AzStringVecDestructorTag AzStringVecDestructorTag;

struct AzStringVecDestructorVariant_DefaultRust { AzStringVecDestructorTag tag; };
typedef struct AzStringVecDestructorVariant_DefaultRust AzStringVecDestructorVariant_DefaultRust;
struct AzStringVecDestructorVariant_NoDestructor { AzStringVecDestructorTag tag; };
typedef struct AzStringVecDestructorVariant_NoDestructor AzStringVecDestructorVariant_NoDestructor;
struct AzStringVecDestructorVariant_External { AzStringVecDestructorTag tag; AzStringVecDestructorType payload; };
typedef struct AzStringVecDestructorVariant_External AzStringVecDestructorVariant_External;
union AzStringVecDestructor {
    AzStringVecDestructorVariant_DefaultRust DefaultRust;
    AzStringVecDestructorVariant_NoDestructor NoDestructor;
    AzStringVecDestructorVariant_External External;
};
typedef union AzStringVecDestructor AzStringVecDestructor;

enum AzStringPairVecDestructorTag {
   AzStringPairVecDestructorTag_DefaultRust,
   AzStringPairVecDestructorTag_NoDestructor,
   AzStringPairVecDestructorTag_External,
};
typedef enum AzStringPairVecDestructorTag AzStringPairVecDestructorTag;

struct AzStringPairVecDestructorVariant_DefaultRust { AzStringPairVecDestructorTag tag; };
typedef struct AzStringPairVecDestructorVariant_DefaultRust AzStringPairVecDestructorVariant_DefaultRust;
struct AzStringPairVecDestructorVariant_NoDestructor { AzStringPairVecDestructorTag tag; };
typedef struct AzStringPairVecDestructorVariant_NoDestructor AzStringPairVecDestructorVariant_NoDestructor;
struct AzStringPairVecDestructorVariant_External { AzStringPairVecDestructorTag tag; AzStringPairVecDestructorType payload; };
typedef struct AzStringPairVecDestructorVariant_External AzStringPairVecDestructorVariant_External;
union AzStringPairVecDestructor {
    AzStringPairVecDestructorVariant_DefaultRust DefaultRust;
    AzStringPairVecDestructorVariant_NoDestructor NoDestructor;
    AzStringPairVecDestructorVariant_External External;
};
typedef union AzStringPairVecDestructor AzStringPairVecDestructor;

enum AzNormalizedLinearColorStopVecDestructorTag {
   AzNormalizedLinearColorStopVecDestructorTag_DefaultRust,
   AzNormalizedLinearColorStopVecDestructorTag_NoDestructor,
   AzNormalizedLinearColorStopVecDestructorTag_External,
};
typedef enum AzNormalizedLinearColorStopVecDestructorTag AzNormalizedLinearColorStopVecDestructorTag;

struct AzNormalizedLinearColorStopVecDestructorVariant_DefaultRust { AzNormalizedLinearColorStopVecDestructorTag tag; };
typedef struct AzNormalizedLinearColorStopVecDestructorVariant_DefaultRust AzNormalizedLinearColorStopVecDestructorVariant_DefaultRust;
struct AzNormalizedLinearColorStopVecDestructorVariant_NoDestructor { AzNormalizedLinearColorStopVecDestructorTag tag; };
typedef struct AzNormalizedLinearColorStopVecDestructorVariant_NoDestructor AzNormalizedLinearColorStopVecDestructorVariant_NoDestructor;
struct AzNormalizedLinearColorStopVecDestructorVariant_External { AzNormalizedLinearColorStopVecDestructorTag tag; AzNormalizedLinearColorStopVecDestructorType payload; };
typedef struct AzNormalizedLinearColorStopVecDestructorVariant_External AzNormalizedLinearColorStopVecDestructorVariant_External;
union AzNormalizedLinearColorStopVecDestructor {
    AzNormalizedLinearColorStopVecDestructorVariant_DefaultRust DefaultRust;
    AzNormalizedLinearColorStopVecDestructorVariant_NoDestructor NoDestructor;
    AzNormalizedLinearColorStopVecDestructorVariant_External External;
};
typedef union AzNormalizedLinearColorStopVecDestructor AzNormalizedLinearColorStopVecDestructor;

enum AzNormalizedRadialColorStopVecDestructorTag {
   AzNormalizedRadialColorStopVecDestructorTag_DefaultRust,
   AzNormalizedRadialColorStopVecDestructorTag_NoDestructor,
   AzNormalizedRadialColorStopVecDestructorTag_External,
};
typedef enum AzNormalizedRadialColorStopVecDestructorTag AzNormalizedRadialColorStopVecDestructorTag;

struct AzNormalizedRadialColorStopVecDestructorVariant_DefaultRust { AzNormalizedRadialColorStopVecDestructorTag tag; };
typedef struct AzNormalizedRadialColorStopVecDestructorVariant_DefaultRust AzNormalizedRadialColorStopVecDestructorVariant_DefaultRust;
struct AzNormalizedRadialColorStopVecDestructorVariant_NoDestructor { AzNormalizedRadialColorStopVecDestructorTag tag; };
typedef struct AzNormalizedRadialColorStopVecDestructorVariant_NoDestructor AzNormalizedRadialColorStopVecDestructorVariant_NoDestructor;
struct AzNormalizedRadialColorStopVecDestructorVariant_External { AzNormalizedRadialColorStopVecDestructorTag tag; AzNormalizedRadialColorStopVecDestructorType payload; };
typedef struct AzNormalizedRadialColorStopVecDestructorVariant_External AzNormalizedRadialColorStopVecDestructorVariant_External;
union AzNormalizedRadialColorStopVecDestructor {
    AzNormalizedRadialColorStopVecDestructorVariant_DefaultRust DefaultRust;
    AzNormalizedRadialColorStopVecDestructorVariant_NoDestructor NoDestructor;
    AzNormalizedRadialColorStopVecDestructorVariant_External External;
};
typedef union AzNormalizedRadialColorStopVecDestructor AzNormalizedRadialColorStopVecDestructor;

enum AzNodeIdVecDestructorTag {
   AzNodeIdVecDestructorTag_DefaultRust,
   AzNodeIdVecDestructorTag_NoDestructor,
   AzNodeIdVecDestructorTag_External,
};
typedef enum AzNodeIdVecDestructorTag AzNodeIdVecDestructorTag;

struct AzNodeIdVecDestructorVariant_DefaultRust { AzNodeIdVecDestructorTag tag; };
typedef struct AzNodeIdVecDestructorVariant_DefaultRust AzNodeIdVecDestructorVariant_DefaultRust;
struct AzNodeIdVecDestructorVariant_NoDestructor { AzNodeIdVecDestructorTag tag; };
typedef struct AzNodeIdVecDestructorVariant_NoDestructor AzNodeIdVecDestructorVariant_NoDestructor;
struct AzNodeIdVecDestructorVariant_External { AzNodeIdVecDestructorTag tag; AzNodeIdVecDestructorType payload; };
typedef struct AzNodeIdVecDestructorVariant_External AzNodeIdVecDestructorVariant_External;
union AzNodeIdVecDestructor {
    AzNodeIdVecDestructorVariant_DefaultRust DefaultRust;
    AzNodeIdVecDestructorVariant_NoDestructor NoDestructor;
    AzNodeIdVecDestructorVariant_External External;
};
typedef union AzNodeIdVecDestructor AzNodeIdVecDestructor;

enum AzNodeVecDestructorTag {
   AzNodeVecDestructorTag_DefaultRust,
   AzNodeVecDestructorTag_NoDestructor,
   AzNodeVecDestructorTag_External,
};
typedef enum AzNodeVecDestructorTag AzNodeVecDestructorTag;

struct AzNodeVecDestructorVariant_DefaultRust { AzNodeVecDestructorTag tag; };
typedef struct AzNodeVecDestructorVariant_DefaultRust AzNodeVecDestructorVariant_DefaultRust;
struct AzNodeVecDestructorVariant_NoDestructor { AzNodeVecDestructorTag tag; };
typedef struct AzNodeVecDestructorVariant_NoDestructor AzNodeVecDestructorVariant_NoDestructor;
struct AzNodeVecDestructorVariant_External { AzNodeVecDestructorTag tag; AzNodeVecDestructorType payload; };
typedef struct AzNodeVecDestructorVariant_External AzNodeVecDestructorVariant_External;
union AzNodeVecDestructor {
    AzNodeVecDestructorVariant_DefaultRust DefaultRust;
    AzNodeVecDestructorVariant_NoDestructor NoDestructor;
    AzNodeVecDestructorVariant_External External;
};
typedef union AzNodeVecDestructor AzNodeVecDestructor;

enum AzStyledNodeVecDestructorTag {
   AzStyledNodeVecDestructorTag_DefaultRust,
   AzStyledNodeVecDestructorTag_NoDestructor,
   AzStyledNodeVecDestructorTag_External,
};
typedef enum AzStyledNodeVecDestructorTag AzStyledNodeVecDestructorTag;

struct AzStyledNodeVecDestructorVariant_DefaultRust { AzStyledNodeVecDestructorTag tag; };
typedef struct AzStyledNodeVecDestructorVariant_DefaultRust AzStyledNodeVecDestructorVariant_DefaultRust;
struct AzStyledNodeVecDestructorVariant_NoDestructor { AzStyledNodeVecDestructorTag tag; };
typedef struct AzStyledNodeVecDestructorVariant_NoDestructor AzStyledNodeVecDestructorVariant_NoDestructor;
struct AzStyledNodeVecDestructorVariant_External { AzStyledNodeVecDestructorTag tag; AzStyledNodeVecDestructorType payload; };
typedef struct AzStyledNodeVecDestructorVariant_External AzStyledNodeVecDestructorVariant_External;
union AzStyledNodeVecDestructor {
    AzStyledNodeVecDestructorVariant_DefaultRust DefaultRust;
    AzStyledNodeVecDestructorVariant_NoDestructor NoDestructor;
    AzStyledNodeVecDestructorVariant_External External;
};
typedef union AzStyledNodeVecDestructor AzStyledNodeVecDestructor;

enum AzTagIdToNodeIdMappingVecDestructorTag {
   AzTagIdToNodeIdMappingVecDestructorTag_DefaultRust,
   AzTagIdToNodeIdMappingVecDestructorTag_NoDestructor,
   AzTagIdToNodeIdMappingVecDestructorTag_External,
};
typedef enum AzTagIdToNodeIdMappingVecDestructorTag AzTagIdToNodeIdMappingVecDestructorTag;

struct AzTagIdToNodeIdMappingVecDestructorVariant_DefaultRust { AzTagIdToNodeIdMappingVecDestructorTag tag; };
typedef struct AzTagIdToNodeIdMappingVecDestructorVariant_DefaultRust AzTagIdToNodeIdMappingVecDestructorVariant_DefaultRust;
struct AzTagIdToNodeIdMappingVecDestructorVariant_NoDestructor { AzTagIdToNodeIdMappingVecDestructorTag tag; };
typedef struct AzTagIdToNodeIdMappingVecDestructorVariant_NoDestructor AzTagIdToNodeIdMappingVecDestructorVariant_NoDestructor;
struct AzTagIdToNodeIdMappingVecDestructorVariant_External { AzTagIdToNodeIdMappingVecDestructorTag tag; AzTagIdToNodeIdMappingVecDestructorType payload; };
typedef struct AzTagIdToNodeIdMappingVecDestructorVariant_External AzTagIdToNodeIdMappingVecDestructorVariant_External;
union AzTagIdToNodeIdMappingVecDestructor {
    AzTagIdToNodeIdMappingVecDestructorVariant_DefaultRust DefaultRust;
    AzTagIdToNodeIdMappingVecDestructorVariant_NoDestructor NoDestructor;
    AzTagIdToNodeIdMappingVecDestructorVariant_External External;
};
typedef union AzTagIdToNodeIdMappingVecDestructor AzTagIdToNodeIdMappingVecDestructor;

enum AzParentWithNodeDepthVecDestructorTag {
   AzParentWithNodeDepthVecDestructorTag_DefaultRust,
   AzParentWithNodeDepthVecDestructorTag_NoDestructor,
   AzParentWithNodeDepthVecDestructorTag_External,
};
typedef enum AzParentWithNodeDepthVecDestructorTag AzParentWithNodeDepthVecDestructorTag;

struct AzParentWithNodeDepthVecDestructorVariant_DefaultRust { AzParentWithNodeDepthVecDestructorTag tag; };
typedef struct AzParentWithNodeDepthVecDestructorVariant_DefaultRust AzParentWithNodeDepthVecDestructorVariant_DefaultRust;
struct AzParentWithNodeDepthVecDestructorVariant_NoDestructor { AzParentWithNodeDepthVecDestructorTag tag; };
typedef struct AzParentWithNodeDepthVecDestructorVariant_NoDestructor AzParentWithNodeDepthVecDestructorVariant_NoDestructor;
struct AzParentWithNodeDepthVecDestructorVariant_External { AzParentWithNodeDepthVecDestructorTag tag; AzParentWithNodeDepthVecDestructorType payload; };
typedef struct AzParentWithNodeDepthVecDestructorVariant_External AzParentWithNodeDepthVecDestructorVariant_External;
union AzParentWithNodeDepthVecDestructor {
    AzParentWithNodeDepthVecDestructorVariant_DefaultRust DefaultRust;
    AzParentWithNodeDepthVecDestructorVariant_NoDestructor NoDestructor;
    AzParentWithNodeDepthVecDestructorVariant_External External;
};
typedef union AzParentWithNodeDepthVecDestructor AzParentWithNodeDepthVecDestructor;

enum AzNodeDataVecDestructorTag {
   AzNodeDataVecDestructorTag_DefaultRust,
   AzNodeDataVecDestructorTag_NoDestructor,
   AzNodeDataVecDestructorTag_External,
};
typedef enum AzNodeDataVecDestructorTag AzNodeDataVecDestructorTag;

struct AzNodeDataVecDestructorVariant_DefaultRust { AzNodeDataVecDestructorTag tag; };
typedef struct AzNodeDataVecDestructorVariant_DefaultRust AzNodeDataVecDestructorVariant_DefaultRust;
struct AzNodeDataVecDestructorVariant_NoDestructor { AzNodeDataVecDestructorTag tag; };
typedef struct AzNodeDataVecDestructorVariant_NoDestructor AzNodeDataVecDestructorVariant_NoDestructor;
struct AzNodeDataVecDestructorVariant_External { AzNodeDataVecDestructorTag tag; AzNodeDataVecDestructorType payload; };
typedef struct AzNodeDataVecDestructorVariant_External AzNodeDataVecDestructorVariant_External;
union AzNodeDataVecDestructor {
    AzNodeDataVecDestructorVariant_DefaultRust DefaultRust;
    AzNodeDataVecDestructorVariant_NoDestructor NoDestructor;
    AzNodeDataVecDestructorVariant_External External;
};
typedef union AzNodeDataVecDestructor AzNodeDataVecDestructor;

enum AzOptionI16Tag {
   AzOptionI16Tag_None,
   AzOptionI16Tag_Some,
};
typedef enum AzOptionI16Tag AzOptionI16Tag;

struct AzOptionI16Variant_None { AzOptionI16Tag tag; };
typedef struct AzOptionI16Variant_None AzOptionI16Variant_None;
struct AzOptionI16Variant_Some { AzOptionI16Tag tag; int16_t payload; };
typedef struct AzOptionI16Variant_Some AzOptionI16Variant_Some;
union AzOptionI16 {
    AzOptionI16Variant_None None;
    AzOptionI16Variant_Some Some;
};
typedef union AzOptionI16 AzOptionI16;

enum AzOptionU16Tag {
   AzOptionU16Tag_None,
   AzOptionU16Tag_Some,
};
typedef enum AzOptionU16Tag AzOptionU16Tag;

struct AzOptionU16Variant_None { AzOptionU16Tag tag; };
typedef struct AzOptionU16Variant_None AzOptionU16Variant_None;
struct AzOptionU16Variant_Some { AzOptionU16Tag tag; uint16_t payload; };
typedef struct AzOptionU16Variant_Some AzOptionU16Variant_Some;
union AzOptionU16 {
    AzOptionU16Variant_None None;
    AzOptionU16Variant_Some Some;
};
typedef union AzOptionU16 AzOptionU16;

enum AzOptionU32Tag {
   AzOptionU32Tag_None,
   AzOptionU32Tag_Some,
};
typedef enum AzOptionU32Tag AzOptionU32Tag;

struct AzOptionU32Variant_None { AzOptionU32Tag tag; };
typedef struct AzOptionU32Variant_None AzOptionU32Variant_None;
struct AzOptionU32Variant_Some { AzOptionU32Tag tag; uint32_t payload; };
typedef struct AzOptionU32Variant_Some AzOptionU32Variant_Some;
union AzOptionU32 {
    AzOptionU32Variant_None None;
    AzOptionU32Variant_Some Some;
};
typedef union AzOptionU32 AzOptionU32;

enum AzOptionHwndHandleTag {
   AzOptionHwndHandleTag_None,
   AzOptionHwndHandleTag_Some,
};
typedef enum AzOptionHwndHandleTag AzOptionHwndHandleTag;

struct AzOptionHwndHandleVariant_None { AzOptionHwndHandleTag tag; };
typedef struct AzOptionHwndHandleVariant_None AzOptionHwndHandleVariant_None;
struct AzOptionHwndHandleVariant_Some { AzOptionHwndHandleTag tag; void* restrict payload; };
typedef struct AzOptionHwndHandleVariant_Some AzOptionHwndHandleVariant_Some;
union AzOptionHwndHandle {
    AzOptionHwndHandleVariant_None None;
    AzOptionHwndHandleVariant_Some Some;
};
typedef union AzOptionHwndHandle AzOptionHwndHandle;

enum AzOptionX11VisualTag {
   AzOptionX11VisualTag_None,
   AzOptionX11VisualTag_Some,
};
typedef enum AzOptionX11VisualTag AzOptionX11VisualTag;

struct AzOptionX11VisualVariant_None { AzOptionX11VisualTag tag; };
typedef struct AzOptionX11VisualVariant_None AzOptionX11VisualVariant_None;
struct AzOptionX11VisualVariant_Some { AzOptionX11VisualTag tag; void* payload; };
typedef struct AzOptionX11VisualVariant_Some AzOptionX11VisualVariant_Some;
union AzOptionX11Visual {
    AzOptionX11VisualVariant_None None;
    AzOptionX11VisualVariant_Some Some;
};
typedef union AzOptionX11Visual AzOptionX11Visual;

enum AzOptionI32Tag {
   AzOptionI32Tag_None,
   AzOptionI32Tag_Some,
};
typedef enum AzOptionI32Tag AzOptionI32Tag;

struct AzOptionI32Variant_None { AzOptionI32Tag tag; };
typedef struct AzOptionI32Variant_None AzOptionI32Variant_None;
struct AzOptionI32Variant_Some { AzOptionI32Tag tag; int32_t payload; };
typedef struct AzOptionI32Variant_Some AzOptionI32Variant_Some;
union AzOptionI32 {
    AzOptionI32Variant_None None;
    AzOptionI32Variant_Some Some;
};
typedef union AzOptionI32 AzOptionI32;

enum AzOptionF32Tag {
   AzOptionF32Tag_None,
   AzOptionF32Tag_Some,
};
typedef enum AzOptionF32Tag AzOptionF32Tag;

struct AzOptionF32Variant_None { AzOptionF32Tag tag; };
typedef struct AzOptionF32Variant_None AzOptionF32Variant_None;
struct AzOptionF32Variant_Some { AzOptionF32Tag tag; float payload; };
typedef struct AzOptionF32Variant_Some AzOptionF32Variant_Some;
union AzOptionF32 {
    AzOptionF32Variant_None None;
    AzOptionF32Variant_Some Some;
};
typedef union AzOptionF32 AzOptionF32;

enum AzOptionCharTag {
   AzOptionCharTag_None,
   AzOptionCharTag_Some,
};
typedef enum AzOptionCharTag AzOptionCharTag;

struct AzOptionCharVariant_None { AzOptionCharTag tag; };
typedef struct AzOptionCharVariant_None AzOptionCharVariant_None;
struct AzOptionCharVariant_Some { AzOptionCharTag tag; uint32_t payload; };
typedef struct AzOptionCharVariant_Some AzOptionCharVariant_Some;
union AzOptionChar {
    AzOptionCharVariant_None None;
    AzOptionCharVariant_Some Some;
};
typedef union AzOptionChar AzOptionChar;

enum AzOptionUsizeTag {
   AzOptionUsizeTag_None,
   AzOptionUsizeTag_Some,
};
typedef enum AzOptionUsizeTag AzOptionUsizeTag;

struct AzOptionUsizeVariant_None { AzOptionUsizeTag tag; };
typedef struct AzOptionUsizeVariant_None AzOptionUsizeVariant_None;
struct AzOptionUsizeVariant_Some { AzOptionUsizeTag tag; size_t payload; };
typedef struct AzOptionUsizeVariant_Some AzOptionUsizeVariant_Some;
union AzOptionUsize {
    AzOptionUsizeVariant_None None;
    AzOptionUsizeVariant_Some Some;
};
typedef union AzOptionUsize AzOptionUsize;

struct AzSvgParseErrorPosition {
    uint32_t row;
    uint32_t col;
};
typedef struct AzSvgParseErrorPosition AzSvgParseErrorPosition;

struct AzSystemCallbacks {
    AzCreateThreadFn create_thread_fn;
    AzGetSystemTimeFn get_system_time_fn;
};
typedef struct AzSystemCallbacks AzSystemCallbacks;

struct AzRendererOptions {
    AzVsync vsync;
    AzSrgb srgb;
    AzHwAcceleration hw_accel;
};
typedef struct AzRendererOptions AzRendererOptions;

struct AzLayoutRect {
    AzLayoutPoint origin;
    AzLayoutSize size;
};
typedef struct AzLayoutRect AzLayoutRect;

enum AzRawWindowHandleTag {
   AzRawWindowHandleTag_IOS,
   AzRawWindowHandleTag_MacOS,
   AzRawWindowHandleTag_Xlib,
   AzRawWindowHandleTag_Xcb,
   AzRawWindowHandleTag_Wayland,
   AzRawWindowHandleTag_Windows,
   AzRawWindowHandleTag_Web,
   AzRawWindowHandleTag_Android,
   AzRawWindowHandleTag_Unsupported,
};
typedef enum AzRawWindowHandleTag AzRawWindowHandleTag;

struct AzRawWindowHandleVariant_IOS { AzRawWindowHandleTag tag; AzIOSHandle payload; };
typedef struct AzRawWindowHandleVariant_IOS AzRawWindowHandleVariant_IOS;
struct AzRawWindowHandleVariant_MacOS { AzRawWindowHandleTag tag; AzMacOSHandle payload; };
typedef struct AzRawWindowHandleVariant_MacOS AzRawWindowHandleVariant_MacOS;
struct AzRawWindowHandleVariant_Xlib { AzRawWindowHandleTag tag; AzXlibHandle payload; };
typedef struct AzRawWindowHandleVariant_Xlib AzRawWindowHandleVariant_Xlib;
struct AzRawWindowHandleVariant_Xcb { AzRawWindowHandleTag tag; AzXcbHandle payload; };
typedef struct AzRawWindowHandleVariant_Xcb AzRawWindowHandleVariant_Xcb;
struct AzRawWindowHandleVariant_Wayland { AzRawWindowHandleTag tag; AzWaylandHandle payload; };
typedef struct AzRawWindowHandleVariant_Wayland AzRawWindowHandleVariant_Wayland;
struct AzRawWindowHandleVariant_Windows { AzRawWindowHandleTag tag; AzWindowsHandle payload; };
typedef struct AzRawWindowHandleVariant_Windows AzRawWindowHandleVariant_Windows;
struct AzRawWindowHandleVariant_Web { AzRawWindowHandleTag tag; AzWebHandle payload; };
typedef struct AzRawWindowHandleVariant_Web AzRawWindowHandleVariant_Web;
struct AzRawWindowHandleVariant_Android { AzRawWindowHandleTag tag; AzAndroidHandle payload; };
typedef struct AzRawWindowHandleVariant_Android AzRawWindowHandleVariant_Android;
struct AzRawWindowHandleVariant_Unsupported { AzRawWindowHandleTag tag; };
typedef struct AzRawWindowHandleVariant_Unsupported AzRawWindowHandleVariant_Unsupported;
union AzRawWindowHandle {
    AzRawWindowHandleVariant_IOS IOS;
    AzRawWindowHandleVariant_MacOS MacOS;
    AzRawWindowHandleVariant_Xlib Xlib;
    AzRawWindowHandleVariant_Xcb Xcb;
    AzRawWindowHandleVariant_Wayland Wayland;
    AzRawWindowHandleVariant_Windows Windows;
    AzRawWindowHandleVariant_Web Web;
    AzRawWindowHandleVariant_Android Android;
    AzRawWindowHandleVariant_Unsupported Unsupported;
};
typedef union AzRawWindowHandle AzRawWindowHandle;

struct AzLogicalRect {
    AzLogicalPosition origin;
    AzLogicalSize size;
};
typedef struct AzLogicalRect AzLogicalRect;

enum AzAcceleratorKeyTag {
   AzAcceleratorKeyTag_Ctrl,
   AzAcceleratorKeyTag_Alt,
   AzAcceleratorKeyTag_Shift,
   AzAcceleratorKeyTag_Key,
};
typedef enum AzAcceleratorKeyTag AzAcceleratorKeyTag;

struct AzAcceleratorKeyVariant_Ctrl { AzAcceleratorKeyTag tag; };
typedef struct AzAcceleratorKeyVariant_Ctrl AzAcceleratorKeyVariant_Ctrl;
struct AzAcceleratorKeyVariant_Alt { AzAcceleratorKeyTag tag; };
typedef struct AzAcceleratorKeyVariant_Alt AzAcceleratorKeyVariant_Alt;
struct AzAcceleratorKeyVariant_Shift { AzAcceleratorKeyTag tag; };
typedef struct AzAcceleratorKeyVariant_Shift AzAcceleratorKeyVariant_Shift;
struct AzAcceleratorKeyVariant_Key { AzAcceleratorKeyTag tag; AzVirtualKeyCode payload; };
typedef struct AzAcceleratorKeyVariant_Key AzAcceleratorKeyVariant_Key;
union AzAcceleratorKey {
    AzAcceleratorKeyVariant_Ctrl Ctrl;
    AzAcceleratorKeyVariant_Alt Alt;
    AzAcceleratorKeyVariant_Shift Shift;
    AzAcceleratorKeyVariant_Key Key;
};
typedef union AzAcceleratorKey AzAcceleratorKey;

struct AzWindowFlags {
    AzWindowFrame frame;
    bool  is_about_to_close;
    bool  has_decorations;
    bool  is_visible;
    bool  is_always_on_top;
    bool  is_resizable;
    bool  has_focus;
    bool  has_extended_window_frame;
    bool  has_blur_behind_window;
    bool  smooth_scroll_enabled;
    bool  autotab_enabled;
};
typedef struct AzWindowFlags AzWindowFlags;

enum AzCursorPositionTag {
   AzCursorPositionTag_OutOfWindow,
   AzCursorPositionTag_Uninitialized,
   AzCursorPositionTag_InWindow,
};
typedef enum AzCursorPositionTag AzCursorPositionTag;

struct AzCursorPositionVariant_OutOfWindow { AzCursorPositionTag tag; };
typedef struct AzCursorPositionVariant_OutOfWindow AzCursorPositionVariant_OutOfWindow;
struct AzCursorPositionVariant_Uninitialized { AzCursorPositionTag tag; };
typedef struct AzCursorPositionVariant_Uninitialized AzCursorPositionVariant_Uninitialized;
struct AzCursorPositionVariant_InWindow { AzCursorPositionTag tag; AzLogicalPosition payload; };
typedef struct AzCursorPositionVariant_InWindow AzCursorPositionVariant_InWindow;
union AzCursorPosition {
    AzCursorPositionVariant_OutOfWindow OutOfWindow;
    AzCursorPositionVariant_Uninitialized Uninitialized;
    AzCursorPositionVariant_InWindow InWindow;
};
typedef union AzCursorPosition AzCursorPosition;

enum AzWindowPositionTag {
   AzWindowPositionTag_Uninitialized,
   AzWindowPositionTag_Initialized,
};
typedef enum AzWindowPositionTag AzWindowPositionTag;

struct AzWindowPositionVariant_Uninitialized { AzWindowPositionTag tag; };
typedef struct AzWindowPositionVariant_Uninitialized AzWindowPositionVariant_Uninitialized;
struct AzWindowPositionVariant_Initialized { AzWindowPositionTag tag; AzPhysicalPositionI32 payload; };
typedef struct AzWindowPositionVariant_Initialized AzWindowPositionVariant_Initialized;
union AzWindowPosition {
    AzWindowPositionVariant_Uninitialized Uninitialized;
    AzWindowPositionVariant_Initialized Initialized;
};
typedef union AzWindowPosition AzWindowPosition;

enum AzImePositionTag {
   AzImePositionTag_Uninitialized,
   AzImePositionTag_Initialized,
};
typedef enum AzImePositionTag AzImePositionTag;

struct AzImePositionVariant_Uninitialized { AzImePositionTag tag; };
typedef struct AzImePositionVariant_Uninitialized AzImePositionVariant_Uninitialized;
struct AzImePositionVariant_Initialized { AzImePositionTag tag; AzLogicalPosition payload; };
typedef struct AzImePositionVariant_Initialized AzImePositionVariant_Initialized;
union AzImePosition {
    AzImePositionVariant_Uninitialized Uninitialized;
    AzImePositionVariant_Initialized Initialized;
};
typedef union AzImePosition AzImePosition;

struct AzVideoMode {
    AzLayoutSize size;
    uint16_t bit_depth;
    uint16_t refresh_rate;
};
typedef struct AzVideoMode AzVideoMode;

struct AzDomNodeId {
    AzDomId dom;
    AzNodeId node;
};
typedef struct AzDomNodeId AzDomNodeId;

enum AzPositionInfoTag {
   AzPositionInfoTag_Static,
   AzPositionInfoTag_Fixed,
   AzPositionInfoTag_Absolute,
   AzPositionInfoTag_Relative,
};
typedef enum AzPositionInfoTag AzPositionInfoTag;

struct AzPositionInfoVariant_Static { AzPositionInfoTag tag; AzPositionInfoInner payload; };
typedef struct AzPositionInfoVariant_Static AzPositionInfoVariant_Static;
struct AzPositionInfoVariant_Fixed { AzPositionInfoTag tag; AzPositionInfoInner payload; };
typedef struct AzPositionInfoVariant_Fixed AzPositionInfoVariant_Fixed;
struct AzPositionInfoVariant_Absolute { AzPositionInfoTag tag; AzPositionInfoInner payload; };
typedef struct AzPositionInfoVariant_Absolute AzPositionInfoVariant_Absolute;
struct AzPositionInfoVariant_Relative { AzPositionInfoTag tag; AzPositionInfoInner payload; };
typedef struct AzPositionInfoVariant_Relative AzPositionInfoVariant_Relative;
union AzPositionInfo {
    AzPositionInfoVariant_Static Static;
    AzPositionInfoVariant_Fixed Fixed;
    AzPositionInfoVariant_Absolute Absolute;
    AzPositionInfoVariant_Relative Relative;
};
typedef union AzPositionInfo AzPositionInfo;

struct AzHidpiAdjustedBounds {
    AzLogicalSize logical_size;
    float hidpi_factor;
};
typedef struct AzHidpiAdjustedBounds AzHidpiAdjustedBounds;

struct AzInlineGlyph {
    AzLogicalRect bounds;
    AzOptionChar unicode_codepoint;
    uint32_t glyph_index;
};
typedef struct AzInlineGlyph AzInlineGlyph;

struct AzInlineTextHit {
    AzOptionChar unicode_codepoint;
    AzLogicalPosition hit_relative_to_inline_text;
    AzLogicalPosition hit_relative_to_line;
    AzLogicalPosition hit_relative_to_text_content;
    AzLogicalPosition hit_relative_to_glyph;
    size_t line_index_relative_to_text;
    size_t word_index_relative_to_text;
    size_t text_content_index_relative_to_text;
    size_t glyph_index_relative_to_text;
    size_t char_index_relative_to_text;
    size_t word_index_relative_to_line;
    size_t text_content_index_relative_to_line;
    size_t glyph_index_relative_to_line;
    size_t char_index_relative_to_line;
    size_t glyph_index_relative_to_word;
    size_t char_index_relative_to_word;
};
typedef struct AzInlineTextHit AzInlineTextHit;

struct AzIFrameCallbackInfo {
    void* system_fonts;
    void* image_cache;
    AzWindowTheme window_theme;
    AzHidpiAdjustedBounds bounds;
    AzLogicalSize scroll_size;
    AzLogicalPosition scroll_offset;
    AzLogicalSize virtual_scroll_size;
    AzLogicalPosition virtual_scroll_offset;
    void* _reserved_ref;
    void* restrict _reserved_mut;
};
typedef struct AzIFrameCallbackInfo AzIFrameCallbackInfo;

struct AzTimerCallbackReturn {
    AzUpdate should_update;
    AzTerminateTimer should_terminate;
};
typedef struct AzTimerCallbackReturn AzTimerCallbackReturn;

struct AzRefAny {
    void* _internal_ptr;
    AzRefCount sharing_info;
};
typedef struct AzRefAny AzRefAny;

struct AzIFrameNode {
    AzIFrameCallback callback;
    AzRefAny data;
};
typedef struct AzIFrameNode AzIFrameNode;

enum AzNotEventFilterTag {
   AzNotEventFilterTag_Hover,
   AzNotEventFilterTag_Focus,
};
typedef enum AzNotEventFilterTag AzNotEventFilterTag;

struct AzNotEventFilterVariant_Hover { AzNotEventFilterTag tag; AzHoverEventFilter payload; };
typedef struct AzNotEventFilterVariant_Hover AzNotEventFilterVariant_Hover;
struct AzNotEventFilterVariant_Focus { AzNotEventFilterTag tag; AzFocusEventFilter payload; };
typedef struct AzNotEventFilterVariant_Focus AzNotEventFilterVariant_Focus;
union AzNotEventFilter {
    AzNotEventFilterVariant_Hover Hover;
    AzNotEventFilterVariant_Focus Focus;
};
typedef union AzNotEventFilter AzNotEventFilter;

struct AzMenuCallback {
    AzCallback callback;
    AzRefAny data;
};
typedef struct AzMenuCallback AzMenuCallback;

enum AzMenuItemIconTag {
   AzMenuItemIconTag_Checkbox,
   AzMenuItemIconTag_Image,
};
typedef enum AzMenuItemIconTag AzMenuItemIconTag;

struct AzMenuItemIconVariant_Checkbox { AzMenuItemIconTag tag; bool payload; };
typedef struct AzMenuItemIconVariant_Checkbox AzMenuItemIconVariant_Checkbox;
struct AzMenuItemIconVariant_Image { AzMenuItemIconTag tag; AzImageRef payload; };
typedef struct AzMenuItemIconVariant_Image AzMenuItemIconVariant_Image;
union AzMenuItemIcon {
    AzMenuItemIconVariant_Checkbox Checkbox;
    AzMenuItemIconVariant_Image Image;
};
typedef union AzMenuItemIcon AzMenuItemIcon;

enum AzCssNthChildSelectorTag {
   AzCssNthChildSelectorTag_Number,
   AzCssNthChildSelectorTag_Even,
   AzCssNthChildSelectorTag_Odd,
   AzCssNthChildSelectorTag_Pattern,
};
typedef enum AzCssNthChildSelectorTag AzCssNthChildSelectorTag;

struct AzCssNthChildSelectorVariant_Number { AzCssNthChildSelectorTag tag; uint32_t payload; };
typedef struct AzCssNthChildSelectorVariant_Number AzCssNthChildSelectorVariant_Number;
struct AzCssNthChildSelectorVariant_Even { AzCssNthChildSelectorTag tag; };
typedef struct AzCssNthChildSelectorVariant_Even AzCssNthChildSelectorVariant_Even;
struct AzCssNthChildSelectorVariant_Odd { AzCssNthChildSelectorTag tag; };
typedef struct AzCssNthChildSelectorVariant_Odd AzCssNthChildSelectorVariant_Odd;
struct AzCssNthChildSelectorVariant_Pattern { AzCssNthChildSelectorTag tag; AzCssNthChildPattern payload; };
typedef struct AzCssNthChildSelectorVariant_Pattern AzCssNthChildSelectorVariant_Pattern;
union AzCssNthChildSelector {
    AzCssNthChildSelectorVariant_Number Number;
    AzCssNthChildSelectorVariant_Even Even;
    AzCssNthChildSelectorVariant_Odd Odd;
    AzCssNthChildSelectorVariant_Pattern Pattern;
};
typedef union AzCssNthChildSelector AzCssNthChildSelector;

struct AzPixelValue {
    AzSizeMetric metric;
    AzFloatValue number;
};
typedef struct AzPixelValue AzPixelValue;

struct AzPixelValueNoPercent {
    AzPixelValue inner;
};
typedef struct AzPixelValueNoPercent AzPixelValueNoPercent;

struct AzStyleBoxShadow {
    AzPixelValueNoPercent offset[2];
    AzColorU color;
    AzPixelValueNoPercent blur_radius;
    AzPixelValueNoPercent spread_radius;
    AzBoxShadowClipMode clip_mode;
};
typedef struct AzStyleBoxShadow AzStyleBoxShadow;

struct AzLayoutBottom {
    AzPixelValue inner;
};
typedef struct AzLayoutBottom AzLayoutBottom;

struct AzLayoutFlexGrow {
    AzFloatValue inner;
};
typedef struct AzLayoutFlexGrow AzLayoutFlexGrow;

struct AzLayoutFlexShrink {
    AzFloatValue inner;
};
typedef struct AzLayoutFlexShrink AzLayoutFlexShrink;

struct AzLayoutHeight {
    AzPixelValue inner;
};
typedef struct AzLayoutHeight AzLayoutHeight;

struct AzLayoutLeft {
    AzPixelValue inner;
};
typedef struct AzLayoutLeft AzLayoutLeft;

struct AzLayoutMarginBottom {
    AzPixelValue inner;
};
typedef struct AzLayoutMarginBottom AzLayoutMarginBottom;

struct AzLayoutMarginLeft {
    AzPixelValue inner;
};
typedef struct AzLayoutMarginLeft AzLayoutMarginLeft;

struct AzLayoutMarginRight {
    AzPixelValue inner;
};
typedef struct AzLayoutMarginRight AzLayoutMarginRight;

struct AzLayoutMarginTop {
    AzPixelValue inner;
};
typedef struct AzLayoutMarginTop AzLayoutMarginTop;

struct AzLayoutMaxHeight {
    AzPixelValue inner;
};
typedef struct AzLayoutMaxHeight AzLayoutMaxHeight;

struct AzLayoutMaxWidth {
    AzPixelValue inner;
};
typedef struct AzLayoutMaxWidth AzLayoutMaxWidth;

struct AzLayoutMinHeight {
    AzPixelValue inner;
};
typedef struct AzLayoutMinHeight AzLayoutMinHeight;

struct AzLayoutMinWidth {
    AzPixelValue inner;
};
typedef struct AzLayoutMinWidth AzLayoutMinWidth;

struct AzLayoutPaddingBottom {
    AzPixelValue inner;
};
typedef struct AzLayoutPaddingBottom AzLayoutPaddingBottom;

struct AzLayoutPaddingLeft {
    AzPixelValue inner;
};
typedef struct AzLayoutPaddingLeft AzLayoutPaddingLeft;

struct AzLayoutPaddingRight {
    AzPixelValue inner;
};
typedef struct AzLayoutPaddingRight AzLayoutPaddingRight;

struct AzLayoutPaddingTop {
    AzPixelValue inner;
};
typedef struct AzLayoutPaddingTop AzLayoutPaddingTop;

struct AzLayoutRight {
    AzPixelValue inner;
};
typedef struct AzLayoutRight AzLayoutRight;

struct AzLayoutTop {
    AzPixelValue inner;
};
typedef struct AzLayoutTop AzLayoutTop;

struct AzLayoutWidth {
    AzPixelValue inner;
};
typedef struct AzLayoutWidth AzLayoutWidth;

struct AzPercentageValue {
    AzFloatValue number;
};
typedef struct AzPercentageValue AzPercentageValue;

struct AzAngleValue {
    AzAngleMetric metric;
    AzFloatValue number;
};
typedef struct AzAngleValue AzAngleValue;

struct AzNormalizedLinearColorStop {
    AzPercentageValue offset;
    AzColorU color;
};
typedef struct AzNormalizedLinearColorStop AzNormalizedLinearColorStop;

struct AzNormalizedRadialColorStop {
    AzAngleValue offset;
    AzColorU color;
};
typedef struct AzNormalizedRadialColorStop AzNormalizedRadialColorStop;

struct AzDirectionCorners {
    AzDirectionCorner from;
    AzDirectionCorner to;
};
typedef struct AzDirectionCorners AzDirectionCorners;

enum AzDirectionTag {
   AzDirectionTag_Angle,
   AzDirectionTag_FromTo,
};
typedef enum AzDirectionTag AzDirectionTag;

struct AzDirectionVariant_Angle { AzDirectionTag tag; AzAngleValue payload; };
typedef struct AzDirectionVariant_Angle AzDirectionVariant_Angle;
struct AzDirectionVariant_FromTo { AzDirectionTag tag; AzDirectionCorners payload; };
typedef struct AzDirectionVariant_FromTo AzDirectionVariant_FromTo;
union AzDirection {
    AzDirectionVariant_Angle Angle;
    AzDirectionVariant_FromTo FromTo;
};
typedef union AzDirection AzDirection;

enum AzBackgroundPositionHorizontalTag {
   AzBackgroundPositionHorizontalTag_Left,
   AzBackgroundPositionHorizontalTag_Center,
   AzBackgroundPositionHorizontalTag_Right,
   AzBackgroundPositionHorizontalTag_Exact,
};
typedef enum AzBackgroundPositionHorizontalTag AzBackgroundPositionHorizontalTag;

struct AzBackgroundPositionHorizontalVariant_Left { AzBackgroundPositionHorizontalTag tag; };
typedef struct AzBackgroundPositionHorizontalVariant_Left AzBackgroundPositionHorizontalVariant_Left;
struct AzBackgroundPositionHorizontalVariant_Center { AzBackgroundPositionHorizontalTag tag; };
typedef struct AzBackgroundPositionHorizontalVariant_Center AzBackgroundPositionHorizontalVariant_Center;
struct AzBackgroundPositionHorizontalVariant_Right { AzBackgroundPositionHorizontalTag tag; };
typedef struct AzBackgroundPositionHorizontalVariant_Right AzBackgroundPositionHorizontalVariant_Right;
struct AzBackgroundPositionHorizontalVariant_Exact { AzBackgroundPositionHorizontalTag tag; AzPixelValue payload; };
typedef struct AzBackgroundPositionHorizontalVariant_Exact AzBackgroundPositionHorizontalVariant_Exact;
union AzBackgroundPositionHorizontal {
    AzBackgroundPositionHorizontalVariant_Left Left;
    AzBackgroundPositionHorizontalVariant_Center Center;
    AzBackgroundPositionHorizontalVariant_Right Right;
    AzBackgroundPositionHorizontalVariant_Exact Exact;
};
typedef union AzBackgroundPositionHorizontal AzBackgroundPositionHorizontal;

enum AzBackgroundPositionVerticalTag {
   AzBackgroundPositionVerticalTag_Top,
   AzBackgroundPositionVerticalTag_Center,
   AzBackgroundPositionVerticalTag_Bottom,
   AzBackgroundPositionVerticalTag_Exact,
};
typedef enum AzBackgroundPositionVerticalTag AzBackgroundPositionVerticalTag;

struct AzBackgroundPositionVerticalVariant_Top { AzBackgroundPositionVerticalTag tag; };
typedef struct AzBackgroundPositionVerticalVariant_Top AzBackgroundPositionVerticalVariant_Top;
struct AzBackgroundPositionVerticalVariant_Center { AzBackgroundPositionVerticalTag tag; };
typedef struct AzBackgroundPositionVerticalVariant_Center AzBackgroundPositionVerticalVariant_Center;
struct AzBackgroundPositionVerticalVariant_Bottom { AzBackgroundPositionVerticalTag tag; };
typedef struct AzBackgroundPositionVerticalVariant_Bottom AzBackgroundPositionVerticalVariant_Bottom;
struct AzBackgroundPositionVerticalVariant_Exact { AzBackgroundPositionVerticalTag tag; AzPixelValue payload; };
typedef struct AzBackgroundPositionVerticalVariant_Exact AzBackgroundPositionVerticalVariant_Exact;
union AzBackgroundPositionVertical {
    AzBackgroundPositionVerticalVariant_Top Top;
    AzBackgroundPositionVerticalVariant_Center Center;
    AzBackgroundPositionVerticalVariant_Bottom Bottom;
    AzBackgroundPositionVerticalVariant_Exact Exact;
};
typedef union AzBackgroundPositionVertical AzBackgroundPositionVertical;

struct AzStyleBackgroundPosition {
    AzBackgroundPositionHorizontal horizontal;
    AzBackgroundPositionVertical vertical;
};
typedef struct AzStyleBackgroundPosition AzStyleBackgroundPosition;

enum AzStyleBackgroundSizeTag {
   AzStyleBackgroundSizeTag_ExactSize,
   AzStyleBackgroundSizeTag_Contain,
   AzStyleBackgroundSizeTag_Cover,
};
typedef enum AzStyleBackgroundSizeTag AzStyleBackgroundSizeTag;

struct AzStyleBackgroundSizeVariant_ExactSize { AzStyleBackgroundSizeTag tag; AzPixelValue payload[2]; };
typedef struct AzStyleBackgroundSizeVariant_ExactSize AzStyleBackgroundSizeVariant_ExactSize;
struct AzStyleBackgroundSizeVariant_Contain { AzStyleBackgroundSizeTag tag; };
typedef struct AzStyleBackgroundSizeVariant_Contain AzStyleBackgroundSizeVariant_Contain;
struct AzStyleBackgroundSizeVariant_Cover { AzStyleBackgroundSizeTag tag; };
typedef struct AzStyleBackgroundSizeVariant_Cover AzStyleBackgroundSizeVariant_Cover;
union AzStyleBackgroundSize {
    AzStyleBackgroundSizeVariant_ExactSize ExactSize;
    AzStyleBackgroundSizeVariant_Contain Contain;
    AzStyleBackgroundSizeVariant_Cover Cover;
};
typedef union AzStyleBackgroundSize AzStyleBackgroundSize;

struct AzStyleBorderBottomColor {
    AzColorU inner;
};
typedef struct AzStyleBorderBottomColor AzStyleBorderBottomColor;

struct AzStyleBorderBottomLeftRadius {
    AzPixelValue inner;
};
typedef struct AzStyleBorderBottomLeftRadius AzStyleBorderBottomLeftRadius;

struct AzStyleBorderBottomRightRadius {
    AzPixelValue inner;
};
typedef struct AzStyleBorderBottomRightRadius AzStyleBorderBottomRightRadius;

struct AzStyleBorderBottomStyle {
    AzBorderStyle inner;
};
typedef struct AzStyleBorderBottomStyle AzStyleBorderBottomStyle;

struct AzLayoutBorderBottomWidth {
    AzPixelValue inner;
};
typedef struct AzLayoutBorderBottomWidth AzLayoutBorderBottomWidth;

struct AzStyleBorderLeftColor {
    AzColorU inner;
};
typedef struct AzStyleBorderLeftColor AzStyleBorderLeftColor;

struct AzStyleBorderLeftStyle {
    AzBorderStyle inner;
};
typedef struct AzStyleBorderLeftStyle AzStyleBorderLeftStyle;

struct AzLayoutBorderLeftWidth {
    AzPixelValue inner;
};
typedef struct AzLayoutBorderLeftWidth AzLayoutBorderLeftWidth;

struct AzStyleBorderRightColor {
    AzColorU inner;
};
typedef struct AzStyleBorderRightColor AzStyleBorderRightColor;

struct AzStyleBorderRightStyle {
    AzBorderStyle inner;
};
typedef struct AzStyleBorderRightStyle AzStyleBorderRightStyle;

struct AzLayoutBorderRightWidth {
    AzPixelValue inner;
};
typedef struct AzLayoutBorderRightWidth AzLayoutBorderRightWidth;

struct AzStyleBorderTopColor {
    AzColorU inner;
};
typedef struct AzStyleBorderTopColor AzStyleBorderTopColor;

struct AzStyleBorderTopLeftRadius {
    AzPixelValue inner;
};
typedef struct AzStyleBorderTopLeftRadius AzStyleBorderTopLeftRadius;

struct AzStyleBorderTopRightRadius {
    AzPixelValue inner;
};
typedef struct AzStyleBorderTopRightRadius AzStyleBorderTopRightRadius;

struct AzStyleBorderTopStyle {
    AzBorderStyle inner;
};
typedef struct AzStyleBorderTopStyle AzStyleBorderTopStyle;

struct AzLayoutBorderTopWidth {
    AzPixelValue inner;
};
typedef struct AzLayoutBorderTopWidth AzLayoutBorderTopWidth;

struct AzStyleFontSize {
    AzPixelValue inner;
};
typedef struct AzStyleFontSize AzStyleFontSize;

struct AzStyleLetterSpacing {
    AzPixelValue inner;
};
typedef struct AzStyleLetterSpacing AzStyleLetterSpacing;

struct AzStyleLineHeight {
    AzPercentageValue inner;
};
typedef struct AzStyleLineHeight AzStyleLineHeight;

struct AzStyleTabWidth {
    AzPercentageValue inner;
};
typedef struct AzStyleTabWidth AzStyleTabWidth;

struct AzStyleOpacity {
    AzPercentageValue inner;
};
typedef struct AzStyleOpacity AzStyleOpacity;

struct AzStyleTransformOrigin {
    AzPixelValue x;
    AzPixelValue y;
};
typedef struct AzStyleTransformOrigin AzStyleTransformOrigin;

struct AzStylePerspectiveOrigin {
    AzPixelValue x;
    AzPixelValue y;
};
typedef struct AzStylePerspectiveOrigin AzStylePerspectiveOrigin;

struct AzStyleTransformMatrix2D {
    AzPixelValue a;
    AzPixelValue b;
    AzPixelValue c;
    AzPixelValue d;
    AzPixelValue tx;
    AzPixelValue ty;
};
typedef struct AzStyleTransformMatrix2D AzStyleTransformMatrix2D;

struct AzStyleTransformMatrix3D {
    AzPixelValue m11;
    AzPixelValue m12;
    AzPixelValue m13;
    AzPixelValue m14;
    AzPixelValue m21;
    AzPixelValue m22;
    AzPixelValue m23;
    AzPixelValue m24;
    AzPixelValue m31;
    AzPixelValue m32;
    AzPixelValue m33;
    AzPixelValue m34;
    AzPixelValue m41;
    AzPixelValue m42;
    AzPixelValue m43;
    AzPixelValue m44;
};
typedef struct AzStyleTransformMatrix3D AzStyleTransformMatrix3D;

struct AzStyleTransformTranslate2D {
    AzPixelValue x;
    AzPixelValue y;
};
typedef struct AzStyleTransformTranslate2D AzStyleTransformTranslate2D;

struct AzStyleTransformTranslate3D {
    AzPixelValue x;
    AzPixelValue y;
    AzPixelValue z;
};
typedef struct AzStyleTransformTranslate3D AzStyleTransformTranslate3D;

struct AzStyleTransformRotate3D {
    AzPercentageValue x;
    AzPercentageValue y;
    AzPercentageValue z;
    AzAngleValue angle;
};
typedef struct AzStyleTransformRotate3D AzStyleTransformRotate3D;

struct AzStyleTransformScale2D {
    AzPercentageValue x;
    AzPercentageValue y;
};
typedef struct AzStyleTransformScale2D AzStyleTransformScale2D;

struct AzStyleTransformScale3D {
    AzPercentageValue x;
    AzPercentageValue y;
    AzPercentageValue z;
};
typedef struct AzStyleTransformScale3D AzStyleTransformScale3D;

struct AzStyleTransformSkew2D {
    AzPercentageValue x;
    AzPercentageValue y;
};
typedef struct AzStyleTransformSkew2D AzStyleTransformSkew2D;

struct AzStyleTextColor {
    AzColorU inner;
};
typedef struct AzStyleTextColor AzStyleTextColor;

struct AzStyleWordSpacing {
    AzPixelValue inner;
};
typedef struct AzStyleWordSpacing AzStyleWordSpacing;

enum AzStyleBoxShadowValueTag {
   AzStyleBoxShadowValueTag_Auto,
   AzStyleBoxShadowValueTag_None,
   AzStyleBoxShadowValueTag_Inherit,
   AzStyleBoxShadowValueTag_Initial,
   AzStyleBoxShadowValueTag_Exact,
};
typedef enum AzStyleBoxShadowValueTag AzStyleBoxShadowValueTag;

struct AzStyleBoxShadowValueVariant_Auto { AzStyleBoxShadowValueTag tag; };
typedef struct AzStyleBoxShadowValueVariant_Auto AzStyleBoxShadowValueVariant_Auto;
struct AzStyleBoxShadowValueVariant_None { AzStyleBoxShadowValueTag tag; };
typedef struct AzStyleBoxShadowValueVariant_None AzStyleBoxShadowValueVariant_None;
struct AzStyleBoxShadowValueVariant_Inherit { AzStyleBoxShadowValueTag tag; };
typedef struct AzStyleBoxShadowValueVariant_Inherit AzStyleBoxShadowValueVariant_Inherit;
struct AzStyleBoxShadowValueVariant_Initial { AzStyleBoxShadowValueTag tag; };
typedef struct AzStyleBoxShadowValueVariant_Initial AzStyleBoxShadowValueVariant_Initial;
struct AzStyleBoxShadowValueVariant_Exact { AzStyleBoxShadowValueTag tag; AzStyleBoxShadow payload; };
typedef struct AzStyleBoxShadowValueVariant_Exact AzStyleBoxShadowValueVariant_Exact;
union AzStyleBoxShadowValue {
    AzStyleBoxShadowValueVariant_Auto Auto;
    AzStyleBoxShadowValueVariant_None None;
    AzStyleBoxShadowValueVariant_Inherit Inherit;
    AzStyleBoxShadowValueVariant_Initial Initial;
    AzStyleBoxShadowValueVariant_Exact Exact;
};
typedef union AzStyleBoxShadowValue AzStyleBoxShadowValue;

enum AzLayoutAlignContentValueTag {
   AzLayoutAlignContentValueTag_Auto,
   AzLayoutAlignContentValueTag_None,
   AzLayoutAlignContentValueTag_Inherit,
   AzLayoutAlignContentValueTag_Initial,
   AzLayoutAlignContentValueTag_Exact,
};
typedef enum AzLayoutAlignContentValueTag AzLayoutAlignContentValueTag;

struct AzLayoutAlignContentValueVariant_Auto { AzLayoutAlignContentValueTag tag; };
typedef struct AzLayoutAlignContentValueVariant_Auto AzLayoutAlignContentValueVariant_Auto;
struct AzLayoutAlignContentValueVariant_None { AzLayoutAlignContentValueTag tag; };
typedef struct AzLayoutAlignContentValueVariant_None AzLayoutAlignContentValueVariant_None;
struct AzLayoutAlignContentValueVariant_Inherit { AzLayoutAlignContentValueTag tag; };
typedef struct AzLayoutAlignContentValueVariant_Inherit AzLayoutAlignContentValueVariant_Inherit;
struct AzLayoutAlignContentValueVariant_Initial { AzLayoutAlignContentValueTag tag; };
typedef struct AzLayoutAlignContentValueVariant_Initial AzLayoutAlignContentValueVariant_Initial;
struct AzLayoutAlignContentValueVariant_Exact { AzLayoutAlignContentValueTag tag; AzLayoutAlignContent payload; };
typedef struct AzLayoutAlignContentValueVariant_Exact AzLayoutAlignContentValueVariant_Exact;
union AzLayoutAlignContentValue {
    AzLayoutAlignContentValueVariant_Auto Auto;
    AzLayoutAlignContentValueVariant_None None;
    AzLayoutAlignContentValueVariant_Inherit Inherit;
    AzLayoutAlignContentValueVariant_Initial Initial;
    AzLayoutAlignContentValueVariant_Exact Exact;
};
typedef union AzLayoutAlignContentValue AzLayoutAlignContentValue;

enum AzLayoutAlignItemsValueTag {
   AzLayoutAlignItemsValueTag_Auto,
   AzLayoutAlignItemsValueTag_None,
   AzLayoutAlignItemsValueTag_Inherit,
   AzLayoutAlignItemsValueTag_Initial,
   AzLayoutAlignItemsValueTag_Exact,
};
typedef enum AzLayoutAlignItemsValueTag AzLayoutAlignItemsValueTag;

struct AzLayoutAlignItemsValueVariant_Auto { AzLayoutAlignItemsValueTag tag; };
typedef struct AzLayoutAlignItemsValueVariant_Auto AzLayoutAlignItemsValueVariant_Auto;
struct AzLayoutAlignItemsValueVariant_None { AzLayoutAlignItemsValueTag tag; };
typedef struct AzLayoutAlignItemsValueVariant_None AzLayoutAlignItemsValueVariant_None;
struct AzLayoutAlignItemsValueVariant_Inherit { AzLayoutAlignItemsValueTag tag; };
typedef struct AzLayoutAlignItemsValueVariant_Inherit AzLayoutAlignItemsValueVariant_Inherit;
struct AzLayoutAlignItemsValueVariant_Initial { AzLayoutAlignItemsValueTag tag; };
typedef struct AzLayoutAlignItemsValueVariant_Initial AzLayoutAlignItemsValueVariant_Initial;
struct AzLayoutAlignItemsValueVariant_Exact { AzLayoutAlignItemsValueTag tag; AzLayoutAlignItems payload; };
typedef struct AzLayoutAlignItemsValueVariant_Exact AzLayoutAlignItemsValueVariant_Exact;
union AzLayoutAlignItemsValue {
    AzLayoutAlignItemsValueVariant_Auto Auto;
    AzLayoutAlignItemsValueVariant_None None;
    AzLayoutAlignItemsValueVariant_Inherit Inherit;
    AzLayoutAlignItemsValueVariant_Initial Initial;
    AzLayoutAlignItemsValueVariant_Exact Exact;
};
typedef union AzLayoutAlignItemsValue AzLayoutAlignItemsValue;

enum AzLayoutBottomValueTag {
   AzLayoutBottomValueTag_Auto,
   AzLayoutBottomValueTag_None,
   AzLayoutBottomValueTag_Inherit,
   AzLayoutBottomValueTag_Initial,
   AzLayoutBottomValueTag_Exact,
};
typedef enum AzLayoutBottomValueTag AzLayoutBottomValueTag;

struct AzLayoutBottomValueVariant_Auto { AzLayoutBottomValueTag tag; };
typedef struct AzLayoutBottomValueVariant_Auto AzLayoutBottomValueVariant_Auto;
struct AzLayoutBottomValueVariant_None { AzLayoutBottomValueTag tag; };
typedef struct AzLayoutBottomValueVariant_None AzLayoutBottomValueVariant_None;
struct AzLayoutBottomValueVariant_Inherit { AzLayoutBottomValueTag tag; };
typedef struct AzLayoutBottomValueVariant_Inherit AzLayoutBottomValueVariant_Inherit;
struct AzLayoutBottomValueVariant_Initial { AzLayoutBottomValueTag tag; };
typedef struct AzLayoutBottomValueVariant_Initial AzLayoutBottomValueVariant_Initial;
struct AzLayoutBottomValueVariant_Exact { AzLayoutBottomValueTag tag; AzLayoutBottom payload; };
typedef struct AzLayoutBottomValueVariant_Exact AzLayoutBottomValueVariant_Exact;
union AzLayoutBottomValue {
    AzLayoutBottomValueVariant_Auto Auto;
    AzLayoutBottomValueVariant_None None;
    AzLayoutBottomValueVariant_Inherit Inherit;
    AzLayoutBottomValueVariant_Initial Initial;
    AzLayoutBottomValueVariant_Exact Exact;
};
typedef union AzLayoutBottomValue AzLayoutBottomValue;

enum AzLayoutBoxSizingValueTag {
   AzLayoutBoxSizingValueTag_Auto,
   AzLayoutBoxSizingValueTag_None,
   AzLayoutBoxSizingValueTag_Inherit,
   AzLayoutBoxSizingValueTag_Initial,
   AzLayoutBoxSizingValueTag_Exact,
};
typedef enum AzLayoutBoxSizingValueTag AzLayoutBoxSizingValueTag;

struct AzLayoutBoxSizingValueVariant_Auto { AzLayoutBoxSizingValueTag tag; };
typedef struct AzLayoutBoxSizingValueVariant_Auto AzLayoutBoxSizingValueVariant_Auto;
struct AzLayoutBoxSizingValueVariant_None { AzLayoutBoxSizingValueTag tag; };
typedef struct AzLayoutBoxSizingValueVariant_None AzLayoutBoxSizingValueVariant_None;
struct AzLayoutBoxSizingValueVariant_Inherit { AzLayoutBoxSizingValueTag tag; };
typedef struct AzLayoutBoxSizingValueVariant_Inherit AzLayoutBoxSizingValueVariant_Inherit;
struct AzLayoutBoxSizingValueVariant_Initial { AzLayoutBoxSizingValueTag tag; };
typedef struct AzLayoutBoxSizingValueVariant_Initial AzLayoutBoxSizingValueVariant_Initial;
struct AzLayoutBoxSizingValueVariant_Exact { AzLayoutBoxSizingValueTag tag; AzLayoutBoxSizing payload; };
typedef struct AzLayoutBoxSizingValueVariant_Exact AzLayoutBoxSizingValueVariant_Exact;
union AzLayoutBoxSizingValue {
    AzLayoutBoxSizingValueVariant_Auto Auto;
    AzLayoutBoxSizingValueVariant_None None;
    AzLayoutBoxSizingValueVariant_Inherit Inherit;
    AzLayoutBoxSizingValueVariant_Initial Initial;
    AzLayoutBoxSizingValueVariant_Exact Exact;
};
typedef union AzLayoutBoxSizingValue AzLayoutBoxSizingValue;

enum AzLayoutFlexDirectionValueTag {
   AzLayoutFlexDirectionValueTag_Auto,
   AzLayoutFlexDirectionValueTag_None,
   AzLayoutFlexDirectionValueTag_Inherit,
   AzLayoutFlexDirectionValueTag_Initial,
   AzLayoutFlexDirectionValueTag_Exact,
};
typedef enum AzLayoutFlexDirectionValueTag AzLayoutFlexDirectionValueTag;

struct AzLayoutFlexDirectionValueVariant_Auto { AzLayoutFlexDirectionValueTag tag; };
typedef struct AzLayoutFlexDirectionValueVariant_Auto AzLayoutFlexDirectionValueVariant_Auto;
struct AzLayoutFlexDirectionValueVariant_None { AzLayoutFlexDirectionValueTag tag; };
typedef struct AzLayoutFlexDirectionValueVariant_None AzLayoutFlexDirectionValueVariant_None;
struct AzLayoutFlexDirectionValueVariant_Inherit { AzLayoutFlexDirectionValueTag tag; };
typedef struct AzLayoutFlexDirectionValueVariant_Inherit AzLayoutFlexDirectionValueVariant_Inherit;
struct AzLayoutFlexDirectionValueVariant_Initial { AzLayoutFlexDirectionValueTag tag; };
typedef struct AzLayoutFlexDirectionValueVariant_Initial AzLayoutFlexDirectionValueVariant_Initial;
struct AzLayoutFlexDirectionValueVariant_Exact { AzLayoutFlexDirectionValueTag tag; AzLayoutFlexDirection payload; };
typedef struct AzLayoutFlexDirectionValueVariant_Exact AzLayoutFlexDirectionValueVariant_Exact;
union AzLayoutFlexDirectionValue {
    AzLayoutFlexDirectionValueVariant_Auto Auto;
    AzLayoutFlexDirectionValueVariant_None None;
    AzLayoutFlexDirectionValueVariant_Inherit Inherit;
    AzLayoutFlexDirectionValueVariant_Initial Initial;
    AzLayoutFlexDirectionValueVariant_Exact Exact;
};
typedef union AzLayoutFlexDirectionValue AzLayoutFlexDirectionValue;

enum AzLayoutDisplayValueTag {
   AzLayoutDisplayValueTag_Auto,
   AzLayoutDisplayValueTag_None,
   AzLayoutDisplayValueTag_Inherit,
   AzLayoutDisplayValueTag_Initial,
   AzLayoutDisplayValueTag_Exact,
};
typedef enum AzLayoutDisplayValueTag AzLayoutDisplayValueTag;

struct AzLayoutDisplayValueVariant_Auto { AzLayoutDisplayValueTag tag; };
typedef struct AzLayoutDisplayValueVariant_Auto AzLayoutDisplayValueVariant_Auto;
struct AzLayoutDisplayValueVariant_None { AzLayoutDisplayValueTag tag; };
typedef struct AzLayoutDisplayValueVariant_None AzLayoutDisplayValueVariant_None;
struct AzLayoutDisplayValueVariant_Inherit { AzLayoutDisplayValueTag tag; };
typedef struct AzLayoutDisplayValueVariant_Inherit AzLayoutDisplayValueVariant_Inherit;
struct AzLayoutDisplayValueVariant_Initial { AzLayoutDisplayValueTag tag; };
typedef struct AzLayoutDisplayValueVariant_Initial AzLayoutDisplayValueVariant_Initial;
struct AzLayoutDisplayValueVariant_Exact { AzLayoutDisplayValueTag tag; AzLayoutDisplay payload; };
typedef struct AzLayoutDisplayValueVariant_Exact AzLayoutDisplayValueVariant_Exact;
union AzLayoutDisplayValue {
    AzLayoutDisplayValueVariant_Auto Auto;
    AzLayoutDisplayValueVariant_None None;
    AzLayoutDisplayValueVariant_Inherit Inherit;
    AzLayoutDisplayValueVariant_Initial Initial;
    AzLayoutDisplayValueVariant_Exact Exact;
};
typedef union AzLayoutDisplayValue AzLayoutDisplayValue;

enum AzLayoutFlexGrowValueTag {
   AzLayoutFlexGrowValueTag_Auto,
   AzLayoutFlexGrowValueTag_None,
   AzLayoutFlexGrowValueTag_Inherit,
   AzLayoutFlexGrowValueTag_Initial,
   AzLayoutFlexGrowValueTag_Exact,
};
typedef enum AzLayoutFlexGrowValueTag AzLayoutFlexGrowValueTag;

struct AzLayoutFlexGrowValueVariant_Auto { AzLayoutFlexGrowValueTag tag; };
typedef struct AzLayoutFlexGrowValueVariant_Auto AzLayoutFlexGrowValueVariant_Auto;
struct AzLayoutFlexGrowValueVariant_None { AzLayoutFlexGrowValueTag tag; };
typedef struct AzLayoutFlexGrowValueVariant_None AzLayoutFlexGrowValueVariant_None;
struct AzLayoutFlexGrowValueVariant_Inherit { AzLayoutFlexGrowValueTag tag; };
typedef struct AzLayoutFlexGrowValueVariant_Inherit AzLayoutFlexGrowValueVariant_Inherit;
struct AzLayoutFlexGrowValueVariant_Initial { AzLayoutFlexGrowValueTag tag; };
typedef struct AzLayoutFlexGrowValueVariant_Initial AzLayoutFlexGrowValueVariant_Initial;
struct AzLayoutFlexGrowValueVariant_Exact { AzLayoutFlexGrowValueTag tag; AzLayoutFlexGrow payload; };
typedef struct AzLayoutFlexGrowValueVariant_Exact AzLayoutFlexGrowValueVariant_Exact;
union AzLayoutFlexGrowValue {
    AzLayoutFlexGrowValueVariant_Auto Auto;
    AzLayoutFlexGrowValueVariant_None None;
    AzLayoutFlexGrowValueVariant_Inherit Inherit;
    AzLayoutFlexGrowValueVariant_Initial Initial;
    AzLayoutFlexGrowValueVariant_Exact Exact;
};
typedef union AzLayoutFlexGrowValue AzLayoutFlexGrowValue;

enum AzLayoutFlexShrinkValueTag {
   AzLayoutFlexShrinkValueTag_Auto,
   AzLayoutFlexShrinkValueTag_None,
   AzLayoutFlexShrinkValueTag_Inherit,
   AzLayoutFlexShrinkValueTag_Initial,
   AzLayoutFlexShrinkValueTag_Exact,
};
typedef enum AzLayoutFlexShrinkValueTag AzLayoutFlexShrinkValueTag;

struct AzLayoutFlexShrinkValueVariant_Auto { AzLayoutFlexShrinkValueTag tag; };
typedef struct AzLayoutFlexShrinkValueVariant_Auto AzLayoutFlexShrinkValueVariant_Auto;
struct AzLayoutFlexShrinkValueVariant_None { AzLayoutFlexShrinkValueTag tag; };
typedef struct AzLayoutFlexShrinkValueVariant_None AzLayoutFlexShrinkValueVariant_None;
struct AzLayoutFlexShrinkValueVariant_Inherit { AzLayoutFlexShrinkValueTag tag; };
typedef struct AzLayoutFlexShrinkValueVariant_Inherit AzLayoutFlexShrinkValueVariant_Inherit;
struct AzLayoutFlexShrinkValueVariant_Initial { AzLayoutFlexShrinkValueTag tag; };
typedef struct AzLayoutFlexShrinkValueVariant_Initial AzLayoutFlexShrinkValueVariant_Initial;
struct AzLayoutFlexShrinkValueVariant_Exact { AzLayoutFlexShrinkValueTag tag; AzLayoutFlexShrink payload; };
typedef struct AzLayoutFlexShrinkValueVariant_Exact AzLayoutFlexShrinkValueVariant_Exact;
union AzLayoutFlexShrinkValue {
    AzLayoutFlexShrinkValueVariant_Auto Auto;
    AzLayoutFlexShrinkValueVariant_None None;
    AzLayoutFlexShrinkValueVariant_Inherit Inherit;
    AzLayoutFlexShrinkValueVariant_Initial Initial;
    AzLayoutFlexShrinkValueVariant_Exact Exact;
};
typedef union AzLayoutFlexShrinkValue AzLayoutFlexShrinkValue;

enum AzLayoutFloatValueTag {
   AzLayoutFloatValueTag_Auto,
   AzLayoutFloatValueTag_None,
   AzLayoutFloatValueTag_Inherit,
   AzLayoutFloatValueTag_Initial,
   AzLayoutFloatValueTag_Exact,
};
typedef enum AzLayoutFloatValueTag AzLayoutFloatValueTag;

struct AzLayoutFloatValueVariant_Auto { AzLayoutFloatValueTag tag; };
typedef struct AzLayoutFloatValueVariant_Auto AzLayoutFloatValueVariant_Auto;
struct AzLayoutFloatValueVariant_None { AzLayoutFloatValueTag tag; };
typedef struct AzLayoutFloatValueVariant_None AzLayoutFloatValueVariant_None;
struct AzLayoutFloatValueVariant_Inherit { AzLayoutFloatValueTag tag; };
typedef struct AzLayoutFloatValueVariant_Inherit AzLayoutFloatValueVariant_Inherit;
struct AzLayoutFloatValueVariant_Initial { AzLayoutFloatValueTag tag; };
typedef struct AzLayoutFloatValueVariant_Initial AzLayoutFloatValueVariant_Initial;
struct AzLayoutFloatValueVariant_Exact { AzLayoutFloatValueTag tag; AzLayoutFloat payload; };
typedef struct AzLayoutFloatValueVariant_Exact AzLayoutFloatValueVariant_Exact;
union AzLayoutFloatValue {
    AzLayoutFloatValueVariant_Auto Auto;
    AzLayoutFloatValueVariant_None None;
    AzLayoutFloatValueVariant_Inherit Inherit;
    AzLayoutFloatValueVariant_Initial Initial;
    AzLayoutFloatValueVariant_Exact Exact;
};
typedef union AzLayoutFloatValue AzLayoutFloatValue;

enum AzLayoutHeightValueTag {
   AzLayoutHeightValueTag_Auto,
   AzLayoutHeightValueTag_None,
   AzLayoutHeightValueTag_Inherit,
   AzLayoutHeightValueTag_Initial,
   AzLayoutHeightValueTag_Exact,
};
typedef enum AzLayoutHeightValueTag AzLayoutHeightValueTag;

struct AzLayoutHeightValueVariant_Auto { AzLayoutHeightValueTag tag; };
typedef struct AzLayoutHeightValueVariant_Auto AzLayoutHeightValueVariant_Auto;
struct AzLayoutHeightValueVariant_None { AzLayoutHeightValueTag tag; };
typedef struct AzLayoutHeightValueVariant_None AzLayoutHeightValueVariant_None;
struct AzLayoutHeightValueVariant_Inherit { AzLayoutHeightValueTag tag; };
typedef struct AzLayoutHeightValueVariant_Inherit AzLayoutHeightValueVariant_Inherit;
struct AzLayoutHeightValueVariant_Initial { AzLayoutHeightValueTag tag; };
typedef struct AzLayoutHeightValueVariant_Initial AzLayoutHeightValueVariant_Initial;
struct AzLayoutHeightValueVariant_Exact { AzLayoutHeightValueTag tag; AzLayoutHeight payload; };
typedef struct AzLayoutHeightValueVariant_Exact AzLayoutHeightValueVariant_Exact;
union AzLayoutHeightValue {
    AzLayoutHeightValueVariant_Auto Auto;
    AzLayoutHeightValueVariant_None None;
    AzLayoutHeightValueVariant_Inherit Inherit;
    AzLayoutHeightValueVariant_Initial Initial;
    AzLayoutHeightValueVariant_Exact Exact;
};
typedef union AzLayoutHeightValue AzLayoutHeightValue;

enum AzLayoutJustifyContentValueTag {
   AzLayoutJustifyContentValueTag_Auto,
   AzLayoutJustifyContentValueTag_None,
   AzLayoutJustifyContentValueTag_Inherit,
   AzLayoutJustifyContentValueTag_Initial,
   AzLayoutJustifyContentValueTag_Exact,
};
typedef enum AzLayoutJustifyContentValueTag AzLayoutJustifyContentValueTag;

struct AzLayoutJustifyContentValueVariant_Auto { AzLayoutJustifyContentValueTag tag; };
typedef struct AzLayoutJustifyContentValueVariant_Auto AzLayoutJustifyContentValueVariant_Auto;
struct AzLayoutJustifyContentValueVariant_None { AzLayoutJustifyContentValueTag tag; };
typedef struct AzLayoutJustifyContentValueVariant_None AzLayoutJustifyContentValueVariant_None;
struct AzLayoutJustifyContentValueVariant_Inherit { AzLayoutJustifyContentValueTag tag; };
typedef struct AzLayoutJustifyContentValueVariant_Inherit AzLayoutJustifyContentValueVariant_Inherit;
struct AzLayoutJustifyContentValueVariant_Initial { AzLayoutJustifyContentValueTag tag; };
typedef struct AzLayoutJustifyContentValueVariant_Initial AzLayoutJustifyContentValueVariant_Initial;
struct AzLayoutJustifyContentValueVariant_Exact { AzLayoutJustifyContentValueTag tag; AzLayoutJustifyContent payload; };
typedef struct AzLayoutJustifyContentValueVariant_Exact AzLayoutJustifyContentValueVariant_Exact;
union AzLayoutJustifyContentValue {
    AzLayoutJustifyContentValueVariant_Auto Auto;
    AzLayoutJustifyContentValueVariant_None None;
    AzLayoutJustifyContentValueVariant_Inherit Inherit;
    AzLayoutJustifyContentValueVariant_Initial Initial;
    AzLayoutJustifyContentValueVariant_Exact Exact;
};
typedef union AzLayoutJustifyContentValue AzLayoutJustifyContentValue;

enum AzLayoutLeftValueTag {
   AzLayoutLeftValueTag_Auto,
   AzLayoutLeftValueTag_None,
   AzLayoutLeftValueTag_Inherit,
   AzLayoutLeftValueTag_Initial,
   AzLayoutLeftValueTag_Exact,
};
typedef enum AzLayoutLeftValueTag AzLayoutLeftValueTag;

struct AzLayoutLeftValueVariant_Auto { AzLayoutLeftValueTag tag; };
typedef struct AzLayoutLeftValueVariant_Auto AzLayoutLeftValueVariant_Auto;
struct AzLayoutLeftValueVariant_None { AzLayoutLeftValueTag tag; };
typedef struct AzLayoutLeftValueVariant_None AzLayoutLeftValueVariant_None;
struct AzLayoutLeftValueVariant_Inherit { AzLayoutLeftValueTag tag; };
typedef struct AzLayoutLeftValueVariant_Inherit AzLayoutLeftValueVariant_Inherit;
struct AzLayoutLeftValueVariant_Initial { AzLayoutLeftValueTag tag; };
typedef struct AzLayoutLeftValueVariant_Initial AzLayoutLeftValueVariant_Initial;
struct AzLayoutLeftValueVariant_Exact { AzLayoutLeftValueTag tag; AzLayoutLeft payload; };
typedef struct AzLayoutLeftValueVariant_Exact AzLayoutLeftValueVariant_Exact;
union AzLayoutLeftValue {
    AzLayoutLeftValueVariant_Auto Auto;
    AzLayoutLeftValueVariant_None None;
    AzLayoutLeftValueVariant_Inherit Inherit;
    AzLayoutLeftValueVariant_Initial Initial;
    AzLayoutLeftValueVariant_Exact Exact;
};
typedef union AzLayoutLeftValue AzLayoutLeftValue;

enum AzLayoutMarginBottomValueTag {
   AzLayoutMarginBottomValueTag_Auto,
   AzLayoutMarginBottomValueTag_None,
   AzLayoutMarginBottomValueTag_Inherit,
   AzLayoutMarginBottomValueTag_Initial,
   AzLayoutMarginBottomValueTag_Exact,
};
typedef enum AzLayoutMarginBottomValueTag AzLayoutMarginBottomValueTag;

struct AzLayoutMarginBottomValueVariant_Auto { AzLayoutMarginBottomValueTag tag; };
typedef struct AzLayoutMarginBottomValueVariant_Auto AzLayoutMarginBottomValueVariant_Auto;
struct AzLayoutMarginBottomValueVariant_None { AzLayoutMarginBottomValueTag tag; };
typedef struct AzLayoutMarginBottomValueVariant_None AzLayoutMarginBottomValueVariant_None;
struct AzLayoutMarginBottomValueVariant_Inherit { AzLayoutMarginBottomValueTag tag; };
typedef struct AzLayoutMarginBottomValueVariant_Inherit AzLayoutMarginBottomValueVariant_Inherit;
struct AzLayoutMarginBottomValueVariant_Initial { AzLayoutMarginBottomValueTag tag; };
typedef struct AzLayoutMarginBottomValueVariant_Initial AzLayoutMarginBottomValueVariant_Initial;
struct AzLayoutMarginBottomValueVariant_Exact { AzLayoutMarginBottomValueTag tag; AzLayoutMarginBottom payload; };
typedef struct AzLayoutMarginBottomValueVariant_Exact AzLayoutMarginBottomValueVariant_Exact;
union AzLayoutMarginBottomValue {
    AzLayoutMarginBottomValueVariant_Auto Auto;
    AzLayoutMarginBottomValueVariant_None None;
    AzLayoutMarginBottomValueVariant_Inherit Inherit;
    AzLayoutMarginBottomValueVariant_Initial Initial;
    AzLayoutMarginBottomValueVariant_Exact Exact;
};
typedef union AzLayoutMarginBottomValue AzLayoutMarginBottomValue;

enum AzLayoutMarginLeftValueTag {
   AzLayoutMarginLeftValueTag_Auto,
   AzLayoutMarginLeftValueTag_None,
   AzLayoutMarginLeftValueTag_Inherit,
   AzLayoutMarginLeftValueTag_Initial,
   AzLayoutMarginLeftValueTag_Exact,
};
typedef enum AzLayoutMarginLeftValueTag AzLayoutMarginLeftValueTag;

struct AzLayoutMarginLeftValueVariant_Auto { AzLayoutMarginLeftValueTag tag; };
typedef struct AzLayoutMarginLeftValueVariant_Auto AzLayoutMarginLeftValueVariant_Auto;
struct AzLayoutMarginLeftValueVariant_None { AzLayoutMarginLeftValueTag tag; };
typedef struct AzLayoutMarginLeftValueVariant_None AzLayoutMarginLeftValueVariant_None;
struct AzLayoutMarginLeftValueVariant_Inherit { AzLayoutMarginLeftValueTag tag; };
typedef struct AzLayoutMarginLeftValueVariant_Inherit AzLayoutMarginLeftValueVariant_Inherit;
struct AzLayoutMarginLeftValueVariant_Initial { AzLayoutMarginLeftValueTag tag; };
typedef struct AzLayoutMarginLeftValueVariant_Initial AzLayoutMarginLeftValueVariant_Initial;
struct AzLayoutMarginLeftValueVariant_Exact { AzLayoutMarginLeftValueTag tag; AzLayoutMarginLeft payload; };
typedef struct AzLayoutMarginLeftValueVariant_Exact AzLayoutMarginLeftValueVariant_Exact;
union AzLayoutMarginLeftValue {
    AzLayoutMarginLeftValueVariant_Auto Auto;
    AzLayoutMarginLeftValueVariant_None None;
    AzLayoutMarginLeftValueVariant_Inherit Inherit;
    AzLayoutMarginLeftValueVariant_Initial Initial;
    AzLayoutMarginLeftValueVariant_Exact Exact;
};
typedef union AzLayoutMarginLeftValue AzLayoutMarginLeftValue;

enum AzLayoutMarginRightValueTag {
   AzLayoutMarginRightValueTag_Auto,
   AzLayoutMarginRightValueTag_None,
   AzLayoutMarginRightValueTag_Inherit,
   AzLayoutMarginRightValueTag_Initial,
   AzLayoutMarginRightValueTag_Exact,
};
typedef enum AzLayoutMarginRightValueTag AzLayoutMarginRightValueTag;

struct AzLayoutMarginRightValueVariant_Auto { AzLayoutMarginRightValueTag tag; };
typedef struct AzLayoutMarginRightValueVariant_Auto AzLayoutMarginRightValueVariant_Auto;
struct AzLayoutMarginRightValueVariant_None { AzLayoutMarginRightValueTag tag; };
typedef struct AzLayoutMarginRightValueVariant_None AzLayoutMarginRightValueVariant_None;
struct AzLayoutMarginRightValueVariant_Inherit { AzLayoutMarginRightValueTag tag; };
typedef struct AzLayoutMarginRightValueVariant_Inherit AzLayoutMarginRightValueVariant_Inherit;
struct AzLayoutMarginRightValueVariant_Initial { AzLayoutMarginRightValueTag tag; };
typedef struct AzLayoutMarginRightValueVariant_Initial AzLayoutMarginRightValueVariant_Initial;
struct AzLayoutMarginRightValueVariant_Exact { AzLayoutMarginRightValueTag tag; AzLayoutMarginRight payload; };
typedef struct AzLayoutMarginRightValueVariant_Exact AzLayoutMarginRightValueVariant_Exact;
union AzLayoutMarginRightValue {
    AzLayoutMarginRightValueVariant_Auto Auto;
    AzLayoutMarginRightValueVariant_None None;
    AzLayoutMarginRightValueVariant_Inherit Inherit;
    AzLayoutMarginRightValueVariant_Initial Initial;
    AzLayoutMarginRightValueVariant_Exact Exact;
};
typedef union AzLayoutMarginRightValue AzLayoutMarginRightValue;

enum AzLayoutMarginTopValueTag {
   AzLayoutMarginTopValueTag_Auto,
   AzLayoutMarginTopValueTag_None,
   AzLayoutMarginTopValueTag_Inherit,
   AzLayoutMarginTopValueTag_Initial,
   AzLayoutMarginTopValueTag_Exact,
};
typedef enum AzLayoutMarginTopValueTag AzLayoutMarginTopValueTag;

struct AzLayoutMarginTopValueVariant_Auto { AzLayoutMarginTopValueTag tag; };
typedef struct AzLayoutMarginTopValueVariant_Auto AzLayoutMarginTopValueVariant_Auto;
struct AzLayoutMarginTopValueVariant_None { AzLayoutMarginTopValueTag tag; };
typedef struct AzLayoutMarginTopValueVariant_None AzLayoutMarginTopValueVariant_None;
struct AzLayoutMarginTopValueVariant_Inherit { AzLayoutMarginTopValueTag tag; };
typedef struct AzLayoutMarginTopValueVariant_Inherit AzLayoutMarginTopValueVariant_Inherit;
struct AzLayoutMarginTopValueVariant_Initial { AzLayoutMarginTopValueTag tag; };
typedef struct AzLayoutMarginTopValueVariant_Initial AzLayoutMarginTopValueVariant_Initial;
struct AzLayoutMarginTopValueVariant_Exact { AzLayoutMarginTopValueTag tag; AzLayoutMarginTop payload; };
typedef struct AzLayoutMarginTopValueVariant_Exact AzLayoutMarginTopValueVariant_Exact;
union AzLayoutMarginTopValue {
    AzLayoutMarginTopValueVariant_Auto Auto;
    AzLayoutMarginTopValueVariant_None None;
    AzLayoutMarginTopValueVariant_Inherit Inherit;
    AzLayoutMarginTopValueVariant_Initial Initial;
    AzLayoutMarginTopValueVariant_Exact Exact;
};
typedef union AzLayoutMarginTopValue AzLayoutMarginTopValue;

enum AzLayoutMaxHeightValueTag {
   AzLayoutMaxHeightValueTag_Auto,
   AzLayoutMaxHeightValueTag_None,
   AzLayoutMaxHeightValueTag_Inherit,
   AzLayoutMaxHeightValueTag_Initial,
   AzLayoutMaxHeightValueTag_Exact,
};
typedef enum AzLayoutMaxHeightValueTag AzLayoutMaxHeightValueTag;

struct AzLayoutMaxHeightValueVariant_Auto { AzLayoutMaxHeightValueTag tag; };
typedef struct AzLayoutMaxHeightValueVariant_Auto AzLayoutMaxHeightValueVariant_Auto;
struct AzLayoutMaxHeightValueVariant_None { AzLayoutMaxHeightValueTag tag; };
typedef struct AzLayoutMaxHeightValueVariant_None AzLayoutMaxHeightValueVariant_None;
struct AzLayoutMaxHeightValueVariant_Inherit { AzLayoutMaxHeightValueTag tag; };
typedef struct AzLayoutMaxHeightValueVariant_Inherit AzLayoutMaxHeightValueVariant_Inherit;
struct AzLayoutMaxHeightValueVariant_Initial { AzLayoutMaxHeightValueTag tag; };
typedef struct AzLayoutMaxHeightValueVariant_Initial AzLayoutMaxHeightValueVariant_Initial;
struct AzLayoutMaxHeightValueVariant_Exact { AzLayoutMaxHeightValueTag tag; AzLayoutMaxHeight payload; };
typedef struct AzLayoutMaxHeightValueVariant_Exact AzLayoutMaxHeightValueVariant_Exact;
union AzLayoutMaxHeightValue {
    AzLayoutMaxHeightValueVariant_Auto Auto;
    AzLayoutMaxHeightValueVariant_None None;
    AzLayoutMaxHeightValueVariant_Inherit Inherit;
    AzLayoutMaxHeightValueVariant_Initial Initial;
    AzLayoutMaxHeightValueVariant_Exact Exact;
};
typedef union AzLayoutMaxHeightValue AzLayoutMaxHeightValue;

enum AzLayoutMaxWidthValueTag {
   AzLayoutMaxWidthValueTag_Auto,
   AzLayoutMaxWidthValueTag_None,
   AzLayoutMaxWidthValueTag_Inherit,
   AzLayoutMaxWidthValueTag_Initial,
   AzLayoutMaxWidthValueTag_Exact,
};
typedef enum AzLayoutMaxWidthValueTag AzLayoutMaxWidthValueTag;

struct AzLayoutMaxWidthValueVariant_Auto { AzLayoutMaxWidthValueTag tag; };
typedef struct AzLayoutMaxWidthValueVariant_Auto AzLayoutMaxWidthValueVariant_Auto;
struct AzLayoutMaxWidthValueVariant_None { AzLayoutMaxWidthValueTag tag; };
typedef struct AzLayoutMaxWidthValueVariant_None AzLayoutMaxWidthValueVariant_None;
struct AzLayoutMaxWidthValueVariant_Inherit { AzLayoutMaxWidthValueTag tag; };
typedef struct AzLayoutMaxWidthValueVariant_Inherit AzLayoutMaxWidthValueVariant_Inherit;
struct AzLayoutMaxWidthValueVariant_Initial { AzLayoutMaxWidthValueTag tag; };
typedef struct AzLayoutMaxWidthValueVariant_Initial AzLayoutMaxWidthValueVariant_Initial;
struct AzLayoutMaxWidthValueVariant_Exact { AzLayoutMaxWidthValueTag tag; AzLayoutMaxWidth payload; };
typedef struct AzLayoutMaxWidthValueVariant_Exact AzLayoutMaxWidthValueVariant_Exact;
union AzLayoutMaxWidthValue {
    AzLayoutMaxWidthValueVariant_Auto Auto;
    AzLayoutMaxWidthValueVariant_None None;
    AzLayoutMaxWidthValueVariant_Inherit Inherit;
    AzLayoutMaxWidthValueVariant_Initial Initial;
    AzLayoutMaxWidthValueVariant_Exact Exact;
};
typedef union AzLayoutMaxWidthValue AzLayoutMaxWidthValue;

enum AzLayoutMinHeightValueTag {
   AzLayoutMinHeightValueTag_Auto,
   AzLayoutMinHeightValueTag_None,
   AzLayoutMinHeightValueTag_Inherit,
   AzLayoutMinHeightValueTag_Initial,
   AzLayoutMinHeightValueTag_Exact,
};
typedef enum AzLayoutMinHeightValueTag AzLayoutMinHeightValueTag;

struct AzLayoutMinHeightValueVariant_Auto { AzLayoutMinHeightValueTag tag; };
typedef struct AzLayoutMinHeightValueVariant_Auto AzLayoutMinHeightValueVariant_Auto;
struct AzLayoutMinHeightValueVariant_None { AzLayoutMinHeightValueTag tag; };
typedef struct AzLayoutMinHeightValueVariant_None AzLayoutMinHeightValueVariant_None;
struct AzLayoutMinHeightValueVariant_Inherit { AzLayoutMinHeightValueTag tag; };
typedef struct AzLayoutMinHeightValueVariant_Inherit AzLayoutMinHeightValueVariant_Inherit;
struct AzLayoutMinHeightValueVariant_Initial { AzLayoutMinHeightValueTag tag; };
typedef struct AzLayoutMinHeightValueVariant_Initial AzLayoutMinHeightValueVariant_Initial;
struct AzLayoutMinHeightValueVariant_Exact { AzLayoutMinHeightValueTag tag; AzLayoutMinHeight payload; };
typedef struct AzLayoutMinHeightValueVariant_Exact AzLayoutMinHeightValueVariant_Exact;
union AzLayoutMinHeightValue {
    AzLayoutMinHeightValueVariant_Auto Auto;
    AzLayoutMinHeightValueVariant_None None;
    AzLayoutMinHeightValueVariant_Inherit Inherit;
    AzLayoutMinHeightValueVariant_Initial Initial;
    AzLayoutMinHeightValueVariant_Exact Exact;
};
typedef union AzLayoutMinHeightValue AzLayoutMinHeightValue;

enum AzLayoutMinWidthValueTag {
   AzLayoutMinWidthValueTag_Auto,
   AzLayoutMinWidthValueTag_None,
   AzLayoutMinWidthValueTag_Inherit,
   AzLayoutMinWidthValueTag_Initial,
   AzLayoutMinWidthValueTag_Exact,
};
typedef enum AzLayoutMinWidthValueTag AzLayoutMinWidthValueTag;

struct AzLayoutMinWidthValueVariant_Auto { AzLayoutMinWidthValueTag tag; };
typedef struct AzLayoutMinWidthValueVariant_Auto AzLayoutMinWidthValueVariant_Auto;
struct AzLayoutMinWidthValueVariant_None { AzLayoutMinWidthValueTag tag; };
typedef struct AzLayoutMinWidthValueVariant_None AzLayoutMinWidthValueVariant_None;
struct AzLayoutMinWidthValueVariant_Inherit { AzLayoutMinWidthValueTag tag; };
typedef struct AzLayoutMinWidthValueVariant_Inherit AzLayoutMinWidthValueVariant_Inherit;
struct AzLayoutMinWidthValueVariant_Initial { AzLayoutMinWidthValueTag tag; };
typedef struct AzLayoutMinWidthValueVariant_Initial AzLayoutMinWidthValueVariant_Initial;
struct AzLayoutMinWidthValueVariant_Exact { AzLayoutMinWidthValueTag tag; AzLayoutMinWidth payload; };
typedef struct AzLayoutMinWidthValueVariant_Exact AzLayoutMinWidthValueVariant_Exact;
union AzLayoutMinWidthValue {
    AzLayoutMinWidthValueVariant_Auto Auto;
    AzLayoutMinWidthValueVariant_None None;
    AzLayoutMinWidthValueVariant_Inherit Inherit;
    AzLayoutMinWidthValueVariant_Initial Initial;
    AzLayoutMinWidthValueVariant_Exact Exact;
};
typedef union AzLayoutMinWidthValue AzLayoutMinWidthValue;

enum AzLayoutPaddingBottomValueTag {
   AzLayoutPaddingBottomValueTag_Auto,
   AzLayoutPaddingBottomValueTag_None,
   AzLayoutPaddingBottomValueTag_Inherit,
   AzLayoutPaddingBottomValueTag_Initial,
   AzLayoutPaddingBottomValueTag_Exact,
};
typedef enum AzLayoutPaddingBottomValueTag AzLayoutPaddingBottomValueTag;

struct AzLayoutPaddingBottomValueVariant_Auto { AzLayoutPaddingBottomValueTag tag; };
typedef struct AzLayoutPaddingBottomValueVariant_Auto AzLayoutPaddingBottomValueVariant_Auto;
struct AzLayoutPaddingBottomValueVariant_None { AzLayoutPaddingBottomValueTag tag; };
typedef struct AzLayoutPaddingBottomValueVariant_None AzLayoutPaddingBottomValueVariant_None;
struct AzLayoutPaddingBottomValueVariant_Inherit { AzLayoutPaddingBottomValueTag tag; };
typedef struct AzLayoutPaddingBottomValueVariant_Inherit AzLayoutPaddingBottomValueVariant_Inherit;
struct AzLayoutPaddingBottomValueVariant_Initial { AzLayoutPaddingBottomValueTag tag; };
typedef struct AzLayoutPaddingBottomValueVariant_Initial AzLayoutPaddingBottomValueVariant_Initial;
struct AzLayoutPaddingBottomValueVariant_Exact { AzLayoutPaddingBottomValueTag tag; AzLayoutPaddingBottom payload; };
typedef struct AzLayoutPaddingBottomValueVariant_Exact AzLayoutPaddingBottomValueVariant_Exact;
union AzLayoutPaddingBottomValue {
    AzLayoutPaddingBottomValueVariant_Auto Auto;
    AzLayoutPaddingBottomValueVariant_None None;
    AzLayoutPaddingBottomValueVariant_Inherit Inherit;
    AzLayoutPaddingBottomValueVariant_Initial Initial;
    AzLayoutPaddingBottomValueVariant_Exact Exact;
};
typedef union AzLayoutPaddingBottomValue AzLayoutPaddingBottomValue;

enum AzLayoutPaddingLeftValueTag {
   AzLayoutPaddingLeftValueTag_Auto,
   AzLayoutPaddingLeftValueTag_None,
   AzLayoutPaddingLeftValueTag_Inherit,
   AzLayoutPaddingLeftValueTag_Initial,
   AzLayoutPaddingLeftValueTag_Exact,
};
typedef enum AzLayoutPaddingLeftValueTag AzLayoutPaddingLeftValueTag;

struct AzLayoutPaddingLeftValueVariant_Auto { AzLayoutPaddingLeftValueTag tag; };
typedef struct AzLayoutPaddingLeftValueVariant_Auto AzLayoutPaddingLeftValueVariant_Auto;
struct AzLayoutPaddingLeftValueVariant_None { AzLayoutPaddingLeftValueTag tag; };
typedef struct AzLayoutPaddingLeftValueVariant_None AzLayoutPaddingLeftValueVariant_None;
struct AzLayoutPaddingLeftValueVariant_Inherit { AzLayoutPaddingLeftValueTag tag; };
typedef struct AzLayoutPaddingLeftValueVariant_Inherit AzLayoutPaddingLeftValueVariant_Inherit;
struct AzLayoutPaddingLeftValueVariant_Initial { AzLayoutPaddingLeftValueTag tag; };
typedef struct AzLayoutPaddingLeftValueVariant_Initial AzLayoutPaddingLeftValueVariant_Initial;
struct AzLayoutPaddingLeftValueVariant_Exact { AzLayoutPaddingLeftValueTag tag; AzLayoutPaddingLeft payload; };
typedef struct AzLayoutPaddingLeftValueVariant_Exact AzLayoutPaddingLeftValueVariant_Exact;
union AzLayoutPaddingLeftValue {
    AzLayoutPaddingLeftValueVariant_Auto Auto;
    AzLayoutPaddingLeftValueVariant_None None;
    AzLayoutPaddingLeftValueVariant_Inherit Inherit;
    AzLayoutPaddingLeftValueVariant_Initial Initial;
    AzLayoutPaddingLeftValueVariant_Exact Exact;
};
typedef union AzLayoutPaddingLeftValue AzLayoutPaddingLeftValue;

enum AzLayoutPaddingRightValueTag {
   AzLayoutPaddingRightValueTag_Auto,
   AzLayoutPaddingRightValueTag_None,
   AzLayoutPaddingRightValueTag_Inherit,
   AzLayoutPaddingRightValueTag_Initial,
   AzLayoutPaddingRightValueTag_Exact,
};
typedef enum AzLayoutPaddingRightValueTag AzLayoutPaddingRightValueTag;

struct AzLayoutPaddingRightValueVariant_Auto { AzLayoutPaddingRightValueTag tag; };
typedef struct AzLayoutPaddingRightValueVariant_Auto AzLayoutPaddingRightValueVariant_Auto;
struct AzLayoutPaddingRightValueVariant_None { AzLayoutPaddingRightValueTag tag; };
typedef struct AzLayoutPaddingRightValueVariant_None AzLayoutPaddingRightValueVariant_None;
struct AzLayoutPaddingRightValueVariant_Inherit { AzLayoutPaddingRightValueTag tag; };
typedef struct AzLayoutPaddingRightValueVariant_Inherit AzLayoutPaddingRightValueVariant_Inherit;
struct AzLayoutPaddingRightValueVariant_Initial { AzLayoutPaddingRightValueTag tag; };
typedef struct AzLayoutPaddingRightValueVariant_Initial AzLayoutPaddingRightValueVariant_Initial;
struct AzLayoutPaddingRightValueVariant_Exact { AzLayoutPaddingRightValueTag tag; AzLayoutPaddingRight payload; };
typedef struct AzLayoutPaddingRightValueVariant_Exact AzLayoutPaddingRightValueVariant_Exact;
union AzLayoutPaddingRightValue {
    AzLayoutPaddingRightValueVariant_Auto Auto;
    AzLayoutPaddingRightValueVariant_None None;
    AzLayoutPaddingRightValueVariant_Inherit Inherit;
    AzLayoutPaddingRightValueVariant_Initial Initial;
    AzLayoutPaddingRightValueVariant_Exact Exact;
};
typedef union AzLayoutPaddingRightValue AzLayoutPaddingRightValue;

enum AzLayoutPaddingTopValueTag {
   AzLayoutPaddingTopValueTag_Auto,
   AzLayoutPaddingTopValueTag_None,
   AzLayoutPaddingTopValueTag_Inherit,
   AzLayoutPaddingTopValueTag_Initial,
   AzLayoutPaddingTopValueTag_Exact,
};
typedef enum AzLayoutPaddingTopValueTag AzLayoutPaddingTopValueTag;

struct AzLayoutPaddingTopValueVariant_Auto { AzLayoutPaddingTopValueTag tag; };
typedef struct AzLayoutPaddingTopValueVariant_Auto AzLayoutPaddingTopValueVariant_Auto;
struct AzLayoutPaddingTopValueVariant_None { AzLayoutPaddingTopValueTag tag; };
typedef struct AzLayoutPaddingTopValueVariant_None AzLayoutPaddingTopValueVariant_None;
struct AzLayoutPaddingTopValueVariant_Inherit { AzLayoutPaddingTopValueTag tag; };
typedef struct AzLayoutPaddingTopValueVariant_Inherit AzLayoutPaddingTopValueVariant_Inherit;
struct AzLayoutPaddingTopValueVariant_Initial { AzLayoutPaddingTopValueTag tag; };
typedef struct AzLayoutPaddingTopValueVariant_Initial AzLayoutPaddingTopValueVariant_Initial;
struct AzLayoutPaddingTopValueVariant_Exact { AzLayoutPaddingTopValueTag tag; AzLayoutPaddingTop payload; };
typedef struct AzLayoutPaddingTopValueVariant_Exact AzLayoutPaddingTopValueVariant_Exact;
union AzLayoutPaddingTopValue {
    AzLayoutPaddingTopValueVariant_Auto Auto;
    AzLayoutPaddingTopValueVariant_None None;
    AzLayoutPaddingTopValueVariant_Inherit Inherit;
    AzLayoutPaddingTopValueVariant_Initial Initial;
    AzLayoutPaddingTopValueVariant_Exact Exact;
};
typedef union AzLayoutPaddingTopValue AzLayoutPaddingTopValue;

enum AzLayoutPositionValueTag {
   AzLayoutPositionValueTag_Auto,
   AzLayoutPositionValueTag_None,
   AzLayoutPositionValueTag_Inherit,
   AzLayoutPositionValueTag_Initial,
   AzLayoutPositionValueTag_Exact,
};
typedef enum AzLayoutPositionValueTag AzLayoutPositionValueTag;

struct AzLayoutPositionValueVariant_Auto { AzLayoutPositionValueTag tag; };
typedef struct AzLayoutPositionValueVariant_Auto AzLayoutPositionValueVariant_Auto;
struct AzLayoutPositionValueVariant_None { AzLayoutPositionValueTag tag; };
typedef struct AzLayoutPositionValueVariant_None AzLayoutPositionValueVariant_None;
struct AzLayoutPositionValueVariant_Inherit { AzLayoutPositionValueTag tag; };
typedef struct AzLayoutPositionValueVariant_Inherit AzLayoutPositionValueVariant_Inherit;
struct AzLayoutPositionValueVariant_Initial { AzLayoutPositionValueTag tag; };
typedef struct AzLayoutPositionValueVariant_Initial AzLayoutPositionValueVariant_Initial;
struct AzLayoutPositionValueVariant_Exact { AzLayoutPositionValueTag tag; AzLayoutPosition payload; };
typedef struct AzLayoutPositionValueVariant_Exact AzLayoutPositionValueVariant_Exact;
union AzLayoutPositionValue {
    AzLayoutPositionValueVariant_Auto Auto;
    AzLayoutPositionValueVariant_None None;
    AzLayoutPositionValueVariant_Inherit Inherit;
    AzLayoutPositionValueVariant_Initial Initial;
    AzLayoutPositionValueVariant_Exact Exact;
};
typedef union AzLayoutPositionValue AzLayoutPositionValue;

enum AzLayoutRightValueTag {
   AzLayoutRightValueTag_Auto,
   AzLayoutRightValueTag_None,
   AzLayoutRightValueTag_Inherit,
   AzLayoutRightValueTag_Initial,
   AzLayoutRightValueTag_Exact,
};
typedef enum AzLayoutRightValueTag AzLayoutRightValueTag;

struct AzLayoutRightValueVariant_Auto { AzLayoutRightValueTag tag; };
typedef struct AzLayoutRightValueVariant_Auto AzLayoutRightValueVariant_Auto;
struct AzLayoutRightValueVariant_None { AzLayoutRightValueTag tag; };
typedef struct AzLayoutRightValueVariant_None AzLayoutRightValueVariant_None;
struct AzLayoutRightValueVariant_Inherit { AzLayoutRightValueTag tag; };
typedef struct AzLayoutRightValueVariant_Inherit AzLayoutRightValueVariant_Inherit;
struct AzLayoutRightValueVariant_Initial { AzLayoutRightValueTag tag; };
typedef struct AzLayoutRightValueVariant_Initial AzLayoutRightValueVariant_Initial;
struct AzLayoutRightValueVariant_Exact { AzLayoutRightValueTag tag; AzLayoutRight payload; };
typedef struct AzLayoutRightValueVariant_Exact AzLayoutRightValueVariant_Exact;
union AzLayoutRightValue {
    AzLayoutRightValueVariant_Auto Auto;
    AzLayoutRightValueVariant_None None;
    AzLayoutRightValueVariant_Inherit Inherit;
    AzLayoutRightValueVariant_Initial Initial;
    AzLayoutRightValueVariant_Exact Exact;
};
typedef union AzLayoutRightValue AzLayoutRightValue;

enum AzLayoutTopValueTag {
   AzLayoutTopValueTag_Auto,
   AzLayoutTopValueTag_None,
   AzLayoutTopValueTag_Inherit,
   AzLayoutTopValueTag_Initial,
   AzLayoutTopValueTag_Exact,
};
typedef enum AzLayoutTopValueTag AzLayoutTopValueTag;

struct AzLayoutTopValueVariant_Auto { AzLayoutTopValueTag tag; };
typedef struct AzLayoutTopValueVariant_Auto AzLayoutTopValueVariant_Auto;
struct AzLayoutTopValueVariant_None { AzLayoutTopValueTag tag; };
typedef struct AzLayoutTopValueVariant_None AzLayoutTopValueVariant_None;
struct AzLayoutTopValueVariant_Inherit { AzLayoutTopValueTag tag; };
typedef struct AzLayoutTopValueVariant_Inherit AzLayoutTopValueVariant_Inherit;
struct AzLayoutTopValueVariant_Initial { AzLayoutTopValueTag tag; };
typedef struct AzLayoutTopValueVariant_Initial AzLayoutTopValueVariant_Initial;
struct AzLayoutTopValueVariant_Exact { AzLayoutTopValueTag tag; AzLayoutTop payload; };
typedef struct AzLayoutTopValueVariant_Exact AzLayoutTopValueVariant_Exact;
union AzLayoutTopValue {
    AzLayoutTopValueVariant_Auto Auto;
    AzLayoutTopValueVariant_None None;
    AzLayoutTopValueVariant_Inherit Inherit;
    AzLayoutTopValueVariant_Initial Initial;
    AzLayoutTopValueVariant_Exact Exact;
};
typedef union AzLayoutTopValue AzLayoutTopValue;

enum AzLayoutWidthValueTag {
   AzLayoutWidthValueTag_Auto,
   AzLayoutWidthValueTag_None,
   AzLayoutWidthValueTag_Inherit,
   AzLayoutWidthValueTag_Initial,
   AzLayoutWidthValueTag_Exact,
};
typedef enum AzLayoutWidthValueTag AzLayoutWidthValueTag;

struct AzLayoutWidthValueVariant_Auto { AzLayoutWidthValueTag tag; };
typedef struct AzLayoutWidthValueVariant_Auto AzLayoutWidthValueVariant_Auto;
struct AzLayoutWidthValueVariant_None { AzLayoutWidthValueTag tag; };
typedef struct AzLayoutWidthValueVariant_None AzLayoutWidthValueVariant_None;
struct AzLayoutWidthValueVariant_Inherit { AzLayoutWidthValueTag tag; };
typedef struct AzLayoutWidthValueVariant_Inherit AzLayoutWidthValueVariant_Inherit;
struct AzLayoutWidthValueVariant_Initial { AzLayoutWidthValueTag tag; };
typedef struct AzLayoutWidthValueVariant_Initial AzLayoutWidthValueVariant_Initial;
struct AzLayoutWidthValueVariant_Exact { AzLayoutWidthValueTag tag; AzLayoutWidth payload; };
typedef struct AzLayoutWidthValueVariant_Exact AzLayoutWidthValueVariant_Exact;
union AzLayoutWidthValue {
    AzLayoutWidthValueVariant_Auto Auto;
    AzLayoutWidthValueVariant_None None;
    AzLayoutWidthValueVariant_Inherit Inherit;
    AzLayoutWidthValueVariant_Initial Initial;
    AzLayoutWidthValueVariant_Exact Exact;
};
typedef union AzLayoutWidthValue AzLayoutWidthValue;

enum AzLayoutFlexWrapValueTag {
   AzLayoutFlexWrapValueTag_Auto,
   AzLayoutFlexWrapValueTag_None,
   AzLayoutFlexWrapValueTag_Inherit,
   AzLayoutFlexWrapValueTag_Initial,
   AzLayoutFlexWrapValueTag_Exact,
};
typedef enum AzLayoutFlexWrapValueTag AzLayoutFlexWrapValueTag;

struct AzLayoutFlexWrapValueVariant_Auto { AzLayoutFlexWrapValueTag tag; };
typedef struct AzLayoutFlexWrapValueVariant_Auto AzLayoutFlexWrapValueVariant_Auto;
struct AzLayoutFlexWrapValueVariant_None { AzLayoutFlexWrapValueTag tag; };
typedef struct AzLayoutFlexWrapValueVariant_None AzLayoutFlexWrapValueVariant_None;
struct AzLayoutFlexWrapValueVariant_Inherit { AzLayoutFlexWrapValueTag tag; };
typedef struct AzLayoutFlexWrapValueVariant_Inherit AzLayoutFlexWrapValueVariant_Inherit;
struct AzLayoutFlexWrapValueVariant_Initial { AzLayoutFlexWrapValueTag tag; };
typedef struct AzLayoutFlexWrapValueVariant_Initial AzLayoutFlexWrapValueVariant_Initial;
struct AzLayoutFlexWrapValueVariant_Exact { AzLayoutFlexWrapValueTag tag; AzLayoutFlexWrap payload; };
typedef struct AzLayoutFlexWrapValueVariant_Exact AzLayoutFlexWrapValueVariant_Exact;
union AzLayoutFlexWrapValue {
    AzLayoutFlexWrapValueVariant_Auto Auto;
    AzLayoutFlexWrapValueVariant_None None;
    AzLayoutFlexWrapValueVariant_Inherit Inherit;
    AzLayoutFlexWrapValueVariant_Initial Initial;
    AzLayoutFlexWrapValueVariant_Exact Exact;
};
typedef union AzLayoutFlexWrapValue AzLayoutFlexWrapValue;

enum AzLayoutOverflowValueTag {
   AzLayoutOverflowValueTag_Auto,
   AzLayoutOverflowValueTag_None,
   AzLayoutOverflowValueTag_Inherit,
   AzLayoutOverflowValueTag_Initial,
   AzLayoutOverflowValueTag_Exact,
};
typedef enum AzLayoutOverflowValueTag AzLayoutOverflowValueTag;

struct AzLayoutOverflowValueVariant_Auto { AzLayoutOverflowValueTag tag; };
typedef struct AzLayoutOverflowValueVariant_Auto AzLayoutOverflowValueVariant_Auto;
struct AzLayoutOverflowValueVariant_None { AzLayoutOverflowValueTag tag; };
typedef struct AzLayoutOverflowValueVariant_None AzLayoutOverflowValueVariant_None;
struct AzLayoutOverflowValueVariant_Inherit { AzLayoutOverflowValueTag tag; };
typedef struct AzLayoutOverflowValueVariant_Inherit AzLayoutOverflowValueVariant_Inherit;
struct AzLayoutOverflowValueVariant_Initial { AzLayoutOverflowValueTag tag; };
typedef struct AzLayoutOverflowValueVariant_Initial AzLayoutOverflowValueVariant_Initial;
struct AzLayoutOverflowValueVariant_Exact { AzLayoutOverflowValueTag tag; AzLayoutOverflow payload; };
typedef struct AzLayoutOverflowValueVariant_Exact AzLayoutOverflowValueVariant_Exact;
union AzLayoutOverflowValue {
    AzLayoutOverflowValueVariant_Auto Auto;
    AzLayoutOverflowValueVariant_None None;
    AzLayoutOverflowValueVariant_Inherit Inherit;
    AzLayoutOverflowValueVariant_Initial Initial;
    AzLayoutOverflowValueVariant_Exact Exact;
};
typedef union AzLayoutOverflowValue AzLayoutOverflowValue;

enum AzStyleBorderBottomColorValueTag {
   AzStyleBorderBottomColorValueTag_Auto,
   AzStyleBorderBottomColorValueTag_None,
   AzStyleBorderBottomColorValueTag_Inherit,
   AzStyleBorderBottomColorValueTag_Initial,
   AzStyleBorderBottomColorValueTag_Exact,
};
typedef enum AzStyleBorderBottomColorValueTag AzStyleBorderBottomColorValueTag;

struct AzStyleBorderBottomColorValueVariant_Auto { AzStyleBorderBottomColorValueTag tag; };
typedef struct AzStyleBorderBottomColorValueVariant_Auto AzStyleBorderBottomColorValueVariant_Auto;
struct AzStyleBorderBottomColorValueVariant_None { AzStyleBorderBottomColorValueTag tag; };
typedef struct AzStyleBorderBottomColorValueVariant_None AzStyleBorderBottomColorValueVariant_None;
struct AzStyleBorderBottomColorValueVariant_Inherit { AzStyleBorderBottomColorValueTag tag; };
typedef struct AzStyleBorderBottomColorValueVariant_Inherit AzStyleBorderBottomColorValueVariant_Inherit;
struct AzStyleBorderBottomColorValueVariant_Initial { AzStyleBorderBottomColorValueTag tag; };
typedef struct AzStyleBorderBottomColorValueVariant_Initial AzStyleBorderBottomColorValueVariant_Initial;
struct AzStyleBorderBottomColorValueVariant_Exact { AzStyleBorderBottomColorValueTag tag; AzStyleBorderBottomColor payload; };
typedef struct AzStyleBorderBottomColorValueVariant_Exact AzStyleBorderBottomColorValueVariant_Exact;
union AzStyleBorderBottomColorValue {
    AzStyleBorderBottomColorValueVariant_Auto Auto;
    AzStyleBorderBottomColorValueVariant_None None;
    AzStyleBorderBottomColorValueVariant_Inherit Inherit;
    AzStyleBorderBottomColorValueVariant_Initial Initial;
    AzStyleBorderBottomColorValueVariant_Exact Exact;
};
typedef union AzStyleBorderBottomColorValue AzStyleBorderBottomColorValue;

enum AzStyleBorderBottomLeftRadiusValueTag {
   AzStyleBorderBottomLeftRadiusValueTag_Auto,
   AzStyleBorderBottomLeftRadiusValueTag_None,
   AzStyleBorderBottomLeftRadiusValueTag_Inherit,
   AzStyleBorderBottomLeftRadiusValueTag_Initial,
   AzStyleBorderBottomLeftRadiusValueTag_Exact,
};
typedef enum AzStyleBorderBottomLeftRadiusValueTag AzStyleBorderBottomLeftRadiusValueTag;

struct AzStyleBorderBottomLeftRadiusValueVariant_Auto { AzStyleBorderBottomLeftRadiusValueTag tag; };
typedef struct AzStyleBorderBottomLeftRadiusValueVariant_Auto AzStyleBorderBottomLeftRadiusValueVariant_Auto;
struct AzStyleBorderBottomLeftRadiusValueVariant_None { AzStyleBorderBottomLeftRadiusValueTag tag; };
typedef struct AzStyleBorderBottomLeftRadiusValueVariant_None AzStyleBorderBottomLeftRadiusValueVariant_None;
struct AzStyleBorderBottomLeftRadiusValueVariant_Inherit { AzStyleBorderBottomLeftRadiusValueTag tag; };
typedef struct AzStyleBorderBottomLeftRadiusValueVariant_Inherit AzStyleBorderBottomLeftRadiusValueVariant_Inherit;
struct AzStyleBorderBottomLeftRadiusValueVariant_Initial { AzStyleBorderBottomLeftRadiusValueTag tag; };
typedef struct AzStyleBorderBottomLeftRadiusValueVariant_Initial AzStyleBorderBottomLeftRadiusValueVariant_Initial;
struct AzStyleBorderBottomLeftRadiusValueVariant_Exact { AzStyleBorderBottomLeftRadiusValueTag tag; AzStyleBorderBottomLeftRadius payload; };
typedef struct AzStyleBorderBottomLeftRadiusValueVariant_Exact AzStyleBorderBottomLeftRadiusValueVariant_Exact;
union AzStyleBorderBottomLeftRadiusValue {
    AzStyleBorderBottomLeftRadiusValueVariant_Auto Auto;
    AzStyleBorderBottomLeftRadiusValueVariant_None None;
    AzStyleBorderBottomLeftRadiusValueVariant_Inherit Inherit;
    AzStyleBorderBottomLeftRadiusValueVariant_Initial Initial;
    AzStyleBorderBottomLeftRadiusValueVariant_Exact Exact;
};
typedef union AzStyleBorderBottomLeftRadiusValue AzStyleBorderBottomLeftRadiusValue;

enum AzStyleBorderBottomRightRadiusValueTag {
   AzStyleBorderBottomRightRadiusValueTag_Auto,
   AzStyleBorderBottomRightRadiusValueTag_None,
   AzStyleBorderBottomRightRadiusValueTag_Inherit,
   AzStyleBorderBottomRightRadiusValueTag_Initial,
   AzStyleBorderBottomRightRadiusValueTag_Exact,
};
typedef enum AzStyleBorderBottomRightRadiusValueTag AzStyleBorderBottomRightRadiusValueTag;

struct AzStyleBorderBottomRightRadiusValueVariant_Auto { AzStyleBorderBottomRightRadiusValueTag tag; };
typedef struct AzStyleBorderBottomRightRadiusValueVariant_Auto AzStyleBorderBottomRightRadiusValueVariant_Auto;
struct AzStyleBorderBottomRightRadiusValueVariant_None { AzStyleBorderBottomRightRadiusValueTag tag; };
typedef struct AzStyleBorderBottomRightRadiusValueVariant_None AzStyleBorderBottomRightRadiusValueVariant_None;
struct AzStyleBorderBottomRightRadiusValueVariant_Inherit { AzStyleBorderBottomRightRadiusValueTag tag; };
typedef struct AzStyleBorderBottomRightRadiusValueVariant_Inherit AzStyleBorderBottomRightRadiusValueVariant_Inherit;
struct AzStyleBorderBottomRightRadiusValueVariant_Initial { AzStyleBorderBottomRightRadiusValueTag tag; };
typedef struct AzStyleBorderBottomRightRadiusValueVariant_Initial AzStyleBorderBottomRightRadiusValueVariant_Initial;
struct AzStyleBorderBottomRightRadiusValueVariant_Exact { AzStyleBorderBottomRightRadiusValueTag tag; AzStyleBorderBottomRightRadius payload; };
typedef struct AzStyleBorderBottomRightRadiusValueVariant_Exact AzStyleBorderBottomRightRadiusValueVariant_Exact;
union AzStyleBorderBottomRightRadiusValue {
    AzStyleBorderBottomRightRadiusValueVariant_Auto Auto;
    AzStyleBorderBottomRightRadiusValueVariant_None None;
    AzStyleBorderBottomRightRadiusValueVariant_Inherit Inherit;
    AzStyleBorderBottomRightRadiusValueVariant_Initial Initial;
    AzStyleBorderBottomRightRadiusValueVariant_Exact Exact;
};
typedef union AzStyleBorderBottomRightRadiusValue AzStyleBorderBottomRightRadiusValue;

enum AzStyleBorderBottomStyleValueTag {
   AzStyleBorderBottomStyleValueTag_Auto,
   AzStyleBorderBottomStyleValueTag_None,
   AzStyleBorderBottomStyleValueTag_Inherit,
   AzStyleBorderBottomStyleValueTag_Initial,
   AzStyleBorderBottomStyleValueTag_Exact,
};
typedef enum AzStyleBorderBottomStyleValueTag AzStyleBorderBottomStyleValueTag;

struct AzStyleBorderBottomStyleValueVariant_Auto { AzStyleBorderBottomStyleValueTag tag; };
typedef struct AzStyleBorderBottomStyleValueVariant_Auto AzStyleBorderBottomStyleValueVariant_Auto;
struct AzStyleBorderBottomStyleValueVariant_None { AzStyleBorderBottomStyleValueTag tag; };
typedef struct AzStyleBorderBottomStyleValueVariant_None AzStyleBorderBottomStyleValueVariant_None;
struct AzStyleBorderBottomStyleValueVariant_Inherit { AzStyleBorderBottomStyleValueTag tag; };
typedef struct AzStyleBorderBottomStyleValueVariant_Inherit AzStyleBorderBottomStyleValueVariant_Inherit;
struct AzStyleBorderBottomStyleValueVariant_Initial { AzStyleBorderBottomStyleValueTag tag; };
typedef struct AzStyleBorderBottomStyleValueVariant_Initial AzStyleBorderBottomStyleValueVariant_Initial;
struct AzStyleBorderBottomStyleValueVariant_Exact { AzStyleBorderBottomStyleValueTag tag; AzStyleBorderBottomStyle payload; };
typedef struct AzStyleBorderBottomStyleValueVariant_Exact AzStyleBorderBottomStyleValueVariant_Exact;
union AzStyleBorderBottomStyleValue {
    AzStyleBorderBottomStyleValueVariant_Auto Auto;
    AzStyleBorderBottomStyleValueVariant_None None;
    AzStyleBorderBottomStyleValueVariant_Inherit Inherit;
    AzStyleBorderBottomStyleValueVariant_Initial Initial;
    AzStyleBorderBottomStyleValueVariant_Exact Exact;
};
typedef union AzStyleBorderBottomStyleValue AzStyleBorderBottomStyleValue;

enum AzLayoutBorderBottomWidthValueTag {
   AzLayoutBorderBottomWidthValueTag_Auto,
   AzLayoutBorderBottomWidthValueTag_None,
   AzLayoutBorderBottomWidthValueTag_Inherit,
   AzLayoutBorderBottomWidthValueTag_Initial,
   AzLayoutBorderBottomWidthValueTag_Exact,
};
typedef enum AzLayoutBorderBottomWidthValueTag AzLayoutBorderBottomWidthValueTag;

struct AzLayoutBorderBottomWidthValueVariant_Auto { AzLayoutBorderBottomWidthValueTag tag; };
typedef struct AzLayoutBorderBottomWidthValueVariant_Auto AzLayoutBorderBottomWidthValueVariant_Auto;
struct AzLayoutBorderBottomWidthValueVariant_None { AzLayoutBorderBottomWidthValueTag tag; };
typedef struct AzLayoutBorderBottomWidthValueVariant_None AzLayoutBorderBottomWidthValueVariant_None;
struct AzLayoutBorderBottomWidthValueVariant_Inherit { AzLayoutBorderBottomWidthValueTag tag; };
typedef struct AzLayoutBorderBottomWidthValueVariant_Inherit AzLayoutBorderBottomWidthValueVariant_Inherit;
struct AzLayoutBorderBottomWidthValueVariant_Initial { AzLayoutBorderBottomWidthValueTag tag; };
typedef struct AzLayoutBorderBottomWidthValueVariant_Initial AzLayoutBorderBottomWidthValueVariant_Initial;
struct AzLayoutBorderBottomWidthValueVariant_Exact { AzLayoutBorderBottomWidthValueTag tag; AzLayoutBorderBottomWidth payload; };
typedef struct AzLayoutBorderBottomWidthValueVariant_Exact AzLayoutBorderBottomWidthValueVariant_Exact;
union AzLayoutBorderBottomWidthValue {
    AzLayoutBorderBottomWidthValueVariant_Auto Auto;
    AzLayoutBorderBottomWidthValueVariant_None None;
    AzLayoutBorderBottomWidthValueVariant_Inherit Inherit;
    AzLayoutBorderBottomWidthValueVariant_Initial Initial;
    AzLayoutBorderBottomWidthValueVariant_Exact Exact;
};
typedef union AzLayoutBorderBottomWidthValue AzLayoutBorderBottomWidthValue;

enum AzStyleBorderLeftColorValueTag {
   AzStyleBorderLeftColorValueTag_Auto,
   AzStyleBorderLeftColorValueTag_None,
   AzStyleBorderLeftColorValueTag_Inherit,
   AzStyleBorderLeftColorValueTag_Initial,
   AzStyleBorderLeftColorValueTag_Exact,
};
typedef enum AzStyleBorderLeftColorValueTag AzStyleBorderLeftColorValueTag;

struct AzStyleBorderLeftColorValueVariant_Auto { AzStyleBorderLeftColorValueTag tag; };
typedef struct AzStyleBorderLeftColorValueVariant_Auto AzStyleBorderLeftColorValueVariant_Auto;
struct AzStyleBorderLeftColorValueVariant_None { AzStyleBorderLeftColorValueTag tag; };
typedef struct AzStyleBorderLeftColorValueVariant_None AzStyleBorderLeftColorValueVariant_None;
struct AzStyleBorderLeftColorValueVariant_Inherit { AzStyleBorderLeftColorValueTag tag; };
typedef struct AzStyleBorderLeftColorValueVariant_Inherit AzStyleBorderLeftColorValueVariant_Inherit;
struct AzStyleBorderLeftColorValueVariant_Initial { AzStyleBorderLeftColorValueTag tag; };
typedef struct AzStyleBorderLeftColorValueVariant_Initial AzStyleBorderLeftColorValueVariant_Initial;
struct AzStyleBorderLeftColorValueVariant_Exact { AzStyleBorderLeftColorValueTag tag; AzStyleBorderLeftColor payload; };
typedef struct AzStyleBorderLeftColorValueVariant_Exact AzStyleBorderLeftColorValueVariant_Exact;
union AzStyleBorderLeftColorValue {
    AzStyleBorderLeftColorValueVariant_Auto Auto;
    AzStyleBorderLeftColorValueVariant_None None;
    AzStyleBorderLeftColorValueVariant_Inherit Inherit;
    AzStyleBorderLeftColorValueVariant_Initial Initial;
    AzStyleBorderLeftColorValueVariant_Exact Exact;
};
typedef union AzStyleBorderLeftColorValue AzStyleBorderLeftColorValue;

enum AzStyleBorderLeftStyleValueTag {
   AzStyleBorderLeftStyleValueTag_Auto,
   AzStyleBorderLeftStyleValueTag_None,
   AzStyleBorderLeftStyleValueTag_Inherit,
   AzStyleBorderLeftStyleValueTag_Initial,
   AzStyleBorderLeftStyleValueTag_Exact,
};
typedef enum AzStyleBorderLeftStyleValueTag AzStyleBorderLeftStyleValueTag;

struct AzStyleBorderLeftStyleValueVariant_Auto { AzStyleBorderLeftStyleValueTag tag; };
typedef struct AzStyleBorderLeftStyleValueVariant_Auto AzStyleBorderLeftStyleValueVariant_Auto;
struct AzStyleBorderLeftStyleValueVariant_None { AzStyleBorderLeftStyleValueTag tag; };
typedef struct AzStyleBorderLeftStyleValueVariant_None AzStyleBorderLeftStyleValueVariant_None;
struct AzStyleBorderLeftStyleValueVariant_Inherit { AzStyleBorderLeftStyleValueTag tag; };
typedef struct AzStyleBorderLeftStyleValueVariant_Inherit AzStyleBorderLeftStyleValueVariant_Inherit;
struct AzStyleBorderLeftStyleValueVariant_Initial { AzStyleBorderLeftStyleValueTag tag; };
typedef struct AzStyleBorderLeftStyleValueVariant_Initial AzStyleBorderLeftStyleValueVariant_Initial;
struct AzStyleBorderLeftStyleValueVariant_Exact { AzStyleBorderLeftStyleValueTag tag; AzStyleBorderLeftStyle payload; };
typedef struct AzStyleBorderLeftStyleValueVariant_Exact AzStyleBorderLeftStyleValueVariant_Exact;
union AzStyleBorderLeftStyleValue {
    AzStyleBorderLeftStyleValueVariant_Auto Auto;
    AzStyleBorderLeftStyleValueVariant_None None;
    AzStyleBorderLeftStyleValueVariant_Inherit Inherit;
    AzStyleBorderLeftStyleValueVariant_Initial Initial;
    AzStyleBorderLeftStyleValueVariant_Exact Exact;
};
typedef union AzStyleBorderLeftStyleValue AzStyleBorderLeftStyleValue;

enum AzLayoutBorderLeftWidthValueTag {
   AzLayoutBorderLeftWidthValueTag_Auto,
   AzLayoutBorderLeftWidthValueTag_None,
   AzLayoutBorderLeftWidthValueTag_Inherit,
   AzLayoutBorderLeftWidthValueTag_Initial,
   AzLayoutBorderLeftWidthValueTag_Exact,
};
typedef enum AzLayoutBorderLeftWidthValueTag AzLayoutBorderLeftWidthValueTag;

struct AzLayoutBorderLeftWidthValueVariant_Auto { AzLayoutBorderLeftWidthValueTag tag; };
typedef struct AzLayoutBorderLeftWidthValueVariant_Auto AzLayoutBorderLeftWidthValueVariant_Auto;
struct AzLayoutBorderLeftWidthValueVariant_None { AzLayoutBorderLeftWidthValueTag tag; };
typedef struct AzLayoutBorderLeftWidthValueVariant_None AzLayoutBorderLeftWidthValueVariant_None;
struct AzLayoutBorderLeftWidthValueVariant_Inherit { AzLayoutBorderLeftWidthValueTag tag; };
typedef struct AzLayoutBorderLeftWidthValueVariant_Inherit AzLayoutBorderLeftWidthValueVariant_Inherit;
struct AzLayoutBorderLeftWidthValueVariant_Initial { AzLayoutBorderLeftWidthValueTag tag; };
typedef struct AzLayoutBorderLeftWidthValueVariant_Initial AzLayoutBorderLeftWidthValueVariant_Initial;
struct AzLayoutBorderLeftWidthValueVariant_Exact { AzLayoutBorderLeftWidthValueTag tag; AzLayoutBorderLeftWidth payload; };
typedef struct AzLayoutBorderLeftWidthValueVariant_Exact AzLayoutBorderLeftWidthValueVariant_Exact;
union AzLayoutBorderLeftWidthValue {
    AzLayoutBorderLeftWidthValueVariant_Auto Auto;
    AzLayoutBorderLeftWidthValueVariant_None None;
    AzLayoutBorderLeftWidthValueVariant_Inherit Inherit;
    AzLayoutBorderLeftWidthValueVariant_Initial Initial;
    AzLayoutBorderLeftWidthValueVariant_Exact Exact;
};
typedef union AzLayoutBorderLeftWidthValue AzLayoutBorderLeftWidthValue;

enum AzStyleBorderRightColorValueTag {
   AzStyleBorderRightColorValueTag_Auto,
   AzStyleBorderRightColorValueTag_None,
   AzStyleBorderRightColorValueTag_Inherit,
   AzStyleBorderRightColorValueTag_Initial,
   AzStyleBorderRightColorValueTag_Exact,
};
typedef enum AzStyleBorderRightColorValueTag AzStyleBorderRightColorValueTag;

struct AzStyleBorderRightColorValueVariant_Auto { AzStyleBorderRightColorValueTag tag; };
typedef struct AzStyleBorderRightColorValueVariant_Auto AzStyleBorderRightColorValueVariant_Auto;
struct AzStyleBorderRightColorValueVariant_None { AzStyleBorderRightColorValueTag tag; };
typedef struct AzStyleBorderRightColorValueVariant_None AzStyleBorderRightColorValueVariant_None;
struct AzStyleBorderRightColorValueVariant_Inherit { AzStyleBorderRightColorValueTag tag; };
typedef struct AzStyleBorderRightColorValueVariant_Inherit AzStyleBorderRightColorValueVariant_Inherit;
struct AzStyleBorderRightColorValueVariant_Initial { AzStyleBorderRightColorValueTag tag; };
typedef struct AzStyleBorderRightColorValueVariant_Initial AzStyleBorderRightColorValueVariant_Initial;
struct AzStyleBorderRightColorValueVariant_Exact { AzStyleBorderRightColorValueTag tag; AzStyleBorderRightColor payload; };
typedef struct AzStyleBorderRightColorValueVariant_Exact AzStyleBorderRightColorValueVariant_Exact;
union AzStyleBorderRightColorValue {
    AzStyleBorderRightColorValueVariant_Auto Auto;
    AzStyleBorderRightColorValueVariant_None None;
    AzStyleBorderRightColorValueVariant_Inherit Inherit;
    AzStyleBorderRightColorValueVariant_Initial Initial;
    AzStyleBorderRightColorValueVariant_Exact Exact;
};
typedef union AzStyleBorderRightColorValue AzStyleBorderRightColorValue;

enum AzStyleBorderRightStyleValueTag {
   AzStyleBorderRightStyleValueTag_Auto,
   AzStyleBorderRightStyleValueTag_None,
   AzStyleBorderRightStyleValueTag_Inherit,
   AzStyleBorderRightStyleValueTag_Initial,
   AzStyleBorderRightStyleValueTag_Exact,
};
typedef enum AzStyleBorderRightStyleValueTag AzStyleBorderRightStyleValueTag;

struct AzStyleBorderRightStyleValueVariant_Auto { AzStyleBorderRightStyleValueTag tag; };
typedef struct AzStyleBorderRightStyleValueVariant_Auto AzStyleBorderRightStyleValueVariant_Auto;
struct AzStyleBorderRightStyleValueVariant_None { AzStyleBorderRightStyleValueTag tag; };
typedef struct AzStyleBorderRightStyleValueVariant_None AzStyleBorderRightStyleValueVariant_None;
struct AzStyleBorderRightStyleValueVariant_Inherit { AzStyleBorderRightStyleValueTag tag; };
typedef struct AzStyleBorderRightStyleValueVariant_Inherit AzStyleBorderRightStyleValueVariant_Inherit;
struct AzStyleBorderRightStyleValueVariant_Initial { AzStyleBorderRightStyleValueTag tag; };
typedef struct AzStyleBorderRightStyleValueVariant_Initial AzStyleBorderRightStyleValueVariant_Initial;
struct AzStyleBorderRightStyleValueVariant_Exact { AzStyleBorderRightStyleValueTag tag; AzStyleBorderRightStyle payload; };
typedef struct AzStyleBorderRightStyleValueVariant_Exact AzStyleBorderRightStyleValueVariant_Exact;
union AzStyleBorderRightStyleValue {
    AzStyleBorderRightStyleValueVariant_Auto Auto;
    AzStyleBorderRightStyleValueVariant_None None;
    AzStyleBorderRightStyleValueVariant_Inherit Inherit;
    AzStyleBorderRightStyleValueVariant_Initial Initial;
    AzStyleBorderRightStyleValueVariant_Exact Exact;
};
typedef union AzStyleBorderRightStyleValue AzStyleBorderRightStyleValue;

enum AzLayoutBorderRightWidthValueTag {
   AzLayoutBorderRightWidthValueTag_Auto,
   AzLayoutBorderRightWidthValueTag_None,
   AzLayoutBorderRightWidthValueTag_Inherit,
   AzLayoutBorderRightWidthValueTag_Initial,
   AzLayoutBorderRightWidthValueTag_Exact,
};
typedef enum AzLayoutBorderRightWidthValueTag AzLayoutBorderRightWidthValueTag;

struct AzLayoutBorderRightWidthValueVariant_Auto { AzLayoutBorderRightWidthValueTag tag; };
typedef struct AzLayoutBorderRightWidthValueVariant_Auto AzLayoutBorderRightWidthValueVariant_Auto;
struct AzLayoutBorderRightWidthValueVariant_None { AzLayoutBorderRightWidthValueTag tag; };
typedef struct AzLayoutBorderRightWidthValueVariant_None AzLayoutBorderRightWidthValueVariant_None;
struct AzLayoutBorderRightWidthValueVariant_Inherit { AzLayoutBorderRightWidthValueTag tag; };
typedef struct AzLayoutBorderRightWidthValueVariant_Inherit AzLayoutBorderRightWidthValueVariant_Inherit;
struct AzLayoutBorderRightWidthValueVariant_Initial { AzLayoutBorderRightWidthValueTag tag; };
typedef struct AzLayoutBorderRightWidthValueVariant_Initial AzLayoutBorderRightWidthValueVariant_Initial;
struct AzLayoutBorderRightWidthValueVariant_Exact { AzLayoutBorderRightWidthValueTag tag; AzLayoutBorderRightWidth payload; };
typedef struct AzLayoutBorderRightWidthValueVariant_Exact AzLayoutBorderRightWidthValueVariant_Exact;
union AzLayoutBorderRightWidthValue {
    AzLayoutBorderRightWidthValueVariant_Auto Auto;
    AzLayoutBorderRightWidthValueVariant_None None;
    AzLayoutBorderRightWidthValueVariant_Inherit Inherit;
    AzLayoutBorderRightWidthValueVariant_Initial Initial;
    AzLayoutBorderRightWidthValueVariant_Exact Exact;
};
typedef union AzLayoutBorderRightWidthValue AzLayoutBorderRightWidthValue;

enum AzStyleBorderTopColorValueTag {
   AzStyleBorderTopColorValueTag_Auto,
   AzStyleBorderTopColorValueTag_None,
   AzStyleBorderTopColorValueTag_Inherit,
   AzStyleBorderTopColorValueTag_Initial,
   AzStyleBorderTopColorValueTag_Exact,
};
typedef enum AzStyleBorderTopColorValueTag AzStyleBorderTopColorValueTag;

struct AzStyleBorderTopColorValueVariant_Auto { AzStyleBorderTopColorValueTag tag; };
typedef struct AzStyleBorderTopColorValueVariant_Auto AzStyleBorderTopColorValueVariant_Auto;
struct AzStyleBorderTopColorValueVariant_None { AzStyleBorderTopColorValueTag tag; };
typedef struct AzStyleBorderTopColorValueVariant_None AzStyleBorderTopColorValueVariant_None;
struct AzStyleBorderTopColorValueVariant_Inherit { AzStyleBorderTopColorValueTag tag; };
typedef struct AzStyleBorderTopColorValueVariant_Inherit AzStyleBorderTopColorValueVariant_Inherit;
struct AzStyleBorderTopColorValueVariant_Initial { AzStyleBorderTopColorValueTag tag; };
typedef struct AzStyleBorderTopColorValueVariant_Initial AzStyleBorderTopColorValueVariant_Initial;
struct AzStyleBorderTopColorValueVariant_Exact { AzStyleBorderTopColorValueTag tag; AzStyleBorderTopColor payload; };
typedef struct AzStyleBorderTopColorValueVariant_Exact AzStyleBorderTopColorValueVariant_Exact;
union AzStyleBorderTopColorValue {
    AzStyleBorderTopColorValueVariant_Auto Auto;
    AzStyleBorderTopColorValueVariant_None None;
    AzStyleBorderTopColorValueVariant_Inherit Inherit;
    AzStyleBorderTopColorValueVariant_Initial Initial;
    AzStyleBorderTopColorValueVariant_Exact Exact;
};
typedef union AzStyleBorderTopColorValue AzStyleBorderTopColorValue;

enum AzStyleBorderTopLeftRadiusValueTag {
   AzStyleBorderTopLeftRadiusValueTag_Auto,
   AzStyleBorderTopLeftRadiusValueTag_None,
   AzStyleBorderTopLeftRadiusValueTag_Inherit,
   AzStyleBorderTopLeftRadiusValueTag_Initial,
   AzStyleBorderTopLeftRadiusValueTag_Exact,
};
typedef enum AzStyleBorderTopLeftRadiusValueTag AzStyleBorderTopLeftRadiusValueTag;

struct AzStyleBorderTopLeftRadiusValueVariant_Auto { AzStyleBorderTopLeftRadiusValueTag tag; };
typedef struct AzStyleBorderTopLeftRadiusValueVariant_Auto AzStyleBorderTopLeftRadiusValueVariant_Auto;
struct AzStyleBorderTopLeftRadiusValueVariant_None { AzStyleBorderTopLeftRadiusValueTag tag; };
typedef struct AzStyleBorderTopLeftRadiusValueVariant_None AzStyleBorderTopLeftRadiusValueVariant_None;
struct AzStyleBorderTopLeftRadiusValueVariant_Inherit { AzStyleBorderTopLeftRadiusValueTag tag; };
typedef struct AzStyleBorderTopLeftRadiusValueVariant_Inherit AzStyleBorderTopLeftRadiusValueVariant_Inherit;
struct AzStyleBorderTopLeftRadiusValueVariant_Initial { AzStyleBorderTopLeftRadiusValueTag tag; };
typedef struct AzStyleBorderTopLeftRadiusValueVariant_Initial AzStyleBorderTopLeftRadiusValueVariant_Initial;
struct AzStyleBorderTopLeftRadiusValueVariant_Exact { AzStyleBorderTopLeftRadiusValueTag tag; AzStyleBorderTopLeftRadius payload; };
typedef struct AzStyleBorderTopLeftRadiusValueVariant_Exact AzStyleBorderTopLeftRadiusValueVariant_Exact;
union AzStyleBorderTopLeftRadiusValue {
    AzStyleBorderTopLeftRadiusValueVariant_Auto Auto;
    AzStyleBorderTopLeftRadiusValueVariant_None None;
    AzStyleBorderTopLeftRadiusValueVariant_Inherit Inherit;
    AzStyleBorderTopLeftRadiusValueVariant_Initial Initial;
    AzStyleBorderTopLeftRadiusValueVariant_Exact Exact;
};
typedef union AzStyleBorderTopLeftRadiusValue AzStyleBorderTopLeftRadiusValue;

enum AzStyleBorderTopRightRadiusValueTag {
   AzStyleBorderTopRightRadiusValueTag_Auto,
   AzStyleBorderTopRightRadiusValueTag_None,
   AzStyleBorderTopRightRadiusValueTag_Inherit,
   AzStyleBorderTopRightRadiusValueTag_Initial,
   AzStyleBorderTopRightRadiusValueTag_Exact,
};
typedef enum AzStyleBorderTopRightRadiusValueTag AzStyleBorderTopRightRadiusValueTag;

struct AzStyleBorderTopRightRadiusValueVariant_Auto { AzStyleBorderTopRightRadiusValueTag tag; };
typedef struct AzStyleBorderTopRightRadiusValueVariant_Auto AzStyleBorderTopRightRadiusValueVariant_Auto;
struct AzStyleBorderTopRightRadiusValueVariant_None { AzStyleBorderTopRightRadiusValueTag tag; };
typedef struct AzStyleBorderTopRightRadiusValueVariant_None AzStyleBorderTopRightRadiusValueVariant_None;
struct AzStyleBorderTopRightRadiusValueVariant_Inherit { AzStyleBorderTopRightRadiusValueTag tag; };
typedef struct AzStyleBorderTopRightRadiusValueVariant_Inherit AzStyleBorderTopRightRadiusValueVariant_Inherit;
struct AzStyleBorderTopRightRadiusValueVariant_Initial { AzStyleBorderTopRightRadiusValueTag tag; };
typedef struct AzStyleBorderTopRightRadiusValueVariant_Initial AzStyleBorderTopRightRadiusValueVariant_Initial;
struct AzStyleBorderTopRightRadiusValueVariant_Exact { AzStyleBorderTopRightRadiusValueTag tag; AzStyleBorderTopRightRadius payload; };
typedef struct AzStyleBorderTopRightRadiusValueVariant_Exact AzStyleBorderTopRightRadiusValueVariant_Exact;
union AzStyleBorderTopRightRadiusValue {
    AzStyleBorderTopRightRadiusValueVariant_Auto Auto;
    AzStyleBorderTopRightRadiusValueVariant_None None;
    AzStyleBorderTopRightRadiusValueVariant_Inherit Inherit;
    AzStyleBorderTopRightRadiusValueVariant_Initial Initial;
    AzStyleBorderTopRightRadiusValueVariant_Exact Exact;
};
typedef union AzStyleBorderTopRightRadiusValue AzStyleBorderTopRightRadiusValue;

enum AzStyleBorderTopStyleValueTag {
   AzStyleBorderTopStyleValueTag_Auto,
   AzStyleBorderTopStyleValueTag_None,
   AzStyleBorderTopStyleValueTag_Inherit,
   AzStyleBorderTopStyleValueTag_Initial,
   AzStyleBorderTopStyleValueTag_Exact,
};
typedef enum AzStyleBorderTopStyleValueTag AzStyleBorderTopStyleValueTag;

struct AzStyleBorderTopStyleValueVariant_Auto { AzStyleBorderTopStyleValueTag tag; };
typedef struct AzStyleBorderTopStyleValueVariant_Auto AzStyleBorderTopStyleValueVariant_Auto;
struct AzStyleBorderTopStyleValueVariant_None { AzStyleBorderTopStyleValueTag tag; };
typedef struct AzStyleBorderTopStyleValueVariant_None AzStyleBorderTopStyleValueVariant_None;
struct AzStyleBorderTopStyleValueVariant_Inherit { AzStyleBorderTopStyleValueTag tag; };
typedef struct AzStyleBorderTopStyleValueVariant_Inherit AzStyleBorderTopStyleValueVariant_Inherit;
struct AzStyleBorderTopStyleValueVariant_Initial { AzStyleBorderTopStyleValueTag tag; };
typedef struct AzStyleBorderTopStyleValueVariant_Initial AzStyleBorderTopStyleValueVariant_Initial;
struct AzStyleBorderTopStyleValueVariant_Exact { AzStyleBorderTopStyleValueTag tag; AzStyleBorderTopStyle payload; };
typedef struct AzStyleBorderTopStyleValueVariant_Exact AzStyleBorderTopStyleValueVariant_Exact;
union AzStyleBorderTopStyleValue {
    AzStyleBorderTopStyleValueVariant_Auto Auto;
    AzStyleBorderTopStyleValueVariant_None None;
    AzStyleBorderTopStyleValueVariant_Inherit Inherit;
    AzStyleBorderTopStyleValueVariant_Initial Initial;
    AzStyleBorderTopStyleValueVariant_Exact Exact;
};
typedef union AzStyleBorderTopStyleValue AzStyleBorderTopStyleValue;

enum AzLayoutBorderTopWidthValueTag {
   AzLayoutBorderTopWidthValueTag_Auto,
   AzLayoutBorderTopWidthValueTag_None,
   AzLayoutBorderTopWidthValueTag_Inherit,
   AzLayoutBorderTopWidthValueTag_Initial,
   AzLayoutBorderTopWidthValueTag_Exact,
};
typedef enum AzLayoutBorderTopWidthValueTag AzLayoutBorderTopWidthValueTag;

struct AzLayoutBorderTopWidthValueVariant_Auto { AzLayoutBorderTopWidthValueTag tag; };
typedef struct AzLayoutBorderTopWidthValueVariant_Auto AzLayoutBorderTopWidthValueVariant_Auto;
struct AzLayoutBorderTopWidthValueVariant_None { AzLayoutBorderTopWidthValueTag tag; };
typedef struct AzLayoutBorderTopWidthValueVariant_None AzLayoutBorderTopWidthValueVariant_None;
struct AzLayoutBorderTopWidthValueVariant_Inherit { AzLayoutBorderTopWidthValueTag tag; };
typedef struct AzLayoutBorderTopWidthValueVariant_Inherit AzLayoutBorderTopWidthValueVariant_Inherit;
struct AzLayoutBorderTopWidthValueVariant_Initial { AzLayoutBorderTopWidthValueTag tag; };
typedef struct AzLayoutBorderTopWidthValueVariant_Initial AzLayoutBorderTopWidthValueVariant_Initial;
struct AzLayoutBorderTopWidthValueVariant_Exact { AzLayoutBorderTopWidthValueTag tag; AzLayoutBorderTopWidth payload; };
typedef struct AzLayoutBorderTopWidthValueVariant_Exact AzLayoutBorderTopWidthValueVariant_Exact;
union AzLayoutBorderTopWidthValue {
    AzLayoutBorderTopWidthValueVariant_Auto Auto;
    AzLayoutBorderTopWidthValueVariant_None None;
    AzLayoutBorderTopWidthValueVariant_Inherit Inherit;
    AzLayoutBorderTopWidthValueVariant_Initial Initial;
    AzLayoutBorderTopWidthValueVariant_Exact Exact;
};
typedef union AzLayoutBorderTopWidthValue AzLayoutBorderTopWidthValue;

enum AzStyleCursorValueTag {
   AzStyleCursorValueTag_Auto,
   AzStyleCursorValueTag_None,
   AzStyleCursorValueTag_Inherit,
   AzStyleCursorValueTag_Initial,
   AzStyleCursorValueTag_Exact,
};
typedef enum AzStyleCursorValueTag AzStyleCursorValueTag;

struct AzStyleCursorValueVariant_Auto { AzStyleCursorValueTag tag; };
typedef struct AzStyleCursorValueVariant_Auto AzStyleCursorValueVariant_Auto;
struct AzStyleCursorValueVariant_None { AzStyleCursorValueTag tag; };
typedef struct AzStyleCursorValueVariant_None AzStyleCursorValueVariant_None;
struct AzStyleCursorValueVariant_Inherit { AzStyleCursorValueTag tag; };
typedef struct AzStyleCursorValueVariant_Inherit AzStyleCursorValueVariant_Inherit;
struct AzStyleCursorValueVariant_Initial { AzStyleCursorValueTag tag; };
typedef struct AzStyleCursorValueVariant_Initial AzStyleCursorValueVariant_Initial;
struct AzStyleCursorValueVariant_Exact { AzStyleCursorValueTag tag; AzStyleCursor payload; };
typedef struct AzStyleCursorValueVariant_Exact AzStyleCursorValueVariant_Exact;
union AzStyleCursorValue {
    AzStyleCursorValueVariant_Auto Auto;
    AzStyleCursorValueVariant_None None;
    AzStyleCursorValueVariant_Inherit Inherit;
    AzStyleCursorValueVariant_Initial Initial;
    AzStyleCursorValueVariant_Exact Exact;
};
typedef union AzStyleCursorValue AzStyleCursorValue;

enum AzStyleFontSizeValueTag {
   AzStyleFontSizeValueTag_Auto,
   AzStyleFontSizeValueTag_None,
   AzStyleFontSizeValueTag_Inherit,
   AzStyleFontSizeValueTag_Initial,
   AzStyleFontSizeValueTag_Exact,
};
typedef enum AzStyleFontSizeValueTag AzStyleFontSizeValueTag;

struct AzStyleFontSizeValueVariant_Auto { AzStyleFontSizeValueTag tag; };
typedef struct AzStyleFontSizeValueVariant_Auto AzStyleFontSizeValueVariant_Auto;
struct AzStyleFontSizeValueVariant_None { AzStyleFontSizeValueTag tag; };
typedef struct AzStyleFontSizeValueVariant_None AzStyleFontSizeValueVariant_None;
struct AzStyleFontSizeValueVariant_Inherit { AzStyleFontSizeValueTag tag; };
typedef struct AzStyleFontSizeValueVariant_Inherit AzStyleFontSizeValueVariant_Inherit;
struct AzStyleFontSizeValueVariant_Initial { AzStyleFontSizeValueTag tag; };
typedef struct AzStyleFontSizeValueVariant_Initial AzStyleFontSizeValueVariant_Initial;
struct AzStyleFontSizeValueVariant_Exact { AzStyleFontSizeValueTag tag; AzStyleFontSize payload; };
typedef struct AzStyleFontSizeValueVariant_Exact AzStyleFontSizeValueVariant_Exact;
union AzStyleFontSizeValue {
    AzStyleFontSizeValueVariant_Auto Auto;
    AzStyleFontSizeValueVariant_None None;
    AzStyleFontSizeValueVariant_Inherit Inherit;
    AzStyleFontSizeValueVariant_Initial Initial;
    AzStyleFontSizeValueVariant_Exact Exact;
};
typedef union AzStyleFontSizeValue AzStyleFontSizeValue;

enum AzStyleLetterSpacingValueTag {
   AzStyleLetterSpacingValueTag_Auto,
   AzStyleLetterSpacingValueTag_None,
   AzStyleLetterSpacingValueTag_Inherit,
   AzStyleLetterSpacingValueTag_Initial,
   AzStyleLetterSpacingValueTag_Exact,
};
typedef enum AzStyleLetterSpacingValueTag AzStyleLetterSpacingValueTag;

struct AzStyleLetterSpacingValueVariant_Auto { AzStyleLetterSpacingValueTag tag; };
typedef struct AzStyleLetterSpacingValueVariant_Auto AzStyleLetterSpacingValueVariant_Auto;
struct AzStyleLetterSpacingValueVariant_None { AzStyleLetterSpacingValueTag tag; };
typedef struct AzStyleLetterSpacingValueVariant_None AzStyleLetterSpacingValueVariant_None;
struct AzStyleLetterSpacingValueVariant_Inherit { AzStyleLetterSpacingValueTag tag; };
typedef struct AzStyleLetterSpacingValueVariant_Inherit AzStyleLetterSpacingValueVariant_Inherit;
struct AzStyleLetterSpacingValueVariant_Initial { AzStyleLetterSpacingValueTag tag; };
typedef struct AzStyleLetterSpacingValueVariant_Initial AzStyleLetterSpacingValueVariant_Initial;
struct AzStyleLetterSpacingValueVariant_Exact { AzStyleLetterSpacingValueTag tag; AzStyleLetterSpacing payload; };
typedef struct AzStyleLetterSpacingValueVariant_Exact AzStyleLetterSpacingValueVariant_Exact;
union AzStyleLetterSpacingValue {
    AzStyleLetterSpacingValueVariant_Auto Auto;
    AzStyleLetterSpacingValueVariant_None None;
    AzStyleLetterSpacingValueVariant_Inherit Inherit;
    AzStyleLetterSpacingValueVariant_Initial Initial;
    AzStyleLetterSpacingValueVariant_Exact Exact;
};
typedef union AzStyleLetterSpacingValue AzStyleLetterSpacingValue;

enum AzStyleLineHeightValueTag {
   AzStyleLineHeightValueTag_Auto,
   AzStyleLineHeightValueTag_None,
   AzStyleLineHeightValueTag_Inherit,
   AzStyleLineHeightValueTag_Initial,
   AzStyleLineHeightValueTag_Exact,
};
typedef enum AzStyleLineHeightValueTag AzStyleLineHeightValueTag;

struct AzStyleLineHeightValueVariant_Auto { AzStyleLineHeightValueTag tag; };
typedef struct AzStyleLineHeightValueVariant_Auto AzStyleLineHeightValueVariant_Auto;
struct AzStyleLineHeightValueVariant_None { AzStyleLineHeightValueTag tag; };
typedef struct AzStyleLineHeightValueVariant_None AzStyleLineHeightValueVariant_None;
struct AzStyleLineHeightValueVariant_Inherit { AzStyleLineHeightValueTag tag; };
typedef struct AzStyleLineHeightValueVariant_Inherit AzStyleLineHeightValueVariant_Inherit;
struct AzStyleLineHeightValueVariant_Initial { AzStyleLineHeightValueTag tag; };
typedef struct AzStyleLineHeightValueVariant_Initial AzStyleLineHeightValueVariant_Initial;
struct AzStyleLineHeightValueVariant_Exact { AzStyleLineHeightValueTag tag; AzStyleLineHeight payload; };
typedef struct AzStyleLineHeightValueVariant_Exact AzStyleLineHeightValueVariant_Exact;
union AzStyleLineHeightValue {
    AzStyleLineHeightValueVariant_Auto Auto;
    AzStyleLineHeightValueVariant_None None;
    AzStyleLineHeightValueVariant_Inherit Inherit;
    AzStyleLineHeightValueVariant_Initial Initial;
    AzStyleLineHeightValueVariant_Exact Exact;
};
typedef union AzStyleLineHeightValue AzStyleLineHeightValue;

enum AzStyleTabWidthValueTag {
   AzStyleTabWidthValueTag_Auto,
   AzStyleTabWidthValueTag_None,
   AzStyleTabWidthValueTag_Inherit,
   AzStyleTabWidthValueTag_Initial,
   AzStyleTabWidthValueTag_Exact,
};
typedef enum AzStyleTabWidthValueTag AzStyleTabWidthValueTag;

struct AzStyleTabWidthValueVariant_Auto { AzStyleTabWidthValueTag tag; };
typedef struct AzStyleTabWidthValueVariant_Auto AzStyleTabWidthValueVariant_Auto;
struct AzStyleTabWidthValueVariant_None { AzStyleTabWidthValueTag tag; };
typedef struct AzStyleTabWidthValueVariant_None AzStyleTabWidthValueVariant_None;
struct AzStyleTabWidthValueVariant_Inherit { AzStyleTabWidthValueTag tag; };
typedef struct AzStyleTabWidthValueVariant_Inherit AzStyleTabWidthValueVariant_Inherit;
struct AzStyleTabWidthValueVariant_Initial { AzStyleTabWidthValueTag tag; };
typedef struct AzStyleTabWidthValueVariant_Initial AzStyleTabWidthValueVariant_Initial;
struct AzStyleTabWidthValueVariant_Exact { AzStyleTabWidthValueTag tag; AzStyleTabWidth payload; };
typedef struct AzStyleTabWidthValueVariant_Exact AzStyleTabWidthValueVariant_Exact;
union AzStyleTabWidthValue {
    AzStyleTabWidthValueVariant_Auto Auto;
    AzStyleTabWidthValueVariant_None None;
    AzStyleTabWidthValueVariant_Inherit Inherit;
    AzStyleTabWidthValueVariant_Initial Initial;
    AzStyleTabWidthValueVariant_Exact Exact;
};
typedef union AzStyleTabWidthValue AzStyleTabWidthValue;

enum AzStyleTextAlignValueTag {
   AzStyleTextAlignValueTag_Auto,
   AzStyleTextAlignValueTag_None,
   AzStyleTextAlignValueTag_Inherit,
   AzStyleTextAlignValueTag_Initial,
   AzStyleTextAlignValueTag_Exact,
};
typedef enum AzStyleTextAlignValueTag AzStyleTextAlignValueTag;

struct AzStyleTextAlignValueVariant_Auto { AzStyleTextAlignValueTag tag; };
typedef struct AzStyleTextAlignValueVariant_Auto AzStyleTextAlignValueVariant_Auto;
struct AzStyleTextAlignValueVariant_None { AzStyleTextAlignValueTag tag; };
typedef struct AzStyleTextAlignValueVariant_None AzStyleTextAlignValueVariant_None;
struct AzStyleTextAlignValueVariant_Inherit { AzStyleTextAlignValueTag tag; };
typedef struct AzStyleTextAlignValueVariant_Inherit AzStyleTextAlignValueVariant_Inherit;
struct AzStyleTextAlignValueVariant_Initial { AzStyleTextAlignValueTag tag; };
typedef struct AzStyleTextAlignValueVariant_Initial AzStyleTextAlignValueVariant_Initial;
struct AzStyleTextAlignValueVariant_Exact { AzStyleTextAlignValueTag tag; AzStyleTextAlign payload; };
typedef struct AzStyleTextAlignValueVariant_Exact AzStyleTextAlignValueVariant_Exact;
union AzStyleTextAlignValue {
    AzStyleTextAlignValueVariant_Auto Auto;
    AzStyleTextAlignValueVariant_None None;
    AzStyleTextAlignValueVariant_Inherit Inherit;
    AzStyleTextAlignValueVariant_Initial Initial;
    AzStyleTextAlignValueVariant_Exact Exact;
};
typedef union AzStyleTextAlignValue AzStyleTextAlignValue;

enum AzStyleTextColorValueTag {
   AzStyleTextColorValueTag_Auto,
   AzStyleTextColorValueTag_None,
   AzStyleTextColorValueTag_Inherit,
   AzStyleTextColorValueTag_Initial,
   AzStyleTextColorValueTag_Exact,
};
typedef enum AzStyleTextColorValueTag AzStyleTextColorValueTag;

struct AzStyleTextColorValueVariant_Auto { AzStyleTextColorValueTag tag; };
typedef struct AzStyleTextColorValueVariant_Auto AzStyleTextColorValueVariant_Auto;
struct AzStyleTextColorValueVariant_None { AzStyleTextColorValueTag tag; };
typedef struct AzStyleTextColorValueVariant_None AzStyleTextColorValueVariant_None;
struct AzStyleTextColorValueVariant_Inherit { AzStyleTextColorValueTag tag; };
typedef struct AzStyleTextColorValueVariant_Inherit AzStyleTextColorValueVariant_Inherit;
struct AzStyleTextColorValueVariant_Initial { AzStyleTextColorValueTag tag; };
typedef struct AzStyleTextColorValueVariant_Initial AzStyleTextColorValueVariant_Initial;
struct AzStyleTextColorValueVariant_Exact { AzStyleTextColorValueTag tag; AzStyleTextColor payload; };
typedef struct AzStyleTextColorValueVariant_Exact AzStyleTextColorValueVariant_Exact;
union AzStyleTextColorValue {
    AzStyleTextColorValueVariant_Auto Auto;
    AzStyleTextColorValueVariant_None None;
    AzStyleTextColorValueVariant_Inherit Inherit;
    AzStyleTextColorValueVariant_Initial Initial;
    AzStyleTextColorValueVariant_Exact Exact;
};
typedef union AzStyleTextColorValue AzStyleTextColorValue;

enum AzStyleWordSpacingValueTag {
   AzStyleWordSpacingValueTag_Auto,
   AzStyleWordSpacingValueTag_None,
   AzStyleWordSpacingValueTag_Inherit,
   AzStyleWordSpacingValueTag_Initial,
   AzStyleWordSpacingValueTag_Exact,
};
typedef enum AzStyleWordSpacingValueTag AzStyleWordSpacingValueTag;

struct AzStyleWordSpacingValueVariant_Auto { AzStyleWordSpacingValueTag tag; };
typedef struct AzStyleWordSpacingValueVariant_Auto AzStyleWordSpacingValueVariant_Auto;
struct AzStyleWordSpacingValueVariant_None { AzStyleWordSpacingValueTag tag; };
typedef struct AzStyleWordSpacingValueVariant_None AzStyleWordSpacingValueVariant_None;
struct AzStyleWordSpacingValueVariant_Inherit { AzStyleWordSpacingValueTag tag; };
typedef struct AzStyleWordSpacingValueVariant_Inherit AzStyleWordSpacingValueVariant_Inherit;
struct AzStyleWordSpacingValueVariant_Initial { AzStyleWordSpacingValueTag tag; };
typedef struct AzStyleWordSpacingValueVariant_Initial AzStyleWordSpacingValueVariant_Initial;
struct AzStyleWordSpacingValueVariant_Exact { AzStyleWordSpacingValueTag tag; AzStyleWordSpacing payload; };
typedef struct AzStyleWordSpacingValueVariant_Exact AzStyleWordSpacingValueVariant_Exact;
union AzStyleWordSpacingValue {
    AzStyleWordSpacingValueVariant_Auto Auto;
    AzStyleWordSpacingValueVariant_None None;
    AzStyleWordSpacingValueVariant_Inherit Inherit;
    AzStyleWordSpacingValueVariant_Initial Initial;
    AzStyleWordSpacingValueVariant_Exact Exact;
};
typedef union AzStyleWordSpacingValue AzStyleWordSpacingValue;

enum AzStyleOpacityValueTag {
   AzStyleOpacityValueTag_Auto,
   AzStyleOpacityValueTag_None,
   AzStyleOpacityValueTag_Inherit,
   AzStyleOpacityValueTag_Initial,
   AzStyleOpacityValueTag_Exact,
};
typedef enum AzStyleOpacityValueTag AzStyleOpacityValueTag;

struct AzStyleOpacityValueVariant_Auto { AzStyleOpacityValueTag tag; };
typedef struct AzStyleOpacityValueVariant_Auto AzStyleOpacityValueVariant_Auto;
struct AzStyleOpacityValueVariant_None { AzStyleOpacityValueTag tag; };
typedef struct AzStyleOpacityValueVariant_None AzStyleOpacityValueVariant_None;
struct AzStyleOpacityValueVariant_Inherit { AzStyleOpacityValueTag tag; };
typedef struct AzStyleOpacityValueVariant_Inherit AzStyleOpacityValueVariant_Inherit;
struct AzStyleOpacityValueVariant_Initial { AzStyleOpacityValueTag tag; };
typedef struct AzStyleOpacityValueVariant_Initial AzStyleOpacityValueVariant_Initial;
struct AzStyleOpacityValueVariant_Exact { AzStyleOpacityValueTag tag; AzStyleOpacity payload; };
typedef struct AzStyleOpacityValueVariant_Exact AzStyleOpacityValueVariant_Exact;
union AzStyleOpacityValue {
    AzStyleOpacityValueVariant_Auto Auto;
    AzStyleOpacityValueVariant_None None;
    AzStyleOpacityValueVariant_Inherit Inherit;
    AzStyleOpacityValueVariant_Initial Initial;
    AzStyleOpacityValueVariant_Exact Exact;
};
typedef union AzStyleOpacityValue AzStyleOpacityValue;

enum AzStyleTransformOriginValueTag {
   AzStyleTransformOriginValueTag_Auto,
   AzStyleTransformOriginValueTag_None,
   AzStyleTransformOriginValueTag_Inherit,
   AzStyleTransformOriginValueTag_Initial,
   AzStyleTransformOriginValueTag_Exact,
};
typedef enum AzStyleTransformOriginValueTag AzStyleTransformOriginValueTag;

struct AzStyleTransformOriginValueVariant_Auto { AzStyleTransformOriginValueTag tag; };
typedef struct AzStyleTransformOriginValueVariant_Auto AzStyleTransformOriginValueVariant_Auto;
struct AzStyleTransformOriginValueVariant_None { AzStyleTransformOriginValueTag tag; };
typedef struct AzStyleTransformOriginValueVariant_None AzStyleTransformOriginValueVariant_None;
struct AzStyleTransformOriginValueVariant_Inherit { AzStyleTransformOriginValueTag tag; };
typedef struct AzStyleTransformOriginValueVariant_Inherit AzStyleTransformOriginValueVariant_Inherit;
struct AzStyleTransformOriginValueVariant_Initial { AzStyleTransformOriginValueTag tag; };
typedef struct AzStyleTransformOriginValueVariant_Initial AzStyleTransformOriginValueVariant_Initial;
struct AzStyleTransformOriginValueVariant_Exact { AzStyleTransformOriginValueTag tag; AzStyleTransformOrigin payload; };
typedef struct AzStyleTransformOriginValueVariant_Exact AzStyleTransformOriginValueVariant_Exact;
union AzStyleTransformOriginValue {
    AzStyleTransformOriginValueVariant_Auto Auto;
    AzStyleTransformOriginValueVariant_None None;
    AzStyleTransformOriginValueVariant_Inherit Inherit;
    AzStyleTransformOriginValueVariant_Initial Initial;
    AzStyleTransformOriginValueVariant_Exact Exact;
};
typedef union AzStyleTransformOriginValue AzStyleTransformOriginValue;

enum AzStylePerspectiveOriginValueTag {
   AzStylePerspectiveOriginValueTag_Auto,
   AzStylePerspectiveOriginValueTag_None,
   AzStylePerspectiveOriginValueTag_Inherit,
   AzStylePerspectiveOriginValueTag_Initial,
   AzStylePerspectiveOriginValueTag_Exact,
};
typedef enum AzStylePerspectiveOriginValueTag AzStylePerspectiveOriginValueTag;

struct AzStylePerspectiveOriginValueVariant_Auto { AzStylePerspectiveOriginValueTag tag; };
typedef struct AzStylePerspectiveOriginValueVariant_Auto AzStylePerspectiveOriginValueVariant_Auto;
struct AzStylePerspectiveOriginValueVariant_None { AzStylePerspectiveOriginValueTag tag; };
typedef struct AzStylePerspectiveOriginValueVariant_None AzStylePerspectiveOriginValueVariant_None;
struct AzStylePerspectiveOriginValueVariant_Inherit { AzStylePerspectiveOriginValueTag tag; };
typedef struct AzStylePerspectiveOriginValueVariant_Inherit AzStylePerspectiveOriginValueVariant_Inherit;
struct AzStylePerspectiveOriginValueVariant_Initial { AzStylePerspectiveOriginValueTag tag; };
typedef struct AzStylePerspectiveOriginValueVariant_Initial AzStylePerspectiveOriginValueVariant_Initial;
struct AzStylePerspectiveOriginValueVariant_Exact { AzStylePerspectiveOriginValueTag tag; AzStylePerspectiveOrigin payload; };
typedef struct AzStylePerspectiveOriginValueVariant_Exact AzStylePerspectiveOriginValueVariant_Exact;
union AzStylePerspectiveOriginValue {
    AzStylePerspectiveOriginValueVariant_Auto Auto;
    AzStylePerspectiveOriginValueVariant_None None;
    AzStylePerspectiveOriginValueVariant_Inherit Inherit;
    AzStylePerspectiveOriginValueVariant_Initial Initial;
    AzStylePerspectiveOriginValueVariant_Exact Exact;
};
typedef union AzStylePerspectiveOriginValue AzStylePerspectiveOriginValue;

enum AzStyleBackfaceVisibilityValueTag {
   AzStyleBackfaceVisibilityValueTag_Auto,
   AzStyleBackfaceVisibilityValueTag_None,
   AzStyleBackfaceVisibilityValueTag_Inherit,
   AzStyleBackfaceVisibilityValueTag_Initial,
   AzStyleBackfaceVisibilityValueTag_Exact,
};
typedef enum AzStyleBackfaceVisibilityValueTag AzStyleBackfaceVisibilityValueTag;

struct AzStyleBackfaceVisibilityValueVariant_Auto { AzStyleBackfaceVisibilityValueTag tag; };
typedef struct AzStyleBackfaceVisibilityValueVariant_Auto AzStyleBackfaceVisibilityValueVariant_Auto;
struct AzStyleBackfaceVisibilityValueVariant_None { AzStyleBackfaceVisibilityValueTag tag; };
typedef struct AzStyleBackfaceVisibilityValueVariant_None AzStyleBackfaceVisibilityValueVariant_None;
struct AzStyleBackfaceVisibilityValueVariant_Inherit { AzStyleBackfaceVisibilityValueTag tag; };
typedef struct AzStyleBackfaceVisibilityValueVariant_Inherit AzStyleBackfaceVisibilityValueVariant_Inherit;
struct AzStyleBackfaceVisibilityValueVariant_Initial { AzStyleBackfaceVisibilityValueTag tag; };
typedef struct AzStyleBackfaceVisibilityValueVariant_Initial AzStyleBackfaceVisibilityValueVariant_Initial;
struct AzStyleBackfaceVisibilityValueVariant_Exact { AzStyleBackfaceVisibilityValueTag tag; AzStyleBackfaceVisibility payload; };
typedef struct AzStyleBackfaceVisibilityValueVariant_Exact AzStyleBackfaceVisibilityValueVariant_Exact;
union AzStyleBackfaceVisibilityValue {
    AzStyleBackfaceVisibilityValueVariant_Auto Auto;
    AzStyleBackfaceVisibilityValueVariant_None None;
    AzStyleBackfaceVisibilityValueVariant_Inherit Inherit;
    AzStyleBackfaceVisibilityValueVariant_Initial Initial;
    AzStyleBackfaceVisibilityValueVariant_Exact Exact;
};
typedef union AzStyleBackfaceVisibilityValue AzStyleBackfaceVisibilityValue;

struct AzButtonOnClick {
    AzRefAny data;
    AzCallback callback;
};
typedef struct AzButtonOnClick AzButtonOnClick;

struct AzCheckBoxOnToggle {
    AzRefAny data;
    AzCheckBoxOnToggleCallback callback;
};
typedef struct AzCheckBoxOnToggle AzCheckBoxOnToggle;

struct AzColorInputState {
    AzColorU color;
};
typedef struct AzColorInputState AzColorInputState;

struct AzColorInputOnValueChange {
    AzRefAny data;
    AzColorInputOnValueChangeCallback callback;
};
typedef struct AzColorInputOnValueChange AzColorInputOnValueChange;

enum AzTextInputSelectionTag {
   AzTextInputSelectionTag_All,
   AzTextInputSelectionTag_FromTo,
};
typedef enum AzTextInputSelectionTag AzTextInputSelectionTag;

struct AzTextInputSelectionVariant_All { AzTextInputSelectionTag tag; };
typedef struct AzTextInputSelectionVariant_All AzTextInputSelectionVariant_All;
struct AzTextInputSelectionVariant_FromTo { AzTextInputSelectionTag tag; AzTextInputSelectionRange payload; };
typedef struct AzTextInputSelectionVariant_FromTo AzTextInputSelectionVariant_FromTo;
union AzTextInputSelection {
    AzTextInputSelectionVariant_All All;
    AzTextInputSelectionVariant_FromTo FromTo;
};
typedef union AzTextInputSelection AzTextInputSelection;

struct AzTextInputOnTextInput {
    AzRefAny data;
    AzTextInputOnTextInputCallback callback;
};
typedef struct AzTextInputOnTextInput AzTextInputOnTextInput;

struct AzTextInputOnVirtualKeyDown {
    AzRefAny data;
    AzTextInputOnVirtualKeyDownCallback callback;
};
typedef struct AzTextInputOnVirtualKeyDown AzTextInputOnVirtualKeyDown;

struct AzTextInputOnFocusLost {
    AzRefAny data;
    AzTextInputOnFocusLostCallback callback;
};
typedef struct AzTextInputOnFocusLost AzTextInputOnFocusLost;

struct AzOnTextInputReturn {
    AzUpdate update;
    AzTextInputValid valid;
};
typedef struct AzOnTextInputReturn AzOnTextInputReturn;

struct AzNumberInputOnValueChange {
    AzRefAny data;
    AzNumberInputOnValueChangeCallback callback;
};
typedef struct AzNumberInputOnValueChange AzNumberInputOnValueChange;

struct AzParentWithNodeDepth {
    size_t depth;
    AzNodeId node_id;
};
typedef struct AzParentWithNodeDepth AzParentWithNodeDepth;

struct AzGl {
    void* ptr;
    AzRendererType renderer_type;
};
typedef struct AzGl AzGl;

struct AzRefstrVecRef {
    AzRefstr* ptr;
    size_t len;
};
typedef struct AzRefstrVecRef AzRefstrVecRef;

struct AzImageMask {
    AzImageRef image;
    AzLogicalRect rect;
    bool  repeat;
};
typedef struct AzImageMask AzImageMask;

struct AzFontMetrics {
    uint16_t units_per_em;
    uint16_t font_flags;
    int16_t x_min;
    int16_t y_min;
    int16_t x_max;
    int16_t y_max;
    int16_t ascender;
    int16_t descender;
    int16_t line_gap;
    uint16_t advance_width_max;
    int16_t min_left_side_bearing;
    int16_t min_right_side_bearing;
    int16_t x_max_extent;
    int16_t caret_slope_rise;
    int16_t caret_slope_run;
    int16_t caret_offset;
    uint16_t num_h_metrics;
    int16_t x_avg_char_width;
    uint16_t us_weight_class;
    uint16_t us_width_class;
    uint16_t fs_type;
    int16_t y_subscript_x_size;
    int16_t y_subscript_y_size;
    int16_t y_subscript_x_offset;
    int16_t y_subscript_y_offset;
    int16_t y_superscript_x_size;
    int16_t y_superscript_y_size;
    int16_t y_superscript_x_offset;
    int16_t y_superscript_y_offset;
    int16_t y_strikeout_size;
    int16_t y_strikeout_position;
    int16_t s_family_class;
    uint8_t[; 10] panose;
    uint32_t ul_unicode_range1;
    uint32_t ul_unicode_range2;
    uint32_t ul_unicode_range3;
    uint32_t ul_unicode_range4;
    uint32_t ach_vend_id;
    uint16_t fs_selection;
    uint16_t us_first_char_index;
    uint16_t us_last_char_index;
    AzOptionI16 s_typo_ascender;
    AzOptionI16 s_typo_descender;
    AzOptionI16 s_typo_line_gap;
    AzOptionU16 us_win_ascent;
    AzOptionU16 us_win_descent;
    AzOptionU32 ul_code_page_range1;
    AzOptionU32 ul_code_page_range2;
    AzOptionI16 sx_height;
    AzOptionI16 s_cap_height;
    AzOptionU16 us_default_char;
    AzOptionU16 us_break_char;
    AzOptionU16 us_max_context;
    AzOptionU16 us_lower_optical_point_size;
    AzOptionU16 us_upper_optical_point_size;
};
typedef struct AzFontMetrics AzFontMetrics;

struct AzSvgLine {
    AzSvgPoint start;
    AzSvgPoint end;
};
typedef struct AzSvgLine AzSvgLine;

struct AzSvgQuadraticCurve {
    AzSvgPoint start;
    AzSvgPoint ctrl;
    AzSvgPoint end;
};
typedef struct AzSvgQuadraticCurve AzSvgQuadraticCurve;

struct AzSvgCubicCurve {
    AzSvgPoint start;
    AzSvgPoint ctrl_1;
    AzSvgPoint ctrl_2;
    AzSvgPoint end;
};
typedef struct AzSvgCubicCurve AzSvgCubicCurve;

struct AzSvgStringFormatOptions {
    bool  use_single_quote;
    AzIndent indent;
    AzIndent attributes_indent;
};
typedef struct AzSvgStringFormatOptions AzSvgStringFormatOptions;

struct AzSvgFillStyle {
    AzSvgLineJoin line_join;
    float miter_limit;
    float tolerance;
    AzSvgFillRule fill_rule;
    AzSvgTransform transform;
    bool  anti_alias;
    bool  high_quality_aa;
};
typedef struct AzSvgFillStyle AzSvgFillStyle;

struct AzInstantPtr {
    void* ptr;
    AzInstantPtrCloneFn clone_fn;
    AzInstantPtrDestructorFn destructor;
};
typedef struct AzInstantPtr AzInstantPtr;

enum AzDurationTag {
   AzDurationTag_System,
   AzDurationTag_Tick,
};
typedef enum AzDurationTag AzDurationTag;

struct AzDurationVariant_System { AzDurationTag tag; AzSystemTimeDiff payload; };
typedef struct AzDurationVariant_System AzDurationVariant_System;
struct AzDurationVariant_Tick { AzDurationTag tag; AzSystemTickDiff payload; };
typedef struct AzDurationVariant_Tick AzDurationVariant_Tick;
union AzDuration {
    AzDurationVariant_System System;
    AzDurationVariant_Tick Tick;
};
typedef union AzDuration AzDuration;

enum AzThreadSendMsgTag {
   AzThreadSendMsgTag_TerminateThread,
   AzThreadSendMsgTag_Tick,
   AzThreadSendMsgTag_Custom,
};
typedef enum AzThreadSendMsgTag AzThreadSendMsgTag;

struct AzThreadSendMsgVariant_TerminateThread { AzThreadSendMsgTag tag; };
typedef struct AzThreadSendMsgVariant_TerminateThread AzThreadSendMsgVariant_TerminateThread;
struct AzThreadSendMsgVariant_Tick { AzThreadSendMsgTag tag; };
typedef struct AzThreadSendMsgVariant_Tick AzThreadSendMsgVariant_Tick;
struct AzThreadSendMsgVariant_Custom { AzThreadSendMsgTag tag; AzRefAny payload; };
typedef struct AzThreadSendMsgVariant_Custom AzThreadSendMsgVariant_Custom;
union AzThreadSendMsg {
    AzThreadSendMsgVariant_TerminateThread TerminateThread;
    AzThreadSendMsgVariant_Tick Tick;
    AzThreadSendMsgVariant_Custom Custom;
};
typedef union AzThreadSendMsg AzThreadSendMsg;

struct AzThreadWriteBackMsg {
    AzRefAny data;
    AzWriteBackCallback callback;
};
typedef struct AzThreadWriteBackMsg AzThreadWriteBackMsg;

struct AzAccessibilityStateVec {
    AzAccessibilityState* ptr;
    size_t len;
    size_t cap;
    AzAccessibilityStateVecDestructor destructor;
};
typedef struct AzAccessibilityStateVec AzAccessibilityStateVec;

struct AzMenuItem;
typedef struct AzMenuItem AzMenuItem;
struct AzMenuItemVec {
    AzMenuItem* ptr;
    size_t len;
    size_t cap;
    AzMenuItemVecDestructor destructor;
};
typedef struct AzMenuItemVec AzMenuItemVec;

struct AzXmlNode;
typedef struct AzXmlNode AzXmlNode;
struct AzXmlNodeVec {
    AzXmlNode* ptr;
    size_t len;
    size_t cap;
    AzXmlNodeVecDestructor destructor;
};
typedef struct AzXmlNodeVec AzXmlNodeVec;

struct AzInlineGlyphVec {
    AzInlineGlyph* ptr;
    size_t len;
    size_t cap;
    AzInlineGlyphVecDestructor destructor;
};
typedef struct AzInlineGlyphVec AzInlineGlyphVec;

struct AzInlineTextHitVec {
    AzInlineTextHit* ptr;
    size_t len;
    size_t cap;
    AzInlineTextHitVecDestructor destructor;
};
typedef struct AzInlineTextHitVec AzInlineTextHitVec;

struct AzVideoModeVec {
    AzVideoMode* ptr;
    size_t len;
    size_t cap;
    AzVideoModeVecDestructor destructor;
};
typedef struct AzVideoModeVec AzVideoModeVec;

struct AzDom;
typedef struct AzDom AzDom;
struct AzDomVec {
    AzDom* ptr;
    size_t len;
    size_t cap;
    AzDomVecDestructor destructor;
};
typedef struct AzDomVec AzDomVec;

struct AzStyleBackgroundPositionVec {
    AzStyleBackgroundPosition* ptr;
    size_t len;
    size_t cap;
    AzStyleBackgroundPositionVecDestructor destructor;
};
typedef struct AzStyleBackgroundPositionVec AzStyleBackgroundPositionVec;

struct AzStyleBackgroundRepeatVec {
    AzStyleBackgroundRepeat* ptr;
    size_t len;
    size_t cap;
    AzStyleBackgroundRepeatVecDestructor destructor;
};
typedef struct AzStyleBackgroundRepeatVec AzStyleBackgroundRepeatVec;

struct AzStyleBackgroundSizeVec {
    AzStyleBackgroundSize* ptr;
    size_t len;
    size_t cap;
    AzStyleBackgroundSizeVecDestructor destructor;
};
typedef struct AzStyleBackgroundSizeVec AzStyleBackgroundSizeVec;

struct AzSvgVertexVec {
    AzSvgVertex* ptr;
    size_t len;
    size_t cap;
    AzSvgVertexVecDestructor destructor;
};
typedef struct AzSvgVertexVec AzSvgVertexVec;

struct AzU32Vec {
    uint32_t* ptr;
    size_t len;
    size_t cap;
    AzU32VecDestructor destructor;
};
typedef struct AzU32Vec AzU32Vec;

struct AzXWindowTypeVec {
    AzXWindowType* ptr;
    size_t len;
    size_t cap;
    AzXWindowTypeVecDestructor destructor;
};
typedef struct AzXWindowTypeVec AzXWindowTypeVec;

struct AzVirtualKeyCodeVec {
    AzVirtualKeyCode* ptr;
    size_t len;
    size_t cap;
    AzVirtualKeyCodeVecDestructor destructor;
};
typedef struct AzVirtualKeyCodeVec AzVirtualKeyCodeVec;

struct AzCascadeInfoVec {
    AzCascadeInfo* ptr;
    size_t len;
    size_t cap;
    AzCascadeInfoVecDestructor destructor;
};
typedef struct AzCascadeInfoVec AzCascadeInfoVec;

struct AzScanCodeVec {
    uint32_t* ptr;
    size_t len;
    size_t cap;
    AzScanCodeVecDestructor destructor;
};
typedef struct AzScanCodeVec AzScanCodeVec;

struct AzU16Vec {
    uint16_t* ptr;
    size_t len;
    size_t cap;
    AzU16VecDestructor destructor;
};
typedef struct AzU16Vec AzU16Vec;

struct AzF32Vec {
    float* ptr;
    size_t len;
    size_t cap;
    AzF32VecDestructor destructor;
};
typedef struct AzF32Vec AzF32Vec;

struct AzU8Vec {
    uint8_t* ptr;
    size_t len;
    size_t cap;
    AzU8VecDestructor destructor;
};
typedef struct AzU8Vec AzU8Vec;

struct AzGLuintVec {
    uint32_t* ptr;
    size_t len;
    size_t cap;
    AzGLuintVecDestructor destructor;
};
typedef struct AzGLuintVec AzGLuintVec;

struct AzGLintVec {
    int32_t* ptr;
    size_t len;
    size_t cap;
    AzGLintVecDestructor destructor;
};
typedef struct AzGLintVec AzGLintVec;

struct AzNormalizedLinearColorStopVec {
    AzNormalizedLinearColorStop* ptr;
    size_t len;
    size_t cap;
    AzNormalizedLinearColorStopVecDestructor destructor;
};
typedef struct AzNormalizedLinearColorStopVec AzNormalizedLinearColorStopVec;

struct AzNormalizedRadialColorStopVec {
    AzNormalizedRadialColorStop* ptr;
    size_t len;
    size_t cap;
    AzNormalizedRadialColorStopVecDestructor destructor;
};
typedef struct AzNormalizedRadialColorStopVec AzNormalizedRadialColorStopVec;

struct AzNodeIdVec {
    AzNodeId* ptr;
    size_t len;
    size_t cap;
    AzNodeIdVecDestructor destructor;
};
typedef struct AzNodeIdVec AzNodeIdVec;

struct AzNodeVec {
    AzNode* ptr;
    size_t len;
    size_t cap;
    AzNodeVecDestructor destructor;
};
typedef struct AzNodeVec AzNodeVec;

struct AzParentWithNodeDepthVec {
    AzParentWithNodeDepth* ptr;
    size_t len;
    size_t cap;
    AzParentWithNodeDepthVecDestructor destructor;
};
typedef struct AzParentWithNodeDepthVec AzParentWithNodeDepthVec;

enum AzOptionColorInputOnValueChangeTag {
   AzOptionColorInputOnValueChangeTag_None,
   AzOptionColorInputOnValueChangeTag_Some,
};
typedef enum AzOptionColorInputOnValueChangeTag AzOptionColorInputOnValueChangeTag;

struct AzOptionColorInputOnValueChangeVariant_None { AzOptionColorInputOnValueChangeTag tag; };
typedef struct AzOptionColorInputOnValueChangeVariant_None AzOptionColorInputOnValueChangeVariant_None;
struct AzOptionColorInputOnValueChangeVariant_Some { AzOptionColorInputOnValueChangeTag tag; AzColorInputOnValueChange payload; };
typedef struct AzOptionColorInputOnValueChangeVariant_Some AzOptionColorInputOnValueChangeVariant_Some;
union AzOptionColorInputOnValueChange {
    AzOptionColorInputOnValueChangeVariant_None None;
    AzOptionColorInputOnValueChangeVariant_Some Some;
};
typedef union AzOptionColorInputOnValueChange AzOptionColorInputOnValueChange;

enum AzOptionButtonOnClickTag {
   AzOptionButtonOnClickTag_None,
   AzOptionButtonOnClickTag_Some,
};
typedef enum AzOptionButtonOnClickTag AzOptionButtonOnClickTag;

struct AzOptionButtonOnClickVariant_None { AzOptionButtonOnClickTag tag; };
typedef struct AzOptionButtonOnClickVariant_None AzOptionButtonOnClickVariant_None;
struct AzOptionButtonOnClickVariant_Some { AzOptionButtonOnClickTag tag; AzButtonOnClick payload; };
typedef struct AzOptionButtonOnClickVariant_Some AzOptionButtonOnClickVariant_Some;
union AzOptionButtonOnClick {
    AzOptionButtonOnClickVariant_None None;
    AzOptionButtonOnClickVariant_Some Some;
};
typedef union AzOptionButtonOnClick AzOptionButtonOnClick;

enum AzOptionCheckBoxOnToggleTag {
   AzOptionCheckBoxOnToggleTag_None,
   AzOptionCheckBoxOnToggleTag_Some,
};
typedef enum AzOptionCheckBoxOnToggleTag AzOptionCheckBoxOnToggleTag;

struct AzOptionCheckBoxOnToggleVariant_None { AzOptionCheckBoxOnToggleTag tag; };
typedef struct AzOptionCheckBoxOnToggleVariant_None AzOptionCheckBoxOnToggleVariant_None;
struct AzOptionCheckBoxOnToggleVariant_Some { AzOptionCheckBoxOnToggleTag tag; AzCheckBoxOnToggle payload; };
typedef struct AzOptionCheckBoxOnToggleVariant_Some AzOptionCheckBoxOnToggleVariant_Some;
union AzOptionCheckBoxOnToggle {
    AzOptionCheckBoxOnToggleVariant_None None;
    AzOptionCheckBoxOnToggleVariant_Some Some;
};
typedef union AzOptionCheckBoxOnToggle AzOptionCheckBoxOnToggle;

enum AzOptionTextInputOnTextInputTag {
   AzOptionTextInputOnTextInputTag_None,
   AzOptionTextInputOnTextInputTag_Some,
};
typedef enum AzOptionTextInputOnTextInputTag AzOptionTextInputOnTextInputTag;

struct AzOptionTextInputOnTextInputVariant_None { AzOptionTextInputOnTextInputTag tag; };
typedef struct AzOptionTextInputOnTextInputVariant_None AzOptionTextInputOnTextInputVariant_None;
struct AzOptionTextInputOnTextInputVariant_Some { AzOptionTextInputOnTextInputTag tag; AzTextInputOnTextInput payload; };
typedef struct AzOptionTextInputOnTextInputVariant_Some AzOptionTextInputOnTextInputVariant_Some;
union AzOptionTextInputOnTextInput {
    AzOptionTextInputOnTextInputVariant_None None;
    AzOptionTextInputOnTextInputVariant_Some Some;
};
typedef union AzOptionTextInputOnTextInput AzOptionTextInputOnTextInput;

enum AzOptionTextInputOnVirtualKeyDownTag {
   AzOptionTextInputOnVirtualKeyDownTag_None,
   AzOptionTextInputOnVirtualKeyDownTag_Some,
};
typedef enum AzOptionTextInputOnVirtualKeyDownTag AzOptionTextInputOnVirtualKeyDownTag;

struct AzOptionTextInputOnVirtualKeyDownVariant_None { AzOptionTextInputOnVirtualKeyDownTag tag; };
typedef struct AzOptionTextInputOnVirtualKeyDownVariant_None AzOptionTextInputOnVirtualKeyDownVariant_None;
struct AzOptionTextInputOnVirtualKeyDownVariant_Some { AzOptionTextInputOnVirtualKeyDownTag tag; AzTextInputOnVirtualKeyDown payload; };
typedef struct AzOptionTextInputOnVirtualKeyDownVariant_Some AzOptionTextInputOnVirtualKeyDownVariant_Some;
union AzOptionTextInputOnVirtualKeyDown {
    AzOptionTextInputOnVirtualKeyDownVariant_None None;
    AzOptionTextInputOnVirtualKeyDownVariant_Some Some;
};
typedef union AzOptionTextInputOnVirtualKeyDown AzOptionTextInputOnVirtualKeyDown;

enum AzOptionTextInputOnFocusLostTag {
   AzOptionTextInputOnFocusLostTag_None,
   AzOptionTextInputOnFocusLostTag_Some,
};
typedef enum AzOptionTextInputOnFocusLostTag AzOptionTextInputOnFocusLostTag;

struct AzOptionTextInputOnFocusLostVariant_None { AzOptionTextInputOnFocusLostTag tag; };
typedef struct AzOptionTextInputOnFocusLostVariant_None AzOptionTextInputOnFocusLostVariant_None;
struct AzOptionTextInputOnFocusLostVariant_Some { AzOptionTextInputOnFocusLostTag tag; AzTextInputOnFocusLost payload; };
typedef struct AzOptionTextInputOnFocusLostVariant_Some AzOptionTextInputOnFocusLostVariant_Some;
union AzOptionTextInputOnFocusLost {
    AzOptionTextInputOnFocusLostVariant_None None;
    AzOptionTextInputOnFocusLostVariant_Some Some;
};
typedef union AzOptionTextInputOnFocusLost AzOptionTextInputOnFocusLost;

enum AzOptionTextInputSelectionTag {
   AzOptionTextInputSelectionTag_None,
   AzOptionTextInputSelectionTag_Some,
};
typedef enum AzOptionTextInputSelectionTag AzOptionTextInputSelectionTag;

struct AzOptionTextInputSelectionVariant_None { AzOptionTextInputSelectionTag tag; };
typedef struct AzOptionTextInputSelectionVariant_None AzOptionTextInputSelectionVariant_None;
struct AzOptionTextInputSelectionVariant_Some { AzOptionTextInputSelectionTag tag; AzTextInputSelection payload; };
typedef struct AzOptionTextInputSelectionVariant_Some AzOptionTextInputSelectionVariant_Some;
union AzOptionTextInputSelection {
    AzOptionTextInputSelectionVariant_None None;
    AzOptionTextInputSelectionVariant_Some Some;
};
typedef union AzOptionTextInputSelection AzOptionTextInputSelection;

enum AzOptionNumberInputOnValueChangeTag {
   AzOptionNumberInputOnValueChangeTag_None,
   AzOptionNumberInputOnValueChangeTag_Some,
};
typedef enum AzOptionNumberInputOnValueChangeTag AzOptionNumberInputOnValueChangeTag;

struct AzOptionNumberInputOnValueChangeVariant_None { AzOptionNumberInputOnValueChangeTag tag; };
typedef struct AzOptionNumberInputOnValueChangeVariant_None AzOptionNumberInputOnValueChangeVariant_None;
struct AzOptionNumberInputOnValueChangeVariant_Some { AzOptionNumberInputOnValueChangeTag tag; AzNumberInputOnValueChange payload; };
typedef struct AzOptionNumberInputOnValueChangeVariant_Some AzOptionNumberInputOnValueChangeVariant_Some;
union AzOptionNumberInputOnValueChange {
    AzOptionNumberInputOnValueChangeVariant_None None;
    AzOptionNumberInputOnValueChangeVariant_Some Some;
};
typedef union AzOptionNumberInputOnValueChange AzOptionNumberInputOnValueChange;

enum AzOptionMenuItemIconTag {
   AzOptionMenuItemIconTag_None,
   AzOptionMenuItemIconTag_Some,
};
typedef enum AzOptionMenuItemIconTag AzOptionMenuItemIconTag;

struct AzOptionMenuItemIconVariant_None { AzOptionMenuItemIconTag tag; };
typedef struct AzOptionMenuItemIconVariant_None AzOptionMenuItemIconVariant_None;
struct AzOptionMenuItemIconVariant_Some { AzOptionMenuItemIconTag tag; AzMenuItemIcon payload; };
typedef struct AzOptionMenuItemIconVariant_Some AzOptionMenuItemIconVariant_Some;
union AzOptionMenuItemIcon {
    AzOptionMenuItemIconVariant_None None;
    AzOptionMenuItemIconVariant_Some Some;
};
typedef union AzOptionMenuItemIcon AzOptionMenuItemIcon;

enum AzOptionMenuCallbackTag {
   AzOptionMenuCallbackTag_None,
   AzOptionMenuCallbackTag_Some,
};
typedef enum AzOptionMenuCallbackTag AzOptionMenuCallbackTag;

struct AzOptionMenuCallbackVariant_None { AzOptionMenuCallbackTag tag; };
typedef struct AzOptionMenuCallbackVariant_None AzOptionMenuCallbackVariant_None;
struct AzOptionMenuCallbackVariant_Some { AzOptionMenuCallbackTag tag; AzMenuCallback payload; };
typedef struct AzOptionMenuCallbackVariant_Some AzOptionMenuCallbackVariant_Some;
union AzOptionMenuCallback {
    AzOptionMenuCallbackVariant_None None;
    AzOptionMenuCallbackVariant_Some Some;
};
typedef union AzOptionMenuCallback AzOptionMenuCallback;

enum AzOptionPositionInfoTag {
   AzOptionPositionInfoTag_None,
   AzOptionPositionInfoTag_Some,
};
typedef enum AzOptionPositionInfoTag AzOptionPositionInfoTag;

struct AzOptionPositionInfoVariant_None { AzOptionPositionInfoTag tag; };
typedef struct AzOptionPositionInfoVariant_None AzOptionPositionInfoVariant_None;
struct AzOptionPositionInfoVariant_Some { AzOptionPositionInfoTag tag; AzPositionInfo payload; };
typedef struct AzOptionPositionInfoVariant_Some AzOptionPositionInfoVariant_Some;
union AzOptionPositionInfo {
    AzOptionPositionInfoVariant_None None;
    AzOptionPositionInfoVariant_Some Some;
};
typedef union AzOptionPositionInfo AzOptionPositionInfo;

enum AzOptionTimerIdTag {
   AzOptionTimerIdTag_None,
   AzOptionTimerIdTag_Some,
};
typedef enum AzOptionTimerIdTag AzOptionTimerIdTag;

struct AzOptionTimerIdVariant_None { AzOptionTimerIdTag tag; };
typedef struct AzOptionTimerIdVariant_None AzOptionTimerIdVariant_None;
struct AzOptionTimerIdVariant_Some { AzOptionTimerIdTag tag; AzTimerId payload; };
typedef struct AzOptionTimerIdVariant_Some AzOptionTimerIdVariant_Some;
union AzOptionTimerId {
    AzOptionTimerIdVariant_None None;
    AzOptionTimerIdVariant_Some Some;
};
typedef union AzOptionTimerId AzOptionTimerId;

enum AzOptionThreadIdTag {
   AzOptionThreadIdTag_None,
   AzOptionThreadIdTag_Some,
};
typedef enum AzOptionThreadIdTag AzOptionThreadIdTag;

struct AzOptionThreadIdVariant_None { AzOptionThreadIdTag tag; };
typedef struct AzOptionThreadIdVariant_None AzOptionThreadIdVariant_None;
struct AzOptionThreadIdVariant_Some { AzOptionThreadIdTag tag; AzThreadId payload; };
typedef struct AzOptionThreadIdVariant_Some AzOptionThreadIdVariant_Some;
union AzOptionThreadId {
    AzOptionThreadIdVariant_None None;
    AzOptionThreadIdVariant_Some Some;
};
typedef union AzOptionThreadId AzOptionThreadId;

enum AzOptionImageRefTag {
   AzOptionImageRefTag_None,
   AzOptionImageRefTag_Some,
};
typedef enum AzOptionImageRefTag AzOptionImageRefTag;

struct AzOptionImageRefVariant_None { AzOptionImageRefTag tag; };
typedef struct AzOptionImageRefVariant_None AzOptionImageRefVariant_None;
struct AzOptionImageRefVariant_Some { AzOptionImageRefTag tag; AzImageRef payload; };
typedef struct AzOptionImageRefVariant_Some AzOptionImageRefVariant_Some;
union AzOptionImageRef {
    AzOptionImageRefVariant_None None;
    AzOptionImageRefVariant_Some Some;
};
typedef union AzOptionImageRef AzOptionImageRef;

enum AzOptionFontRefTag {
   AzOptionFontRefTag_None,
   AzOptionFontRefTag_Some,
};
typedef enum AzOptionFontRefTag AzOptionFontRefTag;

struct AzOptionFontRefVariant_None { AzOptionFontRefTag tag; };
typedef struct AzOptionFontRefVariant_None AzOptionFontRefVariant_None;
struct AzOptionFontRefVariant_Some { AzOptionFontRefTag tag; AzFontRef payload; };
typedef struct AzOptionFontRefVariant_Some AzOptionFontRefVariant_Some;
union AzOptionFontRef {
    AzOptionFontRefVariant_None None;
    AzOptionFontRefVariant_Some Some;
};
typedef union AzOptionFontRef AzOptionFontRef;

enum AzOptionSystemClipboardTag {
   AzOptionSystemClipboardTag_None,
   AzOptionSystemClipboardTag_Some,
};
typedef enum AzOptionSystemClipboardTag AzOptionSystemClipboardTag;

struct AzOptionSystemClipboardVariant_None { AzOptionSystemClipboardTag tag; };
typedef struct AzOptionSystemClipboardVariant_None AzOptionSystemClipboardVariant_None;
struct AzOptionSystemClipboardVariant_Some { AzOptionSystemClipboardTag tag; AzSystemClipboard payload; };
typedef struct AzOptionSystemClipboardVariant_Some AzOptionSystemClipboardVariant_Some;
union AzOptionSystemClipboard {
    AzOptionSystemClipboardVariant_None None;
    AzOptionSystemClipboardVariant_Some Some;
};
typedef union AzOptionSystemClipboard AzOptionSystemClipboard;

enum AzOptionGlTag {
   AzOptionGlTag_None,
   AzOptionGlTag_Some,
};
typedef enum AzOptionGlTag AzOptionGlTag;

struct AzOptionGlVariant_None { AzOptionGlTag tag; };
typedef struct AzOptionGlVariant_None AzOptionGlVariant_None;
struct AzOptionGlVariant_Some { AzOptionGlTag tag; AzGl payload; };
typedef struct AzOptionGlVariant_Some AzOptionGlVariant_Some;
union AzOptionGl {
    AzOptionGlVariant_None None;
    AzOptionGlVariant_Some Some;
};
typedef union AzOptionGl AzOptionGl;

enum AzOptionPercentageValueTag {
   AzOptionPercentageValueTag_None,
   AzOptionPercentageValueTag_Some,
};
typedef enum AzOptionPercentageValueTag AzOptionPercentageValueTag;

struct AzOptionPercentageValueVariant_None { AzOptionPercentageValueTag tag; };
typedef struct AzOptionPercentageValueVariant_None AzOptionPercentageValueVariant_None;
struct AzOptionPercentageValueVariant_Some { AzOptionPercentageValueTag tag; AzPercentageValue payload; };
typedef struct AzOptionPercentageValueVariant_Some AzOptionPercentageValueVariant_Some;
union AzOptionPercentageValue {
    AzOptionPercentageValueVariant_None None;
    AzOptionPercentageValueVariant_Some Some;
};
typedef union AzOptionPercentageValue AzOptionPercentageValue;

enum AzOptionAngleValueTag {
   AzOptionAngleValueTag_None,
   AzOptionAngleValueTag_Some,
};
typedef enum AzOptionAngleValueTag AzOptionAngleValueTag;

struct AzOptionAngleValueVariant_None { AzOptionAngleValueTag tag; };
typedef struct AzOptionAngleValueVariant_None AzOptionAngleValueVariant_None;
struct AzOptionAngleValueVariant_Some { AzOptionAngleValueTag tag; AzAngleValue payload; };
typedef struct AzOptionAngleValueVariant_Some AzOptionAngleValueVariant_Some;
union AzOptionAngleValue {
    AzOptionAngleValueVariant_None None;
    AzOptionAngleValueVariant_Some Some;
};
typedef union AzOptionAngleValue AzOptionAngleValue;

enum AzOptionRendererOptionsTag {
   AzOptionRendererOptionsTag_None,
   AzOptionRendererOptionsTag_Some,
};
typedef enum AzOptionRendererOptionsTag AzOptionRendererOptionsTag;

struct AzOptionRendererOptionsVariant_None { AzOptionRendererOptionsTag tag; };
typedef struct AzOptionRendererOptionsVariant_None AzOptionRendererOptionsVariant_None;
struct AzOptionRendererOptionsVariant_Some { AzOptionRendererOptionsTag tag; AzRendererOptions payload; };
typedef struct AzOptionRendererOptionsVariant_Some AzOptionRendererOptionsVariant_Some;
union AzOptionRendererOptions {
    AzOptionRendererOptionsVariant_None None;
    AzOptionRendererOptionsVariant_Some Some;
};
typedef union AzOptionRendererOptions AzOptionRendererOptions;

enum AzOptionCallbackTag {
   AzOptionCallbackTag_None,
   AzOptionCallbackTag_Some,
};
typedef enum AzOptionCallbackTag AzOptionCallbackTag;

struct AzOptionCallbackVariant_None { AzOptionCallbackTag tag; };
typedef struct AzOptionCallbackVariant_None AzOptionCallbackVariant_None;
struct AzOptionCallbackVariant_Some { AzOptionCallbackTag tag; AzCallback payload; };
typedef struct AzOptionCallbackVariant_Some AzOptionCallbackVariant_Some;
union AzOptionCallback {
    AzOptionCallbackVariant_None None;
    AzOptionCallbackVariant_Some Some;
};
typedef union AzOptionCallback AzOptionCallback;

enum AzOptionThreadSendMsgTag {
   AzOptionThreadSendMsgTag_None,
   AzOptionThreadSendMsgTag_Some,
};
typedef enum AzOptionThreadSendMsgTag AzOptionThreadSendMsgTag;

struct AzOptionThreadSendMsgVariant_None { AzOptionThreadSendMsgTag tag; };
typedef struct AzOptionThreadSendMsgVariant_None AzOptionThreadSendMsgVariant_None;
struct AzOptionThreadSendMsgVariant_Some { AzOptionThreadSendMsgTag tag; AzThreadSendMsg payload; };
typedef struct AzOptionThreadSendMsgVariant_Some AzOptionThreadSendMsgVariant_Some;
union AzOptionThreadSendMsg {
    AzOptionThreadSendMsgVariant_None None;
    AzOptionThreadSendMsgVariant_Some Some;
};
typedef union AzOptionThreadSendMsg AzOptionThreadSendMsg;

enum AzOptionLayoutRectTag {
   AzOptionLayoutRectTag_None,
   AzOptionLayoutRectTag_Some,
};
typedef enum AzOptionLayoutRectTag AzOptionLayoutRectTag;

struct AzOptionLayoutRectVariant_None { AzOptionLayoutRectTag tag; };
typedef struct AzOptionLayoutRectVariant_None AzOptionLayoutRectVariant_None;
struct AzOptionLayoutRectVariant_Some { AzOptionLayoutRectTag tag; AzLayoutRect payload; };
typedef struct AzOptionLayoutRectVariant_Some AzOptionLayoutRectVariant_Some;
union AzOptionLayoutRect {
    AzOptionLayoutRectVariant_None None;
    AzOptionLayoutRectVariant_Some Some;
};
typedef union AzOptionLayoutRect AzOptionLayoutRect;

enum AzOptionRefAnyTag {
   AzOptionRefAnyTag_None,
   AzOptionRefAnyTag_Some,
};
typedef enum AzOptionRefAnyTag AzOptionRefAnyTag;

struct AzOptionRefAnyVariant_None { AzOptionRefAnyTag tag; };
typedef struct AzOptionRefAnyVariant_None AzOptionRefAnyVariant_None;
struct AzOptionRefAnyVariant_Some { AzOptionRefAnyTag tag; AzRefAny payload; };
typedef struct AzOptionRefAnyVariant_Some AzOptionRefAnyVariant_Some;
union AzOptionRefAny {
    AzOptionRefAnyVariant_None None;
    AzOptionRefAnyVariant_Some Some;
};
typedef union AzOptionRefAny AzOptionRefAny;

enum AzOptionLayoutPointTag {
   AzOptionLayoutPointTag_None,
   AzOptionLayoutPointTag_Some,
};
typedef enum AzOptionLayoutPointTag AzOptionLayoutPointTag;

struct AzOptionLayoutPointVariant_None { AzOptionLayoutPointTag tag; };
typedef struct AzOptionLayoutPointVariant_None AzOptionLayoutPointVariant_None;
struct AzOptionLayoutPointVariant_Some { AzOptionLayoutPointTag tag; AzLayoutPoint payload; };
typedef struct AzOptionLayoutPointVariant_Some AzOptionLayoutPointVariant_Some;
union AzOptionLayoutPoint {
    AzOptionLayoutPointVariant_None None;
    AzOptionLayoutPointVariant_Some Some;
};
typedef union AzOptionLayoutPoint AzOptionLayoutPoint;

enum AzOptionLayoutSizeTag {
   AzOptionLayoutSizeTag_None,
   AzOptionLayoutSizeTag_Some,
};
typedef enum AzOptionLayoutSizeTag AzOptionLayoutSizeTag;

struct AzOptionLayoutSizeVariant_None { AzOptionLayoutSizeTag tag; };
typedef struct AzOptionLayoutSizeVariant_None AzOptionLayoutSizeVariant_None;
struct AzOptionLayoutSizeVariant_Some { AzOptionLayoutSizeTag tag; AzLayoutSize payload; };
typedef struct AzOptionLayoutSizeVariant_Some AzOptionLayoutSizeVariant_Some;
union AzOptionLayoutSize {
    AzOptionLayoutSizeVariant_None None;
    AzOptionLayoutSizeVariant_Some Some;
};
typedef union AzOptionLayoutSize AzOptionLayoutSize;

enum AzOptionWindowThemeTag {
   AzOptionWindowThemeTag_None,
   AzOptionWindowThemeTag_Some,
};
typedef enum AzOptionWindowThemeTag AzOptionWindowThemeTag;

struct AzOptionWindowThemeVariant_None { AzOptionWindowThemeTag tag; };
typedef struct AzOptionWindowThemeVariant_None AzOptionWindowThemeVariant_None;
struct AzOptionWindowThemeVariant_Some { AzOptionWindowThemeTag tag; AzWindowTheme payload; };
typedef struct AzOptionWindowThemeVariant_Some AzOptionWindowThemeVariant_Some;
union AzOptionWindowTheme {
    AzOptionWindowThemeVariant_None None;
    AzOptionWindowThemeVariant_Some Some;
};
typedef union AzOptionWindowTheme AzOptionWindowTheme;

enum AzOptionNodeIdTag {
   AzOptionNodeIdTag_None,
   AzOptionNodeIdTag_Some,
};
typedef enum AzOptionNodeIdTag AzOptionNodeIdTag;

struct AzOptionNodeIdVariant_None { AzOptionNodeIdTag tag; };
typedef struct AzOptionNodeIdVariant_None AzOptionNodeIdVariant_None;
struct AzOptionNodeIdVariant_Some { AzOptionNodeIdTag tag; AzNodeId payload; };
typedef struct AzOptionNodeIdVariant_Some AzOptionNodeIdVariant_Some;
union AzOptionNodeId {
    AzOptionNodeIdVariant_None None;
    AzOptionNodeIdVariant_Some Some;
};
typedef union AzOptionNodeId AzOptionNodeId;

enum AzOptionDomNodeIdTag {
   AzOptionDomNodeIdTag_None,
   AzOptionDomNodeIdTag_Some,
};
typedef enum AzOptionDomNodeIdTag AzOptionDomNodeIdTag;

struct AzOptionDomNodeIdVariant_None { AzOptionDomNodeIdTag tag; };
typedef struct AzOptionDomNodeIdVariant_None AzOptionDomNodeIdVariant_None;
struct AzOptionDomNodeIdVariant_Some { AzOptionDomNodeIdTag tag; AzDomNodeId payload; };
typedef struct AzOptionDomNodeIdVariant_Some AzOptionDomNodeIdVariant_Some;
union AzOptionDomNodeId {
    AzOptionDomNodeIdVariant_None None;
    AzOptionDomNodeIdVariant_Some Some;
};
typedef union AzOptionDomNodeId AzOptionDomNodeId;

enum AzOptionColorUTag {
   AzOptionColorUTag_None,
   AzOptionColorUTag_Some,
};
typedef enum AzOptionColorUTag AzOptionColorUTag;

struct AzOptionColorUVariant_None { AzOptionColorUTag tag; };
typedef struct AzOptionColorUVariant_None AzOptionColorUVariant_None;
struct AzOptionColorUVariant_Some { AzOptionColorUTag tag; AzColorU payload; };
typedef struct AzOptionColorUVariant_Some AzOptionColorUVariant_Some;
union AzOptionColorU {
    AzOptionColorUVariant_None None;
    AzOptionColorUVariant_Some Some;
};
typedef union AzOptionColorU AzOptionColorU;

enum AzOptionSvgDashPatternTag {
   AzOptionSvgDashPatternTag_None,
   AzOptionSvgDashPatternTag_Some,
};
typedef enum AzOptionSvgDashPatternTag AzOptionSvgDashPatternTag;

struct AzOptionSvgDashPatternVariant_None { AzOptionSvgDashPatternTag tag; };
typedef struct AzOptionSvgDashPatternVariant_None AzOptionSvgDashPatternVariant_None;
struct AzOptionSvgDashPatternVariant_Some { AzOptionSvgDashPatternTag tag; AzSvgDashPattern payload; };
typedef struct AzOptionSvgDashPatternVariant_Some AzOptionSvgDashPatternVariant_Some;
union AzOptionSvgDashPattern {
    AzOptionSvgDashPatternVariant_None None;
    AzOptionSvgDashPatternVariant_Some Some;
};
typedef union AzOptionSvgDashPattern AzOptionSvgDashPattern;

enum AzOptionLogicalPositionTag {
   AzOptionLogicalPositionTag_None,
   AzOptionLogicalPositionTag_Some,
};
typedef enum AzOptionLogicalPositionTag AzOptionLogicalPositionTag;

struct AzOptionLogicalPositionVariant_None { AzOptionLogicalPositionTag tag; };
typedef struct AzOptionLogicalPositionVariant_None AzOptionLogicalPositionVariant_None;
struct AzOptionLogicalPositionVariant_Some { AzOptionLogicalPositionTag tag; AzLogicalPosition payload; };
typedef struct AzOptionLogicalPositionVariant_Some AzOptionLogicalPositionVariant_Some;
union AzOptionLogicalPosition {
    AzOptionLogicalPositionVariant_None None;
    AzOptionLogicalPositionVariant_Some Some;
};
typedef union AzOptionLogicalPosition AzOptionLogicalPosition;

enum AzOptionPhysicalPositionI32Tag {
   AzOptionPhysicalPositionI32Tag_None,
   AzOptionPhysicalPositionI32Tag_Some,
};
typedef enum AzOptionPhysicalPositionI32Tag AzOptionPhysicalPositionI32Tag;

struct AzOptionPhysicalPositionI32Variant_None { AzOptionPhysicalPositionI32Tag tag; };
typedef struct AzOptionPhysicalPositionI32Variant_None AzOptionPhysicalPositionI32Variant_None;
struct AzOptionPhysicalPositionI32Variant_Some { AzOptionPhysicalPositionI32Tag tag; AzPhysicalPositionI32 payload; };
typedef struct AzOptionPhysicalPositionI32Variant_Some AzOptionPhysicalPositionI32Variant_Some;
union AzOptionPhysicalPositionI32 {
    AzOptionPhysicalPositionI32Variant_None None;
    AzOptionPhysicalPositionI32Variant_Some Some;
};
typedef union AzOptionPhysicalPositionI32 AzOptionPhysicalPositionI32;

enum AzOptionMouseCursorTypeTag {
   AzOptionMouseCursorTypeTag_None,
   AzOptionMouseCursorTypeTag_Some,
};
typedef enum AzOptionMouseCursorTypeTag AzOptionMouseCursorTypeTag;

struct AzOptionMouseCursorTypeVariant_None { AzOptionMouseCursorTypeTag tag; };
typedef struct AzOptionMouseCursorTypeVariant_None AzOptionMouseCursorTypeVariant_None;
struct AzOptionMouseCursorTypeVariant_Some { AzOptionMouseCursorTypeTag tag; AzMouseCursorType payload; };
typedef struct AzOptionMouseCursorTypeVariant_Some AzOptionMouseCursorTypeVariant_Some;
union AzOptionMouseCursorType {
    AzOptionMouseCursorTypeVariant_None None;
    AzOptionMouseCursorTypeVariant_Some Some;
};
typedef union AzOptionMouseCursorType AzOptionMouseCursorType;

enum AzOptionLogicalSizeTag {
   AzOptionLogicalSizeTag_None,
   AzOptionLogicalSizeTag_Some,
};
typedef enum AzOptionLogicalSizeTag AzOptionLogicalSizeTag;

struct AzOptionLogicalSizeVariant_None { AzOptionLogicalSizeTag tag; };
typedef struct AzOptionLogicalSizeVariant_None AzOptionLogicalSizeVariant_None;
struct AzOptionLogicalSizeVariant_Some { AzOptionLogicalSizeTag tag; AzLogicalSize payload; };
typedef struct AzOptionLogicalSizeVariant_Some AzOptionLogicalSizeVariant_Some;
union AzOptionLogicalSize {
    AzOptionLogicalSizeVariant_None None;
    AzOptionLogicalSizeVariant_Some Some;
};
typedef union AzOptionLogicalSize AzOptionLogicalSize;

enum AzOptionVirtualKeyCodeTag {
   AzOptionVirtualKeyCodeTag_None,
   AzOptionVirtualKeyCodeTag_Some,
};
typedef enum AzOptionVirtualKeyCodeTag AzOptionVirtualKeyCodeTag;

struct AzOptionVirtualKeyCodeVariant_None { AzOptionVirtualKeyCodeTag tag; };
typedef struct AzOptionVirtualKeyCodeVariant_None AzOptionVirtualKeyCodeVariant_None;
struct AzOptionVirtualKeyCodeVariant_Some { AzOptionVirtualKeyCodeTag tag; AzVirtualKeyCode payload; };
typedef struct AzOptionVirtualKeyCodeVariant_Some AzOptionVirtualKeyCodeVariant_Some;
union AzOptionVirtualKeyCode {
    AzOptionVirtualKeyCodeVariant_None None;
    AzOptionVirtualKeyCodeVariant_Some Some;
};
typedef union AzOptionVirtualKeyCode AzOptionVirtualKeyCode;

enum AzOptionImageMaskTag {
   AzOptionImageMaskTag_None,
   AzOptionImageMaskTag_Some,
};
typedef enum AzOptionImageMaskTag AzOptionImageMaskTag;

struct AzOptionImageMaskVariant_None { AzOptionImageMaskTag tag; };
typedef struct AzOptionImageMaskVariant_None AzOptionImageMaskVariant_None;
struct AzOptionImageMaskVariant_Some { AzOptionImageMaskTag tag; AzImageMask payload; };
typedef struct AzOptionImageMaskVariant_Some AzOptionImageMaskVariant_Some;
union AzOptionImageMask {
    AzOptionImageMaskVariant_None None;
    AzOptionImageMaskVariant_Some Some;
};
typedef union AzOptionImageMask AzOptionImageMask;

enum AzOptionTabIndexTag {
   AzOptionTabIndexTag_None,
   AzOptionTabIndexTag_Some,
};
typedef enum AzOptionTabIndexTag AzOptionTabIndexTag;

struct AzOptionTabIndexVariant_None { AzOptionTabIndexTag tag; };
typedef struct AzOptionTabIndexVariant_None AzOptionTabIndexVariant_None;
struct AzOptionTabIndexVariant_Some { AzOptionTabIndexTag tag; AzTabIndex payload; };
typedef struct AzOptionTabIndexVariant_Some AzOptionTabIndexVariant_Some;
union AzOptionTabIndex {
    AzOptionTabIndexVariant_None None;
    AzOptionTabIndexVariant_Some Some;
};
typedef union AzOptionTabIndex AzOptionTabIndex;

enum AzOptionTagIdTag {
   AzOptionTagIdTag_None,
   AzOptionTagIdTag_Some,
};
typedef enum AzOptionTagIdTag AzOptionTagIdTag;

struct AzOptionTagIdVariant_None { AzOptionTagIdTag tag; };
typedef struct AzOptionTagIdVariant_None AzOptionTagIdVariant_None;
struct AzOptionTagIdVariant_Some { AzOptionTagIdTag tag; AzTagId payload; };
typedef struct AzOptionTagIdVariant_Some AzOptionTagIdVariant_Some;
union AzOptionTagId {
    AzOptionTagIdVariant_None None;
    AzOptionTagIdVariant_Some Some;
};
typedef union AzOptionTagId AzOptionTagId;

enum AzOptionDurationTag {
   AzOptionDurationTag_None,
   AzOptionDurationTag_Some,
};
typedef enum AzOptionDurationTag AzOptionDurationTag;

struct AzOptionDurationVariant_None { AzOptionDurationTag tag; };
typedef struct AzOptionDurationVariant_None AzOptionDurationVariant_None;
struct AzOptionDurationVariant_Some { AzOptionDurationTag tag; AzDuration payload; };
typedef struct AzOptionDurationVariant_Some AzOptionDurationVariant_Some;
union AzOptionDuration {
    AzOptionDurationVariant_None None;
    AzOptionDurationVariant_Some Some;
};
typedef union AzOptionDuration AzOptionDuration;

enum AzOptionU8VecTag {
   AzOptionU8VecTag_None,
   AzOptionU8VecTag_Some,
};
typedef enum AzOptionU8VecTag AzOptionU8VecTag;

struct AzOptionU8VecVariant_None { AzOptionU8VecTag tag; };
typedef struct AzOptionU8VecVariant_None AzOptionU8VecVariant_None;
struct AzOptionU8VecVariant_Some { AzOptionU8VecTag tag; AzU8Vec payload; };
typedef struct AzOptionU8VecVariant_Some AzOptionU8VecVariant_Some;
union AzOptionU8Vec {
    AzOptionU8VecVariant_None None;
    AzOptionU8VecVariant_Some Some;
};
typedef union AzOptionU8Vec AzOptionU8Vec;

enum AzOptionU8VecRefTag {
   AzOptionU8VecRefTag_None,
   AzOptionU8VecRefTag_Some,
};
typedef enum AzOptionU8VecRefTag AzOptionU8VecRefTag;

struct AzOptionU8VecRefVariant_None { AzOptionU8VecRefTag tag; };
typedef struct AzOptionU8VecRefVariant_None AzOptionU8VecRefVariant_None;
struct AzOptionU8VecRefVariant_Some { AzOptionU8VecRefTag tag; AzU8VecRef payload; };
typedef struct AzOptionU8VecRefVariant_Some AzOptionU8VecRefVariant_Some;
union AzOptionU8VecRef {
    AzOptionU8VecRefVariant_None None;
    AzOptionU8VecRefVariant_Some Some;
};
typedef union AzOptionU8VecRef AzOptionU8VecRef;

enum AzResultU8VecEncodeImageErrorTag {
   AzResultU8VecEncodeImageErrorTag_Ok,
   AzResultU8VecEncodeImageErrorTag_Err,
};
typedef enum AzResultU8VecEncodeImageErrorTag AzResultU8VecEncodeImageErrorTag;

struct AzResultU8VecEncodeImageErrorVariant_Ok { AzResultU8VecEncodeImageErrorTag tag; AzU8Vec payload; };
typedef struct AzResultU8VecEncodeImageErrorVariant_Ok AzResultU8VecEncodeImageErrorVariant_Ok;
struct AzResultU8VecEncodeImageErrorVariant_Err { AzResultU8VecEncodeImageErrorTag tag; AzEncodeImageError payload; };
typedef struct AzResultU8VecEncodeImageErrorVariant_Err AzResultU8VecEncodeImageErrorVariant_Err;
union AzResultU8VecEncodeImageError {
    AzResultU8VecEncodeImageErrorVariant_Ok Ok;
    AzResultU8VecEncodeImageErrorVariant_Err Err;
};
typedef union AzResultU8VecEncodeImageError AzResultU8VecEncodeImageError;

struct AzNonXmlCharError {
    uint32_t ch;
    AzSvgParseErrorPosition pos;
};
typedef struct AzNonXmlCharError AzNonXmlCharError;

struct AzInvalidCharError {
    uint8_t expected;
    uint8_t got;
    AzSvgParseErrorPosition pos;
};
typedef struct AzInvalidCharError AzInvalidCharError;

struct AzInvalidCharMultipleError {
    uint8_t expected;
    AzU8Vec got;
    AzSvgParseErrorPosition pos;
};
typedef struct AzInvalidCharMultipleError AzInvalidCharMultipleError;

struct AzInvalidQuoteError {
    uint8_t got;
    AzSvgParseErrorPosition pos;
};
typedef struct AzInvalidQuoteError AzInvalidQuoteError;

struct AzInvalidSpaceError {
    uint8_t got;
    AzSvgParseErrorPosition pos;
};
typedef struct AzInvalidSpaceError AzInvalidSpaceError;

struct AzAppConfig {
    AzLayoutSolver layout_solver;
    AzAppLogLevel log_level;
    bool  enable_visual_panic_hook;
    bool  enable_logging_on_panic;
    bool  enable_tab_navigation;
    AzSystemCallbacks system_callbacks;
};
typedef struct AzAppConfig AzAppConfig;

struct AzSmallWindowIconBytes {
    AzIconKey key;
    AzU8Vec rgba_bytes;
};
typedef struct AzSmallWindowIconBytes AzSmallWindowIconBytes;

struct AzLargeWindowIconBytes {
    AzIconKey key;
    AzU8Vec rgba_bytes;
};
typedef struct AzLargeWindowIconBytes AzLargeWindowIconBytes;

enum AzWindowIconTag {
   AzWindowIconTag_Small,
   AzWindowIconTag_Large,
};
typedef enum AzWindowIconTag AzWindowIconTag;

struct AzWindowIconVariant_Small { AzWindowIconTag tag; AzSmallWindowIconBytes payload; };
typedef struct AzWindowIconVariant_Small AzWindowIconVariant_Small;
struct AzWindowIconVariant_Large { AzWindowIconTag tag; AzLargeWindowIconBytes payload; };
typedef struct AzWindowIconVariant_Large AzWindowIconVariant_Large;
union AzWindowIcon {
    AzWindowIconVariant_Small Small;
    AzWindowIconVariant_Large Large;
};
typedef union AzWindowIcon AzWindowIcon;

struct AzTaskBarIcon {
    AzIconKey key;
    AzU8Vec rgba_bytes;
};
typedef struct AzTaskBarIcon AzTaskBarIcon;

struct AzWindowSize {
    AzLogicalSize dimensions;
    float hidpi_factor;
    float system_hidpi_factor;
    uint32_t dpi;
    AzOptionLogicalSize min_dimensions;
    AzOptionLogicalSize max_dimensions;
};
typedef struct AzWindowSize AzWindowSize;

struct AzKeyboardState {
    bool  shift_down;
    bool  ctrl_down;
    bool  alt_down;
    bool  super_down;
    AzOptionChar current_char;
    AzOptionVirtualKeyCode current_virtual_keycode;
    AzVirtualKeyCodeVec pressed_virtual_keycodes;
    AzScanCodeVec pressed_scancodes;
};
typedef struct AzKeyboardState AzKeyboardState;

struct AzMouseState {
    AzOptionMouseCursorType mouse_cursor_type;
    AzCursorPosition cursor_position;
    bool  is_cursor_locked;
    bool  left_down;
    bool  right_down;
    bool  middle_down;
    AzOptionF32 scroll_x;
    AzOptionF32 scroll_y;
};
typedef struct AzMouseState AzMouseState;

struct AzMarshaledLayoutCallback {
    AzRefAny marshal_data;
    AzMarshaledLayoutCallbackInner cb;
};
typedef struct AzMarshaledLayoutCallback AzMarshaledLayoutCallback;

struct AzInlineTextContents {
    AzInlineGlyphVec glyphs;
    AzLogicalRect bounds;
};
typedef struct AzInlineTextContents AzInlineTextContents;

enum AzAnimationEasingTag {
   AzAnimationEasingTag_Ease,
   AzAnimationEasingTag_Linear,
   AzAnimationEasingTag_EaseIn,
   AzAnimationEasingTag_EaseOut,
   AzAnimationEasingTag_EaseInOut,
   AzAnimationEasingTag_CubicBezier,
};
typedef enum AzAnimationEasingTag AzAnimationEasingTag;

struct AzAnimationEasingVariant_Ease { AzAnimationEasingTag tag; };
typedef struct AzAnimationEasingVariant_Ease AzAnimationEasingVariant_Ease;
struct AzAnimationEasingVariant_Linear { AzAnimationEasingTag tag; };
typedef struct AzAnimationEasingVariant_Linear AzAnimationEasingVariant_Linear;
struct AzAnimationEasingVariant_EaseIn { AzAnimationEasingTag tag; };
typedef struct AzAnimationEasingVariant_EaseIn AzAnimationEasingVariant_EaseIn;
struct AzAnimationEasingVariant_EaseOut { AzAnimationEasingTag tag; };
typedef struct AzAnimationEasingVariant_EaseOut AzAnimationEasingVariant_EaseOut;
struct AzAnimationEasingVariant_EaseInOut { AzAnimationEasingTag tag; };
typedef struct AzAnimationEasingVariant_EaseInOut AzAnimationEasingVariant_EaseInOut;
struct AzAnimationEasingVariant_CubicBezier { AzAnimationEasingTag tag; AzSvgCubicCurve payload; };
typedef struct AzAnimationEasingVariant_CubicBezier AzAnimationEasingVariant_CubicBezier;
union AzAnimationEasing {
    AzAnimationEasingVariant_Ease Ease;
    AzAnimationEasingVariant_Linear Linear;
    AzAnimationEasingVariant_EaseIn EaseIn;
    AzAnimationEasingVariant_EaseOut EaseOut;
    AzAnimationEasingVariant_EaseInOut EaseInOut;
    AzAnimationEasingVariant_CubicBezier CubicBezier;
};
typedef union AzAnimationEasing AzAnimationEasing;

struct AzRenderImageCallbackInfo {
    AzDomNodeId callback_node_id;
    AzHidpiAdjustedBounds bounds;
    AzOptionGl* gl_context;
    void* image_cache;
    void* system_fonts;
    AzNodeVec* node_hierarchy;
    void* words_cache;
    void* shaped_words_cache;
    void* positioned_words_cache;
    void* positioned_rects;
    void* _reserved_ref;
    void* restrict _reserved_mut;
};
typedef struct AzRenderImageCallbackInfo AzRenderImageCallbackInfo;

struct AzLayoutCallbackInfo {
    AzWindowSize window_size;
    AzWindowTheme theme;
    void* image_cache;
    AzOptionGl* gl_context;
    void* system_fonts;
    void* _reserved_ref;
    void* restrict _reserved_mut;
};
typedef struct AzLayoutCallbackInfo AzLayoutCallbackInfo;

enum AzEventFilterTag {
   AzEventFilterTag_Hover,
   AzEventFilterTag_Not,
   AzEventFilterTag_Focus,
   AzEventFilterTag_Window,
   AzEventFilterTag_Component,
   AzEventFilterTag_Application,
};
typedef enum AzEventFilterTag AzEventFilterTag;

struct AzEventFilterVariant_Hover { AzEventFilterTag tag; AzHoverEventFilter payload; };
typedef struct AzEventFilterVariant_Hover AzEventFilterVariant_Hover;
struct AzEventFilterVariant_Not { AzEventFilterTag tag; AzNotEventFilter payload; };
typedef struct AzEventFilterVariant_Not AzEventFilterVariant_Not;
struct AzEventFilterVariant_Focus { AzEventFilterTag tag; AzFocusEventFilter payload; };
typedef struct AzEventFilterVariant_Focus AzEventFilterVariant_Focus;
struct AzEventFilterVariant_Window { AzEventFilterTag tag; AzWindowEventFilter payload; };
typedef struct AzEventFilterVariant_Window AzEventFilterVariant_Window;
struct AzEventFilterVariant_Component { AzEventFilterTag tag; AzComponentEventFilter payload; };
typedef struct AzEventFilterVariant_Component AzEventFilterVariant_Component;
struct AzEventFilterVariant_Application { AzEventFilterTag tag; AzApplicationEventFilter payload; };
typedef struct AzEventFilterVariant_Application AzEventFilterVariant_Application;
union AzEventFilter {
    AzEventFilterVariant_Hover Hover;
    AzEventFilterVariant_Not Not;
    AzEventFilterVariant_Focus Focus;
    AzEventFilterVariant_Window Window;
    AzEventFilterVariant_Component Component;
    AzEventFilterVariant_Application Application;
};
typedef union AzEventFilter AzEventFilter;

struct AzMenu {
    AzMenuItemVec items;
    AzMenuPopupPosition position;
};
typedef struct AzMenu AzMenu;

struct AzVirtualKeyCodeCombo {
    AzVirtualKeyCodeVec keys;
};
typedef struct AzVirtualKeyCodeCombo AzVirtualKeyCodeCombo;

enum AzCssPathPseudoSelectorTag {
   AzCssPathPseudoSelectorTag_First,
   AzCssPathPseudoSelectorTag_Last,
   AzCssPathPseudoSelectorTag_NthChild,
   AzCssPathPseudoSelectorTag_Hover,
   AzCssPathPseudoSelectorTag_Active,
   AzCssPathPseudoSelectorTag_Focus,
};
typedef enum AzCssPathPseudoSelectorTag AzCssPathPseudoSelectorTag;

struct AzCssPathPseudoSelectorVariant_First { AzCssPathPseudoSelectorTag tag; };
typedef struct AzCssPathPseudoSelectorVariant_First AzCssPathPseudoSelectorVariant_First;
struct AzCssPathPseudoSelectorVariant_Last { AzCssPathPseudoSelectorTag tag; };
typedef struct AzCssPathPseudoSelectorVariant_Last AzCssPathPseudoSelectorVariant_Last;
struct AzCssPathPseudoSelectorVariant_NthChild { AzCssPathPseudoSelectorTag tag; AzCssNthChildSelector payload; };
typedef struct AzCssPathPseudoSelectorVariant_NthChild AzCssPathPseudoSelectorVariant_NthChild;
struct AzCssPathPseudoSelectorVariant_Hover { AzCssPathPseudoSelectorTag tag; };
typedef struct AzCssPathPseudoSelectorVariant_Hover AzCssPathPseudoSelectorVariant_Hover;
struct AzCssPathPseudoSelectorVariant_Active { AzCssPathPseudoSelectorTag tag; };
typedef struct AzCssPathPseudoSelectorVariant_Active AzCssPathPseudoSelectorVariant_Active;
struct AzCssPathPseudoSelectorVariant_Focus { AzCssPathPseudoSelectorTag tag; };
typedef struct AzCssPathPseudoSelectorVariant_Focus AzCssPathPseudoSelectorVariant_Focus;
union AzCssPathPseudoSelector {
    AzCssPathPseudoSelectorVariant_First First;
    AzCssPathPseudoSelectorVariant_Last Last;
    AzCssPathPseudoSelectorVariant_NthChild NthChild;
    AzCssPathPseudoSelectorVariant_Hover Hover;
    AzCssPathPseudoSelectorVariant_Active Active;
    AzCssPathPseudoSelectorVariant_Focus Focus;
};
typedef union AzCssPathPseudoSelector AzCssPathPseudoSelector;

enum AzAnimationInterpolationFunctionTag {
   AzAnimationInterpolationFunctionTag_Ease,
   AzAnimationInterpolationFunctionTag_Linear,
   AzAnimationInterpolationFunctionTag_EaseIn,
   AzAnimationInterpolationFunctionTag_EaseOut,
   AzAnimationInterpolationFunctionTag_EaseInOut,
   AzAnimationInterpolationFunctionTag_CubicBezier,
};
typedef enum AzAnimationInterpolationFunctionTag AzAnimationInterpolationFunctionTag;

struct AzAnimationInterpolationFunctionVariant_Ease { AzAnimationInterpolationFunctionTag tag; };
typedef struct AzAnimationInterpolationFunctionVariant_Ease AzAnimationInterpolationFunctionVariant_Ease;
struct AzAnimationInterpolationFunctionVariant_Linear { AzAnimationInterpolationFunctionTag tag; };
typedef struct AzAnimationInterpolationFunctionVariant_Linear AzAnimationInterpolationFunctionVariant_Linear;
struct AzAnimationInterpolationFunctionVariant_EaseIn { AzAnimationInterpolationFunctionTag tag; };
typedef struct AzAnimationInterpolationFunctionVariant_EaseIn AzAnimationInterpolationFunctionVariant_EaseIn;
struct AzAnimationInterpolationFunctionVariant_EaseOut { AzAnimationInterpolationFunctionTag tag; };
typedef struct AzAnimationInterpolationFunctionVariant_EaseOut AzAnimationInterpolationFunctionVariant_EaseOut;
struct AzAnimationInterpolationFunctionVariant_EaseInOut { AzAnimationInterpolationFunctionTag tag; };
typedef struct AzAnimationInterpolationFunctionVariant_EaseInOut AzAnimationInterpolationFunctionVariant_EaseInOut;
struct AzAnimationInterpolationFunctionVariant_CubicBezier { AzAnimationInterpolationFunctionTag tag; AzSvgCubicCurve payload; };
typedef struct AzAnimationInterpolationFunctionVariant_CubicBezier AzAnimationInterpolationFunctionVariant_CubicBezier;
union AzAnimationInterpolationFunction {
    AzAnimationInterpolationFunctionVariant_Ease Ease;
    AzAnimationInterpolationFunctionVariant_Linear Linear;
    AzAnimationInterpolationFunctionVariant_EaseIn EaseIn;
    AzAnimationInterpolationFunctionVariant_EaseOut EaseOut;
    AzAnimationInterpolationFunctionVariant_EaseInOut EaseInOut;
    AzAnimationInterpolationFunctionVariant_CubicBezier CubicBezier;
};
typedef union AzAnimationInterpolationFunction AzAnimationInterpolationFunction;

struct AzInterpolateContext {
    AzAnimationInterpolationFunction animation_func;
    float parent_rect_width;
    float parent_rect_height;
    float current_rect_width;
    float current_rect_height;
};
typedef struct AzInterpolateContext AzInterpolateContext;

struct AzLinearGradient {
    AzDirection direction;
    AzExtendMode extend_mode;
    AzNormalizedLinearColorStopVec stops;
};
typedef struct AzLinearGradient AzLinearGradient;

struct AzRadialGradient {
    AzShape shape;
    AzRadialGradientSize size;
    AzStyleBackgroundPosition position;
    AzExtendMode extend_mode;
    AzNormalizedLinearColorStopVec stops;
};
typedef struct AzRadialGradient AzRadialGradient;

struct AzConicGradient {
    AzExtendMode extend_mode;
    AzStyleBackgroundPosition center;
    AzAngleValue angle;
    AzNormalizedRadialColorStopVec stops;
};
typedef struct AzConicGradient AzConicGradient;

enum AzStyleTransformTag {
   AzStyleTransformTag_Matrix,
   AzStyleTransformTag_Matrix3D,
   AzStyleTransformTag_Translate,
   AzStyleTransformTag_Translate3D,
   AzStyleTransformTag_TranslateX,
   AzStyleTransformTag_TranslateY,
   AzStyleTransformTag_TranslateZ,
   AzStyleTransformTag_Rotate,
   AzStyleTransformTag_Rotate3D,
   AzStyleTransformTag_RotateX,
   AzStyleTransformTag_RotateY,
   AzStyleTransformTag_RotateZ,
   AzStyleTransformTag_Scale,
   AzStyleTransformTag_Scale3D,
   AzStyleTransformTag_ScaleX,
   AzStyleTransformTag_ScaleY,
   AzStyleTransformTag_ScaleZ,
   AzStyleTransformTag_Skew,
   AzStyleTransformTag_SkewX,
   AzStyleTransformTag_SkewY,
   AzStyleTransformTag_Perspective,
};
typedef enum AzStyleTransformTag AzStyleTransformTag;

struct AzStyleTransformVariant_Matrix { AzStyleTransformTag tag; AzStyleTransformMatrix2D payload; };
typedef struct AzStyleTransformVariant_Matrix AzStyleTransformVariant_Matrix;
struct AzStyleTransformVariant_Matrix3D { AzStyleTransformTag tag; AzStyleTransformMatrix3D payload; };
typedef struct AzStyleTransformVariant_Matrix3D AzStyleTransformVariant_Matrix3D;
struct AzStyleTransformVariant_Translate { AzStyleTransformTag tag; AzStyleTransformTranslate2D payload; };
typedef struct AzStyleTransformVariant_Translate AzStyleTransformVariant_Translate;
struct AzStyleTransformVariant_Translate3D { AzStyleTransformTag tag; AzStyleTransformTranslate3D payload; };
typedef struct AzStyleTransformVariant_Translate3D AzStyleTransformVariant_Translate3D;
struct AzStyleTransformVariant_TranslateX { AzStyleTransformTag tag; AzPixelValue payload; };
typedef struct AzStyleTransformVariant_TranslateX AzStyleTransformVariant_TranslateX;
struct AzStyleTransformVariant_TranslateY { AzStyleTransformTag tag; AzPixelValue payload; };
typedef struct AzStyleTransformVariant_TranslateY AzStyleTransformVariant_TranslateY;
struct AzStyleTransformVariant_TranslateZ { AzStyleTransformTag tag; AzPixelValue payload; };
typedef struct AzStyleTransformVariant_TranslateZ AzStyleTransformVariant_TranslateZ;
struct AzStyleTransformVariant_Rotate { AzStyleTransformTag tag; AzAngleValue payload; };
typedef struct AzStyleTransformVariant_Rotate AzStyleTransformVariant_Rotate;
struct AzStyleTransformVariant_Rotate3D { AzStyleTransformTag tag; AzStyleTransformRotate3D payload; };
typedef struct AzStyleTransformVariant_Rotate3D AzStyleTransformVariant_Rotate3D;
struct AzStyleTransformVariant_RotateX { AzStyleTransformTag tag; AzAngleValue payload; };
typedef struct AzStyleTransformVariant_RotateX AzStyleTransformVariant_RotateX;
struct AzStyleTransformVariant_RotateY { AzStyleTransformTag tag; AzAngleValue payload; };
typedef struct AzStyleTransformVariant_RotateY AzStyleTransformVariant_RotateY;
struct AzStyleTransformVariant_RotateZ { AzStyleTransformTag tag; AzAngleValue payload; };
typedef struct AzStyleTransformVariant_RotateZ AzStyleTransformVariant_RotateZ;
struct AzStyleTransformVariant_Scale { AzStyleTransformTag tag; AzStyleTransformScale2D payload; };
typedef struct AzStyleTransformVariant_Scale AzStyleTransformVariant_Scale;
struct AzStyleTransformVariant_Scale3D { AzStyleTransformTag tag; AzStyleTransformScale3D payload; };
typedef struct AzStyleTransformVariant_Scale3D AzStyleTransformVariant_Scale3D;
struct AzStyleTransformVariant_ScaleX { AzStyleTransformTag tag; AzPercentageValue payload; };
typedef struct AzStyleTransformVariant_ScaleX AzStyleTransformVariant_ScaleX;
struct AzStyleTransformVariant_ScaleY { AzStyleTransformTag tag; AzPercentageValue payload; };
typedef struct AzStyleTransformVariant_ScaleY AzStyleTransformVariant_ScaleY;
struct AzStyleTransformVariant_ScaleZ { AzStyleTransformTag tag; AzPercentageValue payload; };
typedef struct AzStyleTransformVariant_ScaleZ AzStyleTransformVariant_ScaleZ;
struct AzStyleTransformVariant_Skew { AzStyleTransformTag tag; AzStyleTransformSkew2D payload; };
typedef struct AzStyleTransformVariant_Skew AzStyleTransformVariant_Skew;
struct AzStyleTransformVariant_SkewX { AzStyleTransformTag tag; AzPercentageValue payload; };
typedef struct AzStyleTransformVariant_SkewX AzStyleTransformVariant_SkewX;
struct AzStyleTransformVariant_SkewY { AzStyleTransformTag tag; AzPercentageValue payload; };
typedef struct AzStyleTransformVariant_SkewY AzStyleTransformVariant_SkewY;
struct AzStyleTransformVariant_Perspective { AzStyleTransformTag tag; AzPixelValue payload; };
typedef struct AzStyleTransformVariant_Perspective AzStyleTransformVariant_Perspective;
union AzStyleTransform {
    AzStyleTransformVariant_Matrix Matrix;
    AzStyleTransformVariant_Matrix3D Matrix3D;
    AzStyleTransformVariant_Translate Translate;
    AzStyleTransformVariant_Translate3D Translate3D;
    AzStyleTransformVariant_TranslateX TranslateX;
    AzStyleTransformVariant_TranslateY TranslateY;
    AzStyleTransformVariant_TranslateZ TranslateZ;
    AzStyleTransformVariant_Rotate Rotate;
    AzStyleTransformVariant_Rotate3D Rotate3D;
    AzStyleTransformVariant_RotateX RotateX;
    AzStyleTransformVariant_RotateY RotateY;
    AzStyleTransformVariant_RotateZ RotateZ;
    AzStyleTransformVariant_Scale Scale;
    AzStyleTransformVariant_Scale3D Scale3D;
    AzStyleTransformVariant_ScaleX ScaleX;
    AzStyleTransformVariant_ScaleY ScaleY;
    AzStyleTransformVariant_ScaleZ ScaleZ;
    AzStyleTransformVariant_Skew Skew;
    AzStyleTransformVariant_SkewX SkewX;
    AzStyleTransformVariant_SkewY SkewY;
    AzStyleTransformVariant_Perspective Perspective;
};
typedef union AzStyleTransform AzStyleTransform;

enum AzStyleBackgroundPositionVecValueTag {
   AzStyleBackgroundPositionVecValueTag_Auto,
   AzStyleBackgroundPositionVecValueTag_None,
   AzStyleBackgroundPositionVecValueTag_Inherit,
   AzStyleBackgroundPositionVecValueTag_Initial,
   AzStyleBackgroundPositionVecValueTag_Exact,
};
typedef enum AzStyleBackgroundPositionVecValueTag AzStyleBackgroundPositionVecValueTag;

struct AzStyleBackgroundPositionVecValueVariant_Auto { AzStyleBackgroundPositionVecValueTag tag; };
typedef struct AzStyleBackgroundPositionVecValueVariant_Auto AzStyleBackgroundPositionVecValueVariant_Auto;
struct AzStyleBackgroundPositionVecValueVariant_None { AzStyleBackgroundPositionVecValueTag tag; };
typedef struct AzStyleBackgroundPositionVecValueVariant_None AzStyleBackgroundPositionVecValueVariant_None;
struct AzStyleBackgroundPositionVecValueVariant_Inherit { AzStyleBackgroundPositionVecValueTag tag; };
typedef struct AzStyleBackgroundPositionVecValueVariant_Inherit AzStyleBackgroundPositionVecValueVariant_Inherit;
struct AzStyleBackgroundPositionVecValueVariant_Initial { AzStyleBackgroundPositionVecValueTag tag; };
typedef struct AzStyleBackgroundPositionVecValueVariant_Initial AzStyleBackgroundPositionVecValueVariant_Initial;
struct AzStyleBackgroundPositionVecValueVariant_Exact { AzStyleBackgroundPositionVecValueTag tag; AzStyleBackgroundPositionVec payload; };
typedef struct AzStyleBackgroundPositionVecValueVariant_Exact AzStyleBackgroundPositionVecValueVariant_Exact;
union AzStyleBackgroundPositionVecValue {
    AzStyleBackgroundPositionVecValueVariant_Auto Auto;
    AzStyleBackgroundPositionVecValueVariant_None None;
    AzStyleBackgroundPositionVecValueVariant_Inherit Inherit;
    AzStyleBackgroundPositionVecValueVariant_Initial Initial;
    AzStyleBackgroundPositionVecValueVariant_Exact Exact;
};
typedef union AzStyleBackgroundPositionVecValue AzStyleBackgroundPositionVecValue;

enum AzStyleBackgroundRepeatVecValueTag {
   AzStyleBackgroundRepeatVecValueTag_Auto,
   AzStyleBackgroundRepeatVecValueTag_None,
   AzStyleBackgroundRepeatVecValueTag_Inherit,
   AzStyleBackgroundRepeatVecValueTag_Initial,
   AzStyleBackgroundRepeatVecValueTag_Exact,
};
typedef enum AzStyleBackgroundRepeatVecValueTag AzStyleBackgroundRepeatVecValueTag;

struct AzStyleBackgroundRepeatVecValueVariant_Auto { AzStyleBackgroundRepeatVecValueTag tag; };
typedef struct AzStyleBackgroundRepeatVecValueVariant_Auto AzStyleBackgroundRepeatVecValueVariant_Auto;
struct AzStyleBackgroundRepeatVecValueVariant_None { AzStyleBackgroundRepeatVecValueTag tag; };
typedef struct AzStyleBackgroundRepeatVecValueVariant_None AzStyleBackgroundRepeatVecValueVariant_None;
struct AzStyleBackgroundRepeatVecValueVariant_Inherit { AzStyleBackgroundRepeatVecValueTag tag; };
typedef struct AzStyleBackgroundRepeatVecValueVariant_Inherit AzStyleBackgroundRepeatVecValueVariant_Inherit;
struct AzStyleBackgroundRepeatVecValueVariant_Initial { AzStyleBackgroundRepeatVecValueTag tag; };
typedef struct AzStyleBackgroundRepeatVecValueVariant_Initial AzStyleBackgroundRepeatVecValueVariant_Initial;
struct AzStyleBackgroundRepeatVecValueVariant_Exact { AzStyleBackgroundRepeatVecValueTag tag; AzStyleBackgroundRepeatVec payload; };
typedef struct AzStyleBackgroundRepeatVecValueVariant_Exact AzStyleBackgroundRepeatVecValueVariant_Exact;
union AzStyleBackgroundRepeatVecValue {
    AzStyleBackgroundRepeatVecValueVariant_Auto Auto;
    AzStyleBackgroundRepeatVecValueVariant_None None;
    AzStyleBackgroundRepeatVecValueVariant_Inherit Inherit;
    AzStyleBackgroundRepeatVecValueVariant_Initial Initial;
    AzStyleBackgroundRepeatVecValueVariant_Exact Exact;
};
typedef union AzStyleBackgroundRepeatVecValue AzStyleBackgroundRepeatVecValue;

enum AzStyleBackgroundSizeVecValueTag {
   AzStyleBackgroundSizeVecValueTag_Auto,
   AzStyleBackgroundSizeVecValueTag_None,
   AzStyleBackgroundSizeVecValueTag_Inherit,
   AzStyleBackgroundSizeVecValueTag_Initial,
   AzStyleBackgroundSizeVecValueTag_Exact,
};
typedef enum AzStyleBackgroundSizeVecValueTag AzStyleBackgroundSizeVecValueTag;

struct AzStyleBackgroundSizeVecValueVariant_Auto { AzStyleBackgroundSizeVecValueTag tag; };
typedef struct AzStyleBackgroundSizeVecValueVariant_Auto AzStyleBackgroundSizeVecValueVariant_Auto;
struct AzStyleBackgroundSizeVecValueVariant_None { AzStyleBackgroundSizeVecValueTag tag; };
typedef struct AzStyleBackgroundSizeVecValueVariant_None AzStyleBackgroundSizeVecValueVariant_None;
struct AzStyleBackgroundSizeVecValueVariant_Inherit { AzStyleBackgroundSizeVecValueTag tag; };
typedef struct AzStyleBackgroundSizeVecValueVariant_Inherit AzStyleBackgroundSizeVecValueVariant_Inherit;
struct AzStyleBackgroundSizeVecValueVariant_Initial { AzStyleBackgroundSizeVecValueTag tag; };
typedef struct AzStyleBackgroundSizeVecValueVariant_Initial AzStyleBackgroundSizeVecValueVariant_Initial;
struct AzStyleBackgroundSizeVecValueVariant_Exact { AzStyleBackgroundSizeVecValueTag tag; AzStyleBackgroundSizeVec payload; };
typedef struct AzStyleBackgroundSizeVecValueVariant_Exact AzStyleBackgroundSizeVecValueVariant_Exact;
union AzStyleBackgroundSizeVecValue {
    AzStyleBackgroundSizeVecValueVariant_Auto Auto;
    AzStyleBackgroundSizeVecValueVariant_None None;
    AzStyleBackgroundSizeVecValueVariant_Inherit Inherit;
    AzStyleBackgroundSizeVecValueVariant_Initial Initial;
    AzStyleBackgroundSizeVecValueVariant_Exact Exact;
};
typedef union AzStyleBackgroundSizeVecValue AzStyleBackgroundSizeVecValue;

struct AzCheckBoxStateWrapper {
    AzCheckBoxState inner;
    AzOptionCheckBoxOnToggle on_toggle;
};
typedef struct AzCheckBoxStateWrapper AzCheckBoxStateWrapper;

struct AzNumberInputStateWrapper {
    AzNumberInputState inner;
    AzOptionNumberInputOnValueChange on_value_change;
};
typedef struct AzNumberInputStateWrapper AzNumberInputStateWrapper;

struct AzStyledNode {
    AzStyledNodeState state;
    AzOptionTagId tag_id;
};
typedef struct AzStyledNode AzStyledNode;

struct AzTagIdToNodeIdMapping {
    AzTagId tag_id;
    AzNodeId node_id;
    AzOptionTabIndex tab_index;
    AzNodeIdVec parents;
};
typedef struct AzTagIdToNodeIdMapping AzTagIdToNodeIdMapping;

struct AzTexture {
    uint32_t texture_id;
    AzRawImageFormat format;
    AzTextureFlags flags;
    AzPhysicalSizeU32 size;
    AzGl gl_context;
};
typedef struct AzTexture AzTexture;

struct AzGetProgramBinaryReturn {
    AzU8Vec _0;
    uint32_t _1;
};
typedef struct AzGetProgramBinaryReturn AzGetProgramBinaryReturn;

enum AzRawImageDataTag {
   AzRawImageDataTag_U8,
   AzRawImageDataTag_U16,
   AzRawImageDataTag_F32,
};
typedef enum AzRawImageDataTag AzRawImageDataTag;

struct AzRawImageDataVariant_U8 { AzRawImageDataTag tag; AzU8Vec payload; };
typedef struct AzRawImageDataVariant_U8 AzRawImageDataVariant_U8;
struct AzRawImageDataVariant_U16 { AzRawImageDataTag tag; AzU16Vec payload; };
typedef struct AzRawImageDataVariant_U16 AzRawImageDataVariant_U16;
struct AzRawImageDataVariant_F32 { AzRawImageDataTag tag; AzF32Vec payload; };
typedef struct AzRawImageDataVariant_F32 AzRawImageDataVariant_F32;
union AzRawImageData {
    AzRawImageDataVariant_U8 U8;
    AzRawImageDataVariant_U16 U16;
    AzRawImageDataVariant_F32 F32;
};
typedef union AzRawImageData AzRawImageData;

struct AzFontSource {
    AzU8Vec data;
    uint32_t font_index;
    bool  parse_glyph_outlines;
};
typedef struct AzFontSource AzFontSource;

enum AzSvgPathElementTag {
   AzSvgPathElementTag_Line,
   AzSvgPathElementTag_QuadraticCurve,
   AzSvgPathElementTag_CubicCurve,
};
typedef enum AzSvgPathElementTag AzSvgPathElementTag;

struct AzSvgPathElementVariant_Line { AzSvgPathElementTag tag; AzSvgLine payload; };
typedef struct AzSvgPathElementVariant_Line AzSvgPathElementVariant_Line;
struct AzSvgPathElementVariant_QuadraticCurve { AzSvgPathElementTag tag; AzSvgQuadraticCurve payload; };
typedef struct AzSvgPathElementVariant_QuadraticCurve AzSvgPathElementVariant_QuadraticCurve;
struct AzSvgPathElementVariant_CubicCurve { AzSvgPathElementTag tag; AzSvgCubicCurve payload; };
typedef struct AzSvgPathElementVariant_CubicCurve AzSvgPathElementVariant_CubicCurve;
union AzSvgPathElement {
    AzSvgPathElementVariant_Line Line;
    AzSvgPathElementVariant_QuadraticCurve QuadraticCurve;
    AzSvgPathElementVariant_CubicCurve CubicCurve;
};
typedef union AzSvgPathElement AzSvgPathElement;

struct AzTessellatedSvgNode {
    AzSvgVertexVec vertices;
    AzU32Vec indices;
};
typedef struct AzTessellatedSvgNode AzTessellatedSvgNode;

struct AzTessellatedSvgNodeVecRef {
    AzTessellatedSvgNode* ptr;
    size_t len;
};
typedef struct AzTessellatedSvgNodeVecRef AzTessellatedSvgNodeVecRef;

struct AzSvgRenderOptions {
    AzOptionLayoutSize target_size;
    AzOptionColorU background_color;
    AzSvgFitTo fit;
};
typedef struct AzSvgRenderOptions AzSvgRenderOptions;

struct AzSvgStrokeStyle {
    AzSvgLineCap start_cap;
    AzSvgLineCap end_cap;
    AzSvgLineJoin line_join;
    AzOptionSvgDashPattern dash_pattern;
    float line_width;
    float miter_limit;
    float tolerance;
    bool  apply_line_width;
    AzSvgTransform transform;
    bool  anti_alias;
    bool  high_quality_aa;
};
typedef struct AzSvgStrokeStyle AzSvgStrokeStyle;

struct AzXml {
    AzXmlNodeVec root;
};
typedef struct AzXml AzXml;

enum AzInstantTag {
   AzInstantTag_System,
   AzInstantTag_Tick,
};
typedef enum AzInstantTag AzInstantTag;

struct AzInstantVariant_System { AzInstantTag tag; AzInstantPtr payload; };
typedef struct AzInstantVariant_System AzInstantVariant_System;
struct AzInstantVariant_Tick { AzInstantTag tag; AzSystemTick payload; };
typedef struct AzInstantVariant_Tick AzInstantVariant_Tick;
union AzInstant {
    AzInstantVariant_System System;
    AzInstantVariant_Tick Tick;
};
typedef union AzInstant AzInstant;

enum AzThreadReceiveMsgTag {
   AzThreadReceiveMsgTag_WriteBack,
   AzThreadReceiveMsgTag_Update,
};
typedef enum AzThreadReceiveMsgTag AzThreadReceiveMsgTag;

struct AzThreadReceiveMsgVariant_WriteBack { AzThreadReceiveMsgTag tag; AzThreadWriteBackMsg payload; };
typedef struct AzThreadReceiveMsgVariant_WriteBack AzThreadReceiveMsgVariant_WriteBack;
struct AzThreadReceiveMsgVariant_Update { AzThreadReceiveMsgTag tag; AzUpdate payload; };
typedef struct AzThreadReceiveMsgVariant_Update AzThreadReceiveMsgVariant_Update;
union AzThreadReceiveMsg {
    AzThreadReceiveMsgVariant_WriteBack WriteBack;
    AzThreadReceiveMsgVariant_Update Update;
};
typedef union AzThreadReceiveMsg AzThreadReceiveMsg;

struct AzString {
    AzU8Vec vec;
};
typedef struct AzString AzString;

struct AzTessellatedSvgNodeVec {
    AzTessellatedSvgNode* ptr;
    size_t len;
    size_t cap;
    AzTessellatedSvgNodeVecDestructor destructor;
};
typedef struct AzTessellatedSvgNodeVec AzTessellatedSvgNodeVec;

struct AzStyleTransformVec {
    AzStyleTransform* ptr;
    size_t len;
    size_t cap;
    AzStyleTransformVecDestructor destructor;
};
typedef struct AzStyleTransformVec AzStyleTransformVec;

struct AzSvgPathElementVec {
    AzSvgPathElement* ptr;
    size_t len;
    size_t cap;
    AzSvgPathElementVecDestructor destructor;
};
typedef struct AzSvgPathElementVec AzSvgPathElementVec;

struct AzStringVec {
    AzString* ptr;
    size_t len;
    size_t cap;
    AzStringVecDestructor destructor;
};
typedef struct AzStringVec AzStringVec;

struct AzStyledNodeVec {
    AzStyledNode* ptr;
    size_t len;
    size_t cap;
    AzStyledNodeVecDestructor destructor;
};
typedef struct AzStyledNodeVec AzStyledNodeVec;

struct AzTagIdToNodeIdMappingVec {
    AzTagIdToNodeIdMapping* ptr;
    size_t len;
    size_t cap;
    AzTagIdToNodeIdMappingVecDestructor destructor;
};
typedef struct AzTagIdToNodeIdMappingVec AzTagIdToNodeIdMappingVec;

enum AzOptionVirtualKeyCodeComboTag {
   AzOptionVirtualKeyCodeComboTag_None,
   AzOptionVirtualKeyCodeComboTag_Some,
};
typedef enum AzOptionVirtualKeyCodeComboTag AzOptionVirtualKeyCodeComboTag;

struct AzOptionVirtualKeyCodeComboVariant_None { AzOptionVirtualKeyCodeComboTag tag; };
typedef struct AzOptionVirtualKeyCodeComboVariant_None AzOptionVirtualKeyCodeComboVariant_None;
struct AzOptionVirtualKeyCodeComboVariant_Some { AzOptionVirtualKeyCodeComboTag tag; AzVirtualKeyCodeCombo payload; };
typedef struct AzOptionVirtualKeyCodeComboVariant_Some AzOptionVirtualKeyCodeComboVariant_Some;
union AzOptionVirtualKeyCodeCombo {
    AzOptionVirtualKeyCodeComboVariant_None None;
    AzOptionVirtualKeyCodeComboVariant_Some Some;
};
typedef union AzOptionVirtualKeyCodeCombo AzOptionVirtualKeyCodeCombo;

enum AzOptionMouseStateTag {
   AzOptionMouseStateTag_None,
   AzOptionMouseStateTag_Some,
};
typedef enum AzOptionMouseStateTag AzOptionMouseStateTag;

struct AzOptionMouseStateVariant_None { AzOptionMouseStateTag tag; };
typedef struct AzOptionMouseStateVariant_None AzOptionMouseStateVariant_None;
struct AzOptionMouseStateVariant_Some { AzOptionMouseStateTag tag; AzMouseState payload; };
typedef struct AzOptionMouseStateVariant_Some AzOptionMouseStateVariant_Some;
union AzOptionMouseState {
    AzOptionMouseStateVariant_None None;
    AzOptionMouseStateVariant_Some Some;
};
typedef union AzOptionMouseState AzOptionMouseState;

enum AzOptionKeyboardStateTag {
   AzOptionKeyboardStateTag_None,
   AzOptionKeyboardStateTag_Some,
};
typedef enum AzOptionKeyboardStateTag AzOptionKeyboardStateTag;

struct AzOptionKeyboardStateVariant_None { AzOptionKeyboardStateTag tag; };
typedef struct AzOptionKeyboardStateVariant_None AzOptionKeyboardStateVariant_None;
struct AzOptionKeyboardStateVariant_Some { AzOptionKeyboardStateTag tag; AzKeyboardState payload; };
typedef struct AzOptionKeyboardStateVariant_Some AzOptionKeyboardStateVariant_Some;
union AzOptionKeyboardState {
    AzOptionKeyboardStateVariant_None None;
    AzOptionKeyboardStateVariant_Some Some;
};
typedef union AzOptionKeyboardState AzOptionKeyboardState;

enum AzOptionStringVecTag {
   AzOptionStringVecTag_None,
   AzOptionStringVecTag_Some,
};
typedef enum AzOptionStringVecTag AzOptionStringVecTag;

struct AzOptionStringVecVariant_None { AzOptionStringVecTag tag; };
typedef struct AzOptionStringVecVariant_None AzOptionStringVecVariant_None;
struct AzOptionStringVecVariant_Some { AzOptionStringVecTag tag; AzStringVec payload; };
typedef struct AzOptionStringVecVariant_Some AzOptionStringVecVariant_Some;
union AzOptionStringVec {
    AzOptionStringVecVariant_None None;
    AzOptionStringVecVariant_Some Some;
};
typedef union AzOptionStringVec AzOptionStringVec;

enum AzOptionThreadReceiveMsgTag {
   AzOptionThreadReceiveMsgTag_None,
   AzOptionThreadReceiveMsgTag_Some,
};
typedef enum AzOptionThreadReceiveMsgTag AzOptionThreadReceiveMsgTag;

struct AzOptionThreadReceiveMsgVariant_None { AzOptionThreadReceiveMsgTag tag; };
typedef struct AzOptionThreadReceiveMsgVariant_None AzOptionThreadReceiveMsgVariant_None;
struct AzOptionThreadReceiveMsgVariant_Some { AzOptionThreadReceiveMsgTag tag; AzThreadReceiveMsg payload; };
typedef struct AzOptionThreadReceiveMsgVariant_Some AzOptionThreadReceiveMsgVariant_Some;
union AzOptionThreadReceiveMsg {
    AzOptionThreadReceiveMsgVariant_None None;
    AzOptionThreadReceiveMsgVariant_Some Some;
};
typedef union AzOptionThreadReceiveMsg AzOptionThreadReceiveMsg;

enum AzOptionTaskBarIconTag {
   AzOptionTaskBarIconTag_None,
   AzOptionTaskBarIconTag_Some,
};
typedef enum AzOptionTaskBarIconTag AzOptionTaskBarIconTag;

struct AzOptionTaskBarIconVariant_None { AzOptionTaskBarIconTag tag; };
typedef struct AzOptionTaskBarIconVariant_None AzOptionTaskBarIconVariant_None;
struct AzOptionTaskBarIconVariant_Some { AzOptionTaskBarIconTag tag; AzTaskBarIcon payload; };
typedef struct AzOptionTaskBarIconVariant_Some AzOptionTaskBarIconVariant_Some;
union AzOptionTaskBarIcon {
    AzOptionTaskBarIconVariant_None None;
    AzOptionTaskBarIconVariant_Some Some;
};
typedef union AzOptionTaskBarIcon AzOptionTaskBarIcon;

enum AzOptionWindowIconTag {
   AzOptionWindowIconTag_None,
   AzOptionWindowIconTag_Some,
};
typedef enum AzOptionWindowIconTag AzOptionWindowIconTag;

struct AzOptionWindowIconVariant_None { AzOptionWindowIconTag tag; };
typedef struct AzOptionWindowIconVariant_None AzOptionWindowIconVariant_None;
struct AzOptionWindowIconVariant_Some { AzOptionWindowIconTag tag; AzWindowIcon payload; };
typedef struct AzOptionWindowIconVariant_Some AzOptionWindowIconVariant_Some;
union AzOptionWindowIcon {
    AzOptionWindowIconVariant_None None;
    AzOptionWindowIconVariant_Some Some;
};
typedef union AzOptionWindowIcon AzOptionWindowIcon;

enum AzOptionStringTag {
   AzOptionStringTag_None,
   AzOptionStringTag_Some,
};
typedef enum AzOptionStringTag AzOptionStringTag;

struct AzOptionStringVariant_None { AzOptionStringTag tag; };
typedef struct AzOptionStringVariant_None AzOptionStringVariant_None;
struct AzOptionStringVariant_Some { AzOptionStringTag tag; AzString payload; };
typedef struct AzOptionStringVariant_Some AzOptionStringVariant_Some;
union AzOptionString {
    AzOptionStringVariant_None None;
    AzOptionStringVariant_Some Some;
};
typedef union AzOptionString AzOptionString;

enum AzOptionTextureTag {
   AzOptionTextureTag_None,
   AzOptionTextureTag_Some,
};
typedef enum AzOptionTextureTag AzOptionTextureTag;

struct AzOptionTextureVariant_None { AzOptionTextureTag tag; };
typedef struct AzOptionTextureVariant_None AzOptionTextureVariant_None;
struct AzOptionTextureVariant_Some { AzOptionTextureTag tag; AzTexture payload; };
typedef struct AzOptionTextureVariant_Some AzOptionTextureVariant_Some;
union AzOptionTexture {
    AzOptionTextureVariant_None None;
    AzOptionTextureVariant_Some Some;
};
typedef union AzOptionTexture AzOptionTexture;

enum AzOptionInstantTag {
   AzOptionInstantTag_None,
   AzOptionInstantTag_Some,
};
typedef enum AzOptionInstantTag AzOptionInstantTag;

struct AzOptionInstantVariant_None { AzOptionInstantTag tag; };
typedef struct AzOptionInstantVariant_None AzOptionInstantVariant_None;
struct AzOptionInstantVariant_Some { AzOptionInstantTag tag; AzInstant payload; };
typedef struct AzOptionInstantVariant_Some AzOptionInstantVariant_Some;
union AzOptionInstant {
    AzOptionInstantVariant_None None;
    AzOptionInstantVariant_Some Some;
};
typedef union AzOptionInstant AzOptionInstant;

struct AzDuplicatedNamespaceError {
    AzString ns;
    AzSvgParseErrorPosition pos;
};
typedef struct AzDuplicatedNamespaceError AzDuplicatedNamespaceError;

struct AzUnknownNamespaceError {
    AzString ns;
    AzSvgParseErrorPosition pos;
};
typedef struct AzUnknownNamespaceError AzUnknownNamespaceError;

struct AzUnexpectedCloseTagError {
    AzString expected;
    AzString actual;
    AzSvgParseErrorPosition pos;
};
typedef struct AzUnexpectedCloseTagError AzUnexpectedCloseTagError;

struct AzUnknownEntityReferenceError {
    AzString entity;
    AzSvgParseErrorPosition pos;
};
typedef struct AzUnknownEntityReferenceError AzUnknownEntityReferenceError;

struct AzDuplicatedAttributeError {
    AzString attribute;
    AzSvgParseErrorPosition pos;
};
typedef struct AzDuplicatedAttributeError AzDuplicatedAttributeError;

struct AzInvalidStringError {
    AzString got;
    AzSvgParseErrorPosition pos;
};
typedef struct AzInvalidStringError AzInvalidStringError;

struct AzWindowsWindowOptions {
    bool  allow_drag_drop;
    bool  no_redirection_bitmap;
    AzOptionWindowIcon window_icon;
    AzOptionTaskBarIcon taskbar_icon;
    AzOptionHwndHandle parent_window;
};
typedef struct AzWindowsWindowOptions AzWindowsWindowOptions;

struct AzWaylandTheme {
    uint8_t title_bar_active_background_color[4];
    uint8_t title_bar_active_separator_color[4];
    uint8_t title_bar_active_text_color[4];
    uint8_t title_bar_inactive_background_color[4];
    uint8_t title_bar_inactive_separator_color[4];
    uint8_t title_bar_inactive_text_color[4];
    uint8_t maximize_idle_foreground_inactive_color[4];
    uint8_t minimize_idle_foreground_inactive_color[4];
    uint8_t close_idle_foreground_inactive_color[4];
    uint8_t maximize_hovered_foreground_inactive_color[4];
    uint8_t minimize_hovered_foreground_inactive_color[4];
    uint8_t close_hovered_foreground_inactive_color[4];
    uint8_t maximize_disabled_foreground_inactive_color[4];
    uint8_t minimize_disabled_foreground_inactive_color[4];
    uint8_t close_disabled_foreground_inactive_color[4];
    uint8_t maximize_idle_background_inactive_color[4];
    uint8_t minimize_idle_background_inactive_color[4];
    uint8_t close_idle_background_inactive_color[4];
    uint8_t maximize_hovered_background_inactive_color[4];
    uint8_t minimize_hovered_background_inactive_color[4];
    uint8_t close_hovered_background_inactive_color[4];
    uint8_t maximize_disabled_background_inactive_color[4];
    uint8_t minimize_disabled_background_inactive_color[4];
    uint8_t close_disabled_background_inactive_color[4];
    uint8_t maximize_idle_foreground_active_color[4];
    uint8_t minimize_idle_foreground_active_color[4];
    uint8_t close_idle_foreground_active_color[4];
    uint8_t maximize_hovered_foreground_active_color[4];
    uint8_t minimize_hovered_foreground_active_color[4];
    uint8_t close_hovered_foreground_active_color[4];
    uint8_t maximize_disabled_foreground_active_color[4];
    uint8_t minimize_disabled_foreground_active_color[4];
    uint8_t close_disabled_foreground_active_color[4];
    uint8_t maximize_idle_background_active_color[4];
    uint8_t minimize_idle_background_active_color[4];
    uint8_t close_idle_background_active_color[4];
    uint8_t maximize_hovered_background_active_color[4];
    uint8_t minimize_hovered_background_active_color[4];
    uint8_t close_hovered_background_active_color[4];
    uint8_t maximize_disabled_background_active_color[4];
    uint8_t minimize_disabled_background_active_color[4];
    uint8_t close_disabled_background_active_color[4];
    AzString title_bar_font;
    float title_bar_font_size;
};
typedef struct AzWaylandTheme AzWaylandTheme;

struct AzStringPair {
    AzString key;
    AzString value;
};
typedef struct AzStringPair AzStringPair;

struct AzMonitor {
    size_t id;
    AzOptionString name;
    AzLayoutSize size;
    AzLayoutPoint position;
    double scale_factor;
    AzVideoModeVec video_modes;
    bool  is_primary_monitor;
};
typedef struct AzMonitor AzMonitor;

enum AzLayoutCallbackTag {
   AzLayoutCallbackTag_Raw,
   AzLayoutCallbackTag_Marshaled,
};
typedef enum AzLayoutCallbackTag AzLayoutCallbackTag;

struct AzLayoutCallbackVariant_Raw { AzLayoutCallbackTag tag; AzLayoutCallbackInner payload; };
typedef struct AzLayoutCallbackVariant_Raw AzLayoutCallbackVariant_Raw;
struct AzLayoutCallbackVariant_Marshaled { AzLayoutCallbackTag tag; AzMarshaledLayoutCallback payload; };
typedef struct AzLayoutCallbackVariant_Marshaled AzLayoutCallbackVariant_Marshaled;
union AzLayoutCallback {
    AzLayoutCallbackVariant_Raw Raw;
    AzLayoutCallbackVariant_Marshaled Marshaled;
};
typedef union AzLayoutCallback AzLayoutCallback;

enum AzInlineWordTag {
   AzInlineWordTag_Tab,
   AzInlineWordTag_Return,
   AzInlineWordTag_Space,
   AzInlineWordTag_Word,
};
typedef enum AzInlineWordTag AzInlineWordTag;

struct AzInlineWordVariant_Tab { AzInlineWordTag tag; };
typedef struct AzInlineWordVariant_Tab AzInlineWordVariant_Tab;
struct AzInlineWordVariant_Return { AzInlineWordTag tag; };
typedef struct AzInlineWordVariant_Return AzInlineWordVariant_Return;
struct AzInlineWordVariant_Space { AzInlineWordTag tag; };
typedef struct AzInlineWordVariant_Space AzInlineWordVariant_Space;
struct AzInlineWordVariant_Word { AzInlineWordTag tag; AzInlineTextContents payload; };
typedef struct AzInlineWordVariant_Word AzInlineWordVariant_Word;
union AzInlineWord {
    AzInlineWordVariant_Tab Tab;
    AzInlineWordVariant_Return Return;
    AzInlineWordVariant_Space Space;
    AzInlineWordVariant_Word Word;
};
typedef union AzInlineWord AzInlineWord;

struct AzCallbackData {
    AzEventFilter event;
    AzCallback callback;
    AzRefAny data;
};
typedef struct AzCallbackData AzCallbackData;

enum AzNodeTypeTag {
   AzNodeTypeTag_Body,
   AzNodeTypeTag_Div,
   AzNodeTypeTag_Br,
   AzNodeTypeTag_Text,
   AzNodeTypeTag_Image,
   AzNodeTypeTag_IFrame,
};
typedef enum AzNodeTypeTag AzNodeTypeTag;

struct AzNodeTypeVariant_Body { AzNodeTypeTag tag; };
typedef struct AzNodeTypeVariant_Body AzNodeTypeVariant_Body;
struct AzNodeTypeVariant_Div { AzNodeTypeTag tag; };
typedef struct AzNodeTypeVariant_Div AzNodeTypeVariant_Div;
struct AzNodeTypeVariant_Br { AzNodeTypeTag tag; };
typedef struct AzNodeTypeVariant_Br AzNodeTypeVariant_Br;
struct AzNodeTypeVariant_Text { AzNodeTypeTag tag; AzString payload; };
typedef struct AzNodeTypeVariant_Text AzNodeTypeVariant_Text;
struct AzNodeTypeVariant_Image { AzNodeTypeTag tag; AzImageRef payload; };
typedef struct AzNodeTypeVariant_Image AzNodeTypeVariant_Image;
struct AzNodeTypeVariant_IFrame { AzNodeTypeTag tag; AzIFrameNode payload; };
typedef struct AzNodeTypeVariant_IFrame AzNodeTypeVariant_IFrame;
union AzNodeType {
    AzNodeTypeVariant_Body Body;
    AzNodeTypeVariant_Div Div;
    AzNodeTypeVariant_Br Br;
    AzNodeTypeVariant_Text Text;
    AzNodeTypeVariant_Image Image;
    AzNodeTypeVariant_IFrame IFrame;
};
typedef union AzNodeType AzNodeType;

struct AzAccessibilityInfo {
    AzOptionString name;
    AzOptionString value;
    AzAccessibilityRole role;
    AzAccessibilityStateVec states;
    AzOptionVirtualKeyCodeCombo accelerator;
    AzOptionString default_action;
};
typedef struct AzAccessibilityInfo AzAccessibilityInfo;

enum AzIdOrClassTag {
   AzIdOrClassTag_Id,
   AzIdOrClassTag_Class,
};
typedef enum AzIdOrClassTag AzIdOrClassTag;

struct AzIdOrClassVariant_Id { AzIdOrClassTag tag; AzString payload; };
typedef struct AzIdOrClassVariant_Id AzIdOrClassVariant_Id;
struct AzIdOrClassVariant_Class { AzIdOrClassTag tag; AzString payload; };
typedef struct AzIdOrClassVariant_Class AzIdOrClassVariant_Class;
union AzIdOrClass {
    AzIdOrClassVariant_Id Id;
    AzIdOrClassVariant_Class Class;
};
typedef union AzIdOrClass AzIdOrClass;

struct AzStringMenuItem {
    AzString label;
    AzOptionVirtualKeyCodeCombo accelerator;
    AzOptionMenuCallback callback;
    AzMenuItemState state;
    AzOptionMenuItemIcon icon;
    AzMenuItemVec children;
};
typedef struct AzStringMenuItem AzStringMenuItem;

enum AzCssPathSelectorTag {
   AzCssPathSelectorTag_Global,
   AzCssPathSelectorTag_Type,
   AzCssPathSelectorTag_Class,
   AzCssPathSelectorTag_Id,
   AzCssPathSelectorTag_PseudoSelector,
   AzCssPathSelectorTag_DirectChildren,
   AzCssPathSelectorTag_Children,
};
typedef enum AzCssPathSelectorTag AzCssPathSelectorTag;

struct AzCssPathSelectorVariant_Global { AzCssPathSelectorTag tag; };
typedef struct AzCssPathSelectorVariant_Global AzCssPathSelectorVariant_Global;
struct AzCssPathSelectorVariant_Type { AzCssPathSelectorTag tag; AzNodeTypeKey payload; };
typedef struct AzCssPathSelectorVariant_Type AzCssPathSelectorVariant_Type;
struct AzCssPathSelectorVariant_Class { AzCssPathSelectorTag tag; AzString payload; };
typedef struct AzCssPathSelectorVariant_Class AzCssPathSelectorVariant_Class;
struct AzCssPathSelectorVariant_Id { AzCssPathSelectorTag tag; AzString payload; };
typedef struct AzCssPathSelectorVariant_Id AzCssPathSelectorVariant_Id;
struct AzCssPathSelectorVariant_PseudoSelector { AzCssPathSelectorTag tag; AzCssPathPseudoSelector payload; };
typedef struct AzCssPathSelectorVariant_PseudoSelector AzCssPathSelectorVariant_PseudoSelector;
struct AzCssPathSelectorVariant_DirectChildren { AzCssPathSelectorTag tag; };
typedef struct AzCssPathSelectorVariant_DirectChildren AzCssPathSelectorVariant_DirectChildren;
struct AzCssPathSelectorVariant_Children { AzCssPathSelectorTag tag; };
typedef struct AzCssPathSelectorVariant_Children AzCssPathSelectorVariant_Children;
union AzCssPathSelector {
    AzCssPathSelectorVariant_Global Global;
    AzCssPathSelectorVariant_Type Type;
    AzCssPathSelectorVariant_Class Class;
    AzCssPathSelectorVariant_Id Id;
    AzCssPathSelectorVariant_PseudoSelector PseudoSelector;
    AzCssPathSelectorVariant_DirectChildren DirectChildren;
    AzCssPathSelectorVariant_Children Children;
};
typedef union AzCssPathSelector AzCssPathSelector;

enum AzStyleBackgroundContentTag {
   AzStyleBackgroundContentTag_LinearGradient,
   AzStyleBackgroundContentTag_RadialGradient,
   AzStyleBackgroundContentTag_ConicGradient,
   AzStyleBackgroundContentTag_Image,
   AzStyleBackgroundContentTag_Color,
};
typedef enum AzStyleBackgroundContentTag AzStyleBackgroundContentTag;

struct AzStyleBackgroundContentVariant_LinearGradient { AzStyleBackgroundContentTag tag; AzLinearGradient payload; };
typedef struct AzStyleBackgroundContentVariant_LinearGradient AzStyleBackgroundContentVariant_LinearGradient;
struct AzStyleBackgroundContentVariant_RadialGradient { AzStyleBackgroundContentTag tag; AzRadialGradient payload; };
typedef struct AzStyleBackgroundContentVariant_RadialGradient AzStyleBackgroundContentVariant_RadialGradient;
struct AzStyleBackgroundContentVariant_ConicGradient { AzStyleBackgroundContentTag tag; AzConicGradient payload; };
typedef struct AzStyleBackgroundContentVariant_ConicGradient AzStyleBackgroundContentVariant_ConicGradient;
struct AzStyleBackgroundContentVariant_Image { AzStyleBackgroundContentTag tag; AzString payload; };
typedef struct AzStyleBackgroundContentVariant_Image AzStyleBackgroundContentVariant_Image;
struct AzStyleBackgroundContentVariant_Color { AzStyleBackgroundContentTag tag; AzColorU payload; };
typedef struct AzStyleBackgroundContentVariant_Color AzStyleBackgroundContentVariant_Color;
union AzStyleBackgroundContent {
    AzStyleBackgroundContentVariant_LinearGradient LinearGradient;
    AzStyleBackgroundContentVariant_RadialGradient RadialGradient;
    AzStyleBackgroundContentVariant_ConicGradient ConicGradient;
    AzStyleBackgroundContentVariant_Image Image;
    AzStyleBackgroundContentVariant_Color Color;
};
typedef union AzStyleBackgroundContent AzStyleBackgroundContent;

struct AzScrollbarInfo {
    AzLayoutWidth width;
    AzLayoutPaddingLeft padding_left;
    AzLayoutPaddingRight padding_right;
    AzStyleBackgroundContent track;
    AzStyleBackgroundContent thumb;
    AzStyleBackgroundContent button;
    AzStyleBackgroundContent corner;
    AzStyleBackgroundContent resizer;
};
typedef struct AzScrollbarInfo AzScrollbarInfo;

struct AzScrollbarStyle {
    AzScrollbarInfo horizontal;
    AzScrollbarInfo vertical;
};
typedef struct AzScrollbarStyle AzScrollbarStyle;

enum AzStyleFontFamilyTag {
   AzStyleFontFamilyTag_System,
   AzStyleFontFamilyTag_File,
   AzStyleFontFamilyTag_Ref,
};
typedef enum AzStyleFontFamilyTag AzStyleFontFamilyTag;

struct AzStyleFontFamilyVariant_System { AzStyleFontFamilyTag tag; AzString payload; };
typedef struct AzStyleFontFamilyVariant_System AzStyleFontFamilyVariant_System;
struct AzStyleFontFamilyVariant_File { AzStyleFontFamilyTag tag; AzString payload; };
typedef struct AzStyleFontFamilyVariant_File AzStyleFontFamilyVariant_File;
struct AzStyleFontFamilyVariant_Ref { AzStyleFontFamilyTag tag; AzFontRef payload; };
typedef struct AzStyleFontFamilyVariant_Ref AzStyleFontFamilyVariant_Ref;
union AzStyleFontFamily {
    AzStyleFontFamilyVariant_System System;
    AzStyleFontFamilyVariant_File File;
    AzStyleFontFamilyVariant_Ref Ref;
};
typedef union AzStyleFontFamily AzStyleFontFamily;

enum AzScrollbarStyleValueTag {
   AzScrollbarStyleValueTag_Auto,
   AzScrollbarStyleValueTag_None,
   AzScrollbarStyleValueTag_Inherit,
   AzScrollbarStyleValueTag_Initial,
   AzScrollbarStyleValueTag_Exact,
};
typedef enum AzScrollbarStyleValueTag AzScrollbarStyleValueTag;

struct AzScrollbarStyleValueVariant_Auto { AzScrollbarStyleValueTag tag; };
typedef struct AzScrollbarStyleValueVariant_Auto AzScrollbarStyleValueVariant_Auto;
struct AzScrollbarStyleValueVariant_None { AzScrollbarStyleValueTag tag; };
typedef struct AzScrollbarStyleValueVariant_None AzScrollbarStyleValueVariant_None;
struct AzScrollbarStyleValueVariant_Inherit { AzScrollbarStyleValueTag tag; };
typedef struct AzScrollbarStyleValueVariant_Inherit AzScrollbarStyleValueVariant_Inherit;
struct AzScrollbarStyleValueVariant_Initial { AzScrollbarStyleValueTag tag; };
typedef struct AzScrollbarStyleValueVariant_Initial AzScrollbarStyleValueVariant_Initial;
struct AzScrollbarStyleValueVariant_Exact { AzScrollbarStyleValueTag tag; AzScrollbarStyle payload; };
typedef struct AzScrollbarStyleValueVariant_Exact AzScrollbarStyleValueVariant_Exact;
union AzScrollbarStyleValue {
    AzScrollbarStyleValueVariant_Auto Auto;
    AzScrollbarStyleValueVariant_None None;
    AzScrollbarStyleValueVariant_Inherit Inherit;
    AzScrollbarStyleValueVariant_Initial Initial;
    AzScrollbarStyleValueVariant_Exact Exact;
};
typedef union AzScrollbarStyleValue AzScrollbarStyleValue;

enum AzStyleTransformVecValueTag {
   AzStyleTransformVecValueTag_Auto,
   AzStyleTransformVecValueTag_None,
   AzStyleTransformVecValueTag_Inherit,
   AzStyleTransformVecValueTag_Initial,
   AzStyleTransformVecValueTag_Exact,
};
typedef enum AzStyleTransformVecValueTag AzStyleTransformVecValueTag;

struct AzStyleTransformVecValueVariant_Auto { AzStyleTransformVecValueTag tag; };
typedef struct AzStyleTransformVecValueVariant_Auto AzStyleTransformVecValueVariant_Auto;
struct AzStyleTransformVecValueVariant_None { AzStyleTransformVecValueTag tag; };
typedef struct AzStyleTransformVecValueVariant_None AzStyleTransformVecValueVariant_None;
struct AzStyleTransformVecValueVariant_Inherit { AzStyleTransformVecValueTag tag; };
typedef struct AzStyleTransformVecValueVariant_Inherit AzStyleTransformVecValueVariant_Inherit;
struct AzStyleTransformVecValueVariant_Initial { AzStyleTransformVecValueTag tag; };
typedef struct AzStyleTransformVecValueVariant_Initial AzStyleTransformVecValueVariant_Initial;
struct AzStyleTransformVecValueVariant_Exact { AzStyleTransformVecValueTag tag; AzStyleTransformVec payload; };
typedef struct AzStyleTransformVecValueVariant_Exact AzStyleTransformVecValueVariant_Exact;
union AzStyleTransformVecValue {
    AzStyleTransformVecValueVariant_Auto Auto;
    AzStyleTransformVecValueVariant_None None;
    AzStyleTransformVecValueVariant_Inherit Inherit;
    AzStyleTransformVecValueVariant_Initial Initial;
    AzStyleTransformVecValueVariant_Exact Exact;
};
typedef union AzStyleTransformVecValue AzStyleTransformVecValue;

struct AzColorInputStateWrapper {
    AzColorInputState inner;
    AzString title;
    AzOptionColorInputOnValueChange on_value_change;
};
typedef struct AzColorInputStateWrapper AzColorInputStateWrapper;

struct AzTextInputState {
    AzU32Vec text;
    AzOptionString placeholder;
    size_t max_len;
    AzOptionTextInputSelection selection;
    size_t cursor_pos;
};
typedef struct AzTextInputState AzTextInputState;

struct AzVertexAttribute {
    AzString name;
    AzOptionUsize layout_location;
    AzVertexAttributeType attribute_type;
    size_t item_count;
};
typedef struct AzVertexAttribute AzVertexAttribute;

struct AzDebugMessage {
    AzString message;
    uint32_t source;
    uint32_t ty;
    uint32_t id;
    uint32_t severity;
};
typedef struct AzDebugMessage AzDebugMessage;

struct AzGetActiveAttribReturn {
    int32_t _0;
    uint32_t _1;
    AzString _2;
};
typedef struct AzGetActiveAttribReturn AzGetActiveAttribReturn;

struct AzGetActiveUniformReturn {
    int32_t _0;
    uint32_t _1;
    AzString _2;
};
typedef struct AzGetActiveUniformReturn AzGetActiveUniformReturn;

struct AzRawImage {
    AzRawImageData pixels;
    size_t width;
    size_t height;
    bool  alpha_premultiplied;
    AzRawImageFormat data_format;
};
typedef struct AzRawImage AzRawImage;

struct AzSvgPath {
    AzSvgPathElementVec items;
};
typedef struct AzSvgPath AzSvgPath;

struct AzSvgParseOptions {
    AzOptionString relative_image_path;
    float dpi;
    AzString default_font_family;
    float font_size;
    AzStringVec languages;
    AzShapeRendering shape_rendering;
    AzTextRendering text_rendering;
    AzImageRendering image_rendering;
    bool  keep_named_groups;
    AzFontDatabase fontdb;
};
typedef struct AzSvgParseOptions AzSvgParseOptions;

enum AzSvgStyleTag {
   AzSvgStyleTag_Fill,
   AzSvgStyleTag_Stroke,
};
typedef enum AzSvgStyleTag AzSvgStyleTag;

struct AzSvgStyleVariant_Fill { AzSvgStyleTag tag; AzSvgFillStyle payload; };
typedef struct AzSvgStyleVariant_Fill AzSvgStyleVariant_Fill;
struct AzSvgStyleVariant_Stroke { AzSvgStyleTag tag; AzSvgStrokeStyle payload; };
typedef struct AzSvgStyleVariant_Stroke AzSvgStyleVariant_Stroke;
union AzSvgStyle {
    AzSvgStyleVariant_Fill Fill;
    AzSvgStyleVariant_Stroke Stroke;
};
typedef union AzSvgStyle AzSvgStyle;

struct AzFile {
    void* ptr;
    AzString path;
};
typedef struct AzFile AzFile;

struct AzFileTypeList {
    AzStringVec document_types;
    AzString document_descriptor;
};
typedef struct AzFileTypeList AzFileTypeList;

struct AzTimer {
    AzRefAny data;
    AzOptionDomNodeId node_id;
    AzInstant created;
    AzOptionInstant last_run;
    size_t run_count;
    AzOptionDuration delay;
    AzOptionDuration interval;
    AzOptionDuration timeout;
    AzTimerCallback callback;
};
typedef struct AzTimer AzTimer;

enum AzFmtValueTag {
   AzFmtValueTag_Bool,
   AzFmtValueTag_Uchar,
   AzFmtValueTag_Schar,
   AzFmtValueTag_Ushort,
   AzFmtValueTag_Sshort,
   AzFmtValueTag_Uint,
   AzFmtValueTag_Sint,
   AzFmtValueTag_Ulong,
   AzFmtValueTag_Slong,
   AzFmtValueTag_Isize,
   AzFmtValueTag_Usize,
   AzFmtValueTag_Float,
   AzFmtValueTag_Double,
   AzFmtValueTag_Str,
   AzFmtValueTag_StrVec,
};
typedef enum AzFmtValueTag AzFmtValueTag;

struct AzFmtValueVariant_Bool { AzFmtValueTag tag; bool payload; };
typedef struct AzFmtValueVariant_Bool AzFmtValueVariant_Bool;
struct AzFmtValueVariant_Uchar { AzFmtValueTag tag; uint8_t payload; };
typedef struct AzFmtValueVariant_Uchar AzFmtValueVariant_Uchar;
struct AzFmtValueVariant_Schar { AzFmtValueTag tag; int8_t payload; };
typedef struct AzFmtValueVariant_Schar AzFmtValueVariant_Schar;
struct AzFmtValueVariant_Ushort { AzFmtValueTag tag; uint16_t payload; };
typedef struct AzFmtValueVariant_Ushort AzFmtValueVariant_Ushort;
struct AzFmtValueVariant_Sshort { AzFmtValueTag tag; int16_t payload; };
typedef struct AzFmtValueVariant_Sshort AzFmtValueVariant_Sshort;
struct AzFmtValueVariant_Uint { AzFmtValueTag tag; uint32_t payload; };
typedef struct AzFmtValueVariant_Uint AzFmtValueVariant_Uint;
struct AzFmtValueVariant_Sint { AzFmtValueTag tag; int32_t payload; };
typedef struct AzFmtValueVariant_Sint AzFmtValueVariant_Sint;
struct AzFmtValueVariant_Ulong { AzFmtValueTag tag; uint64_t payload; };
typedef struct AzFmtValueVariant_Ulong AzFmtValueVariant_Ulong;
struct AzFmtValueVariant_Slong { AzFmtValueTag tag; int64_t payload; };
typedef struct AzFmtValueVariant_Slong AzFmtValueVariant_Slong;
struct AzFmtValueVariant_Isize { AzFmtValueTag tag; ssize_t payload; };
typedef struct AzFmtValueVariant_Isize AzFmtValueVariant_Isize;
struct AzFmtValueVariant_Usize { AzFmtValueTag tag; size_t payload; };
typedef struct AzFmtValueVariant_Usize AzFmtValueVariant_Usize;
struct AzFmtValueVariant_Float { AzFmtValueTag tag; float payload; };
typedef struct AzFmtValueVariant_Float AzFmtValueVariant_Float;
struct AzFmtValueVariant_Double { AzFmtValueTag tag; double payload; };
typedef struct AzFmtValueVariant_Double AzFmtValueVariant_Double;
struct AzFmtValueVariant_Str { AzFmtValueTag tag; AzString payload; };
typedef struct AzFmtValueVariant_Str AzFmtValueVariant_Str;
struct AzFmtValueVariant_StrVec { AzFmtValueTag tag; AzStringVec payload; };
typedef struct AzFmtValueVariant_StrVec AzFmtValueVariant_StrVec;
union AzFmtValue {
    AzFmtValueVariant_Bool Bool;
    AzFmtValueVariant_Uchar Uchar;
    AzFmtValueVariant_Schar Schar;
    AzFmtValueVariant_Ushort Ushort;
    AzFmtValueVariant_Sshort Sshort;
    AzFmtValueVariant_Uint Uint;
    AzFmtValueVariant_Sint Sint;
    AzFmtValueVariant_Ulong Ulong;
    AzFmtValueVariant_Slong Slong;
    AzFmtValueVariant_Isize Isize;
    AzFmtValueVariant_Usize Usize;
    AzFmtValueVariant_Float Float;
    AzFmtValueVariant_Double Double;
    AzFmtValueVariant_Str Str;
    AzFmtValueVariant_StrVec StrVec;
};
typedef union AzFmtValue AzFmtValue;

struct AzFmtArg {
    AzString key;
    AzFmtValue value;
};
typedef struct AzFmtArg AzFmtArg;

struct AzStyleFontFamilyVec {
    AzStyleFontFamily* ptr;
    size_t len;
    size_t cap;
    AzStyleFontFamilyVecDestructor destructor;
};
typedef struct AzStyleFontFamilyVec AzStyleFontFamilyVec;

struct AzFmtArgVec {
    AzFmtArg* ptr;
    size_t len;
    size_t cap;
    AzFmtArgVecDestructor destructor;
};
typedef struct AzFmtArgVec AzFmtArgVec;

struct AzInlineWordVec {
    AzInlineWord* ptr;
    size_t len;
    size_t cap;
    AzInlineWordVecDestructor destructor;
};
typedef struct AzInlineWordVec AzInlineWordVec;

struct AzMonitorVec {
    AzMonitor* ptr;
    size_t len;
    size_t cap;
    AzMonitorVecDestructor destructor;
};
typedef struct AzMonitorVec AzMonitorVec;

struct AzIdOrClassVec {
    AzIdOrClass* ptr;
    size_t len;
    size_t cap;
    AzIdOrClassVecDestructor destructor;
};
typedef struct AzIdOrClassVec AzIdOrClassVec;

struct AzStyleBackgroundContentVec {
    AzStyleBackgroundContent* ptr;
    size_t len;
    size_t cap;
    AzStyleBackgroundContentVecDestructor destructor;
};
typedef struct AzStyleBackgroundContentVec AzStyleBackgroundContentVec;

struct AzSvgPathVec {
    AzSvgPath* ptr;
    size_t len;
    size_t cap;
    AzSvgPathVecDestructor destructor;
};
typedef struct AzSvgPathVec AzSvgPathVec;

struct AzVertexAttributeVec {
    AzVertexAttribute* ptr;
    size_t len;
    size_t cap;
    AzVertexAttributeVecDestructor destructor;
};
typedef struct AzVertexAttributeVec AzVertexAttributeVec;

struct AzCssPathSelectorVec {
    AzCssPathSelector* ptr;
    size_t len;
    size_t cap;
    AzCssPathSelectorVecDestructor destructor;
};
typedef struct AzCssPathSelectorVec AzCssPathSelectorVec;

struct AzCallbackDataVec {
    AzCallbackData* ptr;
    size_t len;
    size_t cap;
    AzCallbackDataVecDestructor destructor;
};
typedef struct AzCallbackDataVec AzCallbackDataVec;

struct AzDebugMessageVec {
    AzDebugMessage* ptr;
    size_t len;
    size_t cap;
    AzDebugMessageVecDestructor destructor;
};
typedef struct AzDebugMessageVec AzDebugMessageVec;

struct AzStringPairVec {
    AzStringPair* ptr;
    size_t len;
    size_t cap;
    AzStringPairVecDestructor destructor;
};
typedef struct AzStringPairVec AzStringPairVec;

enum AzOptionFileTypeListTag {
   AzOptionFileTypeListTag_None,
   AzOptionFileTypeListTag_Some,
};
typedef enum AzOptionFileTypeListTag AzOptionFileTypeListTag;

struct AzOptionFileTypeListVariant_None { AzOptionFileTypeListTag tag; };
typedef struct AzOptionFileTypeListVariant_None AzOptionFileTypeListVariant_None;
struct AzOptionFileTypeListVariant_Some { AzOptionFileTypeListTag tag; AzFileTypeList payload; };
typedef struct AzOptionFileTypeListVariant_Some AzOptionFileTypeListVariant_Some;
union AzOptionFileTypeList {
    AzOptionFileTypeListVariant_None None;
    AzOptionFileTypeListVariant_Some Some;
};
typedef union AzOptionFileTypeList AzOptionFileTypeList;

enum AzOptionFileTag {
   AzOptionFileTag_None,
   AzOptionFileTag_Some,
};
typedef enum AzOptionFileTag AzOptionFileTag;

struct AzOptionFileVariant_None { AzOptionFileTag tag; };
typedef struct AzOptionFileVariant_None AzOptionFileVariant_None;
struct AzOptionFileVariant_Some { AzOptionFileTag tag; AzFile payload; };
typedef struct AzOptionFileVariant_Some AzOptionFileVariant_Some;
union AzOptionFile {
    AzOptionFileVariant_None None;
    AzOptionFileVariant_Some Some;
};
typedef union AzOptionFile AzOptionFile;

enum AzOptionRawImageTag {
   AzOptionRawImageTag_None,
   AzOptionRawImageTag_Some,
};
typedef enum AzOptionRawImageTag AzOptionRawImageTag;

struct AzOptionRawImageVariant_None { AzOptionRawImageTag tag; };
typedef struct AzOptionRawImageVariant_None AzOptionRawImageVariant_None;
struct AzOptionRawImageVariant_Some { AzOptionRawImageTag tag; AzRawImage payload; };
typedef struct AzOptionRawImageVariant_Some AzOptionRawImageVariant_Some;
union AzOptionRawImage {
    AzOptionRawImageVariant_None None;
    AzOptionRawImageVariant_Some Some;
};
typedef union AzOptionRawImage AzOptionRawImage;

enum AzOptionWaylandThemeTag {
   AzOptionWaylandThemeTag_None,
   AzOptionWaylandThemeTag_Some,
};
typedef enum AzOptionWaylandThemeTag AzOptionWaylandThemeTag;

struct AzOptionWaylandThemeVariant_None { AzOptionWaylandThemeTag tag; };
typedef struct AzOptionWaylandThemeVariant_None AzOptionWaylandThemeVariant_None;
struct AzOptionWaylandThemeVariant_Some { AzOptionWaylandThemeTag tag; AzWaylandTheme payload; };
typedef struct AzOptionWaylandThemeVariant_Some AzOptionWaylandThemeVariant_Some;
union AzOptionWaylandTheme {
    AzOptionWaylandThemeVariant_None None;
    AzOptionWaylandThemeVariant_Some Some;
};
typedef union AzOptionWaylandTheme AzOptionWaylandTheme;

enum AzResultRawImageDecodeImageErrorTag {
   AzResultRawImageDecodeImageErrorTag_Ok,
   AzResultRawImageDecodeImageErrorTag_Err,
};
typedef enum AzResultRawImageDecodeImageErrorTag AzResultRawImageDecodeImageErrorTag;

struct AzResultRawImageDecodeImageErrorVariant_Ok { AzResultRawImageDecodeImageErrorTag tag; AzRawImage payload; };
typedef struct AzResultRawImageDecodeImageErrorVariant_Ok AzResultRawImageDecodeImageErrorVariant_Ok;
struct AzResultRawImageDecodeImageErrorVariant_Err { AzResultRawImageDecodeImageErrorTag tag; AzDecodeImageError payload; };
typedef struct AzResultRawImageDecodeImageErrorVariant_Err AzResultRawImageDecodeImageErrorVariant_Err;
union AzResultRawImageDecodeImageError {
    AzResultRawImageDecodeImageErrorVariant_Ok Ok;
    AzResultRawImageDecodeImageErrorVariant_Err Err;
};
typedef union AzResultRawImageDecodeImageError AzResultRawImageDecodeImageError;

enum AzXmlStreamErrorTag {
   AzXmlStreamErrorTag_UnexpectedEndOfStream,
   AzXmlStreamErrorTag_InvalidName,
   AzXmlStreamErrorTag_NonXmlChar,
   AzXmlStreamErrorTag_InvalidChar,
   AzXmlStreamErrorTag_InvalidCharMultiple,
   AzXmlStreamErrorTag_InvalidQuote,
   AzXmlStreamErrorTag_InvalidSpace,
   AzXmlStreamErrorTag_InvalidString,
   AzXmlStreamErrorTag_InvalidReference,
   AzXmlStreamErrorTag_InvalidExternalID,
   AzXmlStreamErrorTag_InvalidCommentData,
   AzXmlStreamErrorTag_InvalidCommentEnd,
   AzXmlStreamErrorTag_InvalidCharacterData,
};
typedef enum AzXmlStreamErrorTag AzXmlStreamErrorTag;

struct AzXmlStreamErrorVariant_UnexpectedEndOfStream { AzXmlStreamErrorTag tag; };
typedef struct AzXmlStreamErrorVariant_UnexpectedEndOfStream AzXmlStreamErrorVariant_UnexpectedEndOfStream;
struct AzXmlStreamErrorVariant_InvalidName { AzXmlStreamErrorTag tag; };
typedef struct AzXmlStreamErrorVariant_InvalidName AzXmlStreamErrorVariant_InvalidName;
struct AzXmlStreamErrorVariant_NonXmlChar { AzXmlStreamErrorTag tag; AzNonXmlCharError payload; };
typedef struct AzXmlStreamErrorVariant_NonXmlChar AzXmlStreamErrorVariant_NonXmlChar;
struct AzXmlStreamErrorVariant_InvalidChar { AzXmlStreamErrorTag tag; AzInvalidCharError payload; };
typedef struct AzXmlStreamErrorVariant_InvalidChar AzXmlStreamErrorVariant_InvalidChar;
struct AzXmlStreamErrorVariant_InvalidCharMultiple { AzXmlStreamErrorTag tag; AzInvalidCharMultipleError payload; };
typedef struct AzXmlStreamErrorVariant_InvalidCharMultiple AzXmlStreamErrorVariant_InvalidCharMultiple;
struct AzXmlStreamErrorVariant_InvalidQuote { AzXmlStreamErrorTag tag; AzInvalidQuoteError payload; };
typedef struct AzXmlStreamErrorVariant_InvalidQuote AzXmlStreamErrorVariant_InvalidQuote;
struct AzXmlStreamErrorVariant_InvalidSpace { AzXmlStreamErrorTag tag; AzInvalidSpaceError payload; };
typedef struct AzXmlStreamErrorVariant_InvalidSpace AzXmlStreamErrorVariant_InvalidSpace;
struct AzXmlStreamErrorVariant_InvalidString { AzXmlStreamErrorTag tag; AzInvalidStringError payload; };
typedef struct AzXmlStreamErrorVariant_InvalidString AzXmlStreamErrorVariant_InvalidString;
struct AzXmlStreamErrorVariant_InvalidReference { AzXmlStreamErrorTag tag; };
typedef struct AzXmlStreamErrorVariant_InvalidReference AzXmlStreamErrorVariant_InvalidReference;
struct AzXmlStreamErrorVariant_InvalidExternalID { AzXmlStreamErrorTag tag; };
typedef struct AzXmlStreamErrorVariant_InvalidExternalID AzXmlStreamErrorVariant_InvalidExternalID;
struct AzXmlStreamErrorVariant_InvalidCommentData { AzXmlStreamErrorTag tag; };
typedef struct AzXmlStreamErrorVariant_InvalidCommentData AzXmlStreamErrorVariant_InvalidCommentData;
struct AzXmlStreamErrorVariant_InvalidCommentEnd { AzXmlStreamErrorTag tag; };
typedef struct AzXmlStreamErrorVariant_InvalidCommentEnd AzXmlStreamErrorVariant_InvalidCommentEnd;
struct AzXmlStreamErrorVariant_InvalidCharacterData { AzXmlStreamErrorTag tag; };
typedef struct AzXmlStreamErrorVariant_InvalidCharacterData AzXmlStreamErrorVariant_InvalidCharacterData;
union AzXmlStreamError {
    AzXmlStreamErrorVariant_UnexpectedEndOfStream UnexpectedEndOfStream;
    AzXmlStreamErrorVariant_InvalidName InvalidName;
    AzXmlStreamErrorVariant_NonXmlChar NonXmlChar;
    AzXmlStreamErrorVariant_InvalidChar InvalidChar;
    AzXmlStreamErrorVariant_InvalidCharMultiple InvalidCharMultiple;
    AzXmlStreamErrorVariant_InvalidQuote InvalidQuote;
    AzXmlStreamErrorVariant_InvalidSpace InvalidSpace;
    AzXmlStreamErrorVariant_InvalidString InvalidString;
    AzXmlStreamErrorVariant_InvalidReference InvalidReference;
    AzXmlStreamErrorVariant_InvalidExternalID InvalidExternalID;
    AzXmlStreamErrorVariant_InvalidCommentData InvalidCommentData;
    AzXmlStreamErrorVariant_InvalidCommentEnd InvalidCommentEnd;
    AzXmlStreamErrorVariant_InvalidCharacterData InvalidCharacterData;
};
typedef union AzXmlStreamError AzXmlStreamError;

struct AzLinuxWindowOptions {
    AzOptionX11Visual x11_visual;
    AzOptionI32 x11_screen;
    AzStringPairVec x11_wm_classes;
    bool  x11_override_redirect;
    AzXWindowTypeVec x11_window_types;
    AzOptionString x11_gtk_theme_variant;
    AzOptionLogicalSize x11_resize_increments;
    AzOptionLogicalSize x11_base_size;
    AzOptionString wayland_app_id;
    AzOptionWaylandTheme wayland_theme;
    bool  request_user_attention;
    AzOptionWindowIcon window_icon;
};
typedef struct AzLinuxWindowOptions AzLinuxWindowOptions;

struct AzInlineLine {
    AzInlineWordVec words;
    AzLogicalRect bounds;
};
typedef struct AzInlineLine AzInlineLine;

enum AzMenuItemTag {
   AzMenuItemTag_Label,
   AzMenuItemTag_Separator,
   AzMenuItemTag_BreakLine,
};
typedef enum AzMenuItemTag AzMenuItemTag;

struct AzMenuItemVariant_Label { AzMenuItemTag tag; AzStringMenuItem payload; };
typedef struct AzMenuItemVariant_Label AzMenuItemVariant_Label;
struct AzMenuItemVariant_Separator { AzMenuItemTag tag; };
typedef struct AzMenuItemVariant_Separator AzMenuItemVariant_Separator;
struct AzMenuItemVariant_BreakLine { AzMenuItemTag tag; };
typedef struct AzMenuItemVariant_BreakLine AzMenuItemVariant_BreakLine;
union AzMenuItem {
    AzMenuItemVariant_Label Label;
    AzMenuItemVariant_Separator Separator;
    AzMenuItemVariant_BreakLine BreakLine;
};
typedef union AzMenuItem AzMenuItem;

struct AzCssPath {
    AzCssPathSelectorVec selectors;
};
typedef struct AzCssPath AzCssPath;

enum AzStyleBackgroundContentVecValueTag {
   AzStyleBackgroundContentVecValueTag_Auto,
   AzStyleBackgroundContentVecValueTag_None,
   AzStyleBackgroundContentVecValueTag_Inherit,
   AzStyleBackgroundContentVecValueTag_Initial,
   AzStyleBackgroundContentVecValueTag_Exact,
};
typedef enum AzStyleBackgroundContentVecValueTag AzStyleBackgroundContentVecValueTag;

struct AzStyleBackgroundContentVecValueVariant_Auto { AzStyleBackgroundContentVecValueTag tag; };
typedef struct AzStyleBackgroundContentVecValueVariant_Auto AzStyleBackgroundContentVecValueVariant_Auto;
struct AzStyleBackgroundContentVecValueVariant_None { AzStyleBackgroundContentVecValueTag tag; };
typedef struct AzStyleBackgroundContentVecValueVariant_None AzStyleBackgroundContentVecValueVariant_None;
struct AzStyleBackgroundContentVecValueVariant_Inherit { AzStyleBackgroundContentVecValueTag tag; };
typedef struct AzStyleBackgroundContentVecValueVariant_Inherit AzStyleBackgroundContentVecValueVariant_Inherit;
struct AzStyleBackgroundContentVecValueVariant_Initial { AzStyleBackgroundContentVecValueTag tag; };
typedef struct AzStyleBackgroundContentVecValueVariant_Initial AzStyleBackgroundContentVecValueVariant_Initial;
struct AzStyleBackgroundContentVecValueVariant_Exact { AzStyleBackgroundContentVecValueTag tag; AzStyleBackgroundContentVec payload; };
typedef struct AzStyleBackgroundContentVecValueVariant_Exact AzStyleBackgroundContentVecValueVariant_Exact;
union AzStyleBackgroundContentVecValue {
    AzStyleBackgroundContentVecValueVariant_Auto Auto;
    AzStyleBackgroundContentVecValueVariant_None None;
    AzStyleBackgroundContentVecValueVariant_Inherit Inherit;
    AzStyleBackgroundContentVecValueVariant_Initial Initial;
    AzStyleBackgroundContentVecValueVariant_Exact Exact;
};
typedef union AzStyleBackgroundContentVecValue AzStyleBackgroundContentVecValue;

enum AzStyleFontFamilyVecValueTag {
   AzStyleFontFamilyVecValueTag_Auto,
   AzStyleFontFamilyVecValueTag_None,
   AzStyleFontFamilyVecValueTag_Inherit,
   AzStyleFontFamilyVecValueTag_Initial,
   AzStyleFontFamilyVecValueTag_Exact,
};
typedef enum AzStyleFontFamilyVecValueTag AzStyleFontFamilyVecValueTag;

struct AzStyleFontFamilyVecValueVariant_Auto { AzStyleFontFamilyVecValueTag tag; };
typedef struct AzStyleFontFamilyVecValueVariant_Auto AzStyleFontFamilyVecValueVariant_Auto;
struct AzStyleFontFamilyVecValueVariant_None { AzStyleFontFamilyVecValueTag tag; };
typedef struct AzStyleFontFamilyVecValueVariant_None AzStyleFontFamilyVecValueVariant_None;
struct AzStyleFontFamilyVecValueVariant_Inherit { AzStyleFontFamilyVecValueTag tag; };
typedef struct AzStyleFontFamilyVecValueVariant_Inherit AzStyleFontFamilyVecValueVariant_Inherit;
struct AzStyleFontFamilyVecValueVariant_Initial { AzStyleFontFamilyVecValueTag tag; };
typedef struct AzStyleFontFamilyVecValueVariant_Initial AzStyleFontFamilyVecValueVariant_Initial;
struct AzStyleFontFamilyVecValueVariant_Exact { AzStyleFontFamilyVecValueTag tag; AzStyleFontFamilyVec payload; };
typedef struct AzStyleFontFamilyVecValueVariant_Exact AzStyleFontFamilyVecValueVariant_Exact;
union AzStyleFontFamilyVecValue {
    AzStyleFontFamilyVecValueVariant_Auto Auto;
    AzStyleFontFamilyVecValueVariant_None None;
    AzStyleFontFamilyVecValueVariant_Inherit Inherit;
    AzStyleFontFamilyVecValueVariant_Initial Initial;
    AzStyleFontFamilyVecValueVariant_Exact Exact;
};
typedef union AzStyleFontFamilyVecValue AzStyleFontFamilyVecValue;

enum AzCssPropertyTag {
   AzCssPropertyTag_TextColor,
   AzCssPropertyTag_FontSize,
   AzCssPropertyTag_FontFamily,
   AzCssPropertyTag_TextAlign,
   AzCssPropertyTag_LetterSpacing,
   AzCssPropertyTag_LineHeight,
   AzCssPropertyTag_WordSpacing,
   AzCssPropertyTag_TabWidth,
   AzCssPropertyTag_Cursor,
   AzCssPropertyTag_Display,
   AzCssPropertyTag_Float,
   AzCssPropertyTag_BoxSizing,
   AzCssPropertyTag_Width,
   AzCssPropertyTag_Height,
   AzCssPropertyTag_MinWidth,
   AzCssPropertyTag_MinHeight,
   AzCssPropertyTag_MaxWidth,
   AzCssPropertyTag_MaxHeight,
   AzCssPropertyTag_Position,
   AzCssPropertyTag_Top,
   AzCssPropertyTag_Right,
   AzCssPropertyTag_Left,
   AzCssPropertyTag_Bottom,
   AzCssPropertyTag_FlexWrap,
   AzCssPropertyTag_FlexDirection,
   AzCssPropertyTag_FlexGrow,
   AzCssPropertyTag_FlexShrink,
   AzCssPropertyTag_JustifyContent,
   AzCssPropertyTag_AlignItems,
   AzCssPropertyTag_AlignContent,
   AzCssPropertyTag_BackgroundContent,
   AzCssPropertyTag_BackgroundPosition,
   AzCssPropertyTag_BackgroundSize,
   AzCssPropertyTag_BackgroundRepeat,
   AzCssPropertyTag_OverflowX,
   AzCssPropertyTag_OverflowY,
   AzCssPropertyTag_PaddingTop,
   AzCssPropertyTag_PaddingLeft,
   AzCssPropertyTag_PaddingRight,
   AzCssPropertyTag_PaddingBottom,
   AzCssPropertyTag_MarginTop,
   AzCssPropertyTag_MarginLeft,
   AzCssPropertyTag_MarginRight,
   AzCssPropertyTag_MarginBottom,
   AzCssPropertyTag_BorderTopLeftRadius,
   AzCssPropertyTag_BorderTopRightRadius,
   AzCssPropertyTag_BorderBottomLeftRadius,
   AzCssPropertyTag_BorderBottomRightRadius,
   AzCssPropertyTag_BorderTopColor,
   AzCssPropertyTag_BorderRightColor,
   AzCssPropertyTag_BorderLeftColor,
   AzCssPropertyTag_BorderBottomColor,
   AzCssPropertyTag_BorderTopStyle,
   AzCssPropertyTag_BorderRightStyle,
   AzCssPropertyTag_BorderLeftStyle,
   AzCssPropertyTag_BorderBottomStyle,
   AzCssPropertyTag_BorderTopWidth,
   AzCssPropertyTag_BorderRightWidth,
   AzCssPropertyTag_BorderLeftWidth,
   AzCssPropertyTag_BorderBottomWidth,
   AzCssPropertyTag_BoxShadowLeft,
   AzCssPropertyTag_BoxShadowRight,
   AzCssPropertyTag_BoxShadowTop,
   AzCssPropertyTag_BoxShadowBottom,
   AzCssPropertyTag_ScrollbarStyle,
   AzCssPropertyTag_Opacity,
   AzCssPropertyTag_Transform,
   AzCssPropertyTag_TransformOrigin,
   AzCssPropertyTag_PerspectiveOrigin,
   AzCssPropertyTag_BackfaceVisibility,
};
typedef enum AzCssPropertyTag AzCssPropertyTag;

struct AzCssPropertyVariant_TextColor { AzCssPropertyTag tag; AzStyleTextColorValue payload; };
typedef struct AzCssPropertyVariant_TextColor AzCssPropertyVariant_TextColor;
struct AzCssPropertyVariant_FontSize { AzCssPropertyTag tag; AzStyleFontSizeValue payload; };
typedef struct AzCssPropertyVariant_FontSize AzCssPropertyVariant_FontSize;
struct AzCssPropertyVariant_FontFamily { AzCssPropertyTag tag; AzStyleFontFamilyVecValue payload; };
typedef struct AzCssPropertyVariant_FontFamily AzCssPropertyVariant_FontFamily;
struct AzCssPropertyVariant_TextAlign { AzCssPropertyTag tag; AzStyleTextAlignValue payload; };
typedef struct AzCssPropertyVariant_TextAlign AzCssPropertyVariant_TextAlign;
struct AzCssPropertyVariant_LetterSpacing { AzCssPropertyTag tag; AzStyleLetterSpacingValue payload; };
typedef struct AzCssPropertyVariant_LetterSpacing AzCssPropertyVariant_LetterSpacing;
struct AzCssPropertyVariant_LineHeight { AzCssPropertyTag tag; AzStyleLineHeightValue payload; };
typedef struct AzCssPropertyVariant_LineHeight AzCssPropertyVariant_LineHeight;
struct AzCssPropertyVariant_WordSpacing { AzCssPropertyTag tag; AzStyleWordSpacingValue payload; };
typedef struct AzCssPropertyVariant_WordSpacing AzCssPropertyVariant_WordSpacing;
struct AzCssPropertyVariant_TabWidth { AzCssPropertyTag tag; AzStyleTabWidthValue payload; };
typedef struct AzCssPropertyVariant_TabWidth AzCssPropertyVariant_TabWidth;
struct AzCssPropertyVariant_Cursor { AzCssPropertyTag tag; AzStyleCursorValue payload; };
typedef struct AzCssPropertyVariant_Cursor AzCssPropertyVariant_Cursor;
struct AzCssPropertyVariant_Display { AzCssPropertyTag tag; AzLayoutDisplayValue payload; };
typedef struct AzCssPropertyVariant_Display AzCssPropertyVariant_Display;
struct AzCssPropertyVariant_Float { AzCssPropertyTag tag; AzLayoutFloatValue payload; };
typedef struct AzCssPropertyVariant_Float AzCssPropertyVariant_Float;
struct AzCssPropertyVariant_BoxSizing { AzCssPropertyTag tag; AzLayoutBoxSizingValue payload; };
typedef struct AzCssPropertyVariant_BoxSizing AzCssPropertyVariant_BoxSizing;
struct AzCssPropertyVariant_Width { AzCssPropertyTag tag; AzLayoutWidthValue payload; };
typedef struct AzCssPropertyVariant_Width AzCssPropertyVariant_Width;
struct AzCssPropertyVariant_Height { AzCssPropertyTag tag; AzLayoutHeightValue payload; };
typedef struct AzCssPropertyVariant_Height AzCssPropertyVariant_Height;
struct AzCssPropertyVariant_MinWidth { AzCssPropertyTag tag; AzLayoutMinWidthValue payload; };
typedef struct AzCssPropertyVariant_MinWidth AzCssPropertyVariant_MinWidth;
struct AzCssPropertyVariant_MinHeight { AzCssPropertyTag tag; AzLayoutMinHeightValue payload; };
typedef struct AzCssPropertyVariant_MinHeight AzCssPropertyVariant_MinHeight;
struct AzCssPropertyVariant_MaxWidth { AzCssPropertyTag tag; AzLayoutMaxWidthValue payload; };
typedef struct AzCssPropertyVariant_MaxWidth AzCssPropertyVariant_MaxWidth;
struct AzCssPropertyVariant_MaxHeight { AzCssPropertyTag tag; AzLayoutMaxHeightValue payload; };
typedef struct AzCssPropertyVariant_MaxHeight AzCssPropertyVariant_MaxHeight;
struct AzCssPropertyVariant_Position { AzCssPropertyTag tag; AzLayoutPositionValue payload; };
typedef struct AzCssPropertyVariant_Position AzCssPropertyVariant_Position;
struct AzCssPropertyVariant_Top { AzCssPropertyTag tag; AzLayoutTopValue payload; };
typedef struct AzCssPropertyVariant_Top AzCssPropertyVariant_Top;
struct AzCssPropertyVariant_Right { AzCssPropertyTag tag; AzLayoutRightValue payload; };
typedef struct AzCssPropertyVariant_Right AzCssPropertyVariant_Right;
struct AzCssPropertyVariant_Left { AzCssPropertyTag tag; AzLayoutLeftValue payload; };
typedef struct AzCssPropertyVariant_Left AzCssPropertyVariant_Left;
struct AzCssPropertyVariant_Bottom { AzCssPropertyTag tag; AzLayoutBottomValue payload; };
typedef struct AzCssPropertyVariant_Bottom AzCssPropertyVariant_Bottom;
struct AzCssPropertyVariant_FlexWrap { AzCssPropertyTag tag; AzLayoutFlexWrapValue payload; };
typedef struct AzCssPropertyVariant_FlexWrap AzCssPropertyVariant_FlexWrap;
struct AzCssPropertyVariant_FlexDirection { AzCssPropertyTag tag; AzLayoutFlexDirectionValue payload; };
typedef struct AzCssPropertyVariant_FlexDirection AzCssPropertyVariant_FlexDirection;
struct AzCssPropertyVariant_FlexGrow { AzCssPropertyTag tag; AzLayoutFlexGrowValue payload; };
typedef struct AzCssPropertyVariant_FlexGrow AzCssPropertyVariant_FlexGrow;
struct AzCssPropertyVariant_FlexShrink { AzCssPropertyTag tag; AzLayoutFlexShrinkValue payload; };
typedef struct AzCssPropertyVariant_FlexShrink AzCssPropertyVariant_FlexShrink;
struct AzCssPropertyVariant_JustifyContent { AzCssPropertyTag tag; AzLayoutJustifyContentValue payload; };
typedef struct AzCssPropertyVariant_JustifyContent AzCssPropertyVariant_JustifyContent;
struct AzCssPropertyVariant_AlignItems { AzCssPropertyTag tag; AzLayoutAlignItemsValue payload; };
typedef struct AzCssPropertyVariant_AlignItems AzCssPropertyVariant_AlignItems;
struct AzCssPropertyVariant_AlignContent { AzCssPropertyTag tag; AzLayoutAlignContentValue payload; };
typedef struct AzCssPropertyVariant_AlignContent AzCssPropertyVariant_AlignContent;
struct AzCssPropertyVariant_BackgroundContent { AzCssPropertyTag tag; AzStyleBackgroundContentVecValue payload; };
typedef struct AzCssPropertyVariant_BackgroundContent AzCssPropertyVariant_BackgroundContent;
struct AzCssPropertyVariant_BackgroundPosition { AzCssPropertyTag tag; AzStyleBackgroundPositionVecValue payload; };
typedef struct AzCssPropertyVariant_BackgroundPosition AzCssPropertyVariant_BackgroundPosition;
struct AzCssPropertyVariant_BackgroundSize { AzCssPropertyTag tag; AzStyleBackgroundSizeVecValue payload; };
typedef struct AzCssPropertyVariant_BackgroundSize AzCssPropertyVariant_BackgroundSize;
struct AzCssPropertyVariant_BackgroundRepeat { AzCssPropertyTag tag; AzStyleBackgroundRepeatVecValue payload; };
typedef struct AzCssPropertyVariant_BackgroundRepeat AzCssPropertyVariant_BackgroundRepeat;
struct AzCssPropertyVariant_OverflowX { AzCssPropertyTag tag; AzLayoutOverflowValue payload; };
typedef struct AzCssPropertyVariant_OverflowX AzCssPropertyVariant_OverflowX;
struct AzCssPropertyVariant_OverflowY { AzCssPropertyTag tag; AzLayoutOverflowValue payload; };
typedef struct AzCssPropertyVariant_OverflowY AzCssPropertyVariant_OverflowY;
struct AzCssPropertyVariant_PaddingTop { AzCssPropertyTag tag; AzLayoutPaddingTopValue payload; };
typedef struct AzCssPropertyVariant_PaddingTop AzCssPropertyVariant_PaddingTop;
struct AzCssPropertyVariant_PaddingLeft { AzCssPropertyTag tag; AzLayoutPaddingLeftValue payload; };
typedef struct AzCssPropertyVariant_PaddingLeft AzCssPropertyVariant_PaddingLeft;
struct AzCssPropertyVariant_PaddingRight { AzCssPropertyTag tag; AzLayoutPaddingRightValue payload; };
typedef struct AzCssPropertyVariant_PaddingRight AzCssPropertyVariant_PaddingRight;
struct AzCssPropertyVariant_PaddingBottom { AzCssPropertyTag tag; AzLayoutPaddingBottomValue payload; };
typedef struct AzCssPropertyVariant_PaddingBottom AzCssPropertyVariant_PaddingBottom;
struct AzCssPropertyVariant_MarginTop { AzCssPropertyTag tag; AzLayoutMarginTopValue payload; };
typedef struct AzCssPropertyVariant_MarginTop AzCssPropertyVariant_MarginTop;
struct AzCssPropertyVariant_MarginLeft { AzCssPropertyTag tag; AzLayoutMarginLeftValue payload; };
typedef struct AzCssPropertyVariant_MarginLeft AzCssPropertyVariant_MarginLeft;
struct AzCssPropertyVariant_MarginRight { AzCssPropertyTag tag; AzLayoutMarginRightValue payload; };
typedef struct AzCssPropertyVariant_MarginRight AzCssPropertyVariant_MarginRight;
struct AzCssPropertyVariant_MarginBottom { AzCssPropertyTag tag; AzLayoutMarginBottomValue payload; };
typedef struct AzCssPropertyVariant_MarginBottom AzCssPropertyVariant_MarginBottom;
struct AzCssPropertyVariant_BorderTopLeftRadius { AzCssPropertyTag tag; AzStyleBorderTopLeftRadiusValue payload; };
typedef struct AzCssPropertyVariant_BorderTopLeftRadius AzCssPropertyVariant_BorderTopLeftRadius;
struct AzCssPropertyVariant_BorderTopRightRadius { AzCssPropertyTag tag; AzStyleBorderTopRightRadiusValue payload; };
typedef struct AzCssPropertyVariant_BorderTopRightRadius AzCssPropertyVariant_BorderTopRightRadius;
struct AzCssPropertyVariant_BorderBottomLeftRadius { AzCssPropertyTag tag; AzStyleBorderBottomLeftRadiusValue payload; };
typedef struct AzCssPropertyVariant_BorderBottomLeftRadius AzCssPropertyVariant_BorderBottomLeftRadius;
struct AzCssPropertyVariant_BorderBottomRightRadius { AzCssPropertyTag tag; AzStyleBorderBottomRightRadiusValue payload; };
typedef struct AzCssPropertyVariant_BorderBottomRightRadius AzCssPropertyVariant_BorderBottomRightRadius;
struct AzCssPropertyVariant_BorderTopColor { AzCssPropertyTag tag; AzStyleBorderTopColorValue payload; };
typedef struct AzCssPropertyVariant_BorderTopColor AzCssPropertyVariant_BorderTopColor;
struct AzCssPropertyVariant_BorderRightColor { AzCssPropertyTag tag; AzStyleBorderRightColorValue payload; };
typedef struct AzCssPropertyVariant_BorderRightColor AzCssPropertyVariant_BorderRightColor;
struct AzCssPropertyVariant_BorderLeftColor { AzCssPropertyTag tag; AzStyleBorderLeftColorValue payload; };
typedef struct AzCssPropertyVariant_BorderLeftColor AzCssPropertyVariant_BorderLeftColor;
struct AzCssPropertyVariant_BorderBottomColor { AzCssPropertyTag tag; AzStyleBorderBottomColorValue payload; };
typedef struct AzCssPropertyVariant_BorderBottomColor AzCssPropertyVariant_BorderBottomColor;
struct AzCssPropertyVariant_BorderTopStyle { AzCssPropertyTag tag; AzStyleBorderTopStyleValue payload; };
typedef struct AzCssPropertyVariant_BorderTopStyle AzCssPropertyVariant_BorderTopStyle;
struct AzCssPropertyVariant_BorderRightStyle { AzCssPropertyTag tag; AzStyleBorderRightStyleValue payload; };
typedef struct AzCssPropertyVariant_BorderRightStyle AzCssPropertyVariant_BorderRightStyle;
struct AzCssPropertyVariant_BorderLeftStyle { AzCssPropertyTag tag; AzStyleBorderLeftStyleValue payload; };
typedef struct AzCssPropertyVariant_BorderLeftStyle AzCssPropertyVariant_BorderLeftStyle;
struct AzCssPropertyVariant_BorderBottomStyle { AzCssPropertyTag tag; AzStyleBorderBottomStyleValue payload; };
typedef struct AzCssPropertyVariant_BorderBottomStyle AzCssPropertyVariant_BorderBottomStyle;
struct AzCssPropertyVariant_BorderTopWidth { AzCssPropertyTag tag; AzLayoutBorderTopWidthValue payload; };
typedef struct AzCssPropertyVariant_BorderTopWidth AzCssPropertyVariant_BorderTopWidth;
struct AzCssPropertyVariant_BorderRightWidth { AzCssPropertyTag tag; AzLayoutBorderRightWidthValue payload; };
typedef struct AzCssPropertyVariant_BorderRightWidth AzCssPropertyVariant_BorderRightWidth;
struct AzCssPropertyVariant_BorderLeftWidth { AzCssPropertyTag tag; AzLayoutBorderLeftWidthValue payload; };
typedef struct AzCssPropertyVariant_BorderLeftWidth AzCssPropertyVariant_BorderLeftWidth;
struct AzCssPropertyVariant_BorderBottomWidth { AzCssPropertyTag tag; AzLayoutBorderBottomWidthValue payload; };
typedef struct AzCssPropertyVariant_BorderBottomWidth AzCssPropertyVariant_BorderBottomWidth;
struct AzCssPropertyVariant_BoxShadowLeft { AzCssPropertyTag tag; AzStyleBoxShadowValue payload; };
typedef struct AzCssPropertyVariant_BoxShadowLeft AzCssPropertyVariant_BoxShadowLeft;
struct AzCssPropertyVariant_BoxShadowRight { AzCssPropertyTag tag; AzStyleBoxShadowValue payload; };
typedef struct AzCssPropertyVariant_BoxShadowRight AzCssPropertyVariant_BoxShadowRight;
struct AzCssPropertyVariant_BoxShadowTop { AzCssPropertyTag tag; AzStyleBoxShadowValue payload; };
typedef struct AzCssPropertyVariant_BoxShadowTop AzCssPropertyVariant_BoxShadowTop;
struct AzCssPropertyVariant_BoxShadowBottom { AzCssPropertyTag tag; AzStyleBoxShadowValue payload; };
typedef struct AzCssPropertyVariant_BoxShadowBottom AzCssPropertyVariant_BoxShadowBottom;
struct AzCssPropertyVariant_ScrollbarStyle { AzCssPropertyTag tag; AzScrollbarStyleValue payload; };
typedef struct AzCssPropertyVariant_ScrollbarStyle AzCssPropertyVariant_ScrollbarStyle;
struct AzCssPropertyVariant_Opacity { AzCssPropertyTag tag; AzStyleOpacityValue payload; };
typedef struct AzCssPropertyVariant_Opacity AzCssPropertyVariant_Opacity;
struct AzCssPropertyVariant_Transform { AzCssPropertyTag tag; AzStyleTransformVecValue payload; };
typedef struct AzCssPropertyVariant_Transform AzCssPropertyVariant_Transform;
struct AzCssPropertyVariant_TransformOrigin { AzCssPropertyTag tag; AzStyleTransformOriginValue payload; };
typedef struct AzCssPropertyVariant_TransformOrigin AzCssPropertyVariant_TransformOrigin;
struct AzCssPropertyVariant_PerspectiveOrigin { AzCssPropertyTag tag; AzStylePerspectiveOriginValue payload; };
typedef struct AzCssPropertyVariant_PerspectiveOrigin AzCssPropertyVariant_PerspectiveOrigin;
struct AzCssPropertyVariant_BackfaceVisibility { AzCssPropertyTag tag; AzStyleBackfaceVisibilityValue payload; };
typedef struct AzCssPropertyVariant_BackfaceVisibility AzCssPropertyVariant_BackfaceVisibility;
union AzCssProperty {
    AzCssPropertyVariant_TextColor TextColor;
    AzCssPropertyVariant_FontSize FontSize;
    AzCssPropertyVariant_FontFamily FontFamily;
    AzCssPropertyVariant_TextAlign TextAlign;
    AzCssPropertyVariant_LetterSpacing LetterSpacing;
    AzCssPropertyVariant_LineHeight LineHeight;
    AzCssPropertyVariant_WordSpacing WordSpacing;
    AzCssPropertyVariant_TabWidth TabWidth;
    AzCssPropertyVariant_Cursor Cursor;
    AzCssPropertyVariant_Display Display;
    AzCssPropertyVariant_Float Float;
    AzCssPropertyVariant_BoxSizing BoxSizing;
    AzCssPropertyVariant_Width Width;
    AzCssPropertyVariant_Height Height;
    AzCssPropertyVariant_MinWidth MinWidth;
    AzCssPropertyVariant_MinHeight MinHeight;
    AzCssPropertyVariant_MaxWidth MaxWidth;
    AzCssPropertyVariant_MaxHeight MaxHeight;
    AzCssPropertyVariant_Position Position;
    AzCssPropertyVariant_Top Top;
    AzCssPropertyVariant_Right Right;
    AzCssPropertyVariant_Left Left;
    AzCssPropertyVariant_Bottom Bottom;
    AzCssPropertyVariant_FlexWrap FlexWrap;
    AzCssPropertyVariant_FlexDirection FlexDirection;
    AzCssPropertyVariant_FlexGrow FlexGrow;
    AzCssPropertyVariant_FlexShrink FlexShrink;
    AzCssPropertyVariant_JustifyContent JustifyContent;
    AzCssPropertyVariant_AlignItems AlignItems;
    AzCssPropertyVariant_AlignContent AlignContent;
    AzCssPropertyVariant_BackgroundContent BackgroundContent;
    AzCssPropertyVariant_BackgroundPosition BackgroundPosition;
    AzCssPropertyVariant_BackgroundSize BackgroundSize;
    AzCssPropertyVariant_BackgroundRepeat BackgroundRepeat;
    AzCssPropertyVariant_OverflowX OverflowX;
    AzCssPropertyVariant_OverflowY OverflowY;
    AzCssPropertyVariant_PaddingTop PaddingTop;
    AzCssPropertyVariant_PaddingLeft PaddingLeft;
    AzCssPropertyVariant_PaddingRight PaddingRight;
    AzCssPropertyVariant_PaddingBottom PaddingBottom;
    AzCssPropertyVariant_MarginTop MarginTop;
    AzCssPropertyVariant_MarginLeft MarginLeft;
    AzCssPropertyVariant_MarginRight MarginRight;
    AzCssPropertyVariant_MarginBottom MarginBottom;
    AzCssPropertyVariant_BorderTopLeftRadius BorderTopLeftRadius;
    AzCssPropertyVariant_BorderTopRightRadius BorderTopRightRadius;
    AzCssPropertyVariant_BorderBottomLeftRadius BorderBottomLeftRadius;
    AzCssPropertyVariant_BorderBottomRightRadius BorderBottomRightRadius;
    AzCssPropertyVariant_BorderTopColor BorderTopColor;
    AzCssPropertyVariant_BorderRightColor BorderRightColor;
    AzCssPropertyVariant_BorderLeftColor BorderLeftColor;
    AzCssPropertyVariant_BorderBottomColor BorderBottomColor;
    AzCssPropertyVariant_BorderTopStyle BorderTopStyle;
    AzCssPropertyVariant_BorderRightStyle BorderRightStyle;
    AzCssPropertyVariant_BorderLeftStyle BorderLeftStyle;
    AzCssPropertyVariant_BorderBottomStyle BorderBottomStyle;
    AzCssPropertyVariant_BorderTopWidth BorderTopWidth;
    AzCssPropertyVariant_BorderRightWidth BorderRightWidth;
    AzCssPropertyVariant_BorderLeftWidth BorderLeftWidth;
    AzCssPropertyVariant_BorderBottomWidth BorderBottomWidth;
    AzCssPropertyVariant_BoxShadowLeft BoxShadowLeft;
    AzCssPropertyVariant_BoxShadowRight BoxShadowRight;
    AzCssPropertyVariant_BoxShadowTop BoxShadowTop;
    AzCssPropertyVariant_BoxShadowBottom BoxShadowBottom;
    AzCssPropertyVariant_ScrollbarStyle ScrollbarStyle;
    AzCssPropertyVariant_Opacity Opacity;
    AzCssPropertyVariant_Transform Transform;
    AzCssPropertyVariant_TransformOrigin TransformOrigin;
    AzCssPropertyVariant_PerspectiveOrigin PerspectiveOrigin;
    AzCssPropertyVariant_BackfaceVisibility BackfaceVisibility;
};
typedef union AzCssProperty AzCssProperty;

struct AzTextInputStateWrapper {
    AzTextInputState inner;
    AzOptionTextInputOnTextInput on_text_input;
    AzOptionTextInputOnVirtualKeyDown on_virtual_key_down;
    AzOptionTextInputOnFocusLost on_focus_lost;
    bool  update_text_input_before_calling_focus_lost_fn;
    bool  update_text_input_before_calling_vk_down_fn;
};
typedef struct AzTextInputStateWrapper AzTextInputStateWrapper;

enum AzCssPropertySourceTag {
   AzCssPropertySourceTag_Css,
   AzCssPropertySourceTag_Inline,
};
typedef enum AzCssPropertySourceTag AzCssPropertySourceTag;

struct AzCssPropertySourceVariant_Css { AzCssPropertySourceTag tag; AzCssPath payload; };
typedef struct AzCssPropertySourceVariant_Css AzCssPropertySourceVariant_Css;
struct AzCssPropertySourceVariant_Inline { AzCssPropertySourceTag tag; };
typedef struct AzCssPropertySourceVariant_Inline AzCssPropertySourceVariant_Inline;
union AzCssPropertySource {
    AzCssPropertySourceVariant_Css Css;
    AzCssPropertySourceVariant_Inline Inline;
};
typedef union AzCssPropertySource AzCssPropertySource;

struct AzVertexLayout {
    AzVertexAttributeVec fields;
};
typedef struct AzVertexLayout AzVertexLayout;

struct AzVertexArrayObject {
    AzVertexLayout vertex_layout;
    uint32_t vao_id;
    AzGl gl_context;
};
typedef struct AzVertexArrayObject AzVertexArrayObject;

struct AzVertexBuffer {
    uint32_t vertex_buffer_id;
    size_t vertex_buffer_len;
    AzVertexArrayObject vao;
    uint32_t index_buffer_id;
    size_t index_buffer_len;
    AzIndexBufferFormat index_buffer_format;
};
typedef struct AzVertexBuffer AzVertexBuffer;

struct AzSvgMultiPolygon {
    AzSvgPathVec rings;
};
typedef struct AzSvgMultiPolygon AzSvgMultiPolygon;

struct AzXmlNode {
    AzString tag;
    AzStringPairVec attributes;
    AzXmlNodeVec children;
    AzOptionString text;
};
typedef struct AzXmlNode AzXmlNode;

struct AzInlineLineVec {
    AzInlineLine* ptr;
    size_t len;
    size_t cap;
    AzInlineLineVecDestructor destructor;
};
typedef struct AzInlineLineVec AzInlineLineVec;

struct AzCssPropertyVec {
    AzCssProperty* ptr;
    size_t len;
    size_t cap;
    AzCssPropertyVecDestructor destructor;
};
typedef struct AzCssPropertyVec AzCssPropertyVec;

struct AzSvgMultiPolygonVec {
    AzSvgMultiPolygon* ptr;
    size_t len;
    size_t cap;
    AzSvgMultiPolygonVecDestructor destructor;
};
typedef struct AzSvgMultiPolygonVec AzSvgMultiPolygonVec;

enum AzOptionCssPropertyTag {
   AzOptionCssPropertyTag_None,
   AzOptionCssPropertyTag_Some,
};
typedef enum AzOptionCssPropertyTag AzOptionCssPropertyTag;

struct AzOptionCssPropertyVariant_None { AzOptionCssPropertyTag tag; };
typedef struct AzOptionCssPropertyVariant_None AzOptionCssPropertyVariant_None;
struct AzOptionCssPropertyVariant_Some { AzOptionCssPropertyTag tag; AzCssProperty payload; };
typedef struct AzOptionCssPropertyVariant_Some AzOptionCssPropertyVariant_Some;
union AzOptionCssProperty {
    AzOptionCssPropertyVariant_None None;
    AzOptionCssPropertyVariant_Some Some;
};
typedef union AzOptionCssProperty AzOptionCssProperty;

struct AzXmlTextError {
    AzXmlStreamError stream_error;
    AzSvgParseErrorPosition pos;
};
typedef struct AzXmlTextError AzXmlTextError;

struct AzPlatformSpecificOptions {
    AzWindowsWindowOptions windows_options;
    AzLinuxWindowOptions linux_options;
    AzMacWindowOptions mac_options;
    AzWasmWindowOptions wasm_options;
};
typedef struct AzPlatformSpecificOptions AzPlatformSpecificOptions;

struct AzWindowState {
    AzString title;
    AzWindowTheme theme;
    AzWindowSize size;
    AzWindowPosition position;
    AzWindowFlags flags;
    AzDebugState debug_state;
    AzKeyboardState keyboard_state;
    AzMouseState mouse_state;
    AzTouchState touch_state;
    AzImePosition ime_position;
    AzMonitor monitor;
    AzPlatformSpecificOptions platform_specific_options;
    AzRendererOptions renderer_options;
    AzColorU background_color;
    AzLayoutCallback layout_callback;
    AzOptionCallback close_callback;
};
typedef struct AzWindowState AzWindowState;

struct AzCallbackInfo {
    void* css_property_cache;
    void* styled_node_states;
    void* previous_window_state;
    void* current_window_state;
    AzWindowState* restrict modifiable_window_state;
    AzOptionGl* gl_context;
    void* restrict image_cache;
    void* restrict system_fonts;
    void* restrict timers;
    void* restrict threads;
    void* restrict timers_removed;
    void* restrict threads_removed;
    void* restrict new_windows;
    AzRawWindowHandle* current_window_handle;
    void* node_hierarchy;
    AzSystemCallbacks* system_callbacks;
    void* fonts;
    void* restrict datasets;
    bool * restrict stop_propagation;
    void* restrict focus_target;
    void* words_cache;
    void* shaped_words_cache;
    void* positioned_words_cache;
    void* positioned_rects;
    void* restrict words_changed_in_callbacks;
    void* restrict images_changed_in_callbacks;
    void* restrict image_masks_changed_in_callbacks;
    void* restrict css_properties_changed_in_callbacks;
    void* current_scroll_states;
    void* restrict nodes_scrolled_in_callback;
    AzDomNodeId hit_dom_node;
    AzOptionLogicalPosition cursor_relative_to_item;
    AzOptionLogicalPosition cursor_in_viewport;
    void* _reserved_ref;
    void* restrict _reserved_mut;
};
typedef struct AzCallbackInfo AzCallbackInfo;

struct AzInlineText {
    AzInlineLineVec lines;
    AzLogicalSize content_size;
    float font_size_px;
    size_t last_word_index;
    float baseline_descender_px;
};
typedef struct AzInlineText AzInlineText;

struct AzFocusTargetPath {
    AzDomId dom;
    AzCssPath css_path;
};
typedef struct AzFocusTargetPath AzFocusTargetPath;

struct AzAnimation {
    AzCssProperty from;
    AzCssProperty to;
    AzDuration duration;
    AzAnimationRepeat repeat;
    AzAnimationRepeatCount repeat_count;
    AzAnimationEasing easing;
    bool  relayout_on_finish;
};
typedef struct AzAnimation AzAnimation;

struct AzTimerCallbackInfo {
    AzCallbackInfo callback_info;
    AzOptionDomNodeId node_id;
    AzInstant frame_start;
    size_t call_count;
    bool  is_about_to_finish;
    void* _reserved_ref;
    void* restrict _reserved_mut;
};
typedef struct AzTimerCallbackInfo AzTimerCallbackInfo;

enum AzNodeDataInlineCssPropertyTag {
   AzNodeDataInlineCssPropertyTag_Normal,
   AzNodeDataInlineCssPropertyTag_Active,
   AzNodeDataInlineCssPropertyTag_Focus,
   AzNodeDataInlineCssPropertyTag_Hover,
};
typedef enum AzNodeDataInlineCssPropertyTag AzNodeDataInlineCssPropertyTag;

struct AzNodeDataInlineCssPropertyVariant_Normal { AzNodeDataInlineCssPropertyTag tag; AzCssProperty payload; };
typedef struct AzNodeDataInlineCssPropertyVariant_Normal AzNodeDataInlineCssPropertyVariant_Normal;
struct AzNodeDataInlineCssPropertyVariant_Active { AzNodeDataInlineCssPropertyTag tag; AzCssProperty payload; };
typedef struct AzNodeDataInlineCssPropertyVariant_Active AzNodeDataInlineCssPropertyVariant_Active;
struct AzNodeDataInlineCssPropertyVariant_Focus { AzNodeDataInlineCssPropertyTag tag; AzCssProperty payload; };
typedef struct AzNodeDataInlineCssPropertyVariant_Focus AzNodeDataInlineCssPropertyVariant_Focus;
struct AzNodeDataInlineCssPropertyVariant_Hover { AzNodeDataInlineCssPropertyTag tag; AzCssProperty payload; };
typedef struct AzNodeDataInlineCssPropertyVariant_Hover AzNodeDataInlineCssPropertyVariant_Hover;
union AzNodeDataInlineCssProperty {
    AzNodeDataInlineCssPropertyVariant_Normal Normal;
    AzNodeDataInlineCssPropertyVariant_Active Active;
    AzNodeDataInlineCssPropertyVariant_Focus Focus;
    AzNodeDataInlineCssPropertyVariant_Hover Hover;
};
typedef union AzNodeDataInlineCssProperty AzNodeDataInlineCssProperty;

struct AzDynamicCssProperty {
    AzString dynamic_id;
    AzCssProperty default_value;
};
typedef struct AzDynamicCssProperty AzDynamicCssProperty;

enum AzSvgNodeTag {
   AzSvgNodeTag_MultiPolygonCollection,
   AzSvgNodeTag_MultiPolygon,
   AzSvgNodeTag_Path,
   AzSvgNodeTag_Circle,
   AzSvgNodeTag_Rect,
};
typedef enum AzSvgNodeTag AzSvgNodeTag;

struct AzSvgNodeVariant_MultiPolygonCollection { AzSvgNodeTag tag; AzSvgMultiPolygonVec payload; };
typedef struct AzSvgNodeVariant_MultiPolygonCollection AzSvgNodeVariant_MultiPolygonCollection;
struct AzSvgNodeVariant_MultiPolygon { AzSvgNodeTag tag; AzSvgMultiPolygon payload; };
typedef struct AzSvgNodeVariant_MultiPolygon AzSvgNodeVariant_MultiPolygon;
struct AzSvgNodeVariant_Path { AzSvgNodeTag tag; AzSvgPath payload; };
typedef struct AzSvgNodeVariant_Path AzSvgNodeVariant_Path;
struct AzSvgNodeVariant_Circle { AzSvgNodeTag tag; AzSvgCircle payload; };
typedef struct AzSvgNodeVariant_Circle AzSvgNodeVariant_Circle;
struct AzSvgNodeVariant_Rect { AzSvgNodeTag tag; AzSvgRect payload; };
typedef struct AzSvgNodeVariant_Rect AzSvgNodeVariant_Rect;
union AzSvgNode {
    AzSvgNodeVariant_MultiPolygonCollection MultiPolygonCollection;
    AzSvgNodeVariant_MultiPolygon MultiPolygon;
    AzSvgNodeVariant_Path Path;
    AzSvgNodeVariant_Circle Circle;
    AzSvgNodeVariant_Rect Rect;
};
typedef union AzSvgNode AzSvgNode;

struct AzSvgStyledNode {
    AzSvgNode geometry;
    AzSvgStyle style;
};
typedef struct AzSvgStyledNode AzSvgStyledNode;

struct AzNodeDataInlineCssPropertyVec {
    AzNodeDataInlineCssProperty* ptr;
    size_t len;
    size_t cap;
    AzNodeDataInlineCssPropertyVecDestructor destructor;
};
typedef struct AzNodeDataInlineCssPropertyVec AzNodeDataInlineCssPropertyVec;

enum AzOptionWindowStateTag {
   AzOptionWindowStateTag_None,
   AzOptionWindowStateTag_Some,
};
typedef enum AzOptionWindowStateTag AzOptionWindowStateTag;

struct AzOptionWindowStateVariant_None { AzOptionWindowStateTag tag; };
typedef struct AzOptionWindowStateVariant_None AzOptionWindowStateVariant_None;
struct AzOptionWindowStateVariant_Some { AzOptionWindowStateTag tag; AzWindowState payload; };
typedef struct AzOptionWindowStateVariant_Some AzOptionWindowStateVariant_Some;
union AzOptionWindowState {
    AzOptionWindowStateVariant_None None;
    AzOptionWindowStateVariant_Some Some;
};
typedef union AzOptionWindowState AzOptionWindowState;

enum AzOptionInlineTextTag {
   AzOptionInlineTextTag_None,
   AzOptionInlineTextTag_Some,
};
typedef enum AzOptionInlineTextTag AzOptionInlineTextTag;

struct AzOptionInlineTextVariant_None { AzOptionInlineTextTag tag; };
typedef struct AzOptionInlineTextVariant_None AzOptionInlineTextVariant_None;
struct AzOptionInlineTextVariant_Some { AzOptionInlineTextTag tag; AzInlineText payload; };
typedef struct AzOptionInlineTextVariant_Some AzOptionInlineTextVariant_Some;
union AzOptionInlineText {
    AzOptionInlineTextVariant_None None;
    AzOptionInlineTextVariant_Some Some;
};
typedef union AzOptionInlineText AzOptionInlineText;

enum AzXmlParseErrorTag {
   AzXmlParseErrorTag_InvalidDeclaration,
   AzXmlParseErrorTag_InvalidComment,
   AzXmlParseErrorTag_InvalidPI,
   AzXmlParseErrorTag_InvalidDoctype,
   AzXmlParseErrorTag_InvalidEntity,
   AzXmlParseErrorTag_InvalidElement,
   AzXmlParseErrorTag_InvalidAttribute,
   AzXmlParseErrorTag_InvalidCdata,
   AzXmlParseErrorTag_InvalidCharData,
   AzXmlParseErrorTag_UnknownToken,
};
typedef enum AzXmlParseErrorTag AzXmlParseErrorTag;

struct AzXmlParseErrorVariant_InvalidDeclaration { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidDeclaration AzXmlParseErrorVariant_InvalidDeclaration;
struct AzXmlParseErrorVariant_InvalidComment { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidComment AzXmlParseErrorVariant_InvalidComment;
struct AzXmlParseErrorVariant_InvalidPI { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidPI AzXmlParseErrorVariant_InvalidPI;
struct AzXmlParseErrorVariant_InvalidDoctype { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidDoctype AzXmlParseErrorVariant_InvalidDoctype;
struct AzXmlParseErrorVariant_InvalidEntity { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidEntity AzXmlParseErrorVariant_InvalidEntity;
struct AzXmlParseErrorVariant_InvalidElement { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidElement AzXmlParseErrorVariant_InvalidElement;
struct AzXmlParseErrorVariant_InvalidAttribute { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidAttribute AzXmlParseErrorVariant_InvalidAttribute;
struct AzXmlParseErrorVariant_InvalidCdata { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidCdata AzXmlParseErrorVariant_InvalidCdata;
struct AzXmlParseErrorVariant_InvalidCharData { AzXmlParseErrorTag tag; AzXmlTextError payload; };
typedef struct AzXmlParseErrorVariant_InvalidCharData AzXmlParseErrorVariant_InvalidCharData;
struct AzXmlParseErrorVariant_UnknownToken { AzXmlParseErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlParseErrorVariant_UnknownToken AzXmlParseErrorVariant_UnknownToken;
union AzXmlParseError {
    AzXmlParseErrorVariant_InvalidDeclaration InvalidDeclaration;
    AzXmlParseErrorVariant_InvalidComment InvalidComment;
    AzXmlParseErrorVariant_InvalidPI InvalidPI;
    AzXmlParseErrorVariant_InvalidDoctype InvalidDoctype;
    AzXmlParseErrorVariant_InvalidEntity InvalidEntity;
    AzXmlParseErrorVariant_InvalidElement InvalidElement;
    AzXmlParseErrorVariant_InvalidAttribute InvalidAttribute;
    AzXmlParseErrorVariant_InvalidCdata InvalidCdata;
    AzXmlParseErrorVariant_InvalidCharData InvalidCharData;
    AzXmlParseErrorVariant_UnknownToken UnknownToken;
};
typedef union AzXmlParseError AzXmlParseError;

struct AzWindowCreateOptions {
    AzWindowState state;
    bool  size_to_content;
    AzOptionRendererOptions renderer_type;
    AzOptionWindowTheme theme;
    AzOptionCallback create_callback;
    bool  hot_reload;
};
typedef struct AzWindowCreateOptions AzWindowCreateOptions;

enum AzFocusTargetTag {
   AzFocusTargetTag_Id,
   AzFocusTargetTag_Path,
   AzFocusTargetTag_Previous,
   AzFocusTargetTag_Next,
   AzFocusTargetTag_First,
   AzFocusTargetTag_Last,
   AzFocusTargetTag_NoFocus,
};
typedef enum AzFocusTargetTag AzFocusTargetTag;

struct AzFocusTargetVariant_Id { AzFocusTargetTag tag; AzDomNodeId payload; };
typedef struct AzFocusTargetVariant_Id AzFocusTargetVariant_Id;
struct AzFocusTargetVariant_Path { AzFocusTargetTag tag; AzFocusTargetPath payload; };
typedef struct AzFocusTargetVariant_Path AzFocusTargetVariant_Path;
struct AzFocusTargetVariant_Previous { AzFocusTargetTag tag; };
typedef struct AzFocusTargetVariant_Previous AzFocusTargetVariant_Previous;
struct AzFocusTargetVariant_Next { AzFocusTargetTag tag; };
typedef struct AzFocusTargetVariant_Next AzFocusTargetVariant_Next;
struct AzFocusTargetVariant_First { AzFocusTargetTag tag; };
typedef struct AzFocusTargetVariant_First AzFocusTargetVariant_First;
struct AzFocusTargetVariant_Last { AzFocusTargetTag tag; };
typedef struct AzFocusTargetVariant_Last AzFocusTargetVariant_Last;
struct AzFocusTargetVariant_NoFocus { AzFocusTargetTag tag; };
typedef struct AzFocusTargetVariant_NoFocus AzFocusTargetVariant_NoFocus;
union AzFocusTarget {
    AzFocusTargetVariant_Id Id;
    AzFocusTargetVariant_Path Path;
    AzFocusTargetVariant_Previous Previous;
    AzFocusTargetVariant_Next Next;
    AzFocusTargetVariant_First First;
    AzFocusTargetVariant_Last Last;
    AzFocusTargetVariant_NoFocus NoFocus;
};
typedef union AzFocusTarget AzFocusTarget;

struct AzNodeData {
    AzNodeType node_type;
    AzOptionRefAny dataset;
    AzIdOrClassVec ids_and_classes;
    AzCallbackDataVec callbacks;
    AzNodeDataInlineCssPropertyVec inline_css_props;
    void* extra;
};
typedef struct AzNodeData AzNodeData;

enum AzCssDeclarationTag {
   AzCssDeclarationTag_Static,
   AzCssDeclarationTag_Dynamic,
};
typedef enum AzCssDeclarationTag AzCssDeclarationTag;

struct AzCssDeclarationVariant_Static { AzCssDeclarationTag tag; AzCssProperty payload; };
typedef struct AzCssDeclarationVariant_Static AzCssDeclarationVariant_Static;
struct AzCssDeclarationVariant_Dynamic { AzCssDeclarationTag tag; AzDynamicCssProperty payload; };
typedef struct AzCssDeclarationVariant_Dynamic AzCssDeclarationVariant_Dynamic;
union AzCssDeclaration {
    AzCssDeclarationVariant_Static Static;
    AzCssDeclarationVariant_Dynamic Dynamic;
};
typedef union AzCssDeclaration AzCssDeclaration;

struct AzButton {
    AzString label;
    AzOptionImageRef image;
    AzNodeDataInlineCssPropertyVec container_style;
    AzNodeDataInlineCssPropertyVec label_style;
    AzNodeDataInlineCssPropertyVec image_style;
    AzOptionButtonOnClick on_click;
};
typedef struct AzButton AzButton;

struct AzCheckBox {
    AzCheckBoxStateWrapper state;
    AzNodeDataInlineCssPropertyVec container_style;
    AzNodeDataInlineCssPropertyVec content_style;
};
typedef struct AzCheckBox AzCheckBox;

struct AzLabel {
    AzString text;
    AzNodeDataInlineCssPropertyVec style;
};
typedef struct AzLabel AzLabel;

struct AzColorInput {
    AzColorInputStateWrapper state;
    AzNodeDataInlineCssPropertyVec style;
};
typedef struct AzColorInput AzColorInput;

struct AzTextInput {
    AzTextInputStateWrapper state;
    AzNodeDataInlineCssPropertyVec placeholder_style;
    AzNodeDataInlineCssPropertyVec container_style;
    AzNodeDataInlineCssPropertyVec label_style;
};
typedef struct AzTextInput AzTextInput;

struct AzNumberInput {
    AzTextInput text_input;
    AzNumberInputStateWrapper state;
};
typedef struct AzNumberInput AzNumberInput;

struct AzCssDeclarationVec {
    AzCssDeclaration* ptr;
    size_t len;
    size_t cap;
    AzCssDeclarationVecDestructor destructor;
};
typedef struct AzCssDeclarationVec AzCssDeclarationVec;

struct AzNodeDataVec {
    AzNodeData* ptr;
    size_t len;
    size_t cap;
    AzNodeDataVecDestructor destructor;
};
typedef struct AzNodeDataVec AzNodeDataVec;

enum AzXmlErrorTag {
   AzXmlErrorTag_NoParserAvailable,
   AzXmlErrorTag_InvalidXmlPrefixUri,
   AzXmlErrorTag_UnexpectedXmlUri,
   AzXmlErrorTag_UnexpectedXmlnsUri,
   AzXmlErrorTag_InvalidElementNamePrefix,
   AzXmlErrorTag_DuplicatedNamespace,
   AzXmlErrorTag_UnknownNamespace,
   AzXmlErrorTag_UnexpectedCloseTag,
   AzXmlErrorTag_UnexpectedEntityCloseTag,
   AzXmlErrorTag_UnknownEntityReference,
   AzXmlErrorTag_MalformedEntityReference,
   AzXmlErrorTag_EntityReferenceLoop,
   AzXmlErrorTag_InvalidAttributeValue,
   AzXmlErrorTag_DuplicatedAttribute,
   AzXmlErrorTag_NoRootNode,
   AzXmlErrorTag_SizeLimit,
   AzXmlErrorTag_ParserError,
};
typedef enum AzXmlErrorTag AzXmlErrorTag;

struct AzXmlErrorVariant_NoParserAvailable { AzXmlErrorTag tag; };
typedef struct AzXmlErrorVariant_NoParserAvailable AzXmlErrorVariant_NoParserAvailable;
struct AzXmlErrorVariant_InvalidXmlPrefixUri { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_InvalidXmlPrefixUri AzXmlErrorVariant_InvalidXmlPrefixUri;
struct AzXmlErrorVariant_UnexpectedXmlUri { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_UnexpectedXmlUri AzXmlErrorVariant_UnexpectedXmlUri;
struct AzXmlErrorVariant_UnexpectedXmlnsUri { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_UnexpectedXmlnsUri AzXmlErrorVariant_UnexpectedXmlnsUri;
struct AzXmlErrorVariant_InvalidElementNamePrefix { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_InvalidElementNamePrefix AzXmlErrorVariant_InvalidElementNamePrefix;
struct AzXmlErrorVariant_DuplicatedNamespace { AzXmlErrorTag tag; AzDuplicatedNamespaceError payload; };
typedef struct AzXmlErrorVariant_DuplicatedNamespace AzXmlErrorVariant_DuplicatedNamespace;
struct AzXmlErrorVariant_UnknownNamespace { AzXmlErrorTag tag; AzUnknownNamespaceError payload; };
typedef struct AzXmlErrorVariant_UnknownNamespace AzXmlErrorVariant_UnknownNamespace;
struct AzXmlErrorVariant_UnexpectedCloseTag { AzXmlErrorTag tag; AzUnexpectedCloseTagError payload; };
typedef struct AzXmlErrorVariant_UnexpectedCloseTag AzXmlErrorVariant_UnexpectedCloseTag;
struct AzXmlErrorVariant_UnexpectedEntityCloseTag { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_UnexpectedEntityCloseTag AzXmlErrorVariant_UnexpectedEntityCloseTag;
struct AzXmlErrorVariant_UnknownEntityReference { AzXmlErrorTag tag; AzUnknownEntityReferenceError payload; };
typedef struct AzXmlErrorVariant_UnknownEntityReference AzXmlErrorVariant_UnknownEntityReference;
struct AzXmlErrorVariant_MalformedEntityReference { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_MalformedEntityReference AzXmlErrorVariant_MalformedEntityReference;
struct AzXmlErrorVariant_EntityReferenceLoop { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_EntityReferenceLoop AzXmlErrorVariant_EntityReferenceLoop;
struct AzXmlErrorVariant_InvalidAttributeValue { AzXmlErrorTag tag; AzSvgParseErrorPosition payload; };
typedef struct AzXmlErrorVariant_InvalidAttributeValue AzXmlErrorVariant_InvalidAttributeValue;
struct AzXmlErrorVariant_DuplicatedAttribute { AzXmlErrorTag tag; AzDuplicatedAttributeError payload; };
typedef struct AzXmlErrorVariant_DuplicatedAttribute AzXmlErrorVariant_DuplicatedAttribute;
struct AzXmlErrorVariant_NoRootNode { AzXmlErrorTag tag; };
typedef struct AzXmlErrorVariant_NoRootNode AzXmlErrorVariant_NoRootNode;
struct AzXmlErrorVariant_SizeLimit { AzXmlErrorTag tag; };
typedef struct AzXmlErrorVariant_SizeLimit AzXmlErrorVariant_SizeLimit;
struct AzXmlErrorVariant_ParserError { AzXmlErrorTag tag; AzXmlParseError payload; };
typedef struct AzXmlErrorVariant_ParserError AzXmlErrorVariant_ParserError;
union AzXmlError {
    AzXmlErrorVariant_NoParserAvailable NoParserAvailable;
    AzXmlErrorVariant_InvalidXmlPrefixUri InvalidXmlPrefixUri;
    AzXmlErrorVariant_UnexpectedXmlUri UnexpectedXmlUri;
    AzXmlErrorVariant_UnexpectedXmlnsUri UnexpectedXmlnsUri;
    AzXmlErrorVariant_InvalidElementNamePrefix InvalidElementNamePrefix;
    AzXmlErrorVariant_DuplicatedNamespace DuplicatedNamespace;
    AzXmlErrorVariant_UnknownNamespace UnknownNamespace;
    AzXmlErrorVariant_UnexpectedCloseTag UnexpectedCloseTag;
    AzXmlErrorVariant_UnexpectedEntityCloseTag UnexpectedEntityCloseTag;
    AzXmlErrorVariant_UnknownEntityReference UnknownEntityReference;
    AzXmlErrorVariant_MalformedEntityReference MalformedEntityReference;
    AzXmlErrorVariant_EntityReferenceLoop EntityReferenceLoop;
    AzXmlErrorVariant_InvalidAttributeValue InvalidAttributeValue;
    AzXmlErrorVariant_DuplicatedAttribute DuplicatedAttribute;
    AzXmlErrorVariant_NoRootNode NoRootNode;
    AzXmlErrorVariant_SizeLimit SizeLimit;
    AzXmlErrorVariant_ParserError ParserError;
};
typedef union AzXmlError AzXmlError;

struct AzDom {
    AzNodeData root;
    AzDomVec children;
    size_t total_children;
};
typedef struct AzDom AzDom;

struct AzCssRuleBlock {
    AzCssPath path;
    AzCssDeclarationVec declarations;
};
typedef struct AzCssRuleBlock AzCssRuleBlock;

struct AzStyledDom {
    AzNodeId root;
    AzNodeVec node_hierarchy;
    AzNodeDataVec node_data;
    AzStyledNodeVec styled_nodes;
    AzCascadeInfoVec cascade_info;
    AzNodeIdVec nodes_with_window_callbacks;
    AzNodeIdVec nodes_with_not_callbacks;
    AzNodeIdVec nodes_with_datasets_and_callbacks;
    AzTagIdToNodeIdMappingVec tag_ids_to_node_ids;
    AzParentWithNodeDepthVec non_leaf_nodes;
    AzCssPropertyCache css_property_cache;
};
typedef struct AzStyledDom AzStyledDom;

struct AzCssRuleBlockVec {
    AzCssRuleBlock* ptr;
    size_t len;
    size_t cap;
    AzCssRuleBlockVecDestructor destructor;
};
typedef struct AzCssRuleBlockVec AzCssRuleBlockVec;

enum AzOptionDomTag {
   AzOptionDomTag_None,
   AzOptionDomTag_Some,
};
typedef enum AzOptionDomTag AzOptionDomTag;

struct AzOptionDomVariant_None { AzOptionDomTag tag; };
typedef struct AzOptionDomVariant_None AzOptionDomVariant_None;
struct AzOptionDomVariant_Some { AzOptionDomTag tag; AzDom payload; };
typedef struct AzOptionDomVariant_Some AzOptionDomVariant_Some;
union AzOptionDom {
    AzOptionDomVariant_None None;
    AzOptionDomVariant_Some Some;
};
typedef union AzOptionDom AzOptionDom;

enum AzResultXmlXmlErrorTag {
   AzResultXmlXmlErrorTag_Ok,
   AzResultXmlXmlErrorTag_Err,
};
typedef enum AzResultXmlXmlErrorTag AzResultXmlXmlErrorTag;

struct AzResultXmlXmlErrorVariant_Ok { AzResultXmlXmlErrorTag tag; AzXml payload; };
typedef struct AzResultXmlXmlErrorVariant_Ok AzResultXmlXmlErrorVariant_Ok;
struct AzResultXmlXmlErrorVariant_Err { AzResultXmlXmlErrorTag tag; AzXmlError payload; };
typedef struct AzResultXmlXmlErrorVariant_Err AzResultXmlXmlErrorVariant_Err;
union AzResultXmlXmlError {
    AzResultXmlXmlErrorVariant_Ok Ok;
    AzResultXmlXmlErrorVariant_Err Err;
};
typedef union AzResultXmlXmlError AzResultXmlXmlError;

enum AzSvgParseErrorTag {
   AzSvgParseErrorTag_NoParserAvailable,
   AzSvgParseErrorTag_InvalidFileSuffix,
   AzSvgParseErrorTag_FileOpenFailed,
   AzSvgParseErrorTag_NotAnUtf8Str,
   AzSvgParseErrorTag_MalformedGZip,
   AzSvgParseErrorTag_InvalidSize,
   AzSvgParseErrorTag_ParsingFailed,
};
typedef enum AzSvgParseErrorTag AzSvgParseErrorTag;

struct AzSvgParseErrorVariant_NoParserAvailable { AzSvgParseErrorTag tag; };
typedef struct AzSvgParseErrorVariant_NoParserAvailable AzSvgParseErrorVariant_NoParserAvailable;
struct AzSvgParseErrorVariant_InvalidFileSuffix { AzSvgParseErrorTag tag; };
typedef struct AzSvgParseErrorVariant_InvalidFileSuffix AzSvgParseErrorVariant_InvalidFileSuffix;
struct AzSvgParseErrorVariant_FileOpenFailed { AzSvgParseErrorTag tag; };
typedef struct AzSvgParseErrorVariant_FileOpenFailed AzSvgParseErrorVariant_FileOpenFailed;
struct AzSvgParseErrorVariant_NotAnUtf8Str { AzSvgParseErrorTag tag; };
typedef struct AzSvgParseErrorVariant_NotAnUtf8Str AzSvgParseErrorVariant_NotAnUtf8Str;
struct AzSvgParseErrorVariant_MalformedGZip { AzSvgParseErrorTag tag; };
typedef struct AzSvgParseErrorVariant_MalformedGZip AzSvgParseErrorVariant_MalformedGZip;
struct AzSvgParseErrorVariant_InvalidSize { AzSvgParseErrorTag tag; };
typedef struct AzSvgParseErrorVariant_InvalidSize AzSvgParseErrorVariant_InvalidSize;
struct AzSvgParseErrorVariant_ParsingFailed { AzSvgParseErrorTag tag; AzXmlError payload; };
typedef struct AzSvgParseErrorVariant_ParsingFailed AzSvgParseErrorVariant_ParsingFailed;
union AzSvgParseError {
    AzSvgParseErrorVariant_NoParserAvailable NoParserAvailable;
    AzSvgParseErrorVariant_InvalidFileSuffix InvalidFileSuffix;
    AzSvgParseErrorVariant_FileOpenFailed FileOpenFailed;
    AzSvgParseErrorVariant_NotAnUtf8Str NotAnUtf8Str;
    AzSvgParseErrorVariant_MalformedGZip MalformedGZip;
    AzSvgParseErrorVariant_InvalidSize InvalidSize;
    AzSvgParseErrorVariant_ParsingFailed ParsingFailed;
};
typedef union AzSvgParseError AzSvgParseError;

struct AzIFrameCallbackReturn {
    AzStyledDom dom;
    AzLogicalSize scroll_size;
    AzLogicalPosition scroll_offset;
    AzLogicalSize virtual_scroll_size;
    AzLogicalPosition virtual_scroll_offset;
};
typedef struct AzIFrameCallbackReturn AzIFrameCallbackReturn;

struct AzStylesheet {
    AzCssRuleBlockVec rules;
};
typedef struct AzStylesheet AzStylesheet;

struct AzStylesheetVec {
    AzStylesheet* ptr;
    size_t len;
    size_t cap;
    AzStylesheetVecDestructor destructor;
};
typedef struct AzStylesheetVec AzStylesheetVec;

enum AzResultSvgXmlNodeSvgParseErrorTag {
   AzResultSvgXmlNodeSvgParseErrorTag_Ok,
   AzResultSvgXmlNodeSvgParseErrorTag_Err,
};
typedef enum AzResultSvgXmlNodeSvgParseErrorTag AzResultSvgXmlNodeSvgParseErrorTag;

struct AzResultSvgXmlNodeSvgParseErrorVariant_Ok { AzResultSvgXmlNodeSvgParseErrorTag tag; AzSvgXmlNode payload; };
typedef struct AzResultSvgXmlNodeSvgParseErrorVariant_Ok AzResultSvgXmlNodeSvgParseErrorVariant_Ok;
struct AzResultSvgXmlNodeSvgParseErrorVariant_Err { AzResultSvgXmlNodeSvgParseErrorTag tag; AzSvgParseError payload; };
typedef struct AzResultSvgXmlNodeSvgParseErrorVariant_Err AzResultSvgXmlNodeSvgParseErrorVariant_Err;
union AzResultSvgXmlNodeSvgParseError {
    AzResultSvgXmlNodeSvgParseErrorVariant_Ok Ok;
    AzResultSvgXmlNodeSvgParseErrorVariant_Err Err;
};
typedef union AzResultSvgXmlNodeSvgParseError AzResultSvgXmlNodeSvgParseError;

enum AzResultSvgSvgParseErrorTag {
   AzResultSvgSvgParseErrorTag_Ok,
   AzResultSvgSvgParseErrorTag_Err,
};
typedef enum AzResultSvgSvgParseErrorTag AzResultSvgSvgParseErrorTag;

struct AzResultSvgSvgParseErrorVariant_Ok { AzResultSvgSvgParseErrorTag tag; AzSvg payload; };
typedef struct AzResultSvgSvgParseErrorVariant_Ok AzResultSvgSvgParseErrorVariant_Ok;
struct AzResultSvgSvgParseErrorVariant_Err { AzResultSvgSvgParseErrorTag tag; AzSvgParseError payload; };
typedef struct AzResultSvgSvgParseErrorVariant_Err AzResultSvgSvgParseErrorVariant_Err;
union AzResultSvgSvgParseError {
    AzResultSvgSvgParseErrorVariant_Ok Ok;
    AzResultSvgSvgParseErrorVariant_Err Err;
};
typedef union AzResultSvgSvgParseError AzResultSvgSvgParseError;

struct AzCss {
    AzStylesheetVec stylesheets;
};
typedef struct AzCss AzCss;

#define AzAnimationRepeatCount_Times(v) { .Times = { .tag = AzAnimationRepeatCountTag_Times, .payload = v } }
#define AzAnimationRepeatCount_Infinite { .Infinite = { .tag = AzAnimationRepeatCountTag_Infinite } }
#define AzTabIndex_Auto { .Auto = { .tag = AzTabIndexTag_Auto } }
#define AzTabIndex_OverrideInParent(v) { .OverrideInParent = { .tag = AzTabIndexTag_OverrideInParent, .payload = v } }
#define AzTabIndex_NoKeyboardFocus { .NoKeyboardFocus = { .tag = AzTabIndexTag_NoKeyboardFocus } }
#define AzIndent_None { .None = { .tag = AzIndentTag_None } }
#define AzIndent_Spaces(v) { .Spaces = { .tag = AzIndentTag_Spaces, .payload = v } }
#define AzIndent_Tabs { .Tabs = { .tag = AzIndentTag_Tabs } }
#define AzSvgFitTo_Original { .Original = { .tag = AzSvgFitToTag_Original } }
#define AzSvgFitTo_Width(v) { .Width = { .tag = AzSvgFitToTag_Width, .payload = v } }
#define AzSvgFitTo_Height(v) { .Height = { .tag = AzSvgFitToTag_Height, .payload = v } }
#define AzSvgFitTo_Zoom(v) { .Zoom = { .tag = AzSvgFitToTag_Zoom, .payload = v } }
#define AzStyleFontFamilyVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStyleFontFamilyVecDestructorTag_DefaultRust } }
#define AzStyleFontFamilyVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStyleFontFamilyVecDestructorTag_NoDestructor } }
#define AzStyleFontFamilyVecDestructor_External(v) { .External = { .tag = AzStyleFontFamilyVecDestructorTag_External, .payload = v } }
#define AzAccessibilityStateVecDestructor_DefaultRust { .DefaultRust = { .tag = AzAccessibilityStateVecDestructorTag_DefaultRust } }
#define AzAccessibilityStateVecDestructor_NoDestructor { .NoDestructor = { .tag = AzAccessibilityStateVecDestructorTag_NoDestructor } }
#define AzAccessibilityStateVecDestructor_External(v) { .External = { .tag = AzAccessibilityStateVecDestructorTag_External, .payload = v } }
#define AzMenuItemVecDestructor_DefaultRust { .DefaultRust = { .tag = AzMenuItemVecDestructorTag_DefaultRust } }
#define AzMenuItemVecDestructor_NoDestructor { .NoDestructor = { .tag = AzMenuItemVecDestructorTag_NoDestructor } }
#define AzMenuItemVecDestructor_External(v) { .External = { .tag = AzMenuItemVecDestructorTag_External, .payload = v } }
#define AzTessellatedSvgNodeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzTessellatedSvgNodeVecDestructorTag_DefaultRust } }
#define AzTessellatedSvgNodeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzTessellatedSvgNodeVecDestructorTag_NoDestructor } }
#define AzTessellatedSvgNodeVecDestructor_External(v) { .External = { .tag = AzTessellatedSvgNodeVecDestructorTag_External, .payload = v } }
#define AzXmlNodeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzXmlNodeVecDestructorTag_DefaultRust } }
#define AzXmlNodeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzXmlNodeVecDestructorTag_NoDestructor } }
#define AzXmlNodeVecDestructor_External(v) { .External = { .tag = AzXmlNodeVecDestructorTag_External, .payload = v } }
#define AzFmtArgVecDestructor_DefaultRust { .DefaultRust = { .tag = AzFmtArgVecDestructorTag_DefaultRust } }
#define AzFmtArgVecDestructor_NoDestructor { .NoDestructor = { .tag = AzFmtArgVecDestructorTag_NoDestructor } }
#define AzFmtArgVecDestructor_External(v) { .External = { .tag = AzFmtArgVecDestructorTag_External, .payload = v } }
#define AzInlineLineVecDestructor_DefaultRust { .DefaultRust = { .tag = AzInlineLineVecDestructorTag_DefaultRust } }
#define AzInlineLineVecDestructor_NoDestructor { .NoDestructor = { .tag = AzInlineLineVecDestructorTag_NoDestructor } }
#define AzInlineLineVecDestructor_External(v) { .External = { .tag = AzInlineLineVecDestructorTag_External, .payload = v } }
#define AzInlineWordVecDestructor_DefaultRust { .DefaultRust = { .tag = AzInlineWordVecDestructorTag_DefaultRust } }
#define AzInlineWordVecDestructor_NoDestructor { .NoDestructor = { .tag = AzInlineWordVecDestructorTag_NoDestructor } }
#define AzInlineWordVecDestructor_External(v) { .External = { .tag = AzInlineWordVecDestructorTag_External, .payload = v } }
#define AzInlineGlyphVecDestructor_DefaultRust { .DefaultRust = { .tag = AzInlineGlyphVecDestructorTag_DefaultRust } }
#define AzInlineGlyphVecDestructor_NoDestructor { .NoDestructor = { .tag = AzInlineGlyphVecDestructorTag_NoDestructor } }
#define AzInlineGlyphVecDestructor_External(v) { .External = { .tag = AzInlineGlyphVecDestructorTag_External, .payload = v } }
#define AzInlineTextHitVecDestructor_DefaultRust { .DefaultRust = { .tag = AzInlineTextHitVecDestructorTag_DefaultRust } }
#define AzInlineTextHitVecDestructor_NoDestructor { .NoDestructor = { .tag = AzInlineTextHitVecDestructorTag_NoDestructor } }
#define AzInlineTextHitVecDestructor_External(v) { .External = { .tag = AzInlineTextHitVecDestructorTag_External, .payload = v } }
#define AzMonitorVecDestructor_DefaultRust { .DefaultRust = { .tag = AzMonitorVecDestructorTag_DefaultRust } }
#define AzMonitorVecDestructor_NoDestructor { .NoDestructor = { .tag = AzMonitorVecDestructorTag_NoDestructor } }
#define AzMonitorVecDestructor_External(v) { .External = { .tag = AzMonitorVecDestructorTag_External, .payload = v } }
#define AzVideoModeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzVideoModeVecDestructorTag_DefaultRust } }
#define AzVideoModeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzVideoModeVecDestructorTag_NoDestructor } }
#define AzVideoModeVecDestructor_External(v) { .External = { .tag = AzVideoModeVecDestructorTag_External, .payload = v } }
#define AzDomVecDestructor_DefaultRust { .DefaultRust = { .tag = AzDomVecDestructorTag_DefaultRust } }
#define AzDomVecDestructor_NoDestructor { .NoDestructor = { .tag = AzDomVecDestructorTag_NoDestructor } }
#define AzDomVecDestructor_External(v) { .External = { .tag = AzDomVecDestructorTag_External, .payload = v } }
#define AzIdOrClassVecDestructor_DefaultRust { .DefaultRust = { .tag = AzIdOrClassVecDestructorTag_DefaultRust } }
#define AzIdOrClassVecDestructor_NoDestructor { .NoDestructor = { .tag = AzIdOrClassVecDestructorTag_NoDestructor } }
#define AzIdOrClassVecDestructor_External(v) { .External = { .tag = AzIdOrClassVecDestructorTag_External, .payload = v } }
#define AzNodeDataInlineCssPropertyVecDestructor_DefaultRust { .DefaultRust = { .tag = AzNodeDataInlineCssPropertyVecDestructorTag_DefaultRust } }
#define AzNodeDataInlineCssPropertyVecDestructor_NoDestructor { .NoDestructor = { .tag = AzNodeDataInlineCssPropertyVecDestructorTag_NoDestructor } }
#define AzNodeDataInlineCssPropertyVecDestructor_External(v) { .External = { .tag = AzNodeDataInlineCssPropertyVecDestructorTag_External, .payload = v } }
#define AzStyleBackgroundContentVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStyleBackgroundContentVecDestructorTag_DefaultRust } }
#define AzStyleBackgroundContentVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStyleBackgroundContentVecDestructorTag_NoDestructor } }
#define AzStyleBackgroundContentVecDestructor_External(v) { .External = { .tag = AzStyleBackgroundContentVecDestructorTag_External, .payload = v } }
#define AzStyleBackgroundPositionVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStyleBackgroundPositionVecDestructorTag_DefaultRust } }
#define AzStyleBackgroundPositionVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStyleBackgroundPositionVecDestructorTag_NoDestructor } }
#define AzStyleBackgroundPositionVecDestructor_External(v) { .External = { .tag = AzStyleBackgroundPositionVecDestructorTag_External, .payload = v } }
#define AzStyleBackgroundRepeatVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStyleBackgroundRepeatVecDestructorTag_DefaultRust } }
#define AzStyleBackgroundRepeatVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStyleBackgroundRepeatVecDestructorTag_NoDestructor } }
#define AzStyleBackgroundRepeatVecDestructor_External(v) { .External = { .tag = AzStyleBackgroundRepeatVecDestructorTag_External, .payload = v } }
#define AzStyleBackgroundSizeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStyleBackgroundSizeVecDestructorTag_DefaultRust } }
#define AzStyleBackgroundSizeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStyleBackgroundSizeVecDestructorTag_NoDestructor } }
#define AzStyleBackgroundSizeVecDestructor_External(v) { .External = { .tag = AzStyleBackgroundSizeVecDestructorTag_External, .payload = v } }
#define AzStyleTransformVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStyleTransformVecDestructorTag_DefaultRust } }
#define AzStyleTransformVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStyleTransformVecDestructorTag_NoDestructor } }
#define AzStyleTransformVecDestructor_External(v) { .External = { .tag = AzStyleTransformVecDestructorTag_External, .payload = v } }
#define AzCssPropertyVecDestructor_DefaultRust { .DefaultRust = { .tag = AzCssPropertyVecDestructorTag_DefaultRust } }
#define AzCssPropertyVecDestructor_NoDestructor { .NoDestructor = { .tag = AzCssPropertyVecDestructorTag_NoDestructor } }
#define AzCssPropertyVecDestructor_External(v) { .External = { .tag = AzCssPropertyVecDestructorTag_External, .payload = v } }
#define AzSvgMultiPolygonVecDestructor_DefaultRust { .DefaultRust = { .tag = AzSvgMultiPolygonVecDestructorTag_DefaultRust } }
#define AzSvgMultiPolygonVecDestructor_NoDestructor { .NoDestructor = { .tag = AzSvgMultiPolygonVecDestructorTag_NoDestructor } }
#define AzSvgMultiPolygonVecDestructor_External(v) { .External = { .tag = AzSvgMultiPolygonVecDestructorTag_External, .payload = v } }
#define AzSvgPathVecDestructor_DefaultRust { .DefaultRust = { .tag = AzSvgPathVecDestructorTag_DefaultRust } }
#define AzSvgPathVecDestructor_NoDestructor { .NoDestructor = { .tag = AzSvgPathVecDestructorTag_NoDestructor } }
#define AzSvgPathVecDestructor_External(v) { .External = { .tag = AzSvgPathVecDestructorTag_External, .payload = v } }
#define AzVertexAttributeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzVertexAttributeVecDestructorTag_DefaultRust } }
#define AzVertexAttributeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzVertexAttributeVecDestructorTag_NoDestructor } }
#define AzVertexAttributeVecDestructor_External(v) { .External = { .tag = AzVertexAttributeVecDestructorTag_External, .payload = v } }
#define AzSvgPathElementVecDestructor_DefaultRust { .DefaultRust = { .tag = AzSvgPathElementVecDestructorTag_DefaultRust } }
#define AzSvgPathElementVecDestructor_NoDestructor { .NoDestructor = { .tag = AzSvgPathElementVecDestructorTag_NoDestructor } }
#define AzSvgPathElementVecDestructor_External(v) { .External = { .tag = AzSvgPathElementVecDestructorTag_External, .payload = v } }
#define AzSvgVertexVecDestructor_DefaultRust { .DefaultRust = { .tag = AzSvgVertexVecDestructorTag_DefaultRust } }
#define AzSvgVertexVecDestructor_NoDestructor { .NoDestructor = { .tag = AzSvgVertexVecDestructorTag_NoDestructor } }
#define AzSvgVertexVecDestructor_External(v) { .External = { .tag = AzSvgVertexVecDestructorTag_External, .payload = v } }
#define AzU32VecDestructor_DefaultRust { .DefaultRust = { .tag = AzU32VecDestructorTag_DefaultRust } }
#define AzU32VecDestructor_NoDestructor { .NoDestructor = { .tag = AzU32VecDestructorTag_NoDestructor } }
#define AzU32VecDestructor_External(v) { .External = { .tag = AzU32VecDestructorTag_External, .payload = v } }
#define AzXWindowTypeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzXWindowTypeVecDestructorTag_DefaultRust } }
#define AzXWindowTypeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzXWindowTypeVecDestructorTag_NoDestructor } }
#define AzXWindowTypeVecDestructor_External(v) { .External = { .tag = AzXWindowTypeVecDestructorTag_External, .payload = v } }
#define AzVirtualKeyCodeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzVirtualKeyCodeVecDestructorTag_DefaultRust } }
#define AzVirtualKeyCodeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzVirtualKeyCodeVecDestructorTag_NoDestructor } }
#define AzVirtualKeyCodeVecDestructor_External(v) { .External = { .tag = AzVirtualKeyCodeVecDestructorTag_External, .payload = v } }
#define AzCascadeInfoVecDestructor_DefaultRust { .DefaultRust = { .tag = AzCascadeInfoVecDestructorTag_DefaultRust } }
#define AzCascadeInfoVecDestructor_NoDestructor { .NoDestructor = { .tag = AzCascadeInfoVecDestructorTag_NoDestructor } }
#define AzCascadeInfoVecDestructor_External(v) { .External = { .tag = AzCascadeInfoVecDestructorTag_External, .payload = v } }
#define AzScanCodeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzScanCodeVecDestructorTag_DefaultRust } }
#define AzScanCodeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzScanCodeVecDestructorTag_NoDestructor } }
#define AzScanCodeVecDestructor_External(v) { .External = { .tag = AzScanCodeVecDestructorTag_External, .payload = v } }
#define AzCssDeclarationVecDestructor_DefaultRust { .DefaultRust = { .tag = AzCssDeclarationVecDestructorTag_DefaultRust } }
#define AzCssDeclarationVecDestructor_NoDestructor { .NoDestructor = { .tag = AzCssDeclarationVecDestructorTag_NoDestructor } }
#define AzCssDeclarationVecDestructor_External(v) { .External = { .tag = AzCssDeclarationVecDestructorTag_External, .payload = v } }
#define AzCssPathSelectorVecDestructor_DefaultRust { .DefaultRust = { .tag = AzCssPathSelectorVecDestructorTag_DefaultRust } }
#define AzCssPathSelectorVecDestructor_NoDestructor { .NoDestructor = { .tag = AzCssPathSelectorVecDestructorTag_NoDestructor } }
#define AzCssPathSelectorVecDestructor_External(v) { .External = { .tag = AzCssPathSelectorVecDestructorTag_External, .payload = v } }
#define AzStylesheetVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStylesheetVecDestructorTag_DefaultRust } }
#define AzStylesheetVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStylesheetVecDestructorTag_NoDestructor } }
#define AzStylesheetVecDestructor_External(v) { .External = { .tag = AzStylesheetVecDestructorTag_External, .payload = v } }
#define AzCssRuleBlockVecDestructor_DefaultRust { .DefaultRust = { .tag = AzCssRuleBlockVecDestructorTag_DefaultRust } }
#define AzCssRuleBlockVecDestructor_NoDestructor { .NoDestructor = { .tag = AzCssRuleBlockVecDestructorTag_NoDestructor } }
#define AzCssRuleBlockVecDestructor_External(v) { .External = { .tag = AzCssRuleBlockVecDestructorTag_External, .payload = v } }
#define AzF32VecDestructor_DefaultRust { .DefaultRust = { .tag = AzF32VecDestructorTag_DefaultRust } }
#define AzF32VecDestructor_NoDestructor { .NoDestructor = { .tag = AzF32VecDestructorTag_NoDestructor } }
#define AzF32VecDestructor_External(v) { .External = { .tag = AzF32VecDestructorTag_External, .payload = v } }
#define AzU16VecDestructor_DefaultRust { .DefaultRust = { .tag = AzU16VecDestructorTag_DefaultRust } }
#define AzU16VecDestructor_NoDestructor { .NoDestructor = { .tag = AzU16VecDestructorTag_NoDestructor } }
#define AzU16VecDestructor_External(v) { .External = { .tag = AzU16VecDestructorTag_External, .payload = v } }
#define AzU8VecDestructor_DefaultRust { .DefaultRust = { .tag = AzU8VecDestructorTag_DefaultRust } }
#define AzU8VecDestructor_NoDestructor { .NoDestructor = { .tag = AzU8VecDestructorTag_NoDestructor } }
#define AzU8VecDestructor_External(v) { .External = { .tag = AzU8VecDestructorTag_External, .payload = v } }
#define AzCallbackDataVecDestructor_DefaultRust { .DefaultRust = { .tag = AzCallbackDataVecDestructorTag_DefaultRust } }
#define AzCallbackDataVecDestructor_NoDestructor { .NoDestructor = { .tag = AzCallbackDataVecDestructorTag_NoDestructor } }
#define AzCallbackDataVecDestructor_External(v) { .External = { .tag = AzCallbackDataVecDestructorTag_External, .payload = v } }
#define AzDebugMessageVecDestructor_DefaultRust { .DefaultRust = { .tag = AzDebugMessageVecDestructorTag_DefaultRust } }
#define AzDebugMessageVecDestructor_NoDestructor { .NoDestructor = { .tag = AzDebugMessageVecDestructorTag_NoDestructor } }
#define AzDebugMessageVecDestructor_External(v) { .External = { .tag = AzDebugMessageVecDestructorTag_External, .payload = v } }
#define AzGLuintVecDestructor_DefaultRust { .DefaultRust = { .tag = AzGLuintVecDestructorTag_DefaultRust } }
#define AzGLuintVecDestructor_NoDestructor { .NoDestructor = { .tag = AzGLuintVecDestructorTag_NoDestructor } }
#define AzGLuintVecDestructor_External(v) { .External = { .tag = AzGLuintVecDestructorTag_External, .payload = v } }
#define AzGLintVecDestructor_DefaultRust { .DefaultRust = { .tag = AzGLintVecDestructorTag_DefaultRust } }
#define AzGLintVecDestructor_NoDestructor { .NoDestructor = { .tag = AzGLintVecDestructorTag_NoDestructor } }
#define AzGLintVecDestructor_External(v) { .External = { .tag = AzGLintVecDestructorTag_External, .payload = v } }
#define AzStringVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStringVecDestructorTag_DefaultRust } }
#define AzStringVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStringVecDestructorTag_NoDestructor } }
#define AzStringVecDestructor_External(v) { .External = { .tag = AzStringVecDestructorTag_External, .payload = v } }
#define AzStringPairVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStringPairVecDestructorTag_DefaultRust } }
#define AzStringPairVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStringPairVecDestructorTag_NoDestructor } }
#define AzStringPairVecDestructor_External(v) { .External = { .tag = AzStringPairVecDestructorTag_External, .payload = v } }
#define AzNormalizedLinearColorStopVecDestructor_DefaultRust { .DefaultRust = { .tag = AzNormalizedLinearColorStopVecDestructorTag_DefaultRust } }
#define AzNormalizedLinearColorStopVecDestructor_NoDestructor { .NoDestructor = { .tag = AzNormalizedLinearColorStopVecDestructorTag_NoDestructor } }
#define AzNormalizedLinearColorStopVecDestructor_External(v) { .External = { .tag = AzNormalizedLinearColorStopVecDestructorTag_External, .payload = v } }
#define AzNormalizedRadialColorStopVecDestructor_DefaultRust { .DefaultRust = { .tag = AzNormalizedRadialColorStopVecDestructorTag_DefaultRust } }
#define AzNormalizedRadialColorStopVecDestructor_NoDestructor { .NoDestructor = { .tag = AzNormalizedRadialColorStopVecDestructorTag_NoDestructor } }
#define AzNormalizedRadialColorStopVecDestructor_External(v) { .External = { .tag = AzNormalizedRadialColorStopVecDestructorTag_External, .payload = v } }
#define AzNodeIdVecDestructor_DefaultRust { .DefaultRust = { .tag = AzNodeIdVecDestructorTag_DefaultRust } }
#define AzNodeIdVecDestructor_NoDestructor { .NoDestructor = { .tag = AzNodeIdVecDestructorTag_NoDestructor } }
#define AzNodeIdVecDestructor_External(v) { .External = { .tag = AzNodeIdVecDestructorTag_External, .payload = v } }
#define AzNodeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzNodeVecDestructorTag_DefaultRust } }
#define AzNodeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzNodeVecDestructorTag_NoDestructor } }
#define AzNodeVecDestructor_External(v) { .External = { .tag = AzNodeVecDestructorTag_External, .payload = v } }
#define AzStyledNodeVecDestructor_DefaultRust { .DefaultRust = { .tag = AzStyledNodeVecDestructorTag_DefaultRust } }
#define AzStyledNodeVecDestructor_NoDestructor { .NoDestructor = { .tag = AzStyledNodeVecDestructorTag_NoDestructor } }
#define AzStyledNodeVecDestructor_External(v) { .External = { .tag = AzStyledNodeVecDestructorTag_External, .payload = v } }
#define AzTagIdToNodeIdMappingVecDestructor_DefaultRust { .DefaultRust = { .tag = AzTagIdToNodeIdMappingVecDestructorTag_DefaultRust } }
#define AzTagIdToNodeIdMappingVecDestructor_NoDestructor { .NoDestructor = { .tag = AzTagIdToNodeIdMappingVecDestructorTag_NoDestructor } }
#define AzTagIdToNodeIdMappingVecDestructor_External(v) { .External = { .tag = AzTagIdToNodeIdMappingVecDestructorTag_External, .payload = v } }
#define AzParentWithNodeDepthVecDestructor_DefaultRust { .DefaultRust = { .tag = AzParentWithNodeDepthVecDestructorTag_DefaultRust } }
#define AzParentWithNodeDepthVecDestructor_NoDestructor { .NoDestructor = { .tag = AzParentWithNodeDepthVecDestructorTag_NoDestructor } }
#define AzParentWithNodeDepthVecDestructor_External(v) { .External = { .tag = AzParentWithNodeDepthVecDestructorTag_External, .payload = v } }
#define AzNodeDataVecDestructor_DefaultRust { .DefaultRust = { .tag = AzNodeDataVecDestructorTag_DefaultRust } }
#define AzNodeDataVecDestructor_NoDestructor { .NoDestructor = { .tag = AzNodeDataVecDestructorTag_NoDestructor } }
#define AzNodeDataVecDestructor_External(v) { .External = { .tag = AzNodeDataVecDestructorTag_External, .payload = v } }
#define AzOptionI16_None { .None = { .tag = AzOptionI16Tag_None } }
#define AzOptionI16_Some(v) { .Some = { .tag = AzOptionI16Tag_Some, .payload = v } }
#define AzOptionU16_None { .None = { .tag = AzOptionU16Tag_None } }
#define AzOptionU16_Some(v) { .Some = { .tag = AzOptionU16Tag_Some, .payload = v } }
#define AzOptionU32_None { .None = { .tag = AzOptionU32Tag_None } }
#define AzOptionU32_Some(v) { .Some = { .tag = AzOptionU32Tag_Some, .payload = v } }
#define AzOptionHwndHandle_None { .None = { .tag = AzOptionHwndHandleTag_None } }
#define AzOptionHwndHandle_Some(v) { .Some = { .tag = AzOptionHwndHandleTag_Some, .payload = v } }
#define AzOptionX11Visual_None { .None = { .tag = AzOptionX11VisualTag_None } }
#define AzOptionX11Visual_Some(v) { .Some = { .tag = AzOptionX11VisualTag_Some, .payload = v } }
#define AzOptionI32_None { .None = { .tag = AzOptionI32Tag_None } }
#define AzOptionI32_Some(v) { .Some = { .tag = AzOptionI32Tag_Some, .payload = v } }
#define AzOptionF32_None { .None = { .tag = AzOptionF32Tag_None } }
#define AzOptionF32_Some(v) { .Some = { .tag = AzOptionF32Tag_Some, .payload = v } }
#define AzOptionChar_None { .None = { .tag = AzOptionCharTag_None } }
#define AzOptionChar_Some(v) { .Some = { .tag = AzOptionCharTag_Some, .payload = v } }
#define AzOptionUsize_None { .None = { .tag = AzOptionUsizeTag_None } }
#define AzOptionUsize_Some(v) { .Some = { .tag = AzOptionUsizeTag_Some, .payload = v } }
#define AzRawWindowHandle_IOS(v) { .IOS = { .tag = AzRawWindowHandleTag_IOS, .payload = v } }
#define AzRawWindowHandle_MacOS(v) { .MacOS = { .tag = AzRawWindowHandleTag_MacOS, .payload = v } }
#define AzRawWindowHandle_Xlib(v) { .Xlib = { .tag = AzRawWindowHandleTag_Xlib, .payload = v } }
#define AzRawWindowHandle_Xcb(v) { .Xcb = { .tag = AzRawWindowHandleTag_Xcb, .payload = v } }
#define AzRawWindowHandle_Wayland(v) { .Wayland = { .tag = AzRawWindowHandleTag_Wayland, .payload = v } }
#define AzRawWindowHandle_Windows(v) { .Windows = { .tag = AzRawWindowHandleTag_Windows, .payload = v } }
#define AzRawWindowHandle_Web(v) { .Web = { .tag = AzRawWindowHandleTag_Web, .payload = v } }
#define AzRawWindowHandle_Android(v) { .Android = { .tag = AzRawWindowHandleTag_Android, .payload = v } }
#define AzRawWindowHandle_Unsupported { .Unsupported = { .tag = AzRawWindowHandleTag_Unsupported } }
#define AzAcceleratorKey_Ctrl { .Ctrl = { .tag = AzAcceleratorKeyTag_Ctrl } }
#define AzAcceleratorKey_Alt { .Alt = { .tag = AzAcceleratorKeyTag_Alt } }
#define AzAcceleratorKey_Shift { .Shift = { .tag = AzAcceleratorKeyTag_Shift } }
#define AzAcceleratorKey_Key(v) { .Key = { .tag = AzAcceleratorKeyTag_Key, .payload = v } }
#define AzCursorPosition_OutOfWindow { .OutOfWindow = { .tag = AzCursorPositionTag_OutOfWindow } }
#define AzCursorPosition_Uninitialized { .Uninitialized = { .tag = AzCursorPositionTag_Uninitialized } }
#define AzCursorPosition_InWindow(v) { .InWindow = { .tag = AzCursorPositionTag_InWindow, .payload = v } }
#define AzWindowPosition_Uninitialized { .Uninitialized = { .tag = AzWindowPositionTag_Uninitialized } }
#define AzWindowPosition_Initialized(v) { .Initialized = { .tag = AzWindowPositionTag_Initialized, .payload = v } }
#define AzImePosition_Uninitialized { .Uninitialized = { .tag = AzImePositionTag_Uninitialized } }
#define AzImePosition_Initialized(v) { .Initialized = { .tag = AzImePositionTag_Initialized, .payload = v } }
#define AzPositionInfo_Static(v) { .Static = { .tag = AzPositionInfoTag_Static, .payload = v } }
#define AzPositionInfo_Fixed(v) { .Fixed = { .tag = AzPositionInfoTag_Fixed, .payload = v } }
#define AzPositionInfo_Absolute(v) { .Absolute = { .tag = AzPositionInfoTag_Absolute, .payload = v } }
#define AzPositionInfo_Relative(v) { .Relative = { .tag = AzPositionInfoTag_Relative, .payload = v } }
#define AzNotEventFilter_Hover(v) { .Hover = { .tag = AzNotEventFilterTag_Hover, .payload = v } }
#define AzNotEventFilter_Focus(v) { .Focus = { .tag = AzNotEventFilterTag_Focus, .payload = v } }
#define AzMenuItemIcon_Checkbox(v) { .Checkbox = { .tag = AzMenuItemIconTag_Checkbox, .payload = v } }
#define AzMenuItemIcon_Image(v) { .Image = { .tag = AzMenuItemIconTag_Image, .payload = v } }
#define AzCssNthChildSelector_Number(v) { .Number = { .tag = AzCssNthChildSelectorTag_Number, .payload = v } }
#define AzCssNthChildSelector_Even { .Even = { .tag = AzCssNthChildSelectorTag_Even } }
#define AzCssNthChildSelector_Odd { .Odd = { .tag = AzCssNthChildSelectorTag_Odd } }
#define AzCssNthChildSelector_Pattern(v) { .Pattern = { .tag = AzCssNthChildSelectorTag_Pattern, .payload = v } }
#define AzDirection_Angle(v) { .Angle = { .tag = AzDirectionTag_Angle, .payload = v } }
#define AzDirection_FromTo(v) { .FromTo = { .tag = AzDirectionTag_FromTo, .payload = v } }
#define AzBackgroundPositionHorizontal_Left { .Left = { .tag = AzBackgroundPositionHorizontalTag_Left } }
#define AzBackgroundPositionHorizontal_Center { .Center = { .tag = AzBackgroundPositionHorizontalTag_Center } }
#define AzBackgroundPositionHorizontal_Right { .Right = { .tag = AzBackgroundPositionHorizontalTag_Right } }
#define AzBackgroundPositionHorizontal_Exact(v) { .Exact = { .tag = AzBackgroundPositionHorizontalTag_Exact, .payload = v } }
#define AzBackgroundPositionVertical_Top { .Top = { .tag = AzBackgroundPositionVerticalTag_Top } }
#define AzBackgroundPositionVertical_Center { .Center = { .tag = AzBackgroundPositionVerticalTag_Center } }
#define AzBackgroundPositionVertical_Bottom { .Bottom = { .tag = AzBackgroundPositionVerticalTag_Bottom } }
#define AzBackgroundPositionVertical_Exact(v) { .Exact = { .tag = AzBackgroundPositionVerticalTag_Exact, .payload = v } }
#define AzStyleBackgroundSize_ExactSize(v) { .ExactSize = { .tag = AzStyleBackgroundSizeTag_ExactSize, .payload = v } }
#define AzStyleBackgroundSize_Contain { .Contain = { .tag = AzStyleBackgroundSizeTag_Contain } }
#define AzStyleBackgroundSize_Cover { .Cover = { .tag = AzStyleBackgroundSizeTag_Cover } }
#define AzStyleBoxShadowValue_Auto { .Auto = { .tag = AzStyleBoxShadowValueTag_Auto } }
#define AzStyleBoxShadowValue_None { .None = { .tag = AzStyleBoxShadowValueTag_None } }
#define AzStyleBoxShadowValue_Inherit { .Inherit = { .tag = AzStyleBoxShadowValueTag_Inherit } }
#define AzStyleBoxShadowValue_Initial { .Initial = { .tag = AzStyleBoxShadowValueTag_Initial } }
#define AzStyleBoxShadowValue_Exact(v) { .Exact = { .tag = AzStyleBoxShadowValueTag_Exact, .payload = v } }
#define AzLayoutAlignContentValue_Auto { .Auto = { .tag = AzLayoutAlignContentValueTag_Auto } }
#define AzLayoutAlignContentValue_None { .None = { .tag = AzLayoutAlignContentValueTag_None } }
#define AzLayoutAlignContentValue_Inherit { .Inherit = { .tag = AzLayoutAlignContentValueTag_Inherit } }
#define AzLayoutAlignContentValue_Initial { .Initial = { .tag = AzLayoutAlignContentValueTag_Initial } }
#define AzLayoutAlignContentValue_Exact(v) { .Exact = { .tag = AzLayoutAlignContentValueTag_Exact, .payload = v } }
#define AzLayoutAlignItemsValue_Auto { .Auto = { .tag = AzLayoutAlignItemsValueTag_Auto } }
#define AzLayoutAlignItemsValue_None { .None = { .tag = AzLayoutAlignItemsValueTag_None } }
#define AzLayoutAlignItemsValue_Inherit { .Inherit = { .tag = AzLayoutAlignItemsValueTag_Inherit } }
#define AzLayoutAlignItemsValue_Initial { .Initial = { .tag = AzLayoutAlignItemsValueTag_Initial } }
#define AzLayoutAlignItemsValue_Exact(v) { .Exact = { .tag = AzLayoutAlignItemsValueTag_Exact, .payload = v } }
#define AzLayoutBottomValue_Auto { .Auto = { .tag = AzLayoutBottomValueTag_Auto } }
#define AzLayoutBottomValue_None { .None = { .tag = AzLayoutBottomValueTag_None } }
#define AzLayoutBottomValue_Inherit { .Inherit = { .tag = AzLayoutBottomValueTag_Inherit } }
#define AzLayoutBottomValue_Initial { .Initial = { .tag = AzLayoutBottomValueTag_Initial } }
#define AzLayoutBottomValue_Exact(v) { .Exact = { .tag = AzLayoutBottomValueTag_Exact, .payload = v } }
#define AzLayoutBoxSizingValue_Auto { .Auto = { .tag = AzLayoutBoxSizingValueTag_Auto } }
#define AzLayoutBoxSizingValue_None { .None = { .tag = AzLayoutBoxSizingValueTag_None } }
#define AzLayoutBoxSizingValue_Inherit { .Inherit = { .tag = AzLayoutBoxSizingValueTag_Inherit } }
#define AzLayoutBoxSizingValue_Initial { .Initial = { .tag = AzLayoutBoxSizingValueTag_Initial } }
#define AzLayoutBoxSizingValue_Exact(v) { .Exact = { .tag = AzLayoutBoxSizingValueTag_Exact, .payload = v } }
#define AzLayoutFlexDirectionValue_Auto { .Auto = { .tag = AzLayoutFlexDirectionValueTag_Auto } }
#define AzLayoutFlexDirectionValue_None { .None = { .tag = AzLayoutFlexDirectionValueTag_None } }
#define AzLayoutFlexDirectionValue_Inherit { .Inherit = { .tag = AzLayoutFlexDirectionValueTag_Inherit } }
#define AzLayoutFlexDirectionValue_Initial { .Initial = { .tag = AzLayoutFlexDirectionValueTag_Initial } }
#define AzLayoutFlexDirectionValue_Exact(v) { .Exact = { .tag = AzLayoutFlexDirectionValueTag_Exact, .payload = v } }
#define AzLayoutDisplayValue_Auto { .Auto = { .tag = AzLayoutDisplayValueTag_Auto } }
#define AzLayoutDisplayValue_None { .None = { .tag = AzLayoutDisplayValueTag_None } }
#define AzLayoutDisplayValue_Inherit { .Inherit = { .tag = AzLayoutDisplayValueTag_Inherit } }
#define AzLayoutDisplayValue_Initial { .Initial = { .tag = AzLayoutDisplayValueTag_Initial } }
#define AzLayoutDisplayValue_Exact(v) { .Exact = { .tag = AzLayoutDisplayValueTag_Exact, .payload = v } }
#define AzLayoutFlexGrowValue_Auto { .Auto = { .tag = AzLayoutFlexGrowValueTag_Auto } }
#define AzLayoutFlexGrowValue_None { .None = { .tag = AzLayoutFlexGrowValueTag_None } }
#define AzLayoutFlexGrowValue_Inherit { .Inherit = { .tag = AzLayoutFlexGrowValueTag_Inherit } }
#define AzLayoutFlexGrowValue_Initial { .Initial = { .tag = AzLayoutFlexGrowValueTag_Initial } }
#define AzLayoutFlexGrowValue_Exact(v) { .Exact = { .tag = AzLayoutFlexGrowValueTag_Exact, .payload = v } }
#define AzLayoutFlexShrinkValue_Auto { .Auto = { .tag = AzLayoutFlexShrinkValueTag_Auto } }
#define AzLayoutFlexShrinkValue_None { .None = { .tag = AzLayoutFlexShrinkValueTag_None } }
#define AzLayoutFlexShrinkValue_Inherit { .Inherit = { .tag = AzLayoutFlexShrinkValueTag_Inherit } }
#define AzLayoutFlexShrinkValue_Initial { .Initial = { .tag = AzLayoutFlexShrinkValueTag_Initial } }
#define AzLayoutFlexShrinkValue_Exact(v) { .Exact = { .tag = AzLayoutFlexShrinkValueTag_Exact, .payload = v } }
#define AzLayoutFloatValue_Auto { .Auto = { .tag = AzLayoutFloatValueTag_Auto } }
#define AzLayoutFloatValue_None { .None = { .tag = AzLayoutFloatValueTag_None } }
#define AzLayoutFloatValue_Inherit { .Inherit = { .tag = AzLayoutFloatValueTag_Inherit } }
#define AzLayoutFloatValue_Initial { .Initial = { .tag = AzLayoutFloatValueTag_Initial } }
#define AzLayoutFloatValue_Exact(v) { .Exact = { .tag = AzLayoutFloatValueTag_Exact, .payload = v } }
#define AzLayoutHeightValue_Auto { .Auto = { .tag = AzLayoutHeightValueTag_Auto } }
#define AzLayoutHeightValue_None { .None = { .tag = AzLayoutHeightValueTag_None } }
#define AzLayoutHeightValue_Inherit { .Inherit = { .tag = AzLayoutHeightValueTag_Inherit } }
#define AzLayoutHeightValue_Initial { .Initial = { .tag = AzLayoutHeightValueTag_Initial } }
#define AzLayoutHeightValue_Exact(v) { .Exact = { .tag = AzLayoutHeightValueTag_Exact, .payload = v } }
#define AzLayoutJustifyContentValue_Auto { .Auto = { .tag = AzLayoutJustifyContentValueTag_Auto } }
#define AzLayoutJustifyContentValue_None { .None = { .tag = AzLayoutJustifyContentValueTag_None } }
#define AzLayoutJustifyContentValue_Inherit { .Inherit = { .tag = AzLayoutJustifyContentValueTag_Inherit } }
#define AzLayoutJustifyContentValue_Initial { .Initial = { .tag = AzLayoutJustifyContentValueTag_Initial } }
#define AzLayoutJustifyContentValue_Exact(v) { .Exact = { .tag = AzLayoutJustifyContentValueTag_Exact, .payload = v } }
#define AzLayoutLeftValue_Auto { .Auto = { .tag = AzLayoutLeftValueTag_Auto } }
#define AzLayoutLeftValue_None { .None = { .tag = AzLayoutLeftValueTag_None } }
#define AzLayoutLeftValue_Inherit { .Inherit = { .tag = AzLayoutLeftValueTag_Inherit } }
#define AzLayoutLeftValue_Initial { .Initial = { .tag = AzLayoutLeftValueTag_Initial } }
#define AzLayoutLeftValue_Exact(v) { .Exact = { .tag = AzLayoutLeftValueTag_Exact, .payload = v } }
#define AzLayoutMarginBottomValue_Auto { .Auto = { .tag = AzLayoutMarginBottomValueTag_Auto } }
#define AzLayoutMarginBottomValue_None { .None = { .tag = AzLayoutMarginBottomValueTag_None } }
#define AzLayoutMarginBottomValue_Inherit { .Inherit = { .tag = AzLayoutMarginBottomValueTag_Inherit } }
#define AzLayoutMarginBottomValue_Initial { .Initial = { .tag = AzLayoutMarginBottomValueTag_Initial } }
#define AzLayoutMarginBottomValue_Exact(v) { .Exact = { .tag = AzLayoutMarginBottomValueTag_Exact, .payload = v } }
#define AzLayoutMarginLeftValue_Auto { .Auto = { .tag = AzLayoutMarginLeftValueTag_Auto } }
#define AzLayoutMarginLeftValue_None { .None = { .tag = AzLayoutMarginLeftValueTag_None } }
#define AzLayoutMarginLeftValue_Inherit { .Inherit = { .tag = AzLayoutMarginLeftValueTag_Inherit } }
#define AzLayoutMarginLeftValue_Initial { .Initial = { .tag = AzLayoutMarginLeftValueTag_Initial } }
#define AzLayoutMarginLeftValue_Exact(v) { .Exact = { .tag = AzLayoutMarginLeftValueTag_Exact, .payload = v } }
#define AzLayoutMarginRightValue_Auto { .Auto = { .tag = AzLayoutMarginRightValueTag_Auto } }
#define AzLayoutMarginRightValue_None { .None = { .tag = AzLayoutMarginRightValueTag_None } }
#define AzLayoutMarginRightValue_Inherit { .Inherit = { .tag = AzLayoutMarginRightValueTag_Inherit } }
#define AzLayoutMarginRightValue_Initial { .Initial = { .tag = AzLayoutMarginRightValueTag_Initial } }
#define AzLayoutMarginRightValue_Exact(v) { .Exact = { .tag = AzLayoutMarginRightValueTag_Exact, .payload = v } }
#define AzLayoutMarginTopValue_Auto { .Auto = { .tag = AzLayoutMarginTopValueTag_Auto } }
#define AzLayoutMarginTopValue_None { .None = { .tag = AzLayoutMarginTopValueTag_None } }
#define AzLayoutMarginTopValue_Inherit { .Inherit = { .tag = AzLayoutMarginTopValueTag_Inherit } }
#define AzLayoutMarginTopValue_Initial { .Initial = { .tag = AzLayoutMarginTopValueTag_Initial } }
#define AzLayoutMarginTopValue_Exact(v) { .Exact = { .tag = AzLayoutMarginTopValueTag_Exact, .payload = v } }
#define AzLayoutMaxHeightValue_Auto { .Auto = { .tag = AzLayoutMaxHeightValueTag_Auto } }
#define AzLayoutMaxHeightValue_None { .None = { .tag = AzLayoutMaxHeightValueTag_None } }
#define AzLayoutMaxHeightValue_Inherit { .Inherit = { .tag = AzLayoutMaxHeightValueTag_Inherit } }
#define AzLayoutMaxHeightValue_Initial { .Initial = { .tag = AzLayoutMaxHeightValueTag_Initial } }
#define AzLayoutMaxHeightValue_Exact(v) { .Exact = { .tag = AzLayoutMaxHeightValueTag_Exact, .payload = v } }
#define AzLayoutMaxWidthValue_Auto { .Auto = { .tag = AzLayoutMaxWidthValueTag_Auto } }
#define AzLayoutMaxWidthValue_None { .None = { .tag = AzLayoutMaxWidthValueTag_None } }
#define AzLayoutMaxWidthValue_Inherit { .Inherit = { .tag = AzLayoutMaxWidthValueTag_Inherit } }
#define AzLayoutMaxWidthValue_Initial { .Initial = { .tag = AzLayoutMaxWidthValueTag_Initial } }
#define AzLayoutMaxWidthValue_Exact(v) { .Exact = { .tag = AzLayoutMaxWidthValueTag_Exact, .payload = v } }
#define AzLayoutMinHeightValue_Auto { .Auto = { .tag = AzLayoutMinHeightValueTag_Auto } }
#define AzLayoutMinHeightValue_None { .None = { .tag = AzLayoutMinHeightValueTag_None } }
#define AzLayoutMinHeightValue_Inherit { .Inherit = { .tag = AzLayoutMinHeightValueTag_Inherit } }
#define AzLayoutMinHeightValue_Initial { .Initial = { .tag = AzLayoutMinHeightValueTag_Initial } }
#define AzLayoutMinHeightValue_Exact(v) { .Exact = { .tag = AzLayoutMinHeightValueTag_Exact, .payload = v } }
#define AzLayoutMinWidthValue_Auto { .Auto = { .tag = AzLayoutMinWidthValueTag_Auto } }
#define AzLayoutMinWidthValue_None { .None = { .tag = AzLayoutMinWidthValueTag_None } }
#define AzLayoutMinWidthValue_Inherit { .Inherit = { .tag = AzLayoutMinWidthValueTag_Inherit } }
#define AzLayoutMinWidthValue_Initial { .Initial = { .tag = AzLayoutMinWidthValueTag_Initial } }
#define AzLayoutMinWidthValue_Exact(v) { .Exact = { .tag = AzLayoutMinWidthValueTag_Exact, .payload = v } }
#define AzLayoutPaddingBottomValue_Auto { .Auto = { .tag = AzLayoutPaddingBottomValueTag_Auto } }
#define AzLayoutPaddingBottomValue_None { .None = { .tag = AzLayoutPaddingBottomValueTag_None } }
#define AzLayoutPaddingBottomValue_Inherit { .Inherit = { .tag = AzLayoutPaddingBottomValueTag_Inherit } }
#define AzLayoutPaddingBottomValue_Initial { .Initial = { .tag = AzLayoutPaddingBottomValueTag_Initial } }
#define AzLayoutPaddingBottomValue_Exact(v) { .Exact = { .tag = AzLayoutPaddingBottomValueTag_Exact, .payload = v } }
#define AzLayoutPaddingLeftValue_Auto { .Auto = { .tag = AzLayoutPaddingLeftValueTag_Auto } }
#define AzLayoutPaddingLeftValue_None { .None = { .tag = AzLayoutPaddingLeftValueTag_None } }
#define AzLayoutPaddingLeftValue_Inherit { .Inherit = { .tag = AzLayoutPaddingLeftValueTag_Inherit } }
#define AzLayoutPaddingLeftValue_Initial { .Initial = { .tag = AzLayoutPaddingLeftValueTag_Initial } }
#define AzLayoutPaddingLeftValue_Exact(v) { .Exact = { .tag = AzLayoutPaddingLeftValueTag_Exact, .payload = v } }
#define AzLayoutPaddingRightValue_Auto { .Auto = { .tag = AzLayoutPaddingRightValueTag_Auto } }
#define AzLayoutPaddingRightValue_None { .None = { .tag = AzLayoutPaddingRightValueTag_None } }
#define AzLayoutPaddingRightValue_Inherit { .Inherit = { .tag = AzLayoutPaddingRightValueTag_Inherit } }
#define AzLayoutPaddingRightValue_Initial { .Initial = { .tag = AzLayoutPaddingRightValueTag_Initial } }
#define AzLayoutPaddingRightValue_Exact(v) { .Exact = { .tag = AzLayoutPaddingRightValueTag_Exact, .payload = v } }
#define AzLayoutPaddingTopValue_Auto { .Auto = { .tag = AzLayoutPaddingTopValueTag_Auto } }
#define AzLayoutPaddingTopValue_None { .None = { .tag = AzLayoutPaddingTopValueTag_None } }
#define AzLayoutPaddingTopValue_Inherit { .Inherit = { .tag = AzLayoutPaddingTopValueTag_Inherit } }
#define AzLayoutPaddingTopValue_Initial { .Initial = { .tag = AzLayoutPaddingTopValueTag_Initial } }
#define AzLayoutPaddingTopValue_Exact(v) { .Exact = { .tag = AzLayoutPaddingTopValueTag_Exact, .payload = v } }
#define AzLayoutPositionValue_Auto { .Auto = { .tag = AzLayoutPositionValueTag_Auto } }
#define AzLayoutPositionValue_None { .None = { .tag = AzLayoutPositionValueTag_None } }
#define AzLayoutPositionValue_Inherit { .Inherit = { .tag = AzLayoutPositionValueTag_Inherit } }
#define AzLayoutPositionValue_Initial { .Initial = { .tag = AzLayoutPositionValueTag_Initial } }
#define AzLayoutPositionValue_Exact(v) { .Exact = { .tag = AzLayoutPositionValueTag_Exact, .payload = v } }
#define AzLayoutRightValue_Auto { .Auto = { .tag = AzLayoutRightValueTag_Auto } }
#define AzLayoutRightValue_None { .None = { .tag = AzLayoutRightValueTag_None } }
#define AzLayoutRightValue_Inherit { .Inherit = { .tag = AzLayoutRightValueTag_Inherit } }
#define AzLayoutRightValue_Initial { .Initial = { .tag = AzLayoutRightValueTag_Initial } }
#define AzLayoutRightValue_Exact(v) { .Exact = { .tag = AzLayoutRightValueTag_Exact, .payload = v } }
#define AzLayoutTopValue_Auto { .Auto = { .tag = AzLayoutTopValueTag_Auto } }
#define AzLayoutTopValue_None { .None = { .tag = AzLayoutTopValueTag_None } }
#define AzLayoutTopValue_Inherit { .Inherit = { .tag = AzLayoutTopValueTag_Inherit } }
#define AzLayoutTopValue_Initial { .Initial = { .tag = AzLayoutTopValueTag_Initial } }
#define AzLayoutTopValue_Exact(v) { .Exact = { .tag = AzLayoutTopValueTag_Exact, .payload = v } }
#define AzLayoutWidthValue_Auto { .Auto = { .tag = AzLayoutWidthValueTag_Auto } }
#define AzLayoutWidthValue_None { .None = { .tag = AzLayoutWidthValueTag_None } }
#define AzLayoutWidthValue_Inherit { .Inherit = { .tag = AzLayoutWidthValueTag_Inherit } }
#define AzLayoutWidthValue_Initial { .Initial = { .tag = AzLayoutWidthValueTag_Initial } }
#define AzLayoutWidthValue_Exact(v) { .Exact = { .tag = AzLayoutWidthValueTag_Exact, .payload = v } }
#define AzLayoutFlexWrapValue_Auto { .Auto = { .tag = AzLayoutFlexWrapValueTag_Auto } }
#define AzLayoutFlexWrapValue_None { .None = { .tag = AzLayoutFlexWrapValueTag_None } }
#define AzLayoutFlexWrapValue_Inherit { .Inherit = { .tag = AzLayoutFlexWrapValueTag_Inherit } }
#define AzLayoutFlexWrapValue_Initial { .Initial = { .tag = AzLayoutFlexWrapValueTag_Initial } }
#define AzLayoutFlexWrapValue_Exact(v) { .Exact = { .tag = AzLayoutFlexWrapValueTag_Exact, .payload = v } }
#define AzLayoutOverflowValue_Auto { .Auto = { .tag = AzLayoutOverflowValueTag_Auto } }
#define AzLayoutOverflowValue_None { .None = { .tag = AzLayoutOverflowValueTag_None } }
#define AzLayoutOverflowValue_Inherit { .Inherit = { .tag = AzLayoutOverflowValueTag_Inherit } }
#define AzLayoutOverflowValue_Initial { .Initial = { .tag = AzLayoutOverflowValueTag_Initial } }
#define AzLayoutOverflowValue_Exact(v) { .Exact = { .tag = AzLayoutOverflowValueTag_Exact, .payload = v } }
#define AzStyleBorderBottomColorValue_Auto { .Auto = { .tag = AzStyleBorderBottomColorValueTag_Auto } }
#define AzStyleBorderBottomColorValue_None { .None = { .tag = AzStyleBorderBottomColorValueTag_None } }
#define AzStyleBorderBottomColorValue_Inherit { .Inherit = { .tag = AzStyleBorderBottomColorValueTag_Inherit } }
#define AzStyleBorderBottomColorValue_Initial { .Initial = { .tag = AzStyleBorderBottomColorValueTag_Initial } }
#define AzStyleBorderBottomColorValue_Exact(v) { .Exact = { .tag = AzStyleBorderBottomColorValueTag_Exact, .payload = v } }
#define AzStyleBorderBottomLeftRadiusValue_Auto { .Auto = { .tag = AzStyleBorderBottomLeftRadiusValueTag_Auto } }
#define AzStyleBorderBottomLeftRadiusValue_None { .None = { .tag = AzStyleBorderBottomLeftRadiusValueTag_None } }
#define AzStyleBorderBottomLeftRadiusValue_Inherit { .Inherit = { .tag = AzStyleBorderBottomLeftRadiusValueTag_Inherit } }
#define AzStyleBorderBottomLeftRadiusValue_Initial { .Initial = { .tag = AzStyleBorderBottomLeftRadiusValueTag_Initial } }
#define AzStyleBorderBottomLeftRadiusValue_Exact(v) { .Exact = { .tag = AzStyleBorderBottomLeftRadiusValueTag_Exact, .payload = v } }
#define AzStyleBorderBottomRightRadiusValue_Auto { .Auto = { .tag = AzStyleBorderBottomRightRadiusValueTag_Auto } }
#define AzStyleBorderBottomRightRadiusValue_None { .None = { .tag = AzStyleBorderBottomRightRadiusValueTag_None } }
#define AzStyleBorderBottomRightRadiusValue_Inherit { .Inherit = { .tag = AzStyleBorderBottomRightRadiusValueTag_Inherit } }
#define AzStyleBorderBottomRightRadiusValue_Initial { .Initial = { .tag = AzStyleBorderBottomRightRadiusValueTag_Initial } }
#define AzStyleBorderBottomRightRadiusValue_Exact(v) { .Exact = { .tag = AzStyleBorderBottomRightRadiusValueTag_Exact, .payload = v } }
#define AzStyleBorderBottomStyleValue_Auto { .Auto = { .tag = AzStyleBorderBottomStyleValueTag_Auto } }
#define AzStyleBorderBottomStyleValue_None { .None = { .tag = AzStyleBorderBottomStyleValueTag_None } }
#define AzStyleBorderBottomStyleValue_Inherit { .Inherit = { .tag = AzStyleBorderBottomStyleValueTag_Inherit } }
#define AzStyleBorderBottomStyleValue_Initial { .Initial = { .tag = AzStyleBorderBottomStyleValueTag_Initial } }
#define AzStyleBorderBottomStyleValue_Exact(v) { .Exact = { .tag = AzStyleBorderBottomStyleValueTag_Exact, .payload = v } }
#define AzLayoutBorderBottomWidthValue_Auto { .Auto = { .tag = AzLayoutBorderBottomWidthValueTag_Auto } }
#define AzLayoutBorderBottomWidthValue_None { .None = { .tag = AzLayoutBorderBottomWidthValueTag_None } }
#define AzLayoutBorderBottomWidthValue_Inherit { .Inherit = { .tag = AzLayoutBorderBottomWidthValueTag_Inherit } }
#define AzLayoutBorderBottomWidthValue_Initial { .Initial = { .tag = AzLayoutBorderBottomWidthValueTag_Initial } }
#define AzLayoutBorderBottomWidthValue_Exact(v) { .Exact = { .tag = AzLayoutBorderBottomWidthValueTag_Exact, .payload = v } }
#define AzStyleBorderLeftColorValue_Auto { .Auto = { .tag = AzStyleBorderLeftColorValueTag_Auto } }
#define AzStyleBorderLeftColorValue_None { .None = { .tag = AzStyleBorderLeftColorValueTag_None } }
#define AzStyleBorderLeftColorValue_Inherit { .Inherit = { .tag = AzStyleBorderLeftColorValueTag_Inherit } }
#define AzStyleBorderLeftColorValue_Initial { .Initial = { .tag = AzStyleBorderLeftColorValueTag_Initial } }
#define AzStyleBorderLeftColorValue_Exact(v) { .Exact = { .tag = AzStyleBorderLeftColorValueTag_Exact, .payload = v } }
#define AzStyleBorderLeftStyleValue_Auto { .Auto = { .tag = AzStyleBorderLeftStyleValueTag_Auto } }
#define AzStyleBorderLeftStyleValue_None { .None = { .tag = AzStyleBorderLeftStyleValueTag_None } }
#define AzStyleBorderLeftStyleValue_Inherit { .Inherit = { .tag = AzStyleBorderLeftStyleValueTag_Inherit } }
#define AzStyleBorderLeftStyleValue_Initial { .Initial = { .tag = AzStyleBorderLeftStyleValueTag_Initial } }
#define AzStyleBorderLeftStyleValue_Exact(v) { .Exact = { .tag = AzStyleBorderLeftStyleValueTag_Exact, .payload = v } }
#define AzLayoutBorderLeftWidthValue_Auto { .Auto = { .tag = AzLayoutBorderLeftWidthValueTag_Auto } }
#define AzLayoutBorderLeftWidthValue_None { .None = { .tag = AzLayoutBorderLeftWidthValueTag_None } }
#define AzLayoutBorderLeftWidthValue_Inherit { .Inherit = { .tag = AzLayoutBorderLeftWidthValueTag_Inherit } }
#define AzLayoutBorderLeftWidthValue_Initial { .Initial = { .tag = AzLayoutBorderLeftWidthValueTag_Initial } }
#define AzLayoutBorderLeftWidthValue_Exact(v) { .Exact = { .tag = AzLayoutBorderLeftWidthValueTag_Exact, .payload = v } }
#define AzStyleBorderRightColorValue_Auto { .Auto = { .tag = AzStyleBorderRightColorValueTag_Auto } }
#define AzStyleBorderRightColorValue_None { .None = { .tag = AzStyleBorderRightColorValueTag_None } }
#define AzStyleBorderRightColorValue_Inherit { .Inherit = { .tag = AzStyleBorderRightColorValueTag_Inherit } }
#define AzStyleBorderRightColorValue_Initial { .Initial = { .tag = AzStyleBorderRightColorValueTag_Initial } }
#define AzStyleBorderRightColorValue_Exact(v) { .Exact = { .tag = AzStyleBorderRightColorValueTag_Exact, .payload = v } }
#define AzStyleBorderRightStyleValue_Auto { .Auto = { .tag = AzStyleBorderRightStyleValueTag_Auto } }
#define AzStyleBorderRightStyleValue_None { .None = { .tag = AzStyleBorderRightStyleValueTag_None } }
#define AzStyleBorderRightStyleValue_Inherit { .Inherit = { .tag = AzStyleBorderRightStyleValueTag_Inherit } }
#define AzStyleBorderRightStyleValue_Initial { .Initial = { .tag = AzStyleBorderRightStyleValueTag_Initial } }
#define AzStyleBorderRightStyleValue_Exact(v) { .Exact = { .tag = AzStyleBorderRightStyleValueTag_Exact, .payload = v } }
#define AzLayoutBorderRightWidthValue_Auto { .Auto = { .tag = AzLayoutBorderRightWidthValueTag_Auto } }
#define AzLayoutBorderRightWidthValue_None { .None = { .tag = AzLayoutBorderRightWidthValueTag_None } }
#define AzLayoutBorderRightWidthValue_Inherit { .Inherit = { .tag = AzLayoutBorderRightWidthValueTag_Inherit } }
#define AzLayoutBorderRightWidthValue_Initial { .Initial = { .tag = AzLayoutBorderRightWidthValueTag_Initial } }
#define AzLayoutBorderRightWidthValue_Exact(v) { .Exact = { .tag = AzLayoutBorderRightWidthValueTag_Exact, .payload = v } }
#define AzStyleBorderTopColorValue_Auto { .Auto = { .tag = AzStyleBorderTopColorValueTag_Auto } }
#define AzStyleBorderTopColorValue_None { .None = { .tag = AzStyleBorderTopColorValueTag_None } }
#define AzStyleBorderTopColorValue_Inherit { .Inherit = { .tag = AzStyleBorderTopColorValueTag_Inherit } }
#define AzStyleBorderTopColorValue_Initial { .Initial = { .tag = AzStyleBorderTopColorValueTag_Initial } }
#define AzStyleBorderTopColorValue_Exact(v) { .Exact = { .tag = AzStyleBorderTopColorValueTag_Exact, .payload = v } }
#define AzStyleBorderTopLeftRadiusValue_Auto { .Auto = { .tag = AzStyleBorderTopLeftRadiusValueTag_Auto } }
#define AzStyleBorderTopLeftRadiusValue_None { .None = { .tag = AzStyleBorderTopLeftRadiusValueTag_None } }
#define AzStyleBorderTopLeftRadiusValue_Inherit { .Inherit = { .tag = AzStyleBorderTopLeftRadiusValueTag_Inherit } }
#define AzStyleBorderTopLeftRadiusValue_Initial { .Initial = { .tag = AzStyleBorderTopLeftRadiusValueTag_Initial } }
#define AzStyleBorderTopLeftRadiusValue_Exact(v) { .Exact = { .tag = AzStyleBorderTopLeftRadiusValueTag_Exact, .payload = v } }
#define AzStyleBorderTopRightRadiusValue_Auto { .Auto = { .tag = AzStyleBorderTopRightRadiusValueTag_Auto } }
#define AzStyleBorderTopRightRadiusValue_None { .None = { .tag = AzStyleBorderTopRightRadiusValueTag_None } }
#define AzStyleBorderTopRightRadiusValue_Inherit { .Inherit = { .tag = AzStyleBorderTopRightRadiusValueTag_Inherit } }
#define AzStyleBorderTopRightRadiusValue_Initial { .Initial = { .tag = AzStyleBorderTopRightRadiusValueTag_Initial } }
#define AzStyleBorderTopRightRadiusValue_Exact(v) { .Exact = { .tag = AzStyleBorderTopRightRadiusValueTag_Exact, .payload = v } }
#define AzStyleBorderTopStyleValue_Auto { .Auto = { .tag = AzStyleBorderTopStyleValueTag_Auto } }
#define AzStyleBorderTopStyleValue_None { .None = { .tag = AzStyleBorderTopStyleValueTag_None } }
#define AzStyleBorderTopStyleValue_Inherit { .Inherit = { .tag = AzStyleBorderTopStyleValueTag_Inherit } }
#define AzStyleBorderTopStyleValue_Initial { .Initial = { .tag = AzStyleBorderTopStyleValueTag_Initial } }
#define AzStyleBorderTopStyleValue_Exact(v) { .Exact = { .tag = AzStyleBorderTopStyleValueTag_Exact, .payload = v } }
#define AzLayoutBorderTopWidthValue_Auto { .Auto = { .tag = AzLayoutBorderTopWidthValueTag_Auto } }
#define AzLayoutBorderTopWidthValue_None { .None = { .tag = AzLayoutBorderTopWidthValueTag_None } }
#define AzLayoutBorderTopWidthValue_Inherit { .Inherit = { .tag = AzLayoutBorderTopWidthValueTag_Inherit } }
#define AzLayoutBorderTopWidthValue_Initial { .Initial = { .tag = AzLayoutBorderTopWidthValueTag_Initial } }
#define AzLayoutBorderTopWidthValue_Exact(v) { .Exact = { .tag = AzLayoutBorderTopWidthValueTag_Exact, .payload = v } }
#define AzStyleCursorValue_Auto { .Auto = { .tag = AzStyleCursorValueTag_Auto } }
#define AzStyleCursorValue_None { .None = { .tag = AzStyleCursorValueTag_None } }
#define AzStyleCursorValue_Inherit { .Inherit = { .tag = AzStyleCursorValueTag_Inherit } }
#define AzStyleCursorValue_Initial { .Initial = { .tag = AzStyleCursorValueTag_Initial } }
#define AzStyleCursorValue_Exact(v) { .Exact = { .tag = AzStyleCursorValueTag_Exact, .payload = v } }
#define AzStyleFontSizeValue_Auto { .Auto = { .tag = AzStyleFontSizeValueTag_Auto } }
#define AzStyleFontSizeValue_None { .None = { .tag = AzStyleFontSizeValueTag_None } }
#define AzStyleFontSizeValue_Inherit { .Inherit = { .tag = AzStyleFontSizeValueTag_Inherit } }
#define AzStyleFontSizeValue_Initial { .Initial = { .tag = AzStyleFontSizeValueTag_Initial } }
#define AzStyleFontSizeValue_Exact(v) { .Exact = { .tag = AzStyleFontSizeValueTag_Exact, .payload = v } }
#define AzStyleLetterSpacingValue_Auto { .Auto = { .tag = AzStyleLetterSpacingValueTag_Auto } }
#define AzStyleLetterSpacingValue_None { .None = { .tag = AzStyleLetterSpacingValueTag_None } }
#define AzStyleLetterSpacingValue_Inherit { .Inherit = { .tag = AzStyleLetterSpacingValueTag_Inherit } }
#define AzStyleLetterSpacingValue_Initial { .Initial = { .tag = AzStyleLetterSpacingValueTag_Initial } }
#define AzStyleLetterSpacingValue_Exact(v) { .Exact = { .tag = AzStyleLetterSpacingValueTag_Exact, .payload = v } }
#define AzStyleLineHeightValue_Auto { .Auto = { .tag = AzStyleLineHeightValueTag_Auto } }
#define AzStyleLineHeightValue_None { .None = { .tag = AzStyleLineHeightValueTag_None } }
#define AzStyleLineHeightValue_Inherit { .Inherit = { .tag = AzStyleLineHeightValueTag_Inherit } }
#define AzStyleLineHeightValue_Initial { .Initial = { .tag = AzStyleLineHeightValueTag_Initial } }
#define AzStyleLineHeightValue_Exact(v) { .Exact = { .tag = AzStyleLineHeightValueTag_Exact, .payload = v } }
#define AzStyleTabWidthValue_Auto { .Auto = { .tag = AzStyleTabWidthValueTag_Auto } }
#define AzStyleTabWidthValue_None { .None = { .tag = AzStyleTabWidthValueTag_None } }
#define AzStyleTabWidthValue_Inherit { .Inherit = { .tag = AzStyleTabWidthValueTag_Inherit } }
#define AzStyleTabWidthValue_Initial { .Initial = { .tag = AzStyleTabWidthValueTag_Initial } }
#define AzStyleTabWidthValue_Exact(v) { .Exact = { .tag = AzStyleTabWidthValueTag_Exact, .payload = v } }
#define AzStyleTextAlignValue_Auto { .Auto = { .tag = AzStyleTextAlignValueTag_Auto } }
#define AzStyleTextAlignValue_None { .None = { .tag = AzStyleTextAlignValueTag_None } }
#define AzStyleTextAlignValue_Inherit { .Inherit = { .tag = AzStyleTextAlignValueTag_Inherit } }
#define AzStyleTextAlignValue_Initial { .Initial = { .tag = AzStyleTextAlignValueTag_Initial } }
#define AzStyleTextAlignValue_Exact(v) { .Exact = { .tag = AzStyleTextAlignValueTag_Exact, .payload = v } }
#define AzStyleTextColorValue_Auto { .Auto = { .tag = AzStyleTextColorValueTag_Auto } }
#define AzStyleTextColorValue_None { .None = { .tag = AzStyleTextColorValueTag_None } }
#define AzStyleTextColorValue_Inherit { .Inherit = { .tag = AzStyleTextColorValueTag_Inherit } }
#define AzStyleTextColorValue_Initial { .Initial = { .tag = AzStyleTextColorValueTag_Initial } }
#define AzStyleTextColorValue_Exact(v) { .Exact = { .tag = AzStyleTextColorValueTag_Exact, .payload = v } }
#define AzStyleWordSpacingValue_Auto { .Auto = { .tag = AzStyleWordSpacingValueTag_Auto } }
#define AzStyleWordSpacingValue_None { .None = { .tag = AzStyleWordSpacingValueTag_None } }
#define AzStyleWordSpacingValue_Inherit { .Inherit = { .tag = AzStyleWordSpacingValueTag_Inherit } }
#define AzStyleWordSpacingValue_Initial { .Initial = { .tag = AzStyleWordSpacingValueTag_Initial } }
#define AzStyleWordSpacingValue_Exact(v) { .Exact = { .tag = AzStyleWordSpacingValueTag_Exact, .payload = v } }
#define AzStyleOpacityValue_Auto { .Auto = { .tag = AzStyleOpacityValueTag_Auto } }
#define AzStyleOpacityValue_None { .None = { .tag = AzStyleOpacityValueTag_None } }
#define AzStyleOpacityValue_Inherit { .Inherit = { .tag = AzStyleOpacityValueTag_Inherit } }
#define AzStyleOpacityValue_Initial { .Initial = { .tag = AzStyleOpacityValueTag_Initial } }
#define AzStyleOpacityValue_Exact(v) { .Exact = { .tag = AzStyleOpacityValueTag_Exact, .payload = v } }
#define AzStyleTransformOriginValue_Auto { .Auto = { .tag = AzStyleTransformOriginValueTag_Auto } }
#define AzStyleTransformOriginValue_None { .None = { .tag = AzStyleTransformOriginValueTag_None } }
#define AzStyleTransformOriginValue_Inherit { .Inherit = { .tag = AzStyleTransformOriginValueTag_Inherit } }
#define AzStyleTransformOriginValue_Initial { .Initial = { .tag = AzStyleTransformOriginValueTag_Initial } }
#define AzStyleTransformOriginValue_Exact(v) { .Exact = { .tag = AzStyleTransformOriginValueTag_Exact, .payload = v } }
#define AzStylePerspectiveOriginValue_Auto { .Auto = { .tag = AzStylePerspectiveOriginValueTag_Auto } }
#define AzStylePerspectiveOriginValue_None { .None = { .tag = AzStylePerspectiveOriginValueTag_None } }
#define AzStylePerspectiveOriginValue_Inherit { .Inherit = { .tag = AzStylePerspectiveOriginValueTag_Inherit } }
#define AzStylePerspectiveOriginValue_Initial { .Initial = { .tag = AzStylePerspectiveOriginValueTag_Initial } }
#define AzStylePerspectiveOriginValue_Exact(v) { .Exact = { .tag = AzStylePerspectiveOriginValueTag_Exact, .payload = v } }
#define AzStyleBackfaceVisibilityValue_Auto { .Auto = { .tag = AzStyleBackfaceVisibilityValueTag_Auto } }
#define AzStyleBackfaceVisibilityValue_None { .None = { .tag = AzStyleBackfaceVisibilityValueTag_None } }
#define AzStyleBackfaceVisibilityValue_Inherit { .Inherit = { .tag = AzStyleBackfaceVisibilityValueTag_Inherit } }
#define AzStyleBackfaceVisibilityValue_Initial { .Initial = { .tag = AzStyleBackfaceVisibilityValueTag_Initial } }
#define AzStyleBackfaceVisibilityValue_Exact(v) { .Exact = { .tag = AzStyleBackfaceVisibilityValueTag_Exact, .payload = v } }
#define AzTextInputSelection_All { .All = { .tag = AzTextInputSelectionTag_All } }
#define AzTextInputSelection_FromTo(v) { .FromTo = { .tag = AzTextInputSelectionTag_FromTo, .payload = v } }
#define AzDuration_System(v) { .System = { .tag = AzDurationTag_System, .payload = v } }
#define AzDuration_Tick(v) { .Tick = { .tag = AzDurationTag_Tick, .payload = v } }
#define AzThreadSendMsg_TerminateThread { .TerminateThread = { .tag = AzThreadSendMsgTag_TerminateThread } }
#define AzThreadSendMsg_Tick { .Tick = { .tag = AzThreadSendMsgTag_Tick } }
#define AzThreadSendMsg_Custom(v) { .Custom = { .tag = AzThreadSendMsgTag_Custom, .payload = v } }
#define AzOptionColorInputOnValueChange_None { .None = { .tag = AzOptionColorInputOnValueChangeTag_None } }
#define AzOptionColorInputOnValueChange_Some(v) { .Some = { .tag = AzOptionColorInputOnValueChangeTag_Some, .payload = v } }
#define AzOptionButtonOnClick_None { .None = { .tag = AzOptionButtonOnClickTag_None } }
#define AzOptionButtonOnClick_Some(v) { .Some = { .tag = AzOptionButtonOnClickTag_Some, .payload = v } }
#define AzOptionCheckBoxOnToggle_None { .None = { .tag = AzOptionCheckBoxOnToggleTag_None } }
#define AzOptionCheckBoxOnToggle_Some(v) { .Some = { .tag = AzOptionCheckBoxOnToggleTag_Some, .payload = v } }
#define AzOptionTextInputOnTextInput_None { .None = { .tag = AzOptionTextInputOnTextInputTag_None } }
#define AzOptionTextInputOnTextInput_Some(v) { .Some = { .tag = AzOptionTextInputOnTextInputTag_Some, .payload = v } }
#define AzOptionTextInputOnVirtualKeyDown_None { .None = { .tag = AzOptionTextInputOnVirtualKeyDownTag_None } }
#define AzOptionTextInputOnVirtualKeyDown_Some(v) { .Some = { .tag = AzOptionTextInputOnVirtualKeyDownTag_Some, .payload = v } }
#define AzOptionTextInputOnFocusLost_None { .None = { .tag = AzOptionTextInputOnFocusLostTag_None } }
#define AzOptionTextInputOnFocusLost_Some(v) { .Some = { .tag = AzOptionTextInputOnFocusLostTag_Some, .payload = v } }
#define AzOptionTextInputSelection_None { .None = { .tag = AzOptionTextInputSelectionTag_None } }
#define AzOptionTextInputSelection_Some(v) { .Some = { .tag = AzOptionTextInputSelectionTag_Some, .payload = v } }
#define AzOptionNumberInputOnValueChange_None { .None = { .tag = AzOptionNumberInputOnValueChangeTag_None } }
#define AzOptionNumberInputOnValueChange_Some(v) { .Some = { .tag = AzOptionNumberInputOnValueChangeTag_Some, .payload = v } }
#define AzOptionMenuItemIcon_None { .None = { .tag = AzOptionMenuItemIconTag_None } }
#define AzOptionMenuItemIcon_Some(v) { .Some = { .tag = AzOptionMenuItemIconTag_Some, .payload = v } }
#define AzOptionMenuCallback_None { .None = { .tag = AzOptionMenuCallbackTag_None } }
#define AzOptionMenuCallback_Some(v) { .Some = { .tag = AzOptionMenuCallbackTag_Some, .payload = v } }
#define AzOptionPositionInfo_None { .None = { .tag = AzOptionPositionInfoTag_None } }
#define AzOptionPositionInfo_Some(v) { .Some = { .tag = AzOptionPositionInfoTag_Some, .payload = v } }
#define AzOptionTimerId_None { .None = { .tag = AzOptionTimerIdTag_None } }
#define AzOptionTimerId_Some(v) { .Some = { .tag = AzOptionTimerIdTag_Some, .payload = v } }
#define AzOptionThreadId_None { .None = { .tag = AzOptionThreadIdTag_None } }
#define AzOptionThreadId_Some(v) { .Some = { .tag = AzOptionThreadIdTag_Some, .payload = v } }
#define AzOptionImageRef_None { .None = { .tag = AzOptionImageRefTag_None } }
#define AzOptionImageRef_Some(v) { .Some = { .tag = AzOptionImageRefTag_Some, .payload = v } }
#define AzOptionFontRef_None { .None = { .tag = AzOptionFontRefTag_None } }
#define AzOptionFontRef_Some(v) { .Some = { .tag = AzOptionFontRefTag_Some, .payload = v } }
#define AzOptionSystemClipboard_None { .None = { .tag = AzOptionSystemClipboardTag_None } }
#define AzOptionSystemClipboard_Some(v) { .Some = { .tag = AzOptionSystemClipboardTag_Some, .payload = v } }
#define AzOptionGl_None { .None = { .tag = AzOptionGlTag_None } }
#define AzOptionGl_Some(v) { .Some = { .tag = AzOptionGlTag_Some, .payload = v } }
#define AzOptionPercentageValue_None { .None = { .tag = AzOptionPercentageValueTag_None } }
#define AzOptionPercentageValue_Some(v) { .Some = { .tag = AzOptionPercentageValueTag_Some, .payload = v } }
#define AzOptionAngleValue_None { .None = { .tag = AzOptionAngleValueTag_None } }
#define AzOptionAngleValue_Some(v) { .Some = { .tag = AzOptionAngleValueTag_Some, .payload = v } }
#define AzOptionRendererOptions_None { .None = { .tag = AzOptionRendererOptionsTag_None } }
#define AzOptionRendererOptions_Some(v) { .Some = { .tag = AzOptionRendererOptionsTag_Some, .payload = v } }
#define AzOptionCallback_None { .None = { .tag = AzOptionCallbackTag_None } }
#define AzOptionCallback_Some(v) { .Some = { .tag = AzOptionCallbackTag_Some, .payload = v } }
#define AzOptionThreadSendMsg_None { .None = { .tag = AzOptionThreadSendMsgTag_None } }
#define AzOptionThreadSendMsg_Some(v) { .Some = { .tag = AzOptionThreadSendMsgTag_Some, .payload = v } }
#define AzOptionLayoutRect_None { .None = { .tag = AzOptionLayoutRectTag_None } }
#define AzOptionLayoutRect_Some(v) { .Some = { .tag = AzOptionLayoutRectTag_Some, .payload = v } }
#define AzOptionRefAny_None { .None = { .tag = AzOptionRefAnyTag_None } }
#define AzOptionRefAny_Some(v) { .Some = { .tag = AzOptionRefAnyTag_Some, .payload = v } }
#define AzOptionLayoutPoint_None { .None = { .tag = AzOptionLayoutPointTag_None } }
#define AzOptionLayoutPoint_Some(v) { .Some = { .tag = AzOptionLayoutPointTag_Some, .payload = v } }
#define AzOptionLayoutSize_None { .None = { .tag = AzOptionLayoutSizeTag_None } }
#define AzOptionLayoutSize_Some(v) { .Some = { .tag = AzOptionLayoutSizeTag_Some, .payload = v } }
#define AzOptionWindowTheme_None { .None = { .tag = AzOptionWindowThemeTag_None } }
#define AzOptionWindowTheme_Some(v) { .Some = { .tag = AzOptionWindowThemeTag_Some, .payload = v } }
#define AzOptionNodeId_None { .None = { .tag = AzOptionNodeIdTag_None } }
#define AzOptionNodeId_Some(v) { .Some = { .tag = AzOptionNodeIdTag_Some, .payload = v } }
#define AzOptionDomNodeId_None { .None = { .tag = AzOptionDomNodeIdTag_None } }
#define AzOptionDomNodeId_Some(v) { .Some = { .tag = AzOptionDomNodeIdTag_Some, .payload = v } }
#define AzOptionColorU_None { .None = { .tag = AzOptionColorUTag_None } }
#define AzOptionColorU_Some(v) { .Some = { .tag = AzOptionColorUTag_Some, .payload = v } }
#define AzOptionSvgDashPattern_None { .None = { .tag = AzOptionSvgDashPatternTag_None } }
#define AzOptionSvgDashPattern_Some(v) { .Some = { .tag = AzOptionSvgDashPatternTag_Some, .payload = v } }
#define AzOptionLogicalPosition_None { .None = { .tag = AzOptionLogicalPositionTag_None } }
#define AzOptionLogicalPosition_Some(v) { .Some = { .tag = AzOptionLogicalPositionTag_Some, .payload = v } }
#define AzOptionPhysicalPositionI32_None { .None = { .tag = AzOptionPhysicalPositionI32Tag_None } }
#define AzOptionPhysicalPositionI32_Some(v) { .Some = { .tag = AzOptionPhysicalPositionI32Tag_Some, .payload = v } }
#define AzOptionMouseCursorType_None { .None = { .tag = AzOptionMouseCursorTypeTag_None } }
#define AzOptionMouseCursorType_Some(v) { .Some = { .tag = AzOptionMouseCursorTypeTag_Some, .payload = v } }
#define AzOptionLogicalSize_None { .None = { .tag = AzOptionLogicalSizeTag_None } }
#define AzOptionLogicalSize_Some(v) { .Some = { .tag = AzOptionLogicalSizeTag_Some, .payload = v } }
#define AzOptionVirtualKeyCode_None { .None = { .tag = AzOptionVirtualKeyCodeTag_None } }
#define AzOptionVirtualKeyCode_Some(v) { .Some = { .tag = AzOptionVirtualKeyCodeTag_Some, .payload = v } }
#define AzOptionImageMask_None { .None = { .tag = AzOptionImageMaskTag_None } }
#define AzOptionImageMask_Some(v) { .Some = { .tag = AzOptionImageMaskTag_Some, .payload = v } }
#define AzOptionTabIndex_None { .None = { .tag = AzOptionTabIndexTag_None } }
#define AzOptionTabIndex_Some(v) { .Some = { .tag = AzOptionTabIndexTag_Some, .payload = v } }
#define AzOptionTagId_None { .None = { .tag = AzOptionTagIdTag_None } }
#define AzOptionTagId_Some(v) { .Some = { .tag = AzOptionTagIdTag_Some, .payload = v } }
#define AzOptionDuration_None { .None = { .tag = AzOptionDurationTag_None } }
#define AzOptionDuration_Some(v) { .Some = { .tag = AzOptionDurationTag_Some, .payload = v } }
#define AzOptionU8Vec_None { .None = { .tag = AzOptionU8VecTag_None } }
#define AzOptionU8Vec_Some(v) { .Some = { .tag = AzOptionU8VecTag_Some, .payload = v } }
#define AzOptionU8VecRef_None { .None = { .tag = AzOptionU8VecRefTag_None } }
#define AzOptionU8VecRef_Some(v) { .Some = { .tag = AzOptionU8VecRefTag_Some, .payload = v } }
#define AzResultU8VecEncodeImageError_Ok(v) { .Ok = { .tag = AzResultU8VecEncodeImageErrorTag_Ok, .payload = v } }
#define AzResultU8VecEncodeImageError_Err(v) { .Err = { .tag = AzResultU8VecEncodeImageErrorTag_Err, .payload = v } }
#define AzWindowIcon_Small(v) { .Small = { .tag = AzWindowIconTag_Small, .payload = v } }
#define AzWindowIcon_Large(v) { .Large = { .tag = AzWindowIconTag_Large, .payload = v } }
#define AzAnimationEasing_Ease { .Ease = { .tag = AzAnimationEasingTag_Ease } }
#define AzAnimationEasing_Linear { .Linear = { .tag = AzAnimationEasingTag_Linear } }
#define AzAnimationEasing_EaseIn { .EaseIn = { .tag = AzAnimationEasingTag_EaseIn } }
#define AzAnimationEasing_EaseOut { .EaseOut = { .tag = AzAnimationEasingTag_EaseOut } }
#define AzAnimationEasing_EaseInOut { .EaseInOut = { .tag = AzAnimationEasingTag_EaseInOut } }
#define AzAnimationEasing_CubicBezier(v) { .CubicBezier = { .tag = AzAnimationEasingTag_CubicBezier, .payload = v } }
#define AzEventFilter_Hover(v) { .Hover = { .tag = AzEventFilterTag_Hover, .payload = v } }
#define AzEventFilter_Not(v) { .Not = { .tag = AzEventFilterTag_Not, .payload = v } }
#define AzEventFilter_Focus(v) { .Focus = { .tag = AzEventFilterTag_Focus, .payload = v } }
#define AzEventFilter_Window(v) { .Window = { .tag = AzEventFilterTag_Window, .payload = v } }
#define AzEventFilter_Component(v) { .Component = { .tag = AzEventFilterTag_Component, .payload = v } }
#define AzEventFilter_Application(v) { .Application = { .tag = AzEventFilterTag_Application, .payload = v } }
#define AzCssPathPseudoSelector_First { .First = { .tag = AzCssPathPseudoSelectorTag_First } }
#define AzCssPathPseudoSelector_Last { .Last = { .tag = AzCssPathPseudoSelectorTag_Last } }
#define AzCssPathPseudoSelector_NthChild(v) { .NthChild = { .tag = AzCssPathPseudoSelectorTag_NthChild, .payload = v } }
#define AzCssPathPseudoSelector_Hover { .Hover = { .tag = AzCssPathPseudoSelectorTag_Hover } }
#define AzCssPathPseudoSelector_Active { .Active = { .tag = AzCssPathPseudoSelectorTag_Active } }
#define AzCssPathPseudoSelector_Focus { .Focus = { .tag = AzCssPathPseudoSelectorTag_Focus } }
#define AzAnimationInterpolationFunction_Ease { .Ease = { .tag = AzAnimationInterpolationFunctionTag_Ease } }
#define AzAnimationInterpolationFunction_Linear { .Linear = { .tag = AzAnimationInterpolationFunctionTag_Linear } }
#define AzAnimationInterpolationFunction_EaseIn { .EaseIn = { .tag = AzAnimationInterpolationFunctionTag_EaseIn } }
#define AzAnimationInterpolationFunction_EaseOut { .EaseOut = { .tag = AzAnimationInterpolationFunctionTag_EaseOut } }
#define AzAnimationInterpolationFunction_EaseInOut { .EaseInOut = { .tag = AzAnimationInterpolationFunctionTag_EaseInOut } }
#define AzAnimationInterpolationFunction_CubicBezier(v) { .CubicBezier = { .tag = AzAnimationInterpolationFunctionTag_CubicBezier, .payload = v } }
#define AzStyleTransform_Matrix(v) { .Matrix = { .tag = AzStyleTransformTag_Matrix, .payload = v } }
#define AzStyleTransform_Matrix3D(v) { .Matrix3D = { .tag = AzStyleTransformTag_Matrix3D, .payload = v } }
#define AzStyleTransform_Translate(v) { .Translate = { .tag = AzStyleTransformTag_Translate, .payload = v } }
#define AzStyleTransform_Translate3D(v) { .Translate3D = { .tag = AzStyleTransformTag_Translate3D, .payload = v } }
#define AzStyleTransform_TranslateX(v) { .TranslateX = { .tag = AzStyleTransformTag_TranslateX, .payload = v } }
#define AzStyleTransform_TranslateY(v) { .TranslateY = { .tag = AzStyleTransformTag_TranslateY, .payload = v } }
#define AzStyleTransform_TranslateZ(v) { .TranslateZ = { .tag = AzStyleTransformTag_TranslateZ, .payload = v } }
#define AzStyleTransform_Rotate(v) { .Rotate = { .tag = AzStyleTransformTag_Rotate, .payload = v } }
#define AzStyleTransform_Rotate3D(v) { .Rotate3D = { .tag = AzStyleTransformTag_Rotate3D, .payload = v } }
#define AzStyleTransform_RotateX(v) { .RotateX = { .tag = AzStyleTransformTag_RotateX, .payload = v } }
#define AzStyleTransform_RotateY(v) { .RotateY = { .tag = AzStyleTransformTag_RotateY, .payload = v } }
#define AzStyleTransform_RotateZ(v) { .RotateZ = { .tag = AzStyleTransformTag_RotateZ, .payload = v } }
#define AzStyleTransform_Scale(v) { .Scale = { .tag = AzStyleTransformTag_Scale, .payload = v } }
#define AzStyleTransform_Scale3D(v) { .Scale3D = { .tag = AzStyleTransformTag_Scale3D, .payload = v } }
#define AzStyleTransform_ScaleX(v) { .ScaleX = { .tag = AzStyleTransformTag_ScaleX, .payload = v } }
#define AzStyleTransform_ScaleY(v) { .ScaleY = { .tag = AzStyleTransformTag_ScaleY, .payload = v } }
#define AzStyleTransform_ScaleZ(v) { .ScaleZ = { .tag = AzStyleTransformTag_ScaleZ, .payload = v } }
#define AzStyleTransform_Skew(v) { .Skew = { .tag = AzStyleTransformTag_Skew, .payload = v } }
#define AzStyleTransform_SkewX(v) { .SkewX = { .tag = AzStyleTransformTag_SkewX, .payload = v } }
#define AzStyleTransform_SkewY(v) { .SkewY = { .tag = AzStyleTransformTag_SkewY, .payload = v } }
#define AzStyleTransform_Perspective(v) { .Perspective = { .tag = AzStyleTransformTag_Perspective, .payload = v } }
#define AzStyleBackgroundPositionVecValue_Auto { .Auto = { .tag = AzStyleBackgroundPositionVecValueTag_Auto } }
#define AzStyleBackgroundPositionVecValue_None { .None = { .tag = AzStyleBackgroundPositionVecValueTag_None } }
#define AzStyleBackgroundPositionVecValue_Inherit { .Inherit = { .tag = AzStyleBackgroundPositionVecValueTag_Inherit } }
#define AzStyleBackgroundPositionVecValue_Initial { .Initial = { .tag = AzStyleBackgroundPositionVecValueTag_Initial } }
#define AzStyleBackgroundPositionVecValue_Exact(v) { .Exact = { .tag = AzStyleBackgroundPositionVecValueTag_Exact, .payload = v } }
#define AzStyleBackgroundRepeatVecValue_Auto { .Auto = { .tag = AzStyleBackgroundRepeatVecValueTag_Auto } }
#define AzStyleBackgroundRepeatVecValue_None { .None = { .tag = AzStyleBackgroundRepeatVecValueTag_None } }
#define AzStyleBackgroundRepeatVecValue_Inherit { .Inherit = { .tag = AzStyleBackgroundRepeatVecValueTag_Inherit } }
#define AzStyleBackgroundRepeatVecValue_Initial { .Initial = { .tag = AzStyleBackgroundRepeatVecValueTag_Initial } }
#define AzStyleBackgroundRepeatVecValue_Exact(v) { .Exact = { .tag = AzStyleBackgroundRepeatVecValueTag_Exact, .payload = v } }
#define AzStyleBackgroundSizeVecValue_Auto { .Auto = { .tag = AzStyleBackgroundSizeVecValueTag_Auto } }
#define AzStyleBackgroundSizeVecValue_None { .None = { .tag = AzStyleBackgroundSizeVecValueTag_None } }
#define AzStyleBackgroundSizeVecValue_Inherit { .Inherit = { .tag = AzStyleBackgroundSizeVecValueTag_Inherit } }
#define AzStyleBackgroundSizeVecValue_Initial { .Initial = { .tag = AzStyleBackgroundSizeVecValueTag_Initial } }
#define AzStyleBackgroundSizeVecValue_Exact(v) { .Exact = { .tag = AzStyleBackgroundSizeVecValueTag_Exact, .payload = v } }
#define AzRawImageData_U8(v) { .U8 = { .tag = AzRawImageDataTag_U8, .payload = v } }
#define AzRawImageData_U16(v) { .U16 = { .tag = AzRawImageDataTag_U16, .payload = v } }
#define AzRawImageData_F32(v) { .F32 = { .tag = AzRawImageDataTag_F32, .payload = v } }
#define AzSvgPathElement_Line(v) { .Line = { .tag = AzSvgPathElementTag_Line, .payload = v } }
#define AzSvgPathElement_QuadraticCurve(v) { .QuadraticCurve = { .tag = AzSvgPathElementTag_QuadraticCurve, .payload = v } }
#define AzSvgPathElement_CubicCurve(v) { .CubicCurve = { .tag = AzSvgPathElementTag_CubicCurve, .payload = v } }
#define AzInstant_System(v) { .System = { .tag = AzInstantTag_System, .payload = v } }
#define AzInstant_Tick(v) { .Tick = { .tag = AzInstantTag_Tick, .payload = v } }
#define AzThreadReceiveMsg_WriteBack(v) { .WriteBack = { .tag = AzThreadReceiveMsgTag_WriteBack, .payload = v } }
#define AzThreadReceiveMsg_Update(v) { .Update = { .tag = AzThreadReceiveMsgTag_Update, .payload = v } }
#define AzOptionVirtualKeyCodeCombo_None { .None = { .tag = AzOptionVirtualKeyCodeComboTag_None } }
#define AzOptionVirtualKeyCodeCombo_Some(v) { .Some = { .tag = AzOptionVirtualKeyCodeComboTag_Some, .payload = v } }
#define AzOptionMouseState_None { .None = { .tag = AzOptionMouseStateTag_None } }
#define AzOptionMouseState_Some(v) { .Some = { .tag = AzOptionMouseStateTag_Some, .payload = v } }
#define AzOptionKeyboardState_None { .None = { .tag = AzOptionKeyboardStateTag_None } }
#define AzOptionKeyboardState_Some(v) { .Some = { .tag = AzOptionKeyboardStateTag_Some, .payload = v } }
#define AzOptionStringVec_None { .None = { .tag = AzOptionStringVecTag_None } }
#define AzOptionStringVec_Some(v) { .Some = { .tag = AzOptionStringVecTag_Some, .payload = v } }
#define AzOptionThreadReceiveMsg_None { .None = { .tag = AzOptionThreadReceiveMsgTag_None } }
#define AzOptionThreadReceiveMsg_Some(v) { .Some = { .tag = AzOptionThreadReceiveMsgTag_Some, .payload = v } }
#define AzOptionTaskBarIcon_None { .None = { .tag = AzOptionTaskBarIconTag_None } }
#define AzOptionTaskBarIcon_Some(v) { .Some = { .tag = AzOptionTaskBarIconTag_Some, .payload = v } }
#define AzOptionWindowIcon_None { .None = { .tag = AzOptionWindowIconTag_None } }
#define AzOptionWindowIcon_Some(v) { .Some = { .tag = AzOptionWindowIconTag_Some, .payload = v } }
#define AzOptionString_None { .None = { .tag = AzOptionStringTag_None } }
#define AzOptionString_Some(v) { .Some = { .tag = AzOptionStringTag_Some, .payload = v } }
#define AzOptionTexture_None { .None = { .tag = AzOptionTextureTag_None } }
#define AzOptionTexture_Some(v) { .Some = { .tag = AzOptionTextureTag_Some, .payload = v } }
#define AzOptionInstant_None { .None = { .tag = AzOptionInstantTag_None } }
#define AzOptionInstant_Some(v) { .Some = { .tag = AzOptionInstantTag_Some, .payload = v } }
#define AzLayoutCallback_Raw(v) { .Raw = { .tag = AzLayoutCallbackTag_Raw, .payload = v } }
#define AzLayoutCallback_Marshaled(v) { .Marshaled = { .tag = AzLayoutCallbackTag_Marshaled, .payload = v } }
#define AzInlineWord_Tab { .Tab = { .tag = AzInlineWordTag_Tab } }
#define AzInlineWord_Return { .Return = { .tag = AzInlineWordTag_Return } }
#define AzInlineWord_Space { .Space = { .tag = AzInlineWordTag_Space } }
#define AzInlineWord_Word(v) { .Word = { .tag = AzInlineWordTag_Word, .payload = v } }
#define AzNodeType_Body { .Body = { .tag = AzNodeTypeTag_Body } }
#define AzNodeType_Div { .Div = { .tag = AzNodeTypeTag_Div } }
#define AzNodeType_Br { .Br = { .tag = AzNodeTypeTag_Br } }
#define AzNodeType_Text(v) { .Text = { .tag = AzNodeTypeTag_Text, .payload = v } }
#define AzNodeType_Image(v) { .Image = { .tag = AzNodeTypeTag_Image, .payload = v } }
#define AzNodeType_IFrame(v) { .IFrame = { .tag = AzNodeTypeTag_IFrame, .payload = v } }
#define AzIdOrClass_Id(v) { .Id = { .tag = AzIdOrClassTag_Id, .payload = v } }
#define AzIdOrClass_Class(v) { .Class = { .tag = AzIdOrClassTag_Class, .payload = v } }
#define AzCssPathSelector_Global { .Global = { .tag = AzCssPathSelectorTag_Global } }
#define AzCssPathSelector_Type(v) { .Type = { .tag = AzCssPathSelectorTag_Type, .payload = v } }
#define AzCssPathSelector_Class(v) { .Class = { .tag = AzCssPathSelectorTag_Class, .payload = v } }
#define AzCssPathSelector_Id(v) { .Id = { .tag = AzCssPathSelectorTag_Id, .payload = v } }
#define AzCssPathSelector_PseudoSelector(v) { .PseudoSelector = { .tag = AzCssPathSelectorTag_PseudoSelector, .payload = v } }
#define AzCssPathSelector_DirectChildren { .DirectChildren = { .tag = AzCssPathSelectorTag_DirectChildren } }
#define AzCssPathSelector_Children { .Children = { .tag = AzCssPathSelectorTag_Children } }
#define AzStyleBackgroundContent_LinearGradient(v) { .LinearGradient = { .tag = AzStyleBackgroundContentTag_LinearGradient, .payload = v } }
#define AzStyleBackgroundContent_RadialGradient(v) { .RadialGradient = { .tag = AzStyleBackgroundContentTag_RadialGradient, .payload = v } }
#define AzStyleBackgroundContent_ConicGradient(v) { .ConicGradient = { .tag = AzStyleBackgroundContentTag_ConicGradient, .payload = v } }
#define AzStyleBackgroundContent_Image(v) { .Image = { .tag = AzStyleBackgroundContentTag_Image, .payload = v } }
#define AzStyleBackgroundContent_Color(v) { .Color = { .tag = AzStyleBackgroundContentTag_Color, .payload = v } }
#define AzStyleFontFamily_System(v) { .System = { .tag = AzStyleFontFamilyTag_System, .payload = v } }
#define AzStyleFontFamily_File(v) { .File = { .tag = AzStyleFontFamilyTag_File, .payload = v } }
#define AzStyleFontFamily_Ref(v) { .Ref = { .tag = AzStyleFontFamilyTag_Ref, .payload = v } }
#define AzScrollbarStyleValue_Auto { .Auto = { .tag = AzScrollbarStyleValueTag_Auto } }
#define AzScrollbarStyleValue_None { .None = { .tag = AzScrollbarStyleValueTag_None } }
#define AzScrollbarStyleValue_Inherit { .Inherit = { .tag = AzScrollbarStyleValueTag_Inherit } }
#define AzScrollbarStyleValue_Initial { .Initial = { .tag = AzScrollbarStyleValueTag_Initial } }
#define AzScrollbarStyleValue_Exact(v) { .Exact = { .tag = AzScrollbarStyleValueTag_Exact, .payload = v } }
#define AzStyleTransformVecValue_Auto { .Auto = { .tag = AzStyleTransformVecValueTag_Auto } }
#define AzStyleTransformVecValue_None { .None = { .tag = AzStyleTransformVecValueTag_None } }
#define AzStyleTransformVecValue_Inherit { .Inherit = { .tag = AzStyleTransformVecValueTag_Inherit } }
#define AzStyleTransformVecValue_Initial { .Initial = { .tag = AzStyleTransformVecValueTag_Initial } }
#define AzStyleTransformVecValue_Exact(v) { .Exact = { .tag = AzStyleTransformVecValueTag_Exact, .payload = v } }
#define AzSvgStyle_Fill(v) { .Fill = { .tag = AzSvgStyleTag_Fill, .payload = v } }
#define AzSvgStyle_Stroke(v) { .Stroke = { .tag = AzSvgStyleTag_Stroke, .payload = v } }
#define AzFmtValue_Bool(v) { .Bool = { .tag = AzFmtValueTag_Bool, .payload = v } }
#define AzFmtValue_Uchar(v) { .Uchar = { .tag = AzFmtValueTag_Uchar, .payload = v } }
#define AzFmtValue_Schar(v) { .Schar = { .tag = AzFmtValueTag_Schar, .payload = v } }
#define AzFmtValue_Ushort(v) { .Ushort = { .tag = AzFmtValueTag_Ushort, .payload = v } }
#define AzFmtValue_Sshort(v) { .Sshort = { .tag = AzFmtValueTag_Sshort, .payload = v } }
#define AzFmtValue_Uint(v) { .Uint = { .tag = AzFmtValueTag_Uint, .payload = v } }
#define AzFmtValue_Sint(v) { .Sint = { .tag = AzFmtValueTag_Sint, .payload = v } }
#define AzFmtValue_Ulong(v) { .Ulong = { .tag = AzFmtValueTag_Ulong, .payload = v } }
#define AzFmtValue_Slong(v) { .Slong = { .tag = AzFmtValueTag_Slong, .payload = v } }
#define AzFmtValue_Isize(v) { .Isize = { .tag = AzFmtValueTag_Isize, .payload = v } }
#define AzFmtValue_Usize(v) { .Usize = { .tag = AzFmtValueTag_Usize, .payload = v } }
#define AzFmtValue_Float(v) { .Float = { .tag = AzFmtValueTag_Float, .payload = v } }
#define AzFmtValue_Double(v) { .Double = { .tag = AzFmtValueTag_Double, .payload = v } }
#define AzFmtValue_Str(v) { .Str = { .tag = AzFmtValueTag_Str, .payload = v } }
#define AzFmtValue_StrVec(v) { .StrVec = { .tag = AzFmtValueTag_StrVec, .payload = v } }
#define AzOptionFileTypeList_None { .None = { .tag = AzOptionFileTypeListTag_None } }
#define AzOptionFileTypeList_Some(v) { .Some = { .tag = AzOptionFileTypeListTag_Some, .payload = v } }
#define AzOptionFile_None { .None = { .tag = AzOptionFileTag_None } }
#define AzOptionFile_Some(v) { .Some = { .tag = AzOptionFileTag_Some, .payload = v } }
#define AzOptionRawImage_None { .None = { .tag = AzOptionRawImageTag_None } }
#define AzOptionRawImage_Some(v) { .Some = { .tag = AzOptionRawImageTag_Some, .payload = v } }
#define AzOptionWaylandTheme_None { .None = { .tag = AzOptionWaylandThemeTag_None } }
#define AzOptionWaylandTheme_Some(v) { .Some = { .tag = AzOptionWaylandThemeTag_Some, .payload = v } }
#define AzResultRawImageDecodeImageError_Ok(v) { .Ok = { .tag = AzResultRawImageDecodeImageErrorTag_Ok, .payload = v } }
#define AzResultRawImageDecodeImageError_Err(v) { .Err = { .tag = AzResultRawImageDecodeImageErrorTag_Err, .payload = v } }
#define AzXmlStreamError_UnexpectedEndOfStream { .UnexpectedEndOfStream = { .tag = AzXmlStreamErrorTag_UnexpectedEndOfStream } }
#define AzXmlStreamError_InvalidName { .InvalidName = { .tag = AzXmlStreamErrorTag_InvalidName } }
#define AzXmlStreamError_NonXmlChar(v) { .NonXmlChar = { .tag = AzXmlStreamErrorTag_NonXmlChar, .payload = v } }
#define AzXmlStreamError_InvalidChar(v) { .InvalidChar = { .tag = AzXmlStreamErrorTag_InvalidChar, .payload = v } }
#define AzXmlStreamError_InvalidCharMultiple(v) { .InvalidCharMultiple = { .tag = AzXmlStreamErrorTag_InvalidCharMultiple, .payload = v } }
#define AzXmlStreamError_InvalidQuote(v) { .InvalidQuote = { .tag = AzXmlStreamErrorTag_InvalidQuote, .payload = v } }
#define AzXmlStreamError_InvalidSpace(v) { .InvalidSpace = { .tag = AzXmlStreamErrorTag_InvalidSpace, .payload = v } }
#define AzXmlStreamError_InvalidString(v) { .InvalidString = { .tag = AzXmlStreamErrorTag_InvalidString, .payload = v } }
#define AzXmlStreamError_InvalidReference { .InvalidReference = { .tag = AzXmlStreamErrorTag_InvalidReference } }
#define AzXmlStreamError_InvalidExternalID { .InvalidExternalID = { .tag = AzXmlStreamErrorTag_InvalidExternalID } }
#define AzXmlStreamError_InvalidCommentData { .InvalidCommentData = { .tag = AzXmlStreamErrorTag_InvalidCommentData } }
#define AzXmlStreamError_InvalidCommentEnd { .InvalidCommentEnd = { .tag = AzXmlStreamErrorTag_InvalidCommentEnd } }
#define AzXmlStreamError_InvalidCharacterData { .InvalidCharacterData = { .tag = AzXmlStreamErrorTag_InvalidCharacterData } }
#define AzMenuItem_Label(v) { .Label = { .tag = AzMenuItemTag_Label, .payload = v } }
#define AzMenuItem_Separator { .Separator = { .tag = AzMenuItemTag_Separator } }
#define AzMenuItem_BreakLine { .BreakLine = { .tag = AzMenuItemTag_BreakLine } }
#define AzStyleBackgroundContentVecValue_Auto { .Auto = { .tag = AzStyleBackgroundContentVecValueTag_Auto } }
#define AzStyleBackgroundContentVecValue_None { .None = { .tag = AzStyleBackgroundContentVecValueTag_None } }
#define AzStyleBackgroundContentVecValue_Inherit { .Inherit = { .tag = AzStyleBackgroundContentVecValueTag_Inherit } }
#define AzStyleBackgroundContentVecValue_Initial { .Initial = { .tag = AzStyleBackgroundContentVecValueTag_Initial } }
#define AzStyleBackgroundContentVecValue_Exact(v) { .Exact = { .tag = AzStyleBackgroundContentVecValueTag_Exact, .payload = v } }
#define AzStyleFontFamilyVecValue_Auto { .Auto = { .tag = AzStyleFontFamilyVecValueTag_Auto } }
#define AzStyleFontFamilyVecValue_None { .None = { .tag = AzStyleFontFamilyVecValueTag_None } }
#define AzStyleFontFamilyVecValue_Inherit { .Inherit = { .tag = AzStyleFontFamilyVecValueTag_Inherit } }
#define AzStyleFontFamilyVecValue_Initial { .Initial = { .tag = AzStyleFontFamilyVecValueTag_Initial } }
#define AzStyleFontFamilyVecValue_Exact(v) { .Exact = { .tag = AzStyleFontFamilyVecValueTag_Exact, .payload = v } }
#define AzCssProperty_TextColor(v) { .TextColor = { .tag = AzCssPropertyTag_TextColor, .payload = v } }
#define AzCssProperty_FontSize(v) { .FontSize = { .tag = AzCssPropertyTag_FontSize, .payload = v } }
#define AzCssProperty_FontFamily(v) { .FontFamily = { .tag = AzCssPropertyTag_FontFamily, .payload = v } }
#define AzCssProperty_TextAlign(v) { .TextAlign = { .tag = AzCssPropertyTag_TextAlign, .payload = v } }
#define AzCssProperty_LetterSpacing(v) { .LetterSpacing = { .tag = AzCssPropertyTag_LetterSpacing, .payload = v } }
#define AzCssProperty_LineHeight(v) { .LineHeight = { .tag = AzCssPropertyTag_LineHeight, .payload = v } }
#define AzCssProperty_WordSpacing(v) { .WordSpacing = { .tag = AzCssPropertyTag_WordSpacing, .payload = v } }
#define AzCssProperty_TabWidth(v) { .TabWidth = { .tag = AzCssPropertyTag_TabWidth, .payload = v } }
#define AzCssProperty_Cursor(v) { .Cursor = { .tag = AzCssPropertyTag_Cursor, .payload = v } }
#define AzCssProperty_Display(v) { .Display = { .tag = AzCssPropertyTag_Display, .payload = v } }
#define AzCssProperty_Float(v) { .Float = { .tag = AzCssPropertyTag_Float, .payload = v } }
#define AzCssProperty_BoxSizing(v) { .BoxSizing = { .tag = AzCssPropertyTag_BoxSizing, .payload = v } }
#define AzCssProperty_Width(v) { .Width = { .tag = AzCssPropertyTag_Width, .payload = v } }
#define AzCssProperty_Height(v) { .Height = { .tag = AzCssPropertyTag_Height, .payload = v } }
#define AzCssProperty_MinWidth(v) { .MinWidth = { .tag = AzCssPropertyTag_MinWidth, .payload = v } }
#define AzCssProperty_MinHeight(v) { .MinHeight = { .tag = AzCssPropertyTag_MinHeight, .payload = v } }
#define AzCssProperty_MaxWidth(v) { .MaxWidth = { .tag = AzCssPropertyTag_MaxWidth, .payload = v } }
#define AzCssProperty_MaxHeight(v) { .MaxHeight = { .tag = AzCssPropertyTag_MaxHeight, .payload = v } }
#define AzCssProperty_Position(v) { .Position = { .tag = AzCssPropertyTag_Position, .payload = v } }
#define AzCssProperty_Top(v) { .Top = { .tag = AzCssPropertyTag_Top, .payload = v } }
#define AzCssProperty_Right(v) { .Right = { .tag = AzCssPropertyTag_Right, .payload = v } }
#define AzCssProperty_Left(v) { .Left = { .tag = AzCssPropertyTag_Left, .payload = v } }
#define AzCssProperty_Bottom(v) { .Bottom = { .tag = AzCssPropertyTag_Bottom, .payload = v } }
#define AzCssProperty_FlexWrap(v) { .FlexWrap = { .tag = AzCssPropertyTag_FlexWrap, .payload = v } }
#define AzCssProperty_FlexDirection(v) { .FlexDirection = { .tag = AzCssPropertyTag_FlexDirection, .payload = v } }
#define AzCssProperty_FlexGrow(v) { .FlexGrow = { .tag = AzCssPropertyTag_FlexGrow, .payload = v } }
#define AzCssProperty_FlexShrink(v) { .FlexShrink = { .tag = AzCssPropertyTag_FlexShrink, .payload = v } }
#define AzCssProperty_JustifyContent(v) { .JustifyContent = { .tag = AzCssPropertyTag_JustifyContent, .payload = v } }
#define AzCssProperty_AlignItems(v) { .AlignItems = { .tag = AzCssPropertyTag_AlignItems, .payload = v } }
#define AzCssProperty_AlignContent(v) { .AlignContent = { .tag = AzCssPropertyTag_AlignContent, .payload = v } }
#define AzCssProperty_BackgroundContent(v) { .BackgroundContent = { .tag = AzCssPropertyTag_BackgroundContent, .payload = v } }
#define AzCssProperty_BackgroundPosition(v) { .BackgroundPosition = { .tag = AzCssPropertyTag_BackgroundPosition, .payload = v } }
#define AzCssProperty_BackgroundSize(v) { .BackgroundSize = { .tag = AzCssPropertyTag_BackgroundSize, .payload = v } }
#define AzCssProperty_BackgroundRepeat(v) { .BackgroundRepeat = { .tag = AzCssPropertyTag_BackgroundRepeat, .payload = v } }
#define AzCssProperty_OverflowX(v) { .OverflowX = { .tag = AzCssPropertyTag_OverflowX, .payload = v } }
#define AzCssProperty_OverflowY(v) { .OverflowY = { .tag = AzCssPropertyTag_OverflowY, .payload = v } }
#define AzCssProperty_PaddingTop(v) { .PaddingTop = { .tag = AzCssPropertyTag_PaddingTop, .payload = v } }
#define AzCssProperty_PaddingLeft(v) { .PaddingLeft = { .tag = AzCssPropertyTag_PaddingLeft, .payload = v } }
#define AzCssProperty_PaddingRight(v) { .PaddingRight = { .tag = AzCssPropertyTag_PaddingRight, .payload = v } }
#define AzCssProperty_PaddingBottom(v) { .PaddingBottom = { .tag = AzCssPropertyTag_PaddingBottom, .payload = v } }
#define AzCssProperty_MarginTop(v) { .MarginTop = { .tag = AzCssPropertyTag_MarginTop, .payload = v } }
#define AzCssProperty_MarginLeft(v) { .MarginLeft = { .tag = AzCssPropertyTag_MarginLeft, .payload = v } }
#define AzCssProperty_MarginRight(v) { .MarginRight = { .tag = AzCssPropertyTag_MarginRight, .payload = v } }
#define AzCssProperty_MarginBottom(v) { .MarginBottom = { .tag = AzCssPropertyTag_MarginBottom, .payload = v } }
#define AzCssProperty_BorderTopLeftRadius(v) { .BorderTopLeftRadius = { .tag = AzCssPropertyTag_BorderTopLeftRadius, .payload = v } }
#define AzCssProperty_BorderTopRightRadius(v) { .BorderTopRightRadius = { .tag = AzCssPropertyTag_BorderTopRightRadius, .payload = v } }
#define AzCssProperty_BorderBottomLeftRadius(v) { .BorderBottomLeftRadius = { .tag = AzCssPropertyTag_BorderBottomLeftRadius, .payload = v } }
#define AzCssProperty_BorderBottomRightRadius(v) { .BorderBottomRightRadius = { .tag = AzCssPropertyTag_BorderBottomRightRadius, .payload = v } }
#define AzCssProperty_BorderTopColor(v) { .BorderTopColor = { .tag = AzCssPropertyTag_BorderTopColor, .payload = v } }
#define AzCssProperty_BorderRightColor(v) { .BorderRightColor = { .tag = AzCssPropertyTag_BorderRightColor, .payload = v } }
#define AzCssProperty_BorderLeftColor(v) { .BorderLeftColor = { .tag = AzCssPropertyTag_BorderLeftColor, .payload = v } }
#define AzCssProperty_BorderBottomColor(v) { .BorderBottomColor = { .tag = AzCssPropertyTag_BorderBottomColor, .payload = v } }
#define AzCssProperty_BorderTopStyle(v) { .BorderTopStyle = { .tag = AzCssPropertyTag_BorderTopStyle, .payload = v } }
#define AzCssProperty_BorderRightStyle(v) { .BorderRightStyle = { .tag = AzCssPropertyTag_BorderRightStyle, .payload = v } }
#define AzCssProperty_BorderLeftStyle(v) { .BorderLeftStyle = { .tag = AzCssPropertyTag_BorderLeftStyle, .payload = v } }
#define AzCssProperty_BorderBottomStyle(v) { .BorderBottomStyle = { .tag = AzCssPropertyTag_BorderBottomStyle, .payload = v } }
#define AzCssProperty_BorderTopWidth(v) { .BorderTopWidth = { .tag = AzCssPropertyTag_BorderTopWidth, .payload = v } }
#define AzCssProperty_BorderRightWidth(v) { .BorderRightWidth = { .tag = AzCssPropertyTag_BorderRightWidth, .payload = v } }
#define AzCssProperty_BorderLeftWidth(v) { .BorderLeftWidth = { .tag = AzCssPropertyTag_BorderLeftWidth, .payload = v } }
#define AzCssProperty_BorderBottomWidth(v) { .BorderBottomWidth = { .tag = AzCssPropertyTag_BorderBottomWidth, .payload = v } }
#define AzCssProperty_BoxShadowLeft(v) { .BoxShadowLeft = { .tag = AzCssPropertyTag_BoxShadowLeft, .payload = v } }
#define AzCssProperty_BoxShadowRight(v) { .BoxShadowRight = { .tag = AzCssPropertyTag_BoxShadowRight, .payload = v } }
#define AzCssProperty_BoxShadowTop(v) { .BoxShadowTop = { .tag = AzCssPropertyTag_BoxShadowTop, .payload = v } }
#define AzCssProperty_BoxShadowBottom(v) { .BoxShadowBottom = { .tag = AzCssPropertyTag_BoxShadowBottom, .payload = v } }
#define AzCssProperty_ScrollbarStyle(v) { .ScrollbarStyle = { .tag = AzCssPropertyTag_ScrollbarStyle, .payload = v } }
#define AzCssProperty_Opacity(v) { .Opacity = { .tag = AzCssPropertyTag_Opacity, .payload = v } }
#define AzCssProperty_Transform(v) { .Transform = { .tag = AzCssPropertyTag_Transform, .payload = v } }
#define AzCssProperty_TransformOrigin(v) { .TransformOrigin = { .tag = AzCssPropertyTag_TransformOrigin, .payload = v } }
#define AzCssProperty_PerspectiveOrigin(v) { .PerspectiveOrigin = { .tag = AzCssPropertyTag_PerspectiveOrigin, .payload = v } }
#define AzCssProperty_BackfaceVisibility(v) { .BackfaceVisibility = { .tag = AzCssPropertyTag_BackfaceVisibility, .payload = v } }
#define AzCssPropertySource_Css(v) { .Css = { .tag = AzCssPropertySourceTag_Css, .payload = v } }
#define AzCssPropertySource_Inline { .Inline = { .tag = AzCssPropertySourceTag_Inline } }
#define AzOptionCssProperty_None { .None = { .tag = AzOptionCssPropertyTag_None } }
#define AzOptionCssProperty_Some(v) { .Some = { .tag = AzOptionCssPropertyTag_Some, .payload = v } }
#define AzNodeDataInlineCssProperty_Normal(v) { .Normal = { .tag = AzNodeDataInlineCssPropertyTag_Normal, .payload = v } }
#define AzNodeDataInlineCssProperty_Active(v) { .Active = { .tag = AzNodeDataInlineCssPropertyTag_Active, .payload = v } }
#define AzNodeDataInlineCssProperty_Focus(v) { .Focus = { .tag = AzNodeDataInlineCssPropertyTag_Focus, .payload = v } }
#define AzNodeDataInlineCssProperty_Hover(v) { .Hover = { .tag = AzNodeDataInlineCssPropertyTag_Hover, .payload = v } }
#define AzSvgNode_MultiPolygonCollection(v) { .MultiPolygonCollection = { .tag = AzSvgNodeTag_MultiPolygonCollection, .payload = v } }
#define AzSvgNode_MultiPolygon(v) { .MultiPolygon = { .tag = AzSvgNodeTag_MultiPolygon, .payload = v } }
#define AzSvgNode_Path(v) { .Path = { .tag = AzSvgNodeTag_Path, .payload = v } }
#define AzSvgNode_Circle(v) { .Circle = { .tag = AzSvgNodeTag_Circle, .payload = v } }
#define AzSvgNode_Rect(v) { .Rect = { .tag = AzSvgNodeTag_Rect, .payload = v } }
#define AzOptionWindowState_None { .None = { .tag = AzOptionWindowStateTag_None } }
#define AzOptionWindowState_Some(v) { .Some = { .tag = AzOptionWindowStateTag_Some, .payload = v } }
#define AzOptionInlineText_None { .None = { .tag = AzOptionInlineTextTag_None } }
#define AzOptionInlineText_Some(v) { .Some = { .tag = AzOptionInlineTextTag_Some, .payload = v } }
#define AzXmlParseError_InvalidDeclaration(v) { .InvalidDeclaration = { .tag = AzXmlParseErrorTag_InvalidDeclaration, .payload = v } }
#define AzXmlParseError_InvalidComment(v) { .InvalidComment = { .tag = AzXmlParseErrorTag_InvalidComment, .payload = v } }
#define AzXmlParseError_InvalidPI(v) { .InvalidPI = { .tag = AzXmlParseErrorTag_InvalidPI, .payload = v } }
#define AzXmlParseError_InvalidDoctype(v) { .InvalidDoctype = { .tag = AzXmlParseErrorTag_InvalidDoctype, .payload = v } }
#define AzXmlParseError_InvalidEntity(v) { .InvalidEntity = { .tag = AzXmlParseErrorTag_InvalidEntity, .payload = v } }
#define AzXmlParseError_InvalidElement(v) { .InvalidElement = { .tag = AzXmlParseErrorTag_InvalidElement, .payload = v } }
#define AzXmlParseError_InvalidAttribute(v) { .InvalidAttribute = { .tag = AzXmlParseErrorTag_InvalidAttribute, .payload = v } }
#define AzXmlParseError_InvalidCdata(v) { .InvalidCdata = { .tag = AzXmlParseErrorTag_InvalidCdata, .payload = v } }
#define AzXmlParseError_InvalidCharData(v) { .InvalidCharData = { .tag = AzXmlParseErrorTag_InvalidCharData, .payload = v } }
#define AzXmlParseError_UnknownToken(v) { .UnknownToken = { .tag = AzXmlParseErrorTag_UnknownToken, .payload = v } }
#define AzFocusTarget_Id(v) { .Id = { .tag = AzFocusTargetTag_Id, .payload = v } }
#define AzFocusTarget_Path(v) { .Path = { .tag = AzFocusTargetTag_Path, .payload = v } }
#define AzFocusTarget_Previous { .Previous = { .tag = AzFocusTargetTag_Previous } }
#define AzFocusTarget_Next { .Next = { .tag = AzFocusTargetTag_Next } }
#define AzFocusTarget_First { .First = { .tag = AzFocusTargetTag_First } }
#define AzFocusTarget_Last { .Last = { .tag = AzFocusTargetTag_Last } }
#define AzFocusTarget_NoFocus { .NoFocus = { .tag = AzFocusTargetTag_NoFocus } }
#define AzCssDeclaration_Static(v) { .Static = { .tag = AzCssDeclarationTag_Static, .payload = v } }
#define AzCssDeclaration_Dynamic(v) { .Dynamic = { .tag = AzCssDeclarationTag_Dynamic, .payload = v } }
#define AzXmlError_NoParserAvailable { .NoParserAvailable = { .tag = AzXmlErrorTag_NoParserAvailable } }
#define AzXmlError_InvalidXmlPrefixUri(v) { .InvalidXmlPrefixUri = { .tag = AzXmlErrorTag_InvalidXmlPrefixUri, .payload = v } }
#define AzXmlError_UnexpectedXmlUri(v) { .UnexpectedXmlUri = { .tag = AzXmlErrorTag_UnexpectedXmlUri, .payload = v } }
#define AzXmlError_UnexpectedXmlnsUri(v) { .UnexpectedXmlnsUri = { .tag = AzXmlErrorTag_UnexpectedXmlnsUri, .payload = v } }
#define AzXmlError_InvalidElementNamePrefix(v) { .InvalidElementNamePrefix = { .tag = AzXmlErrorTag_InvalidElementNamePrefix, .payload = v } }
#define AzXmlError_DuplicatedNamespace(v) { .DuplicatedNamespace = { .tag = AzXmlErrorTag_DuplicatedNamespace, .payload = v } }
#define AzXmlError_UnknownNamespace(v) { .UnknownNamespace = { .tag = AzXmlErrorTag_UnknownNamespace, .payload = v } }
#define AzXmlError_UnexpectedCloseTag(v) { .UnexpectedCloseTag = { .tag = AzXmlErrorTag_UnexpectedCloseTag, .payload = v } }
#define AzXmlError_UnexpectedEntityCloseTag(v) { .UnexpectedEntityCloseTag = { .tag = AzXmlErrorTag_UnexpectedEntityCloseTag, .payload = v } }
#define AzXmlError_UnknownEntityReference(v) { .UnknownEntityReference = { .tag = AzXmlErrorTag_UnknownEntityReference, .payload = v } }
#define AzXmlError_MalformedEntityReference(v) { .MalformedEntityReference = { .tag = AzXmlErrorTag_MalformedEntityReference, .payload = v } }
#define AzXmlError_EntityReferenceLoop(v) { .EntityReferenceLoop = { .tag = AzXmlErrorTag_EntityReferenceLoop, .payload = v } }
#define AzXmlError_InvalidAttributeValue(v) { .InvalidAttributeValue = { .tag = AzXmlErrorTag_InvalidAttributeValue, .payload = v } }
#define AzXmlError_DuplicatedAttribute(v) { .DuplicatedAttribute = { .tag = AzXmlErrorTag_DuplicatedAttribute, .payload = v } }
#define AzXmlError_NoRootNode { .NoRootNode = { .tag = AzXmlErrorTag_NoRootNode } }
#define AzXmlError_SizeLimit { .SizeLimit = { .tag = AzXmlErrorTag_SizeLimit } }
#define AzXmlError_ParserError(v) { .ParserError = { .tag = AzXmlErrorTag_ParserError, .payload = v } }
#define AzOptionDom_None { .None = { .tag = AzOptionDomTag_None } }
#define AzOptionDom_Some(v) { .Some = { .tag = AzOptionDomTag_Some, .payload = v } }
#define AzResultXmlXmlError_Ok(v) { .Ok = { .tag = AzResultXmlXmlErrorTag_Ok, .payload = v } }
#define AzResultXmlXmlError_Err(v) { .Err = { .tag = AzResultXmlXmlErrorTag_Err, .payload = v } }
#define AzSvgParseError_NoParserAvailable { .NoParserAvailable = { .tag = AzSvgParseErrorTag_NoParserAvailable } }
#define AzSvgParseError_InvalidFileSuffix { .InvalidFileSuffix = { .tag = AzSvgParseErrorTag_InvalidFileSuffix } }
#define AzSvgParseError_FileOpenFailed { .FileOpenFailed = { .tag = AzSvgParseErrorTag_FileOpenFailed } }
#define AzSvgParseError_NotAnUtf8Str { .NotAnUtf8Str = { .tag = AzSvgParseErrorTag_NotAnUtf8Str } }
#define AzSvgParseError_MalformedGZip { .MalformedGZip = { .tag = AzSvgParseErrorTag_MalformedGZip } }
#define AzSvgParseError_InvalidSize { .InvalidSize = { .tag = AzSvgParseErrorTag_InvalidSize } }
#define AzSvgParseError_ParsingFailed(v) { .ParsingFailed = { .tag = AzSvgParseErrorTag_ParsingFailed, .payload = v } }
#define AzResultSvgXmlNodeSvgParseError_Ok(v) { .Ok = { .tag = AzResultSvgXmlNodeSvgParseErrorTag_Ok, .payload = v } }
#define AzResultSvgXmlNodeSvgParseError_Err(v) { .Err = { .tag = AzResultSvgXmlNodeSvgParseErrorTag_Err, .payload = v } }
#define AzResultSvgSvgParseError_Ok(v) { .Ok = { .tag = AzResultSvgSvgParseErrorTag_Ok, .payload = v } }
#define AzResultSvgSvgParseError_Err(v) { .Err = { .tag = AzResultSvgSvgParseErrorTag_Err, .payload = v } }
AzAccessibilityState AzAccessibilityStateVecArray[] = {};
#define AzAccessibilityStateVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzAccessibilityState), .cap = sizeof(v) / sizeof(AzAccessibilityState), .destructor = { .NoDestructor = { .tag = AzAccessibilityStateVecDestructorTag_NoDestructor, }, }, }
#define AzAccessibilityStateVec_empty { .ptr = &AzAccessibilityStateVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzAccessibilityStateVecDestructorTag_NoDestructor, }, }, }

AzMenuItem AzMenuItemVecArray[] = {};
#define AzMenuItemVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzMenuItem), .cap = sizeof(v) / sizeof(AzMenuItem), .destructor = { .NoDestructor = { .tag = AzMenuItemVecDestructorTag_NoDestructor, }, }, }
#define AzMenuItemVec_empty { .ptr = &AzMenuItemVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzMenuItemVecDestructorTag_NoDestructor, }, }, }

AzTessellatedSvgNode AzTessellatedSvgNodeVecArray[] = {};
#define AzTessellatedSvgNodeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzTessellatedSvgNode), .cap = sizeof(v) / sizeof(AzTessellatedSvgNode), .destructor = { .NoDestructor = { .tag = AzTessellatedSvgNodeVecDestructorTag_NoDestructor, }, }, }
#define AzTessellatedSvgNodeVec_empty { .ptr = &AzTessellatedSvgNodeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzTessellatedSvgNodeVecDestructorTag_NoDestructor, }, }, }

AzStyleFontFamily AzStyleFontFamilyVecArray[] = {};
#define AzStyleFontFamilyVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStyleFontFamily), .cap = sizeof(v) / sizeof(AzStyleFontFamily), .destructor = { .NoDestructor = { .tag = AzStyleFontFamilyVecDestructorTag_NoDestructor, }, }, }
#define AzStyleFontFamilyVec_empty { .ptr = &AzStyleFontFamilyVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStyleFontFamilyVecDestructorTag_NoDestructor, }, }, }

AzXmlNode AzXmlNodeVecArray[] = {};
#define AzXmlNodeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzXmlNode), .cap = sizeof(v) / sizeof(AzXmlNode), .destructor = { .NoDestructor = { .tag = AzXmlNodeVecDestructorTag_NoDestructor, }, }, }
#define AzXmlNodeVec_empty { .ptr = &AzXmlNodeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzXmlNodeVecDestructorTag_NoDestructor, }, }, }

AzFmtArg AzFmtArgVecArray[] = {};
#define AzFmtArgVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzFmtArg), .cap = sizeof(v) / sizeof(AzFmtArg), .destructor = { .NoDestructor = { .tag = AzFmtArgVecDestructorTag_NoDestructor, }, }, }
#define AzFmtArgVec_empty { .ptr = &AzFmtArgVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzFmtArgVecDestructorTag_NoDestructor, }, }, }

AzInlineLine AzInlineLineVecArray[] = {};
#define AzInlineLineVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzInlineLine), .cap = sizeof(v) / sizeof(AzInlineLine), .destructor = { .NoDestructor = { .tag = AzInlineLineVecDestructorTag_NoDestructor, }, }, }
#define AzInlineLineVec_empty { .ptr = &AzInlineLineVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzInlineLineVecDestructorTag_NoDestructor, }, }, }

AzInlineWord AzInlineWordVecArray[] = {};
#define AzInlineWordVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzInlineWord), .cap = sizeof(v) / sizeof(AzInlineWord), .destructor = { .NoDestructor = { .tag = AzInlineWordVecDestructorTag_NoDestructor, }, }, }
#define AzInlineWordVec_empty { .ptr = &AzInlineWordVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzInlineWordVecDestructorTag_NoDestructor, }, }, }

AzInlineGlyph AzInlineGlyphVecArray[] = {};
#define AzInlineGlyphVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzInlineGlyph), .cap = sizeof(v) / sizeof(AzInlineGlyph), .destructor = { .NoDestructor = { .tag = AzInlineGlyphVecDestructorTag_NoDestructor, }, }, }
#define AzInlineGlyphVec_empty { .ptr = &AzInlineGlyphVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzInlineGlyphVecDestructorTag_NoDestructor, }, }, }

AzInlineTextHit AzInlineTextHitVecArray[] = {};
#define AzInlineTextHitVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzInlineTextHit), .cap = sizeof(v) / sizeof(AzInlineTextHit), .destructor = { .NoDestructor = { .tag = AzInlineTextHitVecDestructorTag_NoDestructor, }, }, }
#define AzInlineTextHitVec_empty { .ptr = &AzInlineTextHitVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzInlineTextHitVecDestructorTag_NoDestructor, }, }, }

AzMonitor AzMonitorVecArray[] = {};
#define AzMonitorVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzMonitor), .cap = sizeof(v) / sizeof(AzMonitor), .destructor = { .NoDestructor = { .tag = AzMonitorVecDestructorTag_NoDestructor, }, }, }
#define AzMonitorVec_empty { .ptr = &AzMonitorVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzMonitorVecDestructorTag_NoDestructor, }, }, }

AzVideoMode AzVideoModeVecArray[] = {};
#define AzVideoModeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzVideoMode), .cap = sizeof(v) / sizeof(AzVideoMode), .destructor = { .NoDestructor = { .tag = AzVideoModeVecDestructorTag_NoDestructor, }, }, }
#define AzVideoModeVec_empty { .ptr = &AzVideoModeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzVideoModeVecDestructorTag_NoDestructor, }, }, }

AzDom AzDomVecArray[] = {};
#define AzDomVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzDom), .cap = sizeof(v) / sizeof(AzDom), .destructor = { .NoDestructor = { .tag = AzDomVecDestructorTag_NoDestructor, }, }, }
#define AzDomVec_empty { .ptr = &AzDomVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzDomVecDestructorTag_NoDestructor, }, }, }

AzIdOrClass AzIdOrClassVecArray[] = {};
#define AzIdOrClassVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzIdOrClass), .cap = sizeof(v) / sizeof(AzIdOrClass), .destructor = { .NoDestructor = { .tag = AzIdOrClassVecDestructorTag_NoDestructor, }, }, }
#define AzIdOrClassVec_empty { .ptr = &AzIdOrClassVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzIdOrClassVecDestructorTag_NoDestructor, }, }, }

AzNodeDataInlineCssProperty AzNodeDataInlineCssPropertyVecArray[] = {};
#define AzNodeDataInlineCssPropertyVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzNodeDataInlineCssProperty), .cap = sizeof(v) / sizeof(AzNodeDataInlineCssProperty), .destructor = { .NoDestructor = { .tag = AzNodeDataInlineCssPropertyVecDestructorTag_NoDestructor, }, }, }
#define AzNodeDataInlineCssPropertyVec_empty { .ptr = &AzNodeDataInlineCssPropertyVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzNodeDataInlineCssPropertyVecDestructorTag_NoDestructor, }, }, }

AzStyleBackgroundContent AzStyleBackgroundContentVecArray[] = {};
#define AzStyleBackgroundContentVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStyleBackgroundContent), .cap = sizeof(v) / sizeof(AzStyleBackgroundContent), .destructor = { .NoDestructor = { .tag = AzStyleBackgroundContentVecDestructorTag_NoDestructor, }, }, }
#define AzStyleBackgroundContentVec_empty { .ptr = &AzStyleBackgroundContentVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStyleBackgroundContentVecDestructorTag_NoDestructor, }, }, }

AzStyleBackgroundPosition AzStyleBackgroundPositionVecArray[] = {};
#define AzStyleBackgroundPositionVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStyleBackgroundPosition), .cap = sizeof(v) / sizeof(AzStyleBackgroundPosition), .destructor = { .NoDestructor = { .tag = AzStyleBackgroundPositionVecDestructorTag_NoDestructor, }, }, }
#define AzStyleBackgroundPositionVec_empty { .ptr = &AzStyleBackgroundPositionVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStyleBackgroundPositionVecDestructorTag_NoDestructor, }, }, }

AzStyleBackgroundRepeat AzStyleBackgroundRepeatVecArray[] = {};
#define AzStyleBackgroundRepeatVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStyleBackgroundRepeat), .cap = sizeof(v) / sizeof(AzStyleBackgroundRepeat), .destructor = { .NoDestructor = { .tag = AzStyleBackgroundRepeatVecDestructorTag_NoDestructor, }, }, }
#define AzStyleBackgroundRepeatVec_empty { .ptr = &AzStyleBackgroundRepeatVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStyleBackgroundRepeatVecDestructorTag_NoDestructor, }, }, }

AzStyleBackgroundSize AzStyleBackgroundSizeVecArray[] = {};
#define AzStyleBackgroundSizeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStyleBackgroundSize), .cap = sizeof(v) / sizeof(AzStyleBackgroundSize), .destructor = { .NoDestructor = { .tag = AzStyleBackgroundSizeVecDestructorTag_NoDestructor, }, }, }
#define AzStyleBackgroundSizeVec_empty { .ptr = &AzStyleBackgroundSizeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStyleBackgroundSizeVecDestructorTag_NoDestructor, }, }, }

AzStyleTransform AzStyleTransformVecArray[] = {};
#define AzStyleTransformVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStyleTransform), .cap = sizeof(v) / sizeof(AzStyleTransform), .destructor = { .NoDestructor = { .tag = AzStyleTransformVecDestructorTag_NoDestructor, }, }, }
#define AzStyleTransformVec_empty { .ptr = &AzStyleTransformVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStyleTransformVecDestructorTag_NoDestructor, }, }, }

AzCssProperty AzCssPropertyVecArray[] = {};
#define AzCssPropertyVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzCssProperty), .cap = sizeof(v) / sizeof(AzCssProperty), .destructor = { .NoDestructor = { .tag = AzCssPropertyVecDestructorTag_NoDestructor, }, }, }
#define AzCssPropertyVec_empty { .ptr = &AzCssPropertyVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzCssPropertyVecDestructorTag_NoDestructor, }, }, }

AzSvgMultiPolygon AzSvgMultiPolygonVecArray[] = {};
#define AzSvgMultiPolygonVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzSvgMultiPolygon), .cap = sizeof(v) / sizeof(AzSvgMultiPolygon), .destructor = { .NoDestructor = { .tag = AzSvgMultiPolygonVecDestructorTag_NoDestructor, }, }, }
#define AzSvgMultiPolygonVec_empty { .ptr = &AzSvgMultiPolygonVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzSvgMultiPolygonVecDestructorTag_NoDestructor, }, }, }

AzSvgPath AzSvgPathVecArray[] = {};
#define AzSvgPathVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzSvgPath), .cap = sizeof(v) / sizeof(AzSvgPath), .destructor = { .NoDestructor = { .tag = AzSvgPathVecDestructorTag_NoDestructor, }, }, }
#define AzSvgPathVec_empty { .ptr = &AzSvgPathVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzSvgPathVecDestructorTag_NoDestructor, }, }, }

AzVertexAttribute AzVertexAttributeVecArray[] = {};
#define AzVertexAttributeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzVertexAttribute), .cap = sizeof(v) / sizeof(AzVertexAttribute), .destructor = { .NoDestructor = { .tag = AzVertexAttributeVecDestructorTag_NoDestructor, }, }, }
#define AzVertexAttributeVec_empty { .ptr = &AzVertexAttributeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzVertexAttributeVecDestructorTag_NoDestructor, }, }, }

AzSvgPathElement AzSvgPathElementVecArray[] = {};
#define AzSvgPathElementVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzSvgPathElement), .cap = sizeof(v) / sizeof(AzSvgPathElement), .destructor = { .NoDestructor = { .tag = AzSvgPathElementVecDestructorTag_NoDestructor, }, }, }
#define AzSvgPathElementVec_empty { .ptr = &AzSvgPathElementVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzSvgPathElementVecDestructorTag_NoDestructor, }, }, }

AzSvgVertex AzSvgVertexVecArray[] = {};
#define AzSvgVertexVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzSvgVertex), .cap = sizeof(v) / sizeof(AzSvgVertex), .destructor = { .NoDestructor = { .tag = AzSvgVertexVecDestructorTag_NoDestructor, }, }, }
#define AzSvgVertexVec_empty { .ptr = &AzSvgVertexVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzSvgVertexVecDestructorTag_NoDestructor, }, }, }

uint32_t AzU32VecArray[] = {};
#define AzU32Vec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(uint32_t), .cap = sizeof(v) / sizeof(uint32_t), .destructor = { .NoDestructor = { .tag = AzU32VecDestructorTag_NoDestructor, }, }, }
#define AzU32Vec_empty { .ptr = &AzU32VecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzU32VecDestructorTag_NoDestructor, }, }, }

AzXWindowType AzXWindowTypeVecArray[] = {};
#define AzXWindowTypeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzXWindowType), .cap = sizeof(v) / sizeof(AzXWindowType), .destructor = { .NoDestructor = { .tag = AzXWindowTypeVecDestructorTag_NoDestructor, }, }, }
#define AzXWindowTypeVec_empty { .ptr = &AzXWindowTypeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzXWindowTypeVecDestructorTag_NoDestructor, }, }, }

AzVirtualKeyCode AzVirtualKeyCodeVecArray[] = {};
#define AzVirtualKeyCodeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzVirtualKeyCode), .cap = sizeof(v) / sizeof(AzVirtualKeyCode), .destructor = { .NoDestructor = { .tag = AzVirtualKeyCodeVecDestructorTag_NoDestructor, }, }, }
#define AzVirtualKeyCodeVec_empty { .ptr = &AzVirtualKeyCodeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzVirtualKeyCodeVecDestructorTag_NoDestructor, }, }, }

AzCascadeInfo AzCascadeInfoVecArray[] = {};
#define AzCascadeInfoVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzCascadeInfo), .cap = sizeof(v) / sizeof(AzCascadeInfo), .destructor = { .NoDestructor = { .tag = AzCascadeInfoVecDestructorTag_NoDestructor, }, }, }
#define AzCascadeInfoVec_empty { .ptr = &AzCascadeInfoVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzCascadeInfoVecDestructorTag_NoDestructor, }, }, }

uint32_t AzScanCodeVecArray[] = {};
#define AzScanCodeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(uint32_t), .cap = sizeof(v) / sizeof(uint32_t), .destructor = { .NoDestructor = { .tag = AzScanCodeVecDestructorTag_NoDestructor, }, }, }
#define AzScanCodeVec_empty { .ptr = &AzScanCodeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzScanCodeVecDestructorTag_NoDestructor, }, }, }

AzCssDeclaration AzCssDeclarationVecArray[] = {};
#define AzCssDeclarationVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzCssDeclaration), .cap = sizeof(v) / sizeof(AzCssDeclaration), .destructor = { .NoDestructor = { .tag = AzCssDeclarationVecDestructorTag_NoDestructor, }, }, }
#define AzCssDeclarationVec_empty { .ptr = &AzCssDeclarationVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzCssDeclarationVecDestructorTag_NoDestructor, }, }, }

AzCssPathSelector AzCssPathSelectorVecArray[] = {};
#define AzCssPathSelectorVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzCssPathSelector), .cap = sizeof(v) / sizeof(AzCssPathSelector), .destructor = { .NoDestructor = { .tag = AzCssPathSelectorVecDestructorTag_NoDestructor, }, }, }
#define AzCssPathSelectorVec_empty { .ptr = &AzCssPathSelectorVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzCssPathSelectorVecDestructorTag_NoDestructor, }, }, }

AzStylesheet AzStylesheetVecArray[] = {};
#define AzStylesheetVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStylesheet), .cap = sizeof(v) / sizeof(AzStylesheet), .destructor = { .NoDestructor = { .tag = AzStylesheetVecDestructorTag_NoDestructor, }, }, }
#define AzStylesheetVec_empty { .ptr = &AzStylesheetVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStylesheetVecDestructorTag_NoDestructor, }, }, }

AzCssRuleBlock AzCssRuleBlockVecArray[] = {};
#define AzCssRuleBlockVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzCssRuleBlock), .cap = sizeof(v) / sizeof(AzCssRuleBlock), .destructor = { .NoDestructor = { .tag = AzCssRuleBlockVecDestructorTag_NoDestructor, }, }, }
#define AzCssRuleBlockVec_empty { .ptr = &AzCssRuleBlockVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzCssRuleBlockVecDestructorTag_NoDestructor, }, }, }

uint16_t AzU16VecArray[] = {};
#define AzU16Vec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(uint16_t), .cap = sizeof(v) / sizeof(uint16_t), .destructor = { .NoDestructor = { .tag = AzU16VecDestructorTag_NoDestructor, }, }, }
#define AzU16Vec_empty { .ptr = &AzU16VecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzU16VecDestructorTag_NoDestructor, }, }, }

float AzF32VecArray[] = {};
#define AzF32Vec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(float), .cap = sizeof(v) / sizeof(float), .destructor = { .NoDestructor = { .tag = AzF32VecDestructorTag_NoDestructor, }, }, }
#define AzF32Vec_empty { .ptr = &AzF32VecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzF32VecDestructorTag_NoDestructor, }, }, }

uint8_t AzU8VecArray[] = {};
#define AzU8Vec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(uint8_t), .cap = sizeof(v) / sizeof(uint8_t), .destructor = { .NoDestructor = { .tag = AzU8VecDestructorTag_NoDestructor, }, }, }
#define AzU8Vec_empty { .ptr = &AzU8VecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzU8VecDestructorTag_NoDestructor, }, }, }

AzCallbackData AzCallbackDataVecArray[] = {};
#define AzCallbackDataVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzCallbackData), .cap = sizeof(v) / sizeof(AzCallbackData), .destructor = { .NoDestructor = { .tag = AzCallbackDataVecDestructorTag_NoDestructor, }, }, }
#define AzCallbackDataVec_empty { .ptr = &AzCallbackDataVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzCallbackDataVecDestructorTag_NoDestructor, }, }, }

AzDebugMessage AzDebugMessageVecArray[] = {};
#define AzDebugMessageVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzDebugMessage), .cap = sizeof(v) / sizeof(AzDebugMessage), .destructor = { .NoDestructor = { .tag = AzDebugMessageVecDestructorTag_NoDestructor, }, }, }
#define AzDebugMessageVec_empty { .ptr = &AzDebugMessageVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzDebugMessageVecDestructorTag_NoDestructor, }, }, }

uint32_t AzGLuintVecArray[] = {};
#define AzGLuintVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(uint32_t), .cap = sizeof(v) / sizeof(uint32_t), .destructor = { .NoDestructor = { .tag = AzGLuintVecDestructorTag_NoDestructor, }, }, }
#define AzGLuintVec_empty { .ptr = &AzGLuintVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzGLuintVecDestructorTag_NoDestructor, }, }, }

int32_t AzGLintVecArray[] = {};
#define AzGLintVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(int32_t), .cap = sizeof(v) / sizeof(int32_t), .destructor = { .NoDestructor = { .tag = AzGLintVecDestructorTag_NoDestructor, }, }, }
#define AzGLintVec_empty { .ptr = &AzGLintVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzGLintVecDestructorTag_NoDestructor, }, }, }

AzString AzStringVecArray[] = {};
#define AzStringVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzString), .cap = sizeof(v) / sizeof(AzString), .destructor = { .NoDestructor = { .tag = AzStringVecDestructorTag_NoDestructor, }, }, }
#define AzStringVec_empty { .ptr = &AzStringVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStringVecDestructorTag_NoDestructor, }, }, }

AzStringPair AzStringPairVecArray[] = {};
#define AzStringPairVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStringPair), .cap = sizeof(v) / sizeof(AzStringPair), .destructor = { .NoDestructor = { .tag = AzStringPairVecDestructorTag_NoDestructor, }, }, }
#define AzStringPairVec_empty { .ptr = &AzStringPairVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStringPairVecDestructorTag_NoDestructor, }, }, }

AzNormalizedLinearColorStop AzNormalizedLinearColorStopVecArray[] = {};
#define AzNormalizedLinearColorStopVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzNormalizedLinearColorStop), .cap = sizeof(v) / sizeof(AzNormalizedLinearColorStop), .destructor = { .NoDestructor = { .tag = AzNormalizedLinearColorStopVecDestructorTag_NoDestructor, }, }, }
#define AzNormalizedLinearColorStopVec_empty { .ptr = &AzNormalizedLinearColorStopVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzNormalizedLinearColorStopVecDestructorTag_NoDestructor, }, }, }

AzNormalizedRadialColorStop AzNormalizedRadialColorStopVecArray[] = {};
#define AzNormalizedRadialColorStopVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzNormalizedRadialColorStop), .cap = sizeof(v) / sizeof(AzNormalizedRadialColorStop), .destructor = { .NoDestructor = { .tag = AzNormalizedRadialColorStopVecDestructorTag_NoDestructor, }, }, }
#define AzNormalizedRadialColorStopVec_empty { .ptr = &AzNormalizedRadialColorStopVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzNormalizedRadialColorStopVecDestructorTag_NoDestructor, }, }, }

AzNodeId AzNodeIdVecArray[] = {};
#define AzNodeIdVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzNodeId), .cap = sizeof(v) / sizeof(AzNodeId), .destructor = { .NoDestructor = { .tag = AzNodeIdVecDestructorTag_NoDestructor, }, }, }
#define AzNodeIdVec_empty { .ptr = &AzNodeIdVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzNodeIdVecDestructorTag_NoDestructor, }, }, }

AzNode AzNodeVecArray[] = {};
#define AzNodeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzNode), .cap = sizeof(v) / sizeof(AzNode), .destructor = { .NoDestructor = { .tag = AzNodeVecDestructorTag_NoDestructor, }, }, }
#define AzNodeVec_empty { .ptr = &AzNodeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzNodeVecDestructorTag_NoDestructor, }, }, }

AzStyledNode AzStyledNodeVecArray[] = {};
#define AzStyledNodeVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzStyledNode), .cap = sizeof(v) / sizeof(AzStyledNode), .destructor = { .NoDestructor = { .tag = AzStyledNodeVecDestructorTag_NoDestructor, }, }, }
#define AzStyledNodeVec_empty { .ptr = &AzStyledNodeVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzStyledNodeVecDestructorTag_NoDestructor, }, }, }

AzTagIdToNodeIdMapping AzTagIdToNodeIdMappingVecArray[] = {};
#define AzTagIdToNodeIdMappingVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzTagIdToNodeIdMapping), .cap = sizeof(v) / sizeof(AzTagIdToNodeIdMapping), .destructor = { .NoDestructor = { .tag = AzTagIdToNodeIdMappingVecDestructorTag_NoDestructor, }, }, }
#define AzTagIdToNodeIdMappingVec_empty { .ptr = &AzTagIdToNodeIdMappingVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzTagIdToNodeIdMappingVecDestructorTag_NoDestructor, }, }, }

AzParentWithNodeDepth AzParentWithNodeDepthVecArray[] = {};
#define AzParentWithNodeDepthVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzParentWithNodeDepth), .cap = sizeof(v) / sizeof(AzParentWithNodeDepth), .destructor = { .NoDestructor = { .tag = AzParentWithNodeDepthVecDestructorTag_NoDestructor, }, }, }
#define AzParentWithNodeDepthVec_empty { .ptr = &AzParentWithNodeDepthVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzParentWithNodeDepthVecDestructorTag_NoDestructor, }, }, }

AzNodeData AzNodeDataVecArray[] = {};
#define AzNodeDataVec_fromConstArray(v) { .ptr = &v, .len = sizeof(v) / sizeof(AzNodeData), .cap = sizeof(v) / sizeof(AzNodeData), .destructor = { .NoDestructor = { .tag = AzNodeDataVecDestructorTag_NoDestructor, }, }, }
#define AzNodeDataVec_empty { .ptr = &AzNodeDataVecArray, .len = 0, .cap = 0, .destructor = { .NoDestructor = { .tag = AzNodeDataVecDestructorTag_NoDestructor, }, }, }


/* FUNCTIONS from azul.dll / libazul.so */
extern DLLIMPORT AzApp AzApp_new(AzRefAny  data, AzAppConfig  config);
extern DLLIMPORT void AzApp_addWindow(AzApp* restrict app, AzWindowCreateOptions  window);
extern DLLIMPORT void AzApp_addImage(AzApp* restrict app, AzString  id, AzImageRef  image);
extern DLLIMPORT AzMonitorVec AzApp_getMonitors(const AzApp* app);
extern DLLIMPORT void AzApp_run(const AzApp* app, AzWindowCreateOptions  window);
extern DLLIMPORT void AzApp_delete(AzApp* restrict instance);
extern DLLIMPORT AzApp AzApp_deepCopy(AzApp* const instance);
extern DLLIMPORT AzAppConfig AzAppConfig_new(AzLayoutSolver  layout_solver);
extern DLLIMPORT AzSystemCallbacks AzSystemCallbacks_libraryInternal();
extern DLLIMPORT AzWindowCreateOptions AzWindowCreateOptions_new(AzLayoutCallbackType  layout_callback);
extern DLLIMPORT AzWindowState AzWindowState_new(AzLayoutCallbackType  layout_callback);
extern DLLIMPORT AzWindowState AzWindowState_default();
extern DLLIMPORT AzDomNodeId AzCallbackInfo_getHitNode(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzGetSystemTimeFn AzCallbackInfo_getSystemTimeFn(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzOptionLogicalPosition AzCallbackInfo_getCursorRelativeToViewport(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzOptionLogicalPosition AzCallbackInfo_getCursorRelativeToNode(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzWindowState AzCallbackInfo_getCurrentWindowState(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzKeyboardState AzCallbackInfo_getCurrentKeyboardState(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzMouseState AzCallbackInfo_getCurrentMouseState(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzOptionWindowState AzCallbackInfo_getPreviousWindowState(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzOptionKeyboardState AzCallbackInfo_getPreviousKeyboardState(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzOptionMouseState AzCallbackInfo_getPreviousMouseState(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzRawWindowHandle AzCallbackInfo_getCurrentWindowHandle(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzOptionGl AzCallbackInfo_getGlContext(const AzCallbackInfo* callbackinfo);
extern DLLIMPORT AzOptionLogicalPosition AzCallbackInfo_getScrollPosition(const AzCallbackInfo* callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionRefAny AzCallbackInfo_getDataset(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionString AzCallbackInfo_getStringContents(const AzCallbackInfo* callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionInlineText AzCallbackInfo_getInlineText(const AzCallbackInfo* callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionFontRef AzCallbackInfo_getFontRef(const AzCallbackInfo* callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionInlineText AzCallbackInfo_shapeText(const AzCallbackInfo* callbackinfo, AzDomNodeId  node_id, AzString  text);
extern DLLIMPORT size_t AzCallbackInfo_getIndexInParent(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzCallbackInfo_getParent(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzCallbackInfo_getPreviousSibling(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzCallbackInfo_getNextSibling(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzCallbackInfo_getFirstChild(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzCallbackInfo_getLastChild(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionPositionInfo AzCallbackInfo_getNodePosition(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionLogicalSize AzCallbackInfo_getNodeSize(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionCssProperty AzCallbackInfo_getComputedCssProperty(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id, AzCssPropertyType  property_type);
extern DLLIMPORT void AzCallbackInfo_setWindowState(AzCallbackInfo* restrict callbackinfo, AzWindowState  new_state);
extern DLLIMPORT void AzCallbackInfo_setFocus(AzCallbackInfo* restrict callbackinfo, AzFocusTarget  target);
extern DLLIMPORT void AzCallbackInfo_setCssProperty(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id, AzCssProperty  new_property);
extern DLLIMPORT void AzCallbackInfo_setScrollPosition(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id, AzLogicalPosition  scroll_position);
extern DLLIMPORT void AzCallbackInfo_setStringContents(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id, AzString  string);
extern DLLIMPORT void AzCallbackInfo_addImage(AzCallbackInfo* restrict callbackinfo, AzString  id, AzImageRef  image);
extern DLLIMPORT bool  AzCallbackInfo_hasImage(const AzCallbackInfo* callbackinfo, AzString  id);
extern DLLIMPORT AzOptionImageRef AzCallbackInfo_getImage(const AzCallbackInfo* callbackinfo, AzString  id);
extern DLLIMPORT void AzCallbackInfo_updateImage(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id, AzImageRef  new_image, AzUpdateImageType  image_type);
extern DLLIMPORT void AzCallbackInfo_deleteImage(AzCallbackInfo* restrict callbackinfo, AzString  id);
extern DLLIMPORT void AzCallbackInfo_updateImageMask(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node_id, AzImageMask  new_mask);
extern DLLIMPORT void AzCallbackInfo_stopPropagation(AzCallbackInfo* restrict callbackinfo);
extern DLLIMPORT void AzCallbackInfo_createWindow(AzCallbackInfo* restrict callbackinfo, AzWindowCreateOptions  new_window);
extern DLLIMPORT AzOptionTimerId AzCallbackInfo_startTimer(AzCallbackInfo* restrict callbackinfo, AzTimer  timer);
extern DLLIMPORT AzOptionTimerId AzCallbackInfo_startAnimation(AzCallbackInfo* restrict callbackinfo, AzDomNodeId  node, AzAnimation  animation);
extern DLLIMPORT bool  AzCallbackInfo_stopTimer(AzCallbackInfo* restrict callbackinfo, AzTimerId  timer_id);
extern DLLIMPORT AzOptionThreadId AzCallbackInfo_startThread(AzCallbackInfo* restrict callbackinfo, AzRefAny  thread_initialize_data, AzRefAny  writeback_data, AzThreadCallback  callback);
extern DLLIMPORT bool  AzCallbackInfo_sendThreadMsg(AzCallbackInfo* restrict callbackinfo, AzThreadId  thread_id, AzThreadSendMsg  msg);
extern DLLIMPORT bool  AzCallbackInfo_stopThread(AzCallbackInfo* restrict callbackinfo, AzThreadId  thread_id);
extern DLLIMPORT AzLogicalSize AzHidpiAdjustedBounds_getLogicalSize(const AzHidpiAdjustedBounds* hidpiadjustedbounds);
extern DLLIMPORT AzPhysicalSizeU32 AzHidpiAdjustedBounds_getPhysicalSize(const AzHidpiAdjustedBounds* hidpiadjustedbounds);
extern DLLIMPORT float AzHidpiAdjustedBounds_getHidpiFactor(const AzHidpiAdjustedBounds* hidpiadjustedbounds);
extern DLLIMPORT AzInlineTextHitVec AzInlineText_hitTest(const AzInlineText* inlinetext, AzLogicalPosition  position);
extern DLLIMPORT AzOptionGl AzRenderImageCallbackInfo_getGlContext(const AzRenderImageCallbackInfo* renderimagecallbackinfo);
extern DLLIMPORT AzHidpiAdjustedBounds AzRenderImageCallbackInfo_getBounds(const AzRenderImageCallbackInfo* renderimagecallbackinfo);
extern DLLIMPORT AzDomNodeId AzRenderImageCallbackInfo_getCallbackNodeId(const AzRenderImageCallbackInfo* renderimagecallbackinfo);
extern DLLIMPORT AzOptionInlineText AzRenderImageCallbackInfo_getInlineText(const AzRenderImageCallbackInfo* renderimagecallbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT size_t AzRenderImageCallbackInfo_getIndexInParent(AzRenderImageCallbackInfo* restrict renderimagecallbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzRenderImageCallbackInfo_getParent(AzRenderImageCallbackInfo* restrict renderimagecallbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzRenderImageCallbackInfo_getPreviousSibling(AzRenderImageCallbackInfo* restrict renderimagecallbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzRenderImageCallbackInfo_getNextSibling(AzRenderImageCallbackInfo* restrict renderimagecallbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzRenderImageCallbackInfo_getFirstChild(AzRenderImageCallbackInfo* restrict renderimagecallbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT AzOptionDomNodeId AzRenderImageCallbackInfo_getLastChild(AzRenderImageCallbackInfo* restrict renderimagecallbackinfo, AzDomNodeId  node_id);
extern DLLIMPORT bool  AzRefCount_canBeShared(const AzRefCount* refcount);
extern DLLIMPORT bool  AzRefCount_canBeSharedMut(const AzRefCount* refcount);
extern DLLIMPORT void AzRefCount_increaseRef(AzRefCount* restrict refcount);
extern DLLIMPORT void AzRefCount_decreaseRef(AzRefCount* restrict refcount);
extern DLLIMPORT void AzRefCount_increaseRefmut(AzRefCount* restrict refcount);
extern DLLIMPORT void AzRefCount_decreaseRefmut(AzRefCount* restrict refcount);
extern DLLIMPORT void AzRefCount_delete(AzRefCount* restrict instance);
extern DLLIMPORT AzRefCount AzRefCount_deepCopy(AzRefCount* const instance);
extern DLLIMPORT AzRefAny AzRefAny_newC(void ptr, size_t len, uint64_t type_id, AzString  type_name, AzRefAnyDestructorType  destructor);
extern DLLIMPORT uint64_t AzRefAny_getTypeId(const AzRefAny* refany);
extern DLLIMPORT AzString AzRefAny_getTypeName(const AzRefAny* refany);
extern DLLIMPORT void AzRefAny_delete(AzRefAny* restrict instance);
extern DLLIMPORT AzRefAny AzRefAny_deepCopy(AzRefAny* const instance);
extern DLLIMPORT AzOptionGl AzLayoutCallbackInfo_getGlContext(const AzLayoutCallbackInfo* layoutcallbackinfo);
extern DLLIMPORT AzStringPairVec AzLayoutCallbackInfo_getSystemFonts(const AzLayoutCallbackInfo* layoutcallbackinfo);
extern DLLIMPORT AzOptionImageRef AzLayoutCallbackInfo_getImage(const AzLayoutCallbackInfo* layoutcallbackinfo, AzString  id);
extern DLLIMPORT AzDom AzDom_new(AzNodeType  node_type);
extern DLLIMPORT AzDom AzDom_body();
extern DLLIMPORT AzDom AzDom_div();
extern DLLIMPORT AzDom AzDom_br();
extern DLLIMPORT AzDom AzDom_text(AzString  string);
extern DLLIMPORT AzDom AzDom_image(AzImageRef  image);
extern DLLIMPORT AzDom AzDom_iframe(AzRefAny  data, AzIFrameCallbackType  callback);
extern DLLIMPORT void AzDom_setNodeType(AzDom* restrict dom, AzNodeType  node_type);
extern DLLIMPORT AzDom AzDom_withNodeType(AzDom* restrict dom, AzNodeType  node_type);
extern DLLIMPORT void AzDom_setDataset(AzDom* restrict dom, AzRefAny  dataset);
extern DLLIMPORT AzDom AzDom_withDataset(AzDom* restrict dom, AzRefAny  dataset);
extern DLLIMPORT void AzDom_setIdsAndClasses(AzDom* restrict dom, AzIdOrClassVec  ids_and_classes);
extern DLLIMPORT AzDom AzDom_withIdsAndClasses(AzDom* restrict dom, AzIdOrClassVec  ids_and_classes);
extern DLLIMPORT void AzDom_setCallbacks(AzDom* restrict dom, AzCallbackDataVec  callbacks);
extern DLLIMPORT AzDom AzDom_withCallbacks(AzDom* restrict dom, AzCallbackDataVec  callbacks);
extern DLLIMPORT void AzDom_setInlineCssProps(AzDom* restrict dom, AzNodeDataInlineCssPropertyVec  css_properties);
extern DLLIMPORT AzDom AzDom_withInlineCssProps(AzDom* restrict dom, AzNodeDataInlineCssPropertyVec  css_properties);
extern DLLIMPORT void AzDom_addCallback(AzDom* restrict dom, AzEventFilter  event, AzRefAny  data, AzCallbackType  callback);
extern DLLIMPORT AzDom AzDom_withCallback(AzDom* restrict dom, AzEventFilter  event, AzRefAny  data, AzCallbackType  callback);
extern DLLIMPORT void AzDom_addChild(AzDom* restrict dom, AzDom  child);
extern DLLIMPORT AzDom AzDom_withChild(AzDom* restrict dom, AzDom  child);
extern DLLIMPORT void AzDom_setChildren(AzDom* restrict dom, AzDomVec  children);
extern DLLIMPORT AzDom AzDom_withChildren(AzDom* restrict dom, AzDomVec  children);
extern DLLIMPORT void AzDom_addId(AzDom* restrict dom, AzString  id);
extern DLLIMPORT AzDom AzDom_withId(AzDom* restrict dom, AzString  id);
extern DLLIMPORT void AzDom_addClass(AzDom* restrict dom, AzString  class);
extern DLLIMPORT AzDom AzDom_withClass(AzDom* restrict dom, AzString  class);
extern DLLIMPORT void AzDom_addCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT AzDom AzDom_withCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT void AzDom_addHoverCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT AzDom AzDom_withHoverCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT void AzDom_addActiveCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT AzDom AzDom_withActiveCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT void AzDom_addFocusCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT AzDom AzDom_withFocusCssProperty(AzDom* restrict dom, AzCssProperty  prop);
extern DLLIMPORT void AzDom_setClipMask(AzDom* restrict dom, AzImageMask  clip_mask);
extern DLLIMPORT AzDom AzDom_withClipMask(AzDom* restrict dom, AzImageMask  clip_mask);
extern DLLIMPORT void AzDom_setTabIndex(AzDom* restrict dom, AzTabIndex  tab_index);
extern DLLIMPORT AzDom AzDom_withTabIndex(AzDom* restrict dom, AzTabIndex  tab_index);
extern DLLIMPORT void AzDom_setAccessibilityInfo(AzDom* restrict dom, AzAccessibilityInfo  accessibility_info);
extern DLLIMPORT AzDom AzDom_withAccessibilityInfo(AzDom* restrict dom, AzAccessibilityInfo  accessibility_info);
extern DLLIMPORT void AzDom_setMenuBar(AzDom* restrict dom, AzMenu  menu_bar);
extern DLLIMPORT AzDom AzDom_withMenuBar(AzDom* restrict dom, AzMenu  menu_bar);
extern DLLIMPORT void AzDom_setContextMenu(AzDom* restrict dom, AzMenu  context_menu);
extern DLLIMPORT AzDom AzDom_withContextMenu(AzDom* restrict dom, AzMenu  context_menu);
extern DLLIMPORT uint64_t AzDom_hash(const AzDom* dom);
extern DLLIMPORT size_t AzDom_nodeCount(const AzDom* dom);
extern DLLIMPORT AzString AzDom_getHtmlStringTest(AzDom* restrict dom);
extern DLLIMPORT AzString AzDom_getHtmlStringDebug(AzDom* restrict dom);
extern DLLIMPORT AzStyledDom AzDom_style(AzDom* restrict dom, AzCss  css);
extern DLLIMPORT AzNodeData AzNodeData_new(AzNodeType  node_type);
extern DLLIMPORT AzNodeData AzNodeData_body();
extern DLLIMPORT AzNodeData AzNodeData_div();
extern DLLIMPORT AzNodeData AzNodeData_br();
extern DLLIMPORT AzNodeData AzNodeData_text(AzString  string);
extern DLLIMPORT AzNodeData AzNodeData_image(AzImageRef  image);
extern DLLIMPORT AzNodeData AzNodeData_iframe(AzRefAny  data, AzIFrameCallbackType  callback);
extern DLLIMPORT void AzNodeData_setNodeType(AzNodeData* restrict nodedata, AzNodeType  node_type);
extern DLLIMPORT AzNodeData AzNodeData_withNodeType(AzNodeData* restrict nodedata, AzNodeType  node_type);
extern DLLIMPORT void AzNodeData_setDataset(AzNodeData* restrict nodedata, AzRefAny  dataset);
extern DLLIMPORT AzNodeData AzNodeData_withDataset(AzNodeData* restrict nodedata, AzRefAny  dataset);
extern DLLIMPORT void AzNodeData_setIdsAndClasses(AzNodeData* restrict nodedata, AzIdOrClassVec  ids_and_classes);
extern DLLIMPORT AzNodeData AzNodeData_withIdsAndClasses(AzNodeData* restrict nodedata, AzIdOrClassVec  ids_and_classes);
extern DLLIMPORT void AzNodeData_addCallback(AzNodeData* restrict nodedata, AzEventFilter  event, AzRefAny  data, AzCallbackType  callback);
extern DLLIMPORT AzNodeData AzNodeData_withCallback(AzNodeData* restrict nodedata, AzEventFilter  event, AzRefAny  data, AzCallbackType  callback);
extern DLLIMPORT void AzNodeData_setCallbacks(AzNodeData* restrict nodedata, AzCallbackDataVec  callbacks);
extern DLLIMPORT AzNodeData AzNodeData_withCallbacks(AzNodeData* restrict nodedata, AzCallbackDataVec  callbacks);
extern DLLIMPORT void AzNodeData_setInlineCssProps(AzNodeData* restrict nodedata, AzNodeDataInlineCssPropertyVec  css_properties);
extern DLLIMPORT AzNodeData AzNodeData_withInlineCssProps(AzNodeData* restrict nodedata, AzNodeDataInlineCssPropertyVec  css_properties);
extern DLLIMPORT void AzNodeData_setClipMask(AzNodeData* restrict nodedata, AzImageMask  image_mask);
extern DLLIMPORT void AzNodeData_setTabIndex(AzNodeData* restrict nodedata, AzTabIndex  tab_index);
extern DLLIMPORT void AzNodeData_setAccessibilityInfo(AzNodeData* restrict nodedata, AzAccessibilityInfo  accessibility_info);
extern DLLIMPORT void AzNodeData_setMenuBar(AzNodeData* restrict nodedata, AzMenu  menu_bar);
extern DLLIMPORT void AzNodeData_setContextMenu(AzNodeData* restrict nodedata, AzMenu  context_menu);
extern DLLIMPORT uint64_t AzNodeData_hash(const AzNodeData* nodedata);
extern DLLIMPORT AzEventFilter AzOn_intoEventFilter(const AzOn on);
extern DLLIMPORT AzMenuItem AzMenuItem_new(AzString  label, AzOptionMenuCallback  callback);
extern DLLIMPORT AzStringMenuItem AzStringMenuItem_new(AzString  label);
extern DLLIMPORT void AzStringMenuItem_addChild(AzStringMenuItem* restrict stringmenuitem, AzMenuItem  child);
extern DLLIMPORT AzStringMenuItem AzStringMenuItem_withChild(AzStringMenuItem* restrict stringmenuitem, AzMenuItem  child);
extern DLLIMPORT AzCss AzCss_empty();
extern DLLIMPORT AzCss AzCss_fromString(AzString  s);
extern DLLIMPORT AzColorU AzColorU_fromStr(AzString  string);
extern DLLIMPORT AzString AzColorU_toHash(const AzColorU* coloru);
extern DLLIMPORT AzString AzCssProperty_getKeyString(const AzCssProperty* cssproperty);
extern DLLIMPORT AzString AzCssProperty_getValueString(const AzCssProperty* cssproperty);
extern DLLIMPORT AzString AzCssProperty_getKeyValueString(const AzCssProperty* cssproperty);
extern DLLIMPORT AzCssProperty AzCssProperty_interpolate(const AzCssProperty* cssproperty, AzCssProperty  other, float t, AzInterpolateContext  context);
extern DLLIMPORT AzButton AzButton_new(AzString  label);
extern DLLIMPORT void AzButton_setOnClick(AzButton* restrict button, AzRefAny  data, AzCallbackType  callback);
extern DLLIMPORT AzButton AzButton_withOnClick(AzButton* restrict button, AzRefAny  data, AzCallbackType  callback);
extern DLLIMPORT AzDom AzButton_dom(AzButton* restrict button);
extern DLLIMPORT AzCheckBox AzCheckBox_new(bool  checked);
extern DLLIMPORT void AzCheckBox_setOnToggle(AzCheckBox* restrict checkbox, AzRefAny  data, AzCheckBoxOnToggleCallbackType  callback);
extern DLLIMPORT AzCheckBox AzCheckBox_withOnToggle(AzCheckBox* restrict checkbox, AzRefAny  data, AzCheckBoxOnToggleCallbackType  callback);
extern DLLIMPORT AzDom AzCheckBox_dom(AzCheckBox* restrict checkbox);
extern DLLIMPORT AzLabel AzLabel_new(AzString  text);
extern DLLIMPORT AzDom AzLabel_dom(AzLabel* restrict label);
extern DLLIMPORT AzColorInput AzColorInput_new(AzColorU  color);
extern DLLIMPORT void AzColorInput_setOnValueChange(AzColorInput* restrict colorinput, AzRefAny  data, AzColorInputOnValueChangeCallbackType  callback);
extern DLLIMPORT AzColorInput AzColorInput_withOnValueChange(AzColorInput* restrict colorinput, AzRefAny  data, AzColorInputOnValueChangeCallbackType  callback);
extern DLLIMPORT AzDom AzColorInput_dom(AzColorInput* restrict colorinput);
extern DLLIMPORT AzTextInput AzTextInput_new(AzString  initial_text);
extern DLLIMPORT void AzTextInput_setOnTextInput(AzTextInput* restrict textinput, AzRefAny  data, AzTextInputOnTextInputCallbackType  callback);
extern DLLIMPORT AzTextInput AzTextInput_withOnTextInput(AzTextInput* restrict textinput, AzRefAny  data, AzTextInputOnTextInputCallbackType  callback);
extern DLLIMPORT void AzTextInput_setOnVirtualKeyDown(AzTextInput* restrict textinput, AzRefAny  data, AzTextInputOnVirtualKeyDownCallbackType  callback);
extern DLLIMPORT AzTextInput AzTextInput_withOnVirtualKeyDown(AzTextInput* restrict textinput, AzRefAny  data, AzTextInputOnVirtualKeyDownCallbackType  callback);
extern DLLIMPORT void AzTextInput_setOnFocusLost(AzTextInput* restrict textinput, AzRefAny  data, AzTextInputOnFocusLostCallbackType  callback);
extern DLLIMPORT AzTextInput AzTextInput_withOnFocusLost(AzTextInput* restrict textinput, AzRefAny  data, AzTextInputOnFocusLostCallbackType  callback);
extern DLLIMPORT void AzTextInput_setPlaceholderStyle(AzTextInput* restrict textinput, AzNodeDataInlineCssPropertyVec  placeholder_style);
extern DLLIMPORT AzTextInput AzTextInput_withPlaceholderStyle(AzTextInput* restrict textinput, AzNodeDataInlineCssPropertyVec  placeholder_style);
extern DLLIMPORT void AzTextInput_setContainerStyle(AzTextInput* restrict textinput, AzNodeDataInlineCssPropertyVec  container_style);
extern DLLIMPORT AzTextInput AzTextInput_withContainerStyle(AzTextInput* restrict textinput, AzNodeDataInlineCssPropertyVec  container_style);
extern DLLIMPORT void AzTextInput_setLabelStyle(AzTextInput* restrict textinput, AzNodeDataInlineCssPropertyVec  label_style);
extern DLLIMPORT AzTextInput AzTextInput_withLabelStyle(AzTextInput* restrict textinput, AzNodeDataInlineCssPropertyVec  label_style);
extern DLLIMPORT AzDom AzTextInput_dom(AzTextInput* restrict textinput);
extern DLLIMPORT AzNumberInput AzNumberInput_new(float number);
extern DLLIMPORT AzDom AzNumberInput_dom(AzNumberInput* restrict numberinput);
extern DLLIMPORT void AzCssPropertyCache_delete(AzCssPropertyCache* restrict instance);
extern DLLIMPORT AzCssPropertyCache AzCssPropertyCache_deepCopy(AzCssPropertyCache* const instance);
extern DLLIMPORT AzStyledDom AzStyledDom_new(AzDom  dom, AzCss  css);
extern DLLIMPORT AzStyledDom AzStyledDom_default();
extern DLLIMPORT AzStyledDom AzStyledDom_fromXml(AzString  xml_string);
extern DLLIMPORT AzStyledDom AzStyledDom_fromFile(AzString  xml_file_path);
extern DLLIMPORT void AzStyledDom_appendChild(AzStyledDom* restrict styleddom, AzStyledDom  dom);
extern DLLIMPORT void AzStyledDom_restyle(AzStyledDom* restrict styleddom, AzCss  css);
extern DLLIMPORT size_t AzStyledDom_nodeCount(const AzStyledDom* styleddom);
extern DLLIMPORT AzString AzStyledDom_getHtmlStringTest(const AzStyledDom* styleddom);
extern DLLIMPORT AzString AzStyledDom_getHtmlStringDebug(const AzStyledDom* styleddom);
extern DLLIMPORT AzTexture AzTexture_allocateClipMask(AzGl  gl, AzLayoutSize  size);
extern DLLIMPORT bool  AzTexture_drawClipMask(AzTexture* restrict texture, AzTessellatedSvgNode  node);
extern DLLIMPORT bool  AzTexture_applyFxaa(AzTexture* restrict texture);
extern DLLIMPORT void AzTexture_delete(AzTexture* restrict instance);
extern DLLIMPORT AzTexture AzTexture_deepCopy(AzTexture* const instance);
extern DLLIMPORT void AzGlVoidPtrConst_delete(AzGlVoidPtrConst* restrict instance);
extern DLLIMPORT AzGlVoidPtrConst AzGlVoidPtrConst_deepCopy(AzGlVoidPtrConst* const instance);
extern DLLIMPORT AzGlType AzGl_getType(const AzGl* gl);
extern DLLIMPORT void AzGl_bufferDataUntyped(const AzGl* gl, uint32_t target, ssize_t size, AzGlVoidPtrConst  data, uint32_t usage);
extern DLLIMPORT void AzGl_bufferSubDataUntyped(const AzGl* gl, uint32_t target, ssize_t offset, ssize_t size, AzGlVoidPtrConst  data);
extern DLLIMPORT AzGlVoidPtrMut AzGl_mapBuffer(const AzGl* gl, uint32_t target, uint32_t access);
extern DLLIMPORT AzGlVoidPtrMut AzGl_mapBufferRange(const AzGl* gl, uint32_t target, ssize_t offset, ssize_t length, uint32_t access);
extern DLLIMPORT uint8_t AzGl_unmapBuffer(const AzGl* gl, uint32_t target);
extern DLLIMPORT void AzGl_texBuffer(const AzGl* gl, uint32_t target, uint32_t internal_format, uint32_t buffer);
extern DLLIMPORT void AzGl_shaderSource(const AzGl* gl, uint32_t shader, AzStringVec  strings);
extern DLLIMPORT void AzGl_readBuffer(const AzGl* gl, uint32_t mode);
extern DLLIMPORT void AzGl_readPixelsIntoBuffer(const AzGl* gl, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format, uint32_t pixel_type, AzU8VecRefMut  dst_buffer);
extern DLLIMPORT AzU8Vec AzGl_readPixels(const AzGl* gl, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format, uint32_t pixel_type);
extern DLLIMPORT void AzGl_readPixelsIntoPbo(const AzGl* gl, int32_t x, int32_t y, int32_t width, int32_t height, uint32_t format, uint32_t pixel_type);
extern DLLIMPORT void AzGl_sampleCoverage(const AzGl* gl, float value, bool  invert);
extern DLLIMPORT void AzGl_polygonOffset(const AzGl* gl, float factor, float units);
extern DLLIMPORT void AzGl_pixelStoreI(const AzGl* gl, uint32_t name, int32_t param);
extern DLLIMPORT AzGLuintVec AzGl_genBuffers(const AzGl* gl, int32_t n);
extern DLLIMPORT AzGLuintVec AzGl_genRenderbuffers(const AzGl* gl, int32_t n);
extern DLLIMPORT AzGLuintVec AzGl_genFramebuffers(const AzGl* gl, int32_t n);
extern DLLIMPORT AzGLuintVec AzGl_genTextures(const AzGl* gl, int32_t n);
extern DLLIMPORT AzGLuintVec AzGl_genVertexArrays(const AzGl* gl, int32_t n);
extern DLLIMPORT AzGLuintVec AzGl_genQueries(const AzGl* gl, int32_t n);
extern DLLIMPORT void AzGl_beginQuery(const AzGl* gl, uint32_t target, uint32_t id);
extern DLLIMPORT void AzGl_endQuery(const AzGl* gl, uint32_t target);
extern DLLIMPORT void AzGl_queryCounter(const AzGl* gl, uint32_t id, uint32_t target);
extern DLLIMPORT int32_t AzGl_getQueryObjectIv(const AzGl* gl, uint32_t id, uint32_t pname);
extern DLLIMPORT uint32_t AzGl_getQueryObjectUiv(const AzGl* gl, uint32_t id, uint32_t pname);
extern DLLIMPORT int64_t AzGl_getQueryObjectI64V(const AzGl* gl, uint32_t id, uint32_t pname);
extern DLLIMPORT uint64_t AzGl_getQueryObjectUi64V(const AzGl* gl, uint32_t id, uint32_t pname);
extern DLLIMPORT void AzGl_deleteQueries(const AzGl* gl, AzGLuintVecRef  queries);
extern DLLIMPORT void AzGl_deleteVertexArrays(const AzGl* gl, AzGLuintVecRef  vertex_arrays);
extern DLLIMPORT void AzGl_deleteBuffers(const AzGl* gl, AzGLuintVecRef  buffers);
extern DLLIMPORT void AzGl_deleteRenderbuffers(const AzGl* gl, AzGLuintVecRef  renderbuffers);
extern DLLIMPORT void AzGl_deleteFramebuffers(const AzGl* gl, AzGLuintVecRef  framebuffers);
extern DLLIMPORT void AzGl_deleteTextures(const AzGl* gl, AzGLuintVecRef  textures);
extern DLLIMPORT void AzGl_framebufferRenderbuffer(const AzGl* gl, uint32_t target, uint32_t attachment, uint32_t renderbuffertarget, uint32_t renderbuffer);
extern DLLIMPORT void AzGl_renderbufferStorage(const AzGl* gl, uint32_t target, uint32_t internalformat, int32_t width, int32_t height);
extern DLLIMPORT void AzGl_depthFunc(const AzGl* gl, uint32_t func);
extern DLLIMPORT void AzGl_activeTexture(const AzGl* gl, uint32_t texture);
extern DLLIMPORT void AzGl_attachShader(const AzGl* gl, uint32_t program, uint32_t shader);
extern DLLIMPORT void AzGl_bindAttribLocation(const AzGl* gl, uint32_t program, uint32_t index, AzRefstr  name);
extern DLLIMPORT void AzGl_getUniformIv(const AzGl* gl, uint32_t program, int32_t location, AzGLintVecRefMut  result);
extern DLLIMPORT void AzGl_getUniformFv(const AzGl* gl, uint32_t program, int32_t location, AzGLfloatVecRefMut  result);
extern DLLIMPORT uint32_t AzGl_getUniformBlockIndex(const AzGl* gl, uint32_t program, AzRefstr  name);
extern DLLIMPORT AzGLuintVec AzGl_getUniformIndices(const AzGl* gl, uint32_t program, AzRefstrVecRef  names);
extern DLLIMPORT void AzGl_bindBufferBase(const AzGl* gl, uint32_t target, uint32_t index, uint32_t buffer);
extern DLLIMPORT void AzGl_bindBufferRange(const AzGl* gl, uint32_t target, uint32_t index, uint32_t buffer, ssize_t offset, ssize_t size);
extern DLLIMPORT void AzGl_uniformBlockBinding(const AzGl* gl, uint32_t program, uint32_t uniform_block_index, uint32_t uniform_block_binding);
extern DLLIMPORT void AzGl_bindBuffer(const AzGl* gl, uint32_t target, uint32_t buffer);
extern DLLIMPORT void AzGl_bindVertexArray(const AzGl* gl, uint32_t vao);
extern DLLIMPORT void AzGl_bindRenderbuffer(const AzGl* gl, uint32_t target, uint32_t renderbuffer);
extern DLLIMPORT void AzGl_bindFramebuffer(const AzGl* gl, uint32_t target, uint32_t framebuffer);
extern DLLIMPORT void AzGl_bindTexture(const AzGl* gl, uint32_t target, uint32_t texture);
extern DLLIMPORT void AzGl_drawBuffers(const AzGl* gl, AzGLenumVecRef  bufs);
extern DLLIMPORT void AzGl_texImage2D(const AzGl* gl, uint32_t target, int32_t level, int32_t internal_format, int32_t width, int32_t height, int32_t border, uint32_t format, uint32_t ty, AzOptionU8VecRef  opt_data);
extern DLLIMPORT void AzGl_compressedTexImage2D(const AzGl* gl, uint32_t target, int32_t level, uint32_t internal_format, int32_t width, int32_t height, int32_t border, AzU8VecRef  data);
extern DLLIMPORT void AzGl_compressedTexSubImage2D(const AzGl* gl, uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, uint32_t format, AzU8VecRef  data);
extern DLLIMPORT void AzGl_texImage3D(const AzGl* gl, uint32_t target, int32_t level, int32_t internal_format, int32_t width, int32_t height, int32_t depth, int32_t border, uint32_t format, uint32_t ty, AzOptionU8VecRef  opt_data);
extern DLLIMPORT void AzGl_copyTexImage2D(const AzGl* gl, uint32_t target, int32_t level, uint32_t internal_format, int32_t x, int32_t y, int32_t width, int32_t height, int32_t border);
extern DLLIMPORT void AzGl_copyTexSubImage2D(const AzGl* gl, uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t x, int32_t y, int32_t width, int32_t height);
extern DLLIMPORT void AzGl_copyTexSubImage3D(const AzGl* gl, uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t x, int32_t y, int32_t width, int32_t height);
extern DLLIMPORT void AzGl_texSubImage2D(const AzGl* gl, uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, uint32_t format, uint32_t ty, AzU8VecRef  data);
extern DLLIMPORT void AzGl_texSubImage2DPbo(const AzGl* gl, uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height, uint32_t format, uint32_t ty, size_t offset);
extern DLLIMPORT void AzGl_texSubImage3D(const AzGl* gl, uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, uint32_t format, uint32_t ty, AzU8VecRef  data);
extern DLLIMPORT void AzGl_texSubImage3DPbo(const AzGl* gl, uint32_t target, int32_t level, int32_t xoffset, int32_t yoffset, int32_t zoffset, int32_t width, int32_t height, int32_t depth, uint32_t format, uint32_t ty, size_t offset);
extern DLLIMPORT void AzGl_texStorage2D(const AzGl* gl, uint32_t target, int32_t levels, uint32_t internal_format, int32_t width, int32_t height);
extern DLLIMPORT void AzGl_texStorage3D(const AzGl* gl, uint32_t target, int32_t levels, uint32_t internal_format, int32_t width, int32_t height, int32_t depth);
extern DLLIMPORT void AzGl_getTexImageIntoBuffer(const AzGl* gl, uint32_t target, int32_t level, uint32_t format, uint32_t ty, AzU8VecRefMut  output);
extern DLLIMPORT void AzGl_copyImageSubData(const AzGl* gl, uint32_t src_name, uint32_t src_target, int32_t src_level, int32_t src_x, int32_t src_y, int32_t src_z, uint32_t dst_name, uint32_t dst_target, int32_t dst_level, int32_t dst_x, int32_t dst_y, int32_t dst_z, int32_t src_width, int32_t src_height, int32_t src_depth);
extern DLLIMPORT void AzGl_invalidateFramebuffer(const AzGl* gl, uint32_t target, AzGLenumVecRef  attachments);
extern DLLIMPORT void AzGl_invalidateSubFramebuffer(const AzGl* gl, uint32_t target, AzGLenumVecRef  attachments, int32_t xoffset, int32_t yoffset, int32_t width, int32_t height);
extern DLLIMPORT void AzGl_getIntegerV(const AzGl* gl, uint32_t name, AzGLintVecRefMut  result);
extern DLLIMPORT void AzGl_getInteger64V(const AzGl* gl, uint32_t name, AzGLint64VecRefMut  result);
extern DLLIMPORT void AzGl_getIntegerIv(const AzGl* gl, uint32_t name, uint32_t index, AzGLintVecRefMut  result);
extern DLLIMPORT void AzGl_getInteger64Iv(const AzGl* gl, uint32_t name, uint32_t index, AzGLint64VecRefMut  result);
extern DLLIMPORT void AzGl_getBooleanV(const AzGl* gl, uint32_t name, AzGLbooleanVecRefMut  result);
extern DLLIMPORT void AzGl_getFloatV(const AzGl* gl, uint32_t name, AzGLfloatVecRefMut  result);
extern DLLIMPORT int32_t AzGl_getFramebufferAttachmentParameterIv(const AzGl* gl, uint32_t target, uint32_t attachment, uint32_t pname);
extern DLLIMPORT int32_t AzGl_getRenderbufferParameterIv(const AzGl* gl, uint32_t target, uint32_t pname);
extern DLLIMPORT int32_t AzGl_getTexParameterIv(const AzGl* gl, uint32_t target, uint32_t name);
extern DLLIMPORT float AzGl_getTexParameterFv(const AzGl* gl, uint32_t target, uint32_t name);
extern DLLIMPORT void AzGl_texParameterI(const AzGl* gl, uint32_t target, uint32_t pname, int32_t param);
extern DLLIMPORT void AzGl_texParameterF(const AzGl* gl, uint32_t target, uint32_t pname, float param);
extern DLLIMPORT void AzGl_framebufferTexture2D(const AzGl* gl, uint32_t target, uint32_t attachment, uint32_t textarget, uint32_t texture, int32_t level);
extern DLLIMPORT void AzGl_framebufferTextureLayer(const AzGl* gl, uint32_t target, uint32_t attachment, uint32_t texture, int32_t level, int32_t layer);
extern DLLIMPORT void AzGl_blitFramebuffer(const AzGl* gl, int32_t src_x0, int32_t src_y0, int32_t src_x1, int32_t src_y1, int32_t dst_x0, int32_t dst_y0, int32_t dst_x1, int32_t dst_y1, uint32_t mask, uint32_t filter);
extern DLLIMPORT void AzGl_vertexAttrib4F(const AzGl* gl, uint32_t index, float x, float y, float z, float w);
extern DLLIMPORT void AzGl_vertexAttribPointerF32(const AzGl* gl, uint32_t index, int32_t size, bool  normalized, int32_t stride, uint32_t offset);
extern DLLIMPORT void AzGl_vertexAttribPointer(const AzGl* gl, uint32_t index, int32_t size, uint32_t type_, bool  normalized, int32_t stride, uint32_t offset);
extern DLLIMPORT void AzGl_vertexAttribIPointer(const AzGl* gl, uint32_t index, int32_t size, uint32_t type_, int32_t stride, uint32_t offset);
extern DLLIMPORT void AzGl_vertexAttribDivisor(const AzGl* gl, uint32_t index, uint32_t divisor);
extern DLLIMPORT void AzGl_viewport(const AzGl* gl, int32_t x, int32_t y, int32_t width, int32_t height);
extern DLLIMPORT void AzGl_scissor(const AzGl* gl, int32_t x, int32_t y, int32_t width, int32_t height);
extern DLLIMPORT void AzGl_lineWidth(const AzGl* gl, float width);
extern DLLIMPORT void AzGl_useProgram(const AzGl* gl, uint32_t program);
extern DLLIMPORT void AzGl_validateProgram(const AzGl* gl, uint32_t program);
extern DLLIMPORT void AzGl_drawArrays(const AzGl* gl, uint32_t mode, int32_t first, int32_t count);
extern DLLIMPORT void AzGl_drawArraysInstanced(const AzGl* gl, uint32_t mode, int32_t first, int32_t count, int32_t primcount);
extern DLLIMPORT void AzGl_drawElements(const AzGl* gl, uint32_t mode, int32_t count, uint32_t element_type, uint32_t indices_offset);
extern DLLIMPORT void AzGl_drawElementsInstanced(const AzGl* gl, uint32_t mode, int32_t count, uint32_t element_type, uint32_t indices_offset, int32_t primcount);
extern DLLIMPORT void AzGl_blendColor(const AzGl* gl, float r, float g, float b, float a);
extern DLLIMPORT void AzGl_blendFunc(const AzGl* gl, uint32_t sfactor, uint32_t dfactor);
extern DLLIMPORT void AzGl_blendFuncSeparate(const AzGl* gl, uint32_t src_rgb, uint32_t dest_rgb, uint32_t src_alpha, uint32_t dest_alpha);
extern DLLIMPORT void AzGl_blendEquation(const AzGl* gl, uint32_t mode);
extern DLLIMPORT void AzGl_blendEquationSeparate(const AzGl* gl, uint32_t mode_rgb, uint32_t mode_alpha);
extern DLLIMPORT void AzGl_colorMask(const AzGl* gl, bool  r, bool  g, bool  b, bool  a);
extern DLLIMPORT void AzGl_cullFace(const AzGl* gl, uint32_t mode);
extern DLLIMPORT void AzGl_frontFace(const AzGl* gl, uint32_t mode);
extern DLLIMPORT void AzGl_enable(const AzGl* gl, uint32_t cap);
extern DLLIMPORT void AzGl_disable(const AzGl* gl, uint32_t cap);
extern DLLIMPORT void AzGl_hint(const AzGl* gl, uint32_t param_name, uint32_t param_val);
extern DLLIMPORT uint8_t AzGl_isEnabled(const AzGl* gl, uint32_t cap);
extern DLLIMPORT uint8_t AzGl_isShader(const AzGl* gl, uint32_t shader);
extern DLLIMPORT uint8_t AzGl_isTexture(const AzGl* gl, uint32_t texture);
extern DLLIMPORT uint8_t AzGl_isFramebuffer(const AzGl* gl, uint32_t framebuffer);
extern DLLIMPORT uint8_t AzGl_isRenderbuffer(const AzGl* gl, uint32_t renderbuffer);
extern DLLIMPORT uint32_t AzGl_checkFrameBufferStatus(const AzGl* gl, uint32_t target);
extern DLLIMPORT void AzGl_enableVertexAttribArray(const AzGl* gl, uint32_t index);
extern DLLIMPORT void AzGl_disableVertexAttribArray(const AzGl* gl, uint32_t index);
extern DLLIMPORT void AzGl_uniform1F(const AzGl* gl, int32_t location, float v0);
extern DLLIMPORT void AzGl_uniform1Fv(const AzGl* gl, int32_t location, AzF32VecRef  values);
extern DLLIMPORT void AzGl_uniform1I(const AzGl* gl, int32_t location, int32_t v0);
extern DLLIMPORT void AzGl_uniform1Iv(const AzGl* gl, int32_t location, AzI32VecRef  values);
extern DLLIMPORT void AzGl_uniform1Ui(const AzGl* gl, int32_t location, uint32_t v0);
extern DLLIMPORT void AzGl_uniform2F(const AzGl* gl, int32_t location, float v0, float v1);
extern DLLIMPORT void AzGl_uniform2Fv(const AzGl* gl, int32_t location, AzF32VecRef  values);
extern DLLIMPORT void AzGl_uniform2I(const AzGl* gl, int32_t location, int32_t v0, int32_t v1);
extern DLLIMPORT void AzGl_uniform2Iv(const AzGl* gl, int32_t location, AzI32VecRef  values);
extern DLLIMPORT void AzGl_uniform2Ui(const AzGl* gl, int32_t location, uint32_t v0, uint32_t v1);
extern DLLIMPORT void AzGl_uniform3F(const AzGl* gl, int32_t location, float v0, float v1, float v2);
extern DLLIMPORT void AzGl_uniform3Fv(const AzGl* gl, int32_t location, AzF32VecRef  values);
extern DLLIMPORT void AzGl_uniform3I(const AzGl* gl, int32_t location, int32_t v0, int32_t v1, int32_t v2);
extern DLLIMPORT void AzGl_uniform3Iv(const AzGl* gl, int32_t location, AzI32VecRef  values);
extern DLLIMPORT void AzGl_uniform3Ui(const AzGl* gl, int32_t location, uint32_t v0, uint32_t v1, uint32_t v2);
extern DLLIMPORT void AzGl_uniform4F(const AzGl* gl, int32_t location, float x, float y, float z, float w);
extern DLLIMPORT void AzGl_uniform4I(const AzGl* gl, int32_t location, int32_t x, int32_t y, int32_t z, int32_t w);
extern DLLIMPORT void AzGl_uniform4Iv(const AzGl* gl, int32_t location, AzI32VecRef  values);
extern DLLIMPORT void AzGl_uniform4Ui(const AzGl* gl, int32_t location, uint32_t x, uint32_t y, uint32_t z, uint32_t w);
extern DLLIMPORT void AzGl_uniform4Fv(const AzGl* gl, int32_t location, AzF32VecRef  values);
extern DLLIMPORT void AzGl_uniformMatrix2Fv(const AzGl* gl, int32_t location, bool  transpose, AzF32VecRef  value);
extern DLLIMPORT void AzGl_uniformMatrix3Fv(const AzGl* gl, int32_t location, bool  transpose, AzF32VecRef  value);
extern DLLIMPORT void AzGl_uniformMatrix4Fv(const AzGl* gl, int32_t location, bool  transpose, AzF32VecRef  value);
extern DLLIMPORT void AzGl_depthMask(const AzGl* gl, bool  flag);
extern DLLIMPORT void AzGl_depthRange(const AzGl* gl, double near, double far);
extern DLLIMPORT AzGetActiveAttribReturn AzGl_getActiveAttrib(const AzGl* gl, uint32_t program, uint32_t index);
extern DLLIMPORT AzGetActiveUniformReturn AzGl_getActiveUniform(const AzGl* gl, uint32_t program, uint32_t index);
extern DLLIMPORT AzGLintVec AzGl_getActiveUniformsIv(const AzGl* gl, uint32_t program, AzGLuintVec  indices, uint32_t pname);
extern DLLIMPORT int32_t AzGl_getActiveUniformBlockI(const AzGl* gl, uint32_t program, uint32_t index, uint32_t pname);
extern DLLIMPORT AzGLintVec AzGl_getActiveUniformBlockIv(const AzGl* gl, uint32_t program, uint32_t index, uint32_t pname);
extern DLLIMPORT AzString AzGl_getActiveUniformBlockName(const AzGl* gl, uint32_t program, uint32_t index);
extern DLLIMPORT int32_t AzGl_getAttribLocation(const AzGl* gl, uint32_t program, AzRefstr  name);
extern DLLIMPORT int32_t AzGl_getFragDataLocation(const AzGl* gl, uint32_t program, AzRefstr  name);
extern DLLIMPORT int32_t AzGl_getUniformLocation(const AzGl* gl, uint32_t program, AzRefstr  name);
extern DLLIMPORT AzString AzGl_getProgramInfoLog(const AzGl* gl, uint32_t program);
extern DLLIMPORT void AzGl_getProgramIv(const AzGl* gl, uint32_t program, uint32_t pname, AzGLintVecRefMut  result);
extern DLLIMPORT AzGetProgramBinaryReturn AzGl_getProgramBinary(const AzGl* gl, uint32_t program);
extern DLLIMPORT void AzGl_programBinary(const AzGl* gl, uint32_t program, uint32_t format, AzU8VecRef  binary);
extern DLLIMPORT void AzGl_programParameterI(const AzGl* gl, uint32_t program, uint32_t pname, int32_t value);
extern DLLIMPORT void AzGl_getVertexAttribIv(const AzGl* gl, uint32_t index, uint32_t pname, AzGLintVecRefMut  result);
extern DLLIMPORT void AzGl_getVertexAttribFv(const AzGl* gl, uint32_t index, uint32_t pname, AzGLfloatVecRefMut  result);
extern DLLIMPORT ssize_t AzGl_getVertexAttribPointerV(const AzGl* gl, uint32_t index, uint32_t pname);
extern DLLIMPORT int32_t AzGl_getBufferParameterIv(const AzGl* gl, uint32_t target, uint32_t pname);
extern DLLIMPORT AzString AzGl_getShaderInfoLog(const AzGl* gl, uint32_t shader);
extern DLLIMPORT AzString AzGl_getString(const AzGl* gl, uint32_t which);
extern DLLIMPORT AzString AzGl_getStringI(const AzGl* gl, uint32_t which, uint32_t index);
extern DLLIMPORT void AzGl_getShaderIv(const AzGl* gl, uint32_t shader, uint32_t pname, AzGLintVecRefMut  result);
extern DLLIMPORT AzGlShaderPrecisionFormatReturn AzGl_getShaderPrecisionFormat(const AzGl* gl, uint32_t shader_type, uint32_t precision_type);
extern DLLIMPORT void AzGl_compileShader(const AzGl* gl, uint32_t shader);
extern DLLIMPORT uint32_t AzGl_createProgram(const AzGl* gl);
extern DLLIMPORT void AzGl_deleteProgram(const AzGl* gl, uint32_t program);
extern DLLIMPORT uint32_t AzGl_createShader(const AzGl* gl, uint32_t shader_type);
extern DLLIMPORT void AzGl_deleteShader(const AzGl* gl, uint32_t shader);
extern DLLIMPORT void AzGl_detachShader(const AzGl* gl, uint32_t program, uint32_t shader);
extern DLLIMPORT void AzGl_linkProgram(const AzGl* gl, uint32_t program);
extern DLLIMPORT void AzGl_clearColor(const AzGl* gl, float r, float g, float b, float a);
extern DLLIMPORT void AzGl_clear(const AzGl* gl, uint32_t buffer_mask);
extern DLLIMPORT void AzGl_clearDepth(const AzGl* gl, double depth);
extern DLLIMPORT void AzGl_clearStencil(const AzGl* gl, int32_t s);
extern DLLIMPORT void AzGl_flush(const AzGl* gl);
extern DLLIMPORT void AzGl_finish(const AzGl* gl);
extern DLLIMPORT uint32_t AzGl_getError(const AzGl* gl);
extern DLLIMPORT void AzGl_stencilMask(const AzGl* gl, uint32_t mask);
extern DLLIMPORT void AzGl_stencilMaskSeparate(const AzGl* gl, uint32_t face, uint32_t mask);
extern DLLIMPORT void AzGl_stencilFunc(const AzGl* gl, uint32_t func, int32_t ref_, uint32_t mask);
extern DLLIMPORT void AzGl_stencilFuncSeparate(const AzGl* gl, uint32_t face, uint32_t func, int32_t ref_, uint32_t mask);
extern DLLIMPORT void AzGl_stencilOp(const AzGl* gl, uint32_t sfail, uint32_t dpfail, uint32_t dppass);
extern DLLIMPORT void AzGl_stencilOpSeparate(const AzGl* gl, uint32_t face, uint32_t sfail, uint32_t dpfail, uint32_t dppass);
extern DLLIMPORT void AzGl_eglImageTargetTexture2DOes(const AzGl* gl, uint32_t target, AzGlVoidPtrConst  image);
extern DLLIMPORT void AzGl_generateMipmap(const AzGl* gl, uint32_t target);
extern DLLIMPORT void AzGl_insertEventMarkerExt(const AzGl* gl, AzRefstr  message);
extern DLLIMPORT void AzGl_pushGroupMarkerExt(const AzGl* gl, AzRefstr  message);
extern DLLIMPORT void AzGl_popGroupMarkerExt(const AzGl* gl);
extern DLLIMPORT void AzGl_debugMessageInsertKhr(const AzGl* gl, uint32_t source, uint32_t type_, uint32_t id, uint32_t severity, AzRefstr  message);
extern DLLIMPORT void AzGl_pushDebugGroupKhr(const AzGl* gl, uint32_t source, uint32_t id, AzRefstr  message);
extern DLLIMPORT void AzGl_popDebugGroupKhr(const AzGl* gl);
extern DLLIMPORT AzGLsyncPtr AzGl_fenceSync(const AzGl* gl, uint32_t condition, uint32_t flags);
extern DLLIMPORT uint32_t AzGl_clientWaitSync(const AzGl* gl, AzGLsyncPtr  sync, uint32_t flags, uint64_t timeout);
extern DLLIMPORT void AzGl_waitSync(const AzGl* gl, AzGLsyncPtr  sync, uint32_t flags, uint64_t timeout);
extern DLLIMPORT void AzGl_deleteSync(const AzGl* gl, AzGLsyncPtr  sync);
extern DLLIMPORT void AzGl_textureRangeApple(const AzGl* gl, uint32_t target, AzU8VecRef  data);
extern DLLIMPORT AzGLuintVec AzGl_genFencesApple(const AzGl* gl, int32_t n);
extern DLLIMPORT void AzGl_deleteFencesApple(const AzGl* gl, AzGLuintVecRef  fences);
extern DLLIMPORT void AzGl_setFenceApple(const AzGl* gl, uint32_t fence);
extern DLLIMPORT void AzGl_finishFenceApple(const AzGl* gl, uint32_t fence);
extern DLLIMPORT void AzGl_testFenceApple(const AzGl* gl, uint32_t fence);
extern DLLIMPORT uint8_t AzGl_testObjectApple(const AzGl* gl, uint32_t object, uint32_t name);
extern DLLIMPORT void AzGl_finishObjectApple(const AzGl* gl, uint32_t object, uint32_t name);
extern DLLIMPORT int32_t AzGl_getFragDataIndex(const AzGl* gl, uint32_t program, AzRefstr  name);
extern DLLIMPORT void AzGl_blendBarrierKhr(const AzGl* gl);
extern DLLIMPORT void AzGl_bindFragDataLocationIndexed(const AzGl* gl, uint32_t program, uint32_t color_number, uint32_t index, AzRefstr  name);
extern DLLIMPORT AzDebugMessageVec AzGl_getDebugMessages(const AzGl* gl);
extern DLLIMPORT void AzGl_provokingVertexAngle(const AzGl* gl, uint32_t mode);
extern DLLIMPORT AzGLuintVec AzGl_genVertexArraysApple(const AzGl* gl, int32_t n);
extern DLLIMPORT void AzGl_bindVertexArrayApple(const AzGl* gl, uint32_t vao);
extern DLLIMPORT void AzGl_deleteVertexArraysApple(const AzGl* gl, AzGLuintVecRef  vertex_arrays);
extern DLLIMPORT void AzGl_copyTextureChromium(const AzGl* gl, uint32_t source_id, int32_t source_level, uint32_t dest_target, uint32_t dest_id, int32_t dest_level, int32_t internal_format, uint32_t dest_type, uint8_t unpack_flip_y, uint8_t unpack_premultiply_alpha, uint8_t unpack_unmultiply_alpha);
extern DLLIMPORT void AzGl_copySubTextureChromium(const AzGl* gl, uint32_t source_id, int32_t source_level, uint32_t dest_target, uint32_t dest_id, int32_t dest_level, int32_t x_offset, int32_t y_offset, int32_t x, int32_t y, int32_t width, int32_t height, uint8_t unpack_flip_y, uint8_t unpack_premultiply_alpha, uint8_t unpack_unmultiply_alpha);
extern DLLIMPORT void AzGl_eglImageTargetRenderbufferStorageOes(const AzGl* gl, uint32_t target, AzGlVoidPtrConst  image);
extern DLLIMPORT void AzGl_copyTexture3DAngle(const AzGl* gl, uint32_t source_id, int32_t source_level, uint32_t dest_target, uint32_t dest_id, int32_t dest_level, int32_t internal_format, uint32_t dest_type, uint8_t unpack_flip_y, uint8_t unpack_premultiply_alpha, uint8_t unpack_unmultiply_alpha);
extern DLLIMPORT void AzGl_copySubTexture3DAngle(const AzGl* gl, uint32_t source_id, int32_t source_level, uint32_t dest_target, uint32_t dest_id, int32_t dest_level, int32_t x_offset, int32_t y_offset, int32_t z_offset, int32_t x, int32_t y, int32_t z, int32_t width, int32_t height, int32_t depth, uint8_t unpack_flip_y, uint8_t unpack_premultiply_alpha, uint8_t unpack_unmultiply_alpha);
extern DLLIMPORT void AzGl_bufferStorage(const AzGl* gl, uint32_t target, ssize_t size, AzGlVoidPtrConst  data, uint32_t flags);
extern DLLIMPORT void AzGl_flushMappedBufferRange(const AzGl* gl, uint32_t target, ssize_t offset, ssize_t length);
extern DLLIMPORT void AzGl_delete(AzGl* restrict instance);
extern DLLIMPORT AzGl AzGl_deepCopy(AzGl* const instance);
extern DLLIMPORT void AzGLsyncPtr_delete(AzGLsyncPtr* restrict instance);
extern DLLIMPORT AzGLsyncPtr AzGLsyncPtr_deepCopy(AzGLsyncPtr* const instance);
extern DLLIMPORT AzTextureFlags AzTextureFlags_default();
extern DLLIMPORT AzImageRef AzImageRef_invalid(size_t width, size_t height, AzRawImageFormat  format);
extern DLLIMPORT AzImageRef AzImageRef_rawImage(AzRawImage  data);
extern DLLIMPORT AzImageRef AzImageRef_glTexture(AzTexture  texture);
extern DLLIMPORT AzImageRef AzImageRef_callback(AzRenderImageCallback  callback, AzRefAny  data);
extern DLLIMPORT AzImageRef AzImageRef_cloneBytes(const AzImageRef* imageref);
extern DLLIMPORT bool  AzImageRef_isInvalid(const AzImageRef* imageref);
extern DLLIMPORT bool  AzImageRef_isGlTexture(const AzImageRef* imageref);
extern DLLIMPORT bool  AzImageRef_isRawImage(const AzImageRef* imageref);
extern DLLIMPORT bool  AzImageRef_isCallback(const AzImageRef* imageref);
extern DLLIMPORT void AzImageRef_delete(AzImageRef* restrict instance);
extern DLLIMPORT AzImageRef AzImageRef_deepCopy(AzImageRef* const instance);
extern DLLIMPORT AzRawImage AzRawImage_empty();
extern DLLIMPORT AzRawImage AzRawImage_allocateClipMask(AzLayoutSize  size);
extern DLLIMPORT AzRawImage AzRawImage_decodeImageBytesAny(AzU8VecRef  bytes);
extern DLLIMPORT bool  AzRawImage_drawClipMask(AzRawImage* restrict rawimage, AzSvgNode  node, AzSvgStyle  style);
extern DLLIMPORT AzResultU8VecEncodeImageError AzRawImage_encodeBmp(const AzRawImage* rawimage);
extern DLLIMPORT AzResultU8VecEncodeImageError AzRawImage_encodePng(const AzRawImage* rawimage);
extern DLLIMPORT AzResultU8VecEncodeImageError AzRawImage_encodeJpeg(const AzRawImage* rawimage);
extern DLLIMPORT AzResultU8VecEncodeImageError AzRawImage_encodeTga(const AzRawImage* rawimage);
extern DLLIMPORT AzResultU8VecEncodeImageError AzRawImage_encodePnm(const AzRawImage* rawimage);
extern DLLIMPORT AzResultU8VecEncodeImageError AzRawImage_encodeGif(const AzRawImage* rawimage);
extern DLLIMPORT AzResultU8VecEncodeImageError AzRawImage_encodeTiff(const AzRawImage* rawimage);
extern DLLIMPORT AzFontRef AzFontRef_parse(AzFontSource  source);
extern DLLIMPORT AzFontMetrics AzFontRef_getFontMetrics(const AzFontRef* fontref);
extern DLLIMPORT void AzFontRef_delete(AzFontRef* restrict instance);
extern DLLIMPORT AzFontRef AzFontRef_deepCopy(AzFontRef* const instance);
extern DLLIMPORT AzSvg AzSvg_fromString(AzString  svg_string, AzSvgParseOptions  parse_options);
extern DLLIMPORT AzSvg AzSvg_fromBytes(AzU8VecRef  svg_bytes, AzSvgParseOptions  parse_options);
extern DLLIMPORT AzSvgXmlNode AzSvg_getRoot(const AzSvg* svg);
extern DLLIMPORT AzOptionRawImage AzSvg_render(const AzSvg* svg, AzSvgRenderOptions  options);
extern DLLIMPORT AzString AzSvg_toString(const AzSvg* svg, AzSvgStringFormatOptions  options);
extern DLLIMPORT void AzSvg_delete(AzSvg* restrict instance);
extern DLLIMPORT AzSvg AzSvg_deepCopy(AzSvg* const instance);
extern DLLIMPORT AzSvgXmlNode AzSvgXmlNode_parseFrom(AzU8VecRef  svg_bytes, AzSvgParseOptions  parse_options);
extern DLLIMPORT AzOptionRawImage AzSvgXmlNode_render(const AzSvgXmlNode* svgxmlnode, AzSvgRenderOptions  options);
extern DLLIMPORT AzString AzSvgXmlNode_toString(const AzSvgXmlNode* svgxmlnode, AzSvgStringFormatOptions  options);
extern DLLIMPORT void AzSvgXmlNode_delete(AzSvgXmlNode* restrict instance);
extern DLLIMPORT AzSvgXmlNode AzSvgXmlNode_deepCopy(AzSvgXmlNode* const instance);
extern DLLIMPORT AzTessellatedSvgNode AzSvgMultiPolygon_tessellateFill(const AzSvgMultiPolygon* svgmultipolygon, AzSvgFillStyle  fill_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgMultiPolygon_tessellateStroke(const AzSvgMultiPolygon* svgmultipolygon, AzSvgStrokeStyle  stroke_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgNode_tessellateFill(const AzSvgNode* svgnode, AzSvgFillStyle  fill_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgNode_tessellateStroke(const AzSvgNode* svgnode, AzSvgStrokeStyle  stroke_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgStyledNode_tessellate(const AzSvgStyledNode* svgstylednode);
extern DLLIMPORT AzTessellatedSvgNode AzSvgCircle_tessellateFill(const AzSvgCircle* svgcircle, AzSvgFillStyle  fill_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgCircle_tessellateStroke(const AzSvgCircle* svgcircle, AzSvgStrokeStyle  stroke_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgPath_tessellateFill(const AzSvgPath* svgpath, AzSvgFillStyle  fill_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgPath_tessellateStroke(const AzSvgPath* svgpath, AzSvgStrokeStyle  stroke_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgRect_tessellateFill(const AzSvgRect* svgrect, AzSvgFillStyle  fill_style);
extern DLLIMPORT AzTessellatedSvgNode AzSvgRect_tessellateStroke(const AzSvgRect* svgrect, AzSvgStrokeStyle  stroke_style);
extern DLLIMPORT AzTessellatedSvgNode AzTessellatedSvgNode_empty();
extern DLLIMPORT AzTessellatedSvgNode AzTessellatedSvgNode_fromNodes(AzTessellatedSvgNodeVecRef  nodes);
extern DLLIMPORT AzSvgParseOptions AzSvgParseOptions_default();
extern DLLIMPORT AzSvgRenderOptions AzSvgRenderOptions_default();
extern DLLIMPORT AzXml AzXml_fromStr(AzRefstr  xml_string);
extern DLLIMPORT AzFile AzFile_open(AzString  path);
extern DLLIMPORT AzFile AzFile_create(AzString  path);
extern DLLIMPORT AzOptionString AzFile_readToString(AzFile* restrict file);
extern DLLIMPORT AzOptionU8Vec AzFile_readToBytes(AzFile* restrict file);
extern DLLIMPORT bool  AzFile_writeString(AzFile* restrict file, AzRefstr  bytes);
extern DLLIMPORT bool  AzFile_writeBytes(AzFile* restrict file, AzU8VecRef  bytes);
extern DLLIMPORT void AzFile_close(AzFile* restrict file);
extern DLLIMPORT void AzFile_delete(AzFile* restrict instance);
extern DLLIMPORT AzFile AzFile_deepCopy(AzFile* const instance);
extern DLLIMPORT AzMsgBox AzMsgBox_ok(AzMsgBoxIcon  icon, AzString  title, AzString  message);
extern DLLIMPORT AzMsgBox AzMsgBox_okCancel(AzMsgBoxIcon  icon, AzString  title, AzString  message, AzMsgBoxOkCancel  default_value);
extern DLLIMPORT AzMsgBox AzMsgBox_yesNo(AzMsgBoxIcon  icon, AzString  title, AzString  message, AzMsgBoxYesNo  default_value);
extern DLLIMPORT AzFileDialog AzFileDialog_selectFile(AzString  title, AzOptionString  default_path, AzOptionFileTypeList  filter_list);
extern DLLIMPORT AzFileDialog AzFileDialog_selectMultipleFiles(AzString  title, AzOptionString  default_path, AzOptionFileTypeList  filter_list);
extern DLLIMPORT AzFileDialog AzFileDialog_selectFolder(AzString  title, AzOptionString  default_path);
extern DLLIMPORT AzFileDialog AzFileDialog_saveFile(AzString  title, AzOptionString  default_path);
extern DLLIMPORT AzColorPickerDialog AzColorPickerDialog_open(AzString  title, AzOptionColorU  default_color);
extern DLLIMPORT AzSystemClipboard AzSystemClipboard_new();
extern DLLIMPORT AzOptionString AzSystemClipboard_getStringContents(const AzSystemClipboard* systemclipboard);
extern DLLIMPORT bool  AzSystemClipboard_setStringContents(AzSystemClipboard* restrict systemclipboard, AzString  contents);
extern DLLIMPORT void AzSystemClipboard_delete(AzSystemClipboard* restrict instance);
extern DLLIMPORT AzSystemClipboard AzSystemClipboard_deepCopy(AzSystemClipboard* const instance);
extern DLLIMPORT AzOptionDuration AzInstant_durationSince(const AzInstant* instant, AzInstant  earlier);
extern DLLIMPORT AzInstant AzInstant_addDuration(AzInstant* restrict instant, AzDuration  duration);
extern DLLIMPORT float AzInstant_linearInterpolate(const AzInstant* instant, AzInstant  start, AzInstant  end);
extern DLLIMPORT void AzInstantPtr_delete(AzInstantPtr* restrict instance);
extern DLLIMPORT AzInstantPtr AzInstantPtr_deepCopy(AzInstantPtr* const instance);
extern DLLIMPORT AzTimer AzTimer_new(AzRefAny  timer_data, AzTimerCallbackType  callback, AzGetSystemTimeFn  get_system_time_fn);
extern DLLIMPORT AzTimer AzTimer_withDelay(const AzTimer* timer, AzDuration  delay);
extern DLLIMPORT AzTimer AzTimer_withInterval(const AzTimer* timer, AzDuration  interval);
extern DLLIMPORT AzTimer AzTimer_withTimeout(const AzTimer* timer, AzDuration  timeout);
extern DLLIMPORT void AzThread_delete(AzThread* restrict instance);
extern DLLIMPORT AzThread AzThread_deepCopy(AzThread* const instance);
extern DLLIMPORT bool  AzThreadSender_send(AzThreadSender* restrict threadsender, AzThreadReceiveMsg  msg);
extern DLLIMPORT void AzThreadSender_delete(AzThreadSender* restrict instance);
extern DLLIMPORT AzThreadSender AzThreadSender_deepCopy(AzThreadSender* const instance);
extern DLLIMPORT AzOptionThreadSendMsg AzThreadReceiver_receive(AzThreadReceiver* restrict threadreceiver);
extern DLLIMPORT void AzThreadReceiver_delete(AzThreadReceiver* restrict instance);
extern DLLIMPORT AzThreadReceiver AzThreadReceiver_deepCopy(AzThreadReceiver* const instance);
extern DLLIMPORT AzString AzString_format(AzString  format, AzFmtArgVec  args);
extern DLLIMPORT AzString AzString_copyFromBytes(uint8_t ptr, size_t start, size_t len);
extern DLLIMPORT AzString AzString_trim(const AzString* string);
extern DLLIMPORT AzRefstr AzString_asRefstr(const AzString* string);
extern DLLIMPORT void AzAccessibilityStateVec_delete(AzAccessibilityStateVec* restrict instance);
extern DLLIMPORT void AzMenuItemVec_delete(AzMenuItemVec* restrict instance);
extern DLLIMPORT AzTessellatedSvgNodeVecRef AzTessellatedSvgNodeVec_asRefVec(const AzTessellatedSvgNodeVec* tessellatedsvgnodevec);
extern DLLIMPORT void AzTessellatedSvgNodeVec_delete(AzTessellatedSvgNodeVec* restrict instance);
extern DLLIMPORT void AzStyleFontFamilyVec_delete(AzStyleFontFamilyVec* restrict instance);
extern DLLIMPORT void AzXmlNodeVec_delete(AzXmlNodeVec* restrict instance);
extern DLLIMPORT void AzFmtArgVec_delete(AzFmtArgVec* restrict instance);
extern DLLIMPORT void AzInlineLineVec_delete(AzInlineLineVec* restrict instance);
extern DLLIMPORT void AzInlineWordVec_delete(AzInlineWordVec* restrict instance);
extern DLLIMPORT void AzInlineGlyphVec_delete(AzInlineGlyphVec* restrict instance);
extern DLLIMPORT void AzInlineTextHitVec_delete(AzInlineTextHitVec* restrict instance);
extern DLLIMPORT void AzMonitorVec_delete(AzMonitorVec* restrict instance);
extern DLLIMPORT void AzVideoModeVec_delete(AzVideoModeVec* restrict instance);
extern DLLIMPORT void AzDomVec_delete(AzDomVec* restrict instance);
extern DLLIMPORT void AzIdOrClassVec_delete(AzIdOrClassVec* restrict instance);
extern DLLIMPORT void AzNodeDataInlineCssPropertyVec_delete(AzNodeDataInlineCssPropertyVec* restrict instance);
extern DLLIMPORT void AzStyleBackgroundContentVec_delete(AzStyleBackgroundContentVec* restrict instance);
extern DLLIMPORT void AzStyleBackgroundPositionVec_delete(AzStyleBackgroundPositionVec* restrict instance);
extern DLLIMPORT void AzStyleBackgroundRepeatVec_delete(AzStyleBackgroundRepeatVec* restrict instance);
extern DLLIMPORT void AzStyleBackgroundSizeVec_delete(AzStyleBackgroundSizeVec* restrict instance);
extern DLLIMPORT void AzStyleTransformVec_delete(AzStyleTransformVec* restrict instance);
extern DLLIMPORT void AzCssPropertyVec_delete(AzCssPropertyVec* restrict instance);
extern DLLIMPORT void AzSvgMultiPolygonVec_delete(AzSvgMultiPolygonVec* restrict instance);
extern DLLIMPORT void AzSvgPathVec_delete(AzSvgPathVec* restrict instance);
extern DLLIMPORT void AzVertexAttributeVec_delete(AzVertexAttributeVec* restrict instance);
extern DLLIMPORT void AzSvgPathElementVec_delete(AzSvgPathElementVec* restrict instance);
extern DLLIMPORT void AzSvgVertexVec_delete(AzSvgVertexVec* restrict instance);
extern DLLIMPORT void AzU32Vec_delete(AzU32Vec* restrict instance);
extern DLLIMPORT void AzXWindowTypeVec_delete(AzXWindowTypeVec* restrict instance);
extern DLLIMPORT void AzVirtualKeyCodeVec_delete(AzVirtualKeyCodeVec* restrict instance);
extern DLLIMPORT void AzCascadeInfoVec_delete(AzCascadeInfoVec* restrict instance);
extern DLLIMPORT void AzScanCodeVec_delete(AzScanCodeVec* restrict instance);
extern DLLIMPORT void AzCssDeclarationVec_delete(AzCssDeclarationVec* restrict instance);
extern DLLIMPORT void AzCssPathSelectorVec_delete(AzCssPathSelectorVec* restrict instance);
extern DLLIMPORT void AzStylesheetVec_delete(AzStylesheetVec* restrict instance);
extern DLLIMPORT void AzCssRuleBlockVec_delete(AzCssRuleBlockVec* restrict instance);
extern DLLIMPORT void AzU16Vec_delete(AzU16Vec* restrict instance);
extern DLLIMPORT void AzF32Vec_delete(AzF32Vec* restrict instance);
extern DLLIMPORT AzU8Vec AzU8Vec_copyFromBytes(uint8_t ptr, size_t start, size_t len);
extern DLLIMPORT AzU8VecRef AzU8Vec_asRefVec(const AzU8Vec* u8vec);
extern DLLIMPORT void AzU8Vec_delete(AzU8Vec* restrict instance);
extern DLLIMPORT void AzCallbackDataVec_delete(AzCallbackDataVec* restrict instance);
extern DLLIMPORT void AzDebugMessageVec_delete(AzDebugMessageVec* restrict instance);
extern DLLIMPORT void AzGLuintVec_delete(AzGLuintVec* restrict instance);
extern DLLIMPORT void AzGLintVec_delete(AzGLintVec* restrict instance);
extern DLLIMPORT void AzStringVec_delete(AzStringVec* restrict instance);
extern DLLIMPORT void AzStringPairVec_delete(AzStringPairVec* restrict instance);
extern DLLIMPORT void AzNormalizedLinearColorStopVec_delete(AzNormalizedLinearColorStopVec* restrict instance);
extern DLLIMPORT void AzNormalizedRadialColorStopVec_delete(AzNormalizedRadialColorStopVec* restrict instance);
extern DLLIMPORT void AzNodeIdVec_delete(AzNodeIdVec* restrict instance);
extern DLLIMPORT void AzNodeVec_delete(AzNodeVec* restrict instance);
extern DLLIMPORT void AzStyledNodeVec_delete(AzStyledNodeVec* restrict instance);
extern DLLIMPORT void AzTagIdToNodeIdMappingVec_delete(AzTagIdToNodeIdMappingVec* restrict instance);
extern DLLIMPORT void AzParentWithNodeDepthVec_delete(AzParentWithNodeDepthVec* restrict instance);
extern DLLIMPORT void AzNodeDataVec_delete(AzNodeDataVec* restrict instance);

/* CONSTANTS */

#define AzGl_ACCUM 0x0100
#define AzGl_ACCUM_ALPHA_BITS 0x0D5B
#define AzGl_ACCUM_BLUE_BITS 0x0D5A
#define AzGl_ACCUM_BUFFER_BIT 0x00000200
#define AzGl_ACCUM_CLEAR_VALUE 0x0B80
#define AzGl_ACCUM_GREEN_BITS 0x0D59
#define AzGl_ACCUM_RED_BITS 0x0D58
#define AzGl_ACTIVE_ATTRIBUTES 0x8B89
#define AzGl_ACTIVE_ATTRIBUTE_MAX_LENGTH 0x8B8A
#define AzGl_ACTIVE_TEXTURE 0x84E0
#define AzGl_ACTIVE_UNIFORMS 0x8B86
#define AzGl_ACTIVE_UNIFORM_BLOCKS 0x8A36
#define AzGl_ACTIVE_UNIFORM_BLOCK_MAX_NAME_LENGTH 0x8A35
#define AzGl_ACTIVE_UNIFORM_MAX_LENGTH 0x8B87
#define AzGl_ADD 0x0104
#define AzGl_ADD_SIGNED 0x8574
#define AzGl_ALIASED_LINE_WIDTH_RANGE 0x846E
#define AzGl_ALIASED_POINT_SIZE_RANGE 0x846D
#define AzGl_ALL_ATTRIB_BITS 0xFFFFFFFF
#define AzGl_ALPHA 0x1906
#define AzGl_ALPHA12 0x803D
#define AzGl_ALPHA16 0x803E
#define AzGl_ALPHA16F_EXT 0x881C
#define AzGl_ALPHA32F_EXT 0x8816
#define AzGl_ALPHA4 0x803B
#define AzGl_ALPHA8 0x803C
#define AzGl_ALPHA8_EXT 0x803C
#define AzGl_ALPHA_BIAS 0x0D1D
#define AzGl_ALPHA_BITS 0x0D55
#define AzGl_ALPHA_INTEGER 0x8D97
#define AzGl_ALPHA_SCALE 0x0D1C
#define AzGl_ALPHA_TEST 0x0BC0
#define AzGl_ALPHA_TEST_FUNC 0x0BC1
#define AzGl_ALPHA_TEST_REF 0x0BC2
#define AzGl_ALREADY_SIGNALED 0x911A
#define AzGl_ALWAYS 0x0207
#define AzGl_AMBIENT 0x1200
#define AzGl_AMBIENT_AND_DIFFUSE 0x1602
#define AzGl_AND 0x1501
#define AzGl_AND_INVERTED 0x1504
#define AzGl_AND_REVERSE 0x1502
#define AzGl_ANY_SAMPLES_PASSED 0x8C2F
#define AzGl_ANY_SAMPLES_PASSED_CONSERVATIVE 0x8D6A
#define AzGl_ARRAY_BUFFER 0x8892
#define AzGl_ARRAY_BUFFER_BINDING 0x8894
#define AzGl_ATTACHED_SHADERS 0x8B85
#define AzGl_ATTRIB_STACK_DEPTH 0x0BB0
#define AzGl_AUTO_NORMAL 0x0D80
#define AzGl_AUX0 0x0409
#define AzGl_AUX1 0x040A
#define AzGl_AUX2 0x040B
#define AzGl_AUX3 0x040C
#define AzGl_AUX_BUFFERS 0x0C00
#define AzGl_BACK 0x0405
#define AzGl_BACK_LEFT 0x0402
#define AzGl_BACK_RIGHT 0x0403
#define AzGl_BGR 0x80E0
#define AzGl_BGRA 0x80E1
#define AzGl_BGRA8_EXT 0x93A1
#define AzGl_BGRA_EXT 0x80E1
#define AzGl_BGRA_INTEGER 0x8D9B
#define AzGl_BGR_INTEGER 0x8D9A
#define AzGl_BITMAP 0x1A00
#define AzGl_BITMAP_TOKEN 0x0704
#define AzGl_BLEND 0x0BE2
#define AzGl_BLEND_ADVANCED_COHERENT_KHR 0x9285
#define AzGl_BLEND_COLOR 0x8005
#define AzGl_BLEND_DST 0x0BE0
#define AzGl_BLEND_DST_ALPHA 0x80CA
#define AzGl_BLEND_DST_RGB 0x80C8
#define AzGl_BLEND_EQUATION 0x8009
#define AzGl_BLEND_EQUATION_ALPHA 0x883D
#define AzGl_BLEND_EQUATION_RGB 0x8009
#define AzGl_BLEND_SRC 0x0BE1
#define AzGl_BLEND_SRC_ALPHA 0x80CB
#define AzGl_BLEND_SRC_RGB 0x80C9
#define AzGl_BLUE 0x1905
#define AzGl_BLUE_BIAS 0x0D1B
#define AzGl_BLUE_BITS 0x0D54
#define AzGl_BLUE_INTEGER 0x8D96
#define AzGl_BLUE_SCALE 0x0D1A
#define AzGl_BOOL 0x8B56
#define AzGl_BOOL_VEC2 0x8B57
#define AzGl_BOOL_VEC3 0x8B58
#define AzGl_BOOL_VEC4 0x8B59
#define AzGl_BUFFER 0x82E0
#define AzGl_BUFFER_ACCESS 0x88BB
#define AzGl_BUFFER_ACCESS_FLAGS 0x911F
#define AzGl_BUFFER_KHR 0x82E0
#define AzGl_BUFFER_MAPPED 0x88BC
#define AzGl_BUFFER_MAP_LENGTH 0x9120
#define AzGl_BUFFER_MAP_OFFSET 0x9121
#define AzGl_BUFFER_MAP_POINTER 0x88BD
#define AzGl_BUFFER_SIZE 0x8764
#define AzGl_BUFFER_USAGE 0x8765
#define AzGl_BYTE 0x1400
#define AzGl_C3F_V3F 0x2A24
#define AzGl_C4F_N3F_V3F 0x2A26
#define AzGl_C4UB_V2F 0x2A22
#define AzGl_C4UB_V3F 0x2A23
#define AzGl_CCW 0x0901
#define AzGl_CLAMP 0x2900
#define AzGl_CLAMP_FRAGMENT_COLOR 0x891B
#define AzGl_CLAMP_READ_COLOR 0x891C
#define AzGl_CLAMP_TO_BORDER 0x812D
#define AzGl_CLAMP_TO_EDGE 0x812F
#define AzGl_CLAMP_VERTEX_COLOR 0x891A
#define AzGl_CLEAR 0x1500
#define AzGl_CLIENT_ACTIVE_TEXTURE 0x84E1
#define AzGl_CLIENT_ALL_ATTRIB_BITS 0xFFFFFFFF
#define AzGl_CLIENT_ATTRIB_STACK_DEPTH 0x0BB1
#define AzGl_CLIENT_PIXEL_STORE_BIT 0x00000001
#define AzGl_CLIENT_VERTEX_ARRAY_BIT 0x00000002
#define AzGl_CLIP_DISTANCE0 0x3000
#define AzGl_CLIP_DISTANCE1 0x3001
#define AzGl_CLIP_DISTANCE2 0x3002
#define AzGl_CLIP_DISTANCE3 0x3003
#define AzGl_CLIP_DISTANCE4 0x3004
#define AzGl_CLIP_DISTANCE5 0x3005
#define AzGl_CLIP_DISTANCE6 0x3006
#define AzGl_CLIP_DISTANCE7 0x3007
#define AzGl_CLIP_PLANE0 0x3000
#define AzGl_CLIP_PLANE1 0x3001
#define AzGl_CLIP_PLANE2 0x3002
#define AzGl_CLIP_PLANE3 0x3003
#define AzGl_CLIP_PLANE4 0x3004
#define AzGl_CLIP_PLANE5 0x3005
#define AzGl_COEFF 0x0A00
#define AzGl_COLOR 0x1800
#define AzGl_COLORBURN_KHR 0x929A
#define AzGl_COLORDODGE_KHR 0x9299
#define AzGl_COLOR_ARRAY 0x8076
#define AzGl_COLOR_ARRAY_BUFFER_BINDING 0x8898
#define AzGl_COLOR_ARRAY_POINTER 0x8090
#define AzGl_COLOR_ARRAY_SIZE 0x8081
#define AzGl_COLOR_ARRAY_STRIDE 0x8083
#define AzGl_COLOR_ARRAY_TYPE 0x8082
#define AzGl_COLOR_ATTACHMENT0 0x8CE0
#define AzGl_COLOR_ATTACHMENT1 0x8CE1
#define AzGl_COLOR_ATTACHMENT10 0x8CEA
#define AzGl_COLOR_ATTACHMENT11 0x8CEB
#define AzGl_COLOR_ATTACHMENT12 0x8CEC
#define AzGl_COLOR_ATTACHMENT13 0x8CED
#define AzGl_COLOR_ATTACHMENT14 0x8CEE
#define AzGl_COLOR_ATTACHMENT15 0x8CEF
#define AzGl_COLOR_ATTACHMENT16 0x8CF0
#define AzGl_COLOR_ATTACHMENT17 0x8CF1
#define AzGl_COLOR_ATTACHMENT18 0x8CF2
#define AzGl_COLOR_ATTACHMENT19 0x8CF3
#define AzGl_COLOR_ATTACHMENT2 0x8CE2
#define AzGl_COLOR_ATTACHMENT20 0x8CF4
#define AzGl_COLOR_ATTACHMENT21 0x8CF5
#define AzGl_COLOR_ATTACHMENT22 0x8CF6
#define AzGl_COLOR_ATTACHMENT23 0x8CF7
#define AzGl_COLOR_ATTACHMENT24 0x8CF8
#define AzGl_COLOR_ATTACHMENT25 0x8CF9
#define AzGl_COLOR_ATTACHMENT26 0x8CFA
#define AzGl_COLOR_ATTACHMENT27 0x8CFB
#define AzGl_COLOR_ATTACHMENT28 0x8CFC
#define AzGl_COLOR_ATTACHMENT29 0x8CFD
#define AzGl_COLOR_ATTACHMENT3 0x8CE3
#define AzGl_COLOR_ATTACHMENT30 0x8CFE
#define AzGl_COLOR_ATTACHMENT31 0x8CFF
#define AzGl_COLOR_ATTACHMENT4 0x8CE4
#define AzGl_COLOR_ATTACHMENT5 0x8CE5
#define AzGl_COLOR_ATTACHMENT6 0x8CE6
#define AzGl_COLOR_ATTACHMENT7 0x8CE7
#define AzGl_COLOR_ATTACHMENT8 0x8CE8
#define AzGl_COLOR_ATTACHMENT9 0x8CE9
#define AzGl_COLOR_BUFFER_BIT 0x00004000
#define AzGl_COLOR_CLEAR_VALUE 0x0C22
#define AzGl_COLOR_INDEX 0x1900
#define AzGl_COLOR_INDEXES 0x1603
#define AzGl_COLOR_LOGIC_OP 0x0BF2
#define AzGl_COLOR_MATERIAL 0x0B57
#define AzGl_COLOR_MATERIAL_FACE 0x0B55
#define AzGl_COLOR_MATERIAL_PARAMETER 0x0B56
#define AzGl_COLOR_SUM 0x8458
#define AzGl_COLOR_WRITEMASK 0x0C23
#define AzGl_COMBINE 0x8570
#define AzGl_COMBINE_ALPHA 0x8572
#define AzGl_COMBINE_RGB 0x8571
#define AzGl_COMPARE_REF_TO_TEXTURE 0x884E
#define AzGl_COMPARE_R_TO_TEXTURE 0x884E
#define AzGl_COMPILE 0x1300
#define AzGl_COMPILE_AND_EXECUTE 0x1301
#define AzGl_COMPILE_STATUS 0x8B81
#define AzGl_COMPRESSED_ALPHA 0x84E9
#define AzGl_COMPRESSED_INTENSITY 0x84EC
#define AzGl_COMPRESSED_LUMINANCE 0x84EA
#define AzGl_COMPRESSED_LUMINANCE_ALPHA 0x84EB
#define AzGl_COMPRESSED_R11_EAC 0x9270
#define AzGl_COMPRESSED_RED 0x8225
#define AzGl_COMPRESSED_RED_RGTC1 0x8DBB
#define AzGl_COMPRESSED_RG 0x8226
#define AzGl_COMPRESSED_RG11_EAC 0x9272
#define AzGl_COMPRESSED_RGB 0x84ED
#define AzGl_COMPRESSED_RGB8_ETC2 0x9274
#define AzGl_COMPRESSED_RGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9276
#define AzGl_COMPRESSED_RGBA 0x84EE
#define AzGl_COMPRESSED_RGBA8_ETC2_EAC 0x9278
#define AzGl_COMPRESSED_RG_RGTC2 0x8DBD
#define AzGl_COMPRESSED_SIGNED_R11_EAC 0x9271
#define AzGl_COMPRESSED_SIGNED_RED_RGTC1 0x8DBC
#define AzGl_COMPRESSED_SIGNED_RG11_EAC 0x9273
#define AzGl_COMPRESSED_SIGNED_RG_RGTC2 0x8DBE
#define AzGl_COMPRESSED_SLUMINANCE 0x8C4A
#define AzGl_COMPRESSED_SLUMINANCE_ALPHA 0x8C4B
#define AzGl_COMPRESSED_SRGB 0x8C48
#define AzGl_COMPRESSED_SRGB8_ALPHA8_ETC2_EAC 0x9279
#define AzGl_COMPRESSED_SRGB8_ETC2 0x9275
#define AzGl_COMPRESSED_SRGB8_PUNCHTHROUGH_ALPHA1_ETC2 0x9277
#define AzGl_COMPRESSED_SRGB_ALPHA 0x8C49
#define AzGl_COMPRESSED_TEXTURE_FORMATS 0x86A3
#define AzGl_CONDITION_SATISFIED 0x911C
#define AzGl_CONSTANT 0x8576
#define AzGl_CONSTANT_ALPHA 0x8003
#define AzGl_CONSTANT_ATTENUATION 0x1207
#define AzGl_CONSTANT_COLOR 0x8001
#define AzGl_CONTEXT_COMPATIBILITY_PROFILE_BIT 0x00000002
#define AzGl_CONTEXT_CORE_PROFILE_BIT 0x00000001
#define AzGl_CONTEXT_FLAGS 0x821E
#define AzGl_CONTEXT_FLAG_DEBUG_BIT 0x00000002
#define AzGl_CONTEXT_FLAG_DEBUG_BIT_KHR 0x00000002
#define AzGl_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT 0x00000001
#define AzGl_CONTEXT_PROFILE_MASK 0x9126
#define AzGl_COORD_REPLACE 0x8862
#define AzGl_COPY 0x1503
#define AzGl_COPY_INVERTED 0x150C
#define AzGl_COPY_PIXEL_TOKEN 0x0706
#define AzGl_COPY_READ_BUFFER 0x8F36
#define AzGl_COPY_READ_BUFFER_BINDING 0x8F36
#define AzGl_COPY_WRITE_BUFFER 0x8F37
#define AzGl_COPY_WRITE_BUFFER_BINDING 0x8F37
#define AzGl_CULL_FACE 0x0B44
#define AzGl_CULL_FACE_MODE 0x0B45
#define AzGl_CURRENT_BIT 0x00000001
#define AzGl_CURRENT_COLOR 0x0B00
#define AzGl_CURRENT_FOG_COORD 0x8453
#define AzGl_CURRENT_FOG_COORDINATE 0x8453
#define AzGl_CURRENT_INDEX 0x0B01
#define AzGl_CURRENT_NORMAL 0x0B02
#define AzGl_CURRENT_PROGRAM 0x8B8D
#define AzGl_CURRENT_QUERY 0x8865
#define AzGl_CURRENT_QUERY_EXT 0x8865
#define AzGl_CURRENT_RASTER_COLOR 0x0B04
#define AzGl_CURRENT_RASTER_DISTANCE 0x0B09
#define AzGl_CURRENT_RASTER_INDEX 0x0B05
#define AzGl_CURRENT_RASTER_POSITION 0x0B07
#define AzGl_CURRENT_RASTER_POSITION_VALID 0x0B08
#define AzGl_CURRENT_RASTER_SECONDARY_COLOR 0x845F
#define AzGl_CURRENT_RASTER_TEXTURE_COORDS 0x0B06
#define AzGl_CURRENT_SECONDARY_COLOR 0x8459
#define AzGl_CURRENT_TEXTURE_COORDS 0x0B03
#define AzGl_CURRENT_VERTEX_ATTRIB 0x8626
#define AzGl_CW 0x0900
#define AzGl_DARKEN_KHR 0x9297
#define AzGl_DEBUG_CALLBACK_FUNCTION 0x8244
#define AzGl_DEBUG_CALLBACK_FUNCTION_KHR 0x8244
#define AzGl_DEBUG_CALLBACK_USER_PARAM 0x8245
#define AzGl_DEBUG_CALLBACK_USER_PARAM_KHR 0x8245
#define AzGl_DEBUG_GROUP_STACK_DEPTH 0x826D
#define AzGl_DEBUG_GROUP_STACK_DEPTH_KHR 0x826D
#define AzGl_DEBUG_LOGGED_MESSAGES 0x9145
#define AzGl_DEBUG_LOGGED_MESSAGES_KHR 0x9145
#define AzGl_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH 0x8243
#define AzGl_DEBUG_NEXT_LOGGED_MESSAGE_LENGTH_KHR 0x8243
#define AzGl_DEBUG_OUTPUT 0x92E0
#define AzGl_DEBUG_OUTPUT_KHR 0x92E0
#define AzGl_DEBUG_OUTPUT_SYNCHRONOUS 0x8242
#define AzGl_DEBUG_OUTPUT_SYNCHRONOUS_KHR 0x8242
#define AzGl_DEBUG_SEVERITY_HIGH 0x9146
#define AzGl_DEBUG_SEVERITY_HIGH_KHR 0x9146
#define AzGl_DEBUG_SEVERITY_LOW 0x9148
#define AzGl_DEBUG_SEVERITY_LOW_KHR 0x9148
#define AzGl_DEBUG_SEVERITY_MEDIUM 0x9147
#define AzGl_DEBUG_SEVERITY_MEDIUM_KHR 0x9147
#define AzGl_DEBUG_SEVERITY_NOTIFICATION 0x826B
#define AzGl_DEBUG_SEVERITY_NOTIFICATION_KHR 0x826B
#define AzGl_DEBUG_SOURCE_API 0x8246
#define AzGl_DEBUG_SOURCE_API_KHR 0x8246
#define AzGl_DEBUG_SOURCE_APPLICATION 0x824A
#define AzGl_DEBUG_SOURCE_APPLICATION_KHR 0x824A
#define AzGl_DEBUG_SOURCE_OTHER 0x824B
#define AzGl_DEBUG_SOURCE_OTHER_KHR 0x824B
#define AzGl_DEBUG_SOURCE_SHADER_COMPILER 0x8248
#define AzGl_DEBUG_SOURCE_SHADER_COMPILER_KHR 0x8248
#define AzGl_DEBUG_SOURCE_THIRD_PARTY 0x8249
#define AzGl_DEBUG_SOURCE_THIRD_PARTY_KHR 0x8249
#define AzGl_DEBUG_SOURCE_WINDOW_SYSTEM 0x8247
#define AzGl_DEBUG_SOURCE_WINDOW_SYSTEM_KHR 0x8247
#define AzGl_DEBUG_TYPE_DEPRECATED_BEHAVIOR 0x824D
#define AzGl_DEBUG_TYPE_DEPRECATED_BEHAVIOR_KHR 0x824D
#define AzGl_DEBUG_TYPE_ERROR 0x824C
#define AzGl_DEBUG_TYPE_ERROR_KHR 0x824C
#define AzGl_DEBUG_TYPE_MARKER 0x8268
#define AzGl_DEBUG_TYPE_MARKER_KHR 0x8268
#define AzGl_DEBUG_TYPE_OTHER 0x8251
#define AzGl_DEBUG_TYPE_OTHER_KHR 0x8251
#define AzGl_DEBUG_TYPE_PERFORMANCE 0x8250
#define AzGl_DEBUG_TYPE_PERFORMANCE_KHR 0x8250
#define AzGl_DEBUG_TYPE_POP_GROUP 0x826A
#define AzGl_DEBUG_TYPE_POP_GROUP_KHR 0x826A
#define AzGl_DEBUG_TYPE_PORTABILITY 0x824F
#define AzGl_DEBUG_TYPE_PORTABILITY_KHR 0x824F
#define AzGl_DEBUG_TYPE_PUSH_GROUP 0x8269
#define AzGl_DEBUG_TYPE_PUSH_GROUP_KHR 0x8269
#define AzGl_DEBUG_TYPE_UNDEFINED_BEHAVIOR 0x824E
#define AzGl_DEBUG_TYPE_UNDEFINED_BEHAVIOR_KHR 0x824E
#define AzGl_DECAL 0x2101
#define AzGl_DECR 0x1E03
#define AzGl_DECR_WRAP 0x8508
#define AzGl_DELETE_STATUS 0x8B80
#define AzGl_DEPTH 0x1801
#define AzGl_DEPTH24_STENCIL8 0x88F0
#define AzGl_DEPTH32F_STENCIL8 0x8CAD
#define AzGl_DEPTH_ATTACHMENT 0x8D00
#define AzGl_DEPTH_BIAS 0x0D1F
#define AzGl_DEPTH_BITS 0x0D56
#define AzGl_DEPTH_BUFFER_BIT 0x00000100
#define AzGl_DEPTH_CLAMP 0x864F
#define AzGl_DEPTH_CLEAR_VALUE 0x0B73
#define AzGl_DEPTH_COMPONENT 0x1902
#define AzGl_DEPTH_COMPONENT16 0x81A5
#define AzGl_DEPTH_COMPONENT24 0x81A6
#define AzGl_DEPTH_COMPONENT32 0x81A7
#define AzGl_DEPTH_COMPONENT32F 0x8CAC
#define AzGl_DEPTH_FUNC 0x0B74
#define AzGl_DEPTH_RANGE 0x0B70
#define AzGl_DEPTH_SCALE 0x0D1E
#define AzGl_DEPTH_STENCIL 0x84F9
#define AzGl_DEPTH_STENCIL_ATTACHMENT 0x821A
#define AzGl_DEPTH_TEST 0x0B71
#define AzGl_DEPTH_TEXTURE_MODE 0x884B
#define AzGl_DEPTH_WRITEMASK 0x0B72
#define AzGl_DIFFERENCE_KHR 0x929E
#define AzGl_DIFFUSE 0x1201
#define AzGl_DISPLAY_LIST 0x82E7
#define AzGl_DITHER 0x0BD0
#define AzGl_DOMAIN 0x0A02
#define AzGl_DONT_CARE 0x1100
#define AzGl_DOT3_RGB 0x86AE
#define AzGl_DOT3_RGBA 0x86AF
#define AzGl_DOUBLE 0x140A
#define AzGl_DOUBLEBUFFER 0x0C32
#define AzGl_DRAW_BUFFER 0x0C01
#define AzGl_DRAW_BUFFER0 0x8825
#define AzGl_DRAW_BUFFER1 0x8826
#define AzGl_DRAW_BUFFER10 0x882F
#define AzGl_DRAW_BUFFER11 0x8830
#define AzGl_DRAW_BUFFER12 0x8831
#define AzGl_DRAW_BUFFER13 0x8832
#define AzGl_DRAW_BUFFER14 0x8833
#define AzGl_DRAW_BUFFER15 0x8834
#define AzGl_DRAW_BUFFER2 0x8827
#define AzGl_DRAW_BUFFER3 0x8828
#define AzGl_DRAW_BUFFER4 0x8829
#define AzGl_DRAW_BUFFER5 0x882A
#define AzGl_DRAW_BUFFER6 0x882B
#define AzGl_DRAW_BUFFER7 0x882C
#define AzGl_DRAW_BUFFER8 0x882D
#define AzGl_DRAW_BUFFER9 0x882E
#define AzGl_DRAW_FRAMEBUFFER 0x8CA9
#define AzGl_DRAW_FRAMEBUFFER_BINDING 0x8CA6
#define AzGl_DRAW_PIXELS_APPLE 0x8A0A
#define AzGl_DRAW_PIXEL_TOKEN 0x0705
#define AzGl_DST_ALPHA 0x0304
#define AzGl_DST_COLOR 0x0306
#define AzGl_DYNAMIC_COPY 0x88EA
#define AzGl_DYNAMIC_DRAW 0x88E8
#define AzGl_DYNAMIC_READ 0x88E9
#define AzGl_EDGE_FLAG 0x0B43
#define AzGl_EDGE_FLAG_ARRAY 0x8079
#define AzGl_EDGE_FLAG_ARRAY_BUFFER_BINDING 0x889B
#define AzGl_EDGE_FLAG_ARRAY_POINTER 0x8093
#define AzGl_EDGE_FLAG_ARRAY_STRIDE 0x808C
#define AzGl_ELEMENT_ARRAY_BUFFER 0x8893
#define AzGl_ELEMENT_ARRAY_BUFFER_BINDING 0x8895
#define AzGl_EMISSION 0x1600
#define AzGl_ENABLE_BIT 0x00002000
#define AzGl_EQUAL 0x0202
#define AzGl_EQUIV 0x1509
#define AzGl_EVAL_BIT 0x00010000
#define AzGl_EXCLUSION_KHR 0x92A0
#define AzGl_EXP 0x0800
#define AzGl_EXP2 0x0801
#define AzGl_EXTENSIONS 0x1F03
#define AzGl_EYE_LINEAR 0x2400
#define AzGl_EYE_PLANE 0x2502
#define AzGl_FALSE 0
#define AzGl_FASTEST 0x1101
#define AzGl_FEEDBACK 0x1C01
#define AzGl_FEEDBACK_BUFFER_POINTER 0x0DF0
#define AzGl_FEEDBACK_BUFFER_SIZE 0x0DF1
#define AzGl_FEEDBACK_BUFFER_TYPE 0x0DF2
#define AzGl_FENCE_APPLE 0x8A0B
#define AzGl_FILL 0x1B02
#define AzGl_FIRST_VERTEX_CONVENTION 0x8E4D
#define AzGl_FIXED 0x140C
#define AzGl_FIXED_ONLY 0x891D
#define AzGl_FLAT 0x1D00
#define AzGl_FLOAT 0x1406
#define AzGl_FLOAT_32_UNSIGNED_INT_24_8_REV 0x8DAD
#define AzGl_FLOAT_MAT2 0x8B5A
#define AzGl_FLOAT_MAT2x3 0x8B65
#define AzGl_FLOAT_MAT2x4 0x8B66
#define AzGl_FLOAT_MAT3 0x8B5B
#define AzGl_FLOAT_MAT3x2 0x8B67
#define AzGl_FLOAT_MAT3x4 0x8B68
#define AzGl_FLOAT_MAT4 0x8B5C
#define AzGl_FLOAT_MAT4x2 0x8B69
#define AzGl_FLOAT_MAT4x3 0x8B6A
#define AzGl_FLOAT_VEC2 0x8B50
#define AzGl_FLOAT_VEC3 0x8B51
#define AzGl_FLOAT_VEC4 0x8B52
#define AzGl_FOG 0x0B60
#define AzGl_FOG_BIT 0x00000080
#define AzGl_FOG_COLOR 0x0B66
#define AzGl_FOG_COORD 0x8451
#define AzGl_FOG_COORDINATE 0x8451
#define AzGl_FOG_COORDINATE_ARRAY 0x8457
#define AzGl_FOG_COORDINATE_ARRAY_BUFFER_BINDING 0x889D
#define AzGl_FOG_COORDINATE_ARRAY_POINTER 0x8456
#define AzGl_FOG_COORDINATE_ARRAY_STRIDE 0x8455
#define AzGl_FOG_COORDINATE_ARRAY_TYPE 0x8454
#define AzGl_FOG_COORDINATE_SOURCE 0x8450
#define AzGl_FOG_COORD_ARRAY 0x8457
#define AzGl_FOG_COORD_ARRAY_BUFFER_BINDING 0x889D
#define AzGl_FOG_COORD_ARRAY_POINTER 0x8456
#define AzGl_FOG_COORD_ARRAY_STRIDE 0x8455
#define AzGl_FOG_COORD_ARRAY_TYPE 0x8454
#define AzGl_FOG_COORD_SRC 0x8450
#define AzGl_FOG_DENSITY 0x0B62
#define AzGl_FOG_END 0x0B64
#define AzGl_FOG_HINT 0x0C54
#define AzGl_FOG_INDEX 0x0B61
#define AzGl_FOG_MODE 0x0B65
#define AzGl_FOG_START 0x0B63
#define AzGl_FRAGMENT_DEPTH 0x8452
#define AzGl_FRAGMENT_SHADER 0x8B30
#define AzGl_FRAGMENT_SHADER_DERIVATIVE_HINT 0x8B8B
#define AzGl_FRAMEBUFFER 0x8D40
#define AzGl_FRAMEBUFFER_ATTACHMENT_ALPHA_SIZE 0x8215
#define AzGl_FRAMEBUFFER_ATTACHMENT_ANGLE 0x93A3
#define AzGl_FRAMEBUFFER_ATTACHMENT_BLUE_SIZE 0x8214
#define AzGl_FRAMEBUFFER_ATTACHMENT_COLOR_ENCODING 0x8210
#define AzGl_FRAMEBUFFER_ATTACHMENT_COMPONENT_TYPE 0x8211
#define AzGl_FRAMEBUFFER_ATTACHMENT_DEPTH_SIZE 0x8216
#define AzGl_FRAMEBUFFER_ATTACHMENT_GREEN_SIZE 0x8213
#define AzGl_FRAMEBUFFER_ATTACHMENT_LAYERED 0x8DA7
#define AzGl_FRAMEBUFFER_ATTACHMENT_OBJECT_NAME 0x8CD1
#define AzGl_FRAMEBUFFER_ATTACHMENT_OBJECT_TYPE 0x8CD0
#define AzGl_FRAMEBUFFER_ATTACHMENT_RED_SIZE 0x8212
#define AzGl_FRAMEBUFFER_ATTACHMENT_STENCIL_SIZE 0x8217
#define AzGl_FRAMEBUFFER_ATTACHMENT_TEXTURE_CUBE_MAP_FACE 0x8CD3
#define AzGl_FRAMEBUFFER_ATTACHMENT_TEXTURE_LAYER 0x8CD4
#define AzGl_FRAMEBUFFER_ATTACHMENT_TEXTURE_LEVEL 0x8CD2
#define AzGl_FRAMEBUFFER_BINDING 0x8CA6
#define AzGl_FRAMEBUFFER_COMPLETE 0x8CD5
#define AzGl_FRAMEBUFFER_DEFAULT 0x8218
#define AzGl_FRAMEBUFFER_INCOMPLETE_ATTACHMENT 0x8CD6
#define AzGl_FRAMEBUFFER_INCOMPLETE_DIMENSIONS 0x8CD9
#define AzGl_FRAMEBUFFER_INCOMPLETE_DRAW_BUFFER 0x8CDB
#define AzGl_FRAMEBUFFER_INCOMPLETE_LAYER_TARGETS 0x8DA8
#define AzGl_FRAMEBUFFER_INCOMPLETE_MISSING_ATTACHMENT 0x8CD7
#define AzGl_FRAMEBUFFER_INCOMPLETE_MULTISAMPLE 0x8D56
#define AzGl_FRAMEBUFFER_INCOMPLETE_READ_BUFFER 0x8CDC
#define AzGl_FRAMEBUFFER_SRGB 0x8DB9
#define AzGl_FRAMEBUFFER_UNDEFINED 0x8219
#define AzGl_FRAMEBUFFER_UNSUPPORTED 0x8CDD
#define AzGl_FRONT 0x0404
#define AzGl_FRONT_AND_BACK 0x0408
#define AzGl_FRONT_FACE 0x0B46
#define AzGl_FRONT_LEFT 0x0400
#define AzGl_FRONT_RIGHT 0x0401
#define AzGl_FUNC_ADD 0x8006
#define AzGl_FUNC_REVERSE_SUBTRACT 0x800B
#define AzGl_FUNC_SUBTRACT 0x800A
#define AzGl_GENERATE_MIPMAP 0x8191
#define AzGl_GENERATE_MIPMAP_HINT 0x8192
#define AzGl_GEOMETRY_INPUT_TYPE 0x8917
#define AzGl_GEOMETRY_OUTPUT_TYPE 0x8918
#define AzGl_GEOMETRY_SHADER 0x8DD9
#define AzGl_GEOMETRY_VERTICES_OUT 0x8916
#define AzGl_GEQUAL 0x0206
#define AzGl_GPU_DISJOINT_EXT 0x8FBB
#define AzGl_GREATER 0x0204
#define AzGl_GREEN 0x1904
#define AzGl_GREEN_BIAS 0x0D19
#define AzGl_GREEN_BITS 0x0D53
#define AzGl_GREEN_INTEGER 0x8D95
#define AzGl_GREEN_SCALE 0x0D18
#define AzGl_HALF_FLOAT 0x140B
#define AzGl_HALF_FLOAT_OES 0x8D61
#define AzGl_HARDLIGHT_KHR 0x929B
#define AzGl_HIGH_FLOAT 0x8DF2
#define AzGl_HIGH_INT 0x8DF5
#define AzGl_HINT_BIT 0x00008000
#define AzGl_HSL_COLOR_KHR 0x92AF
#define AzGl_HSL_HUE_KHR 0x92AD
#define AzGl_HSL_LUMINOSITY_KHR 0x92B0
#define AzGl_HSL_SATURATION_KHR 0x92AE
#define AzGl_IMPLEMENTATION_COLOR_READ_FORMAT 0x8B9B
#define AzGl_IMPLEMENTATION_COLOR_READ_TYPE 0x8B9A
#define AzGl_INCR 0x1E02
#define AzGl_INCR_WRAP 0x8507
#define AzGl_INDEX 0x8222
#define AzGl_INDEX_ARRAY 0x8077
#define AzGl_INDEX_ARRAY_BUFFER_BINDING 0x8899
#define AzGl_INDEX_ARRAY_POINTER 0x8091
#define AzGl_INDEX_ARRAY_STRIDE 0x8086
#define AzGl_INDEX_ARRAY_TYPE 0x8085
#define AzGl_INDEX_BITS 0x0D51
#define AzGl_INDEX_CLEAR_VALUE 0x0C20
#define AzGl_INDEX_LOGIC_OP 0x0BF1
#define AzGl_INDEX_MODE 0x0C30
#define AzGl_INDEX_OFFSET 0x0D13
#define AzGl_INDEX_SHIFT 0x0D12
#define AzGl_INDEX_WRITEMASK 0x0C21
#define AzGl_INFO_LOG_LENGTH 0x8B84
#define AzGl_INT 0x1404
#define AzGl_INTENSITY 0x8049
#define AzGl_INTENSITY12 0x804C
#define AzGl_INTENSITY16 0x804D
#define AzGl_INTENSITY4 0x804A
#define AzGl_INTENSITY8 0x804B
#define AzGl_INTERLEAVED_ATTRIBS 0x8C8C
#define AzGl_INTERPOLATE 0x8575
#define AzGl_INT_2_10_10_10_REV 0x8D9F
#define AzGl_INT_SAMPLER_1D 0x8DC9
#define AzGl_INT_SAMPLER_1D_ARRAY 0x8DCE
#define AzGl_INT_SAMPLER_2D 0x8DCA
#define AzGl_INT_SAMPLER_2D_ARRAY 0x8DCF
#define AzGl_INT_SAMPLER_2D_MULTISAMPLE 0x9109
#define AzGl_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910C
#define AzGl_INT_SAMPLER_2D_RECT 0x8DCD
#define AzGl_INT_SAMPLER_3D 0x8DCB
#define AzGl_INT_SAMPLER_BUFFER 0x8DD0
#define AzGl_INT_SAMPLER_CUBE 0x8DCC
#define AzGl_INT_VEC2 0x8B53
#define AzGl_INT_VEC3 0x8B54
#define AzGl_INT_VEC4 0x8B55
#define AzGl_INVALID_ENUM 0x0500
#define AzGl_INVALID_FRAMEBUFFER_OPERATION 0x0506
#define AzGl_INVALID_INDEX 0xFFFFFFFF
#define AzGl_INVALID_OPERATION 0x0502
#define AzGl_INVALID_VALUE 0x0501
#define AzGl_INVERT 0x150A
#define AzGl_KEEP 0x1E00
#define AzGl_LAST_VERTEX_CONVENTION 0x8E4E
#define AzGl_LEFT 0x0406
#define AzGl_LEQUAL 0x0203
#define AzGl_LESS 0x0201
#define AzGl_LIGHT0 0x4000
#define AzGl_LIGHT1 0x4001
#define AzGl_LIGHT2 0x4002
#define AzGl_LIGHT3 0x4003
#define AzGl_LIGHT4 0x4004
#define AzGl_LIGHT5 0x4005
#define AzGl_LIGHT6 0x4006
#define AzGl_LIGHT7 0x4007
#define AzGl_LIGHTEN_KHR 0x9298
#define AzGl_LIGHTING 0x0B50
#define AzGl_LIGHTING_BIT 0x00000040
#define AzGl_LIGHT_MODEL_AMBIENT 0x0B53
#define AzGl_LIGHT_MODEL_COLOR_CONTROL 0x81F8
#define AzGl_LIGHT_MODEL_LOCAL_VIEWER 0x0B51
#define AzGl_LIGHT_MODEL_TWO_SIDE 0x0B52
#define AzGl_LINE 0x1B01
#define AzGl_LINEAR 0x2601
#define AzGl_LINEAR_ATTENUATION 0x1208
#define AzGl_LINEAR_MIPMAP_LINEAR 0x2703
#define AzGl_LINEAR_MIPMAP_NEAREST 0x2701
#define AzGl_LINES 0x0001
#define AzGl_LINES_ADJACENCY 0x000A
#define AzGl_LINE_BIT 0x00000004
#define AzGl_LINE_LOOP 0x0002
#define AzGl_LINE_RESET_TOKEN 0x0707
#define AzGl_LINE_SMOOTH 0x0B20
#define AzGl_LINE_SMOOTH_HINT 0x0C52
#define AzGl_LINE_STIPPLE 0x0B24
#define AzGl_LINE_STIPPLE_PATTERN 0x0B25
#define AzGl_LINE_STIPPLE_REPEAT 0x0B26
#define AzGl_LINE_STRIP 0x0003
#define AzGl_LINE_STRIP_ADJACENCY 0x000B
#define AzGl_LINE_TOKEN 0x0702
#define AzGl_LINE_WIDTH 0x0B21
#define AzGl_LINE_WIDTH_GRANULARITY 0x0B23
#define AzGl_LINE_WIDTH_RANGE 0x0B22
#define AzGl_LINK_STATUS 0x8B82
#define AzGl_LIST_BASE 0x0B32
#define AzGl_LIST_BIT 0x00020000
#define AzGl_LIST_INDEX 0x0B33
#define AzGl_LIST_MODE 0x0B30
#define AzGl_LOAD 0x0101
#define AzGl_LOGIC_OP 0x0BF1
#define AzGl_LOGIC_OP_MODE 0x0BF0
#define AzGl_LOWER_LEFT 0x8CA1
#define AzGl_LOW_FLOAT 0x8DF0
#define AzGl_LOW_INT 0x8DF3
#define AzGl_LUMINANCE 0x1909
#define AzGl_LUMINANCE12 0x8041
#define AzGl_LUMINANCE12_ALPHA12 0x8047
#define AzGl_LUMINANCE12_ALPHA4 0x8046
#define AzGl_LUMINANCE16 0x8042
#define AzGl_LUMINANCE16F_EXT 0x881E
#define AzGl_LUMINANCE16_ALPHA16 0x8048
#define AzGl_LUMINANCE32F_EXT 0x8818
#define AzGl_LUMINANCE4 0x803F
#define AzGl_LUMINANCE4_ALPHA4 0x8043
#define AzGl_LUMINANCE6_ALPHA2 0x8044
#define AzGl_LUMINANCE8 0x8040
#define AzGl_LUMINANCE8_ALPHA8 0x8045
#define AzGl_LUMINANCE8_ALPHA8_EXT 0x8045
#define AzGl_LUMINANCE8_EXT 0x8040
#define AzGl_LUMINANCE_ALPHA 0x190A
#define AzGl_LUMINANCE_ALPHA16F_EXT 0x881F
#define AzGl_LUMINANCE_ALPHA32F_EXT 0x8819
#define AzGl_MAJOR_VERSION 0x821B
#define AzGl_MAP1_COLOR_4 0x0D90
#define AzGl_MAP1_GRID_DOMAIN 0x0DD0
#define AzGl_MAP1_GRID_SEGMENTS 0x0DD1
#define AzGl_MAP1_INDEX 0x0D91
#define AzGl_MAP1_NORMAL 0x0D92
#define AzGl_MAP1_TEXTURE_COORD_1 0x0D93
#define AzGl_MAP1_TEXTURE_COORD_2 0x0D94
#define AzGl_MAP1_TEXTURE_COORD_3 0x0D95
#define AzGl_MAP1_TEXTURE_COORD_4 0x0D96
#define AzGl_MAP1_VERTEX_3 0x0D97
#define AzGl_MAP1_VERTEX_4 0x0D98
#define AzGl_MAP2_COLOR_4 0x0DB0
#define AzGl_MAP2_GRID_DOMAIN 0x0DD2
#define AzGl_MAP2_GRID_SEGMENTS 0x0DD3
#define AzGl_MAP2_INDEX 0x0DB1
#define AzGl_MAP2_NORMAL 0x0DB2
#define AzGl_MAP2_TEXTURE_COORD_1 0x0DB3
#define AzGl_MAP2_TEXTURE_COORD_2 0x0DB4
#define AzGl_MAP2_TEXTURE_COORD_3 0x0DB5
#define AzGl_MAP2_TEXTURE_COORD_4 0x0DB6
#define AzGl_MAP2_VERTEX_3 0x0DB7
#define AzGl_MAP2_VERTEX_4 0x0DB8
#define AzGl_MAP_COLOR 0x0D10
#define AzGl_MAP_FLUSH_EXPLICIT_BIT 0x0010
#define AzGl_MAP_INVALIDATE_BUFFER_BIT 0x0008
#define AzGl_MAP_INVALIDATE_RANGE_BIT 0x0004
#define AzGl_MAP_READ_BIT 0x0001
#define AzGl_MAP_STENCIL 0x0D11
#define AzGl_MAP_UNSYNCHRONIZED_BIT 0x0020
#define AzGl_MAP_WRITE_BIT 0x0002
#define AzGl_MATRIX_MODE 0x0BA0
#define AzGl_MAX 0x8008
#define AzGl_MAX_3D_TEXTURE_SIZE 0x8073
#define AzGl_MAX_ARRAY_TEXTURE_LAYERS 0x88FF
#define AzGl_MAX_ATTRIB_STACK_DEPTH 0x0D35
#define AzGl_MAX_CLIENT_ATTRIB_STACK_DEPTH 0x0D3B
#define AzGl_MAX_CLIP_DISTANCES 0x0D32
#define AzGl_MAX_CLIP_PLANES 0x0D32
#define AzGl_MAX_COLOR_ATTACHMENTS 0x8CDF
#define AzGl_MAX_COLOR_TEXTURE_SAMPLES 0x910E
#define AzGl_MAX_COMBINED_FRAGMENT_UNIFORM_COMPONENTS 0x8A33
#define AzGl_MAX_COMBINED_GEOMETRY_UNIFORM_COMPONENTS 0x8A32
#define AzGl_MAX_COMBINED_TEXTURE_IMAGE_UNITS 0x8B4D
#define AzGl_MAX_COMBINED_UNIFORM_BLOCKS 0x8A2E
#define AzGl_MAX_COMBINED_VERTEX_UNIFORM_COMPONENTS 0x8A31
#define AzGl_MAX_CUBE_MAP_TEXTURE_SIZE 0x851C
#define AzGl_MAX_DEBUG_GROUP_STACK_DEPTH 0x826C
#define AzGl_MAX_DEBUG_GROUP_STACK_DEPTH_KHR 0x826C
#define AzGl_MAX_DEBUG_LOGGED_MESSAGES 0x9144
#define AzGl_MAX_DEBUG_LOGGED_MESSAGES_KHR 0x9144
#define AzGl_MAX_DEBUG_MESSAGE_LENGTH 0x9143
#define AzGl_MAX_DEBUG_MESSAGE_LENGTH_KHR 0x9143
#define AzGl_MAX_DEPTH_TEXTURE_SAMPLES 0x910F
#define AzGl_MAX_DRAW_BUFFERS 0x8824
#define AzGl_MAX_DUAL_SOURCE_DRAW_BUFFERS 0x88FC
#define AzGl_MAX_ELEMENTS_INDICES 0x80E9
#define AzGl_MAX_ELEMENTS_VERTICES 0x80E8
#define AzGl_MAX_ELEMENT_INDEX 0x8D6B
#define AzGl_MAX_EVAL_ORDER 0x0D30
#define AzGl_MAX_FRAGMENT_INPUT_COMPONENTS 0x9125
#define AzGl_MAX_FRAGMENT_UNIFORM_BLOCKS 0x8A2D
#define AzGl_MAX_FRAGMENT_UNIFORM_COMPONENTS 0x8B49
#define AzGl_MAX_FRAGMENT_UNIFORM_VECTORS 0x8DFD
#define AzGl_MAX_GEOMETRY_INPUT_COMPONENTS 0x9123
#define AzGl_MAX_GEOMETRY_OUTPUT_COMPONENTS 0x9124
#define AzGl_MAX_GEOMETRY_OUTPUT_VERTICES 0x8DE0
#define AzGl_MAX_GEOMETRY_TEXTURE_IMAGE_UNITS 0x8C29
#define AzGl_MAX_GEOMETRY_TOTAL_OUTPUT_COMPONENTS 0x8DE1
#define AzGl_MAX_GEOMETRY_UNIFORM_BLOCKS 0x8A2C
#define AzGl_MAX_GEOMETRY_UNIFORM_COMPONENTS 0x8DDF
#define AzGl_MAX_INTEGER_SAMPLES 0x9110
#define AzGl_MAX_LABEL_LENGTH 0x82E8
#define AzGl_MAX_LABEL_LENGTH_KHR 0x82E8
#define AzGl_MAX_LIGHTS 0x0D31
#define AzGl_MAX_LIST_NESTING 0x0B31
#define AzGl_MAX_MODELVIEW_STACK_DEPTH 0x0D36
#define AzGl_MAX_NAME_STACK_DEPTH 0x0D37
#define AzGl_MAX_PIXEL_MAP_TABLE 0x0D34
#define AzGl_MAX_PROGRAM_TEXEL_OFFSET 0x8905
#define AzGl_MAX_PROJECTION_STACK_DEPTH 0x0D38
#define AzGl_MAX_RECTANGLE_TEXTURE_SIZE 0x84F8
#define AzGl_MAX_RECTANGLE_TEXTURE_SIZE_ARB 0x84F8
#define AzGl_MAX_RENDERBUFFER_SIZE 0x84E8
#define AzGl_MAX_SAMPLES 0x8D57
#define AzGl_MAX_SAMPLE_MASK_WORDS 0x8E59
#define AzGl_MAX_SERVER_WAIT_TIMEOUT 0x9111
#define AzGl_MAX_SHADER_PIXEL_LOCAL_STORAGE_FAST_SIZE_EXT 0x8F63
#define AzGl_MAX_SHADER_PIXEL_LOCAL_STORAGE_SIZE_EXT 0x8F67
#define AzGl_MAX_TEXTURE_BUFFER_SIZE 0x8C2B
#define AzGl_MAX_TEXTURE_COORDS 0x8871
#define AzGl_MAX_TEXTURE_IMAGE_UNITS 0x8872
#define AzGl_MAX_TEXTURE_LOD_BIAS 0x84FD
#define AzGl_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
#define AzGl_MAX_TEXTURE_SIZE 0x0D33
#define AzGl_MAX_TEXTURE_STACK_DEPTH 0x0D39
#define AzGl_MAX_TEXTURE_UNITS 0x84E2
#define AzGl_MAX_TRANSFORM_FEEDBACK_INTERLEAVED_COMPONENTS 0x8C8A
#define AzGl_MAX_TRANSFORM_FEEDBACK_SEPARATE_ATTRIBS 0x8C8B
#define AzGl_MAX_TRANSFORM_FEEDBACK_SEPARATE_COMPONENTS 0x8C80
#define AzGl_MAX_UNIFORM_BLOCK_SIZE 0x8A30
#define AzGl_MAX_UNIFORM_BUFFER_BINDINGS 0x8A2F
#define AzGl_MAX_VARYING_COMPONENTS 0x8B4B
#define AzGl_MAX_VARYING_FLOATS 0x8B4B
#define AzGl_MAX_VARYING_VECTORS 0x8DFC
#define AzGl_MAX_VERTEX_ATTRIBS 0x8869
#define AzGl_MAX_VERTEX_OUTPUT_COMPONENTS 0x9122
#define AzGl_MAX_VERTEX_TEXTURE_IMAGE_UNITS 0x8B4C
#define AzGl_MAX_VERTEX_UNIFORM_BLOCKS 0x8A2B
#define AzGl_MAX_VERTEX_UNIFORM_COMPONENTS 0x8B4A
#define AzGl_MAX_VERTEX_UNIFORM_VECTORS 0x8DFB
#define AzGl_MAX_VIEWPORT_DIMS 0x0D3A
#define AzGl_MEDIUM_FLOAT 0x8DF1
#define AzGl_MEDIUM_INT 0x8DF4
#define AzGl_MIN 0x8007
#define AzGl_MINOR_VERSION 0x821C
#define AzGl_MIN_PROGRAM_TEXEL_OFFSET 0x8904
#define AzGl_MIRRORED_REPEAT 0x8370
#define AzGl_MODELVIEW 0x1700
#define AzGl_MODELVIEW_MATRIX 0x0BA6
#define AzGl_MODELVIEW_STACK_DEPTH 0x0BA3
#define AzGl_MODULATE 0x2100
#define AzGl_MULT 0x0103
#define AzGl_MULTIPLY_KHR 0x9294
#define AzGl_MULTISAMPLE 0x809D
#define AzGl_MULTISAMPLE_BIT 0x20000000
#define AzGl_N3F_V3F 0x2A25
#define AzGl_NAME_STACK_DEPTH 0x0D70
#define AzGl_NAND 0x150E
#define AzGl_NEAREST 0x2600
#define AzGl_NEAREST_MIPMAP_LINEAR 0x2702
#define AzGl_NEAREST_MIPMAP_NEAREST 0x2700
#define AzGl_NEVER 0x0200
#define AzGl_NICEST 0x1102
#define AzGl_NONE 0
#define AzGl_NOOP 0x1505
#define AzGl_NOR 0x1508
#define AzGl_NORMALIZE 0x0BA1
#define AzGl_NORMAL_ARRAY 0x8075
#define AzGl_NORMAL_ARRAY_BUFFER_BINDING 0x8897
#define AzGl_NORMAL_ARRAY_POINTER 0x808F
#define AzGl_NORMAL_ARRAY_STRIDE 0x807F
#define AzGl_NORMAL_ARRAY_TYPE 0x807E
#define AzGl_NORMAL_MAP 0x8511
#define AzGl_NOTEQUAL 0x0205
#define AzGl_NO_ERROR 0
#define AzGl_NUM_COMPRESSED_TEXTURE_FORMATS 0x86A2
#define AzGl_NUM_EXTENSIONS 0x821D
#define AzGl_NUM_PROGRAM_BINARY_FORMATS 0x87FE
#define AzGl_NUM_SAMPLE_COUNTS 0x9380
#define AzGl_NUM_SHADER_BINARY_FORMATS 0x8DF9
#define AzGl_OBJECT_LINEAR 0x2401
#define AzGl_OBJECT_PLANE 0x2501
#define AzGl_OBJECT_TYPE 0x9112
#define AzGl_ONE 1
#define AzGl_ONE_MINUS_CONSTANT_ALPHA 0x8004
#define AzGl_ONE_MINUS_CONSTANT_COLOR 0x8002
#define AzGl_ONE_MINUS_DST_ALPHA 0x0305
#define AzGl_ONE_MINUS_DST_COLOR 0x0307
#define AzGl_ONE_MINUS_SRC1_ALPHA 0x88FB
#define AzGl_ONE_MINUS_SRC1_COLOR 0x88FA
#define AzGl_ONE_MINUS_SRC_ALPHA 0x0303
#define AzGl_ONE_MINUS_SRC_COLOR 0x0301
#define AzGl_OPERAND0_ALPHA 0x8598
#define AzGl_OPERAND0_RGB 0x8590
#define AzGl_OPERAND1_ALPHA 0x8599
#define AzGl_OPERAND1_RGB 0x8591
#define AzGl_OPERAND2_ALPHA 0x859A
#define AzGl_OPERAND2_RGB 0x8592
#define AzGl_OR 0x1507
#define AzGl_ORDER 0x0A01
#define AzGl_OR_INVERTED 0x150D
#define AzGl_OR_REVERSE 0x150B
#define AzGl_OUT_OF_MEMORY 0x0505
#define AzGl_OVERLAY_KHR 0x9296
#define AzGl_PACK_ALIGNMENT 0x0D05
#define AzGl_PACK_IMAGE_HEIGHT 0x806C
#define AzGl_PACK_LSB_FIRST 0x0D01
#define AzGl_PACK_ROW_LENGTH 0x0D02
#define AzGl_PACK_SKIP_IMAGES 0x806B
#define AzGl_PACK_SKIP_PIXELS 0x0D04
#define AzGl_PACK_SKIP_ROWS 0x0D03
#define AzGl_PACK_SWAP_BYTES 0x0D00
#define AzGl_PASS_THROUGH_TOKEN 0x0700
#define AzGl_PERSPECTIVE_CORRECTION_HINT 0x0C50
#define AzGl_PIXEL_MAP_A_TO_A 0x0C79
#define AzGl_PIXEL_MAP_A_TO_A_SIZE 0x0CB9
#define AzGl_PIXEL_MAP_B_TO_B 0x0C78
#define AzGl_PIXEL_MAP_B_TO_B_SIZE 0x0CB8
#define AzGl_PIXEL_MAP_G_TO_G 0x0C77
#define AzGl_PIXEL_MAP_G_TO_G_SIZE 0x0CB7
#define AzGl_PIXEL_MAP_I_TO_A 0x0C75
#define AzGl_PIXEL_MAP_I_TO_A_SIZE 0x0CB5
#define AzGl_PIXEL_MAP_I_TO_B 0x0C74
#define AzGl_PIXEL_MAP_I_TO_B_SIZE 0x0CB4
#define AzGl_PIXEL_MAP_I_TO_G 0x0C73
#define AzGl_PIXEL_MAP_I_TO_G_SIZE 0x0CB3
#define AzGl_PIXEL_MAP_I_TO_I 0x0C70
#define AzGl_PIXEL_MAP_I_TO_I_SIZE 0x0CB0
#define AzGl_PIXEL_MAP_I_TO_R 0x0C72
#define AzGl_PIXEL_MAP_I_TO_R_SIZE 0x0CB2
#define AzGl_PIXEL_MAP_R_TO_R 0x0C76
#define AzGl_PIXEL_MAP_R_TO_R_SIZE 0x0CB6
#define AzGl_PIXEL_MAP_S_TO_S 0x0C71
#define AzGl_PIXEL_MAP_S_TO_S_SIZE 0x0CB1
#define AzGl_PIXEL_MODE_BIT 0x00000020
#define AzGl_PIXEL_PACK_BUFFER 0x88EB
#define AzGl_PIXEL_PACK_BUFFER_BINDING 0x88ED
#define AzGl_PIXEL_UNPACK_BUFFER 0x88EC
#define AzGl_PIXEL_UNPACK_BUFFER_BINDING 0x88EF
#define AzGl_POINT 0x1B00
#define AzGl_POINTS 0x0000
#define AzGl_POINT_BIT 0x00000002
#define AzGl_POINT_DISTANCE_ATTENUATION 0x8129
#define AzGl_POINT_FADE_THRESHOLD_SIZE 0x8128
#define AzGl_POINT_SIZE 0x0B11
#define AzGl_POINT_SIZE_GRANULARITY 0x0B13
#define AzGl_POINT_SIZE_MAX 0x8127
#define AzGl_POINT_SIZE_MIN 0x8126
#define AzGl_POINT_SIZE_RANGE 0x0B12
#define AzGl_POINT_SMOOTH 0x0B10
#define AzGl_POINT_SMOOTH_HINT 0x0C51
#define AzGl_POINT_SPRITE 0x8861
#define AzGl_POINT_SPRITE_COORD_ORIGIN 0x8CA0
#define AzGl_POINT_TOKEN 0x0701
#define AzGl_POLYGON 0x0009
#define AzGl_POLYGON_BIT 0x00000008
#define AzGl_POLYGON_MODE 0x0B40
#define AzGl_POLYGON_OFFSET_FACTOR 0x8038
#define AzGl_POLYGON_OFFSET_FILL 0x8037
#define AzGl_POLYGON_OFFSET_LINE 0x2A02
#define AzGl_POLYGON_OFFSET_POINT 0x2A01
#define AzGl_POLYGON_OFFSET_UNITS 0x2A00
#define AzGl_POLYGON_SMOOTH 0x0B41
#define AzGl_POLYGON_SMOOTH_HINT 0x0C53
#define AzGl_POLYGON_STIPPLE 0x0B42
#define AzGl_POLYGON_STIPPLE_BIT 0x00000010
#define AzGl_POLYGON_TOKEN 0x0703
#define AzGl_POSITION 0x1203
#define AzGl_PREVIOUS 0x8578
#define AzGl_PRIMARY_COLOR 0x8577
#define AzGl_PRIMITIVES_GENERATED 0x8C87
#define AzGl_PRIMITIVE_RESTART 0x8F9D
#define AzGl_PRIMITIVE_RESTART_FIXED_INDEX 0x8D69
#define AzGl_PRIMITIVE_RESTART_INDEX 0x8F9E
#define AzGl_PROGRAM 0x82E2
#define AzGl_PROGRAM_BINARY_FORMATS 0x87FF
#define AzGl_PROGRAM_BINARY_LENGTH 0x8741
#define AzGl_PROGRAM_BINARY_RETRIEVABLE_HINT 0x8257
#define AzGl_PROGRAM_KHR 0x82E2
#define AzGl_PROGRAM_PIPELINE 0x82E4
#define AzGl_PROGRAM_PIPELINE_KHR 0x82E4
#define AzGl_PROGRAM_POINT_SIZE 0x8642
#define AzGl_PROJECTION 0x1701
#define AzGl_PROJECTION_MATRIX 0x0BA7
#define AzGl_PROJECTION_STACK_DEPTH 0x0BA4
#define AzGl_PROVOKING_VERTEX 0x8E4F
#define AzGl_PROXY_TEXTURE_1D 0x8063
#define AzGl_PROXY_TEXTURE_1D_ARRAY 0x8C19
#define AzGl_PROXY_TEXTURE_2D 0x8064
#define AzGl_PROXY_TEXTURE_2D_ARRAY 0x8C1B
#define AzGl_PROXY_TEXTURE_2D_MULTISAMPLE 0x9101
#define AzGl_PROXY_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9103
#define AzGl_PROXY_TEXTURE_3D 0x8070
#define AzGl_PROXY_TEXTURE_CUBE_MAP 0x851B
#define AzGl_PROXY_TEXTURE_RECTANGLE 0x84F7
#define AzGl_PROXY_TEXTURE_RECTANGLE_ARB 0x84F7
#define AzGl_Q 0x2003
#define AzGl_QUADRATIC_ATTENUATION 0x1209
#define AzGl_QUADS 0x0007
#define AzGl_QUADS_FOLLOW_PROVOKING_VERTEX_CONVENTION 0x8E4C
#define AzGl_QUAD_STRIP 0x0008
#define AzGl_QUERY 0x82E3
#define AzGl_QUERY_BY_REGION_NO_WAIT 0x8E16
#define AzGl_QUERY_BY_REGION_WAIT 0x8E15
#define AzGl_QUERY_COUNTER_BITS 0x8864
#define AzGl_QUERY_COUNTER_BITS_EXT 0x8864
#define AzGl_QUERY_KHR 0x82E3
#define AzGl_QUERY_NO_WAIT 0x8E14
#define AzGl_QUERY_RESULT 0x8866
#define AzGl_QUERY_RESULT_AVAILABLE 0x8867
#define AzGl_QUERY_RESULT_AVAILABLE_EXT 0x8867
#define AzGl_QUERY_RESULT_EXT 0x8866
#define AzGl_QUERY_WAIT 0x8E13
#define AzGl_R 0x2002
#define AzGl_R11F_G11F_B10F 0x8C3A
#define AzGl_R16 0x822A
#define AzGl_R16F 0x822D
#define AzGl_R16F_EXT 0x822D
#define AzGl_R16I 0x8233
#define AzGl_R16UI 0x8234
#define AzGl_R16_SNORM 0x8F98
#define AzGl_R32F 0x822E
#define AzGl_R32F_EXT 0x822E
#define AzGl_R32I 0x8235
#define AzGl_R32UI 0x8236
#define AzGl_R3_G3_B2 0x2A10
#define AzGl_R8 0x8229
#define AzGl_R8I 0x8231
#define AzGl_R8UI 0x8232
#define AzGl_R8_EXT 0x8229
#define AzGl_R8_SNORM 0x8F94
#define AzGl_RASTERIZER_DISCARD 0x8C89
#define AzGl_READ_BUFFER 0x0C02
#define AzGl_READ_FRAMEBUFFER 0x8CA8
#define AzGl_READ_FRAMEBUFFER_BINDING 0x8CAA
#define AzGl_READ_ONLY 0x88B8
#define AzGl_READ_WRITE 0x88BA
#define AzGl_RED 0x1903
#define AzGl_RED_BIAS 0x0D15
#define AzGl_RED_BITS 0x0D52
#define AzGl_RED_INTEGER 0x8D94
#define AzGl_RED_SCALE 0x0D14
#define AzGl_REFLECTION_MAP 0x8512
#define AzGl_RENDER 0x1C00
#define AzGl_RENDERBUFFER 0x8D41
#define AzGl_RENDERBUFFER_ALPHA_SIZE 0x8D53
#define AzGl_RENDERBUFFER_BINDING 0x8CA7
#define AzGl_RENDERBUFFER_BLUE_SIZE 0x8D52
#define AzGl_RENDERBUFFER_DEPTH_SIZE 0x8D54
#define AzGl_RENDERBUFFER_GREEN_SIZE 0x8D51
#define AzGl_RENDERBUFFER_HEIGHT 0x8D43
#define AzGl_RENDERBUFFER_INTERNAL_FORMAT 0x8D44
#define AzGl_RENDERBUFFER_RED_SIZE 0x8D50
#define AzGl_RENDERBUFFER_SAMPLES 0x8CAB
#define AzGl_RENDERBUFFER_STENCIL_SIZE 0x8D55
#define AzGl_RENDERBUFFER_WIDTH 0x8D42
#define AzGl_RENDERER 0x1F01
#define AzGl_RENDER_MODE 0x0C40
#define AzGl_REPEAT 0x2901
#define AzGl_REPLACE 0x1E01
#define AzGl_REQUIRED_TEXTURE_IMAGE_UNITS_OES 0x8D68
#define AzGl_RESCALE_NORMAL 0x803A
#define AzGl_RETURN 0x0102
#define AzGl_RG 0x8227
#define AzGl_RG16 0x822C
#define AzGl_RG16F 0x822F
#define AzGl_RG16F_EXT 0x822F
#define AzGl_RG16I 0x8239
#define AzGl_RG16UI 0x823A
#define AzGl_RG16_SNORM 0x8F99
#define AzGl_RG32F 0x8230
#define AzGl_RG32F_EXT 0x8230
#define AzGl_RG32I 0x823B
#define AzGl_RG32UI 0x823C
#define AzGl_RG8 0x822B
#define AzGl_RG8I 0x8237
#define AzGl_RG8UI 0x8238
#define AzGl_RG8_EXT 0x822B
#define AzGl_RG8_SNORM 0x8F95
#define AzGl_RGB 0x1907
#define AzGl_RGB10 0x8052
#define AzGl_RGB10_A2 0x8059
#define AzGl_RGB10_A2UI 0x906F
#define AzGl_RGB10_A2_EXT 0x8059
#define AzGl_RGB10_EXT 0x8052
#define AzGl_RGB12 0x8053
#define AzGl_RGB16 0x8054
#define AzGl_RGB16F 0x881B
#define AzGl_RGB16F_EXT 0x881B
#define AzGl_RGB16I 0x8D89
#define AzGl_RGB16UI 0x8D77
#define AzGl_RGB16_SNORM 0x8F9A
#define AzGl_RGB32F 0x8815
#define AzGl_RGB32F_EXT 0x8815
#define AzGl_RGB32I 0x8D83
#define AzGl_RGB32UI 0x8D71
#define AzGl_RGB4 0x804F
#define AzGl_RGB5 0x8050
#define AzGl_RGB565 0x8D62
#define AzGl_RGB5_A1 0x8057
#define AzGl_RGB8 0x8051
#define AzGl_RGB8I 0x8D8F
#define AzGl_RGB8UI 0x8D7D
#define AzGl_RGB8_SNORM 0x8F96
#define AzGl_RGB9_E5 0x8C3D
#define AzGl_RGBA 0x1908
#define AzGl_RGBA12 0x805A
#define AzGl_RGBA16 0x805B
#define AzGl_RGBA16F 0x881A
#define AzGl_RGBA16F_EXT 0x881A
#define AzGl_RGBA16I 0x8D88
#define AzGl_RGBA16UI 0x8D76
#define AzGl_RGBA16_SNORM 0x8F9B
#define AzGl_RGBA2 0x8055
#define AzGl_RGBA32F 0x8814
#define AzGl_RGBA32F_EXT 0x8814
#define AzGl_RGBA32I 0x8D82
#define AzGl_RGBA32UI 0x8D70
#define AzGl_RGBA4 0x8056
#define AzGl_RGBA8 0x8058
#define AzGl_RGBA8I 0x8D8E
#define AzGl_RGBA8UI 0x8D7C
#define AzGl_RGBA8_SNORM 0x8F97
#define AzGl_RGBA_INTEGER 0x8D99
#define AzGl_RGBA_MODE 0x0C31
#define AzGl_RGB_INTEGER 0x8D98
#define AzGl_RGB_SCALE 0x8573
#define AzGl_RG_INTEGER 0x8228
#define AzGl_RIGHT 0x0407
#define AzGl_S 0x2000
#define AzGl_SAMPLER 0x82E6
#define AzGl_SAMPLER_1D 0x8B5D
#define AzGl_SAMPLER_1D_ARRAY 0x8DC0
#define AzGl_SAMPLER_1D_ARRAY_SHADOW 0x8DC3
#define AzGl_SAMPLER_1D_SHADOW 0x8B61
#define AzGl_SAMPLER_2D 0x8B5E
#define AzGl_SAMPLER_2D_ARRAY 0x8DC1
#define AzGl_SAMPLER_2D_ARRAY_SHADOW 0x8DC4
#define AzGl_SAMPLER_2D_MULTISAMPLE 0x9108
#define AzGl_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910B
#define AzGl_SAMPLER_2D_RECT 0x8B63
#define AzGl_SAMPLER_2D_RECT_SHADOW 0x8B64
#define AzGl_SAMPLER_2D_SHADOW 0x8B62
#define AzGl_SAMPLER_3D 0x8B5F
#define AzGl_SAMPLER_BINDING 0x8919
#define AzGl_SAMPLER_BUFFER 0x8DC2
#define AzGl_SAMPLER_CUBE 0x8B60
#define AzGl_SAMPLER_CUBE_SHADOW 0x8DC5
#define AzGl_SAMPLER_EXTERNAL_OES 0x8D66
#define AzGl_SAMPLER_KHR 0x82E6
#define AzGl_SAMPLES 0x80A9
#define AzGl_SAMPLES_PASSED 0x8914
#define AzGl_SAMPLE_ALPHA_TO_COVERAGE 0x809E
#define AzGl_SAMPLE_ALPHA_TO_ONE 0x809F
#define AzGl_SAMPLE_BUFFERS 0x80A8
#define AzGl_SAMPLE_COVERAGE 0x80A0
#define AzGl_SAMPLE_COVERAGE_INVERT 0x80AB
#define AzGl_SAMPLE_COVERAGE_VALUE 0x80AA
#define AzGl_SAMPLE_MASK 0x8E51
#define AzGl_SAMPLE_MASK_VALUE 0x8E52
#define AzGl_SAMPLE_POSITION 0x8E50
#define AzGl_SCISSOR_BIT 0x00080000
#define AzGl_SCISSOR_BOX 0x0C10
#define AzGl_SCISSOR_TEST 0x0C11
#define AzGl_SCREEN_KHR 0x9295
#define AzGl_SECONDARY_COLOR_ARRAY 0x845E
#define AzGl_SECONDARY_COLOR_ARRAY_BUFFER_BINDING 0x889C
#define AzGl_SECONDARY_COLOR_ARRAY_POINTER 0x845D
#define AzGl_SECONDARY_COLOR_ARRAY_SIZE 0x845A
#define AzGl_SECONDARY_COLOR_ARRAY_STRIDE 0x845C
#define AzGl_SECONDARY_COLOR_ARRAY_TYPE 0x845B
#define AzGl_SELECT 0x1C02
#define AzGl_SELECTION_BUFFER_POINTER 0x0DF3
#define AzGl_SELECTION_BUFFER_SIZE 0x0DF4
#define AzGl_SEPARATE_ATTRIBS 0x8C8D
#define AzGl_SEPARATE_SPECULAR_COLOR 0x81FA
#define AzGl_SET 0x150F
#define AzGl_SHADER 0x82E1
#define AzGl_SHADER_BINARY_FORMATS 0x8DF8
#define AzGl_SHADER_COMPILER 0x8DFA
#define AzGl_SHADER_KHR 0x82E1
#define AzGl_SHADER_PIXEL_LOCAL_STORAGE_EXT 0x8F64
#define AzGl_SHADER_SOURCE_LENGTH 0x8B88
#define AzGl_SHADER_TYPE 0x8B4F
#define AzGl_SHADE_MODEL 0x0B54
#define AzGl_SHADING_LANGUAGE_VERSION 0x8B8C
#define AzGl_SHININESS 0x1601
#define AzGl_SHORT 0x1402
#define AzGl_SIGNALED 0x9119
#define AzGl_SIGNED_NORMALIZED 0x8F9C
#define AzGl_SINGLE_COLOR 0x81F9
#define AzGl_SLUMINANCE 0x8C46
#define AzGl_SLUMINANCE8 0x8C47
#define AzGl_SLUMINANCE8_ALPHA8 0x8C45
#define AzGl_SLUMINANCE_ALPHA 0x8C44
#define AzGl_SMOOTH 0x1D01
#define AzGl_SMOOTH_LINE_WIDTH_GRANULARITY 0x0B23
#define AzGl_SMOOTH_LINE_WIDTH_RANGE 0x0B22
#define AzGl_SMOOTH_POINT_SIZE_GRANULARITY 0x0B13
#define AzGl_SMOOTH_POINT_SIZE_RANGE 0x0B12
#define AzGl_SOFTLIGHT_KHR 0x929C
#define AzGl_SOURCE0_ALPHA 0x8588
#define AzGl_SOURCE0_RGB 0x8580
#define AzGl_SOURCE1_ALPHA 0x8589
#define AzGl_SOURCE1_RGB 0x8581
#define AzGl_SOURCE2_ALPHA 0x858A
#define AzGl_SOURCE2_RGB 0x8582
#define AzGl_SPECULAR 0x1202
#define AzGl_SPHERE_MAP 0x2402
#define AzGl_SPOT_CUTOFF 0x1206
#define AzGl_SPOT_DIRECTION 0x1204
#define AzGl_SPOT_EXPONENT 0x1205
#define AzGl_SRC0_ALPHA 0x8588
#define AzGl_SRC0_RGB 0x8580
#define AzGl_SRC1_ALPHA 0x8589
#define AzGl_SRC1_COLOR 0x88F9
#define AzGl_SRC1_RGB 0x8581
#define AzGl_SRC2_ALPHA 0x858A
#define AzGl_SRC2_RGB 0x8582
#define AzGl_SRC_ALPHA 0x0302
#define AzGl_SRC_ALPHA_SATURATE 0x0308
#define AzGl_SRC_COLOR 0x0300
#define AzGl_SRGB 0x8C40
#define AzGl_SRGB8 0x8C41
#define AzGl_SRGB8_ALPHA8 0x8C43
#define AzGl_SRGB_ALPHA 0x8C42
#define AzGl_STACK_OVERFLOW 0x0503
#define AzGl_STACK_OVERFLOW_KHR 0x0503
#define AzGl_STACK_UNDERFLOW 0x0504
#define AzGl_STACK_UNDERFLOW_KHR 0x0504
#define AzGl_STATIC_COPY 0x88E6
#define AzGl_STATIC_DRAW 0x88E4
#define AzGl_STATIC_READ 0x88E5
#define AzGl_STENCIL 0x1802
#define AzGl_STENCIL_ATTACHMENT 0x8D20
#define AzGl_STENCIL_BACK_FAIL 0x8801
#define AzGl_STENCIL_BACK_FUNC 0x8800
#define AzGl_STENCIL_BACK_PASS_DEPTH_FAIL 0x8802
#define AzGl_STENCIL_BACK_PASS_DEPTH_PASS 0x8803
#define AzGl_STENCIL_BACK_REF 0x8CA3
#define AzGl_STENCIL_BACK_VALUE_MASK 0x8CA4
#define AzGl_STENCIL_BACK_WRITEMASK 0x8CA5
#define AzGl_STENCIL_BITS 0x0D57
#define AzGl_STENCIL_BUFFER_BIT 0x00000400
#define AzGl_STENCIL_CLEAR_VALUE 0x0B91
#define AzGl_STENCIL_FAIL 0x0B94
#define AzGl_STENCIL_FUNC 0x0B92
#define AzGl_STENCIL_INDEX 0x1901
#define AzGl_STENCIL_INDEX1 0x8D46
#define AzGl_STENCIL_INDEX16 0x8D49
#define AzGl_STENCIL_INDEX4 0x8D47
#define AzGl_STENCIL_INDEX8 0x8D48
#define AzGl_STENCIL_PASS_DEPTH_FAIL 0x0B95
#define AzGl_STENCIL_PASS_DEPTH_PASS 0x0B96
#define AzGl_STENCIL_REF 0x0B97
#define AzGl_STENCIL_TEST 0x0B90
#define AzGl_STENCIL_VALUE_MASK 0x0B93
#define AzGl_STENCIL_WRITEMASK 0x0B98
#define AzGl_STEREO 0x0C33
#define AzGl_STORAGE_CACHED_APPLE 0x85BE
#define AzGl_STORAGE_PRIVATE_APPLE 0x85BD
#define AzGl_STORAGE_SHARED_APPLE 0x85BF
#define AzGl_STREAM_COPY 0x88E2
#define AzGl_STREAM_DRAW 0x88E0
#define AzGl_STREAM_READ 0x88E1
#define AzGl_SUBPIXEL_BITS 0x0D50
#define AzGl_SUBTRACT 0x84E7
#define AzGl_SYNC_CONDITION 0x9113
#define AzGl_SYNC_FENCE 0x9116
#define AzGl_SYNC_FLAGS 0x9115
#define AzGl_SYNC_FLUSH_COMMANDS_BIT 0x00000001
#define AzGl_SYNC_GPU_COMMANDS_COMPLETE 0x9117
#define AzGl_SYNC_STATUS 0x9114
#define AzGl_T 0x2001
#define AzGl_T2F_C3F_V3F 0x2A2A
#define AzGl_T2F_C4F_N3F_V3F 0x2A2C
#define AzGl_T2F_C4UB_V3F 0x2A29
#define AzGl_T2F_N3F_V3F 0x2A2B
#define AzGl_T2F_V3F 0x2A27
#define AzGl_T4F_C4F_N3F_V4F 0x2A2D
#define AzGl_T4F_V4F 0x2A28
#define AzGl_TEXTURE 0x1702
#define AzGl_TEXTURE0 0x84C0
#define AzGl_TEXTURE1 0x84C1
#define AzGl_TEXTURE10 0x84CA
#define AzGl_TEXTURE11 0x84CB
#define AzGl_TEXTURE12 0x84CC
#define AzGl_TEXTURE13 0x84CD
#define AzGl_TEXTURE14 0x84CE
#define AzGl_TEXTURE15 0x84CF
#define AzGl_TEXTURE16 0x84D0
#define AzGl_TEXTURE17 0x84D1
#define AzGl_TEXTURE18 0x84D2
#define AzGl_TEXTURE19 0x84D3
#define AzGl_TEXTURE2 0x84C2
#define AzGl_TEXTURE20 0x84D4
#define AzGl_TEXTURE21 0x84D5
#define AzGl_TEXTURE22 0x84D6
#define AzGl_TEXTURE23 0x84D7
#define AzGl_TEXTURE24 0x84D8
#define AzGl_TEXTURE25 0x84D9
#define AzGl_TEXTURE26 0x84DA
#define AzGl_TEXTURE27 0x84DB
#define AzGl_TEXTURE28 0x84DC
#define AzGl_TEXTURE29 0x84DD
#define AzGl_TEXTURE3 0x84C3
#define AzGl_TEXTURE30 0x84DE
#define AzGl_TEXTURE31 0x84DF
#define AzGl_TEXTURE4 0x84C4
#define AzGl_TEXTURE5 0x84C5
#define AzGl_TEXTURE6 0x84C6
#define AzGl_TEXTURE7 0x84C7
#define AzGl_TEXTURE8 0x84C8
#define AzGl_TEXTURE9 0x84C9
#define AzGl_TEXTURE_1D 0x0DE0
#define AzGl_TEXTURE_1D_ARRAY 0x8C18
#define AzGl_TEXTURE_2D 0x0DE1
#define AzGl_TEXTURE_2D_ARRAY 0x8C1A
#define AzGl_TEXTURE_2D_MULTISAMPLE 0x9100
#define AzGl_TEXTURE_2D_MULTISAMPLE_ARRAY 0x9102
#define AzGl_TEXTURE_3D 0x806F
#define AzGl_TEXTURE_ALPHA_SIZE 0x805F
#define AzGl_TEXTURE_ALPHA_TYPE 0x8C13
#define AzGl_TEXTURE_BASE_LEVEL 0x813C
#define AzGl_TEXTURE_BINDING_1D 0x8068
#define AzGl_TEXTURE_BINDING_1D_ARRAY 0x8C1C
#define AzGl_TEXTURE_BINDING_2D 0x8069
#define AzGl_TEXTURE_BINDING_2D_ARRAY 0x8C1D
#define AzGl_TEXTURE_BINDING_2D_MULTISAMPLE 0x9104
#define AzGl_TEXTURE_BINDING_2D_MULTISAMPLE_ARRAY 0x9105
#define AzGl_TEXTURE_BINDING_3D 0x806A
#define AzGl_TEXTURE_BINDING_BUFFER 0x8C2C
#define AzGl_TEXTURE_BINDING_CUBE_MAP 0x8514
#define AzGl_TEXTURE_BINDING_EXTERNAL_OES 0x8D67
#define AzGl_TEXTURE_BINDING_RECTANGLE 0x84F6
#define AzGl_TEXTURE_BINDING_RECTANGLE_ARB 0x84F6
#define AzGl_TEXTURE_BIT 0x00040000
#define AzGl_TEXTURE_BLUE_SIZE 0x805E
#define AzGl_TEXTURE_BLUE_TYPE 0x8C12
#define AzGl_TEXTURE_BORDER 0x1005
#define AzGl_TEXTURE_BORDER_COLOR 0x1004
#define AzGl_TEXTURE_BUFFER 0x8C2A
#define AzGl_TEXTURE_BUFFER_DATA_STORE_BINDING 0x8C2D
#define AzGl_TEXTURE_COMPARE_FUNC 0x884D
#define AzGl_TEXTURE_COMPARE_MODE 0x884C
#define AzGl_TEXTURE_COMPONENTS 0x1003
#define AzGl_TEXTURE_COMPRESSED 0x86A1
#define AzGl_TEXTURE_COMPRESSED_IMAGE_SIZE 0x86A0
#define AzGl_TEXTURE_COMPRESSION_HINT 0x84EF
#define AzGl_TEXTURE_COORD_ARRAY 0x8078
#define AzGl_TEXTURE_COORD_ARRAY_BUFFER_BINDING 0x889A
#define AzGl_TEXTURE_COORD_ARRAY_POINTER 0x8092
#define AzGl_TEXTURE_COORD_ARRAY_SIZE 0x8088
#define AzGl_TEXTURE_COORD_ARRAY_STRIDE 0x808A
#define AzGl_TEXTURE_COORD_ARRAY_TYPE 0x8089
#define AzGl_TEXTURE_CUBE_MAP 0x8513
#define AzGl_TEXTURE_CUBE_MAP_NEGATIVE_X 0x8516
#define AzGl_TEXTURE_CUBE_MAP_NEGATIVE_Y 0x8518
#define AzGl_TEXTURE_CUBE_MAP_NEGATIVE_Z 0x851A
#define AzGl_TEXTURE_CUBE_MAP_POSITIVE_X 0x8515
#define AzGl_TEXTURE_CUBE_MAP_POSITIVE_Y 0x8517
#define AzGl_TEXTURE_CUBE_MAP_POSITIVE_Z 0x8519
#define AzGl_TEXTURE_CUBE_MAP_SEAMLESS 0x884F
#define AzGl_TEXTURE_DEPTH 0x8071
#define AzGl_TEXTURE_DEPTH_SIZE 0x884A
#define AzGl_TEXTURE_DEPTH_TYPE 0x8C16
#define AzGl_TEXTURE_ENV 0x2300
#define AzGl_TEXTURE_ENV_COLOR 0x2201
#define AzGl_TEXTURE_ENV_MODE 0x2200
#define AzGl_TEXTURE_EXTERNAL_OES 0x8D65
#define AzGl_TEXTURE_FILTER_CONTROL 0x8500
#define AzGl_TEXTURE_FIXED_SAMPLE_LOCATIONS 0x9107
#define AzGl_TEXTURE_GEN_MODE 0x2500
#define AzGl_TEXTURE_GEN_Q 0x0C63
#define AzGl_TEXTURE_GEN_R 0x0C62
#define AzGl_TEXTURE_GEN_S 0x0C60
#define AzGl_TEXTURE_GEN_T 0x0C61
#define AzGl_TEXTURE_GREEN_SIZE 0x805D
#define AzGl_TEXTURE_GREEN_TYPE 0x8C11
#define AzGl_TEXTURE_HEIGHT 0x1001
#define AzGl_TEXTURE_IMMUTABLE_FORMAT 0x912F
#define AzGl_TEXTURE_IMMUTABLE_FORMAT_EXT 0x912F
#define AzGl_TEXTURE_IMMUTABLE_LEVELS 0x82DF
#define AzGl_TEXTURE_INTENSITY_SIZE 0x8061
#define AzGl_TEXTURE_INTENSITY_TYPE 0x8C15
#define AzGl_TEXTURE_INTERNAL_FORMAT 0x1003
#define AzGl_TEXTURE_LOD_BIAS 0x8501
#define AzGl_TEXTURE_LUMINANCE_SIZE 0x8060
#define AzGl_TEXTURE_LUMINANCE_TYPE 0x8C14
#define AzGl_TEXTURE_MAG_FILTER 0x2800
#define AzGl_TEXTURE_MATRIX 0x0BA8
#define AzGl_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define AzGl_TEXTURE_MAX_LEVEL 0x813D
#define AzGl_TEXTURE_MAX_LOD 0x813B
#define AzGl_TEXTURE_MIN_FILTER 0x2801
#define AzGl_TEXTURE_MIN_LOD 0x813A
#define AzGl_TEXTURE_PRIORITY 0x8066
#define AzGl_TEXTURE_RANGE_LENGTH_APPLE 0x85B7
#define AzGl_TEXTURE_RANGE_POINTER_APPLE 0x85B8
#define AzGl_TEXTURE_RECTANGLE 0x84F5
#define AzGl_TEXTURE_RECTANGLE_ARB 0x84F5
#define AzGl_TEXTURE_RED_SIZE 0x805C
#define AzGl_TEXTURE_RED_TYPE 0x8C10
#define AzGl_TEXTURE_RESIDENT 0x8067
#define AzGl_TEXTURE_SAMPLES 0x9106
#define AzGl_TEXTURE_SHARED_SIZE 0x8C3F
#define AzGl_TEXTURE_STACK_DEPTH 0x0BA5
#define AzGl_TEXTURE_STENCIL_SIZE 0x88F1
#define AzGl_TEXTURE_STORAGE_HINT_APPLE 0x85BC
#define AzGl_TEXTURE_SWIZZLE_A 0x8E45
#define AzGl_TEXTURE_SWIZZLE_B 0x8E44
#define AzGl_TEXTURE_SWIZZLE_G 0x8E43
#define AzGl_TEXTURE_SWIZZLE_R 0x8E42
#define AzGl_TEXTURE_SWIZZLE_RGBA 0x8E46
#define AzGl_TEXTURE_USAGE_ANGLE 0x93A2
#define AzGl_TEXTURE_WIDTH 0x1000
#define AzGl_TEXTURE_WRAP_R 0x8072
#define AzGl_TEXTURE_WRAP_S 0x2802
#define AzGl_TEXTURE_WRAP_T 0x2803
#define AzGl_TIMEOUT_EXPIRED 0x911B
#define AzGl_TIMEOUT_IGNORED 0xFFFFFFFFFFFFFFFF
#define AzGl_TIMESTAMP 0x8E28
#define AzGl_TIMESTAMP_EXT 0x8E28
#define AzGl_TIME_ELAPSED 0x88BF
#define AzGl_TIME_ELAPSED_EXT 0x88BF
#define AzGl_TRANSFORM_BIT 0x00001000
#define AzGl_TRANSFORM_FEEDBACK 0x8E22
#define AzGl_TRANSFORM_FEEDBACK_ACTIVE 0x8E24
#define AzGl_TRANSFORM_FEEDBACK_BINDING 0x8E25
#define AzGl_TRANSFORM_FEEDBACK_BUFFER 0x8C8E
#define AzGl_TRANSFORM_FEEDBACK_BUFFER_BINDING 0x8C8F
#define AzGl_TRANSFORM_FEEDBACK_BUFFER_MODE 0x8C7F
#define AzGl_TRANSFORM_FEEDBACK_BUFFER_SIZE 0x8C85
#define AzGl_TRANSFORM_FEEDBACK_BUFFER_START 0x8C84
#define AzGl_TRANSFORM_FEEDBACK_PAUSED 0x8E23
#define AzGl_TRANSFORM_FEEDBACK_PRIMITIVES_WRITTEN 0x8C88
#define AzGl_TRANSFORM_FEEDBACK_VARYINGS 0x8C83
#define AzGl_TRANSFORM_FEEDBACK_VARYING_MAX_LENGTH 0x8C76
#define AzGl_TRANSPOSE_COLOR_MATRIX 0x84E6
#define AzGl_TRANSPOSE_MODELVIEW_MATRIX 0x84E3
#define AzGl_TRANSPOSE_PROJECTION_MATRIX 0x84E4
#define AzGl_TRANSPOSE_TEXTURE_MATRIX 0x84E5
#define AzGl_TRIANGLES 0x0004
#define AzGl_TRIANGLES_ADJACENCY 0x000C
#define AzGl_TRIANGLE_FAN 0x0006
#define AzGl_TRIANGLE_STRIP 0x0005
#define AzGl_TRIANGLE_STRIP_ADJACENCY 0x000D
#define AzGl_TRUE 1
#define AzGl_UNIFORM_ARRAY_STRIDE 0x8A3C
#define AzGl_UNIFORM_BLOCK_ACTIVE_UNIFORMS 0x8A42
#define AzGl_UNIFORM_BLOCK_ACTIVE_UNIFORM_INDICES 0x8A43
#define AzGl_UNIFORM_BLOCK_BINDING 0x8A3F
#define AzGl_UNIFORM_BLOCK_DATA_SIZE 0x8A40
#define AzGl_UNIFORM_BLOCK_INDEX 0x8A3A
#define AzGl_UNIFORM_BLOCK_NAME_LENGTH 0x8A41
#define AzGl_UNIFORM_BLOCK_REFERENCED_BY_FRAGMENT_SHADER 0x8A46
#define AzGl_UNIFORM_BLOCK_REFERENCED_BY_GEOMETRY_SHADER 0x8A45
#define AzGl_UNIFORM_BLOCK_REFERENCED_BY_VERTEX_SHADER 0x8A44
#define AzGl_UNIFORM_BUFFER 0x8A11
#define AzGl_UNIFORM_BUFFER_BINDING 0x8A28
#define AzGl_UNIFORM_BUFFER_OFFSET_ALIGNMENT 0x8A34
#define AzGl_UNIFORM_BUFFER_SIZE 0x8A2A
#define AzGl_UNIFORM_BUFFER_START 0x8A29
#define AzGl_UNIFORM_IS_ROW_MAJOR 0x8A3E
#define AzGl_UNIFORM_MATRIX_STRIDE 0x8A3D
#define AzGl_UNIFORM_NAME_LENGTH 0x8A39
#define AzGl_UNIFORM_OFFSET 0x8A3B
#define AzGl_UNIFORM_SIZE 0x8A38
#define AzGl_UNIFORM_TYPE 0x8A37
#define AzGl_UNPACK_ALIGNMENT 0x0CF5
#define AzGl_UNPACK_CLIENT_STORAGE_APPLE 0x85B2
#define AzGl_UNPACK_IMAGE_HEIGHT 0x806E
#define AzGl_UNPACK_LSB_FIRST 0x0CF1
#define AzGl_UNPACK_ROW_LENGTH 0x0CF2
#define AzGl_UNPACK_SKIP_IMAGES 0x806D
#define AzGl_UNPACK_SKIP_PIXELS 0x0CF4
#define AzGl_UNPACK_SKIP_ROWS 0x0CF3
#define AzGl_UNPACK_SWAP_BYTES 0x0CF0
#define AzGl_UNSIGNALED 0x9118
#define AzGl_UNSIGNED_BYTE 0x1401
#define AzGl_UNSIGNED_BYTE_2_3_3_REV 0x8362
#define AzGl_UNSIGNED_BYTE_3_3_2 0x8032
#define AzGl_UNSIGNED_INT 0x1405
#define AzGl_UNSIGNED_INT_10F_11F_11F_REV 0x8C3B
#define AzGl_UNSIGNED_INT_10_10_10_2 0x8036
#define AzGl_UNSIGNED_INT_24_8 0x84FA
#define AzGl_UNSIGNED_INT_2_10_10_10_REV 0x8368
#define AzGl_UNSIGNED_INT_5_9_9_9_REV 0x8C3E
#define AzGl_UNSIGNED_INT_8_8_8_8 0x8035
#define AzGl_UNSIGNED_INT_8_8_8_8_REV 0x8367
#define AzGl_UNSIGNED_INT_SAMPLER_1D 0x8DD1
#define AzGl_UNSIGNED_INT_SAMPLER_1D_ARRAY 0x8DD6
#define AzGl_UNSIGNED_INT_SAMPLER_2D 0x8DD2
#define AzGl_UNSIGNED_INT_SAMPLER_2D_ARRAY 0x8DD7
#define AzGl_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE 0x910A
#define AzGl_UNSIGNED_INT_SAMPLER_2D_MULTISAMPLE_ARRAY 0x910D
#define AzGl_UNSIGNED_INT_SAMPLER_2D_RECT 0x8DD5
#define AzGl_UNSIGNED_INT_SAMPLER_3D 0x8DD3
#define AzGl_UNSIGNED_INT_SAMPLER_BUFFER 0x8DD8
#define AzGl_UNSIGNED_INT_SAMPLER_CUBE 0x8DD4
#define AzGl_UNSIGNED_INT_VEC2 0x8DC6
#define AzGl_UNSIGNED_INT_VEC3 0x8DC7
#define AzGl_UNSIGNED_INT_VEC4 0x8DC8
#define AzGl_UNSIGNED_NORMALIZED 0x8C17
#define AzGl_UNSIGNED_SHORT 0x1403
#define AzGl_UNSIGNED_SHORT_1_5_5_5_REV 0x8366
#define AzGl_UNSIGNED_SHORT_4_4_4_4 0x8033
#define AzGl_UNSIGNED_SHORT_4_4_4_4_REV 0x8365
#define AzGl_UNSIGNED_SHORT_5_5_5_1 0x8034
#define AzGl_UNSIGNED_SHORT_5_6_5 0x8363
#define AzGl_UNSIGNED_SHORT_5_6_5_REV 0x8364
#define AzGl_UPPER_LEFT 0x8CA2
#define AzGl_V2F 0x2A20
#define AzGl_V3F 0x2A21
#define AzGl_VALIDATE_STATUS 0x8B83
#define AzGl_VENDOR 0x1F00
#define AzGl_VERSION 0x1F02
#define AzGl_VERTEX_ARRAY 0x8074
#define AzGl_VERTEX_ARRAY_BINDING 0x85B5
#define AzGl_VERTEX_ARRAY_BINDING_APPLE 0x85B5
#define AzGl_VERTEX_ARRAY_BUFFER_BINDING 0x8896
#define AzGl_VERTEX_ARRAY_KHR 0x8074
#define AzGl_VERTEX_ARRAY_POINTER 0x808E
#define AzGl_VERTEX_ARRAY_SIZE 0x807A
#define AzGl_VERTEX_ARRAY_STRIDE 0x807C
#define AzGl_VERTEX_ARRAY_TYPE 0x807B
#define AzGl_VERTEX_ATTRIB_ARRAY_BUFFER_BINDING 0x889F
#define AzGl_VERTEX_ATTRIB_ARRAY_DIVISOR 0x88FE
#define AzGl_VERTEX_ATTRIB_ARRAY_ENABLED 0x8622
#define AzGl_VERTEX_ATTRIB_ARRAY_INTEGER 0x88FD
#define AzGl_VERTEX_ATTRIB_ARRAY_NORMALIZED 0x886A
#define AzGl_VERTEX_ATTRIB_ARRAY_POINTER 0x8645
#define AzGl_VERTEX_ATTRIB_ARRAY_SIZE 0x8623
#define AzGl_VERTEX_ATTRIB_ARRAY_STRIDE 0x8624
#define AzGl_VERTEX_ATTRIB_ARRAY_TYPE 0x8625
#define AzGl_VERTEX_PROGRAM_POINT_SIZE 0x8642
#define AzGl_VERTEX_PROGRAM_TWO_SIDE 0x8643
#define AzGl_VERTEX_SHADER 0x8B31
#define AzGl_VIEWPORT 0x0BA2
#define AzGl_VIEWPORT_BIT 0x00000800
#define AzGl_WAIT_FAILED 0x911D
#define AzGl_WEIGHT_ARRAY_BUFFER_BINDING 0x889E
#define AzGl_WRITE_ONLY 0x88B9
#define AzGl_XOR 0x1506
#define AzGl_ZERO 0
#define AzGl_ZOOM_X 0x0D16
#define AzGl_ZOOM_Y 0x0D17

bool AzRawWindowHandle_matchRefIOS(const AzRawWindowHandle* value, const AzIOSHandle** restrict out) {
    const AzRawWindowHandleVariant_IOS* casted = (const AzRawWindowHandleVariant_IOS*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_IOS;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutIOS(AzRawWindowHandle* restrict value, AzIOSHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_IOS* restrict casted = (AzRawWindowHandleVariant_IOS* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_IOS;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchRefMacOS(const AzRawWindowHandle* value, const AzMacOSHandle** restrict out) {
    const AzRawWindowHandleVariant_MacOS* casted = (const AzRawWindowHandleVariant_MacOS*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_MacOS;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutMacOS(AzRawWindowHandle* restrict value, AzMacOSHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_MacOS* restrict casted = (AzRawWindowHandleVariant_MacOS* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_MacOS;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchRefXlib(const AzRawWindowHandle* value, const AzXlibHandle** restrict out) {
    const AzRawWindowHandleVariant_Xlib* casted = (const AzRawWindowHandleVariant_Xlib*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Xlib;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutXlib(AzRawWindowHandle* restrict value, AzXlibHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_Xlib* restrict casted = (AzRawWindowHandleVariant_Xlib* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Xlib;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchRefXcb(const AzRawWindowHandle* value, const AzXcbHandle** restrict out) {
    const AzRawWindowHandleVariant_Xcb* casted = (const AzRawWindowHandleVariant_Xcb*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Xcb;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutXcb(AzRawWindowHandle* restrict value, AzXcbHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_Xcb* restrict casted = (AzRawWindowHandleVariant_Xcb* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Xcb;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchRefWayland(const AzRawWindowHandle* value, const AzWaylandHandle** restrict out) {
    const AzRawWindowHandleVariant_Wayland* casted = (const AzRawWindowHandleVariant_Wayland*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Wayland;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutWayland(AzRawWindowHandle* restrict value, AzWaylandHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_Wayland* restrict casted = (AzRawWindowHandleVariant_Wayland* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Wayland;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchRefWindows(const AzRawWindowHandle* value, const AzWindowsHandle** restrict out) {
    const AzRawWindowHandleVariant_Windows* casted = (const AzRawWindowHandleVariant_Windows*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Windows;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutWindows(AzRawWindowHandle* restrict value, AzWindowsHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_Windows* restrict casted = (AzRawWindowHandleVariant_Windows* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Windows;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchRefWeb(const AzRawWindowHandle* value, const AzWebHandle** restrict out) {
    const AzRawWindowHandleVariant_Web* casted = (const AzRawWindowHandleVariant_Web*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Web;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutWeb(AzRawWindowHandle* restrict value, AzWebHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_Web* restrict casted = (AzRawWindowHandleVariant_Web* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Web;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchRefAndroid(const AzRawWindowHandle* value, const AzAndroidHandle** restrict out) {
    const AzRawWindowHandleVariant_Android* casted = (const AzRawWindowHandleVariant_Android*)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Android;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawWindowHandle_matchMutAndroid(AzRawWindowHandle* restrict value, AzAndroidHandle* restrict * restrict out) {
    AzRawWindowHandleVariant_Android* restrict casted = (AzRawWindowHandleVariant_Android* restrict)value;
    bool valid = casted->tag == AzRawWindowHandleTag_Android;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzWindowIcon_matchRefSmall(const AzWindowIcon* value, const AzSmallWindowIconBytes** restrict out) {
    const AzWindowIconVariant_Small* casted = (const AzWindowIconVariant_Small*)value;
    bool valid = casted->tag == AzWindowIconTag_Small;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzWindowIcon_matchMutSmall(AzWindowIcon* restrict value, AzSmallWindowIconBytes* restrict * restrict out) {
    AzWindowIconVariant_Small* restrict casted = (AzWindowIconVariant_Small* restrict)value;
    bool valid = casted->tag == AzWindowIconTag_Small;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzWindowIcon_matchRefLarge(const AzWindowIcon* value, const AzLargeWindowIconBytes** restrict out) {
    const AzWindowIconVariant_Large* casted = (const AzWindowIconVariant_Large*)value;
    bool valid = casted->tag == AzWindowIconTag_Large;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzWindowIcon_matchMutLarge(AzWindowIcon* restrict value, AzLargeWindowIconBytes* restrict * restrict out) {
    AzWindowIconVariant_Large* restrict casted = (AzWindowIconVariant_Large* restrict)value;
    bool valid = casted->tag == AzWindowIconTag_Large;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAcceleratorKey_matchRefKey(const AzAcceleratorKey* value, const AzVirtualKeyCode** restrict out) {
    const AzAcceleratorKeyVariant_Key* casted = (const AzAcceleratorKeyVariant_Key*)value;
    bool valid = casted->tag == AzAcceleratorKeyTag_Key;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAcceleratorKey_matchMutKey(AzAcceleratorKey* restrict value, AzVirtualKeyCode* restrict * restrict out) {
    AzAcceleratorKeyVariant_Key* restrict casted = (AzAcceleratorKeyVariant_Key* restrict)value;
    bool valid = casted->tag == AzAcceleratorKeyTag_Key;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCursorPosition_matchRefInWindow(const AzCursorPosition* value, const AzLogicalPosition** restrict out) {
    const AzCursorPositionVariant_InWindow* casted = (const AzCursorPositionVariant_InWindow*)value;
    bool valid = casted->tag == AzCursorPositionTag_InWindow;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCursorPosition_matchMutInWindow(AzCursorPosition* restrict value, AzLogicalPosition* restrict * restrict out) {
    AzCursorPositionVariant_InWindow* restrict casted = (AzCursorPositionVariant_InWindow* restrict)value;
    bool valid = casted->tag == AzCursorPositionTag_InWindow;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzWindowPosition_matchRefInitialized(const AzWindowPosition* value, const AzPhysicalPositionI32** restrict out) {
    const AzWindowPositionVariant_Initialized* casted = (const AzWindowPositionVariant_Initialized*)value;
    bool valid = casted->tag == AzWindowPositionTag_Initialized;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzWindowPosition_matchMutInitialized(AzWindowPosition* restrict value, AzPhysicalPositionI32* restrict * restrict out) {
    AzWindowPositionVariant_Initialized* restrict casted = (AzWindowPositionVariant_Initialized* restrict)value;
    bool valid = casted->tag == AzWindowPositionTag_Initialized;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzImePosition_matchRefInitialized(const AzImePosition* value, const AzLogicalPosition** restrict out) {
    const AzImePositionVariant_Initialized* casted = (const AzImePositionVariant_Initialized*)value;
    bool valid = casted->tag == AzImePositionTag_Initialized;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzImePosition_matchMutInitialized(AzImePosition* restrict value, AzLogicalPosition* restrict * restrict out) {
    AzImePositionVariant_Initialized* restrict casted = (AzImePositionVariant_Initialized* restrict)value;
    bool valid = casted->tag == AzImePositionTag_Initialized;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutCallback_matchRefRaw(const AzLayoutCallback* value, const AzLayoutCallbackInner** restrict out) {
    const AzLayoutCallbackVariant_Raw* casted = (const AzLayoutCallbackVariant_Raw*)value;
    bool valid = casted->tag == AzLayoutCallbackTag_Raw;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutCallback_matchMutRaw(AzLayoutCallback* restrict value, AzLayoutCallbackInner* restrict * restrict out) {
    AzLayoutCallbackVariant_Raw* restrict casted = (AzLayoutCallbackVariant_Raw* restrict)value;
    bool valid = casted->tag == AzLayoutCallbackTag_Raw;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutCallback_matchRefMarshaled(const AzLayoutCallback* value, const AzMarshaledLayoutCallback** restrict out) {
    const AzLayoutCallbackVariant_Marshaled* casted = (const AzLayoutCallbackVariant_Marshaled*)value;
    bool valid = casted->tag == AzLayoutCallbackTag_Marshaled;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutCallback_matchMutMarshaled(AzLayoutCallback* restrict value, AzMarshaledLayoutCallback* restrict * restrict out) {
    AzLayoutCallbackVariant_Marshaled* restrict casted = (AzLayoutCallbackVariant_Marshaled* restrict)value;
    bool valid = casted->tag == AzLayoutCallbackTag_Marshaled;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchRefStatic(const AzPositionInfo* value, const AzPositionInfoInner** restrict out) {
    const AzPositionInfoVariant_Static* casted = (const AzPositionInfoVariant_Static*)value;
    bool valid = casted->tag == AzPositionInfoTag_Static;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchMutStatic(AzPositionInfo* restrict value, AzPositionInfoInner* restrict * restrict out) {
    AzPositionInfoVariant_Static* restrict casted = (AzPositionInfoVariant_Static* restrict)value;
    bool valid = casted->tag == AzPositionInfoTag_Static;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchRefFixed(const AzPositionInfo* value, const AzPositionInfoInner** restrict out) {
    const AzPositionInfoVariant_Fixed* casted = (const AzPositionInfoVariant_Fixed*)value;
    bool valid = casted->tag == AzPositionInfoTag_Fixed;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchMutFixed(AzPositionInfo* restrict value, AzPositionInfoInner* restrict * restrict out) {
    AzPositionInfoVariant_Fixed* restrict casted = (AzPositionInfoVariant_Fixed* restrict)value;
    bool valid = casted->tag == AzPositionInfoTag_Fixed;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchRefAbsolute(const AzPositionInfo* value, const AzPositionInfoInner** restrict out) {
    const AzPositionInfoVariant_Absolute* casted = (const AzPositionInfoVariant_Absolute*)value;
    bool valid = casted->tag == AzPositionInfoTag_Absolute;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchMutAbsolute(AzPositionInfo* restrict value, AzPositionInfoInner* restrict * restrict out) {
    AzPositionInfoVariant_Absolute* restrict casted = (AzPositionInfoVariant_Absolute* restrict)value;
    bool valid = casted->tag == AzPositionInfoTag_Absolute;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchRefRelative(const AzPositionInfo* value, const AzPositionInfoInner** restrict out) {
    const AzPositionInfoVariant_Relative* casted = (const AzPositionInfoVariant_Relative*)value;
    bool valid = casted->tag == AzPositionInfoTag_Relative;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzPositionInfo_matchMutRelative(AzPositionInfo* restrict value, AzPositionInfoInner* restrict * restrict out) {
    AzPositionInfoVariant_Relative* restrict casted = (AzPositionInfoVariant_Relative* restrict)value;
    bool valid = casted->tag == AzPositionInfoTag_Relative;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineWord_matchRefWord(const AzInlineWord* value, const AzInlineTextContents** restrict out) {
    const AzInlineWordVariant_Word* casted = (const AzInlineWordVariant_Word*)value;
    bool valid = casted->tag == AzInlineWordTag_Word;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineWord_matchMutWord(AzInlineWord* restrict value, AzInlineTextContents* restrict * restrict out) {
    AzInlineWordVariant_Word* restrict casted = (AzInlineWordVariant_Word* restrict)value;
    bool valid = casted->tag == AzInlineWordTag_Word;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFocusTarget_matchRefId(const AzFocusTarget* value, const AzDomNodeId** restrict out) {
    const AzFocusTargetVariant_Id* casted = (const AzFocusTargetVariant_Id*)value;
    bool valid = casted->tag == AzFocusTargetTag_Id;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFocusTarget_matchMutId(AzFocusTarget* restrict value, AzDomNodeId* restrict * restrict out) {
    AzFocusTargetVariant_Id* restrict casted = (AzFocusTargetVariant_Id* restrict)value;
    bool valid = casted->tag == AzFocusTargetTag_Id;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFocusTarget_matchRefPath(const AzFocusTarget* value, const AzFocusTargetPath** restrict out) {
    const AzFocusTargetVariant_Path* casted = (const AzFocusTargetVariant_Path*)value;
    bool valid = casted->tag == AzFocusTargetTag_Path;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFocusTarget_matchMutPath(AzFocusTarget* restrict value, AzFocusTargetPath* restrict * restrict out) {
    AzFocusTargetVariant_Path* restrict casted = (AzFocusTargetVariant_Path* restrict)value;
    bool valid = casted->tag == AzFocusTargetTag_Path;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAnimationRepeatCount_matchRefTimes(const AzAnimationRepeatCount* value, const Azusize** restrict out) {
    const AzAnimationRepeatCountVariant_Times* casted = (const AzAnimationRepeatCountVariant_Times*)value;
    bool valid = casted->tag == AzAnimationRepeatCountTag_Times;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAnimationRepeatCount_matchMutTimes(AzAnimationRepeatCount* restrict value, Azusize* restrict * restrict out) {
    AzAnimationRepeatCountVariant_Times* restrict casted = (AzAnimationRepeatCountVariant_Times* restrict)value;
    bool valid = casted->tag == AzAnimationRepeatCountTag_Times;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAnimationEasing_matchRefCubicBezier(const AzAnimationEasing* value, const AzSvgCubicCurve** restrict out) {
    const AzAnimationEasingVariant_CubicBezier* casted = (const AzAnimationEasingVariant_CubicBezier*)value;
    bool valid = casted->tag == AzAnimationEasingTag_CubicBezier;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAnimationEasing_matchMutCubicBezier(AzAnimationEasing* restrict value, AzSvgCubicCurve* restrict * restrict out) {
    AzAnimationEasingVariant_CubicBezier* restrict casted = (AzAnimationEasingVariant_CubicBezier* restrict)value;
    bool valid = casted->tag == AzAnimationEasingTag_CubicBezier;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeType_matchRefText(const AzNodeType* value, const AzString** restrict out) {
    const AzNodeTypeVariant_Text* casted = (const AzNodeTypeVariant_Text*)value;
    bool valid = casted->tag == AzNodeTypeTag_Text;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeType_matchMutText(AzNodeType* restrict value, AzString* restrict * restrict out) {
    AzNodeTypeVariant_Text* restrict casted = (AzNodeTypeVariant_Text* restrict)value;
    bool valid = casted->tag == AzNodeTypeTag_Text;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeType_matchRefImage(const AzNodeType* value, const AzImageRef** restrict out) {
    const AzNodeTypeVariant_Image* casted = (const AzNodeTypeVariant_Image*)value;
    bool valid = casted->tag == AzNodeTypeTag_Image;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeType_matchMutImage(AzNodeType* restrict value, AzImageRef* restrict * restrict out) {
    AzNodeTypeVariant_Image* restrict casted = (AzNodeTypeVariant_Image* restrict)value;
    bool valid = casted->tag == AzNodeTypeTag_Image;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeType_matchRefIFrame(const AzNodeType* value, const AzIFrameNode** restrict out) {
    const AzNodeTypeVariant_IFrame* casted = (const AzNodeTypeVariant_IFrame*)value;
    bool valid = casted->tag == AzNodeTypeTag_IFrame;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeType_matchMutIFrame(AzNodeType* restrict value, AzIFrameNode* restrict * restrict out) {
    AzNodeTypeVariant_IFrame* restrict casted = (AzNodeTypeVariant_IFrame* restrict)value;
    bool valid = casted->tag == AzNodeTypeTag_IFrame;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchRefHover(const AzEventFilter* value, const AzHoverEventFilter** restrict out) {
    const AzEventFilterVariant_Hover* casted = (const AzEventFilterVariant_Hover*)value;
    bool valid = casted->tag == AzEventFilterTag_Hover;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchMutHover(AzEventFilter* restrict value, AzHoverEventFilter* restrict * restrict out) {
    AzEventFilterVariant_Hover* restrict casted = (AzEventFilterVariant_Hover* restrict)value;
    bool valid = casted->tag == AzEventFilterTag_Hover;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchRefNot(const AzEventFilter* value, const AzNotEventFilter** restrict out) {
    const AzEventFilterVariant_Not* casted = (const AzEventFilterVariant_Not*)value;
    bool valid = casted->tag == AzEventFilterTag_Not;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchMutNot(AzEventFilter* restrict value, AzNotEventFilter* restrict * restrict out) {
    AzEventFilterVariant_Not* restrict casted = (AzEventFilterVariant_Not* restrict)value;
    bool valid = casted->tag == AzEventFilterTag_Not;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchRefFocus(const AzEventFilter* value, const AzFocusEventFilter** restrict out) {
    const AzEventFilterVariant_Focus* casted = (const AzEventFilterVariant_Focus*)value;
    bool valid = casted->tag == AzEventFilterTag_Focus;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchMutFocus(AzEventFilter* restrict value, AzFocusEventFilter* restrict * restrict out) {
    AzEventFilterVariant_Focus* restrict casted = (AzEventFilterVariant_Focus* restrict)value;
    bool valid = casted->tag == AzEventFilterTag_Focus;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchRefWindow(const AzEventFilter* value, const AzWindowEventFilter** restrict out) {
    const AzEventFilterVariant_Window* casted = (const AzEventFilterVariant_Window*)value;
    bool valid = casted->tag == AzEventFilterTag_Window;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchMutWindow(AzEventFilter* restrict value, AzWindowEventFilter* restrict * restrict out) {
    AzEventFilterVariant_Window* restrict casted = (AzEventFilterVariant_Window* restrict)value;
    bool valid = casted->tag == AzEventFilterTag_Window;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchRefComponent(const AzEventFilter* value, const AzComponentEventFilter** restrict out) {
    const AzEventFilterVariant_Component* casted = (const AzEventFilterVariant_Component*)value;
    bool valid = casted->tag == AzEventFilterTag_Component;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchMutComponent(AzEventFilter* restrict value, AzComponentEventFilter* restrict * restrict out) {
    AzEventFilterVariant_Component* restrict casted = (AzEventFilterVariant_Component* restrict)value;
    bool valid = casted->tag == AzEventFilterTag_Component;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchRefApplication(const AzEventFilter* value, const AzApplicationEventFilter** restrict out) {
    const AzEventFilterVariant_Application* casted = (const AzEventFilterVariant_Application*)value;
    bool valid = casted->tag == AzEventFilterTag_Application;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzEventFilter_matchMutApplication(AzEventFilter* restrict value, AzApplicationEventFilter* restrict * restrict out) {
    AzEventFilterVariant_Application* restrict casted = (AzEventFilterVariant_Application* restrict)value;
    bool valid = casted->tag == AzEventFilterTag_Application;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNotEventFilter_matchRefHover(const AzNotEventFilter* value, const AzHoverEventFilter** restrict out) {
    const AzNotEventFilterVariant_Hover* casted = (const AzNotEventFilterVariant_Hover*)value;
    bool valid = casted->tag == AzNotEventFilterTag_Hover;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNotEventFilter_matchMutHover(AzNotEventFilter* restrict value, AzHoverEventFilter* restrict * restrict out) {
    AzNotEventFilterVariant_Hover* restrict casted = (AzNotEventFilterVariant_Hover* restrict)value;
    bool valid = casted->tag == AzNotEventFilterTag_Hover;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNotEventFilter_matchRefFocus(const AzNotEventFilter* value, const AzFocusEventFilter** restrict out) {
    const AzNotEventFilterVariant_Focus* casted = (const AzNotEventFilterVariant_Focus*)value;
    bool valid = casted->tag == AzNotEventFilterTag_Focus;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNotEventFilter_matchMutFocus(AzNotEventFilter* restrict value, AzFocusEventFilter* restrict * restrict out) {
    AzNotEventFilterVariant_Focus* restrict casted = (AzNotEventFilterVariant_Focus* restrict)value;
    bool valid = casted->tag == AzNotEventFilterTag_Focus;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTabIndex_matchRefOverrideInParent(const AzTabIndex* value, const Azu32** restrict out) {
    const AzTabIndexVariant_OverrideInParent* casted = (const AzTabIndexVariant_OverrideInParent*)value;
    bool valid = casted->tag == AzTabIndexTag_OverrideInParent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTabIndex_matchMutOverrideInParent(AzTabIndex* restrict value, Azu32* restrict * restrict out) {
    AzTabIndexVariant_OverrideInParent* restrict casted = (AzTabIndexVariant_OverrideInParent* restrict)value;
    bool valid = casted->tag == AzTabIndexTag_OverrideInParent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIdOrClass_matchRefId(const AzIdOrClass* value, const AzString** restrict out) {
    const AzIdOrClassVariant_Id* casted = (const AzIdOrClassVariant_Id*)value;
    bool valid = casted->tag == AzIdOrClassTag_Id;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIdOrClass_matchMutId(AzIdOrClass* restrict value, AzString* restrict * restrict out) {
    AzIdOrClassVariant_Id* restrict casted = (AzIdOrClassVariant_Id* restrict)value;
    bool valid = casted->tag == AzIdOrClassTag_Id;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIdOrClass_matchRefClass(const AzIdOrClass* value, const AzString** restrict out) {
    const AzIdOrClassVariant_Class* casted = (const AzIdOrClassVariant_Class*)value;
    bool valid = casted->tag == AzIdOrClassTag_Class;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIdOrClass_matchMutClass(AzIdOrClass* restrict value, AzString* restrict * restrict out) {
    AzIdOrClassVariant_Class* restrict casted = (AzIdOrClassVariant_Class* restrict)value;
    bool valid = casted->tag == AzIdOrClassTag_Class;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchRefNormal(const AzNodeDataInlineCssProperty* value, const AzCssProperty** restrict out) {
    const AzNodeDataInlineCssPropertyVariant_Normal* casted = (const AzNodeDataInlineCssPropertyVariant_Normal*)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Normal;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchMutNormal(AzNodeDataInlineCssProperty* restrict value, AzCssProperty* restrict * restrict out) {
    AzNodeDataInlineCssPropertyVariant_Normal* restrict casted = (AzNodeDataInlineCssPropertyVariant_Normal* restrict)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Normal;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchRefActive(const AzNodeDataInlineCssProperty* value, const AzCssProperty** restrict out) {
    const AzNodeDataInlineCssPropertyVariant_Active* casted = (const AzNodeDataInlineCssPropertyVariant_Active*)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Active;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchMutActive(AzNodeDataInlineCssProperty* restrict value, AzCssProperty* restrict * restrict out) {
    AzNodeDataInlineCssPropertyVariant_Active* restrict casted = (AzNodeDataInlineCssPropertyVariant_Active* restrict)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Active;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchRefFocus(const AzNodeDataInlineCssProperty* value, const AzCssProperty** restrict out) {
    const AzNodeDataInlineCssPropertyVariant_Focus* casted = (const AzNodeDataInlineCssPropertyVariant_Focus*)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Focus;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchMutFocus(AzNodeDataInlineCssProperty* restrict value, AzCssProperty* restrict * restrict out) {
    AzNodeDataInlineCssPropertyVariant_Focus* restrict casted = (AzNodeDataInlineCssPropertyVariant_Focus* restrict)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Focus;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchRefHover(const AzNodeDataInlineCssProperty* value, const AzCssProperty** restrict out) {
    const AzNodeDataInlineCssPropertyVariant_Hover* casted = (const AzNodeDataInlineCssPropertyVariant_Hover*)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Hover;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssProperty_matchMutHover(AzNodeDataInlineCssProperty* restrict value, AzCssProperty* restrict * restrict out) {
    AzNodeDataInlineCssPropertyVariant_Hover* restrict casted = (AzNodeDataInlineCssPropertyVariant_Hover* restrict)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyTag_Hover;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItem_matchRefLabel(const AzMenuItem* value, const AzStringMenuItem** restrict out) {
    const AzMenuItemVariant_Label* casted = (const AzMenuItemVariant_Label*)value;
    bool valid = casted->tag == AzMenuItemTag_Label;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItem_matchMutLabel(AzMenuItem* restrict value, AzStringMenuItem* restrict * restrict out) {
    AzMenuItemVariant_Label* restrict casted = (AzMenuItemVariant_Label* restrict)value;
    bool valid = casted->tag == AzMenuItemTag_Label;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItemIcon_matchRefCheckbox(const AzMenuItemIcon* value, const Azbool** restrict out) {
    const AzMenuItemIconVariant_Checkbox* casted = (const AzMenuItemIconVariant_Checkbox*)value;
    bool valid = casted->tag == AzMenuItemIconTag_Checkbox;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItemIcon_matchMutCheckbox(AzMenuItemIcon* restrict value, Azbool* restrict * restrict out) {
    AzMenuItemIconVariant_Checkbox* restrict casted = (AzMenuItemIconVariant_Checkbox* restrict)value;
    bool valid = casted->tag == AzMenuItemIconTag_Checkbox;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItemIcon_matchRefImage(const AzMenuItemIcon* value, const AzImageRef** restrict out) {
    const AzMenuItemIconVariant_Image* casted = (const AzMenuItemIconVariant_Image*)value;
    bool valid = casted->tag == AzMenuItemIconTag_Image;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItemIcon_matchMutImage(AzMenuItemIcon* restrict value, AzImageRef* restrict * restrict out) {
    AzMenuItemIconVariant_Image* restrict casted = (AzMenuItemIconVariant_Image* restrict)value;
    bool valid = casted->tag == AzMenuItemIconTag_Image;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssDeclaration_matchRefStatic(const AzCssDeclaration* value, const AzCssProperty** restrict out) {
    const AzCssDeclarationVariant_Static* casted = (const AzCssDeclarationVariant_Static*)value;
    bool valid = casted->tag == AzCssDeclarationTag_Static;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssDeclaration_matchMutStatic(AzCssDeclaration* restrict value, AzCssProperty* restrict * restrict out) {
    AzCssDeclarationVariant_Static* restrict casted = (AzCssDeclarationVariant_Static* restrict)value;
    bool valid = casted->tag == AzCssDeclarationTag_Static;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssDeclaration_matchRefDynamic(const AzCssDeclaration* value, const AzDynamicCssProperty** restrict out) {
    const AzCssDeclarationVariant_Dynamic* casted = (const AzCssDeclarationVariant_Dynamic*)value;
    bool valid = casted->tag == AzCssDeclarationTag_Dynamic;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssDeclaration_matchMutDynamic(AzCssDeclaration* restrict value, AzDynamicCssProperty* restrict * restrict out) {
    AzCssDeclarationVariant_Dynamic* restrict casted = (AzCssDeclarationVariant_Dynamic* restrict)value;
    bool valid = casted->tag == AzCssDeclarationTag_Dynamic;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchRefType(const AzCssPathSelector* value, const AzNodeTypeKey** restrict out) {
    const AzCssPathSelectorVariant_Type* casted = (const AzCssPathSelectorVariant_Type*)value;
    bool valid = casted->tag == AzCssPathSelectorTag_Type;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchMutType(AzCssPathSelector* restrict value, AzNodeTypeKey* restrict * restrict out) {
    AzCssPathSelectorVariant_Type* restrict casted = (AzCssPathSelectorVariant_Type* restrict)value;
    bool valid = casted->tag == AzCssPathSelectorTag_Type;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchRefClass(const AzCssPathSelector* value, const AzString** restrict out) {
    const AzCssPathSelectorVariant_Class* casted = (const AzCssPathSelectorVariant_Class*)value;
    bool valid = casted->tag == AzCssPathSelectorTag_Class;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchMutClass(AzCssPathSelector* restrict value, AzString* restrict * restrict out) {
    AzCssPathSelectorVariant_Class* restrict casted = (AzCssPathSelectorVariant_Class* restrict)value;
    bool valid = casted->tag == AzCssPathSelectorTag_Class;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchRefId(const AzCssPathSelector* value, const AzString** restrict out) {
    const AzCssPathSelectorVariant_Id* casted = (const AzCssPathSelectorVariant_Id*)value;
    bool valid = casted->tag == AzCssPathSelectorTag_Id;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchMutId(AzCssPathSelector* restrict value, AzString* restrict * restrict out) {
    AzCssPathSelectorVariant_Id* restrict casted = (AzCssPathSelectorVariant_Id* restrict)value;
    bool valid = casted->tag == AzCssPathSelectorTag_Id;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchRefPseudoSelector(const AzCssPathSelector* value, const AzCssPathPseudoSelector** restrict out) {
    const AzCssPathSelectorVariant_PseudoSelector* casted = (const AzCssPathSelectorVariant_PseudoSelector*)value;
    bool valid = casted->tag == AzCssPathSelectorTag_PseudoSelector;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelector_matchMutPseudoSelector(AzCssPathSelector* restrict value, AzCssPathPseudoSelector* restrict * restrict out) {
    AzCssPathSelectorVariant_PseudoSelector* restrict casted = (AzCssPathSelectorVariant_PseudoSelector* restrict)value;
    bool valid = casted->tag == AzCssPathSelectorTag_PseudoSelector;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathPseudoSelector_matchRefNthChild(const AzCssPathPseudoSelector* value, const AzCssNthChildSelector** restrict out) {
    const AzCssPathPseudoSelectorVariant_NthChild* casted = (const AzCssPathPseudoSelectorVariant_NthChild*)value;
    bool valid = casted->tag == AzCssPathPseudoSelectorTag_NthChild;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathPseudoSelector_matchMutNthChild(AzCssPathPseudoSelector* restrict value, AzCssNthChildSelector* restrict * restrict out) {
    AzCssPathPseudoSelectorVariant_NthChild* restrict casted = (AzCssPathPseudoSelectorVariant_NthChild* restrict)value;
    bool valid = casted->tag == AzCssPathPseudoSelectorTag_NthChild;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssNthChildSelector_matchRefNumber(const AzCssNthChildSelector* value, const Azu32** restrict out) {
    const AzCssNthChildSelectorVariant_Number* casted = (const AzCssNthChildSelectorVariant_Number*)value;
    bool valid = casted->tag == AzCssNthChildSelectorTag_Number;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssNthChildSelector_matchMutNumber(AzCssNthChildSelector* restrict value, Azu32* restrict * restrict out) {
    AzCssNthChildSelectorVariant_Number* restrict casted = (AzCssNthChildSelectorVariant_Number* restrict)value;
    bool valid = casted->tag == AzCssNthChildSelectorTag_Number;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssNthChildSelector_matchRefPattern(const AzCssNthChildSelector* value, const AzCssNthChildPattern** restrict out) {
    const AzCssNthChildSelectorVariant_Pattern* casted = (const AzCssNthChildSelectorVariant_Pattern*)value;
    bool valid = casted->tag == AzCssNthChildSelectorTag_Pattern;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssNthChildSelector_matchMutPattern(AzCssNthChildSelector* restrict value, AzCssNthChildPattern* restrict * restrict out) {
    AzCssNthChildSelectorVariant_Pattern* restrict casted = (AzCssNthChildSelectorVariant_Pattern* restrict)value;
    bool valid = casted->tag == AzCssNthChildSelectorTag_Pattern;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAnimationInterpolationFunction_matchRefCubicBezier(const AzAnimationInterpolationFunction* value, const AzSvgCubicCurve** restrict out) {
    const AzAnimationInterpolationFunctionVariant_CubicBezier* casted = (const AzAnimationInterpolationFunctionVariant_CubicBezier*)value;
    bool valid = casted->tag == AzAnimationInterpolationFunctionTag_CubicBezier;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAnimationInterpolationFunction_matchMutCubicBezier(AzAnimationInterpolationFunction* restrict value, AzSvgCubicCurve* restrict * restrict out) {
    AzAnimationInterpolationFunctionVariant_CubicBezier* restrict casted = (AzAnimationInterpolationFunctionVariant_CubicBezier* restrict)value;
    bool valid = casted->tag == AzAnimationInterpolationFunctionTag_CubicBezier;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDirection_matchRefAngle(const AzDirection* value, const AzAngleValue** restrict out) {
    const AzDirectionVariant_Angle* casted = (const AzDirectionVariant_Angle*)value;
    bool valid = casted->tag == AzDirectionTag_Angle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDirection_matchMutAngle(AzDirection* restrict value, AzAngleValue* restrict * restrict out) {
    AzDirectionVariant_Angle* restrict casted = (AzDirectionVariant_Angle* restrict)value;
    bool valid = casted->tag == AzDirectionTag_Angle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDirection_matchRefFromTo(const AzDirection* value, const AzDirectionCorners** restrict out) {
    const AzDirectionVariant_FromTo* casted = (const AzDirectionVariant_FromTo*)value;
    bool valid = casted->tag == AzDirectionTag_FromTo;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDirection_matchMutFromTo(AzDirection* restrict value, AzDirectionCorners* restrict * restrict out) {
    AzDirectionVariant_FromTo* restrict casted = (AzDirectionVariant_FromTo* restrict)value;
    bool valid = casted->tag == AzDirectionTag_FromTo;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchRefLinearGradient(const AzStyleBackgroundContent* value, const AzLinearGradient** restrict out) {
    const AzStyleBackgroundContentVariant_LinearGradient* casted = (const AzStyleBackgroundContentVariant_LinearGradient*)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_LinearGradient;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchMutLinearGradient(AzStyleBackgroundContent* restrict value, AzLinearGradient* restrict * restrict out) {
    AzStyleBackgroundContentVariant_LinearGradient* restrict casted = (AzStyleBackgroundContentVariant_LinearGradient* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_LinearGradient;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchRefRadialGradient(const AzStyleBackgroundContent* value, const AzRadialGradient** restrict out) {
    const AzStyleBackgroundContentVariant_RadialGradient* casted = (const AzStyleBackgroundContentVariant_RadialGradient*)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_RadialGradient;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchMutRadialGradient(AzStyleBackgroundContent* restrict value, AzRadialGradient* restrict * restrict out) {
    AzStyleBackgroundContentVariant_RadialGradient* restrict casted = (AzStyleBackgroundContentVariant_RadialGradient* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_RadialGradient;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchRefConicGradient(const AzStyleBackgroundContent* value, const AzConicGradient** restrict out) {
    const AzStyleBackgroundContentVariant_ConicGradient* casted = (const AzStyleBackgroundContentVariant_ConicGradient*)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_ConicGradient;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchMutConicGradient(AzStyleBackgroundContent* restrict value, AzConicGradient* restrict * restrict out) {
    AzStyleBackgroundContentVariant_ConicGradient* restrict casted = (AzStyleBackgroundContentVariant_ConicGradient* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_ConicGradient;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchRefImage(const AzStyleBackgroundContent* value, const AzString** restrict out) {
    const AzStyleBackgroundContentVariant_Image* casted = (const AzStyleBackgroundContentVariant_Image*)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_Image;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchMutImage(AzStyleBackgroundContent* restrict value, AzString* restrict * restrict out) {
    AzStyleBackgroundContentVariant_Image* restrict casted = (AzStyleBackgroundContentVariant_Image* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_Image;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchRefColor(const AzStyleBackgroundContent* value, const AzColorU** restrict out) {
    const AzStyleBackgroundContentVariant_Color* casted = (const AzStyleBackgroundContentVariant_Color*)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_Color;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContent_matchMutColor(AzStyleBackgroundContent* restrict value, AzColorU* restrict * restrict out) {
    AzStyleBackgroundContentVariant_Color* restrict casted = (AzStyleBackgroundContentVariant_Color* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundContentTag_Color;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzBackgroundPositionHorizontal_matchRefExact(const AzBackgroundPositionHorizontal* value, const AzPixelValue** restrict out) {
    const AzBackgroundPositionHorizontalVariant_Exact* casted = (const AzBackgroundPositionHorizontalVariant_Exact*)value;
    bool valid = casted->tag == AzBackgroundPositionHorizontalTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzBackgroundPositionHorizontal_matchMutExact(AzBackgroundPositionHorizontal* restrict value, AzPixelValue* restrict * restrict out) {
    AzBackgroundPositionHorizontalVariant_Exact* restrict casted = (AzBackgroundPositionHorizontalVariant_Exact* restrict)value;
    bool valid = casted->tag == AzBackgroundPositionHorizontalTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzBackgroundPositionVertical_matchRefExact(const AzBackgroundPositionVertical* value, const AzPixelValue** restrict out) {
    const AzBackgroundPositionVerticalVariant_Exact* casted = (const AzBackgroundPositionVerticalVariant_Exact*)value;
    bool valid = casted->tag == AzBackgroundPositionVerticalTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzBackgroundPositionVertical_matchMutExact(AzBackgroundPositionVertical* restrict value, AzPixelValue* restrict * restrict out) {
    AzBackgroundPositionVerticalVariant_Exact* restrict casted = (AzBackgroundPositionVerticalVariant_Exact* restrict)value;
    bool valid = casted->tag == AzBackgroundPositionVerticalTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundSize_matchRefExactSize(const AzStyleBackgroundSize* value, const Az[PixelValue;2]** restrict out) {
    const AzStyleBackgroundSizeVariant_ExactSize* casted = (const AzStyleBackgroundSizeVariant_ExactSize*)value;
    bool valid = casted->tag == AzStyleBackgroundSizeTag_ExactSize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundSize_matchMutExactSize(AzStyleBackgroundSize* restrict value, Az[PixelValue;2]* restrict * restrict out) {
    AzStyleBackgroundSizeVariant_ExactSize* restrict casted = (AzStyleBackgroundSizeVariant_ExactSize* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundSizeTag_ExactSize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamily_matchRefSystem(const AzStyleFontFamily* value, const AzString** restrict out) {
    const AzStyleFontFamilyVariant_System* casted = (const AzStyleFontFamilyVariant_System*)value;
    bool valid = casted->tag == AzStyleFontFamilyTag_System;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamily_matchMutSystem(AzStyleFontFamily* restrict value, AzString* restrict * restrict out) {
    AzStyleFontFamilyVariant_System* restrict casted = (AzStyleFontFamilyVariant_System* restrict)value;
    bool valid = casted->tag == AzStyleFontFamilyTag_System;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamily_matchRefFile(const AzStyleFontFamily* value, const AzString** restrict out) {
    const AzStyleFontFamilyVariant_File* casted = (const AzStyleFontFamilyVariant_File*)value;
    bool valid = casted->tag == AzStyleFontFamilyTag_File;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamily_matchMutFile(AzStyleFontFamily* restrict value, AzString* restrict * restrict out) {
    AzStyleFontFamilyVariant_File* restrict casted = (AzStyleFontFamilyVariant_File* restrict)value;
    bool valid = casted->tag == AzStyleFontFamilyTag_File;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamily_matchRefRef(const AzStyleFontFamily* value, const AzFontRef** restrict out) {
    const AzStyleFontFamilyVariant_Ref* casted = (const AzStyleFontFamilyVariant_Ref*)value;
    bool valid = casted->tag == AzStyleFontFamilyTag_Ref;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamily_matchMutRef(AzStyleFontFamily* restrict value, AzFontRef* restrict * restrict out) {
    AzStyleFontFamilyVariant_Ref* restrict casted = (AzStyleFontFamilyVariant_Ref* restrict)value;
    bool valid = casted->tag == AzStyleFontFamilyTag_Ref;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefMatrix(const AzStyleTransform* value, const AzStyleTransformMatrix2D** restrict out) {
    const AzStyleTransformVariant_Matrix* casted = (const AzStyleTransformVariant_Matrix*)value;
    bool valid = casted->tag == AzStyleTransformTag_Matrix;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutMatrix(AzStyleTransform* restrict value, AzStyleTransformMatrix2D* restrict * restrict out) {
    AzStyleTransformVariant_Matrix* restrict casted = (AzStyleTransformVariant_Matrix* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Matrix;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefMatrix3D(const AzStyleTransform* value, const AzStyleTransformMatrix3D** restrict out) {
    const AzStyleTransformVariant_Matrix3D* casted = (const AzStyleTransformVariant_Matrix3D*)value;
    bool valid = casted->tag == AzStyleTransformTag_Matrix3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutMatrix3D(AzStyleTransform* restrict value, AzStyleTransformMatrix3D* restrict * restrict out) {
    AzStyleTransformVariant_Matrix3D* restrict casted = (AzStyleTransformVariant_Matrix3D* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Matrix3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefTranslate(const AzStyleTransform* value, const AzStyleTransformTranslate2D** restrict out) {
    const AzStyleTransformVariant_Translate* casted = (const AzStyleTransformVariant_Translate*)value;
    bool valid = casted->tag == AzStyleTransformTag_Translate;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutTranslate(AzStyleTransform* restrict value, AzStyleTransformTranslate2D* restrict * restrict out) {
    AzStyleTransformVariant_Translate* restrict casted = (AzStyleTransformVariant_Translate* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Translate;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefTranslate3D(const AzStyleTransform* value, const AzStyleTransformTranslate3D** restrict out) {
    const AzStyleTransformVariant_Translate3D* casted = (const AzStyleTransformVariant_Translate3D*)value;
    bool valid = casted->tag == AzStyleTransformTag_Translate3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutTranslate3D(AzStyleTransform* restrict value, AzStyleTransformTranslate3D* restrict * restrict out) {
    AzStyleTransformVariant_Translate3D* restrict casted = (AzStyleTransformVariant_Translate3D* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Translate3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefTranslateX(const AzStyleTransform* value, const AzPixelValue** restrict out) {
    const AzStyleTransformVariant_TranslateX* casted = (const AzStyleTransformVariant_TranslateX*)value;
    bool valid = casted->tag == AzStyleTransformTag_TranslateX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutTranslateX(AzStyleTransform* restrict value, AzPixelValue* restrict * restrict out) {
    AzStyleTransformVariant_TranslateX* restrict casted = (AzStyleTransformVariant_TranslateX* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_TranslateX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefTranslateY(const AzStyleTransform* value, const AzPixelValue** restrict out) {
    const AzStyleTransformVariant_TranslateY* casted = (const AzStyleTransformVariant_TranslateY*)value;
    bool valid = casted->tag == AzStyleTransformTag_TranslateY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutTranslateY(AzStyleTransform* restrict value, AzPixelValue* restrict * restrict out) {
    AzStyleTransformVariant_TranslateY* restrict casted = (AzStyleTransformVariant_TranslateY* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_TranslateY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefTranslateZ(const AzStyleTransform* value, const AzPixelValue** restrict out) {
    const AzStyleTransformVariant_TranslateZ* casted = (const AzStyleTransformVariant_TranslateZ*)value;
    bool valid = casted->tag == AzStyleTransformTag_TranslateZ;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutTranslateZ(AzStyleTransform* restrict value, AzPixelValue* restrict * restrict out) {
    AzStyleTransformVariant_TranslateZ* restrict casted = (AzStyleTransformVariant_TranslateZ* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_TranslateZ;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefRotate(const AzStyleTransform* value, const AzAngleValue** restrict out) {
    const AzStyleTransformVariant_Rotate* casted = (const AzStyleTransformVariant_Rotate*)value;
    bool valid = casted->tag == AzStyleTransformTag_Rotate;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutRotate(AzStyleTransform* restrict value, AzAngleValue* restrict * restrict out) {
    AzStyleTransformVariant_Rotate* restrict casted = (AzStyleTransformVariant_Rotate* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Rotate;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefRotate3D(const AzStyleTransform* value, const AzStyleTransformRotate3D** restrict out) {
    const AzStyleTransformVariant_Rotate3D* casted = (const AzStyleTransformVariant_Rotate3D*)value;
    bool valid = casted->tag == AzStyleTransformTag_Rotate3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutRotate3D(AzStyleTransform* restrict value, AzStyleTransformRotate3D* restrict * restrict out) {
    AzStyleTransformVariant_Rotate3D* restrict casted = (AzStyleTransformVariant_Rotate3D* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Rotate3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefRotateX(const AzStyleTransform* value, const AzAngleValue** restrict out) {
    const AzStyleTransformVariant_RotateX* casted = (const AzStyleTransformVariant_RotateX*)value;
    bool valid = casted->tag == AzStyleTransformTag_RotateX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutRotateX(AzStyleTransform* restrict value, AzAngleValue* restrict * restrict out) {
    AzStyleTransformVariant_RotateX* restrict casted = (AzStyleTransformVariant_RotateX* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_RotateX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefRotateY(const AzStyleTransform* value, const AzAngleValue** restrict out) {
    const AzStyleTransformVariant_RotateY* casted = (const AzStyleTransformVariant_RotateY*)value;
    bool valid = casted->tag == AzStyleTransformTag_RotateY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutRotateY(AzStyleTransform* restrict value, AzAngleValue* restrict * restrict out) {
    AzStyleTransformVariant_RotateY* restrict casted = (AzStyleTransformVariant_RotateY* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_RotateY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefRotateZ(const AzStyleTransform* value, const AzAngleValue** restrict out) {
    const AzStyleTransformVariant_RotateZ* casted = (const AzStyleTransformVariant_RotateZ*)value;
    bool valid = casted->tag == AzStyleTransformTag_RotateZ;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutRotateZ(AzStyleTransform* restrict value, AzAngleValue* restrict * restrict out) {
    AzStyleTransformVariant_RotateZ* restrict casted = (AzStyleTransformVariant_RotateZ* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_RotateZ;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefScale(const AzStyleTransform* value, const AzStyleTransformScale2D** restrict out) {
    const AzStyleTransformVariant_Scale* casted = (const AzStyleTransformVariant_Scale*)value;
    bool valid = casted->tag == AzStyleTransformTag_Scale;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutScale(AzStyleTransform* restrict value, AzStyleTransformScale2D* restrict * restrict out) {
    AzStyleTransformVariant_Scale* restrict casted = (AzStyleTransformVariant_Scale* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Scale;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefScale3D(const AzStyleTransform* value, const AzStyleTransformScale3D** restrict out) {
    const AzStyleTransformVariant_Scale3D* casted = (const AzStyleTransformVariant_Scale3D*)value;
    bool valid = casted->tag == AzStyleTransformTag_Scale3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutScale3D(AzStyleTransform* restrict value, AzStyleTransformScale3D* restrict * restrict out) {
    AzStyleTransformVariant_Scale3D* restrict casted = (AzStyleTransformVariant_Scale3D* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Scale3D;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefScaleX(const AzStyleTransform* value, const AzPercentageValue** restrict out) {
    const AzStyleTransformVariant_ScaleX* casted = (const AzStyleTransformVariant_ScaleX*)value;
    bool valid = casted->tag == AzStyleTransformTag_ScaleX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutScaleX(AzStyleTransform* restrict value, AzPercentageValue* restrict * restrict out) {
    AzStyleTransformVariant_ScaleX* restrict casted = (AzStyleTransformVariant_ScaleX* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_ScaleX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefScaleY(const AzStyleTransform* value, const AzPercentageValue** restrict out) {
    const AzStyleTransformVariant_ScaleY* casted = (const AzStyleTransformVariant_ScaleY*)value;
    bool valid = casted->tag == AzStyleTransformTag_ScaleY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutScaleY(AzStyleTransform* restrict value, AzPercentageValue* restrict * restrict out) {
    AzStyleTransformVariant_ScaleY* restrict casted = (AzStyleTransformVariant_ScaleY* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_ScaleY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefScaleZ(const AzStyleTransform* value, const AzPercentageValue** restrict out) {
    const AzStyleTransformVariant_ScaleZ* casted = (const AzStyleTransformVariant_ScaleZ*)value;
    bool valid = casted->tag == AzStyleTransformTag_ScaleZ;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutScaleZ(AzStyleTransform* restrict value, AzPercentageValue* restrict * restrict out) {
    AzStyleTransformVariant_ScaleZ* restrict casted = (AzStyleTransformVariant_ScaleZ* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_ScaleZ;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefSkew(const AzStyleTransform* value, const AzStyleTransformSkew2D** restrict out) {
    const AzStyleTransformVariant_Skew* casted = (const AzStyleTransformVariant_Skew*)value;
    bool valid = casted->tag == AzStyleTransformTag_Skew;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutSkew(AzStyleTransform* restrict value, AzStyleTransformSkew2D* restrict * restrict out) {
    AzStyleTransformVariant_Skew* restrict casted = (AzStyleTransformVariant_Skew* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Skew;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefSkewX(const AzStyleTransform* value, const AzPercentageValue** restrict out) {
    const AzStyleTransformVariant_SkewX* casted = (const AzStyleTransformVariant_SkewX*)value;
    bool valid = casted->tag == AzStyleTransformTag_SkewX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutSkewX(AzStyleTransform* restrict value, AzPercentageValue* restrict * restrict out) {
    AzStyleTransformVariant_SkewX* restrict casted = (AzStyleTransformVariant_SkewX* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_SkewX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefSkewY(const AzStyleTransform* value, const AzPercentageValue** restrict out) {
    const AzStyleTransformVariant_SkewY* casted = (const AzStyleTransformVariant_SkewY*)value;
    bool valid = casted->tag == AzStyleTransformTag_SkewY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutSkewY(AzStyleTransform* restrict value, AzPercentageValue* restrict * restrict out) {
    AzStyleTransformVariant_SkewY* restrict casted = (AzStyleTransformVariant_SkewY* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_SkewY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchRefPerspective(const AzStyleTransform* value, const AzPixelValue** restrict out) {
    const AzStyleTransformVariant_Perspective* casted = (const AzStyleTransformVariant_Perspective*)value;
    bool valid = casted->tag == AzStyleTransformTag_Perspective;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransform_matchMutPerspective(AzStyleTransform* restrict value, AzPixelValue* restrict * restrict out) {
    AzStyleTransformVariant_Perspective* restrict casted = (AzStyleTransformVariant_Perspective* restrict)value;
    bool valid = casted->tag == AzStyleTransformTag_Perspective;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBoxShadowValue_matchRefExact(const AzStyleBoxShadowValue* value, const AzStyleBoxShadow** restrict out) {
    const AzStyleBoxShadowValueVariant_Exact* casted = (const AzStyleBoxShadowValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBoxShadowValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBoxShadowValue_matchMutExact(AzStyleBoxShadowValue* restrict value, AzStyleBoxShadow* restrict * restrict out) {
    AzStyleBoxShadowValueVariant_Exact* restrict casted = (AzStyleBoxShadowValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBoxShadowValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutAlignContentValue_matchRefExact(const AzLayoutAlignContentValue* value, const AzLayoutAlignContent** restrict out) {
    const AzLayoutAlignContentValueVariant_Exact* casted = (const AzLayoutAlignContentValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutAlignContentValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutAlignContentValue_matchMutExact(AzLayoutAlignContentValue* restrict value, AzLayoutAlignContent* restrict * restrict out) {
    AzLayoutAlignContentValueVariant_Exact* restrict casted = (AzLayoutAlignContentValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutAlignContentValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutAlignItemsValue_matchRefExact(const AzLayoutAlignItemsValue* value, const AzLayoutAlignItems** restrict out) {
    const AzLayoutAlignItemsValueVariant_Exact* casted = (const AzLayoutAlignItemsValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutAlignItemsValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutAlignItemsValue_matchMutExact(AzLayoutAlignItemsValue* restrict value, AzLayoutAlignItems* restrict * restrict out) {
    AzLayoutAlignItemsValueVariant_Exact* restrict casted = (AzLayoutAlignItemsValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutAlignItemsValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBottomValue_matchRefExact(const AzLayoutBottomValue* value, const AzLayoutBottom** restrict out) {
    const AzLayoutBottomValueVariant_Exact* casted = (const AzLayoutBottomValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutBottomValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBottomValue_matchMutExact(AzLayoutBottomValue* restrict value, AzLayoutBottom* restrict * restrict out) {
    AzLayoutBottomValueVariant_Exact* restrict casted = (AzLayoutBottomValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutBottomValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBoxSizingValue_matchRefExact(const AzLayoutBoxSizingValue* value, const AzLayoutBoxSizing** restrict out) {
    const AzLayoutBoxSizingValueVariant_Exact* casted = (const AzLayoutBoxSizingValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutBoxSizingValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBoxSizingValue_matchMutExact(AzLayoutBoxSizingValue* restrict value, AzLayoutBoxSizing* restrict * restrict out) {
    AzLayoutBoxSizingValueVariant_Exact* restrict casted = (AzLayoutBoxSizingValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutBoxSizingValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexDirectionValue_matchRefExact(const AzLayoutFlexDirectionValue* value, const AzLayoutFlexDirection** restrict out) {
    const AzLayoutFlexDirectionValueVariant_Exact* casted = (const AzLayoutFlexDirectionValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutFlexDirectionValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexDirectionValue_matchMutExact(AzLayoutFlexDirectionValue* restrict value, AzLayoutFlexDirection* restrict * restrict out) {
    AzLayoutFlexDirectionValueVariant_Exact* restrict casted = (AzLayoutFlexDirectionValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutFlexDirectionValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutDisplayValue_matchRefExact(const AzLayoutDisplayValue* value, const AzLayoutDisplay** restrict out) {
    const AzLayoutDisplayValueVariant_Exact* casted = (const AzLayoutDisplayValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutDisplayValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutDisplayValue_matchMutExact(AzLayoutDisplayValue* restrict value, AzLayoutDisplay* restrict * restrict out) {
    AzLayoutDisplayValueVariant_Exact* restrict casted = (AzLayoutDisplayValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutDisplayValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexGrowValue_matchRefExact(const AzLayoutFlexGrowValue* value, const AzLayoutFlexGrow** restrict out) {
    const AzLayoutFlexGrowValueVariant_Exact* casted = (const AzLayoutFlexGrowValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutFlexGrowValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexGrowValue_matchMutExact(AzLayoutFlexGrowValue* restrict value, AzLayoutFlexGrow* restrict * restrict out) {
    AzLayoutFlexGrowValueVariant_Exact* restrict casted = (AzLayoutFlexGrowValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutFlexGrowValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexShrinkValue_matchRefExact(const AzLayoutFlexShrinkValue* value, const AzLayoutFlexShrink** restrict out) {
    const AzLayoutFlexShrinkValueVariant_Exact* casted = (const AzLayoutFlexShrinkValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutFlexShrinkValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexShrinkValue_matchMutExact(AzLayoutFlexShrinkValue* restrict value, AzLayoutFlexShrink* restrict * restrict out) {
    AzLayoutFlexShrinkValueVariant_Exact* restrict casted = (AzLayoutFlexShrinkValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutFlexShrinkValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFloatValue_matchRefExact(const AzLayoutFloatValue* value, const AzLayoutFloat** restrict out) {
    const AzLayoutFloatValueVariant_Exact* casted = (const AzLayoutFloatValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutFloatValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFloatValue_matchMutExact(AzLayoutFloatValue* restrict value, AzLayoutFloat* restrict * restrict out) {
    AzLayoutFloatValueVariant_Exact* restrict casted = (AzLayoutFloatValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutFloatValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutHeightValue_matchRefExact(const AzLayoutHeightValue* value, const AzLayoutHeight** restrict out) {
    const AzLayoutHeightValueVariant_Exact* casted = (const AzLayoutHeightValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutHeightValue_matchMutExact(AzLayoutHeightValue* restrict value, AzLayoutHeight* restrict * restrict out) {
    AzLayoutHeightValueVariant_Exact* restrict casted = (AzLayoutHeightValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutJustifyContentValue_matchRefExact(const AzLayoutJustifyContentValue* value, const AzLayoutJustifyContent** restrict out) {
    const AzLayoutJustifyContentValueVariant_Exact* casted = (const AzLayoutJustifyContentValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutJustifyContentValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutJustifyContentValue_matchMutExact(AzLayoutJustifyContentValue* restrict value, AzLayoutJustifyContent* restrict * restrict out) {
    AzLayoutJustifyContentValueVariant_Exact* restrict casted = (AzLayoutJustifyContentValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutJustifyContentValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutLeftValue_matchRefExact(const AzLayoutLeftValue* value, const AzLayoutLeft** restrict out) {
    const AzLayoutLeftValueVariant_Exact* casted = (const AzLayoutLeftValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutLeftValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutLeftValue_matchMutExact(AzLayoutLeftValue* restrict value, AzLayoutLeft* restrict * restrict out) {
    AzLayoutLeftValueVariant_Exact* restrict casted = (AzLayoutLeftValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutLeftValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginBottomValue_matchRefExact(const AzLayoutMarginBottomValue* value, const AzLayoutMarginBottom** restrict out) {
    const AzLayoutMarginBottomValueVariant_Exact* casted = (const AzLayoutMarginBottomValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMarginBottomValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginBottomValue_matchMutExact(AzLayoutMarginBottomValue* restrict value, AzLayoutMarginBottom* restrict * restrict out) {
    AzLayoutMarginBottomValueVariant_Exact* restrict casted = (AzLayoutMarginBottomValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMarginBottomValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginLeftValue_matchRefExact(const AzLayoutMarginLeftValue* value, const AzLayoutMarginLeft** restrict out) {
    const AzLayoutMarginLeftValueVariant_Exact* casted = (const AzLayoutMarginLeftValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMarginLeftValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginLeftValue_matchMutExact(AzLayoutMarginLeftValue* restrict value, AzLayoutMarginLeft* restrict * restrict out) {
    AzLayoutMarginLeftValueVariant_Exact* restrict casted = (AzLayoutMarginLeftValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMarginLeftValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginRightValue_matchRefExact(const AzLayoutMarginRightValue* value, const AzLayoutMarginRight** restrict out) {
    const AzLayoutMarginRightValueVariant_Exact* casted = (const AzLayoutMarginRightValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMarginRightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginRightValue_matchMutExact(AzLayoutMarginRightValue* restrict value, AzLayoutMarginRight* restrict * restrict out) {
    AzLayoutMarginRightValueVariant_Exact* restrict casted = (AzLayoutMarginRightValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMarginRightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginTopValue_matchRefExact(const AzLayoutMarginTopValue* value, const AzLayoutMarginTop** restrict out) {
    const AzLayoutMarginTopValueVariant_Exact* casted = (const AzLayoutMarginTopValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMarginTopValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMarginTopValue_matchMutExact(AzLayoutMarginTopValue* restrict value, AzLayoutMarginTop* restrict * restrict out) {
    AzLayoutMarginTopValueVariant_Exact* restrict casted = (AzLayoutMarginTopValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMarginTopValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMaxHeightValue_matchRefExact(const AzLayoutMaxHeightValue* value, const AzLayoutMaxHeight** restrict out) {
    const AzLayoutMaxHeightValueVariant_Exact* casted = (const AzLayoutMaxHeightValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMaxHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMaxHeightValue_matchMutExact(AzLayoutMaxHeightValue* restrict value, AzLayoutMaxHeight* restrict * restrict out) {
    AzLayoutMaxHeightValueVariant_Exact* restrict casted = (AzLayoutMaxHeightValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMaxHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMaxWidthValue_matchRefExact(const AzLayoutMaxWidthValue* value, const AzLayoutMaxWidth** restrict out) {
    const AzLayoutMaxWidthValueVariant_Exact* casted = (const AzLayoutMaxWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMaxWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMaxWidthValue_matchMutExact(AzLayoutMaxWidthValue* restrict value, AzLayoutMaxWidth* restrict * restrict out) {
    AzLayoutMaxWidthValueVariant_Exact* restrict casted = (AzLayoutMaxWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMaxWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMinHeightValue_matchRefExact(const AzLayoutMinHeightValue* value, const AzLayoutMinHeight** restrict out) {
    const AzLayoutMinHeightValueVariant_Exact* casted = (const AzLayoutMinHeightValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMinHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMinHeightValue_matchMutExact(AzLayoutMinHeightValue* restrict value, AzLayoutMinHeight* restrict * restrict out) {
    AzLayoutMinHeightValueVariant_Exact* restrict casted = (AzLayoutMinHeightValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMinHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMinWidthValue_matchRefExact(const AzLayoutMinWidthValue* value, const AzLayoutMinWidth** restrict out) {
    const AzLayoutMinWidthValueVariant_Exact* casted = (const AzLayoutMinWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutMinWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutMinWidthValue_matchMutExact(AzLayoutMinWidthValue* restrict value, AzLayoutMinWidth* restrict * restrict out) {
    AzLayoutMinWidthValueVariant_Exact* restrict casted = (AzLayoutMinWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutMinWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingBottomValue_matchRefExact(const AzLayoutPaddingBottomValue* value, const AzLayoutPaddingBottom** restrict out) {
    const AzLayoutPaddingBottomValueVariant_Exact* casted = (const AzLayoutPaddingBottomValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutPaddingBottomValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingBottomValue_matchMutExact(AzLayoutPaddingBottomValue* restrict value, AzLayoutPaddingBottom* restrict * restrict out) {
    AzLayoutPaddingBottomValueVariant_Exact* restrict casted = (AzLayoutPaddingBottomValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutPaddingBottomValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingLeftValue_matchRefExact(const AzLayoutPaddingLeftValue* value, const AzLayoutPaddingLeft** restrict out) {
    const AzLayoutPaddingLeftValueVariant_Exact* casted = (const AzLayoutPaddingLeftValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutPaddingLeftValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingLeftValue_matchMutExact(AzLayoutPaddingLeftValue* restrict value, AzLayoutPaddingLeft* restrict * restrict out) {
    AzLayoutPaddingLeftValueVariant_Exact* restrict casted = (AzLayoutPaddingLeftValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutPaddingLeftValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingRightValue_matchRefExact(const AzLayoutPaddingRightValue* value, const AzLayoutPaddingRight** restrict out) {
    const AzLayoutPaddingRightValueVariant_Exact* casted = (const AzLayoutPaddingRightValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutPaddingRightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingRightValue_matchMutExact(AzLayoutPaddingRightValue* restrict value, AzLayoutPaddingRight* restrict * restrict out) {
    AzLayoutPaddingRightValueVariant_Exact* restrict casted = (AzLayoutPaddingRightValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutPaddingRightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingTopValue_matchRefExact(const AzLayoutPaddingTopValue* value, const AzLayoutPaddingTop** restrict out) {
    const AzLayoutPaddingTopValueVariant_Exact* casted = (const AzLayoutPaddingTopValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutPaddingTopValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPaddingTopValue_matchMutExact(AzLayoutPaddingTopValue* restrict value, AzLayoutPaddingTop* restrict * restrict out) {
    AzLayoutPaddingTopValueVariant_Exact* restrict casted = (AzLayoutPaddingTopValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutPaddingTopValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPositionValue_matchRefExact(const AzLayoutPositionValue* value, const AzLayoutPosition** restrict out) {
    const AzLayoutPositionValueVariant_Exact* casted = (const AzLayoutPositionValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutPositionValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutPositionValue_matchMutExact(AzLayoutPositionValue* restrict value, AzLayoutPosition* restrict * restrict out) {
    AzLayoutPositionValueVariant_Exact* restrict casted = (AzLayoutPositionValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutPositionValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutRightValue_matchRefExact(const AzLayoutRightValue* value, const AzLayoutRight** restrict out) {
    const AzLayoutRightValueVariant_Exact* casted = (const AzLayoutRightValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutRightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutRightValue_matchMutExact(AzLayoutRightValue* restrict value, AzLayoutRight* restrict * restrict out) {
    AzLayoutRightValueVariant_Exact* restrict casted = (AzLayoutRightValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutRightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutTopValue_matchRefExact(const AzLayoutTopValue* value, const AzLayoutTop** restrict out) {
    const AzLayoutTopValueVariant_Exact* casted = (const AzLayoutTopValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutTopValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutTopValue_matchMutExact(AzLayoutTopValue* restrict value, AzLayoutTop* restrict * restrict out) {
    AzLayoutTopValueVariant_Exact* restrict casted = (AzLayoutTopValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutTopValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutWidthValue_matchRefExact(const AzLayoutWidthValue* value, const AzLayoutWidth** restrict out) {
    const AzLayoutWidthValueVariant_Exact* casted = (const AzLayoutWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutWidthValue_matchMutExact(AzLayoutWidthValue* restrict value, AzLayoutWidth* restrict * restrict out) {
    AzLayoutWidthValueVariant_Exact* restrict casted = (AzLayoutWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexWrapValue_matchRefExact(const AzLayoutFlexWrapValue* value, const AzLayoutFlexWrap** restrict out) {
    const AzLayoutFlexWrapValueVariant_Exact* casted = (const AzLayoutFlexWrapValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutFlexWrapValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutFlexWrapValue_matchMutExact(AzLayoutFlexWrapValue* restrict value, AzLayoutFlexWrap* restrict * restrict out) {
    AzLayoutFlexWrapValueVariant_Exact* restrict casted = (AzLayoutFlexWrapValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutFlexWrapValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutOverflowValue_matchRefExact(const AzLayoutOverflowValue* value, const AzLayoutOverflow** restrict out) {
    const AzLayoutOverflowValueVariant_Exact* casted = (const AzLayoutOverflowValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutOverflowValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutOverflowValue_matchMutExact(AzLayoutOverflowValue* restrict value, AzLayoutOverflow* restrict * restrict out) {
    AzLayoutOverflowValueVariant_Exact* restrict casted = (AzLayoutOverflowValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutOverflowValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzScrollbarStyleValue_matchRefExact(const AzScrollbarStyleValue* value, const AzScrollbarStyle** restrict out) {
    const AzScrollbarStyleValueVariant_Exact* casted = (const AzScrollbarStyleValueVariant_Exact*)value;
    bool valid = casted->tag == AzScrollbarStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzScrollbarStyleValue_matchMutExact(AzScrollbarStyleValue* restrict value, AzScrollbarStyle* restrict * restrict out) {
    AzScrollbarStyleValueVariant_Exact* restrict casted = (AzScrollbarStyleValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzScrollbarStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContentVecValue_matchRefExact(const AzStyleBackgroundContentVecValue* value, const AzStyleBackgroundContentVec** restrict out) {
    const AzStyleBackgroundContentVecValueVariant_Exact* casted = (const AzStyleBackgroundContentVecValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBackgroundContentVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContentVecValue_matchMutExact(AzStyleBackgroundContentVecValue* restrict value, AzStyleBackgroundContentVec* restrict * restrict out) {
    AzStyleBackgroundContentVecValueVariant_Exact* restrict casted = (AzStyleBackgroundContentVecValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundContentVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundPositionVecValue_matchRefExact(const AzStyleBackgroundPositionVecValue* value, const AzStyleBackgroundPositionVec** restrict out) {
    const AzStyleBackgroundPositionVecValueVariant_Exact* casted = (const AzStyleBackgroundPositionVecValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBackgroundPositionVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundPositionVecValue_matchMutExact(AzStyleBackgroundPositionVecValue* restrict value, AzStyleBackgroundPositionVec* restrict * restrict out) {
    AzStyleBackgroundPositionVecValueVariant_Exact* restrict casted = (AzStyleBackgroundPositionVecValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundPositionVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundRepeatVecValue_matchRefExact(const AzStyleBackgroundRepeatVecValue* value, const AzStyleBackgroundRepeatVec** restrict out) {
    const AzStyleBackgroundRepeatVecValueVariant_Exact* casted = (const AzStyleBackgroundRepeatVecValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBackgroundRepeatVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundRepeatVecValue_matchMutExact(AzStyleBackgroundRepeatVecValue* restrict value, AzStyleBackgroundRepeatVec* restrict * restrict out) {
    AzStyleBackgroundRepeatVecValueVariant_Exact* restrict casted = (AzStyleBackgroundRepeatVecValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundRepeatVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundSizeVecValue_matchRefExact(const AzStyleBackgroundSizeVecValue* value, const AzStyleBackgroundSizeVec** restrict out) {
    const AzStyleBackgroundSizeVecValueVariant_Exact* casted = (const AzStyleBackgroundSizeVecValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBackgroundSizeVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundSizeVecValue_matchMutExact(AzStyleBackgroundSizeVecValue* restrict value, AzStyleBackgroundSizeVec* restrict * restrict out) {
    AzStyleBackgroundSizeVecValueVariant_Exact* restrict casted = (AzStyleBackgroundSizeVecValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundSizeVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomColorValue_matchRefExact(const AzStyleBorderBottomColorValue* value, const AzStyleBorderBottomColor** restrict out) {
    const AzStyleBorderBottomColorValueVariant_Exact* casted = (const AzStyleBorderBottomColorValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderBottomColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomColorValue_matchMutExact(AzStyleBorderBottomColorValue* restrict value, AzStyleBorderBottomColor* restrict * restrict out) {
    AzStyleBorderBottomColorValueVariant_Exact* restrict casted = (AzStyleBorderBottomColorValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderBottomColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomLeftRadiusValue_matchRefExact(const AzStyleBorderBottomLeftRadiusValue* value, const AzStyleBorderBottomLeftRadius** restrict out) {
    const AzStyleBorderBottomLeftRadiusValueVariant_Exact* casted = (const AzStyleBorderBottomLeftRadiusValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderBottomLeftRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomLeftRadiusValue_matchMutExact(AzStyleBorderBottomLeftRadiusValue* restrict value, AzStyleBorderBottomLeftRadius* restrict * restrict out) {
    AzStyleBorderBottomLeftRadiusValueVariant_Exact* restrict casted = (AzStyleBorderBottomLeftRadiusValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderBottomLeftRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomRightRadiusValue_matchRefExact(const AzStyleBorderBottomRightRadiusValue* value, const AzStyleBorderBottomRightRadius** restrict out) {
    const AzStyleBorderBottomRightRadiusValueVariant_Exact* casted = (const AzStyleBorderBottomRightRadiusValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderBottomRightRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomRightRadiusValue_matchMutExact(AzStyleBorderBottomRightRadiusValue* restrict value, AzStyleBorderBottomRightRadius* restrict * restrict out) {
    AzStyleBorderBottomRightRadiusValueVariant_Exact* restrict casted = (AzStyleBorderBottomRightRadiusValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderBottomRightRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomStyleValue_matchRefExact(const AzStyleBorderBottomStyleValue* value, const AzStyleBorderBottomStyle** restrict out) {
    const AzStyleBorderBottomStyleValueVariant_Exact* casted = (const AzStyleBorderBottomStyleValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderBottomStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderBottomStyleValue_matchMutExact(AzStyleBorderBottomStyleValue* restrict value, AzStyleBorderBottomStyle* restrict * restrict out) {
    AzStyleBorderBottomStyleValueVariant_Exact* restrict casted = (AzStyleBorderBottomStyleValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderBottomStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderBottomWidthValue_matchRefExact(const AzLayoutBorderBottomWidthValue* value, const AzLayoutBorderBottomWidth** restrict out) {
    const AzLayoutBorderBottomWidthValueVariant_Exact* casted = (const AzLayoutBorderBottomWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutBorderBottomWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderBottomWidthValue_matchMutExact(AzLayoutBorderBottomWidthValue* restrict value, AzLayoutBorderBottomWidth* restrict * restrict out) {
    AzLayoutBorderBottomWidthValueVariant_Exact* restrict casted = (AzLayoutBorderBottomWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutBorderBottomWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderLeftColorValue_matchRefExact(const AzStyleBorderLeftColorValue* value, const AzStyleBorderLeftColor** restrict out) {
    const AzStyleBorderLeftColorValueVariant_Exact* casted = (const AzStyleBorderLeftColorValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderLeftColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderLeftColorValue_matchMutExact(AzStyleBorderLeftColorValue* restrict value, AzStyleBorderLeftColor* restrict * restrict out) {
    AzStyleBorderLeftColorValueVariant_Exact* restrict casted = (AzStyleBorderLeftColorValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderLeftColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderLeftStyleValue_matchRefExact(const AzStyleBorderLeftStyleValue* value, const AzStyleBorderLeftStyle** restrict out) {
    const AzStyleBorderLeftStyleValueVariant_Exact* casted = (const AzStyleBorderLeftStyleValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderLeftStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderLeftStyleValue_matchMutExact(AzStyleBorderLeftStyleValue* restrict value, AzStyleBorderLeftStyle* restrict * restrict out) {
    AzStyleBorderLeftStyleValueVariant_Exact* restrict casted = (AzStyleBorderLeftStyleValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderLeftStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderLeftWidthValue_matchRefExact(const AzLayoutBorderLeftWidthValue* value, const AzLayoutBorderLeftWidth** restrict out) {
    const AzLayoutBorderLeftWidthValueVariant_Exact* casted = (const AzLayoutBorderLeftWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutBorderLeftWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderLeftWidthValue_matchMutExact(AzLayoutBorderLeftWidthValue* restrict value, AzLayoutBorderLeftWidth* restrict * restrict out) {
    AzLayoutBorderLeftWidthValueVariant_Exact* restrict casted = (AzLayoutBorderLeftWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutBorderLeftWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderRightColorValue_matchRefExact(const AzStyleBorderRightColorValue* value, const AzStyleBorderRightColor** restrict out) {
    const AzStyleBorderRightColorValueVariant_Exact* casted = (const AzStyleBorderRightColorValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderRightColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderRightColorValue_matchMutExact(AzStyleBorderRightColorValue* restrict value, AzStyleBorderRightColor* restrict * restrict out) {
    AzStyleBorderRightColorValueVariant_Exact* restrict casted = (AzStyleBorderRightColorValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderRightColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderRightStyleValue_matchRefExact(const AzStyleBorderRightStyleValue* value, const AzStyleBorderRightStyle** restrict out) {
    const AzStyleBorderRightStyleValueVariant_Exact* casted = (const AzStyleBorderRightStyleValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderRightStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderRightStyleValue_matchMutExact(AzStyleBorderRightStyleValue* restrict value, AzStyleBorderRightStyle* restrict * restrict out) {
    AzStyleBorderRightStyleValueVariant_Exact* restrict casted = (AzStyleBorderRightStyleValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderRightStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderRightWidthValue_matchRefExact(const AzLayoutBorderRightWidthValue* value, const AzLayoutBorderRightWidth** restrict out) {
    const AzLayoutBorderRightWidthValueVariant_Exact* casted = (const AzLayoutBorderRightWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutBorderRightWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderRightWidthValue_matchMutExact(AzLayoutBorderRightWidthValue* restrict value, AzLayoutBorderRightWidth* restrict * restrict out) {
    AzLayoutBorderRightWidthValueVariant_Exact* restrict casted = (AzLayoutBorderRightWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutBorderRightWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopColorValue_matchRefExact(const AzStyleBorderTopColorValue* value, const AzStyleBorderTopColor** restrict out) {
    const AzStyleBorderTopColorValueVariant_Exact* casted = (const AzStyleBorderTopColorValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderTopColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopColorValue_matchMutExact(AzStyleBorderTopColorValue* restrict value, AzStyleBorderTopColor* restrict * restrict out) {
    AzStyleBorderTopColorValueVariant_Exact* restrict casted = (AzStyleBorderTopColorValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderTopColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopLeftRadiusValue_matchRefExact(const AzStyleBorderTopLeftRadiusValue* value, const AzStyleBorderTopLeftRadius** restrict out) {
    const AzStyleBorderTopLeftRadiusValueVariant_Exact* casted = (const AzStyleBorderTopLeftRadiusValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderTopLeftRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopLeftRadiusValue_matchMutExact(AzStyleBorderTopLeftRadiusValue* restrict value, AzStyleBorderTopLeftRadius* restrict * restrict out) {
    AzStyleBorderTopLeftRadiusValueVariant_Exact* restrict casted = (AzStyleBorderTopLeftRadiusValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderTopLeftRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopRightRadiusValue_matchRefExact(const AzStyleBorderTopRightRadiusValue* value, const AzStyleBorderTopRightRadius** restrict out) {
    const AzStyleBorderTopRightRadiusValueVariant_Exact* casted = (const AzStyleBorderTopRightRadiusValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderTopRightRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopRightRadiusValue_matchMutExact(AzStyleBorderTopRightRadiusValue* restrict value, AzStyleBorderTopRightRadius* restrict * restrict out) {
    AzStyleBorderTopRightRadiusValueVariant_Exact* restrict casted = (AzStyleBorderTopRightRadiusValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderTopRightRadiusValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopStyleValue_matchRefExact(const AzStyleBorderTopStyleValue* value, const AzStyleBorderTopStyle** restrict out) {
    const AzStyleBorderTopStyleValueVariant_Exact* casted = (const AzStyleBorderTopStyleValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBorderTopStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBorderTopStyleValue_matchMutExact(AzStyleBorderTopStyleValue* restrict value, AzStyleBorderTopStyle* restrict * restrict out) {
    AzStyleBorderTopStyleValueVariant_Exact* restrict casted = (AzStyleBorderTopStyleValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBorderTopStyleValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderTopWidthValue_matchRefExact(const AzLayoutBorderTopWidthValue* value, const AzLayoutBorderTopWidth** restrict out) {
    const AzLayoutBorderTopWidthValueVariant_Exact* casted = (const AzLayoutBorderTopWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzLayoutBorderTopWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzLayoutBorderTopWidthValue_matchMutExact(AzLayoutBorderTopWidthValue* restrict value, AzLayoutBorderTopWidth* restrict * restrict out) {
    AzLayoutBorderTopWidthValueVariant_Exact* restrict casted = (AzLayoutBorderTopWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzLayoutBorderTopWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleCursorValue_matchRefExact(const AzStyleCursorValue* value, const AzStyleCursor** restrict out) {
    const AzStyleCursorValueVariant_Exact* casted = (const AzStyleCursorValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleCursorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleCursorValue_matchMutExact(AzStyleCursorValue* restrict value, AzStyleCursor* restrict * restrict out) {
    AzStyleCursorValueVariant_Exact* restrict casted = (AzStyleCursorValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleCursorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamilyVecValue_matchRefExact(const AzStyleFontFamilyVecValue* value, const AzStyleFontFamilyVec** restrict out) {
    const AzStyleFontFamilyVecValueVariant_Exact* casted = (const AzStyleFontFamilyVecValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleFontFamilyVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamilyVecValue_matchMutExact(AzStyleFontFamilyVecValue* restrict value, AzStyleFontFamilyVec* restrict * restrict out) {
    AzStyleFontFamilyVecValueVariant_Exact* restrict casted = (AzStyleFontFamilyVecValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleFontFamilyVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontSizeValue_matchRefExact(const AzStyleFontSizeValue* value, const AzStyleFontSize** restrict out) {
    const AzStyleFontSizeValueVariant_Exact* casted = (const AzStyleFontSizeValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleFontSizeValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontSizeValue_matchMutExact(AzStyleFontSizeValue* restrict value, AzStyleFontSize* restrict * restrict out) {
    AzStyleFontSizeValueVariant_Exact* restrict casted = (AzStyleFontSizeValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleFontSizeValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleLetterSpacingValue_matchRefExact(const AzStyleLetterSpacingValue* value, const AzStyleLetterSpacing** restrict out) {
    const AzStyleLetterSpacingValueVariant_Exact* casted = (const AzStyleLetterSpacingValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleLetterSpacingValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleLetterSpacingValue_matchMutExact(AzStyleLetterSpacingValue* restrict value, AzStyleLetterSpacing* restrict * restrict out) {
    AzStyleLetterSpacingValueVariant_Exact* restrict casted = (AzStyleLetterSpacingValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleLetterSpacingValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleLineHeightValue_matchRefExact(const AzStyleLineHeightValue* value, const AzStyleLineHeight** restrict out) {
    const AzStyleLineHeightValueVariant_Exact* casted = (const AzStyleLineHeightValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleLineHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleLineHeightValue_matchMutExact(AzStyleLineHeightValue* restrict value, AzStyleLineHeight* restrict * restrict out) {
    AzStyleLineHeightValueVariant_Exact* restrict casted = (AzStyleLineHeightValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleLineHeightValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTabWidthValue_matchRefExact(const AzStyleTabWidthValue* value, const AzStyleTabWidth** restrict out) {
    const AzStyleTabWidthValueVariant_Exact* casted = (const AzStyleTabWidthValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleTabWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTabWidthValue_matchMutExact(AzStyleTabWidthValue* restrict value, AzStyleTabWidth* restrict * restrict out) {
    AzStyleTabWidthValueVariant_Exact* restrict casted = (AzStyleTabWidthValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleTabWidthValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTextAlignValue_matchRefExact(const AzStyleTextAlignValue* value, const AzStyleTextAlign** restrict out) {
    const AzStyleTextAlignValueVariant_Exact* casted = (const AzStyleTextAlignValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleTextAlignValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTextAlignValue_matchMutExact(AzStyleTextAlignValue* restrict value, AzStyleTextAlign* restrict * restrict out) {
    AzStyleTextAlignValueVariant_Exact* restrict casted = (AzStyleTextAlignValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleTextAlignValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTextColorValue_matchRefExact(const AzStyleTextColorValue* value, const AzStyleTextColor** restrict out) {
    const AzStyleTextColorValueVariant_Exact* casted = (const AzStyleTextColorValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleTextColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTextColorValue_matchMutExact(AzStyleTextColorValue* restrict value, AzStyleTextColor* restrict * restrict out) {
    AzStyleTextColorValueVariant_Exact* restrict casted = (AzStyleTextColorValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleTextColorValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleWordSpacingValue_matchRefExact(const AzStyleWordSpacingValue* value, const AzStyleWordSpacing** restrict out) {
    const AzStyleWordSpacingValueVariant_Exact* casted = (const AzStyleWordSpacingValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleWordSpacingValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleWordSpacingValue_matchMutExact(AzStyleWordSpacingValue* restrict value, AzStyleWordSpacing* restrict * restrict out) {
    AzStyleWordSpacingValueVariant_Exact* restrict casted = (AzStyleWordSpacingValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleWordSpacingValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleOpacityValue_matchRefExact(const AzStyleOpacityValue* value, const AzStyleOpacity** restrict out) {
    const AzStyleOpacityValueVariant_Exact* casted = (const AzStyleOpacityValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleOpacityValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleOpacityValue_matchMutExact(AzStyleOpacityValue* restrict value, AzStyleOpacity* restrict * restrict out) {
    AzStyleOpacityValueVariant_Exact* restrict casted = (AzStyleOpacityValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleOpacityValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransformVecValue_matchRefExact(const AzStyleTransformVecValue* value, const AzStyleTransformVec** restrict out) {
    const AzStyleTransformVecValueVariant_Exact* casted = (const AzStyleTransformVecValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleTransformVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransformVecValue_matchMutExact(AzStyleTransformVecValue* restrict value, AzStyleTransformVec* restrict * restrict out) {
    AzStyleTransformVecValueVariant_Exact* restrict casted = (AzStyleTransformVecValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleTransformVecValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransformOriginValue_matchRefExact(const AzStyleTransformOriginValue* value, const AzStyleTransformOrigin** restrict out) {
    const AzStyleTransformOriginValueVariant_Exact* casted = (const AzStyleTransformOriginValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleTransformOriginValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransformOriginValue_matchMutExact(AzStyleTransformOriginValue* restrict value, AzStyleTransformOrigin* restrict * restrict out) {
    AzStyleTransformOriginValueVariant_Exact* restrict casted = (AzStyleTransformOriginValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleTransformOriginValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStylePerspectiveOriginValue_matchRefExact(const AzStylePerspectiveOriginValue* value, const AzStylePerspectiveOrigin** restrict out) {
    const AzStylePerspectiveOriginValueVariant_Exact* casted = (const AzStylePerspectiveOriginValueVariant_Exact*)value;
    bool valid = casted->tag == AzStylePerspectiveOriginValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStylePerspectiveOriginValue_matchMutExact(AzStylePerspectiveOriginValue* restrict value, AzStylePerspectiveOrigin* restrict * restrict out) {
    AzStylePerspectiveOriginValueVariant_Exact* restrict casted = (AzStylePerspectiveOriginValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStylePerspectiveOriginValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackfaceVisibilityValue_matchRefExact(const AzStyleBackfaceVisibilityValue* value, const AzStyleBackfaceVisibility** restrict out) {
    const AzStyleBackfaceVisibilityValueVariant_Exact* casted = (const AzStyleBackfaceVisibilityValueVariant_Exact*)value;
    bool valid = casted->tag == AzStyleBackfaceVisibilityValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackfaceVisibilityValue_matchMutExact(AzStyleBackfaceVisibilityValue* restrict value, AzStyleBackfaceVisibility* restrict * restrict out) {
    AzStyleBackfaceVisibilityValueVariant_Exact* restrict casted = (AzStyleBackfaceVisibilityValueVariant_Exact* restrict)value;
    bool valid = casted->tag == AzStyleBackfaceVisibilityValueTag_Exact;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefTextColor(const AzCssProperty* value, const AzStyleTextColorValue** restrict out) {
    const AzCssPropertyVariant_TextColor* casted = (const AzCssPropertyVariant_TextColor*)value;
    bool valid = casted->tag == AzCssPropertyTag_TextColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutTextColor(AzCssProperty* restrict value, AzStyleTextColorValue* restrict * restrict out) {
    AzCssPropertyVariant_TextColor* restrict casted = (AzCssPropertyVariant_TextColor* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_TextColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefFontSize(const AzCssProperty* value, const AzStyleFontSizeValue** restrict out) {
    const AzCssPropertyVariant_FontSize* casted = (const AzCssPropertyVariant_FontSize*)value;
    bool valid = casted->tag == AzCssPropertyTag_FontSize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutFontSize(AzCssProperty* restrict value, AzStyleFontSizeValue* restrict * restrict out) {
    AzCssPropertyVariant_FontSize* restrict casted = (AzCssPropertyVariant_FontSize* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_FontSize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefFontFamily(const AzCssProperty* value, const AzStyleFontFamilyVecValue** restrict out) {
    const AzCssPropertyVariant_FontFamily* casted = (const AzCssPropertyVariant_FontFamily*)value;
    bool valid = casted->tag == AzCssPropertyTag_FontFamily;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutFontFamily(AzCssProperty* restrict value, AzStyleFontFamilyVecValue* restrict * restrict out) {
    AzCssPropertyVariant_FontFamily* restrict casted = (AzCssPropertyVariant_FontFamily* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_FontFamily;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefTextAlign(const AzCssProperty* value, const AzStyleTextAlignValue** restrict out) {
    const AzCssPropertyVariant_TextAlign* casted = (const AzCssPropertyVariant_TextAlign*)value;
    bool valid = casted->tag == AzCssPropertyTag_TextAlign;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutTextAlign(AzCssProperty* restrict value, AzStyleTextAlignValue* restrict * restrict out) {
    AzCssPropertyVariant_TextAlign* restrict casted = (AzCssPropertyVariant_TextAlign* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_TextAlign;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefLetterSpacing(const AzCssProperty* value, const AzStyleLetterSpacingValue** restrict out) {
    const AzCssPropertyVariant_LetterSpacing* casted = (const AzCssPropertyVariant_LetterSpacing*)value;
    bool valid = casted->tag == AzCssPropertyTag_LetterSpacing;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutLetterSpacing(AzCssProperty* restrict value, AzStyleLetterSpacingValue* restrict * restrict out) {
    AzCssPropertyVariant_LetterSpacing* restrict casted = (AzCssPropertyVariant_LetterSpacing* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_LetterSpacing;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefLineHeight(const AzCssProperty* value, const AzStyleLineHeightValue** restrict out) {
    const AzCssPropertyVariant_LineHeight* casted = (const AzCssPropertyVariant_LineHeight*)value;
    bool valid = casted->tag == AzCssPropertyTag_LineHeight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutLineHeight(AzCssProperty* restrict value, AzStyleLineHeightValue* restrict * restrict out) {
    AzCssPropertyVariant_LineHeight* restrict casted = (AzCssPropertyVariant_LineHeight* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_LineHeight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefWordSpacing(const AzCssProperty* value, const AzStyleWordSpacingValue** restrict out) {
    const AzCssPropertyVariant_WordSpacing* casted = (const AzCssPropertyVariant_WordSpacing*)value;
    bool valid = casted->tag == AzCssPropertyTag_WordSpacing;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutWordSpacing(AzCssProperty* restrict value, AzStyleWordSpacingValue* restrict * restrict out) {
    AzCssPropertyVariant_WordSpacing* restrict casted = (AzCssPropertyVariant_WordSpacing* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_WordSpacing;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefTabWidth(const AzCssProperty* value, const AzStyleTabWidthValue** restrict out) {
    const AzCssPropertyVariant_TabWidth* casted = (const AzCssPropertyVariant_TabWidth*)value;
    bool valid = casted->tag == AzCssPropertyTag_TabWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutTabWidth(AzCssProperty* restrict value, AzStyleTabWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_TabWidth* restrict casted = (AzCssPropertyVariant_TabWidth* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_TabWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefCursor(const AzCssProperty* value, const AzStyleCursorValue** restrict out) {
    const AzCssPropertyVariant_Cursor* casted = (const AzCssPropertyVariant_Cursor*)value;
    bool valid = casted->tag == AzCssPropertyTag_Cursor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutCursor(AzCssProperty* restrict value, AzStyleCursorValue* restrict * restrict out) {
    AzCssPropertyVariant_Cursor* restrict casted = (AzCssPropertyVariant_Cursor* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Cursor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefDisplay(const AzCssProperty* value, const AzLayoutDisplayValue** restrict out) {
    const AzCssPropertyVariant_Display* casted = (const AzCssPropertyVariant_Display*)value;
    bool valid = casted->tag == AzCssPropertyTag_Display;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutDisplay(AzCssProperty* restrict value, AzLayoutDisplayValue* restrict * restrict out) {
    AzCssPropertyVariant_Display* restrict casted = (AzCssPropertyVariant_Display* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Display;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefFloat(const AzCssProperty* value, const AzLayoutFloatValue** restrict out) {
    const AzCssPropertyVariant_Float* casted = (const AzCssPropertyVariant_Float*)value;
    bool valid = casted->tag == AzCssPropertyTag_Float;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutFloat(AzCssProperty* restrict value, AzLayoutFloatValue* restrict * restrict out) {
    AzCssPropertyVariant_Float* restrict casted = (AzCssPropertyVariant_Float* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Float;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBoxSizing(const AzCssProperty* value, const AzLayoutBoxSizingValue** restrict out) {
    const AzCssPropertyVariant_BoxSizing* casted = (const AzCssPropertyVariant_BoxSizing*)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxSizing;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBoxSizing(AzCssProperty* restrict value, AzLayoutBoxSizingValue* restrict * restrict out) {
    AzCssPropertyVariant_BoxSizing* restrict casted = (AzCssPropertyVariant_BoxSizing* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxSizing;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefWidth(const AzCssProperty* value, const AzLayoutWidthValue** restrict out) {
    const AzCssPropertyVariant_Width* casted = (const AzCssPropertyVariant_Width*)value;
    bool valid = casted->tag == AzCssPropertyTag_Width;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutWidth(AzCssProperty* restrict value, AzLayoutWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_Width* restrict casted = (AzCssPropertyVariant_Width* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Width;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefHeight(const AzCssProperty* value, const AzLayoutHeightValue** restrict out) {
    const AzCssPropertyVariant_Height* casted = (const AzCssPropertyVariant_Height*)value;
    bool valid = casted->tag == AzCssPropertyTag_Height;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutHeight(AzCssProperty* restrict value, AzLayoutHeightValue* restrict * restrict out) {
    AzCssPropertyVariant_Height* restrict casted = (AzCssPropertyVariant_Height* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Height;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMinWidth(const AzCssProperty* value, const AzLayoutMinWidthValue** restrict out) {
    const AzCssPropertyVariant_MinWidth* casted = (const AzCssPropertyVariant_MinWidth*)value;
    bool valid = casted->tag == AzCssPropertyTag_MinWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMinWidth(AzCssProperty* restrict value, AzLayoutMinWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_MinWidth* restrict casted = (AzCssPropertyVariant_MinWidth* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MinWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMinHeight(const AzCssProperty* value, const AzLayoutMinHeightValue** restrict out) {
    const AzCssPropertyVariant_MinHeight* casted = (const AzCssPropertyVariant_MinHeight*)value;
    bool valid = casted->tag == AzCssPropertyTag_MinHeight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMinHeight(AzCssProperty* restrict value, AzLayoutMinHeightValue* restrict * restrict out) {
    AzCssPropertyVariant_MinHeight* restrict casted = (AzCssPropertyVariant_MinHeight* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MinHeight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMaxWidth(const AzCssProperty* value, const AzLayoutMaxWidthValue** restrict out) {
    const AzCssPropertyVariant_MaxWidth* casted = (const AzCssPropertyVariant_MaxWidth*)value;
    bool valid = casted->tag == AzCssPropertyTag_MaxWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMaxWidth(AzCssProperty* restrict value, AzLayoutMaxWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_MaxWidth* restrict casted = (AzCssPropertyVariant_MaxWidth* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MaxWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMaxHeight(const AzCssProperty* value, const AzLayoutMaxHeightValue** restrict out) {
    const AzCssPropertyVariant_MaxHeight* casted = (const AzCssPropertyVariant_MaxHeight*)value;
    bool valid = casted->tag == AzCssPropertyTag_MaxHeight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMaxHeight(AzCssProperty* restrict value, AzLayoutMaxHeightValue* restrict * restrict out) {
    AzCssPropertyVariant_MaxHeight* restrict casted = (AzCssPropertyVariant_MaxHeight* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MaxHeight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefPosition(const AzCssProperty* value, const AzLayoutPositionValue** restrict out) {
    const AzCssPropertyVariant_Position* casted = (const AzCssPropertyVariant_Position*)value;
    bool valid = casted->tag == AzCssPropertyTag_Position;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutPosition(AzCssProperty* restrict value, AzLayoutPositionValue* restrict * restrict out) {
    AzCssPropertyVariant_Position* restrict casted = (AzCssPropertyVariant_Position* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Position;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefTop(const AzCssProperty* value, const AzLayoutTopValue** restrict out) {
    const AzCssPropertyVariant_Top* casted = (const AzCssPropertyVariant_Top*)value;
    bool valid = casted->tag == AzCssPropertyTag_Top;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutTop(AzCssProperty* restrict value, AzLayoutTopValue* restrict * restrict out) {
    AzCssPropertyVariant_Top* restrict casted = (AzCssPropertyVariant_Top* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Top;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefRight(const AzCssProperty* value, const AzLayoutRightValue** restrict out) {
    const AzCssPropertyVariant_Right* casted = (const AzCssPropertyVariant_Right*)value;
    bool valid = casted->tag == AzCssPropertyTag_Right;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutRight(AzCssProperty* restrict value, AzLayoutRightValue* restrict * restrict out) {
    AzCssPropertyVariant_Right* restrict casted = (AzCssPropertyVariant_Right* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Right;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefLeft(const AzCssProperty* value, const AzLayoutLeftValue** restrict out) {
    const AzCssPropertyVariant_Left* casted = (const AzCssPropertyVariant_Left*)value;
    bool valid = casted->tag == AzCssPropertyTag_Left;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutLeft(AzCssProperty* restrict value, AzLayoutLeftValue* restrict * restrict out) {
    AzCssPropertyVariant_Left* restrict casted = (AzCssPropertyVariant_Left* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Left;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBottom(const AzCssProperty* value, const AzLayoutBottomValue** restrict out) {
    const AzCssPropertyVariant_Bottom* casted = (const AzCssPropertyVariant_Bottom*)value;
    bool valid = casted->tag == AzCssPropertyTag_Bottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBottom(AzCssProperty* restrict value, AzLayoutBottomValue* restrict * restrict out) {
    AzCssPropertyVariant_Bottom* restrict casted = (AzCssPropertyVariant_Bottom* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Bottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefFlexWrap(const AzCssProperty* value, const AzLayoutFlexWrapValue** restrict out) {
    const AzCssPropertyVariant_FlexWrap* casted = (const AzCssPropertyVariant_FlexWrap*)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexWrap;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutFlexWrap(AzCssProperty* restrict value, AzLayoutFlexWrapValue* restrict * restrict out) {
    AzCssPropertyVariant_FlexWrap* restrict casted = (AzCssPropertyVariant_FlexWrap* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexWrap;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefFlexDirection(const AzCssProperty* value, const AzLayoutFlexDirectionValue** restrict out) {
    const AzCssPropertyVariant_FlexDirection* casted = (const AzCssPropertyVariant_FlexDirection*)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexDirection;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutFlexDirection(AzCssProperty* restrict value, AzLayoutFlexDirectionValue* restrict * restrict out) {
    AzCssPropertyVariant_FlexDirection* restrict casted = (AzCssPropertyVariant_FlexDirection* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexDirection;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefFlexGrow(const AzCssProperty* value, const AzLayoutFlexGrowValue** restrict out) {
    const AzCssPropertyVariant_FlexGrow* casted = (const AzCssPropertyVariant_FlexGrow*)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexGrow;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutFlexGrow(AzCssProperty* restrict value, AzLayoutFlexGrowValue* restrict * restrict out) {
    AzCssPropertyVariant_FlexGrow* restrict casted = (AzCssPropertyVariant_FlexGrow* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexGrow;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefFlexShrink(const AzCssProperty* value, const AzLayoutFlexShrinkValue** restrict out) {
    const AzCssPropertyVariant_FlexShrink* casted = (const AzCssPropertyVariant_FlexShrink*)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexShrink;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutFlexShrink(AzCssProperty* restrict value, AzLayoutFlexShrinkValue* restrict * restrict out) {
    AzCssPropertyVariant_FlexShrink* restrict casted = (AzCssPropertyVariant_FlexShrink* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_FlexShrink;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefJustifyContent(const AzCssProperty* value, const AzLayoutJustifyContentValue** restrict out) {
    const AzCssPropertyVariant_JustifyContent* casted = (const AzCssPropertyVariant_JustifyContent*)value;
    bool valid = casted->tag == AzCssPropertyTag_JustifyContent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutJustifyContent(AzCssProperty* restrict value, AzLayoutJustifyContentValue* restrict * restrict out) {
    AzCssPropertyVariant_JustifyContent* restrict casted = (AzCssPropertyVariant_JustifyContent* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_JustifyContent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefAlignItems(const AzCssProperty* value, const AzLayoutAlignItemsValue** restrict out) {
    const AzCssPropertyVariant_AlignItems* casted = (const AzCssPropertyVariant_AlignItems*)value;
    bool valid = casted->tag == AzCssPropertyTag_AlignItems;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutAlignItems(AzCssProperty* restrict value, AzLayoutAlignItemsValue* restrict * restrict out) {
    AzCssPropertyVariant_AlignItems* restrict casted = (AzCssPropertyVariant_AlignItems* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_AlignItems;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefAlignContent(const AzCssProperty* value, const AzLayoutAlignContentValue** restrict out) {
    const AzCssPropertyVariant_AlignContent* casted = (const AzCssPropertyVariant_AlignContent*)value;
    bool valid = casted->tag == AzCssPropertyTag_AlignContent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutAlignContent(AzCssProperty* restrict value, AzLayoutAlignContentValue* restrict * restrict out) {
    AzCssPropertyVariant_AlignContent* restrict casted = (AzCssPropertyVariant_AlignContent* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_AlignContent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBackgroundContent(const AzCssProperty* value, const AzStyleBackgroundContentVecValue** restrict out) {
    const AzCssPropertyVariant_BackgroundContent* casted = (const AzCssPropertyVariant_BackgroundContent*)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundContent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBackgroundContent(AzCssProperty* restrict value, AzStyleBackgroundContentVecValue* restrict * restrict out) {
    AzCssPropertyVariant_BackgroundContent* restrict casted = (AzCssPropertyVariant_BackgroundContent* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundContent;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBackgroundPosition(const AzCssProperty* value, const AzStyleBackgroundPositionVecValue** restrict out) {
    const AzCssPropertyVariant_BackgroundPosition* casted = (const AzCssPropertyVariant_BackgroundPosition*)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundPosition;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBackgroundPosition(AzCssProperty* restrict value, AzStyleBackgroundPositionVecValue* restrict * restrict out) {
    AzCssPropertyVariant_BackgroundPosition* restrict casted = (AzCssPropertyVariant_BackgroundPosition* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundPosition;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBackgroundSize(const AzCssProperty* value, const AzStyleBackgroundSizeVecValue** restrict out) {
    const AzCssPropertyVariant_BackgroundSize* casted = (const AzCssPropertyVariant_BackgroundSize*)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundSize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBackgroundSize(AzCssProperty* restrict value, AzStyleBackgroundSizeVecValue* restrict * restrict out) {
    AzCssPropertyVariant_BackgroundSize* restrict casted = (AzCssPropertyVariant_BackgroundSize* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundSize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBackgroundRepeat(const AzCssProperty* value, const AzStyleBackgroundRepeatVecValue** restrict out) {
    const AzCssPropertyVariant_BackgroundRepeat* casted = (const AzCssPropertyVariant_BackgroundRepeat*)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundRepeat;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBackgroundRepeat(AzCssProperty* restrict value, AzStyleBackgroundRepeatVecValue* restrict * restrict out) {
    AzCssPropertyVariant_BackgroundRepeat* restrict casted = (AzCssPropertyVariant_BackgroundRepeat* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BackgroundRepeat;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefOverflowX(const AzCssProperty* value, const AzLayoutOverflowValue** restrict out) {
    const AzCssPropertyVariant_OverflowX* casted = (const AzCssPropertyVariant_OverflowX*)value;
    bool valid = casted->tag == AzCssPropertyTag_OverflowX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutOverflowX(AzCssProperty* restrict value, AzLayoutOverflowValue* restrict * restrict out) {
    AzCssPropertyVariant_OverflowX* restrict casted = (AzCssPropertyVariant_OverflowX* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_OverflowX;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefOverflowY(const AzCssProperty* value, const AzLayoutOverflowValue** restrict out) {
    const AzCssPropertyVariant_OverflowY* casted = (const AzCssPropertyVariant_OverflowY*)value;
    bool valid = casted->tag == AzCssPropertyTag_OverflowY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutOverflowY(AzCssProperty* restrict value, AzLayoutOverflowValue* restrict * restrict out) {
    AzCssPropertyVariant_OverflowY* restrict casted = (AzCssPropertyVariant_OverflowY* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_OverflowY;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefPaddingTop(const AzCssProperty* value, const AzLayoutPaddingTopValue** restrict out) {
    const AzCssPropertyVariant_PaddingTop* casted = (const AzCssPropertyVariant_PaddingTop*)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingTop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutPaddingTop(AzCssProperty* restrict value, AzLayoutPaddingTopValue* restrict * restrict out) {
    AzCssPropertyVariant_PaddingTop* restrict casted = (AzCssPropertyVariant_PaddingTop* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingTop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefPaddingLeft(const AzCssProperty* value, const AzLayoutPaddingLeftValue** restrict out) {
    const AzCssPropertyVariant_PaddingLeft* casted = (const AzCssPropertyVariant_PaddingLeft*)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingLeft;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutPaddingLeft(AzCssProperty* restrict value, AzLayoutPaddingLeftValue* restrict * restrict out) {
    AzCssPropertyVariant_PaddingLeft* restrict casted = (AzCssPropertyVariant_PaddingLeft* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingLeft;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefPaddingRight(const AzCssProperty* value, const AzLayoutPaddingRightValue** restrict out) {
    const AzCssPropertyVariant_PaddingRight* casted = (const AzCssPropertyVariant_PaddingRight*)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingRight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutPaddingRight(AzCssProperty* restrict value, AzLayoutPaddingRightValue* restrict * restrict out) {
    AzCssPropertyVariant_PaddingRight* restrict casted = (AzCssPropertyVariant_PaddingRight* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingRight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefPaddingBottom(const AzCssProperty* value, const AzLayoutPaddingBottomValue** restrict out) {
    const AzCssPropertyVariant_PaddingBottom* casted = (const AzCssPropertyVariant_PaddingBottom*)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingBottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutPaddingBottom(AzCssProperty* restrict value, AzLayoutPaddingBottomValue* restrict * restrict out) {
    AzCssPropertyVariant_PaddingBottom* restrict casted = (AzCssPropertyVariant_PaddingBottom* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_PaddingBottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMarginTop(const AzCssProperty* value, const AzLayoutMarginTopValue** restrict out) {
    const AzCssPropertyVariant_MarginTop* casted = (const AzCssPropertyVariant_MarginTop*)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginTop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMarginTop(AzCssProperty* restrict value, AzLayoutMarginTopValue* restrict * restrict out) {
    AzCssPropertyVariant_MarginTop* restrict casted = (AzCssPropertyVariant_MarginTop* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginTop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMarginLeft(const AzCssProperty* value, const AzLayoutMarginLeftValue** restrict out) {
    const AzCssPropertyVariant_MarginLeft* casted = (const AzCssPropertyVariant_MarginLeft*)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginLeft;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMarginLeft(AzCssProperty* restrict value, AzLayoutMarginLeftValue* restrict * restrict out) {
    AzCssPropertyVariant_MarginLeft* restrict casted = (AzCssPropertyVariant_MarginLeft* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginLeft;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMarginRight(const AzCssProperty* value, const AzLayoutMarginRightValue** restrict out) {
    const AzCssPropertyVariant_MarginRight* casted = (const AzCssPropertyVariant_MarginRight*)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginRight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMarginRight(AzCssProperty* restrict value, AzLayoutMarginRightValue* restrict * restrict out) {
    AzCssPropertyVariant_MarginRight* restrict casted = (AzCssPropertyVariant_MarginRight* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginRight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefMarginBottom(const AzCssProperty* value, const AzLayoutMarginBottomValue** restrict out) {
    const AzCssPropertyVariant_MarginBottom* casted = (const AzCssPropertyVariant_MarginBottom*)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginBottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutMarginBottom(AzCssProperty* restrict value, AzLayoutMarginBottomValue* restrict * restrict out) {
    AzCssPropertyVariant_MarginBottom* restrict casted = (AzCssPropertyVariant_MarginBottom* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_MarginBottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderTopLeftRadius(const AzCssProperty* value, const AzStyleBorderTopLeftRadiusValue** restrict out) {
    const AzCssPropertyVariant_BorderTopLeftRadius* casted = (const AzCssPropertyVariant_BorderTopLeftRadius*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopLeftRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderTopLeftRadius(AzCssProperty* restrict value, AzStyleBorderTopLeftRadiusValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderTopLeftRadius* restrict casted = (AzCssPropertyVariant_BorderTopLeftRadius* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopLeftRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderTopRightRadius(const AzCssProperty* value, const AzStyleBorderTopRightRadiusValue** restrict out) {
    const AzCssPropertyVariant_BorderTopRightRadius* casted = (const AzCssPropertyVariant_BorderTopRightRadius*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopRightRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderTopRightRadius(AzCssProperty* restrict value, AzStyleBorderTopRightRadiusValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderTopRightRadius* restrict casted = (AzCssPropertyVariant_BorderTopRightRadius* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopRightRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderBottomLeftRadius(const AzCssProperty* value, const AzStyleBorderBottomLeftRadiusValue** restrict out) {
    const AzCssPropertyVariant_BorderBottomLeftRadius* casted = (const AzCssPropertyVariant_BorderBottomLeftRadius*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomLeftRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderBottomLeftRadius(AzCssProperty* restrict value, AzStyleBorderBottomLeftRadiusValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderBottomLeftRadius* restrict casted = (AzCssPropertyVariant_BorderBottomLeftRadius* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomLeftRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderBottomRightRadius(const AzCssProperty* value, const AzStyleBorderBottomRightRadiusValue** restrict out) {
    const AzCssPropertyVariant_BorderBottomRightRadius* casted = (const AzCssPropertyVariant_BorderBottomRightRadius*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomRightRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderBottomRightRadius(AzCssProperty* restrict value, AzStyleBorderBottomRightRadiusValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderBottomRightRadius* restrict casted = (AzCssPropertyVariant_BorderBottomRightRadius* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomRightRadius;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderTopColor(const AzCssProperty* value, const AzStyleBorderTopColorValue** restrict out) {
    const AzCssPropertyVariant_BorderTopColor* casted = (const AzCssPropertyVariant_BorderTopColor*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderTopColor(AzCssProperty* restrict value, AzStyleBorderTopColorValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderTopColor* restrict casted = (AzCssPropertyVariant_BorderTopColor* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderRightColor(const AzCssProperty* value, const AzStyleBorderRightColorValue** restrict out) {
    const AzCssPropertyVariant_BorderRightColor* casted = (const AzCssPropertyVariant_BorderRightColor*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderRightColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderRightColor(AzCssProperty* restrict value, AzStyleBorderRightColorValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderRightColor* restrict casted = (AzCssPropertyVariant_BorderRightColor* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderRightColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderLeftColor(const AzCssProperty* value, const AzStyleBorderLeftColorValue** restrict out) {
    const AzCssPropertyVariant_BorderLeftColor* casted = (const AzCssPropertyVariant_BorderLeftColor*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderLeftColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderLeftColor(AzCssProperty* restrict value, AzStyleBorderLeftColorValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderLeftColor* restrict casted = (AzCssPropertyVariant_BorderLeftColor* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderLeftColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderBottomColor(const AzCssProperty* value, const AzStyleBorderBottomColorValue** restrict out) {
    const AzCssPropertyVariant_BorderBottomColor* casted = (const AzCssPropertyVariant_BorderBottomColor*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderBottomColor(AzCssProperty* restrict value, AzStyleBorderBottomColorValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderBottomColor* restrict casted = (AzCssPropertyVariant_BorderBottomColor* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomColor;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderTopStyle(const AzCssProperty* value, const AzStyleBorderTopStyleValue** restrict out) {
    const AzCssPropertyVariant_BorderTopStyle* casted = (const AzCssPropertyVariant_BorderTopStyle*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderTopStyle(AzCssProperty* restrict value, AzStyleBorderTopStyleValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderTopStyle* restrict casted = (AzCssPropertyVariant_BorderTopStyle* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderRightStyle(const AzCssProperty* value, const AzStyleBorderRightStyleValue** restrict out) {
    const AzCssPropertyVariant_BorderRightStyle* casted = (const AzCssPropertyVariant_BorderRightStyle*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderRightStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderRightStyle(AzCssProperty* restrict value, AzStyleBorderRightStyleValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderRightStyle* restrict casted = (AzCssPropertyVariant_BorderRightStyle* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderRightStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderLeftStyle(const AzCssProperty* value, const AzStyleBorderLeftStyleValue** restrict out) {
    const AzCssPropertyVariant_BorderLeftStyle* casted = (const AzCssPropertyVariant_BorderLeftStyle*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderLeftStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderLeftStyle(AzCssProperty* restrict value, AzStyleBorderLeftStyleValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderLeftStyle* restrict casted = (AzCssPropertyVariant_BorderLeftStyle* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderLeftStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderBottomStyle(const AzCssProperty* value, const AzStyleBorderBottomStyleValue** restrict out) {
    const AzCssPropertyVariant_BorderBottomStyle* casted = (const AzCssPropertyVariant_BorderBottomStyle*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderBottomStyle(AzCssProperty* restrict value, AzStyleBorderBottomStyleValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderBottomStyle* restrict casted = (AzCssPropertyVariant_BorderBottomStyle* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderTopWidth(const AzCssProperty* value, const AzLayoutBorderTopWidthValue** restrict out) {
    const AzCssPropertyVariant_BorderTopWidth* casted = (const AzCssPropertyVariant_BorderTopWidth*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderTopWidth(AzCssProperty* restrict value, AzLayoutBorderTopWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderTopWidth* restrict casted = (AzCssPropertyVariant_BorderTopWidth* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderTopWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderRightWidth(const AzCssProperty* value, const AzLayoutBorderRightWidthValue** restrict out) {
    const AzCssPropertyVariant_BorderRightWidth* casted = (const AzCssPropertyVariant_BorderRightWidth*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderRightWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderRightWidth(AzCssProperty* restrict value, AzLayoutBorderRightWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderRightWidth* restrict casted = (AzCssPropertyVariant_BorderRightWidth* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderRightWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderLeftWidth(const AzCssProperty* value, const AzLayoutBorderLeftWidthValue** restrict out) {
    const AzCssPropertyVariant_BorderLeftWidth* casted = (const AzCssPropertyVariant_BorderLeftWidth*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderLeftWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderLeftWidth(AzCssProperty* restrict value, AzLayoutBorderLeftWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderLeftWidth* restrict casted = (AzCssPropertyVariant_BorderLeftWidth* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderLeftWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBorderBottomWidth(const AzCssProperty* value, const AzLayoutBorderBottomWidthValue** restrict out) {
    const AzCssPropertyVariant_BorderBottomWidth* casted = (const AzCssPropertyVariant_BorderBottomWidth*)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBorderBottomWidth(AzCssProperty* restrict value, AzLayoutBorderBottomWidthValue* restrict * restrict out) {
    AzCssPropertyVariant_BorderBottomWidth* restrict casted = (AzCssPropertyVariant_BorderBottomWidth* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BorderBottomWidth;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBoxShadowLeft(const AzCssProperty* value, const AzStyleBoxShadowValue** restrict out) {
    const AzCssPropertyVariant_BoxShadowLeft* casted = (const AzCssPropertyVariant_BoxShadowLeft*)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowLeft;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBoxShadowLeft(AzCssProperty* restrict value, AzStyleBoxShadowValue* restrict * restrict out) {
    AzCssPropertyVariant_BoxShadowLeft* restrict casted = (AzCssPropertyVariant_BoxShadowLeft* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowLeft;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBoxShadowRight(const AzCssProperty* value, const AzStyleBoxShadowValue** restrict out) {
    const AzCssPropertyVariant_BoxShadowRight* casted = (const AzCssPropertyVariant_BoxShadowRight*)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowRight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBoxShadowRight(AzCssProperty* restrict value, AzStyleBoxShadowValue* restrict * restrict out) {
    AzCssPropertyVariant_BoxShadowRight* restrict casted = (AzCssPropertyVariant_BoxShadowRight* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowRight;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBoxShadowTop(const AzCssProperty* value, const AzStyleBoxShadowValue** restrict out) {
    const AzCssPropertyVariant_BoxShadowTop* casted = (const AzCssPropertyVariant_BoxShadowTop*)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowTop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBoxShadowTop(AzCssProperty* restrict value, AzStyleBoxShadowValue* restrict * restrict out) {
    AzCssPropertyVariant_BoxShadowTop* restrict casted = (AzCssPropertyVariant_BoxShadowTop* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowTop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBoxShadowBottom(const AzCssProperty* value, const AzStyleBoxShadowValue** restrict out) {
    const AzCssPropertyVariant_BoxShadowBottom* casted = (const AzCssPropertyVariant_BoxShadowBottom*)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowBottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBoxShadowBottom(AzCssProperty* restrict value, AzStyleBoxShadowValue* restrict * restrict out) {
    AzCssPropertyVariant_BoxShadowBottom* restrict casted = (AzCssPropertyVariant_BoxShadowBottom* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BoxShadowBottom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefScrollbarStyle(const AzCssProperty* value, const AzScrollbarStyleValue** restrict out) {
    const AzCssPropertyVariant_ScrollbarStyle* casted = (const AzCssPropertyVariant_ScrollbarStyle*)value;
    bool valid = casted->tag == AzCssPropertyTag_ScrollbarStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutScrollbarStyle(AzCssProperty* restrict value, AzScrollbarStyleValue* restrict * restrict out) {
    AzCssPropertyVariant_ScrollbarStyle* restrict casted = (AzCssPropertyVariant_ScrollbarStyle* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_ScrollbarStyle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefOpacity(const AzCssProperty* value, const AzStyleOpacityValue** restrict out) {
    const AzCssPropertyVariant_Opacity* casted = (const AzCssPropertyVariant_Opacity*)value;
    bool valid = casted->tag == AzCssPropertyTag_Opacity;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutOpacity(AzCssProperty* restrict value, AzStyleOpacityValue* restrict * restrict out) {
    AzCssPropertyVariant_Opacity* restrict casted = (AzCssPropertyVariant_Opacity* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Opacity;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefTransform(const AzCssProperty* value, const AzStyleTransformVecValue** restrict out) {
    const AzCssPropertyVariant_Transform* casted = (const AzCssPropertyVariant_Transform*)value;
    bool valid = casted->tag == AzCssPropertyTag_Transform;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutTransform(AzCssProperty* restrict value, AzStyleTransformVecValue* restrict * restrict out) {
    AzCssPropertyVariant_Transform* restrict casted = (AzCssPropertyVariant_Transform* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_Transform;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefTransformOrigin(const AzCssProperty* value, const AzStyleTransformOriginValue** restrict out) {
    const AzCssPropertyVariant_TransformOrigin* casted = (const AzCssPropertyVariant_TransformOrigin*)value;
    bool valid = casted->tag == AzCssPropertyTag_TransformOrigin;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutTransformOrigin(AzCssProperty* restrict value, AzStyleTransformOriginValue* restrict * restrict out) {
    AzCssPropertyVariant_TransformOrigin* restrict casted = (AzCssPropertyVariant_TransformOrigin* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_TransformOrigin;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefPerspectiveOrigin(const AzCssProperty* value, const AzStylePerspectiveOriginValue** restrict out) {
    const AzCssPropertyVariant_PerspectiveOrigin* casted = (const AzCssPropertyVariant_PerspectiveOrigin*)value;
    bool valid = casted->tag == AzCssPropertyTag_PerspectiveOrigin;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutPerspectiveOrigin(AzCssProperty* restrict value, AzStylePerspectiveOriginValue* restrict * restrict out) {
    AzCssPropertyVariant_PerspectiveOrigin* restrict casted = (AzCssPropertyVariant_PerspectiveOrigin* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_PerspectiveOrigin;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchRefBackfaceVisibility(const AzCssProperty* value, const AzStyleBackfaceVisibilityValue** restrict out) {
    const AzCssPropertyVariant_BackfaceVisibility* casted = (const AzCssPropertyVariant_BackfaceVisibility*)value;
    bool valid = casted->tag == AzCssPropertyTag_BackfaceVisibility;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssProperty_matchMutBackfaceVisibility(AzCssProperty* restrict value, AzStyleBackfaceVisibilityValue* restrict * restrict out) {
    AzCssPropertyVariant_BackfaceVisibility* restrict casted = (AzCssPropertyVariant_BackfaceVisibility* restrict)value;
    bool valid = casted->tag == AzCssPropertyTag_BackfaceVisibility;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTextInputSelection_matchRefFromTo(const AzTextInputSelection* value, const AzTextInputSelectionRange** restrict out) {
    const AzTextInputSelectionVariant_FromTo* casted = (const AzTextInputSelectionVariant_FromTo*)value;
    bool valid = casted->tag == AzTextInputSelectionTag_FromTo;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTextInputSelection_matchMutFromTo(AzTextInputSelection* restrict value, AzTextInputSelectionRange* restrict * restrict out) {
    AzTextInputSelectionVariant_FromTo* restrict casted = (AzTextInputSelectionVariant_FromTo* restrict)value;
    bool valid = casted->tag == AzTextInputSelectionTag_FromTo;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPropertySource_matchRefCss(const AzCssPropertySource* value, const AzCssPath** restrict out) {
    const AzCssPropertySourceVariant_Css* casted = (const AzCssPropertySourceVariant_Css*)value;
    bool valid = casted->tag == AzCssPropertySourceTag_Css;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPropertySource_matchMutCss(AzCssPropertySource* restrict value, AzCssPath* restrict * restrict out) {
    AzCssPropertySourceVariant_Css* restrict casted = (AzCssPropertySourceVariant_Css* restrict)value;
    bool valid = casted->tag == AzCssPropertySourceTag_Css;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawImageData_matchRefU8(const AzRawImageData* value, const AzU8Vec** restrict out) {
    const AzRawImageDataVariant_U8* casted = (const AzRawImageDataVariant_U8*)value;
    bool valid = casted->tag == AzRawImageDataTag_U8;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawImageData_matchMutU8(AzRawImageData* restrict value, AzU8Vec* restrict * restrict out) {
    AzRawImageDataVariant_U8* restrict casted = (AzRawImageDataVariant_U8* restrict)value;
    bool valid = casted->tag == AzRawImageDataTag_U8;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawImageData_matchRefU16(const AzRawImageData* value, const AzU16Vec** restrict out) {
    const AzRawImageDataVariant_U16* casted = (const AzRawImageDataVariant_U16*)value;
    bool valid = casted->tag == AzRawImageDataTag_U16;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawImageData_matchMutU16(AzRawImageData* restrict value, AzU16Vec* restrict * restrict out) {
    AzRawImageDataVariant_U16* restrict casted = (AzRawImageDataVariant_U16* restrict)value;
    bool valid = casted->tag == AzRawImageDataTag_U16;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawImageData_matchRefF32(const AzRawImageData* value, const AzF32Vec** restrict out) {
    const AzRawImageDataVariant_F32* casted = (const AzRawImageDataVariant_F32*)value;
    bool valid = casted->tag == AzRawImageDataTag_F32;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzRawImageData_matchMutF32(AzRawImageData* restrict value, AzF32Vec* restrict * restrict out) {
    AzRawImageDataVariant_F32* restrict casted = (AzRawImageDataVariant_F32* restrict)value;
    bool valid = casted->tag == AzRawImageDataTag_F32;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchRefMultiPolygonCollection(const AzSvgNode* value, const AzSvgMultiPolygonVec** restrict out) {
    const AzSvgNodeVariant_MultiPolygonCollection* casted = (const AzSvgNodeVariant_MultiPolygonCollection*)value;
    bool valid = casted->tag == AzSvgNodeTag_MultiPolygonCollection;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchMutMultiPolygonCollection(AzSvgNode* restrict value, AzSvgMultiPolygonVec* restrict * restrict out) {
    AzSvgNodeVariant_MultiPolygonCollection* restrict casted = (AzSvgNodeVariant_MultiPolygonCollection* restrict)value;
    bool valid = casted->tag == AzSvgNodeTag_MultiPolygonCollection;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchRefMultiPolygon(const AzSvgNode* value, const AzSvgMultiPolygon** restrict out) {
    const AzSvgNodeVariant_MultiPolygon* casted = (const AzSvgNodeVariant_MultiPolygon*)value;
    bool valid = casted->tag == AzSvgNodeTag_MultiPolygon;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchMutMultiPolygon(AzSvgNode* restrict value, AzSvgMultiPolygon* restrict * restrict out) {
    AzSvgNodeVariant_MultiPolygon* restrict casted = (AzSvgNodeVariant_MultiPolygon* restrict)value;
    bool valid = casted->tag == AzSvgNodeTag_MultiPolygon;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchRefPath(const AzSvgNode* value, const AzSvgPath** restrict out) {
    const AzSvgNodeVariant_Path* casted = (const AzSvgNodeVariant_Path*)value;
    bool valid = casted->tag == AzSvgNodeTag_Path;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchMutPath(AzSvgNode* restrict value, AzSvgPath* restrict * restrict out) {
    AzSvgNodeVariant_Path* restrict casted = (AzSvgNodeVariant_Path* restrict)value;
    bool valid = casted->tag == AzSvgNodeTag_Path;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchRefCircle(const AzSvgNode* value, const AzSvgCircle** restrict out) {
    const AzSvgNodeVariant_Circle* casted = (const AzSvgNodeVariant_Circle*)value;
    bool valid = casted->tag == AzSvgNodeTag_Circle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchMutCircle(AzSvgNode* restrict value, AzSvgCircle* restrict * restrict out) {
    AzSvgNodeVariant_Circle* restrict casted = (AzSvgNodeVariant_Circle* restrict)value;
    bool valid = casted->tag == AzSvgNodeTag_Circle;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchRefRect(const AzSvgNode* value, const AzSvgRect** restrict out) {
    const AzSvgNodeVariant_Rect* casted = (const AzSvgNodeVariant_Rect*)value;
    bool valid = casted->tag == AzSvgNodeTag_Rect;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgNode_matchMutRect(AzSvgNode* restrict value, AzSvgRect* restrict * restrict out) {
    AzSvgNodeVariant_Rect* restrict casted = (AzSvgNodeVariant_Rect* restrict)value;
    bool valid = casted->tag == AzSvgNodeTag_Rect;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElement_matchRefLine(const AzSvgPathElement* value, const AzSvgLine** restrict out) {
    const AzSvgPathElementVariant_Line* casted = (const AzSvgPathElementVariant_Line*)value;
    bool valid = casted->tag == AzSvgPathElementTag_Line;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElement_matchMutLine(AzSvgPathElement* restrict value, AzSvgLine* restrict * restrict out) {
    AzSvgPathElementVariant_Line* restrict casted = (AzSvgPathElementVariant_Line* restrict)value;
    bool valid = casted->tag == AzSvgPathElementTag_Line;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElement_matchRefQuadraticCurve(const AzSvgPathElement* value, const AzSvgQuadraticCurve** restrict out) {
    const AzSvgPathElementVariant_QuadraticCurve* casted = (const AzSvgPathElementVariant_QuadraticCurve*)value;
    bool valid = casted->tag == AzSvgPathElementTag_QuadraticCurve;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElement_matchMutQuadraticCurve(AzSvgPathElement* restrict value, AzSvgQuadraticCurve* restrict * restrict out) {
    AzSvgPathElementVariant_QuadraticCurve* restrict casted = (AzSvgPathElementVariant_QuadraticCurve* restrict)value;
    bool valid = casted->tag == AzSvgPathElementTag_QuadraticCurve;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElement_matchRefCubicCurve(const AzSvgPathElement* value, const AzSvgCubicCurve** restrict out) {
    const AzSvgPathElementVariant_CubicCurve* casted = (const AzSvgPathElementVariant_CubicCurve*)value;
    bool valid = casted->tag == AzSvgPathElementTag_CubicCurve;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElement_matchMutCubicCurve(AzSvgPathElement* restrict value, AzSvgCubicCurve* restrict * restrict out) {
    AzSvgPathElementVariant_CubicCurve* restrict casted = (AzSvgPathElementVariant_CubicCurve* restrict)value;
    bool valid = casted->tag == AzSvgPathElementTag_CubicCurve;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIndent_matchRefSpaces(const AzIndent* value, const Azu8** restrict out) {
    const AzIndentVariant_Spaces* casted = (const AzIndentVariant_Spaces*)value;
    bool valid = casted->tag == AzIndentTag_Spaces;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIndent_matchMutSpaces(AzIndent* restrict value, Azu8* restrict * restrict out) {
    AzIndentVariant_Spaces* restrict casted = (AzIndentVariant_Spaces* restrict)value;
    bool valid = casted->tag == AzIndentTag_Spaces;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgFitTo_matchRefWidth(const AzSvgFitTo* value, const Azu32** restrict out) {
    const AzSvgFitToVariant_Width* casted = (const AzSvgFitToVariant_Width*)value;
    bool valid = casted->tag == AzSvgFitToTag_Width;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgFitTo_matchMutWidth(AzSvgFitTo* restrict value, Azu32* restrict * restrict out) {
    AzSvgFitToVariant_Width* restrict casted = (AzSvgFitToVariant_Width* restrict)value;
    bool valid = casted->tag == AzSvgFitToTag_Width;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgFitTo_matchRefHeight(const AzSvgFitTo* value, const Azu32** restrict out) {
    const AzSvgFitToVariant_Height* casted = (const AzSvgFitToVariant_Height*)value;
    bool valid = casted->tag == AzSvgFitToTag_Height;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgFitTo_matchMutHeight(AzSvgFitTo* restrict value, Azu32* restrict * restrict out) {
    AzSvgFitToVariant_Height* restrict casted = (AzSvgFitToVariant_Height* restrict)value;
    bool valid = casted->tag == AzSvgFitToTag_Height;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgFitTo_matchRefZoom(const AzSvgFitTo* value, const Azf32** restrict out) {
    const AzSvgFitToVariant_Zoom* casted = (const AzSvgFitToVariant_Zoom*)value;
    bool valid = casted->tag == AzSvgFitToTag_Zoom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgFitTo_matchMutZoom(AzSvgFitTo* restrict value, Azf32* restrict * restrict out) {
    AzSvgFitToVariant_Zoom* restrict casted = (AzSvgFitToVariant_Zoom* restrict)value;
    bool valid = casted->tag == AzSvgFitToTag_Zoom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgStyle_matchRefFill(const AzSvgStyle* value, const AzSvgFillStyle** restrict out) {
    const AzSvgStyleVariant_Fill* casted = (const AzSvgStyleVariant_Fill*)value;
    bool valid = casted->tag == AzSvgStyleTag_Fill;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgStyle_matchMutFill(AzSvgStyle* restrict value, AzSvgFillStyle* restrict * restrict out) {
    AzSvgStyleVariant_Fill* restrict casted = (AzSvgStyleVariant_Fill* restrict)value;
    bool valid = casted->tag == AzSvgStyleTag_Fill;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgStyle_matchRefStroke(const AzSvgStyle* value, const AzSvgStrokeStyle** restrict out) {
    const AzSvgStyleVariant_Stroke* casted = (const AzSvgStyleVariant_Stroke*)value;
    bool valid = casted->tag == AzSvgStyleTag_Stroke;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgStyle_matchMutStroke(AzSvgStyle* restrict value, AzSvgStrokeStyle* restrict * restrict out) {
    AzSvgStyleVariant_Stroke* restrict casted = (AzSvgStyleVariant_Stroke* restrict)value;
    bool valid = casted->tag == AzSvgStyleTag_Stroke;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInstant_matchRefSystem(const AzInstant* value, const AzInstantPtr** restrict out) {
    const AzInstantVariant_System* casted = (const AzInstantVariant_System*)value;
    bool valid = casted->tag == AzInstantTag_System;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInstant_matchMutSystem(AzInstant* restrict value, AzInstantPtr* restrict * restrict out) {
    AzInstantVariant_System* restrict casted = (AzInstantVariant_System* restrict)value;
    bool valid = casted->tag == AzInstantTag_System;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInstant_matchRefTick(const AzInstant* value, const AzSystemTick** restrict out) {
    const AzInstantVariant_Tick* casted = (const AzInstantVariant_Tick*)value;
    bool valid = casted->tag == AzInstantTag_Tick;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInstant_matchMutTick(AzInstant* restrict value, AzSystemTick* restrict * restrict out) {
    AzInstantVariant_Tick* restrict casted = (AzInstantVariant_Tick* restrict)value;
    bool valid = casted->tag == AzInstantTag_Tick;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDuration_matchRefSystem(const AzDuration* value, const AzSystemTimeDiff** restrict out) {
    const AzDurationVariant_System* casted = (const AzDurationVariant_System*)value;
    bool valid = casted->tag == AzDurationTag_System;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDuration_matchMutSystem(AzDuration* restrict value, AzSystemTimeDiff* restrict * restrict out) {
    AzDurationVariant_System* restrict casted = (AzDurationVariant_System* restrict)value;
    bool valid = casted->tag == AzDurationTag_System;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDuration_matchRefTick(const AzDuration* value, const AzSystemTickDiff** restrict out) {
    const AzDurationVariant_Tick* casted = (const AzDurationVariant_Tick*)value;
    bool valid = casted->tag == AzDurationTag_Tick;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDuration_matchMutTick(AzDuration* restrict value, AzSystemTickDiff* restrict * restrict out) {
    AzDurationVariant_Tick* restrict casted = (AzDurationVariant_Tick* restrict)value;
    bool valid = casted->tag == AzDurationTag_Tick;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzThreadSendMsg_matchRefCustom(const AzThreadSendMsg* value, const AzRefAny** restrict out) {
    const AzThreadSendMsgVariant_Custom* casted = (const AzThreadSendMsgVariant_Custom*)value;
    bool valid = casted->tag == AzThreadSendMsgTag_Custom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzThreadSendMsg_matchMutCustom(AzThreadSendMsg* restrict value, AzRefAny* restrict * restrict out) {
    AzThreadSendMsgVariant_Custom* restrict casted = (AzThreadSendMsgVariant_Custom* restrict)value;
    bool valid = casted->tag == AzThreadSendMsgTag_Custom;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzThreadReceiveMsg_matchRefWriteBack(const AzThreadReceiveMsg* value, const AzThreadWriteBackMsg** restrict out) {
    const AzThreadReceiveMsgVariant_WriteBack* casted = (const AzThreadReceiveMsgVariant_WriteBack*)value;
    bool valid = casted->tag == AzThreadReceiveMsgTag_WriteBack;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzThreadReceiveMsg_matchMutWriteBack(AzThreadReceiveMsg* restrict value, AzThreadWriteBackMsg* restrict * restrict out) {
    AzThreadReceiveMsgVariant_WriteBack* restrict casted = (AzThreadReceiveMsgVariant_WriteBack* restrict)value;
    bool valid = casted->tag == AzThreadReceiveMsgTag_WriteBack;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzThreadReceiveMsg_matchRefUpdate(const AzThreadReceiveMsg* value, const AzUpdate** restrict out) {
    const AzThreadReceiveMsgVariant_Update* casted = (const AzThreadReceiveMsgVariant_Update*)value;
    bool valid = casted->tag == AzThreadReceiveMsgTag_Update;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzThreadReceiveMsg_matchMutUpdate(AzThreadReceiveMsg* restrict value, AzUpdate* restrict * restrict out) {
    AzThreadReceiveMsgVariant_Update* restrict casted = (AzThreadReceiveMsgVariant_Update* restrict)value;
    bool valid = casted->tag == AzThreadReceiveMsgTag_Update;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefBool(const AzFmtValue* value, const Azbool** restrict out) {
    const AzFmtValueVariant_Bool* casted = (const AzFmtValueVariant_Bool*)value;
    bool valid = casted->tag == AzFmtValueTag_Bool;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutBool(AzFmtValue* restrict value, Azbool* restrict * restrict out) {
    AzFmtValueVariant_Bool* restrict casted = (AzFmtValueVariant_Bool* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Bool;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefUchar(const AzFmtValue* value, const Azu8** restrict out) {
    const AzFmtValueVariant_Uchar* casted = (const AzFmtValueVariant_Uchar*)value;
    bool valid = casted->tag == AzFmtValueTag_Uchar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutUchar(AzFmtValue* restrict value, Azu8* restrict * restrict out) {
    AzFmtValueVariant_Uchar* restrict casted = (AzFmtValueVariant_Uchar* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Uchar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefSchar(const AzFmtValue* value, const Azi8** restrict out) {
    const AzFmtValueVariant_Schar* casted = (const AzFmtValueVariant_Schar*)value;
    bool valid = casted->tag == AzFmtValueTag_Schar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutSchar(AzFmtValue* restrict value, Azi8* restrict * restrict out) {
    AzFmtValueVariant_Schar* restrict casted = (AzFmtValueVariant_Schar* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Schar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefUshort(const AzFmtValue* value, const Azu16** restrict out) {
    const AzFmtValueVariant_Ushort* casted = (const AzFmtValueVariant_Ushort*)value;
    bool valid = casted->tag == AzFmtValueTag_Ushort;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutUshort(AzFmtValue* restrict value, Azu16* restrict * restrict out) {
    AzFmtValueVariant_Ushort* restrict casted = (AzFmtValueVariant_Ushort* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Ushort;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefSshort(const AzFmtValue* value, const Azi16** restrict out) {
    const AzFmtValueVariant_Sshort* casted = (const AzFmtValueVariant_Sshort*)value;
    bool valid = casted->tag == AzFmtValueTag_Sshort;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutSshort(AzFmtValue* restrict value, Azi16* restrict * restrict out) {
    AzFmtValueVariant_Sshort* restrict casted = (AzFmtValueVariant_Sshort* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Sshort;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefUint(const AzFmtValue* value, const Azu32** restrict out) {
    const AzFmtValueVariant_Uint* casted = (const AzFmtValueVariant_Uint*)value;
    bool valid = casted->tag == AzFmtValueTag_Uint;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutUint(AzFmtValue* restrict value, Azu32* restrict * restrict out) {
    AzFmtValueVariant_Uint* restrict casted = (AzFmtValueVariant_Uint* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Uint;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefSint(const AzFmtValue* value, const Azi32** restrict out) {
    const AzFmtValueVariant_Sint* casted = (const AzFmtValueVariant_Sint*)value;
    bool valid = casted->tag == AzFmtValueTag_Sint;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutSint(AzFmtValue* restrict value, Azi32* restrict * restrict out) {
    AzFmtValueVariant_Sint* restrict casted = (AzFmtValueVariant_Sint* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Sint;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefUlong(const AzFmtValue* value, const Azu64** restrict out) {
    const AzFmtValueVariant_Ulong* casted = (const AzFmtValueVariant_Ulong*)value;
    bool valid = casted->tag == AzFmtValueTag_Ulong;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutUlong(AzFmtValue* restrict value, Azu64* restrict * restrict out) {
    AzFmtValueVariant_Ulong* restrict casted = (AzFmtValueVariant_Ulong* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Ulong;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefSlong(const AzFmtValue* value, const Azi64** restrict out) {
    const AzFmtValueVariant_Slong* casted = (const AzFmtValueVariant_Slong*)value;
    bool valid = casted->tag == AzFmtValueTag_Slong;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutSlong(AzFmtValue* restrict value, Azi64* restrict * restrict out) {
    AzFmtValueVariant_Slong* restrict casted = (AzFmtValueVariant_Slong* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Slong;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefIsize(const AzFmtValue* value, const Azisize** restrict out) {
    const AzFmtValueVariant_Isize* casted = (const AzFmtValueVariant_Isize*)value;
    bool valid = casted->tag == AzFmtValueTag_Isize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutIsize(AzFmtValue* restrict value, Azisize* restrict * restrict out) {
    AzFmtValueVariant_Isize* restrict casted = (AzFmtValueVariant_Isize* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Isize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefUsize(const AzFmtValue* value, const Azusize** restrict out) {
    const AzFmtValueVariant_Usize* casted = (const AzFmtValueVariant_Usize*)value;
    bool valid = casted->tag == AzFmtValueTag_Usize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutUsize(AzFmtValue* restrict value, Azusize* restrict * restrict out) {
    AzFmtValueVariant_Usize* restrict casted = (AzFmtValueVariant_Usize* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Usize;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefFloat(const AzFmtValue* value, const Azf32** restrict out) {
    const AzFmtValueVariant_Float* casted = (const AzFmtValueVariant_Float*)value;
    bool valid = casted->tag == AzFmtValueTag_Float;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutFloat(AzFmtValue* restrict value, Azf32* restrict * restrict out) {
    AzFmtValueVariant_Float* restrict casted = (AzFmtValueVariant_Float* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Float;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefDouble(const AzFmtValue* value, const Azf64** restrict out) {
    const AzFmtValueVariant_Double* casted = (const AzFmtValueVariant_Double*)value;
    bool valid = casted->tag == AzFmtValueTag_Double;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutDouble(AzFmtValue* restrict value, Azf64* restrict * restrict out) {
    AzFmtValueVariant_Double* restrict casted = (AzFmtValueVariant_Double* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Double;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefStr(const AzFmtValue* value, const AzString** restrict out) {
    const AzFmtValueVariant_Str* casted = (const AzFmtValueVariant_Str*)value;
    bool valid = casted->tag == AzFmtValueTag_Str;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutStr(AzFmtValue* restrict value, AzString* restrict * restrict out) {
    AzFmtValueVariant_Str* restrict casted = (AzFmtValueVariant_Str* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_Str;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchRefStrVec(const AzFmtValue* value, const AzStringVec** restrict out) {
    const AzFmtValueVariant_StrVec* casted = (const AzFmtValueVariant_StrVec*)value;
    bool valid = casted->tag == AzFmtValueTag_StrVec;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtValue_matchMutStrVec(AzFmtValue* restrict value, AzStringVec* restrict * restrict out) {
    AzFmtValueVariant_StrVec* restrict casted = (AzFmtValueVariant_StrVec* restrict)value;
    bool valid = casted->tag == AzFmtValueTag_StrVec;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamilyVecDestructor_matchRefExternal(const AzStyleFontFamilyVecDestructor* value, const AzStyleFontFamilyVecDestructorType** restrict out) {
    const AzStyleFontFamilyVecDestructorVariant_External* casted = (const AzStyleFontFamilyVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStyleFontFamilyVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleFontFamilyVecDestructor_matchMutExternal(AzStyleFontFamilyVecDestructor* restrict value, AzStyleFontFamilyVecDestructorType* restrict * restrict out) {
    AzStyleFontFamilyVecDestructorVariant_External* restrict casted = (AzStyleFontFamilyVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStyleFontFamilyVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAccessibilityStateVecDestructor_matchRefExternal(const AzAccessibilityStateVecDestructor* value, const AzAccessibilityStateVecDestructorType** restrict out) {
    const AzAccessibilityStateVecDestructorVariant_External* casted = (const AzAccessibilityStateVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzAccessibilityStateVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzAccessibilityStateVecDestructor_matchMutExternal(AzAccessibilityStateVecDestructor* restrict value, AzAccessibilityStateVecDestructorType* restrict * restrict out) {
    AzAccessibilityStateVecDestructorVariant_External* restrict casted = (AzAccessibilityStateVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzAccessibilityStateVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItemVecDestructor_matchRefExternal(const AzMenuItemVecDestructor* value, const AzMenuItemVecDestructorType** restrict out) {
    const AzMenuItemVecDestructorVariant_External* casted = (const AzMenuItemVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzMenuItemVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMenuItemVecDestructor_matchMutExternal(AzMenuItemVecDestructor* restrict value, AzMenuItemVecDestructorType* restrict * restrict out) {
    AzMenuItemVecDestructorVariant_External* restrict casted = (AzMenuItemVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzMenuItemVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTessellatedSvgNodeVecDestructor_matchRefExternal(const AzTessellatedSvgNodeVecDestructor* value, const AzTessellatedSvgNodeVecDestructorType** restrict out) {
    const AzTessellatedSvgNodeVecDestructorVariant_External* casted = (const AzTessellatedSvgNodeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzTessellatedSvgNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTessellatedSvgNodeVecDestructor_matchMutExternal(AzTessellatedSvgNodeVecDestructor* restrict value, AzTessellatedSvgNodeVecDestructorType* restrict * restrict out) {
    AzTessellatedSvgNodeVecDestructorVariant_External* restrict casted = (AzTessellatedSvgNodeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzTessellatedSvgNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlNodeVecDestructor_matchRefExternal(const AzXmlNodeVecDestructor* value, const AzXmlNodeVecDestructorType** restrict out) {
    const AzXmlNodeVecDestructorVariant_External* casted = (const AzXmlNodeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzXmlNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlNodeVecDestructor_matchMutExternal(AzXmlNodeVecDestructor* restrict value, AzXmlNodeVecDestructorType* restrict * restrict out) {
    AzXmlNodeVecDestructorVariant_External* restrict casted = (AzXmlNodeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzXmlNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtArgVecDestructor_matchRefExternal(const AzFmtArgVecDestructor* value, const AzFmtArgVecDestructorType** restrict out) {
    const AzFmtArgVecDestructorVariant_External* casted = (const AzFmtArgVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzFmtArgVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzFmtArgVecDestructor_matchMutExternal(AzFmtArgVecDestructor* restrict value, AzFmtArgVecDestructorType* restrict * restrict out) {
    AzFmtArgVecDestructorVariant_External* restrict casted = (AzFmtArgVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzFmtArgVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineLineVecDestructor_matchRefExternal(const AzInlineLineVecDestructor* value, const AzInlineLineVecDestructorType** restrict out) {
    const AzInlineLineVecDestructorVariant_External* casted = (const AzInlineLineVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzInlineLineVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineLineVecDestructor_matchMutExternal(AzInlineLineVecDestructor* restrict value, AzInlineLineVecDestructorType* restrict * restrict out) {
    AzInlineLineVecDestructorVariant_External* restrict casted = (AzInlineLineVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzInlineLineVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineWordVecDestructor_matchRefExternal(const AzInlineWordVecDestructor* value, const AzInlineWordVecDestructorType** restrict out) {
    const AzInlineWordVecDestructorVariant_External* casted = (const AzInlineWordVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzInlineWordVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineWordVecDestructor_matchMutExternal(AzInlineWordVecDestructor* restrict value, AzInlineWordVecDestructorType* restrict * restrict out) {
    AzInlineWordVecDestructorVariant_External* restrict casted = (AzInlineWordVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzInlineWordVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineGlyphVecDestructor_matchRefExternal(const AzInlineGlyphVecDestructor* value, const AzInlineGlyphVecDestructorType** restrict out) {
    const AzInlineGlyphVecDestructorVariant_External* casted = (const AzInlineGlyphVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzInlineGlyphVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineGlyphVecDestructor_matchMutExternal(AzInlineGlyphVecDestructor* restrict value, AzInlineGlyphVecDestructorType* restrict * restrict out) {
    AzInlineGlyphVecDestructorVariant_External* restrict casted = (AzInlineGlyphVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzInlineGlyphVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineTextHitVecDestructor_matchRefExternal(const AzInlineTextHitVecDestructor* value, const AzInlineTextHitVecDestructorType** restrict out) {
    const AzInlineTextHitVecDestructorVariant_External* casted = (const AzInlineTextHitVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzInlineTextHitVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzInlineTextHitVecDestructor_matchMutExternal(AzInlineTextHitVecDestructor* restrict value, AzInlineTextHitVecDestructorType* restrict * restrict out) {
    AzInlineTextHitVecDestructorVariant_External* restrict casted = (AzInlineTextHitVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzInlineTextHitVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMonitorVecDestructor_matchRefExternal(const AzMonitorVecDestructor* value, const AzMonitorVecDestructorType** restrict out) {
    const AzMonitorVecDestructorVariant_External* casted = (const AzMonitorVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzMonitorVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzMonitorVecDestructor_matchMutExternal(AzMonitorVecDestructor* restrict value, AzMonitorVecDestructorType* restrict * restrict out) {
    AzMonitorVecDestructorVariant_External* restrict casted = (AzMonitorVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzMonitorVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzVideoModeVecDestructor_matchRefExternal(const AzVideoModeVecDestructor* value, const AzVideoModeVecDestructorType** restrict out) {
    const AzVideoModeVecDestructorVariant_External* casted = (const AzVideoModeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzVideoModeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzVideoModeVecDestructor_matchMutExternal(AzVideoModeVecDestructor* restrict value, AzVideoModeVecDestructorType* restrict * restrict out) {
    AzVideoModeVecDestructorVariant_External* restrict casted = (AzVideoModeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzVideoModeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDomVecDestructor_matchRefExternal(const AzDomVecDestructor* value, const AzDomVecDestructorType** restrict out) {
    const AzDomVecDestructorVariant_External* casted = (const AzDomVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzDomVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDomVecDestructor_matchMutExternal(AzDomVecDestructor* restrict value, AzDomVecDestructorType* restrict * restrict out) {
    AzDomVecDestructorVariant_External* restrict casted = (AzDomVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzDomVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIdOrClassVecDestructor_matchRefExternal(const AzIdOrClassVecDestructor* value, const AzIdOrClassVecDestructorType** restrict out) {
    const AzIdOrClassVecDestructorVariant_External* casted = (const AzIdOrClassVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzIdOrClassVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzIdOrClassVecDestructor_matchMutExternal(AzIdOrClassVecDestructor* restrict value, AzIdOrClassVecDestructorType* restrict * restrict out) {
    AzIdOrClassVecDestructorVariant_External* restrict casted = (AzIdOrClassVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzIdOrClassVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssPropertyVecDestructor_matchRefExternal(const AzNodeDataInlineCssPropertyVecDestructor* value, const AzNodeDataInlineCssPropertyVecDestructorType** restrict out) {
    const AzNodeDataInlineCssPropertyVecDestructorVariant_External* casted = (const AzNodeDataInlineCssPropertyVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataInlineCssPropertyVecDestructor_matchMutExternal(AzNodeDataInlineCssPropertyVecDestructor* restrict value, AzNodeDataInlineCssPropertyVecDestructorType* restrict * restrict out) {
    AzNodeDataInlineCssPropertyVecDestructorVariant_External* restrict casted = (AzNodeDataInlineCssPropertyVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzNodeDataInlineCssPropertyVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContentVecDestructor_matchRefExternal(const AzStyleBackgroundContentVecDestructor* value, const AzStyleBackgroundContentVecDestructorType** restrict out) {
    const AzStyleBackgroundContentVecDestructorVariant_External* casted = (const AzStyleBackgroundContentVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStyleBackgroundContentVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundContentVecDestructor_matchMutExternal(AzStyleBackgroundContentVecDestructor* restrict value, AzStyleBackgroundContentVecDestructorType* restrict * restrict out) {
    AzStyleBackgroundContentVecDestructorVariant_External* restrict casted = (AzStyleBackgroundContentVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundContentVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundPositionVecDestructor_matchRefExternal(const AzStyleBackgroundPositionVecDestructor* value, const AzStyleBackgroundPositionVecDestructorType** restrict out) {
    const AzStyleBackgroundPositionVecDestructorVariant_External* casted = (const AzStyleBackgroundPositionVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStyleBackgroundPositionVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundPositionVecDestructor_matchMutExternal(AzStyleBackgroundPositionVecDestructor* restrict value, AzStyleBackgroundPositionVecDestructorType* restrict * restrict out) {
    AzStyleBackgroundPositionVecDestructorVariant_External* restrict casted = (AzStyleBackgroundPositionVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundPositionVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundRepeatVecDestructor_matchRefExternal(const AzStyleBackgroundRepeatVecDestructor* value, const AzStyleBackgroundRepeatVecDestructorType** restrict out) {
    const AzStyleBackgroundRepeatVecDestructorVariant_External* casted = (const AzStyleBackgroundRepeatVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStyleBackgroundRepeatVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundRepeatVecDestructor_matchMutExternal(AzStyleBackgroundRepeatVecDestructor* restrict value, AzStyleBackgroundRepeatVecDestructorType* restrict * restrict out) {
    AzStyleBackgroundRepeatVecDestructorVariant_External* restrict casted = (AzStyleBackgroundRepeatVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundRepeatVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundSizeVecDestructor_matchRefExternal(const AzStyleBackgroundSizeVecDestructor* value, const AzStyleBackgroundSizeVecDestructorType** restrict out) {
    const AzStyleBackgroundSizeVecDestructorVariant_External* casted = (const AzStyleBackgroundSizeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStyleBackgroundSizeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleBackgroundSizeVecDestructor_matchMutExternal(AzStyleBackgroundSizeVecDestructor* restrict value, AzStyleBackgroundSizeVecDestructorType* restrict * restrict out) {
    AzStyleBackgroundSizeVecDestructorVariant_External* restrict casted = (AzStyleBackgroundSizeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStyleBackgroundSizeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransformVecDestructor_matchRefExternal(const AzStyleTransformVecDestructor* value, const AzStyleTransformVecDestructorType** restrict out) {
    const AzStyleTransformVecDestructorVariant_External* casted = (const AzStyleTransformVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStyleTransformVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyleTransformVecDestructor_matchMutExternal(AzStyleTransformVecDestructor* restrict value, AzStyleTransformVecDestructorType* restrict * restrict out) {
    AzStyleTransformVecDestructorVariant_External* restrict casted = (AzStyleTransformVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStyleTransformVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPropertyVecDestructor_matchRefExternal(const AzCssPropertyVecDestructor* value, const AzCssPropertyVecDestructorType** restrict out) {
    const AzCssPropertyVecDestructorVariant_External* casted = (const AzCssPropertyVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzCssPropertyVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPropertyVecDestructor_matchMutExternal(AzCssPropertyVecDestructor* restrict value, AzCssPropertyVecDestructorType* restrict * restrict out) {
    AzCssPropertyVecDestructorVariant_External* restrict casted = (AzCssPropertyVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzCssPropertyVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgMultiPolygonVecDestructor_matchRefExternal(const AzSvgMultiPolygonVecDestructor* value, const AzSvgMultiPolygonVecDestructorType** restrict out) {
    const AzSvgMultiPolygonVecDestructorVariant_External* casted = (const AzSvgMultiPolygonVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzSvgMultiPolygonVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgMultiPolygonVecDestructor_matchMutExternal(AzSvgMultiPolygonVecDestructor* restrict value, AzSvgMultiPolygonVecDestructorType* restrict * restrict out) {
    AzSvgMultiPolygonVecDestructorVariant_External* restrict casted = (AzSvgMultiPolygonVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzSvgMultiPolygonVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathVecDestructor_matchRefExternal(const AzSvgPathVecDestructor* value, const AzSvgPathVecDestructorType** restrict out) {
    const AzSvgPathVecDestructorVariant_External* casted = (const AzSvgPathVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzSvgPathVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathVecDestructor_matchMutExternal(AzSvgPathVecDestructor* restrict value, AzSvgPathVecDestructorType* restrict * restrict out) {
    AzSvgPathVecDestructorVariant_External* restrict casted = (AzSvgPathVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzSvgPathVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzVertexAttributeVecDestructor_matchRefExternal(const AzVertexAttributeVecDestructor* value, const AzVertexAttributeVecDestructorType** restrict out) {
    const AzVertexAttributeVecDestructorVariant_External* casted = (const AzVertexAttributeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzVertexAttributeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzVertexAttributeVecDestructor_matchMutExternal(AzVertexAttributeVecDestructor* restrict value, AzVertexAttributeVecDestructorType* restrict * restrict out) {
    AzVertexAttributeVecDestructorVariant_External* restrict casted = (AzVertexAttributeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzVertexAttributeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElementVecDestructor_matchRefExternal(const AzSvgPathElementVecDestructor* value, const AzSvgPathElementVecDestructorType** restrict out) {
    const AzSvgPathElementVecDestructorVariant_External* casted = (const AzSvgPathElementVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzSvgPathElementVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgPathElementVecDestructor_matchMutExternal(AzSvgPathElementVecDestructor* restrict value, AzSvgPathElementVecDestructorType* restrict * restrict out) {
    AzSvgPathElementVecDestructorVariant_External* restrict casted = (AzSvgPathElementVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzSvgPathElementVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgVertexVecDestructor_matchRefExternal(const AzSvgVertexVecDestructor* value, const AzSvgVertexVecDestructorType** restrict out) {
    const AzSvgVertexVecDestructorVariant_External* casted = (const AzSvgVertexVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzSvgVertexVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgVertexVecDestructor_matchMutExternal(AzSvgVertexVecDestructor* restrict value, AzSvgVertexVecDestructorType* restrict * restrict out) {
    AzSvgVertexVecDestructorVariant_External* restrict casted = (AzSvgVertexVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzSvgVertexVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzU32VecDestructor_matchRefExternal(const AzU32VecDestructor* value, const AzU32VecDestructorType** restrict out) {
    const AzU32VecDestructorVariant_External* casted = (const AzU32VecDestructorVariant_External*)value;
    bool valid = casted->tag == AzU32VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzU32VecDestructor_matchMutExternal(AzU32VecDestructor* restrict value, AzU32VecDestructorType* restrict * restrict out) {
    AzU32VecDestructorVariant_External* restrict casted = (AzU32VecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzU32VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXWindowTypeVecDestructor_matchRefExternal(const AzXWindowTypeVecDestructor* value, const AzXWindowTypeVecDestructorType** restrict out) {
    const AzXWindowTypeVecDestructorVariant_External* casted = (const AzXWindowTypeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzXWindowTypeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXWindowTypeVecDestructor_matchMutExternal(AzXWindowTypeVecDestructor* restrict value, AzXWindowTypeVecDestructorType* restrict * restrict out) {
    AzXWindowTypeVecDestructorVariant_External* restrict casted = (AzXWindowTypeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzXWindowTypeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzVirtualKeyCodeVecDestructor_matchRefExternal(const AzVirtualKeyCodeVecDestructor* value, const AzVirtualKeyCodeVecDestructorType** restrict out) {
    const AzVirtualKeyCodeVecDestructorVariant_External* casted = (const AzVirtualKeyCodeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzVirtualKeyCodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzVirtualKeyCodeVecDestructor_matchMutExternal(AzVirtualKeyCodeVecDestructor* restrict value, AzVirtualKeyCodeVecDestructorType* restrict * restrict out) {
    AzVirtualKeyCodeVecDestructorVariant_External* restrict casted = (AzVirtualKeyCodeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzVirtualKeyCodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCascadeInfoVecDestructor_matchRefExternal(const AzCascadeInfoVecDestructor* value, const AzCascadeInfoVecDestructorType** restrict out) {
    const AzCascadeInfoVecDestructorVariant_External* casted = (const AzCascadeInfoVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzCascadeInfoVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCascadeInfoVecDestructor_matchMutExternal(AzCascadeInfoVecDestructor* restrict value, AzCascadeInfoVecDestructorType* restrict * restrict out) {
    AzCascadeInfoVecDestructorVariant_External* restrict casted = (AzCascadeInfoVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzCascadeInfoVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzScanCodeVecDestructor_matchRefExternal(const AzScanCodeVecDestructor* value, const AzScanCodeVecDestructorType** restrict out) {
    const AzScanCodeVecDestructorVariant_External* casted = (const AzScanCodeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzScanCodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzScanCodeVecDestructor_matchMutExternal(AzScanCodeVecDestructor* restrict value, AzScanCodeVecDestructorType* restrict * restrict out) {
    AzScanCodeVecDestructorVariant_External* restrict casted = (AzScanCodeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzScanCodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssDeclarationVecDestructor_matchRefExternal(const AzCssDeclarationVecDestructor* value, const AzCssDeclarationVecDestructorType** restrict out) {
    const AzCssDeclarationVecDestructorVariant_External* casted = (const AzCssDeclarationVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzCssDeclarationVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssDeclarationVecDestructor_matchMutExternal(AzCssDeclarationVecDestructor* restrict value, AzCssDeclarationVecDestructorType* restrict * restrict out) {
    AzCssDeclarationVecDestructorVariant_External* restrict casted = (AzCssDeclarationVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzCssDeclarationVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelectorVecDestructor_matchRefExternal(const AzCssPathSelectorVecDestructor* value, const AzCssPathSelectorVecDestructorType** restrict out) {
    const AzCssPathSelectorVecDestructorVariant_External* casted = (const AzCssPathSelectorVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzCssPathSelectorVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssPathSelectorVecDestructor_matchMutExternal(AzCssPathSelectorVecDestructor* restrict value, AzCssPathSelectorVecDestructorType* restrict * restrict out) {
    AzCssPathSelectorVecDestructorVariant_External* restrict casted = (AzCssPathSelectorVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzCssPathSelectorVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStylesheetVecDestructor_matchRefExternal(const AzStylesheetVecDestructor* value, const AzStylesheetVecDestructorType** restrict out) {
    const AzStylesheetVecDestructorVariant_External* casted = (const AzStylesheetVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStylesheetVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStylesheetVecDestructor_matchMutExternal(AzStylesheetVecDestructor* restrict value, AzStylesheetVecDestructorType* restrict * restrict out) {
    AzStylesheetVecDestructorVariant_External* restrict casted = (AzStylesheetVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStylesheetVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssRuleBlockVecDestructor_matchRefExternal(const AzCssRuleBlockVecDestructor* value, const AzCssRuleBlockVecDestructorType** restrict out) {
    const AzCssRuleBlockVecDestructorVariant_External* casted = (const AzCssRuleBlockVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzCssRuleBlockVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCssRuleBlockVecDestructor_matchMutExternal(AzCssRuleBlockVecDestructor* restrict value, AzCssRuleBlockVecDestructorType* restrict * restrict out) {
    AzCssRuleBlockVecDestructorVariant_External* restrict casted = (AzCssRuleBlockVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzCssRuleBlockVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzF32VecDestructor_matchRefExternal(const AzF32VecDestructor* value, const AzF32VecDestructorType** restrict out) {
    const AzF32VecDestructorVariant_External* casted = (const AzF32VecDestructorVariant_External*)value;
    bool valid = casted->tag == AzF32VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzF32VecDestructor_matchMutExternal(AzF32VecDestructor* restrict value, AzF32VecDestructorType* restrict * restrict out) {
    AzF32VecDestructorVariant_External* restrict casted = (AzF32VecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzF32VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzU16VecDestructor_matchRefExternal(const AzU16VecDestructor* value, const AzU16VecDestructorType** restrict out) {
    const AzU16VecDestructorVariant_External* casted = (const AzU16VecDestructorVariant_External*)value;
    bool valid = casted->tag == AzU16VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzU16VecDestructor_matchMutExternal(AzU16VecDestructor* restrict value, AzU16VecDestructorType* restrict * restrict out) {
    AzU16VecDestructorVariant_External* restrict casted = (AzU16VecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzU16VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzU8VecDestructor_matchRefExternal(const AzU8VecDestructor* value, const AzU8VecDestructorType** restrict out) {
    const AzU8VecDestructorVariant_External* casted = (const AzU8VecDestructorVariant_External*)value;
    bool valid = casted->tag == AzU8VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzU8VecDestructor_matchMutExternal(AzU8VecDestructor* restrict value, AzU8VecDestructorType* restrict * restrict out) {
    AzU8VecDestructorVariant_External* restrict casted = (AzU8VecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzU8VecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCallbackDataVecDestructor_matchRefExternal(const AzCallbackDataVecDestructor* value, const AzCallbackDataVecDestructorType** restrict out) {
    const AzCallbackDataVecDestructorVariant_External* casted = (const AzCallbackDataVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzCallbackDataVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzCallbackDataVecDestructor_matchMutExternal(AzCallbackDataVecDestructor* restrict value, AzCallbackDataVecDestructorType* restrict * restrict out) {
    AzCallbackDataVecDestructorVariant_External* restrict casted = (AzCallbackDataVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzCallbackDataVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDebugMessageVecDestructor_matchRefExternal(const AzDebugMessageVecDestructor* value, const AzDebugMessageVecDestructorType** restrict out) {
    const AzDebugMessageVecDestructorVariant_External* casted = (const AzDebugMessageVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzDebugMessageVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzDebugMessageVecDestructor_matchMutExternal(AzDebugMessageVecDestructor* restrict value, AzDebugMessageVecDestructorType* restrict * restrict out) {
    AzDebugMessageVecDestructorVariant_External* restrict casted = (AzDebugMessageVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzDebugMessageVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzGLuintVecDestructor_matchRefExternal(const AzGLuintVecDestructor* value, const AzGLuintVecDestructorType** restrict out) {
    const AzGLuintVecDestructorVariant_External* casted = (const AzGLuintVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzGLuintVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzGLuintVecDestructor_matchMutExternal(AzGLuintVecDestructor* restrict value, AzGLuintVecDestructorType* restrict * restrict out) {
    AzGLuintVecDestructorVariant_External* restrict casted = (AzGLuintVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzGLuintVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzGLintVecDestructor_matchRefExternal(const AzGLintVecDestructor* value, const AzGLintVecDestructorType** restrict out) {
    const AzGLintVecDestructorVariant_External* casted = (const AzGLintVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzGLintVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzGLintVecDestructor_matchMutExternal(AzGLintVecDestructor* restrict value, AzGLintVecDestructorType* restrict * restrict out) {
    AzGLintVecDestructorVariant_External* restrict casted = (AzGLintVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzGLintVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStringVecDestructor_matchRefExternal(const AzStringVecDestructor* value, const AzStringVecDestructorType** restrict out) {
    const AzStringVecDestructorVariant_External* casted = (const AzStringVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStringVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStringVecDestructor_matchMutExternal(AzStringVecDestructor* restrict value, AzStringVecDestructorType* restrict * restrict out) {
    AzStringVecDestructorVariant_External* restrict casted = (AzStringVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStringVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStringPairVecDestructor_matchRefExternal(const AzStringPairVecDestructor* value, const AzStringPairVecDestructorType** restrict out) {
    const AzStringPairVecDestructorVariant_External* casted = (const AzStringPairVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStringPairVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStringPairVecDestructor_matchMutExternal(AzStringPairVecDestructor* restrict value, AzStringPairVecDestructorType* restrict * restrict out) {
    AzStringPairVecDestructorVariant_External* restrict casted = (AzStringPairVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStringPairVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNormalizedLinearColorStopVecDestructor_matchRefExternal(const AzNormalizedLinearColorStopVecDestructor* value, const AzNormalizedLinearColorStopVecDestructorType** restrict out) {
    const AzNormalizedLinearColorStopVecDestructorVariant_External* casted = (const AzNormalizedLinearColorStopVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzNormalizedLinearColorStopVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNormalizedLinearColorStopVecDestructor_matchMutExternal(AzNormalizedLinearColorStopVecDestructor* restrict value, AzNormalizedLinearColorStopVecDestructorType* restrict * restrict out) {
    AzNormalizedLinearColorStopVecDestructorVariant_External* restrict casted = (AzNormalizedLinearColorStopVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzNormalizedLinearColorStopVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNormalizedRadialColorStopVecDestructor_matchRefExternal(const AzNormalizedRadialColorStopVecDestructor* value, const AzNormalizedRadialColorStopVecDestructorType** restrict out) {
    const AzNormalizedRadialColorStopVecDestructorVariant_External* casted = (const AzNormalizedRadialColorStopVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzNormalizedRadialColorStopVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNormalizedRadialColorStopVecDestructor_matchMutExternal(AzNormalizedRadialColorStopVecDestructor* restrict value, AzNormalizedRadialColorStopVecDestructorType* restrict * restrict out) {
    AzNormalizedRadialColorStopVecDestructorVariant_External* restrict casted = (AzNormalizedRadialColorStopVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzNormalizedRadialColorStopVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeIdVecDestructor_matchRefExternal(const AzNodeIdVecDestructor* value, const AzNodeIdVecDestructorType** restrict out) {
    const AzNodeIdVecDestructorVariant_External* casted = (const AzNodeIdVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzNodeIdVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeIdVecDestructor_matchMutExternal(AzNodeIdVecDestructor* restrict value, AzNodeIdVecDestructorType* restrict * restrict out) {
    AzNodeIdVecDestructorVariant_External* restrict casted = (AzNodeIdVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzNodeIdVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeVecDestructor_matchRefExternal(const AzNodeVecDestructor* value, const AzNodeVecDestructorType** restrict out) {
    const AzNodeVecDestructorVariant_External* casted = (const AzNodeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeVecDestructor_matchMutExternal(AzNodeVecDestructor* restrict value, AzNodeVecDestructorType* restrict * restrict out) {
    AzNodeVecDestructorVariant_External* restrict casted = (AzNodeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyledNodeVecDestructor_matchRefExternal(const AzStyledNodeVecDestructor* value, const AzStyledNodeVecDestructorType** restrict out) {
    const AzStyledNodeVecDestructorVariant_External* casted = (const AzStyledNodeVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzStyledNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzStyledNodeVecDestructor_matchMutExternal(AzStyledNodeVecDestructor* restrict value, AzStyledNodeVecDestructorType* restrict * restrict out) {
    AzStyledNodeVecDestructorVariant_External* restrict casted = (AzStyledNodeVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzStyledNodeVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTagIdToNodeIdMappingVecDestructor_matchRefExternal(const AzTagIdToNodeIdMappingVecDestructor* value, const AzTagIdToNodeIdMappingVecDestructorType** restrict out) {
    const AzTagIdToNodeIdMappingVecDestructorVariant_External* casted = (const AzTagIdToNodeIdMappingVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzTagIdToNodeIdMappingVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzTagIdToNodeIdMappingVecDestructor_matchMutExternal(AzTagIdToNodeIdMappingVecDestructor* restrict value, AzTagIdToNodeIdMappingVecDestructorType* restrict * restrict out) {
    AzTagIdToNodeIdMappingVecDestructorVariant_External* restrict casted = (AzTagIdToNodeIdMappingVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzTagIdToNodeIdMappingVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzParentWithNodeDepthVecDestructor_matchRefExternal(const AzParentWithNodeDepthVecDestructor* value, const AzParentWithNodeDepthVecDestructorType** restrict out) {
    const AzParentWithNodeDepthVecDestructorVariant_External* casted = (const AzParentWithNodeDepthVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzParentWithNodeDepthVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzParentWithNodeDepthVecDestructor_matchMutExternal(AzParentWithNodeDepthVecDestructor* restrict value, AzParentWithNodeDepthVecDestructorType* restrict * restrict out) {
    AzParentWithNodeDepthVecDestructorVariant_External* restrict casted = (AzParentWithNodeDepthVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzParentWithNodeDepthVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataVecDestructor_matchRefExternal(const AzNodeDataVecDestructor* value, const AzNodeDataVecDestructorType** restrict out) {
    const AzNodeDataVecDestructorVariant_External* casted = (const AzNodeDataVecDestructorVariant_External*)value;
    bool valid = casted->tag == AzNodeDataVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzNodeDataVecDestructor_matchMutExternal(AzNodeDataVecDestructor* restrict value, AzNodeDataVecDestructorType* restrict * restrict out) {
    AzNodeDataVecDestructorVariant_External* restrict casted = (AzNodeDataVecDestructorVariant_External* restrict)value;
    bool valid = casted->tag == AzNodeDataVecDestructorTag_External;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionColorInputOnValueChange_matchRefSome(const AzOptionColorInputOnValueChange* value, const AzColorInputOnValueChange** restrict out) {
    const AzOptionColorInputOnValueChangeVariant_Some* casted = (const AzOptionColorInputOnValueChangeVariant_Some*)value;
    bool valid = casted->tag == AzOptionColorInputOnValueChangeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionColorInputOnValueChange_matchMutSome(AzOptionColorInputOnValueChange* restrict value, AzColorInputOnValueChange* restrict * restrict out) {
    AzOptionColorInputOnValueChangeVariant_Some* restrict casted = (AzOptionColorInputOnValueChangeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionColorInputOnValueChangeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionButtonOnClick_matchRefSome(const AzOptionButtonOnClick* value, const AzButtonOnClick** restrict out) {
    const AzOptionButtonOnClickVariant_Some* casted = (const AzOptionButtonOnClickVariant_Some*)value;
    bool valid = casted->tag == AzOptionButtonOnClickTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionButtonOnClick_matchMutSome(AzOptionButtonOnClick* restrict value, AzButtonOnClick* restrict * restrict out) {
    AzOptionButtonOnClickVariant_Some* restrict casted = (AzOptionButtonOnClickVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionButtonOnClickTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionCheckBoxOnToggle_matchRefSome(const AzOptionCheckBoxOnToggle* value, const AzCheckBoxOnToggle** restrict out) {
    const AzOptionCheckBoxOnToggleVariant_Some* casted = (const AzOptionCheckBoxOnToggleVariant_Some*)value;
    bool valid = casted->tag == AzOptionCheckBoxOnToggleTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionCheckBoxOnToggle_matchMutSome(AzOptionCheckBoxOnToggle* restrict value, AzCheckBoxOnToggle* restrict * restrict out) {
    AzOptionCheckBoxOnToggleVariant_Some* restrict casted = (AzOptionCheckBoxOnToggleVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionCheckBoxOnToggleTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputOnTextInput_matchRefSome(const AzOptionTextInputOnTextInput* value, const AzTextInputOnTextInput** restrict out) {
    const AzOptionTextInputOnTextInputVariant_Some* casted = (const AzOptionTextInputOnTextInputVariant_Some*)value;
    bool valid = casted->tag == AzOptionTextInputOnTextInputTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputOnTextInput_matchMutSome(AzOptionTextInputOnTextInput* restrict value, AzTextInputOnTextInput* restrict * restrict out) {
    AzOptionTextInputOnTextInputVariant_Some* restrict casted = (AzOptionTextInputOnTextInputVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTextInputOnTextInputTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputOnVirtualKeyDown_matchRefSome(const AzOptionTextInputOnVirtualKeyDown* value, const AzTextInputOnVirtualKeyDown** restrict out) {
    const AzOptionTextInputOnVirtualKeyDownVariant_Some* casted = (const AzOptionTextInputOnVirtualKeyDownVariant_Some*)value;
    bool valid = casted->tag == AzOptionTextInputOnVirtualKeyDownTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputOnVirtualKeyDown_matchMutSome(AzOptionTextInputOnVirtualKeyDown* restrict value, AzTextInputOnVirtualKeyDown* restrict * restrict out) {
    AzOptionTextInputOnVirtualKeyDownVariant_Some* restrict casted = (AzOptionTextInputOnVirtualKeyDownVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTextInputOnVirtualKeyDownTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputOnFocusLost_matchRefSome(const AzOptionTextInputOnFocusLost* value, const AzTextInputOnFocusLost** restrict out) {
    const AzOptionTextInputOnFocusLostVariant_Some* casted = (const AzOptionTextInputOnFocusLostVariant_Some*)value;
    bool valid = casted->tag == AzOptionTextInputOnFocusLostTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputOnFocusLost_matchMutSome(AzOptionTextInputOnFocusLost* restrict value, AzTextInputOnFocusLost* restrict * restrict out) {
    AzOptionTextInputOnFocusLostVariant_Some* restrict casted = (AzOptionTextInputOnFocusLostVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTextInputOnFocusLostTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputSelection_matchRefSome(const AzOptionTextInputSelection* value, const AzTextInputSelection** restrict out) {
    const AzOptionTextInputSelectionVariant_Some* casted = (const AzOptionTextInputSelectionVariant_Some*)value;
    bool valid = casted->tag == AzOptionTextInputSelectionTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTextInputSelection_matchMutSome(AzOptionTextInputSelection* restrict value, AzTextInputSelection* restrict * restrict out) {
    AzOptionTextInputSelectionVariant_Some* restrict casted = (AzOptionTextInputSelectionVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTextInputSelectionTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionNumberInputOnValueChange_matchRefSome(const AzOptionNumberInputOnValueChange* value, const AzNumberInputOnValueChange** restrict out) {
    const AzOptionNumberInputOnValueChangeVariant_Some* casted = (const AzOptionNumberInputOnValueChangeVariant_Some*)value;
    bool valid = casted->tag == AzOptionNumberInputOnValueChangeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionNumberInputOnValueChange_matchMutSome(AzOptionNumberInputOnValueChange* restrict value, AzNumberInputOnValueChange* restrict * restrict out) {
    AzOptionNumberInputOnValueChangeVariant_Some* restrict casted = (AzOptionNumberInputOnValueChangeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionNumberInputOnValueChangeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMenuItemIcon_matchRefSome(const AzOptionMenuItemIcon* value, const AzMenuItemIcon** restrict out) {
    const AzOptionMenuItemIconVariant_Some* casted = (const AzOptionMenuItemIconVariant_Some*)value;
    bool valid = casted->tag == AzOptionMenuItemIconTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMenuItemIcon_matchMutSome(AzOptionMenuItemIcon* restrict value, AzMenuItemIcon* restrict * restrict out) {
    AzOptionMenuItemIconVariant_Some* restrict casted = (AzOptionMenuItemIconVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionMenuItemIconTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMenuCallback_matchRefSome(const AzOptionMenuCallback* value, const AzMenuCallback** restrict out) {
    const AzOptionMenuCallbackVariant_Some* casted = (const AzOptionMenuCallbackVariant_Some*)value;
    bool valid = casted->tag == AzOptionMenuCallbackTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMenuCallback_matchMutSome(AzOptionMenuCallback* restrict value, AzMenuCallback* restrict * restrict out) {
    AzOptionMenuCallbackVariant_Some* restrict casted = (AzOptionMenuCallbackVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionMenuCallbackTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionVirtualKeyCodeCombo_matchRefSome(const AzOptionVirtualKeyCodeCombo* value, const AzVirtualKeyCodeCombo** restrict out) {
    const AzOptionVirtualKeyCodeComboVariant_Some* casted = (const AzOptionVirtualKeyCodeComboVariant_Some*)value;
    bool valid = casted->tag == AzOptionVirtualKeyCodeComboTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionVirtualKeyCodeCombo_matchMutSome(AzOptionVirtualKeyCodeCombo* restrict value, AzVirtualKeyCodeCombo* restrict * restrict out) {
    AzOptionVirtualKeyCodeComboVariant_Some* restrict casted = (AzOptionVirtualKeyCodeComboVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionVirtualKeyCodeComboTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionCssProperty_matchRefSome(const AzOptionCssProperty* value, const AzCssProperty** restrict out) {
    const AzOptionCssPropertyVariant_Some* casted = (const AzOptionCssPropertyVariant_Some*)value;
    bool valid = casted->tag == AzOptionCssPropertyTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionCssProperty_matchMutSome(AzOptionCssProperty* restrict value, AzCssProperty* restrict * restrict out) {
    AzOptionCssPropertyVariant_Some* restrict casted = (AzOptionCssPropertyVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionCssPropertyTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionPositionInfo_matchRefSome(const AzOptionPositionInfo* value, const AzPositionInfo** restrict out) {
    const AzOptionPositionInfoVariant_Some* casted = (const AzOptionPositionInfoVariant_Some*)value;
    bool valid = casted->tag == AzOptionPositionInfoTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionPositionInfo_matchMutSome(AzOptionPositionInfo* restrict value, AzPositionInfo* restrict * restrict out) {
    AzOptionPositionInfoVariant_Some* restrict casted = (AzOptionPositionInfoVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionPositionInfoTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTimerId_matchRefSome(const AzOptionTimerId* value, const AzTimerId** restrict out) {
    const AzOptionTimerIdVariant_Some* casted = (const AzOptionTimerIdVariant_Some*)value;
    bool valid = casted->tag == AzOptionTimerIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTimerId_matchMutSome(AzOptionTimerId* restrict value, AzTimerId* restrict * restrict out) {
    AzOptionTimerIdVariant_Some* restrict casted = (AzOptionTimerIdVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTimerIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionThreadId_matchRefSome(const AzOptionThreadId* value, const AzThreadId** restrict out) {
    const AzOptionThreadIdVariant_Some* casted = (const AzOptionThreadIdVariant_Some*)value;
    bool valid = casted->tag == AzOptionThreadIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionThreadId_matchMutSome(AzOptionThreadId* restrict value, AzThreadId* restrict * restrict out) {
    AzOptionThreadIdVariant_Some* restrict casted = (AzOptionThreadIdVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionThreadIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionI16_matchRefSome(const AzOptionI16* value, const Azi16** restrict out) {
    const AzOptionI16Variant_Some* casted = (const AzOptionI16Variant_Some*)value;
    bool valid = casted->tag == AzOptionI16Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionI16_matchMutSome(AzOptionI16* restrict value, Azi16* restrict * restrict out) {
    AzOptionI16Variant_Some* restrict casted = (AzOptionI16Variant_Some* restrict)value;
    bool valid = casted->tag == AzOptionI16Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU16_matchRefSome(const AzOptionU16* value, const Azu16** restrict out) {
    const AzOptionU16Variant_Some* casted = (const AzOptionU16Variant_Some*)value;
    bool valid = casted->tag == AzOptionU16Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU16_matchMutSome(AzOptionU16* restrict value, Azu16* restrict * restrict out) {
    AzOptionU16Variant_Some* restrict casted = (AzOptionU16Variant_Some* restrict)value;
    bool valid = casted->tag == AzOptionU16Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU32_matchRefSome(const AzOptionU32* value, const Azu32** restrict out) {
    const AzOptionU32Variant_Some* casted = (const AzOptionU32Variant_Some*)value;
    bool valid = casted->tag == AzOptionU32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU32_matchMutSome(AzOptionU32* restrict value, Azu32* restrict * restrict out) {
    AzOptionU32Variant_Some* restrict casted = (AzOptionU32Variant_Some* restrict)value;
    bool valid = casted->tag == AzOptionU32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionImageRef_matchRefSome(const AzOptionImageRef* value, const AzImageRef** restrict out) {
    const AzOptionImageRefVariant_Some* casted = (const AzOptionImageRefVariant_Some*)value;
    bool valid = casted->tag == AzOptionImageRefTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionImageRef_matchMutSome(AzOptionImageRef* restrict value, AzImageRef* restrict * restrict out) {
    AzOptionImageRefVariant_Some* restrict casted = (AzOptionImageRefVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionImageRefTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionFontRef_matchRefSome(const AzOptionFontRef* value, const AzFontRef** restrict out) {
    const AzOptionFontRefVariant_Some* casted = (const AzOptionFontRefVariant_Some*)value;
    bool valid = casted->tag == AzOptionFontRefTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionFontRef_matchMutSome(AzOptionFontRef* restrict value, AzFontRef* restrict * restrict out) {
    AzOptionFontRefVariant_Some* restrict casted = (AzOptionFontRefVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionFontRefTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionSystemClipboard_matchRefSome(const AzOptionSystemClipboard* value, const AzSystemClipboard** restrict out) {
    const AzOptionSystemClipboardVariant_Some* casted = (const AzOptionSystemClipboardVariant_Some*)value;
    bool valid = casted->tag == AzOptionSystemClipboardTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionSystemClipboard_matchMutSome(AzOptionSystemClipboard* restrict value, AzSystemClipboard* restrict * restrict out) {
    AzOptionSystemClipboardVariant_Some* restrict casted = (AzOptionSystemClipboardVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionSystemClipboardTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionFileTypeList_matchRefSome(const AzOptionFileTypeList* value, const AzFileTypeList** restrict out) {
    const AzOptionFileTypeListVariant_Some* casted = (const AzOptionFileTypeListVariant_Some*)value;
    bool valid = casted->tag == AzOptionFileTypeListTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionFileTypeList_matchMutSome(AzOptionFileTypeList* restrict value, AzFileTypeList* restrict * restrict out) {
    AzOptionFileTypeListVariant_Some* restrict casted = (AzOptionFileTypeListVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionFileTypeListTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWindowState_matchRefSome(const AzOptionWindowState* value, const AzWindowState** restrict out) {
    const AzOptionWindowStateVariant_Some* casted = (const AzOptionWindowStateVariant_Some*)value;
    bool valid = casted->tag == AzOptionWindowStateTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWindowState_matchMutSome(AzOptionWindowState* restrict value, AzWindowState* restrict * restrict out) {
    AzOptionWindowStateVariant_Some* restrict casted = (AzOptionWindowStateVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionWindowStateTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMouseState_matchRefSome(const AzOptionMouseState* value, const AzMouseState** restrict out) {
    const AzOptionMouseStateVariant_Some* casted = (const AzOptionMouseStateVariant_Some*)value;
    bool valid = casted->tag == AzOptionMouseStateTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMouseState_matchMutSome(AzOptionMouseState* restrict value, AzMouseState* restrict * restrict out) {
    AzOptionMouseStateVariant_Some* restrict casted = (AzOptionMouseStateVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionMouseStateTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionKeyboardState_matchRefSome(const AzOptionKeyboardState* value, const AzKeyboardState** restrict out) {
    const AzOptionKeyboardStateVariant_Some* casted = (const AzOptionKeyboardStateVariant_Some*)value;
    bool valid = casted->tag == AzOptionKeyboardStateTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionKeyboardState_matchMutSome(AzOptionKeyboardState* restrict value, AzKeyboardState* restrict * restrict out) {
    AzOptionKeyboardStateVariant_Some* restrict casted = (AzOptionKeyboardStateVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionKeyboardStateTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionStringVec_matchRefSome(const AzOptionStringVec* value, const AzStringVec** restrict out) {
    const AzOptionStringVecVariant_Some* casted = (const AzOptionStringVecVariant_Some*)value;
    bool valid = casted->tag == AzOptionStringVecTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionStringVec_matchMutSome(AzOptionStringVec* restrict value, AzStringVec* restrict * restrict out) {
    AzOptionStringVecVariant_Some* restrict casted = (AzOptionStringVecVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionStringVecTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionFile_matchRefSome(const AzOptionFile* value, const AzFile** restrict out) {
    const AzOptionFileVariant_Some* casted = (const AzOptionFileVariant_Some*)value;
    bool valid = casted->tag == AzOptionFileTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionFile_matchMutSome(AzOptionFile* restrict value, AzFile* restrict * restrict out) {
    AzOptionFileVariant_Some* restrict casted = (AzOptionFileVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionFileTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionGl_matchRefSome(const AzOptionGl* value, const AzGl** restrict out) {
    const AzOptionGlVariant_Some* casted = (const AzOptionGlVariant_Some*)value;
    bool valid = casted->tag == AzOptionGlTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionGl_matchMutSome(AzOptionGl* restrict value, AzGl* restrict * restrict out) {
    AzOptionGlVariant_Some* restrict casted = (AzOptionGlVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionGlTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionThreadReceiveMsg_matchRefSome(const AzOptionThreadReceiveMsg* value, const AzThreadReceiveMsg** restrict out) {
    const AzOptionThreadReceiveMsgVariant_Some* casted = (const AzOptionThreadReceiveMsgVariant_Some*)value;
    bool valid = casted->tag == AzOptionThreadReceiveMsgTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionThreadReceiveMsg_matchMutSome(AzOptionThreadReceiveMsg* restrict value, AzThreadReceiveMsg* restrict * restrict out) {
    AzOptionThreadReceiveMsgVariant_Some* restrict casted = (AzOptionThreadReceiveMsgVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionThreadReceiveMsgTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionPercentageValue_matchRefSome(const AzOptionPercentageValue* value, const AzPercentageValue** restrict out) {
    const AzOptionPercentageValueVariant_Some* casted = (const AzOptionPercentageValueVariant_Some*)value;
    bool valid = casted->tag == AzOptionPercentageValueTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionPercentageValue_matchMutSome(AzOptionPercentageValue* restrict value, AzPercentageValue* restrict * restrict out) {
    AzOptionPercentageValueVariant_Some* restrict casted = (AzOptionPercentageValueVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionPercentageValueTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionAngleValue_matchRefSome(const AzOptionAngleValue* value, const AzAngleValue** restrict out) {
    const AzOptionAngleValueVariant_Some* casted = (const AzOptionAngleValueVariant_Some*)value;
    bool valid = casted->tag == AzOptionAngleValueTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionAngleValue_matchMutSome(AzOptionAngleValue* restrict value, AzAngleValue* restrict * restrict out) {
    AzOptionAngleValueVariant_Some* restrict casted = (AzOptionAngleValueVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionAngleValueTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionRendererOptions_matchRefSome(const AzOptionRendererOptions* value, const AzRendererOptions** restrict out) {
    const AzOptionRendererOptionsVariant_Some* casted = (const AzOptionRendererOptionsVariant_Some*)value;
    bool valid = casted->tag == AzOptionRendererOptionsTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionRendererOptions_matchMutSome(AzOptionRendererOptions* restrict value, AzRendererOptions* restrict * restrict out) {
    AzOptionRendererOptionsVariant_Some* restrict casted = (AzOptionRendererOptionsVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionRendererOptionsTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionCallback_matchRefSome(const AzOptionCallback* value, const AzCallback** restrict out) {
    const AzOptionCallbackVariant_Some* casted = (const AzOptionCallbackVariant_Some*)value;
    bool valid = casted->tag == AzOptionCallbackTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionCallback_matchMutSome(AzOptionCallback* restrict value, AzCallback* restrict * restrict out) {
    AzOptionCallbackVariant_Some* restrict casted = (AzOptionCallbackVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionCallbackTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionThreadSendMsg_matchRefSome(const AzOptionThreadSendMsg* value, const AzThreadSendMsg** restrict out) {
    const AzOptionThreadSendMsgVariant_Some* casted = (const AzOptionThreadSendMsgVariant_Some*)value;
    bool valid = casted->tag == AzOptionThreadSendMsgTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionThreadSendMsg_matchMutSome(AzOptionThreadSendMsg* restrict value, AzThreadSendMsg* restrict * restrict out) {
    AzOptionThreadSendMsgVariant_Some* restrict casted = (AzOptionThreadSendMsgVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionThreadSendMsgTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLayoutRect_matchRefSome(const AzOptionLayoutRect* value, const AzLayoutRect** restrict out) {
    const AzOptionLayoutRectVariant_Some* casted = (const AzOptionLayoutRectVariant_Some*)value;
    bool valid = casted->tag == AzOptionLayoutRectTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLayoutRect_matchMutSome(AzOptionLayoutRect* restrict value, AzLayoutRect* restrict * restrict out) {
    AzOptionLayoutRectVariant_Some* restrict casted = (AzOptionLayoutRectVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionLayoutRectTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionRefAny_matchRefSome(const AzOptionRefAny* value, const AzRefAny** restrict out) {
    const AzOptionRefAnyVariant_Some* casted = (const AzOptionRefAnyVariant_Some*)value;
    bool valid = casted->tag == AzOptionRefAnyTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionRefAny_matchMutSome(AzOptionRefAny* restrict value, AzRefAny* restrict * restrict out) {
    AzOptionRefAnyVariant_Some* restrict casted = (AzOptionRefAnyVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionRefAnyTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionInlineText_matchRefSome(const AzOptionInlineText* value, const AzInlineText** restrict out) {
    const AzOptionInlineTextVariant_Some* casted = (const AzOptionInlineTextVariant_Some*)value;
    bool valid = casted->tag == AzOptionInlineTextTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionInlineText_matchMutSome(AzOptionInlineText* restrict value, AzInlineText* restrict * restrict out) {
    AzOptionInlineTextVariant_Some* restrict casted = (AzOptionInlineTextVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionInlineTextTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLayoutPoint_matchRefSome(const AzOptionLayoutPoint* value, const AzLayoutPoint** restrict out) {
    const AzOptionLayoutPointVariant_Some* casted = (const AzOptionLayoutPointVariant_Some*)value;
    bool valid = casted->tag == AzOptionLayoutPointTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLayoutPoint_matchMutSome(AzOptionLayoutPoint* restrict value, AzLayoutPoint* restrict * restrict out) {
    AzOptionLayoutPointVariant_Some* restrict casted = (AzOptionLayoutPointVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionLayoutPointTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLayoutSize_matchRefSome(const AzOptionLayoutSize* value, const AzLayoutSize** restrict out) {
    const AzOptionLayoutSizeVariant_Some* casted = (const AzOptionLayoutSizeVariant_Some*)value;
    bool valid = casted->tag == AzOptionLayoutSizeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLayoutSize_matchMutSome(AzOptionLayoutSize* restrict value, AzLayoutSize* restrict * restrict out) {
    AzOptionLayoutSizeVariant_Some* restrict casted = (AzOptionLayoutSizeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionLayoutSizeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWindowTheme_matchRefSome(const AzOptionWindowTheme* value, const AzWindowTheme** restrict out) {
    const AzOptionWindowThemeVariant_Some* casted = (const AzOptionWindowThemeVariant_Some*)value;
    bool valid = casted->tag == AzOptionWindowThemeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWindowTheme_matchMutSome(AzOptionWindowTheme* restrict value, AzWindowTheme* restrict * restrict out) {
    AzOptionWindowThemeVariant_Some* restrict casted = (AzOptionWindowThemeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionWindowThemeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionNodeId_matchRefSome(const AzOptionNodeId* value, const AzNodeId** restrict out) {
    const AzOptionNodeIdVariant_Some* casted = (const AzOptionNodeIdVariant_Some*)value;
    bool valid = casted->tag == AzOptionNodeIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionNodeId_matchMutSome(AzOptionNodeId* restrict value, AzNodeId* restrict * restrict out) {
    AzOptionNodeIdVariant_Some* restrict casted = (AzOptionNodeIdVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionNodeIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionDomNodeId_matchRefSome(const AzOptionDomNodeId* value, const AzDomNodeId** restrict out) {
    const AzOptionDomNodeIdVariant_Some* casted = (const AzOptionDomNodeIdVariant_Some*)value;
    bool valid = casted->tag == AzOptionDomNodeIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionDomNodeId_matchMutSome(AzOptionDomNodeId* restrict value, AzDomNodeId* restrict * restrict out) {
    AzOptionDomNodeIdVariant_Some* restrict casted = (AzOptionDomNodeIdVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionDomNodeIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionColorU_matchRefSome(const AzOptionColorU* value, const AzColorU** restrict out) {
    const AzOptionColorUVariant_Some* casted = (const AzOptionColorUVariant_Some*)value;
    bool valid = casted->tag == AzOptionColorUTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionColorU_matchMutSome(AzOptionColorU* restrict value, AzColorU* restrict * restrict out) {
    AzOptionColorUVariant_Some* restrict casted = (AzOptionColorUVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionColorUTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionRawImage_matchRefSome(const AzOptionRawImage* value, const AzRawImage** restrict out) {
    const AzOptionRawImageVariant_Some* casted = (const AzOptionRawImageVariant_Some*)value;
    bool valid = casted->tag == AzOptionRawImageTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionRawImage_matchMutSome(AzOptionRawImage* restrict value, AzRawImage* restrict * restrict out) {
    AzOptionRawImageVariant_Some* restrict casted = (AzOptionRawImageVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionRawImageTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionSvgDashPattern_matchRefSome(const AzOptionSvgDashPattern* value, const AzSvgDashPattern** restrict out) {
    const AzOptionSvgDashPatternVariant_Some* casted = (const AzOptionSvgDashPatternVariant_Some*)value;
    bool valid = casted->tag == AzOptionSvgDashPatternTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionSvgDashPattern_matchMutSome(AzOptionSvgDashPattern* restrict value, AzSvgDashPattern* restrict * restrict out) {
    AzOptionSvgDashPatternVariant_Some* restrict casted = (AzOptionSvgDashPatternVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionSvgDashPatternTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWaylandTheme_matchRefSome(const AzOptionWaylandTheme* value, const AzWaylandTheme** restrict out) {
    const AzOptionWaylandThemeVariant_Some* casted = (const AzOptionWaylandThemeVariant_Some*)value;
    bool valid = casted->tag == AzOptionWaylandThemeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWaylandTheme_matchMutSome(AzOptionWaylandTheme* restrict value, AzWaylandTheme* restrict * restrict out) {
    AzOptionWaylandThemeVariant_Some* restrict casted = (AzOptionWaylandThemeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionWaylandThemeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTaskBarIcon_matchRefSome(const AzOptionTaskBarIcon* value, const AzTaskBarIcon** restrict out) {
    const AzOptionTaskBarIconVariant_Some* casted = (const AzOptionTaskBarIconVariant_Some*)value;
    bool valid = casted->tag == AzOptionTaskBarIconTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTaskBarIcon_matchMutSome(AzOptionTaskBarIcon* restrict value, AzTaskBarIcon* restrict * restrict out) {
    AzOptionTaskBarIconVariant_Some* restrict casted = (AzOptionTaskBarIconVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTaskBarIconTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionHwndHandle_matchRefSome(const AzOptionHwndHandle* value, const Az*mut c_void** restrict out) {
    const AzOptionHwndHandleVariant_Some* casted = (const AzOptionHwndHandleVariant_Some*)value;
    bool valid = casted->tag == AzOptionHwndHandleTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionHwndHandle_matchMutSome(AzOptionHwndHandle* restrict value, Az*mut c_void* restrict * restrict out) {
    AzOptionHwndHandleVariant_Some* restrict casted = (AzOptionHwndHandleVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionHwndHandleTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLogicalPosition_matchRefSome(const AzOptionLogicalPosition* value, const AzLogicalPosition** restrict out) {
    const AzOptionLogicalPositionVariant_Some* casted = (const AzOptionLogicalPositionVariant_Some*)value;
    bool valid = casted->tag == AzOptionLogicalPositionTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLogicalPosition_matchMutSome(AzOptionLogicalPosition* restrict value, AzLogicalPosition* restrict * restrict out) {
    AzOptionLogicalPositionVariant_Some* restrict casted = (AzOptionLogicalPositionVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionLogicalPositionTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionPhysicalPositionI32_matchRefSome(const AzOptionPhysicalPositionI32* value, const AzPhysicalPositionI32** restrict out) {
    const AzOptionPhysicalPositionI32Variant_Some* casted = (const AzOptionPhysicalPositionI32Variant_Some*)value;
    bool valid = casted->tag == AzOptionPhysicalPositionI32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionPhysicalPositionI32_matchMutSome(AzOptionPhysicalPositionI32* restrict value, AzPhysicalPositionI32* restrict * restrict out) {
    AzOptionPhysicalPositionI32Variant_Some* restrict casted = (AzOptionPhysicalPositionI32Variant_Some* restrict)value;
    bool valid = casted->tag == AzOptionPhysicalPositionI32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWindowIcon_matchRefSome(const AzOptionWindowIcon* value, const AzWindowIcon** restrict out) {
    const AzOptionWindowIconVariant_Some* casted = (const AzOptionWindowIconVariant_Some*)value;
    bool valid = casted->tag == AzOptionWindowIconTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionWindowIcon_matchMutSome(AzOptionWindowIcon* restrict value, AzWindowIcon* restrict * restrict out) {
    AzOptionWindowIconVariant_Some* restrict casted = (AzOptionWindowIconVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionWindowIconTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionString_matchRefSome(const AzOptionString* value, const AzString** restrict out) {
    const AzOptionStringVariant_Some* casted = (const AzOptionStringVariant_Some*)value;
    bool valid = casted->tag == AzOptionStringTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionString_matchMutSome(AzOptionString* restrict value, AzString* restrict * restrict out) {
    AzOptionStringVariant_Some* restrict casted = (AzOptionStringVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionStringTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionX11Visual_matchRefSome(const AzOptionX11Visual* value, const Az*const c_void** restrict out) {
    const AzOptionX11VisualVariant_Some* casted = (const AzOptionX11VisualVariant_Some*)value;
    bool valid = casted->tag == AzOptionX11VisualTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionX11Visual_matchMutSome(AzOptionX11Visual* restrict value, Az*const c_void* restrict * restrict out) {
    AzOptionX11VisualVariant_Some* restrict casted = (AzOptionX11VisualVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionX11VisualTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionI32_matchRefSome(const AzOptionI32* value, const Azi32** restrict out) {
    const AzOptionI32Variant_Some* casted = (const AzOptionI32Variant_Some*)value;
    bool valid = casted->tag == AzOptionI32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionI32_matchMutSome(AzOptionI32* restrict value, Azi32* restrict * restrict out) {
    AzOptionI32Variant_Some* restrict casted = (AzOptionI32Variant_Some* restrict)value;
    bool valid = casted->tag == AzOptionI32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionF32_matchRefSome(const AzOptionF32* value, const Azf32** restrict out) {
    const AzOptionF32Variant_Some* casted = (const AzOptionF32Variant_Some*)value;
    bool valid = casted->tag == AzOptionF32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionF32_matchMutSome(AzOptionF32* restrict value, Azf32* restrict * restrict out) {
    AzOptionF32Variant_Some* restrict casted = (AzOptionF32Variant_Some* restrict)value;
    bool valid = casted->tag == AzOptionF32Tag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMouseCursorType_matchRefSome(const AzOptionMouseCursorType* value, const AzMouseCursorType** restrict out) {
    const AzOptionMouseCursorTypeVariant_Some* casted = (const AzOptionMouseCursorTypeVariant_Some*)value;
    bool valid = casted->tag == AzOptionMouseCursorTypeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionMouseCursorType_matchMutSome(AzOptionMouseCursorType* restrict value, AzMouseCursorType* restrict * restrict out) {
    AzOptionMouseCursorTypeVariant_Some* restrict casted = (AzOptionMouseCursorTypeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionMouseCursorTypeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLogicalSize_matchRefSome(const AzOptionLogicalSize* value, const AzLogicalSize** restrict out) {
    const AzOptionLogicalSizeVariant_Some* casted = (const AzOptionLogicalSizeVariant_Some*)value;
    bool valid = casted->tag == AzOptionLogicalSizeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionLogicalSize_matchMutSome(AzOptionLogicalSize* restrict value, AzLogicalSize* restrict * restrict out) {
    AzOptionLogicalSizeVariant_Some* restrict casted = (AzOptionLogicalSizeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionLogicalSizeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionChar_matchRefSome(const AzOptionChar* value, const Azu32** restrict out) {
    const AzOptionCharVariant_Some* casted = (const AzOptionCharVariant_Some*)value;
    bool valid = casted->tag == AzOptionCharTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionChar_matchMutSome(AzOptionChar* restrict value, Azu32* restrict * restrict out) {
    AzOptionCharVariant_Some* restrict casted = (AzOptionCharVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionCharTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionVirtualKeyCode_matchRefSome(const AzOptionVirtualKeyCode* value, const AzVirtualKeyCode** restrict out) {
    const AzOptionVirtualKeyCodeVariant_Some* casted = (const AzOptionVirtualKeyCodeVariant_Some*)value;
    bool valid = casted->tag == AzOptionVirtualKeyCodeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionVirtualKeyCode_matchMutSome(AzOptionVirtualKeyCode* restrict value, AzVirtualKeyCode* restrict * restrict out) {
    AzOptionVirtualKeyCodeVariant_Some* restrict casted = (AzOptionVirtualKeyCodeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionVirtualKeyCodeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionDom_matchRefSome(const AzOptionDom* value, const AzDom** restrict out) {
    const AzOptionDomVariant_Some* casted = (const AzOptionDomVariant_Some*)value;
    bool valid = casted->tag == AzOptionDomTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionDom_matchMutSome(AzOptionDom* restrict value, AzDom* restrict * restrict out) {
    AzOptionDomVariant_Some* restrict casted = (AzOptionDomVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionDomTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTexture_matchRefSome(const AzOptionTexture* value, const AzTexture** restrict out) {
    const AzOptionTextureVariant_Some* casted = (const AzOptionTextureVariant_Some*)value;
    bool valid = casted->tag == AzOptionTextureTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTexture_matchMutSome(AzOptionTexture* restrict value, AzTexture* restrict * restrict out) {
    AzOptionTextureVariant_Some* restrict casted = (AzOptionTextureVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTextureTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionImageMask_matchRefSome(const AzOptionImageMask* value, const AzImageMask** restrict out) {
    const AzOptionImageMaskVariant_Some* casted = (const AzOptionImageMaskVariant_Some*)value;
    bool valid = casted->tag == AzOptionImageMaskTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionImageMask_matchMutSome(AzOptionImageMask* restrict value, AzImageMask* restrict * restrict out) {
    AzOptionImageMaskVariant_Some* restrict casted = (AzOptionImageMaskVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionImageMaskTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTabIndex_matchRefSome(const AzOptionTabIndex* value, const AzTabIndex** restrict out) {
    const AzOptionTabIndexVariant_Some* casted = (const AzOptionTabIndexVariant_Some*)value;
    bool valid = casted->tag == AzOptionTabIndexTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTabIndex_matchMutSome(AzOptionTabIndex* restrict value, AzTabIndex* restrict * restrict out) {
    AzOptionTabIndexVariant_Some* restrict casted = (AzOptionTabIndexVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTabIndexTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTagId_matchRefSome(const AzOptionTagId* value, const AzTagId** restrict out) {
    const AzOptionTagIdVariant_Some* casted = (const AzOptionTagIdVariant_Some*)value;
    bool valid = casted->tag == AzOptionTagIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionTagId_matchMutSome(AzOptionTagId* restrict value, AzTagId* restrict * restrict out) {
    AzOptionTagIdVariant_Some* restrict casted = (AzOptionTagIdVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionTagIdTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionDuration_matchRefSome(const AzOptionDuration* value, const AzDuration** restrict out) {
    const AzOptionDurationVariant_Some* casted = (const AzOptionDurationVariant_Some*)value;
    bool valid = casted->tag == AzOptionDurationTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionDuration_matchMutSome(AzOptionDuration* restrict value, AzDuration* restrict * restrict out) {
    AzOptionDurationVariant_Some* restrict casted = (AzOptionDurationVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionDurationTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionInstant_matchRefSome(const AzOptionInstant* value, const AzInstant** restrict out) {
    const AzOptionInstantVariant_Some* casted = (const AzOptionInstantVariant_Some*)value;
    bool valid = casted->tag == AzOptionInstantTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionInstant_matchMutSome(AzOptionInstant* restrict value, AzInstant* restrict * restrict out) {
    AzOptionInstantVariant_Some* restrict casted = (AzOptionInstantVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionInstantTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionUsize_matchRefSome(const AzOptionUsize* value, const Azusize** restrict out) {
    const AzOptionUsizeVariant_Some* casted = (const AzOptionUsizeVariant_Some*)value;
    bool valid = casted->tag == AzOptionUsizeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionUsize_matchMutSome(AzOptionUsize* restrict value, Azusize* restrict * restrict out) {
    AzOptionUsizeVariant_Some* restrict casted = (AzOptionUsizeVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionUsizeTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU8Vec_matchRefSome(const AzOptionU8Vec* value, const AzU8Vec** restrict out) {
    const AzOptionU8VecVariant_Some* casted = (const AzOptionU8VecVariant_Some*)value;
    bool valid = casted->tag == AzOptionU8VecTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU8Vec_matchMutSome(AzOptionU8Vec* restrict value, AzU8Vec* restrict * restrict out) {
    AzOptionU8VecVariant_Some* restrict casted = (AzOptionU8VecVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionU8VecTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU8VecRef_matchRefSome(const AzOptionU8VecRef* value, const AzU8VecRef** restrict out) {
    const AzOptionU8VecRefVariant_Some* casted = (const AzOptionU8VecRefVariant_Some*)value;
    bool valid = casted->tag == AzOptionU8VecRefTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzOptionU8VecRef_matchMutSome(AzOptionU8VecRef* restrict value, AzU8VecRef* restrict * restrict out) {
    AzOptionU8VecRefVariant_Some* restrict casted = (AzOptionU8VecRefVariant_Some* restrict)value;
    bool valid = casted->tag == AzOptionU8VecRefTag_Some;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultXmlXmlError_matchRefOk(const AzResultXmlXmlError* value, const AzXml** restrict out) {
    const AzResultXmlXmlErrorVariant_Ok* casted = (const AzResultXmlXmlErrorVariant_Ok*)value;
    bool valid = casted->tag == AzResultXmlXmlErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultXmlXmlError_matchMutOk(AzResultXmlXmlError* restrict value, AzXml* restrict * restrict out) {
    AzResultXmlXmlErrorVariant_Ok* restrict casted = (AzResultXmlXmlErrorVariant_Ok* restrict)value;
    bool valid = casted->tag == AzResultXmlXmlErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultXmlXmlError_matchRefErr(const AzResultXmlXmlError* value, const AzXmlError** restrict out) {
    const AzResultXmlXmlErrorVariant_Err* casted = (const AzResultXmlXmlErrorVariant_Err*)value;
    bool valid = casted->tag == AzResultXmlXmlErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultXmlXmlError_matchMutErr(AzResultXmlXmlError* restrict value, AzXmlError* restrict * restrict out) {
    AzResultXmlXmlErrorVariant_Err* restrict casted = (AzResultXmlXmlErrorVariant_Err* restrict)value;
    bool valid = casted->tag == AzResultXmlXmlErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultRawImageDecodeImageError_matchRefOk(const AzResultRawImageDecodeImageError* value, const AzRawImage** restrict out) {
    const AzResultRawImageDecodeImageErrorVariant_Ok* casted = (const AzResultRawImageDecodeImageErrorVariant_Ok*)value;
    bool valid = casted->tag == AzResultRawImageDecodeImageErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultRawImageDecodeImageError_matchMutOk(AzResultRawImageDecodeImageError* restrict value, AzRawImage* restrict * restrict out) {
    AzResultRawImageDecodeImageErrorVariant_Ok* restrict casted = (AzResultRawImageDecodeImageErrorVariant_Ok* restrict)value;
    bool valid = casted->tag == AzResultRawImageDecodeImageErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultRawImageDecodeImageError_matchRefErr(const AzResultRawImageDecodeImageError* value, const AzDecodeImageError** restrict out) {
    const AzResultRawImageDecodeImageErrorVariant_Err* casted = (const AzResultRawImageDecodeImageErrorVariant_Err*)value;
    bool valid = casted->tag == AzResultRawImageDecodeImageErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultRawImageDecodeImageError_matchMutErr(AzResultRawImageDecodeImageError* restrict value, AzDecodeImageError* restrict * restrict out) {
    AzResultRawImageDecodeImageErrorVariant_Err* restrict casted = (AzResultRawImageDecodeImageErrorVariant_Err* restrict)value;
    bool valid = casted->tag == AzResultRawImageDecodeImageErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultU8VecEncodeImageError_matchRefOk(const AzResultU8VecEncodeImageError* value, const AzU8Vec** restrict out) {
    const AzResultU8VecEncodeImageErrorVariant_Ok* casted = (const AzResultU8VecEncodeImageErrorVariant_Ok*)value;
    bool valid = casted->tag == AzResultU8VecEncodeImageErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultU8VecEncodeImageError_matchMutOk(AzResultU8VecEncodeImageError* restrict value, AzU8Vec* restrict * restrict out) {
    AzResultU8VecEncodeImageErrorVariant_Ok* restrict casted = (AzResultU8VecEncodeImageErrorVariant_Ok* restrict)value;
    bool valid = casted->tag == AzResultU8VecEncodeImageErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultU8VecEncodeImageError_matchRefErr(const AzResultU8VecEncodeImageError* value, const AzEncodeImageError** restrict out) {
    const AzResultU8VecEncodeImageErrorVariant_Err* casted = (const AzResultU8VecEncodeImageErrorVariant_Err*)value;
    bool valid = casted->tag == AzResultU8VecEncodeImageErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultU8VecEncodeImageError_matchMutErr(AzResultU8VecEncodeImageError* restrict value, AzEncodeImageError* restrict * restrict out) {
    AzResultU8VecEncodeImageErrorVariant_Err* restrict casted = (AzResultU8VecEncodeImageErrorVariant_Err* restrict)value;
    bool valid = casted->tag == AzResultU8VecEncodeImageErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgXmlNodeSvgParseError_matchRefOk(const AzResultSvgXmlNodeSvgParseError* value, const AzSvgXmlNode** restrict out) {
    const AzResultSvgXmlNodeSvgParseErrorVariant_Ok* casted = (const AzResultSvgXmlNodeSvgParseErrorVariant_Ok*)value;
    bool valid = casted->tag == AzResultSvgXmlNodeSvgParseErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgXmlNodeSvgParseError_matchMutOk(AzResultSvgXmlNodeSvgParseError* restrict value, AzSvgXmlNode* restrict * restrict out) {
    AzResultSvgXmlNodeSvgParseErrorVariant_Ok* restrict casted = (AzResultSvgXmlNodeSvgParseErrorVariant_Ok* restrict)value;
    bool valid = casted->tag == AzResultSvgXmlNodeSvgParseErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgXmlNodeSvgParseError_matchRefErr(const AzResultSvgXmlNodeSvgParseError* value, const AzSvgParseError** restrict out) {
    const AzResultSvgXmlNodeSvgParseErrorVariant_Err* casted = (const AzResultSvgXmlNodeSvgParseErrorVariant_Err*)value;
    bool valid = casted->tag == AzResultSvgXmlNodeSvgParseErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgXmlNodeSvgParseError_matchMutErr(AzResultSvgXmlNodeSvgParseError* restrict value, AzSvgParseError* restrict * restrict out) {
    AzResultSvgXmlNodeSvgParseErrorVariant_Err* restrict casted = (AzResultSvgXmlNodeSvgParseErrorVariant_Err* restrict)value;
    bool valid = casted->tag == AzResultSvgXmlNodeSvgParseErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgSvgParseError_matchRefOk(const AzResultSvgSvgParseError* value, const AzSvg** restrict out) {
    const AzResultSvgSvgParseErrorVariant_Ok* casted = (const AzResultSvgSvgParseErrorVariant_Ok*)value;
    bool valid = casted->tag == AzResultSvgSvgParseErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgSvgParseError_matchMutOk(AzResultSvgSvgParseError* restrict value, AzSvg* restrict * restrict out) {
    AzResultSvgSvgParseErrorVariant_Ok* restrict casted = (AzResultSvgSvgParseErrorVariant_Ok* restrict)value;
    bool valid = casted->tag == AzResultSvgSvgParseErrorTag_Ok;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgSvgParseError_matchRefErr(const AzResultSvgSvgParseError* value, const AzSvgParseError** restrict out) {
    const AzResultSvgSvgParseErrorVariant_Err* casted = (const AzResultSvgSvgParseErrorVariant_Err*)value;
    bool valid = casted->tag == AzResultSvgSvgParseErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzResultSvgSvgParseError_matchMutErr(AzResultSvgSvgParseError* restrict value, AzSvgParseError* restrict * restrict out) {
    AzResultSvgSvgParseErrorVariant_Err* restrict casted = (AzResultSvgSvgParseErrorVariant_Err* restrict)value;
    bool valid = casted->tag == AzResultSvgSvgParseErrorTag_Err;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgParseError_matchRefParsingFailed(const AzSvgParseError* value, const AzXmlError** restrict out) {
    const AzSvgParseErrorVariant_ParsingFailed* casted = (const AzSvgParseErrorVariant_ParsingFailed*)value;
    bool valid = casted->tag == AzSvgParseErrorTag_ParsingFailed;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzSvgParseError_matchMutParsingFailed(AzSvgParseError* restrict value, AzXmlError* restrict * restrict out) {
    AzSvgParseErrorVariant_ParsingFailed* restrict casted = (AzSvgParseErrorVariant_ParsingFailed* restrict)value;
    bool valid = casted->tag == AzSvgParseErrorTag_ParsingFailed;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefInvalidXmlPrefixUri(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_InvalidXmlPrefixUri* casted = (const AzXmlErrorVariant_InvalidXmlPrefixUri*)value;
    bool valid = casted->tag == AzXmlErrorTag_InvalidXmlPrefixUri;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutInvalidXmlPrefixUri(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_InvalidXmlPrefixUri* restrict casted = (AzXmlErrorVariant_InvalidXmlPrefixUri* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_InvalidXmlPrefixUri;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefUnexpectedXmlUri(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_UnexpectedXmlUri* casted = (const AzXmlErrorVariant_UnexpectedXmlUri*)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedXmlUri;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutUnexpectedXmlUri(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_UnexpectedXmlUri* restrict casted = (AzXmlErrorVariant_UnexpectedXmlUri* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedXmlUri;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefUnexpectedXmlnsUri(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_UnexpectedXmlnsUri* casted = (const AzXmlErrorVariant_UnexpectedXmlnsUri*)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedXmlnsUri;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutUnexpectedXmlnsUri(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_UnexpectedXmlnsUri* restrict casted = (AzXmlErrorVariant_UnexpectedXmlnsUri* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedXmlnsUri;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefInvalidElementNamePrefix(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_InvalidElementNamePrefix* casted = (const AzXmlErrorVariant_InvalidElementNamePrefix*)value;
    bool valid = casted->tag == AzXmlErrorTag_InvalidElementNamePrefix;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutInvalidElementNamePrefix(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_InvalidElementNamePrefix* restrict casted = (AzXmlErrorVariant_InvalidElementNamePrefix* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_InvalidElementNamePrefix;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefDuplicatedNamespace(const AzXmlError* value, const AzDuplicatedNamespaceError** restrict out) {
    const AzXmlErrorVariant_DuplicatedNamespace* casted = (const AzXmlErrorVariant_DuplicatedNamespace*)value;
    bool valid = casted->tag == AzXmlErrorTag_DuplicatedNamespace;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutDuplicatedNamespace(AzXmlError* restrict value, AzDuplicatedNamespaceError* restrict * restrict out) {
    AzXmlErrorVariant_DuplicatedNamespace* restrict casted = (AzXmlErrorVariant_DuplicatedNamespace* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_DuplicatedNamespace;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefUnknownNamespace(const AzXmlError* value, const AzUnknownNamespaceError** restrict out) {
    const AzXmlErrorVariant_UnknownNamespace* casted = (const AzXmlErrorVariant_UnknownNamespace*)value;
    bool valid = casted->tag == AzXmlErrorTag_UnknownNamespace;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutUnknownNamespace(AzXmlError* restrict value, AzUnknownNamespaceError* restrict * restrict out) {
    AzXmlErrorVariant_UnknownNamespace* restrict casted = (AzXmlErrorVariant_UnknownNamespace* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_UnknownNamespace;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefUnexpectedCloseTag(const AzXmlError* value, const AzUnexpectedCloseTagError** restrict out) {
    const AzXmlErrorVariant_UnexpectedCloseTag* casted = (const AzXmlErrorVariant_UnexpectedCloseTag*)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedCloseTag;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutUnexpectedCloseTag(AzXmlError* restrict value, AzUnexpectedCloseTagError* restrict * restrict out) {
    AzXmlErrorVariant_UnexpectedCloseTag* restrict casted = (AzXmlErrorVariant_UnexpectedCloseTag* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedCloseTag;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefUnexpectedEntityCloseTag(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_UnexpectedEntityCloseTag* casted = (const AzXmlErrorVariant_UnexpectedEntityCloseTag*)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedEntityCloseTag;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutUnexpectedEntityCloseTag(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_UnexpectedEntityCloseTag* restrict casted = (AzXmlErrorVariant_UnexpectedEntityCloseTag* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_UnexpectedEntityCloseTag;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefUnknownEntityReference(const AzXmlError* value, const AzUnknownEntityReferenceError** restrict out) {
    const AzXmlErrorVariant_UnknownEntityReference* casted = (const AzXmlErrorVariant_UnknownEntityReference*)value;
    bool valid = casted->tag == AzXmlErrorTag_UnknownEntityReference;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutUnknownEntityReference(AzXmlError* restrict value, AzUnknownEntityReferenceError* restrict * restrict out) {
    AzXmlErrorVariant_UnknownEntityReference* restrict casted = (AzXmlErrorVariant_UnknownEntityReference* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_UnknownEntityReference;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefMalformedEntityReference(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_MalformedEntityReference* casted = (const AzXmlErrorVariant_MalformedEntityReference*)value;
    bool valid = casted->tag == AzXmlErrorTag_MalformedEntityReference;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutMalformedEntityReference(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_MalformedEntityReference* restrict casted = (AzXmlErrorVariant_MalformedEntityReference* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_MalformedEntityReference;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefEntityReferenceLoop(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_EntityReferenceLoop* casted = (const AzXmlErrorVariant_EntityReferenceLoop*)value;
    bool valid = casted->tag == AzXmlErrorTag_EntityReferenceLoop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutEntityReferenceLoop(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_EntityReferenceLoop* restrict casted = (AzXmlErrorVariant_EntityReferenceLoop* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_EntityReferenceLoop;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefInvalidAttributeValue(const AzXmlError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlErrorVariant_InvalidAttributeValue* casted = (const AzXmlErrorVariant_InvalidAttributeValue*)value;
    bool valid = casted->tag == AzXmlErrorTag_InvalidAttributeValue;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutInvalidAttributeValue(AzXmlError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlErrorVariant_InvalidAttributeValue* restrict casted = (AzXmlErrorVariant_InvalidAttributeValue* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_InvalidAttributeValue;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefDuplicatedAttribute(const AzXmlError* value, const AzDuplicatedAttributeError** restrict out) {
    const AzXmlErrorVariant_DuplicatedAttribute* casted = (const AzXmlErrorVariant_DuplicatedAttribute*)value;
    bool valid = casted->tag == AzXmlErrorTag_DuplicatedAttribute;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutDuplicatedAttribute(AzXmlError* restrict value, AzDuplicatedAttributeError* restrict * restrict out) {
    AzXmlErrorVariant_DuplicatedAttribute* restrict casted = (AzXmlErrorVariant_DuplicatedAttribute* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_DuplicatedAttribute;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchRefParserError(const AzXmlError* value, const AzXmlParseError** restrict out) {
    const AzXmlErrorVariant_ParserError* casted = (const AzXmlErrorVariant_ParserError*)value;
    bool valid = casted->tag == AzXmlErrorTag_ParserError;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlError_matchMutParserError(AzXmlError* restrict value, AzXmlParseError* restrict * restrict out) {
    AzXmlErrorVariant_ParserError* restrict casted = (AzXmlErrorVariant_ParserError* restrict)value;
    bool valid = casted->tag == AzXmlErrorTag_ParserError;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidDeclaration(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidDeclaration* casted = (const AzXmlParseErrorVariant_InvalidDeclaration*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidDeclaration;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidDeclaration(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidDeclaration* restrict casted = (AzXmlParseErrorVariant_InvalidDeclaration* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidDeclaration;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidComment(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidComment* casted = (const AzXmlParseErrorVariant_InvalidComment*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidComment;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidComment(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidComment* restrict casted = (AzXmlParseErrorVariant_InvalidComment* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidComment;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidPI(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidPI* casted = (const AzXmlParseErrorVariant_InvalidPI*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidPI;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidPI(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidPI* restrict casted = (AzXmlParseErrorVariant_InvalidPI* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidPI;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidDoctype(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidDoctype* casted = (const AzXmlParseErrorVariant_InvalidDoctype*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidDoctype;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidDoctype(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidDoctype* restrict casted = (AzXmlParseErrorVariant_InvalidDoctype* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidDoctype;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidEntity(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidEntity* casted = (const AzXmlParseErrorVariant_InvalidEntity*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidEntity;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidEntity(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidEntity* restrict casted = (AzXmlParseErrorVariant_InvalidEntity* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidEntity;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidElement(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidElement* casted = (const AzXmlParseErrorVariant_InvalidElement*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidElement;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidElement(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidElement* restrict casted = (AzXmlParseErrorVariant_InvalidElement* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidElement;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidAttribute(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidAttribute* casted = (const AzXmlParseErrorVariant_InvalidAttribute*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidAttribute;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidAttribute(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidAttribute* restrict casted = (AzXmlParseErrorVariant_InvalidAttribute* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidAttribute;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidCdata(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidCdata* casted = (const AzXmlParseErrorVariant_InvalidCdata*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidCdata;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidCdata(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidCdata* restrict casted = (AzXmlParseErrorVariant_InvalidCdata* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidCdata;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefInvalidCharData(const AzXmlParseError* value, const AzXmlTextError** restrict out) {
    const AzXmlParseErrorVariant_InvalidCharData* casted = (const AzXmlParseErrorVariant_InvalidCharData*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidCharData;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutInvalidCharData(AzXmlParseError* restrict value, AzXmlTextError* restrict * restrict out) {
    AzXmlParseErrorVariant_InvalidCharData* restrict casted = (AzXmlParseErrorVariant_InvalidCharData* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_InvalidCharData;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchRefUnknownToken(const AzXmlParseError* value, const AzSvgParseErrorPosition** restrict out) {
    const AzXmlParseErrorVariant_UnknownToken* casted = (const AzXmlParseErrorVariant_UnknownToken*)value;
    bool valid = casted->tag == AzXmlParseErrorTag_UnknownToken;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlParseError_matchMutUnknownToken(AzXmlParseError* restrict value, AzSvgParseErrorPosition* restrict * restrict out) {
    AzXmlParseErrorVariant_UnknownToken* restrict casted = (AzXmlParseErrorVariant_UnknownToken* restrict)value;
    bool valid = casted->tag == AzXmlParseErrorTag_UnknownToken;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchRefNonXmlChar(const AzXmlStreamError* value, const AzNonXmlCharError** restrict out) {
    const AzXmlStreamErrorVariant_NonXmlChar* casted = (const AzXmlStreamErrorVariant_NonXmlChar*)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_NonXmlChar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchMutNonXmlChar(AzXmlStreamError* restrict value, AzNonXmlCharError* restrict * restrict out) {
    AzXmlStreamErrorVariant_NonXmlChar* restrict casted = (AzXmlStreamErrorVariant_NonXmlChar* restrict)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_NonXmlChar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchRefInvalidChar(const AzXmlStreamError* value, const AzInvalidCharError** restrict out) {
    const AzXmlStreamErrorVariant_InvalidChar* casted = (const AzXmlStreamErrorVariant_InvalidChar*)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidChar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchMutInvalidChar(AzXmlStreamError* restrict value, AzInvalidCharError* restrict * restrict out) {
    AzXmlStreamErrorVariant_InvalidChar* restrict casted = (AzXmlStreamErrorVariant_InvalidChar* restrict)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidChar;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchRefInvalidCharMultiple(const AzXmlStreamError* value, const AzInvalidCharMultipleError** restrict out) {
    const AzXmlStreamErrorVariant_InvalidCharMultiple* casted = (const AzXmlStreamErrorVariant_InvalidCharMultiple*)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidCharMultiple;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchMutInvalidCharMultiple(AzXmlStreamError* restrict value, AzInvalidCharMultipleError* restrict * restrict out) {
    AzXmlStreamErrorVariant_InvalidCharMultiple* restrict casted = (AzXmlStreamErrorVariant_InvalidCharMultiple* restrict)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidCharMultiple;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchRefInvalidQuote(const AzXmlStreamError* value, const AzInvalidQuoteError** restrict out) {
    const AzXmlStreamErrorVariant_InvalidQuote* casted = (const AzXmlStreamErrorVariant_InvalidQuote*)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidQuote;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchMutInvalidQuote(AzXmlStreamError* restrict value, AzInvalidQuoteError* restrict * restrict out) {
    AzXmlStreamErrorVariant_InvalidQuote* restrict casted = (AzXmlStreamErrorVariant_InvalidQuote* restrict)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidQuote;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchRefInvalidSpace(const AzXmlStreamError* value, const AzInvalidSpaceError** restrict out) {
    const AzXmlStreamErrorVariant_InvalidSpace* casted = (const AzXmlStreamErrorVariant_InvalidSpace*)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidSpace;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchMutInvalidSpace(AzXmlStreamError* restrict value, AzInvalidSpaceError* restrict * restrict out) {
    AzXmlStreamErrorVariant_InvalidSpace* restrict casted = (AzXmlStreamErrorVariant_InvalidSpace* restrict)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidSpace;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchRefInvalidString(const AzXmlStreamError* value, const AzInvalidStringError** restrict out) {
    const AzXmlStreamErrorVariant_InvalidString* casted = (const AzXmlStreamErrorVariant_InvalidString*)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidString;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}

bool AzXmlStreamError_matchMutInvalidString(AzXmlStreamError* restrict value, AzInvalidStringError* restrict * restrict out) {
    AzXmlStreamErrorVariant_InvalidString* restrict casted = (AzXmlStreamErrorVariant_InvalidString* restrict)value;
    bool valid = casted->tag == AzXmlStreamErrorTag_InvalidString;
    if (valid) { *out = &casted->payload; } else { *out = 0; }
    return valid;
}



/* Macro to turn a compile-time string into a compile-time AzString
 *
 * static AzString foo = AzString_fromConstStr(\"MyString\");
 */
#define AzString_fromConstStr(s) { \
    .vec = { \
        .ptr = s, \
        .len = sizeof(s) - 1, \
        .cap = sizeof(s) - 1, \
        .destructor = AzU8VecDestructor_NoDestructor, \
    } \
}

/* Macro to initialize a compile-time AzNodeData struct
 *
 * static AzNodeData foo = AzNodeData_new(AzNodeType_Div);
 */
#define AzNodeData_new(nt) { \
    .node_type = nt, \
    .dataset = AzOptionRefAny_None, \
    .ids_and_classes = AzIdOrClassVec_empty, \
    .callbacks = AzCallbackDataVec_empty, \
    .inline_css_props = AzNodeDataInlineCssPropertyVec_empty, \
    .clip_mask = AzOptionImageMask_None, \
    .tab_index = AzOptionTabIndex_None, \
}

/* Macro to initialize a compile-time AzDom struct
 *
 * static AzDom foo = AzDom_new(AzNodeType_Div);
 */
#define AzDom_new(nt) { \
    .root = AzNodeData_new(nt),\
    .children = AzDomVec_empty, \
    .total_children = 0, \
}

/* Macro to initialize the default AppConfig struct, must be in a header file
 * so that the LayoutSolverVersion is defined by the binary, not the library -
 * this way upgrading the library won't break the application layout
 *
 * AzAppConfig foo = AzAppConfig_default();
 */
#define AzAppConfig_default(...) { \
    .layout_solver = AzLayoutSolverVersion_March2021, \
    .log_level = AzAppLogLevel_Error, \
    .enable_visual_panic_hook = true, \
    .enable_logging_on_panic = true, \
    .enable_tab_navigation = true, \
    .system_callbacks = AzSystemCallbacks_libraryInternal(), \
}

/* Macro to generate reflection metadata for a given struct - for a "structName" of "foo", generates:
 *
 * constants:
 * - a foo_RttiTypeId, which serves as the "type ID" for that struct
 * - a foo_RttiString, a compile-time string that identifies the class
 *
 * structs:
 * - struct fooRef(): immutable reference to a RefAny<foo>
 * - struct fooRefMut(): mutable reference to a RefAny<foo>
 *
 * functions:
 * - AzRefAny foo_upcast(myStructInstance): upcasts a #structName to a RefAny
 *
 * - fooRef_create(AzRefAny): creates a new fooRef, but does not yet downcast it (.ptr is set to nullptr)
 * - fooRefMut_create(AzRefAny): creates a new fooRefMut, but does not yet downcast it (.ptr is set to nullptr)
 *
 * - bool foo_downcastRef(AzRefAny, fooRef* restrict): downcasts the RefAny immutably, if true is returned then the fooRef is properly initialized
 * - bool foo_downcastMut(AzRefAny, fooRefMut* restrict): downcasts the RefAny mutably, if true is returned then the fooRef is properly initialized
 *
 * - void fooRef_delete(fooRef): disposes of the fooRef and decreases the immutable reference count
 * - void fooRefMut_delete(fooRefMut): disposes of the fooRefMut and decreases the mutable reference count
 * - bool fooRefAny_delete(AzRefAny): disposes of the AzRefAny type, returns false if the AzRefAny is not of type RefAny<foo>
 *
 * USAGE:
 *
 *     typedef struct { } foo;
 *
 *     // -- destructor of foo, azul will call this function once the refcount hits 0
 *     // note: the function expects a void*, but you can just use a foo*
 *     void fooDestructor(foo* restrict destructorPtr) { }
 *
 *     AZ_REFLECT(foo, fooDestructor)
*/
#define AZ_REFLECT(structName, destructor) \
    /* in C all statics are guaranteed to have a unique address, use that address as a TypeId */ \
    static uint64_t const structName##_RttiTypePtrId = 0; \
    static uint64_t const structName##_RttiTypeId = (uint64_t)(&structName##_RttiTypePtrId); \
    static AzString const structName##_Type_RttiString = AzString_fromConstStr(#structName); \
    \
    AzRefAny structName##_upcast(structName const s) { \
        return AzRefAny_newC(&s, sizeof(structName), structName##_RttiTypeId, structName##_Type_RttiString, destructor); \
    } \
    \
    /* generate structNameRef and structNameRefMut structs*/ \
    typedef struct { const structName* ptr; AzRefCount sharing_info; } structName##Ref; \
    typedef struct { structName* restrict ptr; AzRefCount sharing_info; } structName##RefMut; \
    \
    structName##Ref structName##Ref_create(AzRefAny* const refany) { \
        structName##Ref val = { .ptr = 0, .sharing_info = AzRefCount_deepCopy(&refany->sharing_info) };    \
        return val;    \
    } \
    \
    structName##RefMut structName##RefMut_create(AzRefAny* const refany) { \
        structName##RefMut val = { .ptr = 0, .sharing_info = AzRefCount_deepCopy(&refany->sharing_info), };    \
        return val;    \
    } \
    \
    /* if downcastRef returns true, the downcast worked */ \
    bool structName##_downcastRef(AzRefAny* restrict refany, structName##Ref * restrict result) { \
        if (!AzRefAny_isType(refany, structName##_RttiTypeId)) { return false; } else { \
            if (!AzRefCount_canBeShared(&refany->sharing_info)) { return false; } else {\
                AzRefCount_increaseRef(&refany->sharing_info); \
                result->ptr = (structName* const)(refany->_internal_ptr); \
                return true; \
            } \
        } \
    } \
    \
    /* if downcastRefMut returns true, the mutable downcast worked */ \
    bool structName##_downcastMut(AzRefAny* restrict refany, structName##RefMut * restrict result) { \
        if (!AzRefAny_isType(refany, structName##_RttiTypeId)) { return false; } else { \
            if (!AzRefCount_canBeSharedMut(&refany->sharing_info)) { return false; }  else {\
                AzRefCount_increaseRefmut(&refany->sharing_info); \
                result->ptr = (structName* restrict)(refany->_internal_ptr); \
                return true; \
            } \
        } \
    } \
    \
    /* releases a structNameRef (decreases the RefCount) */ \
    void structName##Ref_delete(structName##Ref* restrict value) { \
        AzRefCount_decreaseRef(&value->sharing_info); \
    }\
    \
    /* releases a structNameRefMut (decreases the mutable RefCount) */ \
    void structName##RefMut_delete(structName##RefMut* restrict value) { \
        AzRefCount_decreaseRefmut(&value->sharing_info); \
    }\
    /* releases a structNameRefAny (checks if the RefCount is 0 and calls the destructor) */ \
    bool structName##RefAny_delete(AzRefAny* restrict refany) { \
        if (!AzRefAny_isType(refany, structName##_RttiTypeId)) { return false; } \
        AzRefAny_delete(refany); \
        return true; \
    }

#endif /* AZUL_H */

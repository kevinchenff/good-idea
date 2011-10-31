#ifdef  _WINDOWS_SOURCE
#ifdef  __ktECmdHeader
#define ExportedByktECmdHeader     __declspec(dllexport)
#else
#define ExportedByktECmdHeader     __declspec(dllimport)
#endif
#else
#define ExportedByktECmdHeader
#endif

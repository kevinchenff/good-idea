#ifdef  _WINDOWS_SOURCE
#ifdef  __ktStrLogService
#define ExportedByktStrLogService     __declspec(dllexport)
#else
#define ExportedByktStrLogService     __declspec(dllimport)
#endif
#else
#define ExportedByktStrLogService
#endif

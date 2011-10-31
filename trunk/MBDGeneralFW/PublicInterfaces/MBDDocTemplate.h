#ifdef  _WINDOWS_SOURCE
#ifdef  __MBDDocTemplate
#define ExportedByMBDDocTemplate     __declspec(dllexport)
#else
#define ExportedByMBDDocTemplate     __declspec(dllimport)
#endif
#else
#define ExportedByMBDDocTemplate
#endif

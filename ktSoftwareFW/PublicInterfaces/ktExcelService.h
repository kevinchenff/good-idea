#ifdef  _WINDOWS_SOURCE
#ifdef  __ktExcelService
#define ExportedByktExcelService     __declspec(dllexport)
#else
#define ExportedByktExcelService     __declspec(dllimport)
#endif
#else
#define ExportedByktExcelService
#endif

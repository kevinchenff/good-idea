#ifdef  _WINDOWS_SOURCE
#ifdef  __ktBasicService
#define ExportedByktBasicService     __declspec(dllexport)
#else
#define ExportedByktBasicService     __declspec(dllimport)
#endif
#else
#define ExportedByktBasicService
#endif

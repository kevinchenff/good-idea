#ifdef  _WINDOWS_SOURCE
#ifdef  __ktPrdService
#define ExportedByktPrdService     __declspec(dllexport)
#else
#define ExportedByktPrdService     __declspec(dllimport)
#endif
#else
#define ExportedByktPrdService
#endif

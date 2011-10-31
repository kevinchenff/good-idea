#ifdef  _WINDOWS_SOURCE
#ifdef  __ktPrtService
#define ExportedByktPrtService     __declspec(dllexport)
#else
#define ExportedByktPrtService     __declspec(dllimport)
#endif
#else
#define ExportedByktPrtService
#endif

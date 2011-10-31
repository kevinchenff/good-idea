#ifdef  _WINDOWS_SOURCE
#ifdef  __ktWebservice
#define ExportedByktWebservice     __declspec(dllexport)
#else
#define ExportedByktWebservice     __declspec(dllimport)
#endif
#else
#define ExportedByktWebservice
#endif

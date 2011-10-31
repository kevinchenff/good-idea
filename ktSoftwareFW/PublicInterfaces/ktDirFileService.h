#ifdef  _WINDOWS_SOURCE
#ifdef  __ktDirFileService
#define ExportedByktDirFileService     __declspec(dllexport)
#else
#define ExportedByktDirFileService     __declspec(dllimport)
#endif
#else
#define ExportedByktDirFileService
#endif

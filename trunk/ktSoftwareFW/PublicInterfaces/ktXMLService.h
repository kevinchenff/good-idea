#ifdef  _WINDOWS_SOURCE
#ifdef  __ktXMLService
#define ExportedByktXMLService     __declspec(dllexport)
#else
#define ExportedByktXMLService     __declspec(dllimport)
#endif
#else
#define ExportedByktXMLService
#endif

//
// sproxy.exe generated file
// do not modify this file
//
// Created: 07/20/2012@22:34:15
//

#pragma once


#if !defined(_WIN32_WINDOWS) && !defined(_WIN32_WINNT) && !defined(_WIN32_WCE)
#pragma message("warning: defining _WIN32_WINDOWS = 0x0410")
#define _WIN32_WINDOWS 0x0410
#endif

#include <atlsoap.h>

namespace Service
{

struct ArrayOfString
{
	BSTR *string;
	int __string_nSizeIs;
};

template <typename TClient = CSoapSocketClientT<> >
class CServiceT : 
	public TClient, 
	public CSoapRootHandler
{
protected:

	const _soapmap ** GetFunctionMap();
	const _soapmap ** GetHeaderMap();
	void * GetHeaderValue();
	const wchar_t * GetNamespaceUri();
	const char * GetServiceName();
	const char * GetNamespaceUriA();
	HRESULT CallFunction(
		void *pvParam, 
		const wchar_t *wszLocalName, int cchLocalName,
		size_t nItem);
	HRESULT GetClientReader(ISAXXMLReader **ppReader);

public:

	HRESULT __stdcall QueryInterface(REFIID riid, void **ppv)
	{
		if (ppv == NULL)
		{
			return E_POINTER;
		}

		*ppv = NULL;

		if (InlineIsEqualGUID(riid, IID_IUnknown) ||
			InlineIsEqualGUID(riid, IID_ISAXContentHandler))
		{
			*ppv = static_cast<ISAXContentHandler *>(this);
			return S_OK;
		}

		return E_NOINTERFACE;
	}

	ULONG __stdcall AddRef()
	{
		return 1;
	}

	ULONG __stdcall Release()
	{
		return 1;
	}

	CServiceT(ISAXXMLReader *pReader = NULL)
		:TClient(_T("http://192.168.100.101:8080/StdPartMS/services/Service"))
	{
		SetClient(true);
		SetReader(pReader);
	}
	
	~CServiceT()
	{
		Uninitialize();
	}
	
	void Uninitialize()
	{
		UninitializeSOAP();
	}	

	HRESULT Query(
		BSTR* in0, int in0_nSizeIs, 
		BSTR** out, int* out_nSizeIs
	);

	HRESULT Insert(
		BSTR* in0, int in0_nSizeIs, 
		BSTR** out, int* out_nSizeIs
	);

	HRESULT GetArrayPrototype1(
		ArrayOfString* in0, int in0_nSizeIs, 
		BSTR* out
	);

	HRESULT GetParametersNameAndKey(
		BSTR** out, int* out_nSizeIs
	);

	HRESULT GetArrayPrototype(
		BSTR* in0, int in0_nSizeIs, 
		BSTR* out
	);
};

typedef CServiceT<> CService;

__if_not_exists(__ArrayOfString_entries)
{
extern __declspec(selectany) const _soapmapentry __ArrayOfString_entries[] =
{
	{ 
		0x14B4AB37, 
		"string", 
		L"string", 
		sizeof("string")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_FIELD | SOAPFLAG_DYNARR | SOAPFLAG_NULLABLE, 
		offsetof(ArrayOfString, string),
		NULL, 
		NULL, 
		0+1 
	},
	{ 
		0x14B4AB37, 
		"string", 
		L"string", 
		sizeof("string")-1, 
		SOAPTYPE_INT, 
		SOAPFLAG_FIELD | SOAPFLAG_NOMARSHAL, 
		offsetof(ArrayOfString, __string_nSizeIs),
		NULL, 
		NULL, 
		-1
	},
	{ 0x00000000 }
};

extern __declspec(selectany) const _soapmap __ArrayOfString_map =
{
	0x4BB09A4B,
	"ArrayOfString",
	L"ArrayOfString",
	sizeof("ArrayOfString")-1,
	sizeof("ArrayOfString")-1,
	SOAPMAP_STRUCT,
	__ArrayOfString_entries,
	sizeof(ArrayOfString),
	1,
	-1,
	SOAPFLAG_NONE,
	0x3B4BC6C5,
	"http://services.stdpms",
	L"http://services.stdpms",
	sizeof("http://services.stdpms")-1
};
}

struct __CService_Query_struct
{
	BSTR *in0;
	int __in0_nSizeIs;
	BSTR *out;
	int __out_nSizeIs;
};

extern __declspec(selectany) const _soapmapentry __CService_Query_entries[] =
{

	{
		0x0001CD07, 
		"in0", 
		L"in0", 
		sizeof("in0")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_IN | SOAPFLAG_DYNARR | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_Query_struct, in0),
		NULL,
		NULL,
		0+1,
	},
	{
		0x0001CD07,
		"__in0_nSizeIs",
		L"__in0_nSizeIs",
		sizeof("__in0_nSizeIs")-1,
		SOAPTYPE_INT,
		SOAPFLAG_NOMARSHAL,
		offsetof(__CService_Query_struct, __in0_nSizeIs),
		NULL,
		NULL,
		-1
	},
	{
		0x0001E7B8, 
		"out", 
		L"out", 
		sizeof("out")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_OUT | SOAPFLAG_DYNARR | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_Query_struct, out),
		NULL,
		NULL,
		2+1,
	},
	{
		0x0001E7B8,
		"__out_nSizeIs",
		L"__out_nSizeIs",
		sizeof("__out_nSizeIs")-1,
		SOAPTYPE_INT,
		SOAPFLAG_NOMARSHAL,
		offsetof(__CService_Query_struct, __out_nSizeIs),
		NULL,
		NULL,
		-1
	},
	{ 0x00000000 }
};

extern __declspec(selectany) const _soapmap __CService_Query_map =
{
	0x15A01E25,
	"Query",
	L"QueryResponse",
	sizeof("Query")-1,
	sizeof("QueryResponse")-1,
	SOAPMAP_FUNC,
	__CService_Query_entries,
	sizeof(__CService_Query_struct),
	1,
	-1,
	SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
	0x3B4BC6C5,
	"http://services.stdpms",
	L"http://services.stdpms",
	sizeof("http://services.stdpms")-1
};


struct __CService_Insert_struct
{
	BSTR *in0;
	int __in0_nSizeIs;
	BSTR *out;
	int __out_nSizeIs;
};

extern __declspec(selectany) const _soapmapentry __CService_Insert_entries[] =
{

	{
		0x0001CD07, 
		"in0", 
		L"in0", 
		sizeof("in0")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_IN | SOAPFLAG_DYNARR | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_Insert_struct, in0),
		NULL,
		NULL,
		0+1,
	},
	{
		0x0001CD07,
		"__in0_nSizeIs",
		L"__in0_nSizeIs",
		sizeof("__in0_nSizeIs")-1,
		SOAPTYPE_INT,
		SOAPFLAG_NOMARSHAL,
		offsetof(__CService_Insert_struct, __in0_nSizeIs),
		NULL,
		NULL,
		-1
	},
	{
		0x0001E7B8, 
		"out", 
		L"out", 
		sizeof("out")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_OUT | SOAPFLAG_DYNARR | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_Insert_struct, out),
		NULL,
		NULL,
		2+1,
	},
	{
		0x0001E7B8,
		"__out_nSizeIs",
		L"__out_nSizeIs",
		sizeof("__out_nSizeIs")-1,
		SOAPTYPE_INT,
		SOAPFLAG_NOMARSHAL,
		offsetof(__CService_Insert_struct, __out_nSizeIs),
		NULL,
		NULL,
		-1
	},
	{ 0x00000000 }
};

extern __declspec(selectany) const _soapmap __CService_Insert_map =
{
	0x505FB0E4,
	"Insert",
	L"InsertResponse",
	sizeof("Insert")-1,
	sizeof("InsertResponse")-1,
	SOAPMAP_FUNC,
	__CService_Insert_entries,
	sizeof(__CService_Insert_struct),
	1,
	-1,
	SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
	0x3B4BC6C5,
	"http://services.stdpms",
	L"http://services.stdpms",
	sizeof("http://services.stdpms")-1
};


struct __CService_GetArrayPrototype1_struct
{
	ArrayOfString *in0;
	int __in0_nSizeIs;
	BSTR out;
};

extern __declspec(selectany) const _soapmapentry __CService_GetArrayPrototype1_entries[] =
{

	{
		0x0001CD07, 
		"in0", 
		L"in0", 
		sizeof("in0")-1, 
		SOAPTYPE_UNK, 
		SOAPFLAG_NONE | SOAPFLAG_IN | SOAPFLAG_DYNARR | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_GetArrayPrototype1_struct, in0),
		NULL,
		&__ArrayOfString_map,
		0+1,
	},
	{
		0x0001CD07,
		"__in0_nSizeIs",
		L"__in0_nSizeIs",
		sizeof("__in0_nSizeIs")-1,
		SOAPTYPE_INT,
		SOAPFLAG_NOMARSHAL,
		offsetof(__CService_GetArrayPrototype1_struct, __in0_nSizeIs),
		NULL,
		NULL,
		-1
	},
	{
		0x0001E7B8, 
		"out", 
		L"out", 
		sizeof("out")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_OUT | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_GetArrayPrototype1_struct, out),
		NULL,
		NULL,
		-1,
	},
	{ 0x00000000 }
};

extern __declspec(selectany) const _soapmap __CService_GetArrayPrototype1_map =
{
	0xE54541D5,
	"GetArrayPrototype1",
	L"GetArrayPrototype1Response",
	sizeof("GetArrayPrototype1")-1,
	sizeof("GetArrayPrototype1Response")-1,
	SOAPMAP_FUNC,
	__CService_GetArrayPrototype1_entries,
	sizeof(__CService_GetArrayPrototype1_struct),
	1,
	-1,
	SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
	0x3B4BC6C5,
	"http://services.stdpms",
	L"http://services.stdpms",
	sizeof("http://services.stdpms")-1
};


struct __CService_GetParametersNameAndKey_struct
{
	BSTR *out;
	int __out_nSizeIs;
};

extern __declspec(selectany) const _soapmapentry __CService_GetParametersNameAndKey_entries[] =
{

	{
		0x0001E7B8, 
		"out", 
		L"out", 
		sizeof("out")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_OUT | SOAPFLAG_DYNARR | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_GetParametersNameAndKey_struct, out),
		NULL,
		NULL,
		0+1,
	},
	{
		0x0001E7B8,
		"__out_nSizeIs",
		L"__out_nSizeIs",
		sizeof("__out_nSizeIs")-1,
		SOAPTYPE_INT,
		SOAPFLAG_NOMARSHAL,
		offsetof(__CService_GetParametersNameAndKey_struct, __out_nSizeIs),
		NULL,
		NULL,
		-1
	},
	{ 0x00000000 }
};

extern __declspec(selectany) const _soapmap __CService_GetParametersNameAndKey_map =
{
	0x1B0B1D00,
	"GetParametersNameAndKey",
	L"GetParametersNameAndKeyResponse",
	sizeof("GetParametersNameAndKey")-1,
	sizeof("GetParametersNameAndKeyResponse")-1,
	SOAPMAP_FUNC,
	__CService_GetParametersNameAndKey_entries,
	sizeof(__CService_GetParametersNameAndKey_struct),
	1,
	-1,
	SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
	0x3B4BC6C5,
	"http://services.stdpms",
	L"http://services.stdpms",
	sizeof("http://services.stdpms")-1
};


struct __CService_GetArrayPrototype_struct
{
	BSTR *in0;
	int __in0_nSizeIs;
	BSTR out;
};

extern __declspec(selectany) const _soapmapentry __CService_GetArrayPrototype_entries[] =
{

	{
		0x0001CD07, 
		"in0", 
		L"in0", 
		sizeof("in0")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_IN | SOAPFLAG_DYNARR | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_GetArrayPrototype_struct, in0),
		NULL,
		NULL,
		0+1,
	},
	{
		0x0001CD07,
		"__in0_nSizeIs",
		L"__in0_nSizeIs",
		sizeof("__in0_nSizeIs")-1,
		SOAPTYPE_INT,
		SOAPFLAG_NOMARSHAL,
		offsetof(__CService_GetArrayPrototype_struct, __in0_nSizeIs),
		NULL,
		NULL,
		-1
	},
	{
		0x0001E7B8, 
		"out", 
		L"out", 
		sizeof("out")-1, 
		SOAPTYPE_STRING, 
		SOAPFLAG_NONE | SOAPFLAG_OUT | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL | SOAPFLAG_NULLABLE,
		offsetof(__CService_GetArrayPrototype_struct, out),
		NULL,
		NULL,
		-1,
	},
	{ 0x00000000 }
};

extern __declspec(selectany) const _soapmap __CService_GetArrayPrototype_map =
{
	0x336B2604,
	"GetArrayPrototype",
	L"GetArrayPrototypeResponse",
	sizeof("GetArrayPrototype")-1,
	sizeof("GetArrayPrototypeResponse")-1,
	SOAPMAP_FUNC,
	__CService_GetArrayPrototype_entries,
	sizeof(__CService_GetArrayPrototype_struct),
	1,
	-1,
	SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
	0x3B4BC6C5,
	"http://services.stdpms",
	L"http://services.stdpms",
	sizeof("http://services.stdpms")-1
};

extern __declspec(selectany) const _soapmap * __CService_funcs[] =
{
	&__CService_Query_map,
	&__CService_Insert_map,
	&__CService_GetArrayPrototype1_map,
	&__CService_GetParametersNameAndKey_map,
	&__CService_GetArrayPrototype_map,
	NULL
};

template <typename TClient>
inline HRESULT CServiceT<TClient>::Query(
		BSTR* in0, int __in0_nSizeIs, 
		BSTR** out, int* __out_nSizeIs
	)
{
    if ( out == NULL )
		return E_POINTER;
	if( __out_nSizeIs == NULL )
		return E_POINTER;

	HRESULT __atlsoap_hr = InitializeSOAP(NULL);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_INITIALIZE_ERROR);
		return __atlsoap_hr;
	}
	
	CleanupClient();

	CComPtr<IStream> __atlsoap_spReadStream;
	__CService_Query_struct __params;
	memset(&__params, 0x00, sizeof(__params));
	__params.in0 = in0;
	__params.__in0_nSizeIs = __in0_nSizeIs;

	__atlsoap_hr = SetClientStruct(&__params, 0);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_OUTOFMEMORY);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = GenerateResponse(GetWriteStream());
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_GENERATE_ERROR);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = SendRequest(_T("SOAPAction: \"\"\r\n"));
	if (FAILED(__atlsoap_hr))
	{
		goto __skip_cleanup;
	}
	__atlsoap_hr = GetReadStream(&__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_READ_ERROR);
		goto __skip_cleanup;
	}
	
	// cleanup any in/out-params and out-headers from previous calls
	Cleanup();
	__atlsoap_hr = BeginParse(__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_PARSE_ERROR);
		goto __cleanup;
	}

	*out = __params.out;
	*__out_nSizeIs = __params.__out_nSizeIs;
	goto __skip_cleanup;
	
__cleanup:
	Cleanup();
__skip_cleanup:
	ResetClientState(true);
	memset(&__params, 0x00, sizeof(__params));
	return __atlsoap_hr;
}

template <typename TClient>
inline HRESULT CServiceT<TClient>::Insert(
		BSTR* in0, int __in0_nSizeIs, 
		BSTR** out, int* __out_nSizeIs
	)
{
    if ( out == NULL )
		return E_POINTER;
	if( __out_nSizeIs == NULL )
		return E_POINTER;

	HRESULT __atlsoap_hr = InitializeSOAP(NULL);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_INITIALIZE_ERROR);
		return __atlsoap_hr;
	}
	
	CleanupClient();

	CComPtr<IStream> __atlsoap_spReadStream;
	__CService_Insert_struct __params;
	memset(&__params, 0x00, sizeof(__params));
	__params.in0 = in0;
	__params.__in0_nSizeIs = __in0_nSizeIs;

	__atlsoap_hr = SetClientStruct(&__params, 1);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_OUTOFMEMORY);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = GenerateResponse(GetWriteStream());
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_GENERATE_ERROR);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = SendRequest(_T("SOAPAction: \"\"\r\n"));
	if (FAILED(__atlsoap_hr))
	{
		goto __skip_cleanup;
	}
	__atlsoap_hr = GetReadStream(&__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_READ_ERROR);
		goto __skip_cleanup;
	}
	
	// cleanup any in/out-params and out-headers from previous calls
	Cleanup();
	__atlsoap_hr = BeginParse(__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_PARSE_ERROR);
		goto __cleanup;
	}

	*out = __params.out;
	*__out_nSizeIs = __params.__out_nSizeIs;
	goto __skip_cleanup;
	
__cleanup:
	Cleanup();
__skip_cleanup:
	ResetClientState(true);
	memset(&__params, 0x00, sizeof(__params));
	return __atlsoap_hr;
}

template <typename TClient>
inline HRESULT CServiceT<TClient>::GetArrayPrototype1(
		ArrayOfString* in0, int __in0_nSizeIs, 
		BSTR* out
	)
{
    if ( out == NULL )
		return E_POINTER;

	HRESULT __atlsoap_hr = InitializeSOAP(NULL);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_INITIALIZE_ERROR);
		return __atlsoap_hr;
	}
	
	CleanupClient();

	CComPtr<IStream> __atlsoap_spReadStream;
	__CService_GetArrayPrototype1_struct __params;
	memset(&__params, 0x00, sizeof(__params));
	__params.in0 = in0;
	__params.__in0_nSizeIs = __in0_nSizeIs;

	__atlsoap_hr = SetClientStruct(&__params, 2);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_OUTOFMEMORY);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = GenerateResponse(GetWriteStream());
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_GENERATE_ERROR);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = SendRequest(_T("SOAPAction: \"\"\r\n"));
	if (FAILED(__atlsoap_hr))
	{
		goto __skip_cleanup;
	}
	__atlsoap_hr = GetReadStream(&__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_READ_ERROR);
		goto __skip_cleanup;
	}
	
	// cleanup any in/out-params and out-headers from previous calls
	Cleanup();
	__atlsoap_hr = BeginParse(__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_PARSE_ERROR);
		goto __cleanup;
	}

	*out = __params.out;
	goto __skip_cleanup;
	
__cleanup:
	Cleanup();
__skip_cleanup:
	ResetClientState(true);
	memset(&__params, 0x00, sizeof(__params));
	return __atlsoap_hr;
}

template <typename TClient>
inline HRESULT CServiceT<TClient>::GetParametersNameAndKey(
		BSTR** out, int* __out_nSizeIs
	)
{
    if ( out == NULL )
		return E_POINTER;
	if( __out_nSizeIs == NULL )
		return E_POINTER;

	HRESULT __atlsoap_hr = InitializeSOAP(NULL);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_INITIALIZE_ERROR);
		return __atlsoap_hr;
	}
	
	CleanupClient();

	CComPtr<IStream> __atlsoap_spReadStream;
	__CService_GetParametersNameAndKey_struct __params;
	memset(&__params, 0x00, sizeof(__params));

	__atlsoap_hr = SetClientStruct(&__params, 3);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_OUTOFMEMORY);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = GenerateResponse(GetWriteStream());
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_GENERATE_ERROR);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = SendRequest(_T("SOAPAction: \"\"\r\n"));
	if (FAILED(__atlsoap_hr))
	{
		goto __skip_cleanup;
	}
	__atlsoap_hr = GetReadStream(&__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_READ_ERROR);
		goto __skip_cleanup;
	}
	
	// cleanup any in/out-params and out-headers from previous calls
	Cleanup();
	__atlsoap_hr = BeginParse(__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_PARSE_ERROR);
		goto __cleanup;
	}

	*out = __params.out;
	*__out_nSizeIs = __params.__out_nSizeIs;
	goto __skip_cleanup;
	
__cleanup:
	Cleanup();
__skip_cleanup:
	ResetClientState(true);
	memset(&__params, 0x00, sizeof(__params));
	return __atlsoap_hr;
}

template <typename TClient>
inline HRESULT CServiceT<TClient>::GetArrayPrototype(
		BSTR* in0, int __in0_nSizeIs, 
		BSTR* out
	)
{
    if ( out == NULL )
		return E_POINTER;

	HRESULT __atlsoap_hr = InitializeSOAP(NULL);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_INITIALIZE_ERROR);
		return __atlsoap_hr;
	}
	
	CleanupClient();

	CComPtr<IStream> __atlsoap_spReadStream;
	__CService_GetArrayPrototype_struct __params;
	memset(&__params, 0x00, sizeof(__params));
	__params.in0 = in0;
	__params.__in0_nSizeIs = __in0_nSizeIs;

	__atlsoap_hr = SetClientStruct(&__params, 4);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_OUTOFMEMORY);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = GenerateResponse(GetWriteStream());
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_GENERATE_ERROR);
		goto __skip_cleanup;
	}
	
	__atlsoap_hr = SendRequest(_T("SOAPAction: \"\"\r\n"));
	if (FAILED(__atlsoap_hr))
	{
		goto __skip_cleanup;
	}
	__atlsoap_hr = GetReadStream(&__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_READ_ERROR);
		goto __skip_cleanup;
	}
	
	// cleanup any in/out-params and out-headers from previous calls
	Cleanup();
	__atlsoap_hr = BeginParse(__atlsoap_spReadStream);
	if (FAILED(__atlsoap_hr))
	{
		SetClientError(SOAPCLIENT_PARSE_ERROR);
		goto __cleanup;
	}

	*out = __params.out;
	goto __skip_cleanup;
	
__cleanup:
	Cleanup();
__skip_cleanup:
	ResetClientState(true);
	memset(&__params, 0x00, sizeof(__params));
	return __atlsoap_hr;
}

template <typename TClient>
ATL_NOINLINE inline const _soapmap ** CServiceT<TClient>::GetFunctionMap()
{
	return __CService_funcs;
}

template <typename TClient>
ATL_NOINLINE inline const _soapmap ** CServiceT<TClient>::GetHeaderMap()
{
	static const _soapmapentry __CService_Query_atlsoapheader_entries[] =
	{
		{ 0x00000000 }
	};

	static const _soapmap __CService_Query_atlsoapheader_map = 
	{
		0x15A01E25,
		"Query",
		L"QueryResponse",
		sizeof("Query")-1,
		sizeof("QueryResponse")-1,
		SOAPMAP_HEADER,
		__CService_Query_atlsoapheader_entries,
		0,
		0,
		-1,
		SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
		0x3B4BC6C5,
		"http://services.stdpms",
		L"http://services.stdpms",
		sizeof("http://services.stdpms")-1
	};

	static const _soapmapentry __CService_Insert_atlsoapheader_entries[] =
	{
		{ 0x00000000 }
	};

	static const _soapmap __CService_Insert_atlsoapheader_map = 
	{
		0x505FB0E4,
		"Insert",
		L"InsertResponse",
		sizeof("Insert")-1,
		sizeof("InsertResponse")-1,
		SOAPMAP_HEADER,
		__CService_Insert_atlsoapheader_entries,
		0,
		0,
		-1,
		SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
		0x3B4BC6C5,
		"http://services.stdpms",
		L"http://services.stdpms",
		sizeof("http://services.stdpms")-1
	};

	static const _soapmapentry __CService_GetArrayPrototype1_atlsoapheader_entries[] =
	{
		{ 0x00000000 }
	};

	static const _soapmap __CService_GetArrayPrototype1_atlsoapheader_map = 
	{
		0xE54541D5,
		"GetArrayPrototype1",
		L"GetArrayPrototype1Response",
		sizeof("GetArrayPrototype1")-1,
		sizeof("GetArrayPrototype1Response")-1,
		SOAPMAP_HEADER,
		__CService_GetArrayPrototype1_atlsoapheader_entries,
		0,
		0,
		-1,
		SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
		0x3B4BC6C5,
		"http://services.stdpms",
		L"http://services.stdpms",
		sizeof("http://services.stdpms")-1
	};

	static const _soapmapentry __CService_GetParametersNameAndKey_atlsoapheader_entries[] =
	{
		{ 0x00000000 }
	};

	static const _soapmap __CService_GetParametersNameAndKey_atlsoapheader_map = 
	{
		0x1B0B1D00,
		"GetParametersNameAndKey",
		L"GetParametersNameAndKeyResponse",
		sizeof("GetParametersNameAndKey")-1,
		sizeof("GetParametersNameAndKeyResponse")-1,
		SOAPMAP_HEADER,
		__CService_GetParametersNameAndKey_atlsoapheader_entries,
		0,
		0,
		-1,
		SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
		0x3B4BC6C5,
		"http://services.stdpms",
		L"http://services.stdpms",
		sizeof("http://services.stdpms")-1
	};

	static const _soapmapentry __CService_GetArrayPrototype_atlsoapheader_entries[] =
	{
		{ 0x00000000 }
	};

	static const _soapmap __CService_GetArrayPrototype_atlsoapheader_map = 
	{
		0x336B2604,
		"GetArrayPrototype",
		L"GetArrayPrototypeResponse",
		sizeof("GetArrayPrototype")-1,
		sizeof("GetArrayPrototypeResponse")-1,
		SOAPMAP_HEADER,
		__CService_GetArrayPrototype_atlsoapheader_entries,
		0,
		0,
		-1,
		SOAPFLAG_NONE | SOAPFLAG_PID | SOAPFLAG_DOCUMENT | SOAPFLAG_LITERAL,
		0x3B4BC6C5,
		"http://services.stdpms",
		L"http://services.stdpms",
		sizeof("http://services.stdpms")-1
	};


	static const _soapmap * __CService_headers[] =
	{
		&__CService_Query_atlsoapheader_map,
		&__CService_Insert_atlsoapheader_map,
		&__CService_GetArrayPrototype1_atlsoapheader_map,
		&__CService_GetParametersNameAndKey_atlsoapheader_map,
		&__CService_GetArrayPrototype_atlsoapheader_map,
		NULL
	};
	
	return __CService_headers;
}

template <typename TClient>
ATL_NOINLINE inline void * CServiceT<TClient>::GetHeaderValue()
{
	return this;
}

template <typename TClient>
ATL_NOINLINE inline const wchar_t * CServiceT<TClient>::GetNamespaceUri()
{
	return L"http://services.stdpms";
}

template <typename TClient>
ATL_NOINLINE inline const char * CServiceT<TClient>::GetServiceName()
{
	return NULL;
}

template <typename TClient>
ATL_NOINLINE inline const char * CServiceT<TClient>::GetNamespaceUriA()
{
	return "http://services.stdpms";
}

template <typename TClient>
ATL_NOINLINE inline HRESULT CServiceT<TClient>::CallFunction(
	void *, 
	const wchar_t *, int,
	size_t)
{
	return E_NOTIMPL;
}

template <typename TClient>
ATL_NOINLINE inline HRESULT CServiceT<TClient>::GetClientReader(ISAXXMLReader **ppReader)
{
	if (ppReader == NULL)
	{
		return E_INVALIDARG;
	}
	
	CComPtr<ISAXXMLReader> spReader = GetReader();
	if (spReader.p != NULL)
	{
		*ppReader = spReader.Detach();
		return S_OK;
	}
	return TClient::GetClientReader(ppReader);
}

} // namespace Service

template<>
inline HRESULT AtlCleanupValue<Service::ArrayOfString>(Service::ArrayOfString *pVal)
{
	pVal;
	AtlCleanupArray(pVal->string, pVal->__string_nSizeIs);	
	return S_OK;
}

template<>
inline HRESULT AtlCleanupValueEx<Service::ArrayOfString>(Service::ArrayOfString *pVal, IAtlMemMgr *pMemMgr)
{
	pVal;
	pMemMgr;
	
	if (pVal->string != NULL)
	{
		AtlCleanupArrayEx(pVal->string, pVal->__string_nSizeIs, pMemMgr);		
		pMemMgr->Free(pVal->string);
	}
	return S_OK;
}

/* soapMBDServicesHttpBindingProxy.cpp
   Generated by gSOAP 2.8.3 from MBDWebService.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#include "soapMBDServicesHttpBindingProxy.h"

MBDServicesHttpBindingProxy::MBDServicesHttpBindingProxy()
{	MBDServicesHttpBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

MBDServicesHttpBindingProxy::MBDServicesHttpBindingProxy(const struct soap &_soap) : soap(_soap)
{ }

MBDServicesHttpBindingProxy::MBDServicesHttpBindingProxy(const char *url)
{	MBDServicesHttpBindingProxy_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
	soap_endpoint = url;
}

MBDServicesHttpBindingProxy::MBDServicesHttpBindingProxy(soap_mode iomode)
{	MBDServicesHttpBindingProxy_init(iomode, iomode);
}

MBDServicesHttpBindingProxy::MBDServicesHttpBindingProxy(const char *url, soap_mode iomode)
{	MBDServicesHttpBindingProxy_init(iomode, iomode);
	soap_endpoint = url;
}

MBDServicesHttpBindingProxy::MBDServicesHttpBindingProxy(soap_mode imode, soap_mode omode)
{	MBDServicesHttpBindingProxy_init(imode, omode);
}

MBDServicesHttpBindingProxy::~MBDServicesHttpBindingProxy()
{ }

void MBDServicesHttpBindingProxy::MBDServicesHttpBindingProxy_init(soap_mode imode, soap_mode omode)
{	soap_imode(this, imode);
	soap_omode(this, omode);
	soap_endpoint = NULL;
	static const struct Namespace namespaces[] =
{
	{"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
	{"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
	{"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
	{"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
	{"kt1", "http://domain.webserviceserver.module.mbd.avicit", NULL, NULL},
	{NULL, NULL, NULL, NULL}
};
	soap_set_namespaces(this, namespaces);
}

void MBDServicesHttpBindingProxy::destroy()
{	soap_destroy(this);
	soap_end(this);
}

void MBDServicesHttpBindingProxy::soap_noheader()
{	this->header = NULL;
}

const SOAP_ENV__Header *MBDServicesHttpBindingProxy::soap_header()
{	return this->header;
}

const SOAP_ENV__Fault *MBDServicesHttpBindingProxy::soap_fault()
{	return this->fault;
}

const char *MBDServicesHttpBindingProxy::soap_fault_string()
{	return *soap_faultstring(this);
}

const char *MBDServicesHttpBindingProxy::soap_fault_detail()
{	return *soap_faultdetail(this);
}

int MBDServicesHttpBindingProxy::soap_close_socket()
{	return soap_closesock(this);
}

void MBDServicesHttpBindingProxy::soap_print_fault(FILE *fd)
{	::soap_print_fault(this, fd);
}

#ifndef WITH_LEAN
void MBDServicesHttpBindingProxy::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this, os);
}

char *MBDServicesHttpBindingProxy::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this, buf, len);
}
#endif

int MBDServicesHttpBindingProxy::Insert(const char *endpoint, const char *soap_action, _kt1__Insert *kt1__Insert, _kt1__InsertResponse *kt1__InsertResponse)
{	struct soap *soap = this;
	struct __kt1__Insert soap_tmp___kt1__Insert;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.190.129:8080/MBDDatabase/services/MBD";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___kt1__Insert.kt1__Insert = kt1__Insert;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___kt1__Insert(soap, &soap_tmp___kt1__Insert);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___kt1__Insert(soap, &soap_tmp___kt1__Insert, "-kt1:Insert", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___kt1__Insert(soap, &soap_tmp___kt1__Insert, "-kt1:Insert", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!kt1__InsertResponse)
		return soap_closesock(soap);
	kt1__InsertResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	kt1__InsertResponse->soap_get(soap, "kt1:InsertResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int MBDServicesHttpBindingProxy::Query(const char *endpoint, const char *soap_action, _kt1__Query *kt1__Query, _kt1__QueryResponse *kt1__QueryResponse)
{	struct soap *soap = this;
	struct __kt1__Query soap_tmp___kt1__Query;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.190.129:8080/MBDDatabase/services/MBD";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___kt1__Query.kt1__Query = kt1__Query;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___kt1__Query(soap, &soap_tmp___kt1__Query);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___kt1__Query(soap, &soap_tmp___kt1__Query, "-kt1:Query", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___kt1__Query(soap, &soap_tmp___kt1__Query, "-kt1:Query", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!kt1__QueryResponse)
		return soap_closesock(soap);
	kt1__QueryResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	kt1__QueryResponse->soap_get(soap, "kt1:QueryResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

int MBDServicesHttpBindingProxy::getInforByIp(const char *endpoint, const char *soap_action, _kt1__getInforByIp *kt1__getInforByIp, _kt1__getInforByIpResponse *kt1__getInforByIpResponse)
{	struct soap *soap = this;
	struct __kt1__getInforByIp soap_tmp___kt1__getInforByIp;
	if (endpoint)
		soap_endpoint = endpoint;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.190.129:8080/MBDDatabase/services/MBD";
	if (!soap_action)
		soap_action = "";
	soap->encodingStyle = NULL;
	soap_tmp___kt1__getInforByIp.kt1__getInforByIp = kt1__getInforByIp;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize___kt1__getInforByIp(soap, &soap_tmp___kt1__getInforByIp);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___kt1__getInforByIp(soap, &soap_tmp___kt1__getInforByIp, "-kt1:getInforByIp", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___kt1__getInforByIp(soap, &soap_tmp___kt1__getInforByIp, "-kt1:getInforByIp", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!kt1__getInforByIpResponse)
		return soap_closesock(soap);
	kt1__getInforByIpResponse->soap_default(soap);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	kt1__getInforByIpResponse->soap_get(soap, "kt1:getInforByIpResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}
/* End of client proxy code */
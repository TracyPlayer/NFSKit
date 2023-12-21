/* -*-  mode:c; tab-width:8; c-basic-offset:8; indent-tabs-mode:nil;  -*- */
/*
Copyright (c) 2014, Ronnie Sahlberg
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer. 
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies, 
either expressed or implied, of the FreeBSD Project.
*/
/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PORTMAP_H_RPCGEN
#define _PORTMAP_H_RPCGEN

#include <nfsc/libnfs-zdr.h>


#ifdef __cplusplus
extern "C" {
#endif

#define PMAP_PORT 111

struct pmap2_mapping {
	u_int prog;
	u_int vers;
	u_int prot;
	u_int port;
};
typedef struct pmap2_mapping pmap2_mapping;

struct pmap2_call_args {
	u_int prog;
	u_int vers;
	u_int proc;
	struct {
		u_int args_len;
		char *args_val;
	} args;
};
typedef struct pmap2_call_args pmap2_call_args;

struct pmap2_call_result {
	u_int port;
	struct {
		u_int res_len;
		char *res_val;
	} res;
};
typedef struct pmap2_call_result pmap2_call_result;

struct pmap2_mapping_list {
	pmap2_mapping map;
	struct pmap2_mapping_list *next;
};
typedef struct pmap2_mapping_list pmap2_mapping_list;

struct pmap2_dump_result {
	struct pmap2_mapping_list *list;
};
typedef struct pmap2_dump_result pmap2_dump_result;

struct pmap3_string_result {
	char *addr;
};
typedef struct pmap3_string_result pmap3_string_result;

struct pmap3_mapping {
	u_int prog;
	u_int vers;
	char *netid;
	char *addr;
	char *owner;
};
typedef struct pmap3_mapping pmap3_mapping;

struct pmap3_mapping_list {
	pmap3_mapping map;
	struct pmap3_mapping_list *next;
};
typedef struct pmap3_mapping_list pmap3_mapping_list;

struct pmap3_dump_result {
	struct pmap3_mapping_list *list;
};
typedef struct pmap3_dump_result pmap3_dump_result;

struct pmap3_call_args {
	u_int prog;
	u_int vers;
	u_int proc;
	struct {
		u_int args_len;
		char *args_val;
	} args;
};
typedef struct pmap3_call_args pmap3_call_args;

struct pmap3_call_result {
	u_int port;
	struct {
		u_int res_len;
		char *res_val;
	} res;
};
typedef struct pmap3_call_result pmap3_call_result;

struct pmap3_netbuf {
	u_int maxlen;
	struct {
		u_int buf_len;
		char *buf_val;
	} buf;
};
typedef struct pmap3_netbuf pmap3_netbuf;

typedef pmap2_mapping PMAP2SETargs;

typedef pmap2_mapping PMAP2UNSETargs;

typedef pmap2_mapping PMAP2GETPORTargs;

typedef pmap2_call_args PMAP2CALLITargs;

typedef pmap2_call_result PMAP2CALLITres;

typedef pmap2_dump_result PMAP2DUMPres;

typedef pmap3_mapping PMAP3SETargs;

typedef pmap3_mapping PMAP3UNSETargs;

typedef pmap3_mapping PMAP3GETADDRargs;

typedef pmap3_string_result PMAP3GETADDRres;

typedef pmap3_dump_result PMAP3DUMPres;

typedef pmap3_call_result PMAP3CALLITargs;

typedef pmap3_call_result PMAP3CALLITres;

typedef pmap3_netbuf PMAP3UADDR2TADDRres;

typedef pmap3_netbuf PMAP3TADDR2UADDRargs;

typedef pmap3_string_result PMAP3TADDR2UADDRres;

#define PMAP_PROGRAM 100000
#define PMAP_V2 2

#if defined(__STDC__) || defined(__cplusplus)
#define PMAP2_NULL 0
extern  void * pmap2_null_2(void *, void *);
extern  void * pmap2_null_2_svc(void *, struct svc_req *);
#define PMAP2_SET 1
extern  uint32_t * pmap2_set_2(PMAP2SETargs *, void *);
extern  uint32_t * pmap2_set_2_svc(PMAP2SETargs *, struct svc_req *);
#define PMAP2_UNSET 2
extern  uint32_t * pmap2_unset_2(PMAP2UNSETargs *, void *);
extern  uint32_t * pmap2_unset_2_svc(PMAP2UNSETargs *, struct svc_req *);
#define PMAP2_GETPORT 3
extern  uint32_t * pmap2_getport_2(PMAP2GETPORTargs *, void *);
extern  uint32_t * pmap2_getport_2_svc(PMAP2GETPORTargs *, struct svc_req *);
#define PMAP2_DUMP 4
extern  PMAP2DUMPres * pmap2_dump_2(void *, void *);
extern  PMAP2DUMPres * pmap2_dump_2_svc(void *, struct svc_req *);
#define PMAP2_CALLIT 5
extern  PMAP2CALLITres * pmap2_callit_2(PMAP2CALLITargs *, void *);
extern  PMAP2CALLITres * pmap2_callit_2_svc(PMAP2CALLITargs *, struct svc_req *);
extern int pmap_program_2_freeresult (void *, zdrproc_t, caddr_t);

#else /* K&R C */
#define PMAP2_NULL 0
extern  void * pmap2_null_2();
extern  void * pmap2_null_2_svc();
#define PMAP2_SET 1
extern  uint32_t * pmap2_set_2();
extern  uint32_t * pmap2_set_2_svc();
#define PMAP2_UNSET 2
extern  uint32_t * pmap2_unset_2();
extern  uint32_t * pmap2_unset_2_svc();
#define PMAP2_GETPORT 3
extern  uint32_t * pmap2_getport_2();
extern  uint32_t * pmap2_getport_2_svc();
#define PMAP2_DUMP 4
extern  PMAP2DUMPres * pmap2_dump_2();
extern  PMAP2DUMPres * pmap2_dump_2_svc();
#define PMAP2_CALLIT 5
extern  PMAP2CALLITres * pmap2_callit_2();
extern  PMAP2CALLITres * pmap2_callit_2_svc();
extern int pmap_program_2_freeresult ();
#endif /* K&R C */
#define PMAP_V3 3

#if defined(__STDC__) || defined(__cplusplus)
#define PMAP3_NULL 0
extern  void * pmap3_null_3(void *, void *);
extern  void * pmap3_null_3_svc(void *, struct svc_req *);
#define PMAP3_SET 1
extern  uint32_t * pmap3_set_3(PMAP3SETargs *, void *);
extern  uint32_t * pmap3_set_3_svc(PMAP3SETargs *, struct svc_req *);
#define PMAP3_UNSET 2
extern  uint32_t * pmap3_unset_3(PMAP3UNSETargs *, void *);
extern  uint32_t * pmap3_unset_3_svc(PMAP3UNSETargs *, struct svc_req *);
#define PMAP3_GETADDR 3
extern  PMAP3GETADDRres * pmap3_getaddr_3(PMAP3GETADDRargs *, void *);
extern  PMAP3GETADDRres * pmap3_getaddr_3_svc(PMAP3GETADDRargs *, struct svc_req *);
#define PMAP3_DUMP 4
extern  PMAP3DUMPres * pmap3_dump_3(void *, void *);
extern  PMAP3DUMPres * pmap3_dump_3_svc(void *, struct svc_req *);
#define PMAP3_CALLIT 5
extern  PMAP3CALLITres * pmap3_callit_3(PMAP3CALLITargs *, void *);
extern  PMAP3CALLITres * pmap3_callit_3_svc(PMAP3CALLITargs *, struct svc_req *);
#define PMAP3_GETTIME 6
extern  uint32_t * pmap3_gettime_3(void *, void *);
extern  uint32_t * pmap3_gettime_3_svc(void *, struct svc_req *);
#define PMAP3_UADDR2TADDR 7
extern  PMAP3UADDR2TADDRres * pmap3_uaddr2taddr_3(char **, void *);
extern  PMAP3UADDR2TADDRres * pmap3_uaddr2taddr_3_svc(char **, struct svc_req *);
#define PMAP3_TADDR2UADDR 8
extern  PMAP3TADDR2UADDRres * pmap3_taddr2uaddr_3(PMAP3TADDR2UADDRargs *, void *);
extern  PMAP3TADDR2UADDRres * pmap3_taddr2uaddr_3_svc(PMAP3TADDR2UADDRargs *, struct svc_req *);
extern int pmap_program_3_freeresult (void *, zdrproc_t, caddr_t);

#else /* K&R C */
#define PMAP3_NULL 0
extern  void * pmap3_null_3();
extern  void * pmap3_null_3_svc();
#define PMAP3_SET 1
extern  uint32_t * pmap3_set_3();
extern  uint32_t * pmap3_set_3_svc();
#define PMAP3_UNSET 2
extern  uint32_t * pmap3_unset_3();
extern  uint32_t * pmap3_unset_3_svc();
#define PMAP3_GETADDR 3
extern  PMAP3GETADDRres * pmap3_getaddr_3();
extern  PMAP3GETADDRres * pmap3_getaddr_3_svc();
#define PMAP3_DUMP 4
extern  PMAP3DUMPres * pmap3_dump_3();
extern  PMAP3DUMPres * pmap3_dump_3_svc();
#define PMAP3_CALLIT 5
extern  PMAP3CALLITres * pmap3_callit_3();
extern  PMAP3CALLITres * pmap3_callit_3_svc();
#define PMAP3_GETTIME 6
extern  uint32_t * pmap3_gettime_3();
extern  uint32_t * pmap3_gettime_3_svc();
#define PMAP3_UADDR2TADDR 7
extern  PMAP3UADDR2TADDRres * pmap3_uaddr2taddr_3();
extern  PMAP3UADDR2TADDRres * pmap3_uaddr2taddr_3_svc();
#define PMAP3_TADDR2UADDR 8
extern  PMAP3TADDR2UADDRres * pmap3_taddr2uaddr_3();
extern  PMAP3TADDR2UADDRres * pmap3_taddr2uaddr_3_svc();
extern int pmap_program_3_freeresult ();
#endif /* K&R C */

/* the zdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  uint32_t zdr_pmap2_mapping (ZDR *, pmap2_mapping*);
extern  uint32_t zdr_pmap2_call_args (ZDR *, pmap2_call_args*);
extern  uint32_t zdr_pmap2_call_result (ZDR *, pmap2_call_result*);
extern  uint32_t zdr_pmap2_mapping_list (ZDR *, pmap2_mapping_list*);
extern  uint32_t zdr_pmap2_dump_result (ZDR *, pmap2_dump_result*);
extern  uint32_t zdr_pmap3_string_result (ZDR *, pmap3_string_result*);
extern  uint32_t zdr_pmap3_mapping (ZDR *, pmap3_mapping*);
extern  uint32_t zdr_pmap3_mapping_list (ZDR *, pmap3_mapping_list*);
extern  uint32_t zdr_pmap3_dump_result (ZDR *, pmap3_dump_result*);
extern  uint32_t zdr_pmap3_call_args (ZDR *, pmap3_call_args*);
extern  uint32_t zdr_pmap3_call_result (ZDR *, pmap3_call_result*);
extern  uint32_t zdr_pmap3_netbuf (ZDR *, pmap3_netbuf*);
extern  uint32_t zdr_PMAP2SETargs (ZDR *, PMAP2SETargs*);
extern  uint32_t zdr_PMAP2UNSETargs (ZDR *, PMAP2UNSETargs*);
extern  uint32_t zdr_PMAP2GETPORTargs (ZDR *, PMAP2GETPORTargs*);
extern  uint32_t zdr_PMAP2CALLITargs (ZDR *, PMAP2CALLITargs*);
extern  uint32_t zdr_PMAP2CALLITres (ZDR *, PMAP2CALLITres*);
extern  uint32_t zdr_PMAP2DUMPres (ZDR *, PMAP2DUMPres*);
extern  uint32_t zdr_PMAP3SETargs (ZDR *, PMAP3SETargs*);
extern  uint32_t zdr_PMAP3UNSETargs (ZDR *, PMAP3UNSETargs*);
extern  uint32_t zdr_PMAP3GETADDRargs (ZDR *, PMAP3GETADDRargs*);
extern  uint32_t zdr_PMAP3GETADDRres (ZDR *, PMAP3GETADDRres*);
extern  uint32_t zdr_PMAP3DUMPres (ZDR *, PMAP3DUMPres*);
extern  uint32_t zdr_PMAP3CALLITargs (ZDR *, PMAP3CALLITargs*);
extern  uint32_t zdr_PMAP3CALLITres (ZDR *, PMAP3CALLITres*);
extern  uint32_t zdr_PMAP3UADDR2TADDRres (ZDR *, PMAP3UADDR2TADDRres*);
extern  uint32_t zdr_PMAP3TADDR2UADDRargs (ZDR *, PMAP3TADDR2UADDRargs*);
extern  uint32_t zdr_PMAP3TADDR2UADDRres (ZDR *, PMAP3TADDR2UADDRres*);

#else /* K&R C */
extern uint32_t zdr_pmap2_mapping ();
extern uint32_t zdr_pmap2_call_args ();
extern uint32_t zdr_pmap2_call_result ();
extern uint32_t zdr_pmap2_mapping_list ();
extern uint32_t zdr_pmap2_dump_result ();
extern uint32_t zdr_pmap3_string_result ();
extern uint32_t zdr_pmap3_mapping ();
extern uint32_t zdr_pmap3_mapping_list ();
extern uint32_t zdr_pmap3_dump_result ();
extern uint32_t zdr_pmap3_call_args ();
extern uint32_t zdr_pmap3_call_result ();
extern uint32_t zdr_pmap3_netbuf ();
extern uint32_t zdr_PMAP2SETargs ();
extern uint32_t zdr_PMAP2UNSETargs ();
extern uint32_t zdr_PMAP2GETPORTargs ();
extern uint32_t zdr_PMAP2CALLITargs ();
extern uint32_t zdr_PMAP2CALLITres ();
extern uint32_t zdr_PMAP2DUMPres ();
extern uint32_t zdr_PMAP3SETargs ();
extern uint32_t zdr_PMAP3UNSETargs ();
extern uint32_t zdr_PMAP3GETADDRargs ();
extern uint32_t zdr_PMAP3GETADDRres ();
extern uint32_t zdr_PMAP3DUMPres ();
extern uint32_t zdr_PMAP3CALLITargs ();
extern uint32_t zdr_PMAP3CALLITres ();
extern uint32_t zdr_PMAP3UADDR2TADDRres ();
extern uint32_t zdr_PMAP3TADDR2UADDRargs ();
extern uint32_t zdr_PMAP3TADDR2UADDRres ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PORTMAP_H_RPCGEN */
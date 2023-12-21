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

#ifndef _NLM_H_RPCGEN
#define _NLM_H_RPCGEN

#include <nfsc/libnfs-zdr.h>


#ifdef __cplusplus
extern "C" {
#endif


struct nlm_fh4 {
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct nlm_fh4 nlm_fh4;

typedef char *nlm4_oh;

struct nlm_cookie {
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct nlm_cookie nlm_cookie;

enum nlmstat4 {
	NLM4_GRANTED = 0,
	NLM4_DENIED = 1,
	NLM4_DENIED_NOLOCKS = 2,
	NLM4_BLOCKED = 3,
	NLM4_DENIED_GRACE_PERIOD = 4,
	NLM4_DEADLCK = 5,
	NLM4_ROFS = 6,
	NLM4_STALE_FH = 7,
	NLM4_FBIG = 8,
	NLM4_FAILED = 9,
};
typedef enum nlmstat4 nlmstat4;

struct nlm4_holder {
	uint32_t exclusive;
	u_int svid;
	nlm4_oh oh;
	uint64_t l_offset;
	uint64_t l_len;
};
typedef struct nlm4_holder nlm4_holder;
#define NLM_MAXNAME 256

struct nlm4_lock {
	char *caller_name;
	struct nlm_fh4 fh;
	nlm4_oh oh;
	u_int svid;
	uint64_t l_offset;
	uint64_t l_len;
};
typedef struct nlm4_lock nlm4_lock;

struct nlm4_share {
	char *caller_name;
	struct nlm_fh4 fh;
	nlm4_oh oh;
	u_int mode;
	u_int access;
};
typedef struct nlm4_share nlm4_share;

struct nlm4_testres_denied {
	nlm4_holder holder;
};
typedef struct nlm4_testres_denied nlm4_testres_denied;

struct nlm4_testreply {
	nlmstat4 status;
	union {
		nlm4_testres_denied lock;
	} nlm4_testreply_u;
};
typedef struct nlm4_testreply nlm4_testreply;

struct NLM4_TESTres {
	nlm_cookie cookie;
	nlm4_testreply reply;
};
typedef struct NLM4_TESTres NLM4_TESTres;

struct NLM4_TESTargs {
	nlm_cookie cookie;
	uint32_t exclusive;
	nlm4_lock lock;
};
typedef struct NLM4_TESTargs NLM4_TESTargs;

struct NLM4_CANCres {
	nlm_cookie cookie;
	nlmstat4 status;
};
typedef struct NLM4_CANCres NLM4_CANCres;

struct NLM4_CANCargs {
	nlm_cookie cookie;
	uint32_t block;
	uint32_t exclusive;
	nlm4_lock lock;
};
typedef struct NLM4_CANCargs NLM4_CANCargs;

struct NLM4_UNLOCKres {
	nlm_cookie cookie;
	nlmstat4 status;
};
typedef struct NLM4_UNLOCKres NLM4_UNLOCKres;

struct NLM4_UNLOCKargs {
	nlm_cookie cookie;
	nlm4_lock lock;
};
typedef struct NLM4_UNLOCKargs NLM4_UNLOCKargs;

struct NLM4_LOCKres {
	nlm_cookie cookie;
	nlmstat4 status;
};
typedef struct NLM4_LOCKres NLM4_LOCKres;

struct NLM4_LOCKargs {
	nlm_cookie cookie;
	uint32_t block;
	uint32_t exclusive;
	nlm4_lock lock;
	uint32_t reclaim;
	int state;
};
typedef struct NLM4_LOCKargs NLM4_LOCKargs;

struct NLM4_GRANTEDargs {
	nlm_cookie cookie;
	uint32_t exclusive;
	nlm4_lock lock;
};
typedef struct NLM4_GRANTEDargs NLM4_GRANTEDargs;

struct NLM4_GRANTEDres {
	nlm_cookie cookie;
	nlmstat4 status;
};
typedef struct NLM4_GRANTEDres NLM4_GRANTEDres;

struct NLM4_SHAREargs {
    nlm_cookie cookie;
    nlm4_share share;
    bool_t reclaim;
};
typedef struct NLM4_SHAREargs NLM4_SHAREargs;

struct NLM4_SHAREres {
    nlm_cookie cookie;
	  nlmstat4 status;
    int32_t sequence;
};
typedef struct NLM4_SHAREres NLM4_SHAREres;

struct NLM4_UNSHAREres {
    nlm_cookie cookie;
	  nlmstat4 status;
    int32_t sequence;
};
typedef struct NLM4_UNSHAREres NLM4_UNSHAREres;

#define NLM_PROGRAM 100021
#define NLM_V4 4

#if defined(__STDC__) || defined(__cplusplus)
#define NLM4_NULL 0
extern  void * nlm4_null_4(void *, void *);
extern  void * nlm4_null_4_svc(void *, struct svc_req *);
#define NLM4_TEST 1
extern  NLM4_TESTres * nlm4_test_4(NLM4_TESTargs *, void *);
extern  NLM4_TESTres * nlm4_test_4_svc(NLM4_TESTargs *, struct svc_req *);
#define NLM4_LOCK 2
extern  NLM4_LOCKres * nlm4_lock_4(NLM4_LOCKargs *, void *);
extern  NLM4_LOCKres * nlm4_lock_4_svc(NLM4_LOCKargs *, struct svc_req *);
#define NLM4_CANCEL 3
extern  NLM4_CANCres * nlm4_cancel_4(NLM4_CANCargs *, void *);
extern  NLM4_CANCres * nlm4_cancel_4_svc(NLM4_CANCargs *, struct svc_req *);
#define NLM4_UNLOCK 4
extern  NLM4_UNLOCKres * nlm4_unlock_4(NLM4_UNLOCKargs *, void *);
extern  NLM4_UNLOCKres * nlm4_unlock_4_svc(NLM4_UNLOCKargs *, struct svc_req *);
#define NLM4_GRANT 5
extern  NLM4_GRANTEDres * nlm4_grant_4(NLM4_GRANTEDargs *, void *);
extern  NLM4_GRANTEDres * nlm4_grant_4_svc(NLM4_GRANTEDargs *, struct svc_req *);
#define NLM4_TEST_MSG 6
extern  void * nlm4_test_msg_4(NLM4_TESTargs *, void *);
extern  void * nlm4_test_msg_4_svc(NLM4_TESTargs *, struct svc_req *);
#define NLM4_LOCK_MSG 7
extern  void * nlm4_lock_msg_4(NLM4_LOCKargs *, void *);
extern  void * nlm4_lock_msg_4_svc(NLM4_LOCKargs *, struct svc_req *);
#define NLM4_CANCEL_MSG 8
extern  void * nlm4_cancel_msg_4(NLM4_CANCargs *, void *);
extern  void * nlm4_cancel_msg_4_svc(NLM4_CANCargs *, struct svc_req *);
#define NLM4_UNLOCK_MSG 9
extern  void * nlm4_unlock_msg_4(NLM4_UNLOCKargs *, void *);
extern  void * nlm4_unlock_msg_4_svc(NLM4_UNLOCKargs *, struct svc_req *);
#define NLM4_GRANT_MSG 10
extern  void * nlm4_grant_msg_4(NLM4_GRANTEDargs *, void *);
extern  void * nlm4_grant_msg_4_svc(NLM4_GRANTEDargs *, struct svc_req *);
#define NLM4_TEST_RES 11
extern  void * nlm4_test_res_4(NLM4_TESTres *, void *);
extern  void * nlm4_test_res_4_svc(NLM4_TESTres *, struct svc_req *);
#define NLM4_LOCK_RES 12
extern  void * nlm4_lock_res_4(NLM4_LOCKres *, void *);
extern  void * nlm4_lock_res_4_svc(NLM4_LOCKres *, struct svc_req *);
#define NLM4_CANCEL_RES 13
extern  void * nlm4_cancel_res_4(NLM4_CANCres *, void *);
extern  void * nlm4_cancel_res_4_svc(NLM4_CANCres *, struct svc_req *);
#define NLM4_UNLOCK_RES 14
extern  void * nlm4_unlock_res_4(NLM4_UNLOCKres *, void *);
extern  void * nlm4_unlock_res_4_svc(NLM4_UNLOCKres *, struct svc_req *);
#define NLM4_GRANT_RES 15
extern  void * nlm4_grant_res_4(NLM4_GRANTEDres *, void *);
extern  void * nlm4_grant_res_4_svc(NLM4_GRANTEDres *, struct svc_req *);
extern int nlm_program_4_freeresult (void *, zdrproc_t, caddr_t);
#define NLM4_SHARE 20
extern NLM4_SHAREres *nlm4_share_4(NLM4_SHAREargs *, void *);
extern NLM4_SHAREres *nlm4_share_4_svc(NLM4_SHAREargs *,
               struct svc_req *);
#define NLM4_UNSHARE 21
extern NLM4_SHAREres *nlm4_unshare_4(NLM4_SHAREargs *, void *);
extern NLM4_SHAREres *nlm4_unshare_4_svc(NLM4_SHAREargs *,
                 struct svc_req *);

#else /* K&R C */
#define NLM4_NULL 0
extern  void * nlm4_null_4();
extern  void * nlm4_null_4_svc();
#define NLM4_TEST 1
extern  NLM4_TESTres * nlm4_test_4();
extern  NLM4_TESTres * nlm4_test_4_svc();
#define NLM4_LOCK 2
extern  NLM4_LOCKres * nlm4_lock_4();
extern  NLM4_LOCKres * nlm4_lock_4_svc();
#define NLM4_CANCEL 3
extern  NLM4_CANCres * nlm4_cancel_4();
extern  NLM4_CANCres * nlm4_cancel_4_svc();
#define NLM4_UNLOCK 4
extern  NLM4_UNLOCKres * nlm4_unlock_4();
extern  NLM4_UNLOCKres * nlm4_unlock_4_svc();
#define NLM4_GRANT 5
extern  NLM4_GRANTEDres * nlm4_grant_4();
extern  NLM4_GRANTEDres * nlm4_grant_4_svc();
#define NLM4_TEST_MSG 6
extern  void * nlm4_test_msg_4();
extern  void * nlm4_test_msg_4_svc();
#define NLM4_LOCK_MSG 7
extern  void * nlm4_lock_msg_4();
extern  void * nlm4_lock_msg_4_svc();
#define NLM4_CANCEL_MSG 8
extern  void * nlm4_cancel_msg_4();
extern  void * nlm4_cancel_msg_4_svc();
#define NLM4_UNLOCK_MSG 9
extern  void * nlm4_unlock_msg_4();
extern  void * nlm4_unlock_msg_4_svc();
#define NLM4_GRANT_MSG 10
extern  void * nlm4_grant_msg_4();
extern  void * nlm4_grant_msg_4_svc();
#define NLM4_TEST_RES 11
extern  void * nlm4_test_res_4();
extern  void * nlm4_test_res_4_svc();
#define NLM4_LOCK_RES 12
extern  void * nlm4_lock_res_4();
extern  void * nlm4_lock_res_4_svc();
#define NLM4_CANCEL_RES 13
extern  void * nlm4_cancel_res_4();
extern  void * nlm4_cancel_res_4_svc();
#define NLM4_UNLOCK_RES 14
extern  void * nlm4_unlock_res_4();
extern  void * nlm4_unlock_res_4_svc();
#define NLM4_GRANT_RES 15
extern  void * nlm4_grant_res_4();
extern  void * nlm4_grant_res_4_svc();
extern int nlm_program_4_freeresult ();
#define NLM4_SHARE 20
extern NLM4_SHAREres *nlm4_share_4();
extern NLM4_SHAREres *nlm4_share_4_svc();
#define NLM4_UNSHARE 21
extern NLM4_SHAREres *nlm4_unshare_4();
extern NLM4_SHAREres *nlm4_unshare_4_svc();
#endif /* K&R C */

/* the zdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  uint32_t zdr_nlm_fh4 (ZDR *, nlm_fh4*);
extern  uint32_t zdr_nlm4_oh (ZDR *, nlm4_oh*);
extern  uint32_t zdr_nlm_cookie (ZDR *, nlm_cookie*);
extern  uint32_t zdr_nlmstat4 (ZDR *, nlmstat4*);
extern  uint32_t zdr_nlm4_holder (ZDR *, nlm4_holder*);
extern  uint32_t zdr_nlm4_lock (ZDR *, nlm4_lock*);
extern  uint32_t zdr_nlm4_share (ZDR *, nlm4_share*);
extern  uint32_t zdr_nlm4_testres_denied (ZDR *, nlm4_testres_denied*);
extern  uint32_t zdr_nlm4_testreply (ZDR *, nlm4_testreply*);
extern  uint32_t zdr_NLM4_TESTres (ZDR *, NLM4_TESTres*);
extern  uint32_t zdr_NLM4_TESTargs (ZDR *, NLM4_TESTargs*);
extern  uint32_t zdr_NLM4_CANCres (ZDR *, NLM4_CANCres*);
extern  uint32_t zdr_NLM4_CANCargs (ZDR *, NLM4_CANCargs*);
extern  uint32_t zdr_NLM4_UNLOCKres (ZDR *, NLM4_UNLOCKres*);
extern  uint32_t zdr_NLM4_UNLOCKargs (ZDR *, NLM4_UNLOCKargs*);
extern  uint32_t zdr_NLM4_LOCKres (ZDR *, NLM4_LOCKres*);
extern  uint32_t zdr_NLM4_LOCKargs (ZDR *, NLM4_LOCKargs*);
extern  uint32_t zdr_NLM4_GRANTEDargs (ZDR *, NLM4_GRANTEDargs*);
extern  uint32_t zdr_NLM4_GRANTEDres (ZDR *, NLM4_GRANTEDres*);
extern  uint32_t zdr_NLM4_SHAREres (ZDR *, NLM4_SHAREres*);
extern  uint32_t zdr_NLM4_SHAREargs (ZDR *, NLM4_SHAREargs*);
extern  uint32_t zdr_NLM4_UNSHAREres (ZDR *, NLM4_UNSHAREres*);
extern  uint32_t zdr_NLM4_UNSHAREargs (ZDR *, NLM4_SHAREargs*);

#else /* K&R C */
extern uint32_t zdr_nlm_fh4 ();
extern uint32_t zdr_nlm4_oh ();
extern uint32_t zdr_nlm_cookie ();
extern uint32_t zdr_nlmstat4 ();
extern uint32_t zdr_nlm4_holder ();
extern uint32_t zdr_nlm4_lock ();
extern uint32_t zdr_nlm4_share ();
extern uint32_t zdr_nlm4_testres_denied ();
extern uint32_t zdr_nlm4_testreply ();
extern uint32_t zdr_NLM4_TESTres ();
extern uint32_t zdr_NLM4_TESTargs ();
extern uint32_t zdr_NLM4_CANCres ();
extern uint32_t zdr_NLM4_CANCargs ();
extern uint32_t zdr_NLM4_UNLOCKres ();
extern uint32_t zdr_NLM4_UNLOCKargs ();
extern uint32_t zdr_NLM4_LOCKres ();
extern uint32_t zdr_NLM4_LOCKargs ();
extern uint32_t zdr_NLM4_GRANTEDargs ();
extern uint32_t zdr_NLM4_GRANTEDres ();
extern  uint32_t zdr_NLM4_SHAREres ();
extern  uint32_t zdr_NLM4_SHAREargs ();
extern  uint32_t zdr_NLM4_UNSHAREres ();
extern  uint32_t zdr_NLM4_UNSHAREargs ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NLM_H_RPCGEN */
/*******************************************************************
 * File automatically generated by rebuild_wrappers.py (v2.2.0.18) *
 *******************************************************************/
#ifndef __wrappedlibtinfoTYPES_H_
#define __wrappedlibtinfoTYPES_H_

#ifndef LIBNAME
#error You should only #include this file inside a wrapped*.c file
#endif
#ifndef ADDED_FUNCTIONS
#define ADDED_FUNCTIONS() 
#endif

typedef int32_t (*iFpip_t)(void*, int32_t, void*);

#define SUPER() ADDED_FUNCTIONS() \
	GO(tputs, iFpip_t)

#endif // __wrappedlibtinfoTYPES_H_

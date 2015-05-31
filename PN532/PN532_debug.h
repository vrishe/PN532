#ifndef __DEBUG_H__
#define __DEBUG_H__


#include <Arduino.h>


#ifdef DEBUG

#ifdef __cplusplus
extern "C" {
#endif

Stream& __PN532_log();

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
#define PN532_LOG(stream) 		\
	extern "C" {				\
	Stream& __PN532_log() { 	\
		return stream; 			\
	}							\
	}
#else
#define PN532_LOG(stream) 		\
	Stream& __PN532_log() { 	\
		return stream; 			\
	}
#endif

#define DMSG(args...)       __PN532_log().print		(args)
#define DMSG_STR(str)       __PN532_log().println	(str)
#define DMSG_HEX(num)       __PN532_log().print		(' '); __PN532_log().print((num), HEX)
#define DMSG_INT(num)       __PN532_log().print		(' '); __PN532_log().print(num)

#else

#define PN532_LOG(stream);

#define DMSG(args...)
#define DMSG_STR(str)
#define DMSG_HEX(num)
#define DMSG_INT(num)

#endif

#endif

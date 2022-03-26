#ifdef __OBJC__
#import <UIKit/UIKit.h>
#else
#ifndef FOUNDATION_EXPORT
#if defined(__cplusplus)
#define FOUNDATION_EXPORT extern "C"
#else
#define FOUNDATION_EXPORT extern
#endif
#endif
#endif

#import "SFConfig.h"
#import "SFDefine.h"
#import "SFMacros.h"
#import "SFURL.h"

FOUNDATION_EXPORT double SFDefineVersionNumber;
FOUNDATION_EXPORT const unsigned char SFDefineVersionString[];


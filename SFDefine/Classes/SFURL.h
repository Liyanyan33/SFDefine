//
//  SFURL.h
//  YYShop_MVVM_OC
//
//  Created by liyanyan33 on 2022/3/18.
// 不同的服务器环境下的域名

#import "SFConfig.h"

#ifndef SFURL_h
#define SFURL_h

#pragma mark HTTP服务器域名-pre
#ifdef kPreTest
#define BaseURL @"https://wxminipre.baixingliangfan.cn/baixing/"

#pragma mark HTTP服务器域名-Sit
#elif kSitTest
#define BaseURL @"https://wxminisit.baixingliangfan.cn/baixing/"

#pragma mark HTTP服务器域名-prd
#elif kReleaseH
#define BaseURL @"https://wxmini.baixingliangfan.cn/baixing/"

#pragma mark HTTP服务器域名-pre-xg
#elif kPreXGTest
#define BaseURL @"https://wxminiprexg.baixingliangfan.cn/baixing/"

#endif

#endif /* SFURL_h */

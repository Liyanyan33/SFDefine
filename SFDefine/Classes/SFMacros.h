//
//  SFMacros.h
//  YYShop_MVVM_OC
//
//  Created by liyanyan33 on 2022/3/17.
//  常用宏

#ifndef SFMacros_h
#define SFMacros_h

#pragma mark 屏幕相关
///屏幕高度
#define ScreenH [UIScreen mainScreen].bounds.size.height

///屏幕宽度
#define ScreenW [UIScreen mainScreen].bounds.size.width

///iPhoneX 机型判断
#define iPhoneX (CGSizeEqualToSize(CGSizeMake(1125,2436), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(750,1624), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(1242,2688), [[UIScreen mainScreen] currentMode].size) || CGSizeEqualToSize(CGSizeMake(828,1792), [[UIScreen mainScreen] currentMode].size)|| CGSizeEqualToSize(CGSizeMake(1080,2340), [[UIScreen mainScreen] currentMode].size)|| CGSizeEqualToSize(CGSizeMake(1170,2532), [[UIScreen mainScreen] currentMode].size)|| CGSizeEqualToSize(CGSizeMake(1284,2778), [[UIScreen mainScreen] currentMode].size))

///状态栏的高度
#define YYStatuBarHeight [UIApplication sharedApplication].statusBarFrame.size.height

///导航栏延伸高度 (延伸到状态栏)
#define YYNavBarHeight (iPhoneX ? 44 + 44 : 44 + 20)

///tab栏的高度
#define YYTabBarHeight (iPhoneX ? 49 + 34 : 49)


#pragma mark 判空处理
//对象是否为空或是[NSNull null]
#define NotNilAndNull(_ref) (((_ref) != nil) && (![(_ref) isEqual:[NSNull null]]))
#define IsNilOrNull(_ref)   (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]))
//字符串是否为空
#define IsStrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref)isEqualToString:@""]))
//数组是否为空
#define IsArrEmpty(_ref)    (((_ref) == nil) || ([(_ref) isEqual:[NSNull null]]) ||([(_ref) count] == 0))

///判断字符串是否为空，为空则返回@"",反之则返回str
#define emptyString(str) (IsStrEmpty(str)?@"":str)

///判断字符串是否为空，为空则返回给定字符串,反之则返回str
#define defaultValueForEmpty(str,defaultString) (IsStrEmpty(str)?defaultString:str)

#pragma mark 字体相关
#define WD_MediumFontSize(s) NotNilAndNull([UIFont fontWithName:@"PingFangSC-Medium" size:s])?[UIFont fontWithName:@"PingFangSC-Medium" size:s]:[UIFont fontWithName:@"Helvetica" size:s]

#define WD_RegularFontSize(s) NotNilAndNull([UIFont fontWithName:@"PingFangSC-Regular" size:s])?[UIFont fontWithName:@"PingFangSC-Regular" size:s]:[UIFont fontWithName:@"Helvetica" size:s]

#define WD_SemiboldFontSize(s) NotNilAndNull([UIFont fontWithName:@"PingFangSC-Semibold" size:s])?[UIFont fontWithName:@"PingFangSC-Semibold" size:s]:[UIFont boldSystemFontOfSize:s]

#define WD_DINAlternateBoldFontSize(s) NotNilAndNull([UIFont fontWithName:@"DINAlternate-Bold" size:s])?[UIFont fontWithName:@"DINAlternate-Bold" size:s]:[UIFont boldSystemFontOfSize:s]

//#define WD_DINAlternate_BoldFontSize(s) [UIFont boldSystemFontOfSize:s]

#pragma mark 屏幕适配相关
#define ScreenWidthMoreThan320 (kScreenWidth > 320)

//iPhone5特殊处理，iPhone5保持和iPhone6一样的宽度/高度处理
#define customWidthForIPhone5(vaule) ScreenWidthMoreThan320?Get375Width(vaule):vaule
//iPhone5特殊处理，iPhone5缩小，宽度/高度/字体/处理
#define customVauleForIPhone5(vaule) ScreenWidthMoreThan320?vaule:Get375Width(vaule)
//适配高度
#define Get375Height(h)  (h) * ScreenW / 375.0f
//适配宽度
#define Get375Width(w)   (w) * ScreenW / 375.0f

#pragma mark 颜色相关
//主题色
#define WD_MainMarkColor            [UIColor colorWithHexString:@"#ff4c42"]
//色块上的白色文字等  （白色）
#define WD_WhiteColor               [UIColor colorWithHexString:@"#ffffff"]
//标题 商品名称 描述等  （黑色）
#define WD_BlackColor               [UIColor colorWithHexString:@"#333333"]
//淡灰色
#define WD_LightBlackColor          [UIColor colorWithHexString:@"#818181"]
//淡灰色
#define WD_LightGrayColor           [UIColor colorWithHexString:@"#cccccc"]
//灰色
#define WD_GrayColor                [UIColor colorWithHexString:@"#999999"]
//分割线颜色
#define WD_LineColor                [UIColor colorWithHexString:@"#DFDFDF"]
//分割线
#define WD_CellLineColor            [UIColor colorWithHexString:@"#e6e6e6"]
//色值
#define RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define RGB(r,g,b) RGBA(r,g,b,1.0f)
//随即色
#define RandomColor [UIColor colorWithRed:arc4random_uniform(256)/255.0 green:arc4random_uniform(256)/255.0 blue:arc4random_uniform(256)/255.0 alpha:1.0];


#pragma mark UIScrollView 适配
#define  MHAdjustsScrollViewInsets_Never(__scrollView)\
do {\
_Pragma("clang diagnostic push")\
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"")\
if ([__scrollView respondsToSelector:NSSelectorFromString(@"setContentInsetAdjustmentBehavior:")]) {\
NSMethodSignature *signature = [UIScrollView instanceMethodSignatureForSelector:@selector(setContentInsetAdjustmentBehavior:)];\
NSInvocation *invocation = [NSInvocation invocationWithMethodSignature:signature];\
NSInteger argument = 2;\
invocation.target = __scrollView;\
invocation.selector = @selector(setContentInsetAdjustmentBehavior:);\
[invocation setArgument:&argument atIndex:2];\
[invocation retainArguments];\
[invocation invoke];\
}\
_Pragma("clang diagnostic pop")\
} while (0)

#pragma mark TableView相关
#define kCellHeight      @"kCellHeight"
#define kCellData        @"kCellData"
#define kCellIdentifier  @"kCellIdentifier"

#define kTableViewNumberOfRowsKey               @"numberOfRows"
#define kTableViewCellListKey                   @"cellList"
#define kTableViewCellHeightKey                 @"cellHeight"
#define kTableViewCellIdentifierKey             @"cellIdentifier"
#define kTableViewCellDataKey                   @"cellData"
#define kTableViewCellSectionDataKey            @"sectionData"
#define kTableViewSectionHeaderHeightKey        @"sectionHeaderHeight"
#define kTableViewSectionHeaderTypeKey          @"sectionHeaderType"
#define kTableViewSectionFooterHeightKey        @"sectionFooterHeight"
#define kTableViewSectionFooterTypeKey          @"sectionFooterType"

#pragma mark Block相关
#ifdef NS_BLOCKS_AVAILABLE
typedef void (^SNBasicBlock)(void);

typedef void (^SNOperationCallBackBlock)(BOOL isSuccess, NSString *errorMsg, NSString *errorCode, NSString *isNeedImageCode, NSString *isRightImageCode);

typedef void (^SNArrayBlock)(NSArray *list);

typedef void (^SNCustomButtons)(NSString *callBack);

typedef void (^BBBasicBlock)(void);
#endif

#pragma mark 循环引用相关
#define SFWeakSelf __weak typeof(self) weakSelf = self;

#pragma mark iOS系统相关
#define iOS15_OR_LATER   ( [[[UIDevice currentDevice] systemVersion] compare:@"15.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS14_OR_LATER   ( [[[UIDevice currentDevice] systemVersion] compare:@"14.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS13_OR_LATER   ( [[[UIDevice currentDevice] systemVersion] compare:@"13.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS12_OR_LATER   ( [[[UIDevice currentDevice] systemVersion] compare:@"12.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS11_OR_LATER   ( [[[UIDevice currentDevice] systemVersion] compare:@"11.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS10_OR_LATER   ( [[[UIDevice currentDevice] systemVersion] compare:@"10.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS9_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"9.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS8_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"8.0" options:NSNumericSearch] != NSOrderedAscending )
#define iOS7_OR_LATER    ( [[[UIDevice currentDevice] systemVersion] compare:@"7.0" options:NSNumericSearch] != NSOrderedAscending )

#define IS_IPAD         (UI_USER_INTERFACE_IDIOM()==UIUserInterfaceIdiomPad)
#define IS_IPHONE_5     [SNSystemInfo is_iPhone_5];

#pragma mark app升级相关
//(AppStore、其余各市场)1 0苏宁发布管理平台
#define kIsOfficial 1
///存储应用版本的key
#define SFApplicationVersionKey   @"SBApplicationVersionKey"
///应用名称
#define SF_APP_NAME    ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleName"])
///应用版本号
#define SF_APP_VERSION ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"])
///应用build
#define SF_APP_BUILD   ([[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleVersion"])

///AppDelegate
#define SFSharedAppDelegate ((AppDelegate *)[UIApplication sharedApplication].delegate)


#pragma mark 沙盒路径
#define SFDocumentPath NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES).firstObject
#define SFLibraryPath  NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES).firstObject
#define SFCachePath    NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES).firstObject
#define SFTempPath     NSTemporaryDirectory()
#define SFHomePath     NSHomeDirectory()

#endif /* SFMacros_h */

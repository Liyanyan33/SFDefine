//
//  SFDefine.h
//  YYShop_MVVM_OC
//
//  Created by liyanyan33 on 2022/3/18.
//  枚举 通知名称 容器数据类处理

#import <Foundation/Foundation.h>

#pragma mark 集合取值容错处理
extern NSString* EncodeStringFromDic(NSDictionary *dic, NSString *key);
extern NSNumber* EncodeNumberFromDic(NSDictionary *dic, NSString *key);
extern NSDictionary* EncodeDicFromDic(NSDictionary *dic, NSString *key);
extern NSArray* EncodeArrayFromDic(NSDictionary *dic, NSString *key);
extern NSArray* EncodeArrayFromDicUsingParseBlock(NSDictionary *dic, NSString *key, id(^parseBlock)(NSDictionary *innerDic));

#pragma mark 所有枚举
///用户登录的渠道
typedef NS_ENUM(NSUInteger, SFUserLoginChannelType) {
    SFUserLoginChannelTypeQQ = 0,           ///qq登录
    SFUserLoginChannelTypeEmail,            ///邮箱登录
    SFUserLoginChannelTypeWeChatId,         ///微信号登录
    SFUserLoginChannelTypePhone,            ///手机号登录
};

///用户性别
typedef NS_ENUM(NSUInteger, SFUserGenderType) {
    SFUserGenderTypeMale = 0,           ///男
    SFUserGenderTypeFemale,             ///女
};

///切换根控制器类型
typedef NS_ENUM(NSUInteger, SFSwitchRootViewControllerFromType) {
    SFSwitchRootViewControllerFromTypeNewFeature = 0,  ///新特性
    SFSwitchRootViewControllerFromTypeLogin,           ///登录
    SFSwitchRootViewControllerFromTypeLogout,          ///登出
};

///tableView支持刷新
typedef NS_ENUM(NSInteger,SFTableViewRefreshType){
    SFTableViewRefreshTypeAll,       ///同时支持上拉 下拉
    SFTableViewRefreshTypePull,      ///只支持下拉
    SFTableViewRefreshTypeLoadMore,  ///只支持上拉
    SFTableViewRefreshTypeNone       ///均不支持
};

///SFBootLoginController 按钮类型
typedef NS_ENUM(NSInteger,SFBootLoginBtnType){
    SFBootLoginBtnTypeLogin,    ///登录
    SFBootLoginBtnTypeRegister, ///注册
    SFBootLoginBtnTypeLanguage  ///语言切换
};

#pragma mark - 通知相关
///切换根控制器的通知
FOUNDATION_EXTERN NSString * const SFSwitchRootViewControllerNotification;
///切换根控制器的通知 UserInfo key
FOUNDATION_EXTERN NSString * const SFSwitchRootViewControllerUserInfoKey;

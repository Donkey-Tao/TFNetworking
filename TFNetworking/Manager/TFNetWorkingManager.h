//
//  TFNetWorkingManager.h
//  TFNetworking
//
//  Created by Donkey-Tao on 2016/5/12.
//  Copyright © 2016年 http://taofei.me All rights reserved.


#import <Foundation/Foundation.h>
#import <AFNetworking/AFNetworking.h>
#import "TFNetworking.h"


NS_ASSUME_NONNULL_BEGIN


///---------------------------------------------------
/// @name Some Preferences Infomation
///---------------------------------------------------

/**
 * @brief 定义枚举类型的网络请求类型：GET OR POST
 * METHOD_GET: 网络请求方式为GET
 * METHOD_POST: 网络请求方式为POST
 */
typedef NS_ENUM(NSInteger,HTTPMETHOD)
{
    METHOD_GET   = 0,
    METHOD_POST  = 1,
};
/** 网络请求成功的回调 */
typedef void (^SuccessBlock)(id responseObject);
/** 网络请求失败的回调 */
typedef void (^FailedBlock)(NSError*error);



///----------------------------------------------------
/// @name Method declarations of TFNetWorkingManager
///----------------------------------------------------

/** TFNetWorkingManager是继承自TFHTTPSessionManager的子类，是在TFHTTPSessionManager基础上进行的封装。 */
@interface TFNetWorkingManager : TFHTTPSessionManager

#pragma mark - TFNetworkingManager的属性
/** 整个项目的网络请求的URL的基地址 */
@property (readonly, nonatomic, copy, nullable) NSString *baseURLString;


#pragma mark - 获取TFNetworking的单例对象
/**
 * @brief TFNetworkingManager的类方法，创建并获取TFNetworkingManager的单例对象
 * @return 返回类型为TFNetWorkingManager的单例对象
 */
+ (instancetype)sharedManager;



#pragma mark - 网络请求方法

/**
 * @brief iOS自带网络请求框架
 * @param urlstring URL地址的字符串
 * @param method URL地址的字符串
 * @param params 请求中使用的参数
 * @param SuccessBlock 请求成功的回调
 * @param failedBlock 请求失败的回调
 */
+ (void)requestURL:(NSString *)urlstring httpMethod:(NSInteger)method params:(NSMutableDictionary *)params complection:(SuccessBlock)SuccessBlock failed:(FailedBlock)failedBlock;

/**
 * @brief AFNetworking数据请求(HTTP)
 * @param URLString URL地址的字符串
 * @param method URL地址的字符串
 * @param parameters 请求中使用的参数
 * @param successBlock 请求成功的回调
 * @param failedBlock 请求失败的回调
 */
+(void)requestAFURL:(NSString *)URLString httpMethod:(NSInteger)method parameters:(id)parameters succeed:(SuccessBlock)successBlock failure:(FailedBlock)failedBlock;

/**
 * @brief AFNetworking网络请求(HTTPS)
 * @param URLString URL地址的字符串
 * @param method URL地址的字符串
 * @param parameters 请求中使用的参数
 * @param successBlock 请求成功的回调
 * @param failedBlock 请求失败的回调
 */
+ (void)requestAFURL:(NSString *)URLString httpMethod:(NSInteger)method Signature:(NSString *)signature Parameters:(NSDictionary *)parameters RequestTimes:(float)requestTimes succeed:(SuccessBlock)successBlock failure:(FailedBlock)failedBlock;



#pragma mark - 上传图片

/**
 * @brief 上传单张图片
 * @param URLString URL地址的字符串
 * @param imageData URL地址的字符串
 * @param parameters 请求中使用的参数
 * @param successBlock 请求成功的回调
 * @param failedBlock 请求失败的回调
 */
+(void)requestAFURL:(NSString *)URLString parameters:(id)parameters imageData:(NSData *)imageData succeed:(SuccessBlock)successBlock failure:(FailedBlock)failedBlock;


/**
 * @brief 上传多张图片
 * @param URLString URL地址的字符串
 * @param parameters 请求中使用的参数
 * @param imageDataArray URL地址的字符串
 * @param successBlock 请求成功的回调
 * @param failedBlock 请求失败的回调
 */
+(void)requestAFURL:(NSString *)URLString parameters:(id)parameters  imageDataArray:(NSArray *)imageDataArray succeed:(SuccessBlock)successBlock failure:(FailedBlock)failedBlock;


/**
 * @brief 上传文件
 * @param URLString URL地址的字符串
 * @param parameters 请求中使用的参数
 * @param fileData URL地址的字符串
 * @param successBlock 请求成功的回调
 * @param failedBlock 请求失败的回调
 */
+(void)requestAFURL:(NSString *)URLString parameters:(id)parameters fileData:(NSData *)fileData succeed:(SuccessBlock)successBlock  failure:(FailedBlock)failedBlock;



#pragma mark - 字符串与JSON的转换

/**
 * @brief 把格式化的JSON格式的字符串转换成字典
 * @param jsonString JSON格式的字符串
 * @return 返回字典
 */
+ (NSDictionary *)dictionaryWithJsonString:(NSString *)jsonString;


/**
 * @brief 把字典转换成字符串
 * @param paramDict 字典
 * @param _type 类型
 * @return 返回字符串
 */
+(NSString*)URLEncryOrDecryString:(NSDictionary *)paramDict IsHead:(BOOL)_type;

@end


NS_ASSUME_NONNULL_END

//
//  EncryptionTools.h
//

#import <Foundation/Foundation.h>
#import <CommonCrypto/CommonCrypto.h>

/**
 *  终端测试指令
 *
 *  DES(ECB)加密
 *  $ echo -n 520it | openssl enc -des-ecb -K 616263 -nosalt | base64
 *
  * DES(CBC)加密
 *  $ echo -n 520it | openssl enc -des-cbc -iv 0102030405060708 -K 616263 -nosalt | base64
 *
 *  AES(ECB)加密
 *  $ echo -n 520it | openssl enc -aes-128-ecb -K 616263 -nosalt | base64
 *
 *  AES(CBC)加密
 *  $ echo -n 520it | openssl enc -aes-128-cbc -iv 0102030405060708 -K 616263 -nosalt | base64
 ***********************************************************************
 *  DES(ECB)解密
 *  $ echo -n VqYjXo2ZlU4= | base64 -D | openssl enc -des-ecb -K 616263 -nosalt -d
 *
 *  DES(CBC)解密
 *  $ echo -n 7MCnAFj6DpQ= | base64 -D | openssl enc -des-cbc -iv 0102030405060708 -K 616263 -nosalt -d
 *
 *  AES(ECB)解密
 *  $ echo -n FqRpCOQG9IL2QrKBHhM+fA== | base64 -D | openssl enc -aes-128-ecb -K 616263 -nosalt -d
 *
 *  AES(CBC)解密
 *  $ echo -n Kd9MN/rNEI40hdLhayPbUw== | base64 -D | openssl enc -aes-128-cbc -iv 0102030405060708 -K 616263 -nosalt -d
 *
 *  提示：
 *      1> 加密过程是先加密，再base64编码
 *      2> 解密过程是先base64解码，再解密
 */
@interface EncryptionTools : NSObject

+ (instancetype)sharedEncryptionTools;

/**
 @constant   kCCAlgorithmAES     高级加密标准，128位(默认)
 @constant   kCCAlgorithmDES     数据加密标准
 */
@property (nonatomic, assign) uint32_t algorithm;

/**AEC-ECB 默认128位
 *  加密字符串并返回base64编码字符串
 *
 *  @param string    要加密的字符串
 *  @param keyString 加密密钥
 *  @param iv 初始化向量(8个字节)(在CBC中用到，ECB中为nil)
 *  @return 返回加密后的base64编码字符串
 */
- (NSString *)encryptString:(NSString *)string keyString:(NSString *)keyString iv:(NSData *)iv;

/**AEC-ECB解密 
 *  解密字符串
 *
 *  @param string    加密并base64编码后的字符串
 *  @param keyString 解密密钥
 *  @param iv        初始化向量(8个字节)
 *
 *  @return 返回解密后的字符串
 */
- (NSString *)decryptString:(NSString *)string keyString:(NSString *)keyString iv:(NSData *)iv;

/*加密 返回16进制字符串
 *string  需要加密的字符串
 *keyString 密钥
 */
- (NSString *)AES128ECBencryptString:(NSString *)string keyString:(NSString *)keyString iv:(NSData *)iv;

/*AES 128 ECB解密 16进制字符串解密为字符串
 *encryText  加密后的16进制字符串
 *key  密钥
 *@param iv 初始化向量(8个字节)(在CBC中用到，ECB中为nil)
 */
-(NSString *)AES128Decrypt:(NSString *)encryptText key:(NSString *)key;

//加密后的密文NSData转为16进制
- (NSString *)hexStringFromData:(NSData *)data;
//16进制转NSData
-(NSData*)dataForHexString:(NSString*)hexString;
@end

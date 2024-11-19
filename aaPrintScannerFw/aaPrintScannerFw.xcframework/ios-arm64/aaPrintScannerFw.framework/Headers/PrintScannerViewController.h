//
//  aaAppHandler.h
//  aaprintscanner
//
//  Created by aaTech on 9/25/19.
//  Copyright © 2019 aaTech. All rights reserved.
//
#import <UIKit/UiKit.h>
#import <Foundation/Foundation.h>

#ifndef PrintScannerViewController_h
#define PrintScannerViewController_h

#define SUBJECT_MAX_CAPTURES    10
#define SUBJECT_MAX_FINGERS     10
#define SUBJECT_MAX_IDLENGTH    256
#define TEXTSTRING_MAX_LENGTH   1024//64
typedef enum _AA_FINGER_TYPE
{
    AA_FINGER_TYPE_RT           = 1,
    AA_FINGER_TYPE_RI           = 2,
    AA_FINGER_TYPE_RM           = 3,
    AA_FINGER_TYPE_RR           = 4,
    AA_FINGER_TYPE_RL           = 5,
    AA_FINGER_TYPE_LT           = 6,
    AA_FINGER_TYPE_LI           = 7,
    AA_FINGER_TYPE_LM           = 8,
    AA_FINGER_TYPE_LR           = 9,
    AA_FINGER_TYPE_LL           = 10,
} AA_FINGER_TYPE;

typedef enum _AA_CAPTURE_TYPE
{
    AA_CAPTURE_TYPE_ONE_FINGER  = 1,
    AA_CAPTURE_TYPE_TWO_FINGER  = 2,
    AA_CAPTURE_TYPE_FOUR_FINGER = 3,
    AA_CAPTURE_TYPE_THREE_ONE   = 4,
} AA_CAPTURE_TYPE;

typedef enum _AA_TEXTSTRING_TYPE
{
    AA_TEXTSTRINGTYPE_TEXT_CANCEL_YES       = 1,
    AA_TEXTSTRINGTYPE_TEXT_CANCEL_NO        = 2,
    AA_TEXTSTRINGTYPE_PREFIX_RESCAN         = 3,
    AA_TEXTSTRINGTYPE_PREFIX_LEFT           = 4,
    AA_TEXTSTRINGTYPE_PREFIX_RIGHT          = 5,
    AA_TEXTSTRINGTYPE_BASE_THUMB            = 6,
    AA_TEXTSTRINGTYPE_BASE_INDEX            = 7,
    AA_TEXTSTRINGTYPE_BASE_MIDDLE           = 8,
    AA_TEXTSTRINGTYPE_BASE_RING             = 9,
    AA_TEXTSTRINGTYPE_BASE_LITTLE           = 10,
    AA_TEXTSTRINGTYPE_BASE_IM               = 11,
    AA_TEXTSTRINGTYPE_BASE_RL               = 12,
    AA_TEXTSTRINGTYPE_BASE_4FINGER          = 13,
    AA_TEXTSTRINGTYPE_MESSAGE_CANCEL_CONFIRM    = 14,
    AA_TEXTSTRINGTYPE_MESSAGE_BG_ISSUE      = 15,
    AA_TEXTSTRINGTYPE_MESSAGE_BG_CHANGED    = 16,
    AA_TEXTSTRINGTYPE_MESSAGE_FINGER_TOOCLOSE   = 17,
    AA_TEXTSTRINGTYPE_MESSAGE_FINGER_TOOFAR = 18,
    AA_TEXTSTRINGTYPE_MESSAGE_FINGER_OUTSIDE    = 19,
    AA_TEXTSTRINGTYPE_MESSAGE_FINGER_EXIT   = 20,
    AA_TEXTSTRINGTYPE_MESSAGE_FINGER_ENTER  = 21,
    AA_TEXTSTRINGTYPE_MESSAGE_FINGER_NOTINPOSITION = 22,
    AA_TEXTSTRINGTYPE_DISPLAYTEXT           = 23,
    
    AA_TEXTSTRINGTYPE_STATUS_SCANNING       = 24,
    AA_TEXTSTRINGTYPE_STATUS_PROCESSING     = 25,
    AA_TEXTSTRINGTYPE_STATUS_RESCANNING     = 26,
    AA_TEXTSTRINGTYPE_STATUS_COMPLETED      = 27,
    
    AA_TEXTSTRINGTYPE_MESSAGE_USE_DARKBG    = 28,
    AA_TEXTSTRINGTYPE_MESSAGE_WRONG_HAND   = 29,
    AA_TEXTSTRINGTYPE_MESSAGE_USE_WHITEBG   = 30,
    
    AA_TEXTSTRINGTYPE_MESSAGE_TIMEOUT_CONFIRM = 31,
    AA_TEXTSTRINGTYPE_MESSAGE_CANCEL_CONFIRM_TITLE = 32,
    AA_TEXTSTRINGTYPE_MESSAGE_FINGER_SKEWED = 33,
    AA_TEXTSTRINGTYPE_MESSAGE_FOCUSING      = 34,
    
    AA_TEXTSTRINGTYPE_MESSAGE_MOVE_CLOSER   = 35,
    AA_TEXTSTRINGTYPE_MESSAGE_MOVE_FARTHER  = 36,
    AA_TEXTSTRINGTYPE_MESSAGE_MOVE_ENABLED  = 37,
    
    AA_TEXTSTRINGTYPE_MESSAGE_BG_TOOBRIGHT = 38,
} AA_TEXTSTRING_TYPE;

typedef enum _AA_HAND_DETECTION_THRESHOLD_TYPE
{
    AA_HAND_DETECTION_TYPE_THUMB            = 0,
    AA_HAND_DETECTION_TYPE_THUMB_BLOCKING   = 1,
    AA_HAND_DETECTION_TYPE_4F               = 2,
    AA_HAND_DETECTION_TYPE_4F_BLOCKING      = 3,
} AA_HAND_DETECTION_THRESHOLD_TYPE;

typedef enum _AA_CAPTUREIMAGE_TYPE
{
    AA_CAPTUREIMAGE_TYPE_BMP    = 0,
    AA_CAPTUREIMAGE_TYPE_WSQ    = 1,
    AA_CAPTUREIMAGE_TYPE_YUV    = 2,
} AA_CAPTUREIMAGE_TYPE;

typedef enum _AA_LICENSEDATA_TYPE
{
    AA_LICENSEDATA_TYPE_AA          = 0,
    AA_LICENSEDATA_TYPE_LIC         = 1
} AA_LICENSEDATA_TYPE;

typedef enum _AA_LICENSEDATA_STATUS
{
    AA_LICENSEDATA_STATUS_INVALID    = -1,
    AA_LICENSEDATA_STATUS_MISSING    = -2,
    AA_LICENSEDATA_STATUS_VALID      = 1,
} AA_LICENSEDATA_STATUS;

typedef enum _AA_FINGERERROR_TYPE
{
    AA_FINGERERROR_NOERROR           = 0,
    AA_FINGERERROR_QUALITYERROR      = 1,
    AA_FINGERERROR_SEQUENTIALERROR   = 2,
} AA_FINGERERROR_TYPE;

typedef enum _AA_QUALITY_TYPE
{
    AA_QUALITY_TYPE_LOW             = 0,
    AA_QUALITY_TYPE_MID             = 1,
    AA_QUALITY_TYPE_HIGH            = 2,
} AA_QUALITY_TYPE;

typedef enum _AA_TIMEOUT_MODE
{
    AA_TIMEOUT_MODE_BESTATTIMEOUT   = 0,
    AA_TIMEOUT_MODE_SKIPATTIMEOUT   = 1,
    AA_TIMEOUT_MODE_NOTIMEOUT       = 2,
} AA_TIMEOUT_MODE;

typedef enum _AA_GENDER
{
    AA_GENDER_MALE                  = 0,
    AA_GENDER_FEMALE                = 1,
} AA_GENDER;

typedef enum _AA_RECAPTURE_TYPE
{
    AA_RECAPTURE_TYPE_NONE          = 0,
    AA_RECAPTURE_TYPE_INTERNAL      = 1,
    AA_RECAPTURE_TYPE_EXTERNAL      = 2,
} AA_RECAPTURE_TYPE;

typedef enum _AA_2F_CAPTURETYPE
{
    AA_2F_CAPTURETYPE_SINGLE        = 0,
    AA_2F_CAPTURETYPE_DOUBLE        = 1,
} AA_2F_CAPTURETYPE;

typedef enum _AA_CALIBRATION_STATUS
{
    AA_CALIBRATION_STATUS_ERROR         = 0,
    AA_CALIBRATION_STATUS_VALID         = 1,
    AA_CALIBRATION_STATUS_MISSING       = 2,
    AA_CALIBRATION_STATUS_DEVICENOTFOUND= 3,
    AA_CALIBRATION_STATUS_DATAERROR     = 4,

} AA_CALIBRATION_STATUS;

@class TextStrings;
@interface TextStrings : NSObject
-(void)setTextDirectionR2L:(BOOL)rightToLeft;
-(void)setText:(NSString*)text ofType:(AA_TEXTSTRING_TYPE)type;
@end

@class InitParams;
@interface InitParams : NSObject
//-(void)setRecaptureScoreMin:(NSArray*)array;
//-(void)setRecaptureTriesMax:(int)max;
-(void)setDisplayScoreOn:(BOOL)on;
-(void)setScoreType:(int)scoreType;
-(void)setDevModeOn:(BOOL)on;
-(void)setCancelConfirmOn:(BOOL)on;
//-(void)setExternalRecaptureOn:(BOOL)on;
-(void)setTextStrings:(TextStrings*)textString;
-(void)setAccountId:(NSString*)accountId;
-(void)setDisplayText:(NSString*)displayText;
-(void)setOverlayRotationOn:(BOOL)on;
-(void)setOverlay4FWidthScale:(float)scale;
-(void)setMessageBoxTopMargin:(int)topMargin;
-(void)setQualityThresholdHigh:(int)threshold;
-(void)setQualityThresholdMid:(int)threshold;
-(void)setQualityThresholdLow:(int)threshold;
-(void)setTorchButtonOn:(BOOL)on;
-(void)setBypassFingerNailCheck:(BOOL)bypass;
-(void)setFingerEnterAnimationOn:(BOOL)on;
-(void)setOverlayInsetOn:(BOOL)on;
-(void)setDebugOn:(BOOL)on;
-(void)setFingerTrackingOn:(BOOL)on;
-(void)setHandDetectionOn:(BOOL)on;
-(void)setHandDetectionThreshold:(int)value ofType:(AA_HAND_DETECTION_THRESHOLD_TYPE)type;
-(void)setOverlayDetectedOpacity:(float)detectedOpacity nonDetectedOpacity:(float)nonDetectedOpacity;
-(void)setSubjectTimeoutTime:(long)ms;
-(void)setCancelButtonOn:(BOOL)on;
-(void)setDisplayThumbTipOn:(BOOL)on;
-(void)setThumbSkewDetectOn:(BOOL)on;
-(void)setThumbSkewThresholds:(int)t1 :(int)t2 :(int)t3;
-(void)setNfiqOptimizeOn:(BOOL)on;
-(void)setRefocusButtonOn:(BOOL)on;

//Recapture
-(void)setRecaptureType:(AA_RECAPTURE_TYPE)recaptureType;
-(void)setRecaptureTriesMax:(int)retries;
-(void)setRecaptureNfiqThreshold:(int)threshold;
-(void)setRecapturePrimaryPassCount:(int)passCount;
-(void)setRecaptureSecondaryPassCount:(int)passCount;

//RecaptureDialog
-(void)setRecaptureDialogOn:(BOOL)on;
-(void)setRecaptureDialogAllowCancelCount:(int)count;

//2Finger Capture Type
-(void)setTwoFingerCaptureType:(AA_2F_CAPTURETYPE)captureType;

//ClipImage on
-(void)setClipImageOn:(BOOL)on;

//CaptureLog on
-(void)setCaptureLogOn:(BOOL)on;

-(void)setAsyncCaptureOn:(BOOL)on;
-(void)setNfiqOn:(BOOL)on;
-(void)setLockModeOn:(BOOL)on;
@end

@class CaptureProfile;
@interface CaptureProfile : NSObject
-(void)setSubjectId:(NSString*)subjectId;
-(void)setSaveDir:(NSString*)saveDir;
-(void)setFingerTypes:(NSArray<NSNumber*>*)fingerTypes;
-(void)setCaptureTypes:(NSArray<NSNumber*>*)captureTypes;
-(void)setFingersPerCapture:(NSArray<NSNumber*>*)fingersPerCapture;
-(void)setSaveImageWidth:(int)width;
-(void)setSaveImageHeight:(int)height;
-(void)setSaveWsqMaxSize:(int)maxSize;
-(void)setSaveImageType:(AA_CAPTUREIMAGE_TYPE)type;
-(void)setGender:(AA_GENDER)gender;
@end

@class CaptureImage;
@interface CaptureImage : NSObject
-(NSData*)getData;
-(AA_CAPTUREIMAGE_TYPE)getType;
-(int)getWidth;
-(int)getHeight;
@end

@class CaptureResult;
@interface CaptureResult : NSObject
-(NSString*)getSubjectId;
-(AA_FINGER_TYPE)getFingerType;
-(CaptureImage*)getImage;
-(CaptureImage*)getDisplayImage;
-(CaptureImage*)getDebugImage;
-(CaptureImage*)getClipBmp;
-(CaptureImage*)getClipWsq;
-(CaptureImage*)getVerifyBmp;
-(int)getNfiqScore;
-(int)getMntCount;
-(int)getAaQuality;
-(int)getClipNfiqScore;
-(int)getClipMntCount;
-(int)getClipAaQuality;
-(AA_FINGERERROR_TYPE)getFingerError;
-(BOOL)getTimedOut;
-(BOOL)getIsRecapturing;
@end

@class LicenseData;
@interface LicenseData : NSObject
-(NSData*)getData;
-(void)setData:(NSData*)data;
-(AA_LICENSEDATA_TYPE)getType;
-(void)setType:(AA_LICENSEDATA_TYPE)type;
@end

@class QualityThreshold;
@interface QualityThreshold : NSObject
-(int)getQualityThresholdOfFingerType:(AA_FINGER_TYPE) fingerType andQualityType:(AA_QUALITY_TYPE)qualityType;
-(void)setQualityThreshold:(int)threshold ofFingerType:(AA_FINGER_TYPE)fingerType andQualityType:(AA_QUALITY_TYPE)qualityType;

-(AA_TIMEOUT_MODE)getTimeoutMode;
-(void)setTimeoutMode:(AA_TIMEOUT_MODE)mode;

-(int)getTimeHigh;
-(int)getTimeMid;
-(int)getTimeTimeout;

-(void)setTimeHigh:(int)time;
-(void)setTimeMid:(int)time;
-(void)setTimeTimeout:(int)time;
@end

@class PrintScannerViewController;
@protocol PrintScannerDelegate<NSObject>
-(void)onCaptureSaved:(NSString*)subjectId;
-(void)onCaptureCanceled;
-(void)onCaptureProcessed:(NSString*)subjectId;
-(NSArray<NSNumber*>*)getRecaptureFingers:(NSArray<CaptureResult*>*)captureResults;
-(NSString*)getRecaptureDialogMessage:(NSArray<CaptureResult*>*)captureResults;
@end

@interface PrintScannerViewController : UIViewController
+(NSString*)getVersion;
+(LicenseData*)getPreLicenseData;
+(int)setLicenseData:(LicenseData*)data;
+(AA_LICENSEDATA_STATUS)checkLicense:(NSString*)accountId;
+(void)voidLicense;
+(void)setQualityThreshold:(QualityThreshold*)qualityThreshold;
+(void)logFunctionName:(NSString*)functionName message:(NSString*)message;
+(int)setMeasurementData:(NSData*)data;

//CalibrationData
+(AA_CALIBRATION_STATUS)checkCalibrationData;
+(int)setCalibrationData:(NSData*)data;

-(instancetype)initWithParams:(InitParams*)params andDelegate:(id<PrintScannerDelegate>) delegate;
-(NSString*)startCapture:(CaptureProfile*)profile;
-(NSString*)startRecapture:(CaptureProfile*)profile;
-(int)saveCapture:(NSString*)subjectId;
-(int)discardCapture:(NSString*)subjectId;
-(NSArray<CaptureResult*>*)getCaptureResults:(NSString*)subjectId;
-(void)pause;
-(void)resume;
-(void)deinit;
-(void)reset;

//CaptureLog
-(NSString*)getCaptureLog;
@end

#endif

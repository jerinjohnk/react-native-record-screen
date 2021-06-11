#import <React/RCTBridgeModule.h>
#import <ReplayKit/ReplayKit.h>
#import <AVFoundation/AVFoundation.h>

@interface RecordScreen : NSObject <RCTBridgeModule>

    @property (strong, nonatomic) RPScreenRecorder *screenRecorder;
    @property (strong, nonatomic) AVAssetWriterInput *videoInput;
    @property (strong, nonatomic) AVAssetWriterInput *audioInput;
    @property (strong, nonatomic) AVAssetWriterInput *micInput;
    @property (assign, nonatomic) int screenWidth;
    @property (assign, nonatomic) int screenHeight;
    @property (assign, nonatomic) BOOL enableMic;
    @property (assign, nonatomic) NSNumber *videoBitRate;
    @property (assign, nonatomic) NSNumber *videoFrameRate;

    @property (nonatomic) AVAssetWriter *writer;
    @property BOOL encounteredFirstBuffer;

@end

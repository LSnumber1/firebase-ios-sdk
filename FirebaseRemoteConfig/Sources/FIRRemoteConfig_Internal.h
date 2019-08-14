#import "googlemac/iPhone/Config/RemoteConfig/Source/FIRRemoteConfig.h"

#import "googlemac/iPhone/Config/RemoteConfig/Source/RCNConfigSettings.h"
#import "third_party/firebase/ios/Releases/FirebaseInterop/Analytics/Public/FIRAnalyticsInterop.h"

@class FIROptions;
@class RCNConfigContent;
@class RCNConfigDBManager;

NS_ASSUME_NONNULL_BEGIN

@class RCNConfigSettings;

@interface FIRRemoteConfig () {
  NSString *_FIRNamespace;
}

/// Internal settings
@property(nonatomic, readonly, strong) RCNConfigSettings *settings;

/// Returns the FIRRemoteConfig instance for your namespace and for the default Firebase App.
/// This singleton object contains the complete set of Remote Config parameter values available to
/// the app, including the Active Config and Default Config.. This object also caches values fetched
/// from the Remote Config Server until they are copied to the Active Config by calling
/// activateFetched. When you fetch values from the Remote Config Server using the default Firebase
/// namespace service, you should use this class method to create a shared instance of the
/// FIRRemoteConfig object to ensure that your app will function properly with the Remote Config
/// Server and the Firebase service. This API is used internally by 2P teams.
+ (FIRRemoteConfig *)remoteConfigWithFIRNamespace:(NSString *)remoteConfigNamespace
    NS_SWIFT_NAME(remoteConfig(FIRNamespace:));

/// Returns the FIRRemoteConfig instance for your namespace and for the default 3P developer's app.
/// This singleton object contains the complete set of Remote Config parameter values available to
/// the app, including the Active Config and Default Config. This object also caches values fetched
/// from the Remote Config Server until they are copied to the Active Config by calling
/// activateFetched. When you fetch values from the Remote Config Server using the default Firebase
/// namespace service, you should use this class method to create a shared instance of the
/// FIRRemoteConfig object to ensure that your app will function properly with the Remote Config
/// Server and the Firebase service.
+ (FIRRemoteConfig *)remoteConfigWithFIRNamespace:(NSString *)remoteConfigNamespace
                                              app:(FIRApp *)app
    NS_SWIFT_NAME(remoteConfig(FIRNamespace:app:));


/// Initialize a FIRRemoteConfig instance with all the required parameters directly. This exists so
/// tests can create FIRRemoteConfig objects without needing FIRApp.
- (instancetype)initWithAppName:(NSString *)appName
                     FIROptions:(FIROptions *)options
                      namespace:(NSString *)FIRNamespace
                      DBManager:(RCNConfigDBManager *)DBManager
                  configContent:(RCNConfigContent *)configContent
                      analytics:(nullable id<FIRAnalyticsInterop>)analytics;

@end

NS_ASSUME_NONNULL_END

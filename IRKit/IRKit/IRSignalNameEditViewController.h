#import <UIKit/UIKit.h>
#import "IRSignal.h"

@protocol IRSignalNameEditViewControllerDelegate;

@interface IRSignalNameEditViewController : UIViewController<UITextFieldDelegate>

@property (nonatomic, unsafe_unretained) id<IRSignalNameEditViewControllerDelegate> delegate;
@property (unsafe_unretained, nonatomic) IBOutlet UITextField *textField;
@property (nonatomic) IRSignal *signal;

@end

@protocol IRSignalNameEditViewControllerDelegate <NSObject>
@required

// Your implementation of this method should dismiss view controller.
- (void)signalNameEditViewController:(IRSignalNameEditViewController *)viewController didFinishWithInfo:(NSDictionary *)info;

@end

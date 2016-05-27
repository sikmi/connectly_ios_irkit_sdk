#import <UIKit/UIKit.h>
#import "IRPeripheral.h"

@protocol IRPeripheralNameEditViewControllerDelegate;

@interface IRPeripheralNameEditViewController : UIViewController<UITextFieldDelegate>

@property (nonatomic, unsafe_unretained) id<IRPeripheralNameEditViewControllerDelegate> delegate;
@property (nonatomic) IRPeripheral *peripheral;
@property (unsafe_unretained, nonatomic) IBOutlet UITextField *textField;
@property (unsafe_unretained, nonatomic) IBOutlet UIImageView *iconView;

@end

@protocol IRPeripheralNameEditViewControllerDelegate <NSObject>
@required

// Your implementation of this method should dismiss view controller.
- (void)nameEditViewController:(IRPeripheralNameEditViewController *)viewController didFinishWithInfo:(NSDictionary *)info;

@end

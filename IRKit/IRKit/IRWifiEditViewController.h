#import <UIKit/UIKit.h>
#import "IRWifiSecuritySelectViewController.h"

@protocol IRWifiEditViewControllerDelegate;

@interface IRWifiEditViewController : UIViewController<UITextFieldDelegate, UITableViewDataSource, UITableViewDelegate, IRWifiSecuritySelectViewControllerDelegate>

@property (nonatomic, unsafe_unretained) id<IRWifiEditViewControllerDelegate> delegate;
@property (unsafe_unretained, nonatomic) IBOutlet UITableView *tableView;
@property (unsafe_unretained, nonatomic) IBOutlet UIImageView *iconView;

@property (nonatomic) IRKeys *keys;

@end

@protocol IRWifiEditViewControllerDelegate <NSObject>
@required

// Your implementation of this method should dismiss view controller.
- (void)wifiEditViewController:(IRWifiEditViewController *)viewController didFinishWithInfo:(NSDictionary *)info;

@end

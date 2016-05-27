#import <UIKit/UIKit.h>
#import "IRKeys.h"

@protocol IRWifiSecuritySelectViewControllerDelegate;

@interface IRWifiSecuritySelectViewController : UIViewController<UITableViewDataSource, UITableViewDelegate>

@property (nonatomic, unsafe_unretained) id<IRWifiSecuritySelectViewControllerDelegate> delegate;
@property (unsafe_unretained, nonatomic) IBOutlet UITableView *tableView;
@property (nonatomic, assign) enum IRSecurityType selectedSecurityType;

@end

@protocol IRWifiSecuritySelectViewControllerDelegate <NSObject>
@required

- (void)securitySelectviewController:(IRWifiSecuritySelectViewController *)viewController didFinishWithSecurityType:(enum IRSecurityType)securityType;

@end

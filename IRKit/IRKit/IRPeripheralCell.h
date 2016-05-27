#import <UIKit/UIKit.h>
#import "IRPeripheral.h"

@interface IRPeripheralCell : UITableViewCell

+ (CGFloat)height;

@property (nonatomic, strong) IRPeripheral *peripheral;

@property (unsafe_unretained, nonatomic) IBOutlet UILabel *nameLabel;
@property (unsafe_unretained, nonatomic) IBOutlet UILabel *detailLabel;
@property (unsafe_unretained, nonatomic) IBOutlet UIImageView *iconView;

@end

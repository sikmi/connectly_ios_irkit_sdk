#import "Log.h"
#import "IRGuidePowerViewController.h"
#import "IRConst.h"
#import "IRViewCustomizer.h"
#import "IRKit.h"
#import "IRWifiEditViewController.h"
#import "IRHelper.h"

@interface IRGuidePowerViewController ()
- (void)hideAmazonLink;
@end

@implementation IRGuidePowerViewController

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil {
    LOG_CURRENT_METHOD;
    self = [super initWithNibName: nibNameOrNil bundle: nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad {
    LOG_CURRENT_METHOD;
    [super viewDidLoad];

    self.title                            = @"セットアップ";

    self.navigationItem.leftBarButtonItem = [[UIBarButtonItem alloc] initWithTitle: @"閉じる"
                                                                              style: UIBarButtonItemStylePlain
                                                                             target: self
                                                                             action: @selector(cancelButtonPressed:)];

    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithTitle: @"次へ"
                                                                              style: UIBarButtonItemStyleDone
                                                                             target: self
                                                                             action: @selector(doneButtonPressed:)];

    [self hideAmazonLink];

 [IRViewCustomizer sharedInstance].viewDidLoad(self);
#ifndef TARGET_IS_EXTENSION
    [[UIApplication sharedApplication] setStatusBarStyle: UIStatusBarStyleLightContent animated: YES];
#endif
}

- (void)viewWillAppear:(BOOL)animated {
    LOG_CURRENT_METHOD;
    [super viewWillAppear: animated];
}

- (void)viewDidAppear:(BOOL)animated {
    LOG_CURRENT_METHOD;
    [super viewDidAppear: animated];
}

- (void)viewWillDisappear:(BOOL)animated {
    LOG_CURRENT_METHOD;
    [super viewWillDisappear: animated];
}

- (void)didReceiveMemoryWarning {
    LOG_CURRENT_METHOD;
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - UI events

- (void)cancelButtonPressed:(id)sender {
    LOG_CURRENT_METHOD;
    [self.delegate scene1ViewController: self
                      didFinishWithInfo: @{
         IRViewControllerResultType: IRViewControllerResultTypeCancelled
     }];
}

- (void)doneButtonPressed:(id)sender {
    LOG_CURRENT_METHOD;
    [self.delegate scene1ViewController: self
                      didFinishWithInfo: @{
         IRViewControllerResultType: IRViewControllerResultTypeDone
     }];
}

- (IBAction)buyButtonPressed:(id)sender {
    LOG_CURRENT_METHOD;
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunused-variable"
    NSString *url = [NSString stringWithFormat: @"%@/store", APIENDPOINT_BASE];
#ifndef TARGET_IS_EXTENSION
    [[UIApplication sharedApplication] openURL: [NSURL URLWithString: url]];
#endif
#pragma clang diagnostic pop
}

- (void)hideAmazonLink {
    UIView *parent = self.view.subviews[3];
    if ([parent isMemberOfClass:[UIView class]]) {
        UIView * child = parent.subviews[1];
        if ([child isMemberOfClass:[UIButton class]]) {
            [child setHidden:YES];
        }
        child = parent.subviews[2];
        if ([child isMemberOfClass:[UIImageView class]]) {
            [child setHidden:YES];
        }
    }
}

@end

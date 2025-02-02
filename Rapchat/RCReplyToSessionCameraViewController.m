//
//  RCReplyToSessionCameraViewController.m
//  Rapchat
//
//  Created by Michael Paris on 12/18/13.
//  Copyright (c) 2013 Michael Paris. All rights reserved.
//

#import "RCReplyToSessionCameraViewController.h"
#import "RCPreviewFileViewController.h"

@interface RCReplyToSessionCameraViewController ()

@end

@implementation RCReplyToSessionCameraViewController

- (BOOL)prefersStatusBarHidden
{
    return YES;
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view.
    
    UIBarButtonItem *rotateButton = [[UIBarButtonItem alloc] initWithImage:[UIImage imageNamed:@"spinner_white"] style:UIBarButtonItemStylePlain target:self action:@selector(changeCamera:)];
    self.navigationItem.rightBarButtonItem = rotateButton;
    
    [self setTitleButton];
}

- (void)setTitleButton
{
    UIButton * button = [[UIButton alloc]initWithFrame:CGRectZero];
    [button addTarget:self action:@selector(changeBeatsButtonClicked) forControlEvents:UIControlEventTouchUpInside];
    [button setImage:[UIImage imageNamed:@"music_white"] forState:UIControlStateNormal];
    [button sizeToFit];
    self.navigationItem.titleView = button;
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    // Hide the navigation bar
}

- (void)viewWillDisappear:(BOOL)animated
{
//    self.navigationController.navigationBar.translucent = NO;
    [super viewWillDisappear:animated];
}

#pragma mark Segues

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if([segue.identifier isEqualToString:@"PreviewVideoSegue"]) {
        if ([segue.destinationViewController isKindOfClass:[RCPreviewFileViewController class]]) {
            RCPreviewFileViewController *controller = segue.destinationViewController;
            controller.sessionId = self.sessionId;
            controller.videoURL = [self getVideoUrl];
            controller.thumbnailImageUrl = self.thumbnailImageUrl;
            controller.isBattle = self.isBattle;
            NSLog(@"Prepared PreviewVideoSegue with url: %@", controller.videoURL);
        }
    }
}

#pragma mark Actions
- (IBAction)changeBeatsButtonClicked {
    [self changeSong];
}
@end

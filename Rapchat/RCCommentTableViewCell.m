//
//  RCCommentTableViewCell.m
//  Rapchat
//
//  Created by Michael Paris on 12/17/13.
//  Copyright (c) 2013 Michael Paris. All rights reserved.
//

#import "RCCommentTableViewCell.h"

@interface RCCommentTableViewCell()

@property RCComment *comment;

@end

@implementation RCCommentTableViewCell

- (id)initWithStyle:(UITableViewCellStyle)style reuseIdentifier:(NSString *)reuseIdentifier
{
    self = [super initWithStyle:style reuseIdentifier:reuseIdentifier];
    if (self) {
        // Initialization code
    }
    return self;
}

- (void)setSelected:(BOOL)selected animated:(BOOL)animated
{
    [super setSelected:selected animated:animated];

    // Configure the view for the selected state
}

- (void)setCellComment:(RCComment *)comment
{
    self.comment = comment;
    self.commentTextView.contentInset = UIEdgeInsetsMake(-4,-5,0,0);
    self.usernameLabel.text = comment.commenter;
    self.commentTextView.text = comment.text;
    // Set Date
    NSDateFormatter *dateFormatter = [NSDateFormatter new];
    NSArray *months = @[@"", @"Jan", @"Feb", @"March", @"Apr", @"May", @"June", @"July", @"Aug", @"Sep",  @"Oct", @"Nov", @"Dec"];
    [dateFormatter setDateFormat:@"MM/dd"];
    NSArray *dateArray = [[dateFormatter stringFromDate:self.comment.created] componentsSeparatedByString:@"/"];
    self.dateLabel.text = [NSString stringWithFormat:@"%@ %@", [months objectAtIndex:[dateArray[0] intValue]], dateArray[1]];
}

@end

//
//  PKPaymentField.h
//  PKPayment Example
//
//  Created by Alex MacCaw on 1/22/13.
//  Copyright (c) 2013 Stripe. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PKCard.h"
#import "PKCardNumber.h"
#import "PKCardExpiry.h"
#import "PKCardCVC.h"
#import "PKAddressZip.h"
#import "PKUSAddressZip.h"

@class PKView, PKTextField;

typedef NS_ENUM(NSInteger, PKViewFieldType) {
    PKViewCardNumberField,
    PKViewExpiryDateField,
    PKViewCVCField,
};

@protocol PKViewDelegate <NSObject>
@optional
- (void)paymentView:(PKView *)paymentView withCard:(PKCard *)card isValid:(BOOL)valid;
- (void)paymentFieldDidBecomeActive:(PKTextField *)paymentField;
@end

@interface PKView : UIView

- (BOOL)isValid;

@property (nonatomic, readonly) UIView *opaqueOverGradientView;
@property (nonatomic, readonly) PKCardNumber *cardNumber;
@property (nonatomic, readonly) PKCardExpiry *cardExpiry;
@property (nonatomic, readonly) PKCardCVC *cardCVC;
@property (nonatomic, readonly) PKAddressZip *addressZip;

@property IBOutlet UIView *innerView;
@property IBOutlet UIView *clipView;
@property IBOutlet PKTextField *cardNumberField;
@property IBOutlet PKTextField *cardExpiryField;
@property IBOutlet PKTextField *cardCVCField;
@property IBOutlet UIImageView *placeholderView;

@property (nonatomic, weak) id <PKViewDelegate> delegate;
@property (readonly) PKCard *card;
@property (nonatomic, strong) UIFont *font;
@property (nonatomic, strong) UIColor *textColor;
@property (nonatomic, assign) UIKeyboardAppearance keyboardAppearance;

#ifndef RELEASE
@property (nonatomic, copy) NSSet *allowedCardNumbers;
#endif

@end

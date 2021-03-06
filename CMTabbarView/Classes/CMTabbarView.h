//
//  CMTabbarView.h
//  CMTabbarView
//
//  Created by Moyun on 2016/11/6.
//  Copyright © 2016年 Cmall. All rights reserved.
//

#import <UIKit/UIKit.h>

@class CMTabbarView;

typedef NS_ENUM(NSInteger,CMTabbarSelectionType) {
    CMTabbarSelectionIndicator,
    CMTabbarSelectionBox,
};

typedef NS_ENUM(NSInteger, CMTabbarIndicatorType) {
    CMTabbarIndicatorLocationDown,
    CMTabbarIndicatorLocationUp,
    CMTabbarIndicatorLocationNone
};

extern NSString *const CMTabIndicatorViewHeight;

extern NSString *const CMTabIndicatorColor;

extern NSString *const CMTabBoxBackgroundColor;

@protocol CMTabbarViewDatasouce <NSObject>

- (NSArray<NSString *> *)tabbarTitlesForTabbarView:(CMTabbarView *)tabbarView;

@end

@protocol CMTabbarViewDelegate <NSObject>

@optional
- (void)tabbarView:(CMTabbarView *)tabbarView didSelectedAtIndex:(NSInteger)index;

@end

@interface CMTabbarView : UIView

@property (weak,   nonatomic) id <CMTabbarViewDatasouce> dataSource;

@property (weak,   nonatomic) id <CMTabbarViewDelegate> delegate;
/**
 Whether the user need color Gradient,Default is true
 */
@property (assign, nonatomic) BOOL needGradient;
/**
 Specifies the type of selection
 Default is CMTabbarSelectionIndicator
 */
@property (assign, nonatomic) CMTabbarSelectionType selectionType;
/**
 Specifies the type of indication
 Default is CMTabbarIndicatorLocationDown
 */
@property (assign, nonatomic) CMTabbarIndicatorType locationType;
/**
 The attributes for the tab indicator(CMTabIndicatorViewHeight,CMTabIndicatorColor,CMTabBoxBackgroundColor)
 */
@property (strong, nonatomic) NSDictionary *indicatorAttributes;
/**
 The attributes for tabs (NSForegroundColorAttributeName, NSFontAttributeName, NSBackgroundColorAttributeName)
 */
@property (strong, nonatomic) NSDictionary *normalAttributes;
/**
 The attributes for selected tabs (NSForegroundColorAttributeName, NSFontAttributeName, NSBackgroundColorAttributeName)
 */
@property (strong, nonatomic) NSDictionary *selectedAttributes;
/**
 Whether the user can scroll the tabbar
 */
@property (assign, nonatomic) BOOL scrollEnable;
/**
 padding Value,Default is 5.0
 */
@property (assign, nonatomic) CGFloat tabPadding;
/**
 User default index
 */
@property (assign, nonatomic) NSUInteger defaultSelectedIndex;

@property (assign, nonatomic) CGFloat tabbarOffsetX;
/**
 Set the current selected tab

 @param index index
 @param animated animated
 */
- (void)setTabIndex:(NSInteger)index animated:(BOOL)animated;

@end

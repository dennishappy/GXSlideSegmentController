//
//  PTSlideSegmentController.h
//  SPTestDemo
//
//  Created by  GuoShengyong on 16/3/31.
//  Copyright © 2016年  GuoShengyong. All rights reserved.
//

#import <UIKit/UIKit.h>

@class GXSlideSegmentController;
/**
 *  Need to be implemented this methods for custom UI of segment button
 */
@protocol GXSlideSegmentDataSource <NSObject>
@required

- (NSInteger)slideSegment:(UICollectionView *)segmentBar
   numberOfItemsInSection:(NSInteger)section;

- (UICollectionViewCell *)slideSegment:(UICollectionView *)segmentBar
                cellForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional
- (NSInteger)numberOfSectionsInslideSegment:(UICollectionView *)segmentBar;

@end

@protocol GXSlideSegmentDelegate <NSObject>
@optional
- (void)slideSegment:(UICollectionView *)segmentBar didSelectedViewController:(UIViewController *)viewController;

- (BOOL)slideSegment:(UICollectionView *)segmentBar shouldSelectViewController:(UIViewController *)viewController;
@end

@interface GXSlideSegmentController : UIViewController

/**
 *  分段选择
 */
@property (nonatomic, strong, readonly) UICollectionView *segmentBar;

/**
 *  滑动视图容器
 */
@property (nonatomic, strong, readonly) UIScrollView *slideView;

/**
 *  指示器
 */
@property (nonatomic, strong, readonly) UIView *indicator;

/**
 *  当前选择的index
 */
@property (nonatomic, assign, readonly) NSInteger selectedIndex;

/**
 *  当前选择的viewController
 */
@property (nonatomic, weak,   readonly) UIViewController *selectedViewController;


/**
 *  Child viewControllers of SlideSegmentController
 */
@property (nonatomic,   copy) NSArray *viewControllers;

/**
 *  指示器UIEdgeInsets
 */
@property (nonatomic, assign) UIEdgeInsets indicatorInsets;

/**
 *  By default segmentBar use viewController's title for segment's button title
 *  You should implement JYSlideSegmentDataSource & JYSlideSegmentDelegate instead of segmentBar delegate & datasource
 */
@property (nonatomic, weak) id <GXSlideSegmentDelegate> delegate;
@property (nonatomic, weak) id <GXSlideSegmentDataSource> dataSource;

- (instancetype)initWithViewControllers:(NSArray *)viewControllers;

- (void)scrollToViewWithIndex:(NSInteger)index animated:(BOOL)animated;

@end

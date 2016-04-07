
#GXSlideSegmentController
仿网易新闻侧滑视图

使用方法：

    NSMutableArray *vcs = [NSMutableArray array];
    for (int i = 0; i < 10; i++) {
        UIViewController *vc = [[UIViewController alloc] init];
        vc.title = [NSString stringWithFormat:@"%d", i];
        vc.view.backgroundColor = [UIColor colorWithRed:((255.0 * (i%2)) / 255) green:((255.0 * ((i+1)%2)) / 255) blue:((255.0 * ((i+2)%2)) / 255) alpha:1];
        [vcs addObject:vc];
    }
    GXSlideSegmentController *slideSegmentController = [[GXSlideSegmentController alloc] initWithViewControllers:vcs];
    slideSegmentController.title = @"GXSlideSegmentController";
    slideSegmentController.indicatorInsets = UIEdgeInsetsMake(0, 8, 0, 8);
    slideSegmentController.indicator.backgroundColor = [UIColor redColor];
    slideSegmentController.indicator.layer.cornerRadius = slideSegmentController.indicator.frame.size.height/2;
    [self.navigationController pushViewController:slideSegmentController animated:YES];
    
#cocoapods
    pod 'GXSlideSegmentControllrt'

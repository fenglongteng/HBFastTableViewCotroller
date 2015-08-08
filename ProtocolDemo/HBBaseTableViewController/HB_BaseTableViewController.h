//
//  BaseTableViewController.h
//  PetAirbnb
//
//  Created by nonato on 14-11-25.
//  Copyright (c) 2014年 Nonato. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HB_BaseTableViewCell.h" 
#import "HB_BaseViewController.h"
//#import "ToolsFunc.h"

static NSString * notify_basetableview_tap = @"basetableview_tap";
static NSString * notify_basetableview_sender = @"BaseViewController";
#define TAG_TABLEVIEW 1521

//注册cell
#define TABLEVIEW_REGISTERXIBCELL_CLASS(TABLEVIEW,CELLCLSSTR) {[TABLEVIEW registerClass:NSClassFromString(CELLCLSSTR) forCellReuseIdentifier:CELLCLSSTR];\
[TABLEVIEW registerNib:[UINib nibWithNibName:CELLCLSSTR bundle:nil] forCellReuseIdentifier:CELLCLSSTR];}

@interface HB_BaseTableViewController : HB_BaseViewController<UITableViewDataSource,UITableViewDelegate>
@property(nonatomic,strong) NSMutableDictionary * dataDictionary;

//上下拉要用到的

@property (nonatomic, assign) BOOL                       noFooterView;
@property (nonatomic, assign) BOOL                       noHeaderFreshView;
@property (nonatomic, strong) UITableView               * tableView;
//不自动配置tableview
@property (nonatomic, assign) BOOL                       noAutoConfigTableView;

//不自动变回未选状态
@property (nonatomic, assign) BOOL                       nodeselectRow;
-(void)removeFooterView;
-(void)finishReloadingData;
-(void)setFooterView;
-(void)startHeaderLoading;

//调用上下拉需要的
-(void)refreshView;
-(void)getNextPageView;
-(void)FinishedLoadData;
-(void)viewDidCurrentView;

-(CGRect)adjustContentOffSet:(CGFloat)top bottom:(CGFloat)bottom;
 
-(void)observeTapgesture;

//配置tableview 一般情况下自动配置 配合 noautoconfigtableview 使用
-(void)configTableView;
/**
 * 配置顶部navigationbar 和 tableview的位置
 */
-(void)TableViewDefaultConfigWithTitle:(NSString *)title;

/**
 * 使用默认配置 供子类调用
 */
-(void)userDefaultConfigWithTitle:(NSString *)title;

/**
 * 根据keyindexpath 刷新该cell
 */
-(void)reloadTableViewCellWithKeyindexpath:(NSString *)keyindexpath;

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section;
- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath;
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath;

@end

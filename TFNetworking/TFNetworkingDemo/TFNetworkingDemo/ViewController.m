//
//  ViewController.m
//  TFNetworkingDemo
//
//  Created by dabay on 2017/3/17.
//  Copyright © 2017年 dabay. All rights reserved.
//

#import "ViewController.h"
#import <TFNetworking.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [TFNetWorkingManager sharedUtil];
    
    // Do any additional setup after loading the view, typically from a nib.
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end

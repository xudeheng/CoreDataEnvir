//
//  NSManagedObject_Background.m
//  CoreDataEnvirSample
//
//  Created by NicholasXu on 15/8/30.
//  Copyright (c) 2015年 Nicholas.Xu. All rights reserved.
//

#import "NSManagedObject_Background.h"
#import "CoreDataEnvir_Background.h"
#import "CoreDataEnvir_Private.h"
#import "NSManagedObject_Convenient.h"

@implementation NSManagedObject (CDEBackground)

/**
 *  Insert an item.
 */
+ (instancetype)insertItemOnBackground
{
    CoreDataEnvir *db = [CoreDataEnvir backgroundInstance];
	id item = nil;
	item = [self insertItemInContext:db];
    return item;
}

/**
 *  Insert an item by block
 *
 *  @param fillingBlock Fill data with this block
 *
 *  @return NSManagedObject 
 */
+ (instancetype)insertItemOnBackgroundWithFillingBlock:(void (^)(id item))fillingBlock
{
	CoreDataEnvir* db = [CoreDataEnvir backgroundInstance];
	[db asyncWithBlock:^(CoreDataEnvir * _Nonnull db) {
		[self insertItemInContext:db fillData:fillingBlock];
		[db saveDataBase];
	}];
    return nil;
}

+ (NSArray *)itemsOnBackground
{
    CoreDataEnvir *db = [CoreDataEnvir backgroundInstance];
    NSArray *items = [db fetchItemsByEntityDescriptionName:NSStringFromClass(self)];
    
    return items;
}

+ (NSArray *)itemsOnBackgroundWithPredicate:(NSPredicate *)predicate
{
    CoreDataEnvir *db = [CoreDataEnvir backgroundInstance];
    NSArray *items = [db fetchItemsByEntityDescriptionName:NSStringFromClass(self) usingPredicate:predicate];
    return items;
}

+ (NSArray *)itemsOnBackgroundWithFormat:(NSString *)fmt, ...
{
    va_list args;
    va_start(args, fmt);
    NSPredicate *pred = [NSPredicate predicateWithFormat:fmt arguments:args];
    va_end(args);
    CoreDataEnvir *db = [CoreDataEnvir backgroundInstance];
    NSArray *items = [db fetchItemsByEntityDescriptionName:NSStringFromClass(self) usingPredicate:pred];
    return items;
}

+ (NSArray *)itemsOnBackgroundSortDescriptions:(NSArray *)sortDescriptions withFormat:(NSString *)fmt, ...
{
    va_list args;
    va_start(args, fmt);
    NSPredicate *pred = [NSPredicate predicateWithFormat:fmt arguments:args];
    va_end(args);
    CoreDataEnvir *db = [CoreDataEnvir backgroundInstance];
    NSArray *items = [db fetchItemsByEntityDescriptionName:NSStringFromClass(self) usingPredicate:pred usingSortDescriptions:sortDescriptions];
    return items;
}

+ (NSArray *)itemsOnBackgroundSortDescriptions:(NSArray *)sortDescriptions fromOffset:(NSUInteger)offset limitedBy:(NSUInteger)limitNumber withFormat:(NSString *)fmt, ...
{
    va_list args;
    va_start(args, fmt);
    NSPredicate *pred = [NSPredicate predicateWithFormat:fmt arguments:args];
    va_end(args);
    CoreDataEnvir *db = [CoreDataEnvir backgroundInstance];
    NSArray *items = [db fetchItemsByEntityDescriptionName:NSStringFromClass(self) usingPredicate:pred usingSortDescriptions:sortDescriptions fromOffset:offset LimitedBy:limitNumber];
    return items;
}

+ (instancetype)lastItemOnBackground
{
    return [[self itemsOnBackground] lastObject];
}

+ (instancetype)lastItemOnBackgroundWithPredicate:(NSPredicate *)predicate
{
    return [[self itemsInContext:[CoreDataEnvir backgroundInstance] usingPredicate:predicate] lastObject];
}

+ (instancetype)lastItemOnBackgroundWithFormat:(NSString *)fmt, ...
{
    va_list args;
    va_start(args, fmt);
    NSPredicate *pred = [NSPredicate predicateWithFormat:fmt arguments:args];
    va_end(args);
    return [self lastItemOnBackgroundWithPredicate:pred];
}

@end

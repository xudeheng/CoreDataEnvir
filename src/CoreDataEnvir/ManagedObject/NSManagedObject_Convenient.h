//
//  NSManagedObject_Convient.h
//  CoreDataEnvirSample
//
//  Created by NicholasXu on 15/8/30.
//  Copyright (c) 2015年 Nicholas.Xu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreDataEnvir/CoreDataEnvir.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSManagedObject (CDEConevient)

+ (NSUInteger)totalCountInContext:(CoreDataEnvir*)db forConfiguration:(NSString* _Nullable)name;

#pragma mark - Inserting operations.

+ (NSFetchRequest*)newFetchRequestInContext:(CoreDataEnvir*)db;

/**
 Creating managed object on background thread.
 */
+ (instancetype)insertItemInContext:(CoreDataEnvir *)cde;

/**
 Createing managed object in specified context with filling 'block'
 */
+ (instancetype)insertItemInContext:(CoreDataEnvir *)cde fillData:(void (^)(NSManagedObject* item))fillingBlock;

#pragma mark - Fetching operations.

/**
 Fetching record items in specified context.
 */
+ (NSArray *)itemsInContext:(CoreDataEnvir *)cde;

/**
 Fetch record items by predicate.
 */
+ (NSArray *)itemsInContext:(CoreDataEnvir *)cde usingPredicate:(NSPredicate *)predicate;

/**
 Fetch record items by format string.
 */
+ (NSArray *)itemsInContext:(CoreDataEnvir *)cde withFormat:(NSString *)fmt,...;

/**
 *  Fetch items by sort descriptions.
 *
 *  @param cde              CoreDataEnvir instance.
 *  @param sortDescriptions SortDescriptions
 *  @param fmt              Predicate format.
 *
 *  @return Array of items match the condition.
 */
+ (NSArray *)itemsInContext:(CoreDataEnvir *)cde sortDescriptions:(NSArray *)sortDescriptions withFormat:(NSString *)fmt,...;

/**
 *  Fetch items addition by limited range.
 *
 *  @param cde              CoreDataEnvir instance
 *  @param sortDescriptions SortDescriptions
 *  @param offset           offset
 *  @param limitNumber       limted number
 *  @param fmt              Predicate format.
 *
 *  @return Array of items match the condition.
 */
+ (NSArray *)itemsInContext:(CoreDataEnvir *)cde sortDescriptions:(NSArray *)sortDescriptions fromOffset:(NSUInteger)offset limitedBy:(NSUInteger)limitNumber withFormat:(NSString *)fmt,...;

/**
 *  Fetch item in specified context.
 *
 *  @param cde CoreDataEnvir instance
 *
 *  @return Last item of the managed object in context.
 */
+ (instancetype)lastItemInContext:(CoreDataEnvir *)cde;

/**
 *  Fetch item in specified context through predicate.
 *
 *  @param cde       CoreDataEnvir instance
 *  @param predicate Predicate.
 *
 *  @return Last item of the managed object in context.
 */
+ (instancetype)lastItemInContext:(CoreDataEnvir *)cde usingPredicate:(NSPredicate *)predicate;

/**
 *  Fetch item in specified context through format string.
 *
 *  @param cde CoreDataEnvir object.
 *  @param fmt Predicate format string.
 *
 *  @return Last item of the managed object in context.
 */
+ (instancetype)lastItemInContext:(CoreDataEnvir *)cde withFormat:(NSString *)fmt,...;

#pragma mark - fault process.

/**
 *  Update NSManagedObject if faulted.
 *
 *  @return Updated object.
 */
- (instancetype)update;

/**
 Update NSManagedObject in specified context if faulted.
 
 @param cde     CoreDataEnvir object.
 */
- (instancetype)updateInContext:(CoreDataEnvir *)cde;

#pragma mark - Deleting .

/**
 *  Remove item.
 *
 *  @param cde CoreDataEnvir object.
 */
- (void)removeFrom:(CoreDataEnvir *)cde;

/**
 *  Remove item.
 */
- (void)remove;

#pragma mark - Drive to save.

/**
 *  Save db on main thread.
 *
 *  @param cde CoreDataEnvir object.
 *
 *  @return Success(YES) or failed(NO).
 */
- (BOOL)saveTo:(CoreDataEnvir *)cde;

/**
 Save db on main thread.
 */
- (BOOL)save;

/**
 *  Save db on main thread.
 *
 *  @param cde CoreDataEnvir object.
 *
 *  @return Success(YES) or failed(NO).
 */
- (BOOL)saveTo:(CoreDataEnvir *)cde forConfiguration:(NSString*)name;

@end

NS_ASSUME_NONNULL_END

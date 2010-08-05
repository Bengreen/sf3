// Copyright (c) 2008-2010 Simon Fell
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE.
//

#import <Cocoa/Cocoa.h>

@class ZKSObject;

// tracks data about changes we're planning to make to salesforce.com
@interface SalesforceObjectChangeSummary : NSObject {
	NSString		*entityName;
	NSMutableArray	*creates;
	NSMutableArray	*updates;
	NSMutableArray	*deletes;
}

-(void)willCreate:(ZKSObject *)o;
-(void)willUpdate:(ZKSObject *)o;
-(void)willDelete:(NSString *)sfId;

-(NSNumber *)adds;
-(NSNumber *)deletes;
-(NSNumber *)updates;

-(NSArray *)createDetails;
-(NSArray *)updateDetails;
-(NSArray *)deleteDetails;

-(int)totalChanges;
-(NSString *)entityName;

@end

// summary data about the set of entities we're planning to change in salesforce.com
@interface SalesforceChangeSummary : NSObject <NSTableViewDataSource> {
	NSMutableDictionary *changes;
	NSArray				*keyIndex;
}

-(SalesforceObjectChangeSummary *)changesForEntity:(NSString *)entityName;

-(int)totalChanges;
-(void)removeEntitiesWithNoChanges;
-(NSArray *)changes;
-(void)dump;
@end
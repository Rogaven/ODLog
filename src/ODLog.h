// ODLog.h
//
// Copyright (c) 2009-2015 Alexey Nazaroff, AJR
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import <Foundation/Foundation.h>

/** Logs & Asserts */
#if DEBUG == 1
    #define __SHORTEN_FILE__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : \
                              strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)

    #define ODLogWithPrefix(prefix, fmt, ...) \
    NSLog((prefix @"[%s:%d] %s \n" fmt), __SHORTEN_FILE__, __LINE__, __FUNCTION__, ##__VA_ARGS__); printf("\n")

    #define ODLog(fmt, ...)  ODLogWithPrefix(@"", fmt, ##__VA_ARGS__)
    #define ODWarn(fmt, ...) ODLogWithPrefix(@"(Warn)", fmt, ##__VA_ARGS__)
    #define ODFail(fmt, ...) ODLogWithPrefix(@"(Fail)", fmt, ##__VA_ARGS__)
#else
    #define ODLog
    #define ODWarn
    #define ODFail
#endif
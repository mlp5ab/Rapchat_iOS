//
//  EZAudioPlotGLKViewController.h
//  EZAudio
//
//  Created by Syed Haris Ali on 11/22/13.
//  Copyright (c) 2013 Syed Haris Ali. All rights reserved.
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#import "TargetConditionals.h"

#if TARGET_OS_IPHONE

#import "EZAudioPlotGL.h"

@class EZAudio;

/**
 EZAudioPlotGLKViewController is a subclass of the GLKViewController and handles the OpenGL drawing routine for iOS OpenGL ES views. This class has not been used outside the scope of the EZAudioPlotGL, but should be safe to use by itself if the intended use case is to have a view controller take up the whole screen.
 */
@interface EZAudioPlotGLKViewController : GLKViewController

#pragma mark - Properties
///-----------------------------------------------------------
/// @name Customizing The Plot's Appearance
///-----------------------------------------------------------
/**
 The default background color of the plot. For iOS the color is specified as a UIColor while for OSX the color is an NSColor. The default value on both platforms is black.
 */
@property (nonatomic,strong) UIColor *backgroundColor;

/**
 The default shader to use to fill the graph.
 */
@property (nonatomic,strong) GLKBaseEffect *baseEffect;

/**
 The default color of the plot's data (i.e. waveform, y-axis values). For iOS the color is specified as a UIColor while for OSX the color is an NSColor. The default value on both platforms is red.
 */
@property (nonatomic,strong) UIColor *color;

/**
 The OpenGL ES context (EAGLContext) in which to perform the drawing
 */
@property (nonatomic,strong) EAGLContext *context;

/**
 The EZAudioPlotGLDrawType specifying which OpenGL primitive to use for drawing (either line strip for stroke and no fill or triangle strip for fill)
 */
@property (nonatomic,assign) EZAudioPlotGLDrawType drawingType;

/**
 The plot's gain value, which controls the scale of the y-axis values. The default value of the gain is 1.0f and should always be greater than 0.0f.
 */
@property (nonatomic,assign,setter=setGain:) float gain;

/**
 The type of plot as specified by the `EZPlotType` enumeration (i.e. a buffer or rolling plot type).
 */
@property (nonatomic,assign,setter=setPlotType:) EZPlotType plotType;

/**
 A boolean indicating whether the graph should be rotated along the x-axis to give a mirrored reflection. This is typical for audio plots to produce the classic waveform look. A value of YES will produce a mirrored reflection of the y-values about the x-axis, while a value of NO will only plot the y-values.
 */
@property (nonatomic,assign,setter=setShouldMirror:) BOOL shouldMirror;

#pragma mark - Adjust Resolution
///-----------------------------------------------------------
/// @name Adjusting The Resolution
///-----------------------------------------------------------

/**
 Sets the length of the rolling history display. Can grow or shrink the display up to the maximum size specified by the kEZAudioPlotMaxHistoryBufferLength macro. Will return the actual set value, which will be either the given value if smaller than the kEZAudioPlotMaxHistoryBufferLength or kEZAudioPlotMaxHistoryBufferLength if a larger value is attempted to be set.
 @param  historyLength The new length of the rolling history buffer.
 @return The new value equal to the historyLength or the kEZAudioPlotMaxHistoryBufferLength.
 */
-(int)setRollingHistoryLength:(int)historyLength;

/**
 Provides the length of the rolling history buffer
 *  @return An int representing the length of the rolling history buffer
 */
-(int)rollingHistoryLength;

#pragma mark - Clearing
///-----------------------------------------------------------
/// @name Clearing The Plot
///-----------------------------------------------------------

/**
 Clears all data from the audio plot (includes both EZPlotTypeBuffer and EZPlotTypeRolling)
 */
-(void)clear;

@property (nonatomic, strong) UIImage *waveformImage;

#pragma mark - Get Samples
///-----------------------------------------------------------
/// @name Updating The Plot
///-----------------------------------------------------------
/**
 Updates the plot with the new buffer data and tells the view to redraw itself. Caller will provide a float array with the values they expect to see on the y-axis. The plot will internally handle mapping the x-axis and y-axis to the current view port, any interpolation for fills effects, and mirroring.
 @param buffer     A float array of values to map to the y-axis.
 @param bufferSize The size of the float array that will be mapped to the y-axis.
 @warning The bufferSize is expected to be the same, constant value once initial triggered. For plots using OpenGL a vertex buffer object will be allocated with a maximum buffersize of (2 * the initial given buffer size) to account for any interpolation necessary for filling in the graph. Updates use the glBufferSubData(...) function, which will crash if the buffersize exceeds the initial maximum allocated size.
 */
-(void)updateBuffer:(float *)buffer
     withBufferSize:(UInt32)bufferSize;

@end

#elif TARGET_OS_MAC
#endif

/* ========================================================================================= */
/* FMOD CE Specific header file. Copyright (c), Firelight Technologies Pty, Ltd 1999-2004.   */
/* ========================================================================================= */

#ifndef _FMOD_CE_H_
#define _FMOD_CE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "fmod.h"

/*
[API]
[
	[DESCRIPTION]
    Returns a TRUE if a fatal open/read or seek error was returned from the file system.

	[PARAMETERS]
 
	[RETURN_VALUE]
    On a fatal disk error, TRUE is returned.
    On normal operation, FALSE is returned.

	[REMARKS]
    This would be TRUE if for example, there was damage to the disk, or the disk was ejected when FMOD was trying to read from it.

	[SEE_ALSO]
]
*/
DLL_API signed char F_API FSOUND_File_HasFatalErrorOccurred();


/*
[API]
[
	[DESCRIPTION]
    Returns a TRUE if a poweron detection has occured.

	[PARAMETERS]
 
	[RETURN_VALUE]
    Upon FMOD detecting a power-on, TRUE is returned.
    On normal operation, FALSE is returned.

	[REMARKS]
    FMOD uses 2 methods to detect power on, and both of them work on the audio output.  FMOD does not try and access windows messages or 
    use any other form of poweron detection, as generally, these don't excist on certain revisions of WindowsCE.
    ----------
    Method 1 is FMOD detects if waveout has stopped working.  This happens on MOST devices and is reliable.
    FMOD can tell if waveout isnt processing any more by checking its cursor position.  
    If waveout is idle for 400ms then it triggeres a mixer reset, and this flag is set.
    ----------
    Method 2 is less elegant, and only happens on certain PocketPC devices.  Waveout doesnt stop on these devices, and even though the sound
    really is dead, the cursor position keeps ticking, and FMOD mixes to it, but there is no sound.  This is a PocketPC bug that FMOD has to work around.
    
    This method, as a last resort, compares GetLocalTime versus QueryPerformanceCounter.  
    QueryPerformanceCounter always stops during poweroff, but GetLocalTime keeps ticking.  
    If the difference is 2 seconds, then fmod knows the result is a timeout caused by power off/on, and triggers this flag as well as doing a mixer reset.
    If the millisecond value of GetLocalTime actually worked, 2 second delay for off then on wouldnt be nescessary, but the granularity of
    this function is seconds, not ms, then 2 seconds is the smallest time period it can skip to detect the power off/on event.

	[SEE_ALSO]
]
*/
DLL_API signed char F_API FSOUND_HasPowerOnOccurred();


#ifdef __cplusplus
}
#endif

#endif

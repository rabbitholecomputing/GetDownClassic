#ifndef CVOLUMEHELPER_H#define CVOLUMEHELPER_H#include <OSUtils.h>class CVolumeHelper{public:	static bool SystemDiskIsLocked()	{		SInt16	theVRef;		SInt32	theDirID;				::FindFolder(kOnSystemDisk, kSystemFolderType,						kCreateFolder, &theVRef, &theDirID);				QHdrPtr vcbQueue = (QHdrPtr)::GetVCBQHdr();		VCBPtr vcbElem = (VCBPtr)vcbQueue->qHead;								while(vcbElem != NULL)		{			if(vcbElem->vcbVRefNum == theVRef)			{				return ((vcbElem->vcbAtrb & 0x8080) > 0);			}			vcbElem = (VCBPtr)vcbElem->qLink;		}				return false; // We should never get here.	}	static SInt16 GetLargestUnlockedVRefNum()	{		bool diskIsLocked = false;					QHdrPtr vcbQueue = (QHdrPtr)::GetVCBQHdr();		VCBPtr vcbElem = (VCBPtr)vcbQueue->qHead;		short candidateVolumeRefNum;		UInt64 biggestVolumeSize = 0;				while(vcbElem != NULL)		{			// Find the largest unlocked volume.			if((vcbElem->vcbAtrb & 0x8080) > 0)			{				// This volume is locked.				vcbElem = (VCBPtr)vcbElem->qLink; continue;			}						// Is it a fixed File Manager disk?			if(vcbElem->vcbFSID != 0)			{				// Foreign file system, ignore it.				vcbElem = (VCBPtr)vcbElem->qLink; continue;			}						UInt64 volSize = (UInt64)vcbElem->vcbAlBlkSiz * (UInt64)vcbElem->vcbNmAlBlks;			if(volSize > biggestVolumeSize)			{				candidateVolumeRefNum = vcbElem->vcbVRefNum;				biggestVolumeSize = volSize;			}						vcbElem = (VCBPtr)vcbElem->qLink;		}				return candidateVolumeRefNum;	}		};#endif
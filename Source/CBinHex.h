#ifndef CBINHEX_H#define CBINHEX_H#include <LFileStream.h>class CBinHex{	LFileStream *fileStream;		public:	CBinHex(FSSpec *fileSpec);	Boolean Decode();};#endif
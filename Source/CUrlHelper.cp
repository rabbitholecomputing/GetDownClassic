#include "CUrlHelper.h"// Format: extension[10], creator code, file typeCUrlHelper::CreatorEntry CUrlHelper::extensionDB[kExtensionsInDB] = {	{ "SIT", OSType('SITx'), OSType('SITD') },	{ "SITX", OSType('SITx'), OSType('SITX') },	{ "BIN", OSType('SITx'), OSType('BINA') },	{ "HQX", OSType('SITx'), OSType('TEXT') },	{ "MOV", OSType('TVOD'), OSType('MooV') },	{ "ZIP", OSType('ZIP '), OSType('ZIP ') },	{ "SEA", OSType('????'), OSType('APPL') },	};
#include "stdafx.h"
#include "Interceptor.h"


static const interceptorFilter filters[] =
{
	{ 
		// Message for querying VIN
		12,	{ 0x00,0x0f,0xff,0xfe,0xcb,0x40,0xb9,0xfb,0x00,0x00,0x00,0x00},	// length , {pattern}
			{ 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x00,0x00,0x00,0x00}, // {mask}
		13, { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 0,0,0 }				// message count, { message index }
	}
};

static const interceptorMsg msgs[] =
{
	// Response from CEM when querying VIN
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x8F, 0x40, 0xF9, 0xFB, 0x57, 0x00, 0x31, 0x80 }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x09, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0A, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0B, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0C, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0D, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0E, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0F, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x08, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x09, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0A, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x0B, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }},
	{12,{ 0x00, 0x80, 0x00, 0x03, 0x4F, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, }}
};

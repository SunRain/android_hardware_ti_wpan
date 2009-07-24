/*
 * TI's FM Stack
 *
 * Copyright 2001-2008 Texas Instruments, Inc. - http://www.ti.com/
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and  
 * limitations under the License.
 */
/*******************************************************************************\
*
*   FILE NAME:      mcp_hal_string.h
*
*   BRIEF:          This file defines String-related HAL utilities.
*
*   DESCRIPTION:    General
*
*   AUTHOR:         Udi Ron
*
\*******************************************************************************/

#ifndef __MCP_HAL_STRING_H
#define __MCP_HAL_STRING_H


/********************************************************************************
 *
 * Include files
 *
 *******************************************************************************/

#include "mcp_hal_types.h"
#include "mcp_hal_config.h"
#include "mcp_hal_defs.h"

/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrCmp()
 *
 * Brief: 
 *	    Compares two strings for equality.
 * 
 * Description: 
 *	    Compares two strings for equality.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *     Str1 [in] - String to compare.
 *
 *     Str2 [in] - String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
McpU8 MCP_HAL_STRING_StrCmp(const char *Str1, const char *Str2);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StriCmp()
 *
 * Brief: 
 *     Compares two strings for equality regardless of case for the ASCII
 *     characters (value 0x1-0x7F) in the string.
 *
 * Description: 
 *     Compares two strings for equality regardless of case for the ASCII
 *     characters (value 0x1-0x7F) in the string.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		Str1 [in] - String to compare.
 *
 *		Str2 [in]- String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
McpU8 MCP_HAL_STRING_StriCmp(const char *Str1, const char *Str2);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrLen()
 *
 * Brief: 
 *	    Calculate the length (number of bytes) in the 0-terminated string.
 *
 * Description: 
 *	    Calculate the length (number of bytes) in the 0-terminated string.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		Str [in]- String to count length 
 *
 * Returns:
 *     Returns length of string.(number of bytes)
 */
McpU16 MCP_HAL_STRING_StrLen(const char *Str);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrCpy()
 *
 * Brief: 
 *	    Copy a string (same as ANSI C strcpy)
 *
 * Description: 
 *	    Copy a string (same as ANSI C strcpy)
 *  
 * 	    The OS_StrCpy function copies StrSource, including the terminating null character, 
 *	    to the location specified by StrDest. No overflow checking is performed when strings 
 *	    are copied or appended. 
 *
 *	    The behavior of OS_StrCpy is undefined if the source and destination strings overlap 
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		StrDest [out]- Destination string.
 *
 *		StrSource [in]- Source string
 *
 * Returns:
 *      Returns StrDest. No return value is reserved to indicate an error.
 */
char* MCP_HAL_STRING_StrCpy(char* StrDest, const char *StrSource);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrnCpy()
 *
 * Brief: 
 *	    Copy characters of one string to another (same as ANSI C strncpy)
 *
 * Description: 
 *	    Copy characters of one string to another (same as ANSI C strncpy)
 *
 * 		The OS_StrnCpy function copies the initial Count characters of StrSource to StrDest and 
 *		returns StrDest. If Count is less than or equal to the length of StrSource, a null character 
 *		is not appended automatically to the copied string. If Count is greater than the length of 
 *		StrSource, the destination string is padded with null characters up to length Count. 
 *
 *		The behavior of OS_StrnCpy is undefined if the source and destination strings overlap.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		StrDest [out] - Destination string.
 *
 *		StrSource [in] - Source string
 *
 *		Count - Number of bytes to be copied
 *
 * Returns:
 *     Returns strDest. No return value is reserved to indicate an error.
 */
char* MCP_HAL_STRING_StrnCpy(char* StrDest, const char *StrSource, McpU32 Count);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrCat()
 *
 * Brief: 
 *		Append a string (same as ANSI C strcat)
 *
 * Description: 
 *		Append a string (same as ANSI C strcat)
 *
 * 		The OS_StrrChr function finds the last occurrence of c (converted to char) in string. 
 *		The search includes the terminating null character.
 *		The OS_StrCat function appends strSource to strDest and terminates the resulting string 
 *		with a null character. The initial character of strSource overwrites the terminating null 
 *		character of strDest. No overflow checking is performed when strings are copied or 
 *		appended. The behavior of OS_StrCat is undefined if the source and destination strings 
 *		overlap
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		strDest [in] - Null-terminated destination string.
 *
 *		strSource [in] - Null-terminated source string
 *
 * Returns:
 *		Returns the destination string (strDest). No return value is reserved to indicate an error.
 */
char *MCP_HAL_STRING_StrCat(char *strDest, const char *strSource);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrrChr()
 *
 * Brief: 
 *      Scan a string for the last occurrence of a character (same as ANSI C strrchr).
 *
 * Description:
 *      Scan a string for the last occurrence of a character (same as ANSI C strrchr).
 * 		The MCP_HAL_STRING_StrrChr function finds the last occurrence of c (converted to char) in string. 
 *		The search includes the terminating null character.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		Str [in] - tNull-terminated string to search
 *
 *      c [in] - Character to be located.
 *
 * Returns:
 *	
 *		Returns a pointer to the last occurrence of c in Str, or NULL if c is not found.
 */
char *MCP_HAL_STRING_StrrChr(const char *Str, McpS32 c);

/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrCmpUtf8()
 *
 * Brief: 
 *	    Compares two strings for equality.
 * 
 * Description: 
 *	    Compares two strings for equality.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *     Str1 [in] - String to compare.
 *
 *     Str2 [in] - String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
McpU8 MCP_HAL_STRING_StrCmpUtf8(const McpUtf8 *Str1, const McpUtf8 *Str2);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StriCmpUtf8()
 *
 * Brief: 
 *     Compares two strings for equality regardless of case.
 *
 * Description: 
 *     Compares two strings for equality regardless of case.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		Str1 [in] - String to compare.
 *
 *		Str2 [in]- String to compare.
 *
 * Returns:
 *     Zero - If strings match.
 *     Non-Zero - If strings do not match.
 */
McpS32 MCP_HAL_STRING_StriCmpUtf8(const McpUtf8 *Str1, const McpUtf8 *Str2);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrLenUtf8()
 *
 * Brief: 
 *	    Calculate the length (number of bytes) in the 0-terminated string.
 *
 * Description: 
 *	    Calculate the length (number of bytes) in the 0-terminated string.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		Str [in]- String to count length (UTF-8 format)
 *
 * Returns:
 *     Returns length of string.(number of bytes)
 */
McpU16 MCP_HAL_STRING_StrLenUtf8(const McpUtf8 *Str);

/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrnCpyUtf8()
 *
 * Brief: 
 *	    Copy characters of one string to another (same as ANSI C strncpy)
 *
 * Description: 
 *	    Copy characters of one string to another (same as ANSI C strncpy)
 *
 * 		The MCP_HAL_STRING_StrnCpyUtf8 function copies the initial Count characters of StrSource to StrDest and 
 *		returns StrDest. If Count is less than or equal to the length of StrSource, a null character 
 *		is not appended automatically to the copied string. If Count is greater than the length of 
 *		StrSource, the destination string is padded with null characters up to length Count. 
 *
 *		The behavior of OS_StrnCpy is undefined if the source and destination strings overlap.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		StrDest [out] - Destination string.
 *
 *		StrSource [in] - Source string
 *
 *		Count - Number of bytes to be copied
 *
 * Returns:
 *     Returns strDest. No return value is reserved to indicate an error.
 */
McpUtf8* MCP_HAL_STRING_StrnCpyUtf8(McpUtf8* StrDest, const McpUtf8 *StrSource, McpU32 Count);

/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrCatUtf8()
 *
 * Brief: 
 *		Append a string (same as ANSI C strcat)
 *
 * Description: 
 *		Append a string (same as ANSI C strcat)
 *
 * 		This function finds the last occurrence of c in string. 
 *		The search includes the terminating null character.
 *		This function appends strSource to strDest and terminates the resulting string 
 *		with a null character. The initial character of strSource overwrites the terminating null 
 *		character of strDest. No overflow checking is performed when strings are copied or 
 *		appended. The behavior of this function is undefined if the source and destination strings 
 *		overlap
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		strDest [in] - Null-terminated destination string.
 *
 *		strSource [in] - Null-terminated source string
 *
 * Returns:
 *		Returns the destination string (strDest). No return value is reserved to indicate an error.
 */
McpUtf8 *MCP_HAL_STRING_StrCatUtf8(McpUtf8 *strDest, const McpUtf8 *strSource);


/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrrChrUtf8()
 *
 * Brief: 
 *      Scan a string for the last occurrence of a character (same as ANSI C strrchr).
 *
 * Description:
 *      Scan a string for the last occurrence of a character (same as ANSI C strrchr).
 *
 * 		This function finds the last occurrence of c in string. 
 *		The search includes the terminating null character.
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		Str [in] - tNull-terminated string to search
 *
 *      c [in] - Character to be located.
 *
 * Returns:
 *	
 *		Returns a pointer to the last occurrence of c in Str, or NULL if c is not found.
 */
McpUtf8 *MCP_HAL_STRING_StrrChrUtf8(const McpUtf8 *Str, McpU32 c);

/*-------------------------------------------------------------------------------
 * MCP_HAL_STRING_StrCpyUtf8()
 *
 * Brief: 
 *		Copy a string (same as ANSI C strcpy)
 *
 * Description:
 * 		This function copies StrSource, including the terminating null character, 
 *		to the location specified by StrDest. No overflow checking is performed when strings 
 *		are copied or appended. 
 *
 *		The behavior of OS_StrCpy is undefined if the source and destination strings overlap 
 *
 * Type:
 *		Synchronous
 *
 * Parameters:
 *		StrDest [out]- Destination string.
 *
 *		StrSource [in]- Source string
 *
 * Returns:
 *     Returns StrDest. No return value is reserved to indicate an error.
 */
McpUtf8* MCP_HAL_STRING_StrCpyUtf8(McpUtf8* StrDest, const McpUtf8 *StrSource);

#endif	/* __MCP_HAL_STRING_H */

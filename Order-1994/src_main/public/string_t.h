#ifndef __STRING_T__
#define __STRING_T__

#include "tools/basetypes.h"

#include <stdarg.h>

#ifndef NO_STRING_T

#ifdef WEAK_STRING_T

typedef int	string_t;

#define NULL_STRING			0

//-----------------------------------------------------------------------------
// Purpose: Given a string_t, make a C string. By convention the result string 
// 			pointer should be considered transient and should not be stored.
//-----------------------------------------------------------------------------

#define STRING( offset )	( ( offset ) ? reinterpret_cast<const char *>( offset ) : "" )

//-----------------------------------------------------------------------------
// Purpose: Given a C string, obtain a string_t
//-----------------------------------------------------------------------------

#define MAKE_STRING( str )	( ( *str != 0 ) ? reinterpret_cast<int>( str ) : 0 )

#else

struct string_t
{
public:
	bool operator!() const							{ return ( pszValue == NULL );			}
	bool operator==( const string_t &rhs ) const	{ return ( pszValue == rhs.pszValue );	}
	bool operator!=( const string_t &rhs ) const	{ return ( pszValue != rhs.pszValue );	}
	bool operator<( const string_t &rhs ) const		{ return ((void *)pszValue < (void *)rhs.pszValue ); }

	const char *ToCStr() const						{ return ( pszValue ) ? pszValue : ""; 	}
	
protected:
	const char *pszValue;
};

//-----------------------------------------------------------------------------

struct castable_string_t : public string_t // string_t is used in unions, hence, no constructor allowed
{
	castable_string_t()							{ pszValue = NULL; }
	castable_string_t( const char *pszFrom )	{ pszValue = (pszFrom && *pszFrom) ? pszFrom : 0; }
};

//-----------------------------------------------------------------------------
// Purpose: The correct way to specify the NULL string as a constant.
//-----------------------------------------------------------------------------

#define NULL_STRING			castable_string_t()

//-----------------------------------------------------------------------------
// Purpose: Given a string_t, make a C string. By convention the result string 
// 			pointer should be considered transient and should not be stored.
//-----------------------------------------------------------------------------

#define STRING( string_t_obj )	(string_t_obj).ToCStr()

//-----------------------------------------------------------------------------
// Purpose: Given a C string, obtain a string_t
//-----------------------------------------------------------------------------

#define MAKE_STRING( c_str )	castable_string_t( c_str )

#endif
#endif
#endif
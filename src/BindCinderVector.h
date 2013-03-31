#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {
        
		void bindCinderVector( lua_State* state );
	
    };

}


#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {

		void bindCinderFbo( lua_State* state );
	
    };

}


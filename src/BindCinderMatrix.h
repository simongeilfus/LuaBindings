#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {

		void bindCinderMatrix( lua_State* state );
	
    };

}


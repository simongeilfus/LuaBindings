#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {

	namespace Bindings {

		void bindCinderCamera( lua_State* state );
	
    };

}


#pragma once

extern "C" {
#include <lua/lua.h>
}

namespace lua {

	namespace Bindings {
        
		void bindCinderAppBasic( lua_State* state );

	};

}


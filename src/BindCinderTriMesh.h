#pragma once

extern "C" {
#include <lua/lua.h>
}


namespace lua {
    
	namespace Bindings {
        
		void bindCinderTriMesh( lua_State* state );
        
    };
    
}


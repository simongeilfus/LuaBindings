//
//  LuaBindings.cpp
//  LuaBindings
//
//  Created by Simon Geilfus on 31/03/13.
//  Copyright (c) 2013 Simon Geilfus. All rights reserved.
//

#include "LuaBindings.h"

#include "BindStdVector.h"

#include "BindCinderApp.h"
#include "BindCinderArea.h"
#include "BindCinderCamera.h"
#include "BindCinderChannel.h"
#include "BindCinderColor.h"
#include "BindCinderEvent.h"
#include "BindCinderFbo.h"
#include "BindCinderFont.h"
#include "BindCinderGl.h"
#include "BindCinderGlslProg.h"
#include "BindCinderMatrix.h"
#include "BindCinderMayaCamUI.h"
#include "BindCinderPerlin.h"
#include "BindCinderRand.h"
#include "BindCinderRect.h"
#include "BindCinderResources.h"
#include "BindCinderSurface.h"
#include "BindCinderText.h"
#include "BindCinderTexture.h"
#include "BindCinderTriMesh.h"
#include "BindCinderUtilities.h"
#include "BindCinderVbo.h"
#include "BindCinderVector.h"

extern "C" {
#include <lua/lua.h>
}

namespace lua { namespace Bindings {
    
	void bindCinder( lua_State* state ){
        bindCinderAppBasic( state );
        bindCinderEvents( state );
        bindCinderUtilities( state );
        bindCinderVector( state );
        bindCinderMatrix( state );
        bindCinderRect( state );
        bindCinderArea( state );
        bindCinderColor( state );
        bindCinderResources( state );
        bindCinderTexture( state );
        bindCinderChannel( state );
        bindCinderSurface( state );
        bindCinderFont( state );
        bindCinderText( state );
        bindCinderTriMesh( state );
        bindCinderRand( state );
        bindCinderPerlin( state );
        bindCinderGL( state );
        bindCinderGlslProg( state );
        bindCinderFbo( state );
        bindCinderVbo( state );
        bindCinderMayaCamUI( state );
        bindCinderCamera( state );
    }
    
	void bindStd( lua_State* state ){
        bindStdVector( state );
    }
}}
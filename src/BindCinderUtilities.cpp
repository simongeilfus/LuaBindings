#include "BindCinderUtilities.h"

#include "cinder/Utilities.h"
#include "cinder/Vector.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    void bindCinderUtilities( lua_State* state ){
        
        module( state ) [
                                   def( "expandPath", expandPath ),
                                   def( "getHomeDirectory", getHomeDirectory ),
                                   def( "getDocumentsDirectory", getDocumentsDirectory ),
                                   def( "getTemporaryDirectory", getTemporaryDirectory ),
                                   def( "getTemporaryFilePath", getTemporaryFilePath ),
                                   def( "getPathDirectory", getPathDirectory ),
                                   def( "getPathFileName", getPathFileName ),
                                   def( "getPathExtension", getPathExtension ),
                                   def( "createDirectories", createDirectories ),
                                   def( "launchWebBrowser", launchWebBrowser ),
                                   def( "deleteFile", deleteFile ),
                                   def( "split", ( std::vector<std::string> (*) (const std::string &, char, bool) ) split ),
                                   def( "toUtf16", toUtf16 ),
                                   def( "toUtf8", toUtf8 ),
                                   // TODO def( "sleep", sleep ),
                                   def( "toString", toString<float> ),
                                   def( "toString", toString<bool> ),
                                   def( "toString", toString<Vec2i> ),
                                   def( "toString", toString<Vec2f> ),
                                   def( "toString", toString<Vec3f> )
                                   ];
        
    }
    
}}

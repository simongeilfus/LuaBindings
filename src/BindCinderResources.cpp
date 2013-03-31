#include "BindCinderResources.h"

#include "cinder/app/AppBasic.h"
#include "cinder/DataSource.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
    static ci::ImageSourceRef loadImage( ci::DataSourceRef source ){ return ci::loadImage( source ); }
    static ci::DataSourceRef loadFile( std::string path ){ return cinder::loadFile( path ); }
    static ci::DataSourceRef loadAsset( std::string path ){ return cinder::app::loadAsset( path ); }
    static ci::DataSourceRef loadResource( std::string macPath, int mswID, std::string mswType ) { return ci::app::AppBasic::get()->loadResource( macPath, mswID, mswType ); }
    
    void bindCinderResources( lua_State* state ){
        
        module( state ) [
                                   
                                   def( "loadFile", ( DataSourceRef(*) (std::string) ) &loadFile ),
                                   def( "loadResource", ( DataSourceRef(*) ( std::string, int, std::string ) ) &loadResource),
                                   def( "loadAsset", ( DataSourceRef(*) ( std::string ) ) &loadAsset),
                                   
                                   class_< DataSourceRef >("DataSourceRef")
                                   .def(constructor<>()),
                                   
                                   def( "loadImage", ( ImageSourceRef(*) (ci::DataSourceRef) ) &loadImage),
                                   
                                   class_< ImageSourceRef >("ImageSourceRef")
                                   .def(constructor<>())
                                   
                                   ];
        
    }
    
}}

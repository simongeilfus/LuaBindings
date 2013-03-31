#include "BindCinderApp.h"

#include "cinder/app/AppBasic.h"

#include <luabind/luabind.hpp>

using namespace ci;
using namespace ci::app;
using namespace std;
using namespace luabind;

namespace lua { namespace Bindings {
    
    
    static int getWindowWidth(){ return ci::app::AppBasic::get()->getWindowWidth(); }
    // TODO static void setWindowWidth( float w ){ ci::app::AppBasic::get()->setWindowWidth( w ); }
    static int getWindowHeight(){ return ci::app::AppBasic::get()->getWindowHeight(); }
    // TODO static void setWindowHeight( float h ){ ci::app::AppBasic::get()->setWindowHeight( h ); }
    static void setWindowSize( float w, float h ){ ci::app::AppBasic::get()->setWindowSize( w, h ); }
    
    static ci::Vec2f getWindowCenter(){ return ci::app::AppBasic::get()->getWindowCenter(); }
    static ci::Vec2f getWindowSize(){ return ci::app::AppBasic::get()->getWindowSize(); }
    static float getWindowAspectRatio(){ return ci::app::AppBasic::get()->getWindowAspectRatio(); }
    static ci::Area getWindowBounds(){ return ci::app::AppBasic::get()->getWindowBounds(); }
    
    static float getFrameRate(){ return ci::app::AppBasic::get()->getFrameRate(); }
    static void setFrameRate( float fps ){ ci::app::AppBasic::get()->setFrameRate( fps ); }
    static float getAverageFps(){ return ci::app::AppBasic::get()->getAverageFps(); }
    static float getFpsSampleInterval(){ return ci::app::AppBasic::get()->getFpsSampleInterval(); }
    static void setFpsSampleInterval( float i ){ ci::app::AppBasic::get()->setFpsSampleInterval( i ); }
    
    static bool isFullScreen(){ return ci::app::AppBasic::get()->isFullScreen(); }
    static void setFullScreen( bool f ){ ci::app::AppBasic::get()->setFullScreen( f ); }
    
    static ci::Vec2f getMousePos(){ return ci::app::AppBasic::get()->getMousePos(); }
    static void hideCursor(){ ci::app::AppBasic::get()->hideCursor(); }
    static void showCursor(){ ci::app::AppBasic::get()->showCursor(); }
    
    static int getElapsedSeconds(){ return ci::app::AppBasic::get()->getElapsedSeconds(); }
    static int getElapsedFrames(){ return ci::app::AppBasic::get()->getElapsedFrames(); }
    
    static void quit(){ ci::app::AppBasic::get()->quit(); }
    static std::string getAppPath(){ return ci::app::AppBasic::get()->getAppPath().generic_string(); }
        
    static void begin( GLenum type ){ glBegin( type ); }
    static void end(){ glEnd(); }
	
    static void console( const std::string &s ){ ci::app::console() << s << std::endl; }
    static void console( float f ){ ci::app::console() << f << std::endl; }
    //static void console( int i ){ ci::app::console() << i << std::endl; }
    
	void bindCinderAppBasic( lua_State* state ){
        
		module( state ) [
                                   def( "getWindowWidth", &getWindowWidth ),
                                   // TODO def( "setWindowWidth", &setWindowWidth ),
                                   def( "getWindowHeight", &getWindowHeight ),
                                   // TODO def( "setWindowHeight", &setWindowHeight ),
                                   //def( "setWindowSize", &setWindowSize ),
                                   
                                   def( "getWindowCenter", &getWindowCenter ),
                                   def( "getWindowSize", &getWindowSize ),
                                   def( "getWindowAspectRatio", &getWindowAspectRatio ),
                                   def( "getWindowBounds", &getWindowBounds ),
                                   
                                   def( "getFrameRate", &getFrameRate ),
                                   def( "setFrameRate", &setFrameRate ),
                                   def( "getAverageFps", &getAverageFps ),
                                   def( "getFpsSampleInterval", &getFpsSampleInterval ),
                                   def( "setFpsSampleInterval", &setFpsSampleInterval ),
                                   
                                   def( "isFullScreen", &isFullScreen ),
                                   def( "setFullScreen", &setFullScreen ),
                                   
                                   def( "getMousePos", &getMousePos ),
                                   def( "hideCursor", &hideCursor ),
                                   def( "showCursor", &showCursor ),
                                   
                                   def( "getElapsedSeconds", &getElapsedSeconds ),
                                   def( "getElapsedFrames", &getElapsedFrames ),
                                   
                                   def( "quit", &quit ),
                                   def( "getAppPath", &getAppPath ),
                                   
                                   //! Console Wrappers
                                   def( "console", ( void(*) (const string&) ) &console ),
                                   def( "console", ( void(*) (float) ) &console )
                                   ];
	}
}}

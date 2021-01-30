#include <ida.hpp>
#include <idp.hpp>
#include <loader.hpp>
#include <kernwin.hpp>
#include "hexrays.hpp"
/*
    You can use __EA64__ to define a 64 bit portion of the binary. 
    Keep in mind that even a 32 bit binary must compile to 64 bit, it
    just has to have a definition removed "__EA64__" and that is literally it. 
    I made this to save time so that people wont have to go through this again.
    I have comented out 'access_type_t' struct in hexrays.hpp because it is duplicated in idp.hpp.

*/

//--------------------------------------------------------------------------
struct plugin_ctx_t : public plugmod_t
{
    virtual bool idaapi run(size_t) override;
};

//--------------------------------------------------------------------------
bool idaapi plugin_ctx_t::run(size_t)
{
  // here is defined 64bit
#ifdef __EA64__
    msg("Hello, world! from 64bit! (cpp)\n");
#endif

    //if 64bit is not defined.
#ifndef __EA64__
    msg("Hello, world! from 32bit! (cpp)\n");

#endif
    return true;
}

//--------------------------------------------------------------------------
static plugmod_t* idaapi init()
{
    return new plugin_ctx_t;
}

//--------------------------------------------------------------------------

plugin_t PLUGIN =
{
  IDP_INTERFACE_VERSION,
  PLUGIN_UNL            // Unload the plugin immediately after calling 'run'
  | PLUGIN_MULTI,       // The plugin can work with multiple idbs in parallel
  init,                 // initialize
  nullptr,
  nullptr,
  nullptr,              // long comment about the plugin
  nullptr,              // multiline help about the plugin
  "Hello, world",       // the preferred short name of the plugin
  nullptr,              // the preferred hotkey to run the plugin
};

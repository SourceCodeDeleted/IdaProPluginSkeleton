## Preface:
I made this plugin to try to save time going through all the instructions in the SDK.
This is a simple hello world plugin and all you literally should need to do is
copy the IDAPRO SDK (You Received this from HexRays) to the project directory and rename it idasdk.
open in visual studio and click build...

## Installation Instructions:
```
1.
- copy the IDASDK to the project directory .
- rename the folder to idasdk.

2.
- Ida64_Debug
- Ida32_Debug


3. Simply build for that particular architecture and copy the testidaplugin.dll to your plugins folder in IdaPro.

4. Open Ida and click edit-> plugins->helloworld (name of our plugin)
5. in the message out put console you will see helloworld from 32/64 bit.
```

## Issues might arise:
-  I have commented out **access_type_t** struct in hexrays.hpp because it is duplicated in idp.hpp.
-  Versions might change . I have made this only for 7.5 and I am only supporting visual studio.
-  the Hexrays.hpp I copied from the Hexrays site so if this changes you might want to update it occasionally.
- I am not exporting  **/EXPORT:LPH** or  **/EXPORT:LDSC** . Upon compilation these exports couldn't be found and I don't have time to investigate.
- You can use **__EA64__** to define a 64 bit only portion of the binary. Ironically, this is all that separates 64 bit and 32 bit IDA API calls.


## Community:
[Join our discord](https://discord.com/invite/wqKQcmK)


## Original Instructions From HexRays:
These probably wont be needed , but just in case. They come from the SDK itself and sort of show what was required to set this up.


```
his guide will help you set up a Visual C++ project that targets both ida32 and ida64 plugins.
Remember that, even though ida32 is used to work on 32-bit files, it is also an x64 application.
Therefore, both plugins (ida32 and ida64) must be built for the x64 platform.

1. File | New | Project From Existing Code...

2. What type of project would you like to create: Visual C++
   <next>

3. Project file location: <folder where you have your files>
   Project name: <your plugin's name>
   <finish>

Once the project is initialized, right-click on the project name and pick Properties.

4. Configuration Manager...
     Active solution platform: select "x64"
   <Close>

5. General | Project Defaults | Configuration Type
     Dynamic Library (.dll)
   <apply>

6. C/C++ | General | Additional Include Directories
     Enter the SDK's include folder in "Include search paths (/I)": eg. C:\idasdk\include;
   <apply>

7. C/C++ | Code Generation | Runtime library (visible only after you add one .cpp file to the project)
     Multi-threaded DLL (/MD)
   <apply>

8. Linker | Command Line | Additional options
     - for processor modules: /EXPORT:LPH
     - for plugins: /EXPORT:PLUGIN
     - for loaders: /EXPORT:LDSC
   <apply>

The steps above constituted the common configuration for both ida32 and ida64 configurations.

We will now create the separate configurations.

9. Still under "Configuration Manager..."

     - under the "Configuration" column, click on "Debug"
     - click "<Edit...>"
     - click "Rename"
     - add an "ida32" prefix to the configuration name, such as "ida32 Debug"
     - <Enter>
     - <Yes>
     - <Close>

     - under "Active solution configuration", click on "Debug"
     - click "<Edit...>"
     - click "Rename"
     - add an "ida32" prefix to the configuration name, such as "ida32 Debug"
     - <Enter>
     - <Yes>
     - <Close>

     - under "Active solution configuration", click on the new configuration name "ida32 Debug"
     - click "<New...>"
     - use a similar name, but with the "ida64" prefix, such as "ida64 Debug"
     - Copy settings from: "ida32 Debug"
     - <Ok>
     - <Close>

In the "Property Page", under "Configuration", select "ida32 Debug".

10. Debugging | Command
      - for ida32: C:\Program Files\IDA 7.2\ida.exe
      - for ida64: C:\Program Files\IDA 7.2\ida64.exe
    <apply>

11. C/C++ | Preprocessor | Preprocessor Definitions
      - for ida32: __NT__;
      - for ida64: __NT__;__EA64__;
    <apply>

12. Linker | General | Output File:
      - for ida32: $(OutDir)\$(ProjectName).dll
      - for ida64: $(OutDir)\$(ProjectName)64.dll
    <apply>

13. Linker | Input | Additional Dependencies
      - for ida32: C:\idasdk\lib\x64_win_vc_32\ida.lib
      - for ida64: C:\idasdk\lib\x64_win_vc_64\ida.lib
    <apply>

In the "Property Page", under "Configuration", select "ida64 Debug" and repeat the last three steps.


You should now be capable to easily switch between the "ida32 Debug" and "ida64 Debug" configurations and build your project.

```

SCRIPT / UTILITY DESCRIPTIONS

These tools/utilities are available at github and on the listed primary pages.

Version Control: https://github.com/smxi/php-browser-detection

============================================================================

PHP Browser Detection

filename: browser_detection.inc

Primary home page: http://techpatterns.com/downloads/php_browser_detection.php
Support forums: http://techpatterns.com/forums/forum-11.html

A general php utility for browser / OS / Mobile / Tablet detection. 
Very robust and heavily tested in production environments. Not heavy weight 
like other php browser detectors, without sacrificing accuracy. 

This is very fast, and very efficient, utility. In continuous use and 
development for almost 15 years.

Returns either string or array data. Full explanation of output options in top
comment header of script.

There are a lot of browser detection scripts out there, some absurdly bloated
and inefficient (all we're doing is parsing the useragent string the server
returns, after all), others too simple, and prone to errors in detection.

============================================================================

PHP Language Detection

filename: language_detection.inc

Primary home page:
http://techpatterns.com/downloads/php_language_detection.php

A lightweight tool to assign browser languages. Based on the $_SERVER["HTTP_ACCEPT_LANGUAGE"]
header. 

Returns an array of the following 4 item array for each language the os supports:
1. full language abbreviation, like en-ca
2. primary language, like en
3. full language string, like English (Canada)
4. primary language string, like English

Easy to use, easy to implement, works well in conjunction with the browser
detection utility.

============================================================================

USERAGENT SWITCHER LIST

filename: useragents.xml

A reasonably complete list of user agents. Primary use is as the default 
full featured useragent list for Chris Pederick's UserAgent Switcher Firefox
addon.

http://chrispederick.com/work/user-agent-switcher/

This list is organized into reasonably easy to navigate sections and 
sub-sections. See below for basic structure.

Very useful to test the browser detection script as well.

This list is updated a few times a year.

Home page/Support Forum: http://techpatterns.com/forums/about304.html

Please note that because Mobile devices have very short lifespans and appear
and disappear constantly, the Mobile useragent section will never be complete.

But it will be generally just fine for testing and debugging purposes.

---------------------------------------------------------------

CONTRIBUTORS

Please note: If you want to contribute any updates to this list, you must
provide the following:

1. The English text version of the useragent, ie, what the end user sees in
the useragent switcher selector.

2. The full, correct, useragent string.

3. Where the new or modified item is located in the xml list.

Finding useragent strings is a pain, so if you provide all of these I'll 
add your update, if it makes sense, right away. 

Properly constructed Pull requests will generally be accepted as long as they
make sense and don't break anything and fit into the primary function of the
list, which is to be full list useful for web developers and others in the
UserAgent Switcher extension.

---------------------------------------------------------------

Current (2015-09-18) Layout/Structure:

Main categories:

    Browsers - Windows
        Legacy Browsers
        Current
    Browsers - Mac
        Legacy Browsers
        Current
    Browsers - Linux
        Console Browsers
        Legacy Browsers
        Gui Browsers
    Browsers - Unix
        Console Browsers
        Legacy Browsers
        Gui Browsers
    Mobile Devices
        Browsers
        Devices
            Divided into brand/device subsections
        OS
            Divided into OS subsections
        Services
        WAP Phones
    Spiders - Search
    Miscellaneous
        Bots - Spiders
        Browsers - Beos
        Browsers - OS/2
        Downloaders
        Feed Readers
        Game Consoles
        Libraries
        Validators
        Miscellaneous
